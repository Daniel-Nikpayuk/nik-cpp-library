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

#ifndef NIK_INTERPRET_BOOLEAN_ARCHITECT_V_0_5_GCC_HPP
#define NIK_INTERPRET_BOOLEAN_ARCHITECT_V_0_5_GCC_HPP

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dependencies:

	#include nik_source(../../.., interpret, cache, architect, v_0_5, gcc)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// module:

namespace nik
{
	nik_begin_module(interpret, boolean, architect, v_0_5, gcc)

		using cache_module = nik_module(interpret, cache, architect, v_0_5, gcc);

		#include"interpret-boolean-architect-v_0_5-source.hpp"

	nik_end_module(interpret, boolean, architect, v_0_5, gcc)

	// if then else:

		template<auto ante, auto conse>
		constexpr auto nik_module(interpret, boolean, architect, v_0_5, gcc)::
			V_if_then_else<false, ante, conse> = conse;
}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

#endif

