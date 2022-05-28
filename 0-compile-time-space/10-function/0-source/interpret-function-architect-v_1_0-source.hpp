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

	#include nik_source(../../.., interpret, pair, architect, v_0_5, gcc)
	#include nik_source(../../.., interpret, reference, architect, v_0_5, gcc)
	#include nik_source(../../.., interpret, list, architect, v_0_5, gcc)

// source:

namespace nik { nik_begin_module(interpret, function, architect, NIK_VERSION, NIK_VENDOR)

	#include nik_import(../../.., interpret, pair, architect, v_0_5, gcc, static, name)

	using store_module	= nik_module(interpret, store, architect, v_0_5, gcc);
	using constant_module	= nik_module(interpret, constant, architect, v_0_5, gcc);
	using reference_module	= nik_module(interpret, reference, architect, v_0_5, gcc);
	using pack_module	= nik_module(interpret, pack, architect, v_0_5, gcc);

	using Constant		= typename constant_module::Constant;
	using Reference		= typename reference_module::Reference;

	#include"v0.5/0_dispatch.hpp"
	#include"v0.5/1_space.hpp"

nik_end_module(interpret, function, architect, NIK_VERSION, NIK_VENDOR)

}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

#endif

