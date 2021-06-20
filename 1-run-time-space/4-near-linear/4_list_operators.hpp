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

#ifndef _3_LIST_OPERATORS_HPP
#define _3_LIST_OPERATORS_HPP

// list operators:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace list_operators
{
	#include"../../0-register-machine/using_namespace_meta_programming.hpp"
//	#include"../../0-register-machine/using_namespace_machine_space.hpp"

	using function_space::_id_;
	using function_space::test;
	using function_space::assign;

	using continuation_space::lift;
	using continuation_space::stem;
	using continuation_space::chain_lift;
	using continuation_space::chain_endopose;
	using continuation_space::close_cycle;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// one cycle signature:

	//	template<typename T>
	//	using deref_type = decltype(**(T*)nullptr);

	template<typename OutT, typename InT, typename EndT> class one_cycle_signature;

		template<typename OutT, typename InT, typename EndT>
		OutT & one_cycle_dout(one_cycle_signature<OutT, InT, EndT> & s)			{ return s.out; }

		template<typename OutT, typename InT, typename EndT>
		auto & one_cycle_iout(one_cycle_signature<OutT, InT, EndT> & s)			{ return *s.out; }

		template<typename OutT, typename InT, typename EndT>
		InT & one_cycle_din(one_cycle_signature<OutT, InT, EndT> & s)			{ return s.in; }

		template<typename OutT, typename InT, typename EndT>
		auto & one_cycle_iin(one_cycle_signature<OutT, InT, EndT> & s)			{ return *s.in; }

		template<typename OutT, typename InT, typename EndT>
		EndT & one_cycle_dend(one_cycle_signature<OutT, InT, EndT> & s)			{ return s.end; }

		template<typename OutT, typename InT, typename EndT>
		auto & one_cycle_iend(one_cycle_signature<OutT, InT, EndT> & s)			{ return *s.end; }

	template<typename OutT, typename InT, typename EndT>
	class one_cycle_signature
	{
		OutT out;
		InT in;
		EndT end;

		public:

			constexpr one_cycle_signature(const OutT & _o, const InT & _i, const EndT & _e) :

				out(_o), in(_i), end(_e) { }

			friend OutT & one_cycle_dout<OutT, InT, EndT>(one_cycle_signature<OutT, InT, EndT> &);
			friend auto & one_cycle_iout<OutT, InT, EndT>(one_cycle_signature<OutT, InT, EndT> &);
			friend InT & one_cycle_din<OutT, InT, EndT>(one_cycle_signature<OutT, InT, EndT> &);
			friend auto & one_cycle_iin<OutT, InT, EndT>(one_cycle_signature<OutT, InT, EndT> &);
			friend EndT & one_cycle_dend<OutT, InT, EndT>(one_cycle_signature<OutT, InT, EndT> &);
			friend auto & one_cycle_iend<OutT, InT, EndT>(one_cycle_signature<OutT, InT, EndT> &);
	};

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

}

#endif

