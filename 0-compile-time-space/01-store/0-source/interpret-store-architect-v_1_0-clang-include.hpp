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

#ifndef NIK_INTERPRET_STORE_ARCHITECT_V_1_0_CLANG_HPP
#define NIK_INTERPRET_STORE_ARCHITECT_V_1_0_CLANG_HPP

// dependencies:

#define NIK_GENERIC_VERSION v_1_0
#define NIK_GENERIC_VENDOR clang
#define NIK_GENERIC_MODULE nik_module(interpret, generic, architect, NIK_GENERIC_VERSION, NIK_GENERIC_VENDOR)

	#include nik_source(../../.., interpret, generic, architect, NIK_GENERIC_VERSION, NIK_GENERIC_VENDOR)

// module:

#define NIK_VERSION v_1_0
#define NIK_VENDOR clang
#define NIK_MODULE nik_module(interpret, store, architect, NIK_VERSION, NIK_VENDOR)

	#include nik_local(interpret, store, architect, NIK_VERSION)

#undef NIK_MODULE
#undef NIK_VENDOR
#undef NIK_VERSION

#undef NIK_GENERIC_MODULE
#undef NIK_GENERIC_VENDOR
#undef NIK_GENERIC_VERSION

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

#endif

