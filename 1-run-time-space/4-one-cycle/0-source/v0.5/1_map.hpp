/************************************************************************************************************************
**
** Copyright 2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of nik_cpp_library.
**
** nik_cpp_library is free software: you can redistribute it and/or modify it under the terms
** of the GNU General Public License as published by the Free Software Foundation, either version 3
** of the License, or (at your option) any later version.
**
** nik_cpp_library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
** without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with nik_cpp_library.
** If not, see <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

// one cycle map:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// spec:

private:

	template
	<
		typename DOutType, typename IOutType,
		typename InType, typename EndType,

		auto function,

		auto dout		= dout<DOutType, InType, EndType>	,
		auto iout		= iout<DOutType, InType, EndType>	,
		auto in			= din<DOutType, InType, EndType>	,
		auto end		= dend<DOutType, InType, EndType>	,

		auto is_equal		= equal<InType, EndType>		,
		auto halt		= _id_					,
		auto out_increment	= add_by<DOutType, 1>			,
		auto in_increment	= add_by<InType, 1>
	>
	static constexpr auto U_map = chain_endopose
	<
		stem
		<
			test   < is_equal , in            , end  >,

			halt,
			assign < iout     , function      , in   >
		>,

		chain_lift
		<
			assign < dout     , out_increment , dout >,
			assign < in       , in_increment  , in   >
		>
	>;

public:

	template<auto f, typename OutType, typename InType, typename EndType>
	static constexpr OutType make_range(OutType out, InType in, EndType end)
	{
		using IOutType	= decltype(*out);
		using signature	= one_cycle<OutType, InType, EndType>;
		auto s		= signature(out, in, end);
		auto result	= dout<OutType, InType, EndType>;
		auto map	= close_cycle<U_map<OutType, IOutType, InType, EndType, f>, signature>;

		return result(map(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

