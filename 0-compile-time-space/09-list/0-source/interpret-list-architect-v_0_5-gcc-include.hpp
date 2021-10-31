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

#ifndef NIK_INTERPRET_LIST_ARCHITECT_V_0_5_GCC_HPP
#define NIK_INTERPRET_LIST_ARCHITECT_V_0_5_GCC_HPP

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dependencies:

	#include nik_source(../../.., interpret, pack, architect, v_0_5, gcc)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// module:

namespace nik
{
	nik_begin_module(interpret, list, architect, v_0_5, gcc)

		#include nik_import(../../.., interpret, constant, architect, v_0_5, gcc, static, name)

		using cache_module	= nik_module(interpret, cache, architect, v_0_5, gcc);
		using machine_module	= nik_module(interpret, machine, architect, v_0_5, gcc);
		using pack_module	= nik_module(interpret, pack, architect, v_0_5, gcc);

		using instr_type	= typename nik_module(interpret, machine, architect, v_0_5, gcc)::instr_type;
		using contr_type	= typename nik_module(interpret, machine, architect, v_0_5, gcc)::label_type;

		#include"interpret-list-architect-v_0_5-source.hpp"

	nik_end_module(interpret, list, architect, v_0_5, gcc)

	// is list:

		template<template<typename...> class L, typename... Ts>
		constexpr bool nik_module(interpret, list, architect, v_0_5, gcc)::is_list<L<Ts...>> = true;

		template<template<auto...> class L, auto... Vs>
		constexpr bool nik_module(interpret, list, architect, v_0_5, gcc)::is_list<L<Vs...>> = true;
}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

#endif

