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

	#include nik_source(../../.., interpret, constant, architect, v_0_5, gcc)
	#include nik_source(../../.., interpret, array, architect, v_0_5, gcc)

// source:

namespace nik { nik_begin_module(interpret, machine, architect, NIK_VERSION, NIK_VENDOR)

	#include nik_import(../../.., interpret, store, architect, v_0_5, gcc, static, name)
	#include nik_import(../../.., interpret, constant, architect, v_0_5, gcc, static, name)
	#include nik_import(../../.., interpret, array, architect, v_0_5, gcc, static, name)

	template<auto... Vs>				// optimized because we know auto_pack<Vs...>
	static constexpr auto U_opt_pack_Vs =		// is not void nor a reference.
		nik_module(interpret, store, architect, v_0_5, gcc)::template
			type_map<auto_pack<Vs...>*>;

//	#include"v0.5/define_macros.hpp"

	//

//	#include"v0.5/0_programs.hpp"
//	#include"v0.5/1_routines.hpp"
//	#include"v0.5/2_controls.hpp"
//	#include"v0.5/3_machines.hpp"
//	#include"v0.5/4_arithmetic.hpp"
//	#include"v0.5/5_functional.hpp"

	//

//	#include"v0.5/undef_macros.hpp"

	friend nik_module(interpret, pack, architect, v_0_5, gcc);

nik_end_module(interpret, machine, architect, NIK_VERSION, NIK_VENDOR)

}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

#endif

