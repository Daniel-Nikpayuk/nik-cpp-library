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

	// none.

// reference source:

namespace nik { nik_begin_module(interpret, reference, architect, NIK_VERSION, NIK_VENDOR)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

private:

	template<typename T>				// This works because as a variable template it has
	nik_ces bool is_reference = false;	// a partial specialize defined outside of this module.

public:

	template<typename T>
	nik_ces bool V_is_reference_T = is_reference<T>;

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

	template<Reference r> nik_ces bool is_to_reference		= (r == Reference::to_reference);
	template<Reference r> nik_ces bool is_from_reference		= (r == Reference::from_reference);

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

nik_end_module(interpret, generic, architect, NIK_VERSION, NIK_VENDOR)

// variable template specializations:

	// is reference:

		template<typename T>
		constexpr bool nik_module(interpret, reference, architect, v_0_5, gcc)::is_reference<T&> = true;

	template<typename Op, nik_vp(*pack)(Op*), auto... Vs>
	constexpr auto NIK_MODULE::apply<pack, Vs...> = Op::template result<Vs...>;
}

