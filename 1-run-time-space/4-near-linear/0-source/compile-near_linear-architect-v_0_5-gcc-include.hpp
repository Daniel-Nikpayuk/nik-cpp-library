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

#ifndef NIK_COMPILE_NEAR_LINEAR_ARCHITECT_V_0_5_GCC_HPP
#define NIK_COMPILE_NEAR_LINEAR_ARCHITECT_V_0_5_GCC_HPP

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dependencies:

	#include nik_source(../../.., compile, signature, architect, v_0_5, gcc)
	#include nik_source(../../.., compile, one_cycle, architect, v_0_5, gcc)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// module:

namespace nik
{
	nik_begin_module(compile, near_linear, architect, v_0_5, gcc)

		#include nik_import(../../.., compile, procedure, architect, v_0_5, gcc, static, name)
		#include nik_import(../../.., compile, signature, architect, v_0_5, gcc, static, name)

		using functor_module	= nik_module(interpret, functor, architect, v_0_5, gcc);
		using boolean_module	= nik_module(interpret, boolean, architect, v_0_5, gcc);
		using function_module	= nik_module(interpret, function, architect, v_0_5, gcc);

		#include"v0.5/0_filter.hpp"
	//	#include"v0.5/1_repeat.hpp"
		#include"v0.5/2_map.hpp"
	//	#include"v0.5/3_fold.hpp"
	//	#include"v0.5/4_find.hpp"
	//	#include"v0.5/5_zip.hpp"
	//	#include"v0.5/6_fasten.hpp"
	//	#include"v0.5/7_glide.hpp"

	nik_end_module(compile, near_linear, architect, v_0_5, gcc)
}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

#endif

