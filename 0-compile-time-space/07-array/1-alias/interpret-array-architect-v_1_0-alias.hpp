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

// array alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

	template<typename T>
	NIK_POLICY bool nik_name(NIK_PREFIX, V_is_array_T)	= NIK_MODULE::template V_is_array_T<T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// array:

/***********************************************************************************************************************/

// variable:

	template<typename Type, Type... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, array)		= NIK_MODULE::template array<Type, Vs...>;

// struct:

	template<typename Type, auto Size>
	using nik_name(NIK_PREFIX, Array)			= typename NIK_MODULE::template Array<Type, Size>;

// apply:

//	template<typename F, auto arr, auto seg>
//	NIK_POLICY auto nik_name(NIK_PREFIX, apply)		= NIK_MODULE::template apply<F, arr>(seg);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

