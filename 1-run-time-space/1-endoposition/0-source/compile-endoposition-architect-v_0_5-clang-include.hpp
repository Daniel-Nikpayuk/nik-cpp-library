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

#ifndef NIK_COMPILE_ENDOPOSITION_ARCHITECT_V_0_5_CLANG_HPP
#define NIK_COMPILE_ENDOPOSITION_ARCHITECT_V_0_5_CLANG_HPP

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dependencies:

	#include nik_source(../../.., compile, composition, architect, v_0_5, clang)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// module:

namespace nik
{
	nik_begin_module(compile, endoposition, architect, v_0_5, clang)

		#include nik_import(../../.., interpret, functor, architect, v_0_5, clang, static, name)
		#include nik_import(../../.., compile, composition, architect, v_0_5, clang, static, name)

		using pack_module = nik_module(interpret, pack, architect, v_0_5, clang);

		#include"compile-endoposition-architect-v_0_5-source.hpp"

	nik_end_module(compile, endoposition, architect, v_0_5, clang)
}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

#endif

