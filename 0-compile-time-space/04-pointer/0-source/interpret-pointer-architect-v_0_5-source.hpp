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

// pointer source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

private:

	template<typename T>				// This works because as a variable template it has
	static constexpr bool is_pointer = false;	// a partial specialize defined outside of this module.

public:

	template<typename T>
	static constexpr bool V_is_pointer_T = is_pointer<T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specifiers:

public:

	enum struct Pointer
	{
		to_pointer,
		from_pointer,

		dimension // filler
	};

	//

	template<Pointer p> static constexpr bool is_to_pointer			= (p == Pointer::to_pointer);
	template<Pointer p> static constexpr bool is_from_pointer		= (p == Pointer::from_pointer);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// modify:

private:

	template<typename, Pointer> struct modify;

	template<typename T>
	struct modify<T, Pointer::to_pointer>
	{
		using type	= T*;
	};

	template<typename T>
	struct modify<T*, Pointer::to_pointer>
	{
		using type	= T*;
	};

	template<typename T>
	struct modify<T, Pointer::from_pointer>
	{
		using type	= T;
	};

	template<typename T>
	struct modify<T*, Pointer::from_pointer>
	{
		using type	= T;

		// alternative implementation (reflection):

		//	template<typename T>
		//	using deref_type = decltype(**(T*)nullptr);
	};

public:

	template<typename T, Pointer p>
	using T_pointer_modify_TxV = typename modify<T, p>::type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

