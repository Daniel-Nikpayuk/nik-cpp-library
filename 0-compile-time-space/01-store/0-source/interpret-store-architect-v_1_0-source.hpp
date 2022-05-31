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

// source:

namespace nik { nik_begin_module(interpret, store, architect, NIK_VERSION, NIK_VENDOR)

public:

	using generic_module	= NIK_GENERIC_MODULE;
	using key_type		= typename NIK_GENERIC_MODULE::key_type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// auto subcategories:

/***********************************************************************************************************************/

// typename to auto:

private:

	template<typename T>				// Unsafe to use directly, as T cannot equal void.
	nik_ces void store(T) { }			// Use U_store_T instead.

	template<typename T>
	nik_ces auto resolve_store = store<T*>;		// This pattern matches references and handles them separately.

public:

	template<typename T>
	nik_ces auto U_store_T = resolve_store<T>;

/***********************************************************************************************************************/

// auto to typename:

private:

	template<typename T> struct match			{ using result = T; };
	template<typename T> struct match<void(*)(T&)>		{ using result = T&; };
	template<typename T> struct match<void(*const)(T&)>	{ using result = T&; };
	template<typename T> struct match<void(*)(T*)>		{ using result = T; };
	template<typename T> struct match<void(*const)(T*)>	{ using result = T; };

public:

	template<typename T>
	using T_restore_T = typename match<T>::result;

	template<typename T>
	nik_ces auto U_restore_T = resolve_store<T_restore_T<T>>;

	template<auto U>
	using T_store_U = T_restore_T<decltype(U)>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// packs:

/***********************************************************************************************************************/

	template<auto...>				struct auto_pack		{ };
	template<typename...>				struct typename_pack		{ };
	template<template<auto...> class...>		struct auto_template_pack	{ };
	template<template<typename...> class...>	struct typename_template_pack	{ };

	template<auto... Vs>
	nik_ces auto U_pack_Vs = resolve_store<auto_pack<Vs...>>;

	template<typename... Ts>
	nik_ces auto U_pack_Ts = resolve_store<typename_pack<Ts...>>;

	template<template<auto...> class... Bs>
	nik_ces auto U_pack_Bs = resolve_store<auto_template_pack<Bs...>>;

	template<template<typename...> class... As>
	nik_ces auto U_pack_As = resolve_store<typename_template_pack<As...>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// generic:

/***********************************************************************************************************************/

// keys:

	struct StoreKey
	{
		nik_ces key_type id					=  0;

		nik_ces key_type pack					=  1;

		nik_ces key_type same					=  2;
		nik_ces key_type is_store				=  3;

		nik_ces key_type is_auto_pack				=  4;
		nik_ces key_type is_typename_pack			=  5;
		nik_ces key_type is_auto_template_pack			=  6;
		nik_ces key_type is_typename_template_pack		=  7;

		nik_ces key_type dimension				=  8;
	};

/***********************************************************************************************************************/

// apply:

private:

	template<key_type Key>
	nik_ces void apply_assert()
	{
		constexpr bool is_key = (Key < StoreKey::dimension); // assumes key_type is unsigned.

		static_assert(is_key, "This store key has not been implemented.");
	}

public:

	struct StoreApply
	{
		template<key_type Key, auto... Vs>
		nik_ces auto result = apply_assert<Key>();
	};

	template<typename T = StoreApply>		// All modules with generics are expected to provide a U_*Apply.
	nik_ces auto U_StoreApply = U_store_T<T>;	// This is the only one which takes braces, otherwise clang warns
							// of the inline function store(T) being undefined.

	// Store apply cannot be defined here,
	// but is still defined in the alias import.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

	friend nik_module(interpret, machine, architect, NIK_VERSION, NIK_VENDOR);

nik_end_module(interpret, store, architect, NIK_VERSION, NIK_VENDOR)

// variable template specializations:

	template<typename T>
	nik_ce auto NIK_MODULE::resolve_store<T&> = NIK_MODULE::template store<T&>;

// apply:

	#define NIK_STORE_APPLY NIK_MODULE::StoreApply::result
	#define NIK_STORE_KEY NIK_MODULE::StoreKey

	// pack:

		template<auto... Vs>
		nik_ce auto NIK_STORE_APPLY<NIK_STORE_KEY::pack, Vs...> = NIK_MODULE::resolve_store<auto_pack<Vs...>>;

	// same:

		template<auto V0, auto V1>
		nik_ce auto NIK_STORE_APPLY<NIK_STORE_KEY::same, V0, V1> = false;

		template<auto V>
		nik_ce auto NIK_STORE_APPLY<NIK_STORE_KEY::same, V, V> = true;

	// is store:

		template<auto V>
		nik_ce bool NIK_STORE_APPLY<NIK_STORE_KEY::is_store, V> = false;

		template<typename T, nik_vp(p)(T*)>
		nik_ce bool NIK_STORE_APPLY<NIK_STORE_KEY::is_store, p> = true;

		template<typename T, nik_vp(p)(T&)>
		nik_ce bool NIK_STORE_APPLY<NIK_STORE_KEY::is_store, p> = true;

	// is auto pack:

		template<auto V>
		nik_ce bool NIK_STORE_APPLY<NIK_STORE_KEY::is_auto_pack, V> = false;

		template<auto... Vs, nik_vp(p)(NIK_MODULE::auto_pack<Vs...>*)>
		nik_ce bool NIK_STORE_APPLY<NIK_STORE_KEY::is_auto_pack, p> = true;

	// is typename pack:

		template<auto V>
		nik_ce bool NIK_STORE_APPLY<NIK_STORE_KEY::is_typename_pack, V> = false;

		template<typename... Ts, nik_vp(p)(NIK_MODULE::typename_pack<Ts...>*)>
		nik_ce bool NIK_STORE_APPLY<NIK_STORE_KEY::is_typename_pack, p> = true;

	// is auto template pack:

		template<auto V>
		nik_ce bool NIK_STORE_APPLY<NIK_STORE_KEY::is_auto_template_pack, V> = false;

		template<template<auto...> class... Bs, nik_vp(p)(NIK_MODULE::auto_template_pack<Bs...>*)>
		nik_ce bool NIK_STORE_APPLY<NIK_STORE_KEY::is_auto_template_pack, p> = true;

	// is typename template pack:

		template<auto V>
		nik_ce bool NIK_STORE_APPLY<NIK_STORE_KEY::is_typename_template_pack, V> = false;

		template<template<typename...> class... As, nik_vp(p)(NIK_MODULE::typename_template_pack<As...>*)>
		nik_ce bool NIK_STORE_APPLY<NIK_STORE_KEY::is_typename_template_pack, p> = true;

	#undef NIK_STORE_KEY
	#undef NIK_STORE_APPLY
}

