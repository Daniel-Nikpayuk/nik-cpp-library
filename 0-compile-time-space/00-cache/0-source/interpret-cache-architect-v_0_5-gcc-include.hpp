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

#ifndef NIK_INTERPRET_CACHE_ARCHITECT_V_0_5_GCC_HPP
#define NIK_INTERPRET_CACHE_ARCHITECT_V_0_5_GCC_HPP

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dependencies:

	// none.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// module:

namespace nik
{
	nik_begin_module(interpret, cache, architect, v_0_5, gcc)

		#include"interpret-cache-architect-v_0_5-source.hpp"

		friend nik_module(interpret, machine, architect, v_0_5, gcc);

	nik_end_module(interpret, cache, architect, v_0_5, gcc)

	// get type map:

		template<typename T>
		constexpr auto nik_module(interpret, cache, architect, v_0_5, gcc)::get_type_map<T&> =
			nik_module(interpret, cache, architect, v_0_5, gcc)::template type_map<T&>;

	// is typename pack:

		template<typename... Ts>
		constexpr bool nik_module(interpret, cache, architect, v_0_5, gcc)::V_is_typename_pack_T
		<
			nik_module(interpret, cache, architect, v_0_5, gcc)::typename_pack<Ts...>

		> = true;

	// is auto pack:

		template<auto... Vs>
		constexpr bool nik_module(interpret, cache, architect, v_0_5, gcc)::V_is_auto_pack_T
		<
			nik_module(interpret, cache, architect, v_0_5, gcc)::auto_pack<Vs...>

		> = true;

	// is typename template pack:

		template<template<typename...> class... As>
		constexpr bool nik_module(interpret, cache, architect, v_0_5, gcc)::V_is_typename_template_pack_T
		<
			nik_module(interpret, cache, architect, v_0_5, gcc)::typename_template_pack<As...>

		> = true;

	// is auto template pack:

		template<template<auto...> class... Bs>
		constexpr bool nik_module(interpret, cache, architect, v_0_5, gcc)::V_is_auto_template_pack_T
		<
			nik_module(interpret, cache, architect, v_0_5, gcc)::auto_template_pack<Bs...>

		> = true;

	// identity type:

		template<typename T>
		constexpr bool nik_module(interpret, cache, architect, v_0_5, gcc)::V_equal_TxT<T,T> = true;
}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

#endif

