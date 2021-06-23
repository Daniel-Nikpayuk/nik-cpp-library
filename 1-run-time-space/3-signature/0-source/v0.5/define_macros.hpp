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

// define macros:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// one cycle accessors:

/***********************************************************************************************************************/

// out, in, end:

	#define NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(_type_, _name_)						\
															\
		_type_ & module::_name_											\
		<													\
			OutType,											\
			InType,												\
			EndType												\
															\
		>(one_cycle_signature											\
		<													\
			_object < OutType >,										\
			_object < InType  >,										\
			_object < EndType >										\
		> &)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

