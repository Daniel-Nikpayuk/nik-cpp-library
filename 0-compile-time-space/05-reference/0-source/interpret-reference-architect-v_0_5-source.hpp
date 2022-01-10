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

// reference source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

private:

	template<typename T>				// This works because as a variable template it has
	static constexpr bool is_reference = false;	// a partial specialize defined outside of this module.

public:

	template<typename T>
	static constexpr bool V_is_reference_T = is_reference<T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specifiers:

public:

	enum struct Reference
	{
		to_reference,
		from_reference,

		dimension // filler
	};

	//

	template<Reference r> static constexpr bool is_to_reference		= (r == Reference::to_reference);
	template<Reference r> static constexpr bool is_from_reference		= (r == Reference::from_reference);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// modify:

private:

	template<typename, Reference> struct modify;

	template<typename T>
	struct modify<T, Reference::to_reference>
	{
		using type	= T&;
	};

	template<typename T>
	struct modify<T&, Reference::to_reference>
	{
		using type	= T&;
	};

	template<typename T>
	struct modify<T, Reference::from_reference>
	{
		using type	= T;
	};

	template<typename T>
	struct modify<T&, Reference::from_reference>
	{
		using type	= T;
	};

public:

	template<typename T, Reference r>
	using T_reference_modify_TxV = typename modify<T, r>::type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

