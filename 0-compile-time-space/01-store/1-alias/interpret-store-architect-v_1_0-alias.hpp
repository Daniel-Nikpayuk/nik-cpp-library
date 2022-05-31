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

// alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// auto subcategories:

/***********************************************************************************************************************/

// typename to auto:

	template<typename T>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_store_T)		= NIK_MODULE::template U_store_T<T>;

/***********************************************************************************************************************/

// auto to typename:

	template<typename T>
	using nik_name(NIK_PREFIX, T_restore_T)			= typename NIK_MODULE::template T_restore_T<T>;

	template<typename T>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_restore_T)	= NIK_MODULE::template U_restore_T<T>;

	template<auto U>
	using nik_name(NIK_PREFIX, T_store_U)			= typename NIK_MODULE::template T_store_U<U>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// packs:

/***********************************************************************************************************************/

	template<auto... Vs>
	using nik_name(NIK_PREFIX, auto_pack)			= typename NIK_MODULE::template auto_pack<Vs...>;

	template<typename... Ts>
	using nik_name(NIK_PREFIX, typename_pack)		= typename NIK_MODULE::template typename_pack<Ts...>;

	template<template<auto...> class... Bs>
	using nik_name(NIK_PREFIX, auto_template_pack)		= typename NIK_MODULE::template auto_template_pack<Bs...>;

	template<template<typename...> class... As>
	using nik_name(NIK_PREFIX, typename_template_pack)	= typename NIK_MODULE::template typename_template_pack<As...>;

	//

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_pack_Vs)		= NIK_MODULE::template U_pack_Vs<Vs...>;

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_pack_Ts)		= NIK_MODULE::template U_pack_Ts<Ts...>;

	template<template<auto...> class... Bs>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_pack_Bs)		= NIK_MODULE::template U_pack_Bs<Bs...>;

	template<template<typename...> class... As>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_pack_As)		= NIK_MODULE::template U_pack_As<As...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// generic:

/***********************************************************************************************************************/

	using nik_name(NIK_PREFIX, StoreKey)			= typename NIK_MODULE::StoreKey;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_StoreApply)	= NIK_MODULE::template U_StoreApply<>;	// braces prevent
													// linking warning.

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, store_apply)	= NIK_MODULE::generic_module::template apply // braces prevent
								<					     // linking warning.
									NIK_MODULE::template U_StoreApply<>, Vs...
								>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

