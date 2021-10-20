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

	// Simplify attr_by_ variations.
	// Create an algebra to toggle
	// into the other variations.

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

	template<Mutability m> static constexpr bool is_immutable		= (m == Mutability::immutable);
	template<Mutability m> static constexpr bool is_variable		= (m == Mutability::variable);

	//

	template<Denotation d> static constexpr bool is_by_value		= (d == Denotation::by_value);
	template<Denotation d> static constexpr bool is_by_reference		= (d == Denotation::by_reference);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attribute filters (level 1):

/***********************************************************************************************************************/

	static constexpr auto attr_by_val		= cons < Mutability::variable  , Denotation::by_value     >;
	static constexpr auto attr_by_ref		= cons < Mutability::variable  , Denotation::by_reference >;
	static constexpr auto attr_by_cval		= cons < Mutability::immutable , Denotation::by_value     >;
	static constexpr auto attr_by_cref		= cons < Mutability::immutable , Denotation::by_reference >;

/***********************************************************************************************************************/

	template<auto p> static constexpr bool attr_is_immutable	= (car<p> == Mutability::immutable);
	template<auto p> static constexpr bool attr_is_variable		= (car<p> == Mutability::variable);

	template<auto p> static constexpr bool attr_is_by_value		= (cdr<p> == Denotation::by_value);
	template<auto p> static constexpr bool attr_is_by_reference	= (cdr<p> == Denotation::by_reference);

	//

	template<auto p> static constexpr auto attr_to_immutable	= cons<Mutability::immutable, cdr<p>>;
	template<auto p> static constexpr auto attr_to_variable		= cons<Mutability::variable, cdr<p>>;

	template<auto p> static constexpr auto attr_to_by_value		= cons<car<p>, Denotation::by_value>;
	template<auto p> static constexpr auto attr_to_by_reference	= cons<car<p>, Denotation::by_reference>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// member argument filters (level 2):

/***********************************************************************************************************************/

	template<typename Type, auto Attr>
	struct _argument
	{
		using type				= Type;
		static constexpr auto attributes	= Attr;
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

	template<typename... Args> using _facade	= cache_module::template typename_pack<Args...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatchers:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// modify: ?

// sign:

/***********************************************************************************************************************/

private:

//	template<typename AttrByVal>
//	struct modify_type
//	{
//		template<typename T>
//		using result = T;
//	};

//	template<typename>
//	struct modify_type<attr_by_ref>
//	{
//		template<typename T>
//		using result = T &;
//	};

//	template<typename>
//	struct modify_type<attr_by_cval>
//	{
//		template<typename T>
//		using result = T const &;
//	};

//	template<typename>
//	struct modify_type<attr_by_cref>
//	{
//		template<typename T>
//		using result = T const &;
//	};

	//

//	template<typename Type>
//	static constexpr auto f_sign_type(Type v) // Type == void(*)(T*) or void(*)(T&)
//	{
//		return v;
//	}

//	template<typename Type, typename Attr>
//	static constexpr auto f_sign_type(void(*)(_argument<Type, Attr>*))
//	{
//		constexpr auto mutate = Attr::mutate;
//		constexpr auto denote = Attr::denote;

//		if constexpr (is_immutable<mutate>)
//		{
//			if constexpr (is_by_value<denote>)	return cache_module::template U_type_T<Type const>;
//			else					return cache_module::template U_type_T<Type const &>;
//		}
//		else
//		{
//			if constexpr (is_by_value<denote>)	return cache_module::template U_type_T<Type>;
//			else					return cache_module::template U_type_T<Type &>;
//		}
//	}

public:

	// arg type cast ?

//	template<typename Arg>
//	using sign_type = cache_module::template T_type_U
//	<
//		f_sign_type(cache_module::template U_type_T<Arg>)
//	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specialize:

/***********************************************************************************************************************/

public:

//	template<auto J, typename... ArgTs>
//	static constexpr auto specialize = cache_module::template T_type_U<J>::template result<arg_type<ArgTs>...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// resolve:

/***********************************************************************************************************************/

private:

//	template<auto J, typename... Args>
//	static constexpr auto f_resolve(void(*)(_facade<Args...>*))
//	{
//		using F = typename cache_module::template T_type_U<J>;

//		return F::template result<arg_type<Args>...>;
//	}

public:

	// Have two variations analogous to "pack" and "list": arg types and facade ? Maybe generic list.

	// Also: "specialize" instead of "resolve" ? Or specialize for lists and resolve for packs ?

//	template<auto J, typename Facade>
//	static constexpr auto resolve = f_resolve<J>(cache_module::template U_type_T<Facade>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

