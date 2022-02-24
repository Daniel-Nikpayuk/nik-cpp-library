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

// cache source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// auto subcategories:

/***********************************************************************************************************************/

// typename to auto:

private:

	template<typename T>						// Unsafe to use directly,
	static constexpr void type_map(T) { }				// as T cannot equal void.
									// use U_type_T instead:

	template<typename T>						// This works because as a variable template it has
	static constexpr auto get_type_map = type_map<T*>;		// a partial specialization defined outside of this module.
									// It pattern matches references and handles them separately.

public:

	template<typename T>						// This implementation was chosen
	static constexpr auto U_type_T = get_type_map<T>;		// as it simplifies the special
									// case when T == void.

	template<typename T>				// T_decltype(_type)_T:
	using T_decltype_T				= decltype(U_type_T<T>);

	template<auto V>				// U_(type_)decltype_V:
	static constexpr auto U_decltype_V	 	= U_type_T<decltype(V)>;

/***********************************************************************************************************************/

// auto to typename (recovery):

private:

	template<typename> struct pattern_match_map_type;

	template<typename T>
	struct pattern_match_map_type<nik_avpcr(T*)>
	{
		using pretype = T;
	};

	template<typename T>
	struct pattern_match_map_type<void(*)(T*)>
	{
		using pretype = T;
	};

	template<typename T>
	struct pattern_match_map_type<nik_avpcr(T&)>
	{
		using pretype = T&;
	};

	template<typename T>
	struct pattern_match_map_type<void(*)(T&)>
	{
		using pretype = T&;
	};

public:

		// Use the fast version when possible.
		// (when T has an empty constructor/destructor)

	template<typename T>
	using T_pretype_T = typename pattern_match_map_type<T>::pretype;

	template<typename T>
	static constexpr auto U_pretype_T = U_type_T<T_pretype_T<T>>;

	template<auto TMap>
	using T_type_U = typename pattern_match_map_type<decltype(TMap)>::pretype;

private:

	template<typename T>
	static constexpr T type_map_to_init_type(nik_avpcr(T*))
	{
		return { };
	}

public:

	template<auto TMap>
	using T_fast_type_U = decltype(type_map_to_init_type(TMap));	// Does not work with type references.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// typename subcategories:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// typename:

	template<typename...> struct typename_pack { };

	template<typename... Ts>
	using R_pack_Ts = typename_pack<Ts...>;

	template<typename... Ts>
	static constexpr auto U_pack_Ts = U_type_T<typename_pack<Ts...>>;

/***********************************************************************************************************************/

// is typename pack:

public:

	template<typename T>
	static constexpr bool V_is_typename_pack_T = false;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// auto:

	template<auto...> struct auto_pack { };

	template<auto... Vs>
	using S_pack_Vs = auto_pack<Vs...>;

	template<auto... Vs>
	static constexpr auto U_pack_Vs = U_type_T<auto_pack<Vs...>>;

/***********************************************************************************************************************/

// is auto pack:

public:

	template<typename T>
	static constexpr bool V_is_auto_pack_T = false;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// typename template:

	template<template<typename...> class...> struct typename_template_pack { };

	template<template<typename...> class... As>
	using C_pack_As = typename_template_pack<As...>;

	template<template<typename...> class... As>
	static constexpr auto U_pack_As = U_type_T<typename_template_pack<As...>>;

/***********************************************************************************************************************/

// is typename template pack:

public:

	template<typename T>
	static constexpr bool V_is_typename_template_pack_T = false;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// auto template:

	template<template<auto...> class...> struct auto_template_pack { };

	template<template<auto...> class... Bs>
	using D_pack_Bs = auto_template_pack<Bs...>;

	template<template<auto...> class... Bs>
	static constexpr auto U_pack_Bs = U_type_T<auto_template_pack<Bs...>>;

/***********************************************************************************************************************/

// is auto template pack:

public:

	template<typename T>
	static constexpr bool V_is_auto_template_pack_T = false;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identity type:

/***********************************************************************************************************************/

public:

	template<typename T1, typename T2>			// This works because as a variable template it has
	static constexpr bool V_equal_TxT = false;		// a partial specialization defined outside of this module.
								// It pattern matches reflexivity and handles it separately.

	template<typename T1, typename T2>
	static constexpr bool V_not_equal_TxT = ! V_equal_TxT<T1, T2>;

	//

	template<auto V1, auto V2>
	static constexpr bool V_equal_VxV = V_equal_TxT<auto_pack<V1>, auto_pack<V2>>;

	template<auto V1, auto V2>
	static constexpr bool V_not_equal_VxV = V_not_equal_TxT<auto_pack<V1>, auto_pack<V2>>;

	//

	template<auto U1, auto U2>
	static constexpr bool V_equal_UxU = V_equal_TxT<T_type_U<U1>, T_type_U<U2>>;

	template<auto U1, auto U2>
	static constexpr bool V_not_equal_UxU = V_not_equal_TxT<T_type_U<U1>, T_type_U<U2>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identifiers (convenience aliases):

/***********************************************************************************************************************/

	template<typename T> static constexpr bool V_equals_void		= V_equal_TxT<T, void>;
	template<typename T> static constexpr bool V_equals_char_ptr		= V_equal_TxT<T, char*>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

