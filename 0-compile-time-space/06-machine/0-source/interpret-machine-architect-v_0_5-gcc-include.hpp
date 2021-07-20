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

#ifndef NIK_INTERPRET_MACHINE_ARCHITECT_V_0_5_GCC_HPP
#define NIK_INTERPRET_MACHINE_ARCHITECT_V_0_5_GCC_HPP

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dependencies:

	#include nik_source(../../.., interpret, constant, architect, v_0_5, gcc)
	#include nik_source(../../.., interpret, array, architect, v_0_5, gcc)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// module:

namespace nik
{
	nik_begin_module(interpret, machine, architect, v_0_5, gcc)

		#include nik_import(../../.., interpret, functor, architect, v_0_5, gcc, static, name)
		#include nik_import(../../.., interpret, constant, architect, v_0_5, gcc, static, name)
		#include nik_import(../../.., interpret, array, architect, v_0_5, gcc, static, name)

		template<auto... Vs>				// optimized because we know auto_pack<Vs...>
		static constexpr auto U_opt_pack_Vs =		// is not void nor a reference.
			nik_module(interpret, functor, architect, v_0_5, gcc)::template
				type_map<auto_pack<Vs...>*>;

		#include"v0.5/define_parameter_macros.hpp"
		#include"v0.5/define_machine_macros.hpp"

		//

		#include"v0.5/0_machines.hpp"
		#include"v0.5/1_dispatchers.hpp"
		#include"v0.5/2_controllers.hpp"

		//

		#include"v0.5/undef_all_macros.hpp"

		friend nik_module(interpret, pack, architect, v_0_5, gcc);

	nik_end_module(interpret, machine, architect, v_0_5, gcc)
}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

#endif

