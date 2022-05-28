/************************************************************************************************************************
**
** Copyright 2021-2022 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

// dependencies:

	#include nik_source(../../.., interpret, store, architect, v_0_5, gcc)

// boolean source:

namespace nik { nik_begin_module(interpret, boolean, architect, NIK_VERSION, NIK_VENDOR)

	using store_module = nik_module(interpret, store, architect, v_0_5, gcc);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// conditionals:

private:

	template<bool True, bool...>
	struct T_if_then_else
	{
		template<typename Ante, typename Conse>
		using result = Ante;
	};

	template<bool... filler>
	struct T_if_then_else<false, filler...>
	{
		template<typename Ante, typename Conse>
		using result = Conse;
	};

	template<bool True, auto ante, auto conse>	// This works because as a variable template it has
	nik_ces auto V_if_then_else = ante;	// a partial specialize defined outside of this module.

public:

	// TxT -> T:

	template<bool is_br, typename Ante, typename Conse>
	using T_if_then_else_TxT = typename T_if_then_else<is_br>::template result<Ante, Conse>;

	// VxV -> V:

	template<bool is_br, auto ante, auto conse>
	nik_ces auto V_if_then_else_VxV = V_if_then_else<is_br, ante, conse>;

	// VxV -> T:

	template<bool is_br, auto ante, auto conse>
	using T_if_then_else_VxV = typename store_module::template T_store_U
	<
		V_if_then_else<is_br, ante, conse>
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

nik_end_module(interpret, generic, architect, NIK_VERSION, NIK_VENDOR)

// variable template specializations:

	// if then else:

		template<auto ante, auto conse>
		constexpr auto nik_module(interpret, boolean, architect, v_0_5, gcc)::
			V_if_then_else<false, ante, conse> = conse;

	template<typename Op, nik_vp(*pack)(Op*), auto... Vs>
	constexpr auto NIK_MODULE::apply<pack, Vs...> = Op::template result<Vs...>;
}

