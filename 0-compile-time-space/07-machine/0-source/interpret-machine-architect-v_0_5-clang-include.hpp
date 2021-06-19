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

#ifndef NIK_INTERPRET_MACHINE_ARCHITECT_V_0_5_CLANG_HPP
#define NIK_INTERPRET_MACHINE_ARCHITECT_V_0_5_CLANG_HPP

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dependencies:

	#include nik_source(../../.., interpret, controller, architect, v_0_5, clang)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// module:

namespace nik
{
	nik_begin_module(interpret, machine, architect, v_0_5, clang)

		#include nik_import(../../.., interpret, functor, architect, v_0_5, clang, static, name)
		#include nik_import(../../.., interpret, constant, architect, v_0_5, clang, static, name)

		using controller_module = nik_module(interpret, controller, architect, v_0_5, clang);

		#include"v0.5/define_parameter_macros.hpp"
		#include"v0.5/define_machine_macros.hpp"

		//

		#include"v0.5/0_machine_declarations.hpp"
		#include"v0.5/1_block_machines.hpp"
		#include"v0.5/2_variadic_machines.hpp"
		#include"v0.5/3_permutatic_machines.hpp"
		#include"v0.5/4_distributic_machines.hpp"
		#include"v0.5/5_near_linear_machines.hpp"
		#include"v0.5/6_machines.hpp"

		//

		#include"v0.5/undef_all_macros.hpp"

		friend nik_module(interpret, pack, architect, v_0_5, clang);

	nik_end_module(interpret, machine, architect, v_0_5, clang)
}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

#endif

