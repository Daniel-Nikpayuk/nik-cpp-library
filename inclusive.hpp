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

#ifndef NIK_CPP_LIBRARY_INCLUSIVE_HPP
#define NIK_CPP_LIBRARY_INCLUSIVE_HPP

/***********************************************************************************************************************/
/***********************************************************************************************************************/

#include"exclusive.hpp"

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compile time space:

//#include nik_source(., interpret, functor, architect, v_0_5, gcc)			// redundant inclusion
//#include nik_source(., interpret, constant, architect, v_0_5, gcc)			// redundant inclusion
#include nik_source(., interpret, boolean, architect, v_0_5, gcc)
#include nik_source(., interpret, pointer, architect, v_0_5, gcc)
#include nik_source(., interpret, reference, architect, v_0_5, gcc)
//#include nik_source(., interpret, array, architect, v_0_5, gcc)			// redundant inclusion
//#include nik_source(., interpret, controller, architect, v_0_5, gcc)			// redundant inclusion
//#include nik_source(., interpret, machine, architect, v_0_5, gcc)			// redundant inclusion
//#include nik_source(., interpret, pack, architect, v_0_5, gcc)			// redundant inclusion
#include nik_source(., interpret, list, architect, v_0_5, gcc)
//#include nik_source(., interpret, function, architect, v_0_5, gcc)			// redundant inclusion
#include nik_source(., interpret, colist, architect, v_0_5, gcc)

/***********************************************************************************************************************/

// run time space:

//#include nik_source(., compile, compose, architect, v_0_5, gcc)			// redundant inclusion
//#include nik_source(., compile, endopose, architect, v_0_5, gcc)			// redundant inclusion
//#include nik_source(., compile, signature, architect, v_0_5, gcc)			// redundant inclusion
//#include nik_source(., compile, near_linear, architect, v_0_5, gcc)			// redundant inclusion
//#include nik_source(., compile, one_cycle, architect, v_0_5, gcc)			// redundant inclusion
//#include nik_source(., compile, typed_stack, architect, v_0_5, gcc)			// redundant inclusion
#include nik_source(., compile, typed_machine, architect, v_0_5, gcc)

/***********************************************************************************************************************/
/***********************************************************************************************************************/


#endif
