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

// one cycle source:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// builtin types:

	static constexpr auto U_void			= functor_module::template U_type_T<void>;
	static constexpr auto U_char			= functor_module::template U_type_T<char>;
	static constexpr auto U_char_ptr		= functor_module::template U_type_T<char*>;

	static constexpr auto U_unsigned_char		= functor_module::template U_type_T<unsigned char>;
	static constexpr auto U_signed_char		= functor_module::template U_type_T<signed char>;

	static constexpr auto U_unsigned_short		= functor_module::template U_type_T<unsigned short>;
	static constexpr auto U_signed_short		= functor_module::template U_type_T<signed short>;

	static constexpr auto U_unsigned_int		= functor_module::template U_type_T<unsigned int>;
	static constexpr auto U_signed_int		= functor_module::template U_type_T<signed int>;

	static constexpr auto U_unsigned_long		= functor_module::template U_type_T<unsigned long>;
	static constexpr auto U_signed_long		= functor_module::template U_type_T<signed long>;

	static constexpr auto U_unsigned_long_long	= functor_module::template U_type_T<unsigned long long>;
	static constexpr auto U_signed_long_long	= functor_module::template U_type_T<signed long long>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// map:

	template
	<
		typename DOutT, typename IOutT,
		typename InT, typename EndT,

		auto function,

		auto dout		= one_cycle_dout<DOutT, InT, EndT>	,
		auto iout		= one_cycle_iout<DOutT, InT, EndT>	,
		auto in			= one_cycle_din<DOutT, InT, EndT>	,
		auto end		= one_cycle_dend<DOutT, InT, EndT>	,

		auto is_equal		= equal<InT, EndT>			,
		auto halt		= _id_					,
		auto out_increment	= add_by<DOutT, 1>			,
		auto in_increment	= add_by<InT, 1>
	>
	constexpr auto U_map = chain_endopose
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

	template<auto f, typename OutT, typename InT, typename EndT>
	OutT make_range(OutT out, InT in, EndT end)
	{
		using IOutT	= decltype(*out);
		auto s		= one_cycle_signature(out, in, end);

		return one_cycle_dout(close_cycle<U_map<OutT, IOutT, InT, EndT, f>>(s));
	}

/*
		char arr[5];
		arr[4] = '\0';

		make_range<add_by<char, 1>>(arr, '0', '4'); // prints: "1234"

		printf("%s\n", arr);
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

