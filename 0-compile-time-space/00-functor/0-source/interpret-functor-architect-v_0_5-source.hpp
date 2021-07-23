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

// typename auto source:

/*
	S   - variadic_value				(typename)
	T   - type					(typename)
	U   - type_map					(constexpr auto)
	V   - value					(constexpr auto)

	B   - template<typename...> class
	C   - template<auto...> class
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// auto category:

/***********************************************************************************************************************/

// typename to auto (functor):

private:

	template<typename T>			// Unsafe to use directly,
	static constexpr void type_map(T) { }	// as T cannot equal void.
						// use U_type_T instead:

	template<typename T>
	struct get_type_map
	{
		static constexpr auto value = type_map<T*>;
	};

	template<typename T>
	struct get_type_map<T&>
	{
		static constexpr auto value = type_map<T&>;
	};

public:

	template<typename T>						// This implementation was chosen
	static constexpr auto U_type_T = get_type_map<T>::value;	// as it simplifies the special
									// case when T == void.

	template<typename T>				// T_decltype(_type)_T:
	using T_decltype_T				= decltype(U_type_T<T>);

	template<auto V>				// U_(type_)decltype_V:
	static constexpr auto U_decltype_V	 	= U_type_T<decltype(V)>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// typename category:

/***********************************************************************************************************************/

// auto to typename recovery:

private:

	template<typename> struct pattern_match_map_type;

	template<typename T>
	struct pattern_match_map_type<void(*)(T*)>
	{
		using pretype = T;
	};

	template<typename T>
	struct pattern_match_map_type<void(*const)(T*)>
	{
		using pretype = T;
	};

	template<typename T>
	struct pattern_match_map_type<void(*)(T&)>
	{
		using pretype = T&;
	};

	template<typename T>
	struct pattern_match_map_type<void(*const)(T&)>
	{
		using pretype = T&;
	};

public:

		// Use the fast version when possible.
		// (when T has an empty constructor/destructor)

	template<typename T>
	using T_pretype_T = typename pattern_match_map_type<T>::pretype;

	template<auto TMap>
	using T_type_U = typename pattern_match_map_type<decltype(TMap)>::pretype;

private:

	template<typename T>
	static constexpr T type_map_to_init_type(void(*)(T*))
	{
		return { };
	}

public:

	template<auto TMap>
	using T_fast_type_U = decltype(type_map_to_init_type(TMap));	// Does not work with type references.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic:

/***********************************************************************************************************************/

// auto:

	template<auto...> struct auto_pack				{ };

	template<auto... Vs>
	static constexpr auto U_pack_Vs = U_type_T<auto_pack<Vs...>>;

/***********************************************************************************************************************/

// is auto pack:

private:

	template<typename T>
	static constexpr bool V_is_auto_pack_U(void(*)(T))			// Unsafe to use directly,
		{ return false; }

	template<auto... Vs>
	static constexpr bool V_is_auto_pack_U(void(*)(auto_pack<Vs...>*))	// Use the following instead:
		{ return true; }

public:

	template<typename T>
	static constexpr bool V_is_auto_pack_T = V_is_auto_pack_U(U_type_T<T>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// typename:

	template<typename...> struct typename_pack			{ };

	template<typename... Ts>
	static constexpr auto U_pack_Ts = U_type_T<typename_pack<Ts...>>;

/***********************************************************************************************************************/

// is typename pack:

private:

	template<typename T>
	static constexpr bool V_is_typename_pack_U(void(*)(T))				// Unsafe to use directly,
		{ return false; }

	template<typename... Ts>
	static constexpr bool V_is_typename_pack_U(void(*)(typename_pack<Ts...>*))	// Use the following instead:
		{ return true; }

public:

	template<typename T>
	static constexpr bool V_is_typename_pack_T = V_is_typename_pack_U(U_type_T<T>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// template:

	template<template<auto...> class...> struct template_pack	{ };

	template<template<auto...> class... Cs>
	static constexpr auto U_pack_Cs = U_type_T<template_pack<Cs...>>;

/***********************************************************************************************************************/

// is template pack:

private:

	template<typename T>
	static constexpr bool V_is_template_pack_U(void(*)(T))				// Unsafe to use directly,
		{ return false; }

	template<template<auto...> class... Cs>
	static constexpr bool V_is_template_pack_U(void(*)(template_pack<Cs...>*))	// Use the following instead:
		{ return true; }

public:

	template<typename T>
	static constexpr bool V_is_template_pack_T = V_is_template_pack_U(U_type_T<T>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identity type:

/***********************************************************************************************************************/

private:

	template<typename T1, typename T2>
	static constexpr bool V_is_equal_UxU(void(*)(T1), void(*)(T2))	// Unsafe to use directly,
		{ return false; }

	template<typename T>
	static constexpr bool V_is_equal_UxU(void(*)(T), void(*)(T))	// Use the following instead:
		{ return true; }

public:

	template<auto TMap1, auto TMap2>
	static constexpr bool V_equal_UxU = V_is_equal_UxU(TMap1, TMap2);

	template<auto TMap1, auto TMap2>
	static constexpr bool V_not_equal_UxU = ! V_is_equal_UxU(TMap1, TMap2);

	//

	template<typename T1, typename T2>
	static constexpr bool V_equal_TxT = V_is_equal_UxU(U_type_T<T1>, U_type_T<T2>);

	template<typename T1, typename T2>
	static constexpr bool V_not_equal_TxT = ! V_is_equal_UxU(U_type_T<T1>, U_type_T<T2>);

	//

	template<auto V1, auto V2>
	static constexpr bool V_equal_VxV = V_is_equal_UxU(U_pack_Vs<V1>, U_pack_Vs<V2>);	// optimized

	template<auto V1, auto V2>
	static constexpr bool V_not_equal_VxV = ! V_is_equal_UxU(U_pack_Vs<V1>, U_pack_Vs<V2>);	// optimized

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identifiers (convenience aliases):

/***********************************************************************************************************************/

	template<typename T> static constexpr bool V_equals_void		= V_equal_TxT<T, void>;
	template<typename T> static constexpr bool V_equals_char_ptr		= V_equal_TxT<T, char*>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

