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

// dispatch source:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// enumeration filters (level 0):

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attributes:

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
	static constexpr bool is_immutable			= (m == Mutability::immutable);

	template<Mutability m>
	static constexpr bool is_variable			= (m == Mutability::variable);

	//

	template<Denotation d>
	static constexpr bool is_reference			= (d == Denotation::reference);

	template<Denotation d>
	static constexpr bool is_dereference			= (d == Denotation::dereference);

/***********************************************************************************************************************/

	template<Mutability m, Denotation d>
	static constexpr bool is_immutable_reference		= (is_immutable<m> && is_reference<d>);

	template<Mutability m, Denotation d>
	static constexpr bool is_immutable_dereference		= (is_immutable<m> && is_dereference<d>);

	template<Mutability m, Denotation d>
	static constexpr bool is_variable_reference		= (is_variable<m> && is_reference<d>);

	template<Mutability m, Denotation d>
	static constexpr bool is_variable_dereference		= (is_variable<m> && is_dereference<d>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attribute filters (level 1):

/***********************************************************************************************************************/

	template<Mutability Mutate, Denotation Denote>
	struct _attributes
	{
		static constexpr Mutability mutate = Mutate;
		static constexpr Denotation denote = Denote;
	};

	//

	using attr_ref		= _attributes < Mutability::variable  , Denotation::reference   >;
	using attr_deref	= _attributes < Mutability::variable  , Denotation::dereference >;
	using attr_cref		= _attributes < Mutability::immutable , Denotation::reference   >;
	using attr_cderef	= _attributes < Mutability::immutable , Denotation::dereference >;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// member argument filters (level 2):

/***********************************************************************************************************************/

	template<typename Type, typename Attr>
	struct _argument
	{
		using type		= Type;
		using attributes	= Attr;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// facade filters (level 3):

/***********************************************************************************************************************/

	template<typename... Args> struct _facade { };

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatchers:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// make assign:

/***********************************************************************************************************************/

	template<typename Sign, auto UFunc, typename... Args>
	static constexpr auto make_assign(void(*)(_facade<Args...>))
	{
		using S_function		= functor_module::template T_type_U<UFunc>;

		// constexpr auto l_value	= out_f<signature, out_next_args::l_attributes>;
		// constexpr auto _out_next_r	= out_f<signature, out_next_args::r_attributes>;
		// constexpr auto _out_next	= make_next_function
		//							<
		//								OutNext::direction,
		//								OutNext::ufunction,
		//								_out_next_l, _out_next_r
		//							>;

		return 0;
	}

/***********************************************************************************************************************/

// resolve:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

