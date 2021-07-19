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
		by_value,
		by_reference,

		dimension // filler
	};

/***********************************************************************************************************************/

	template<Mutability m>
	static constexpr bool is_immutable			= (m == Mutability::immutable);

	template<Mutability m>
	static constexpr bool is_variable			= (m == Mutability::variable);

	//

	template<Denotation d>
	static constexpr bool is_by_value			= (d == Denotation::by_value);

	template<Denotation d>
	static constexpr bool is_by_reference			= (d == Denotation::by_reference);

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

	using attr_by_val	= _attributes < Mutability::variable  , Denotation::by_value     >;
	using attr_by_ref	= _attributes < Mutability::variable  , Denotation::by_reference >;
	using attr_by_cval	= _attributes < Mutability::immutable , Denotation::by_value     >;
	using attr_by_cref	= _attributes < Mutability::immutable , Denotation::by_reference >;

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

	//

	template<typename Type> using arg_by_val	= _argument<Type, attr_by_val>;
	template<typename Type> using arg_by_ref	= _argument<Type, attr_by_ref>;
	template<typename Type> using arg_by_cval	= _argument<Type, attr_by_cval>;
	template<typename Type> using arg_by_cref	= _argument<Type, attr_by_cref>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// facade filters (level 3):

/***********************************************************************************************************************/

	template<typename... Args> using _facade	= functor_module::template typename_pack<Args...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatchers:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// sign:

/***********************************************************************************************************************/

private:

	template<typename Type>
	static constexpr auto f_sign(void(*f)(Type*))
	{
		return f;
	}

	template<typename Type, typename Attr>
	static constexpr auto f_sign(void(*)(_argument<Type, Attr>*))
	{
		constexpr auto mutate = Attr::mutate;
		constexpr auto denote = Attr::denote;

		if constexpr (is_immutable<mutate>)
		{
			if constexpr (is_by_value<denote>)	return functor_module::template U_type_T<Type const>;
			else					return functor_module::template U_type_T<Type const &>;
		}
		else
		{
			if constexpr (is_by_value<denote>)	return functor_module::template U_type_T<Type>;
			else					return functor_module::template U_type_T<Type &>;
		}
	}

public:

	template<typename Arg>
	using sign = functor_module::template T_type_U
	<
		f_sign(functor_module::template U_type_T<Arg>)
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// resolve:

/***********************************************************************************************************************/

private:

	template<auto UFunc, typename... Args>
	static constexpr auto f_resolve(void(*)(_facade<Args...>*))
	{
		using S_function = functor_module::template T_type_U<UFunc>;

		return S_function::template result<sign<Args>...>;
	}

public:

	template<auto ufunction, typename Facade>
	static constexpr auto resolve = f_resolve<ufunction>(functor_module::template U_type_T<Facade>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

