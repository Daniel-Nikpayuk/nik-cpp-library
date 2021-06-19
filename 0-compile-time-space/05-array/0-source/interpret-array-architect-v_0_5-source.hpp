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

// array source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

private:

	template<typename T>
	static constexpr bool V_is_array_U(void(*)(T))		// Unsafe to use directly,
		{ return false; }

	template<typename T, global_size_type N>
	static constexpr bool V_is_array_U(void(*)(T(*)[N]))	// Use the following instead:
		{ return true; }

public:

	template<typename T>
	static constexpr bool V_is_array_T = V_is_array_U(functor_module::template U_type_T<T>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// array:

/***********************************************************************************************************************/

	template<typename Type, Type... Vs>
	static constexpr Type array[] = { Vs... };

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

