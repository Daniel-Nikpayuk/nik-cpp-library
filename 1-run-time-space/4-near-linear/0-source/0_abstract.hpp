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

// abstract:

//	filters (accessors):

//		i(...) - identity
//		d(...) - dereference

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// objects:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attribute specifications:

/***********************************************************************************************************************/

	template<auto...> struct _object_attributes;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// object specifications:

	template<typename Type = void, typename Attr = void>
	struct _object
	{
		using type = Type;
		using attr = Attr;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// signature arguments:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

/***********************************************************************************************************************/

	enum struct Mutability
	{
		immutable,
		variable,

		dimension // filler
	};

	enum struct Denotation
	{
		reference,
		dereference,

		dimension // filler
	};

/***********************************************************************************************************************/

	template<Mutability m>
	static constexpr bool V_is_immutable			= (m == Mutability::immutable);

	template<Mutability m>
	static constexpr bool V_is_variable			= (m == Mutability::variable);

	//

	template<Denotation d>
	static constexpr bool V_is_reference			= (d == Denotation::reference);

	template<Denotation d>
	static constexpr bool V_is_dereference			= (d == Denotation::dereference);

/***********************************************************************************************************************/

	template<Mutability m, Denotation d>
	static constexpr bool V_is_immutable_reference		= (V_is_immutable<m> && V_is_reference<d>);

	template<Mutability m, Denotation d>
	static constexpr bool V_is_immutable_dereference	= (V_is_immutable<m> && V_is_dereference<d>);

	template<Mutability m, Denotation d>
	static constexpr bool V_is_variable_reference		= (V_is_variable<m> && V_is_reference<d>);

	template<Mutability m, Denotation d>
	static constexpr bool V_is_variable_dereference		= (V_is_variable<m> && V_is_dereference<d>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attribute specifications:

/***********************************************************************************************************************/

	template
	<
		Mutability Mutate,
		Denotation Denote,
		auto...
	>
	struct _argument_attributes
	{
		static constexpr Mutability mutate		= Mutate;
		static constexpr Denotation denote		= Denote;
	};

	//

	using imm_ref_arg_attr		= _argument_attributes < Mutability::immutable , Denotation::reference   >;
	using imm_deref_arg_attr	= _argument_attributes < Mutability::immutable , Denotation::dereference >;
	using var_ref_arg_attr		= _argument_attributes < Mutability::variable  , Denotation::reference   >;
	using var_deref_arg_attr	= _argument_attributes < Mutability::variable  , Denotation::dereference >;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// argument specifications:

/***********************************************************************************************************************/

	template<typename = void, typename = void> struct _argument		{ };

	//

	template<typename Type = void> using imm_ref_arg		= _argument < Type , imm_ref_arg_attr   >;
	template<typename Type = void> using imm_deref_arg		= _argument < Type , imm_deref_arg_attr >;
	template<typename Type = void> using var_ref_arg		= _argument < Type , var_ref_arg_attr   >;
	template<typename Type = void> using var_deref_arg		= _argument < Type , var_deref_arg_attr >;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

