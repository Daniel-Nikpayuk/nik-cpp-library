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

// cache alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// auto category:

/***********************************************************************************************************************/

// typename to auto (cache):

	template<typename T>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_type_T)		= NIK_MODULE::template U_type_T<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, T_decltype_T)		= typename NIK_MODULE::template T_decltype_T<T>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_decltype_V) 	= NIK_MODULE::template U_decltype_V<V>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// typename category:

/***********************************************************************************************************************/

// auto to typename recovery:

	template<typename T>
	using nik_name(NIK_PREFIX, T_pretype_T)			= typename NIK_MODULE::template T_pretype_T<T>;

	template<typename T>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_pretype_T)	= NIK_MODULE::template U_pretype_T<T>;

	template<auto TMap>
	using nik_name(NIK_PREFIX, T_type_U)			= typename NIK_MODULE::template T_type_U<TMap>;

	//

	template<auto TMap>
	using nik_name(NIK_PREFIX, T_fast_type_U)		= typename NIK_MODULE::template T_fast_type_U<TMap>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic:

/***********************************************************************************************************************/

// auto:

	template<auto... Vs>
	using nik_name(NIK_PREFIX, auto_pack)			= typename NIK_MODULE::template auto_pack<Vs...>;

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_pack_Vs)		= NIK_MODULE::template U_pack_Vs<Vs...>;

/***********************************************************************************************************************/

// is auto pack:

	template<typename T>
	NIK_POLICY bool nik_name(NIK_PREFIX, V_is_auto_pack_T)	= NIK_MODULE::template V_is_auto_pack_T<T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// typename:

	template<typename... Ts>
	using nik_name(NIK_PREFIX, typename_pack)		= typename NIK_MODULE::template typename_pack<Ts...>;

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_pack_Ts)		= NIK_MODULE::template U_pack_Ts<Ts...>;

/***********************************************************************************************************************/

// is typename pack:

	template<typename T>
	NIK_POLICY bool nik_name(NIK_PREFIX, V_is_typename_pack_T)	= NIK_MODULE::template V_is_typename_pack_T<T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// typename template:

	template<template<typename...> class... As>
	using nik_name(NIK_PREFIX, typename_template_pack)	= typename NIK_MODULE::template typename_template_pack<As...>;

	template<template<typename...> class... As>
	using nik_name(NIK_PREFIX, C_pack_As)			= typename NIK_MODULE::template C_pack_As<As...>;

	template<template<typename...> class... As>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_pack_As)		= NIK_MODULE::template U_pack_As<As...>;

/***********************************************************************************************************************/

// is typename template pack:

	template<typename T>
	NIK_POLICY bool nik_name(NIK_PREFIX, V_is_typename_template_pack_T) =
		NIK_MODULE::template V_is_typename_template_pack_T<T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// auto template:

	template<template<auto...> class... Bs>
	using nik_name(NIK_PREFIX, auto_template_pack)		= typename NIK_MODULE::template auto_template_pack<Bs...>;

	template<template<auto...> class... Bs>
	using nik_name(NIK_PREFIX, D_pack_Bs)			= typename NIK_MODULE::template D_pack_Bs<Bs...>;

	template<template<auto...> class... Bs>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_pack_Bs)		= NIK_MODULE::template U_pack_Bs<Bs...>;

/***********************************************************************************************************************/

// is auto template pack:

	template<typename T>
	NIK_POLICY bool nik_name(NIK_PREFIX, V_is_auto_template_pack_T) =
		NIK_MODULE::template V_is_auto_template_pack_T<T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identity type:

/***********************************************************************************************************************/

	template<typename T1, typename T2>
	NIK_POLICY bool nik_name(NIK_PREFIX, V_equal_TxT)	= NIK_MODULE::template V_equal_TxT<T1, T2>;

	template<typename T1, typename T2>
	NIK_POLICY bool nik_name(NIK_PREFIX, V_not_equal_TxT)	= NIK_MODULE::template V_not_equal_TxT<T1, T2>;

	//

	template<auto V1, auto V2>
	NIK_POLICY bool nik_name(NIK_PREFIX, V_equal_VxV)	= NIK_MODULE::template V_equal_VxV<V1, V2>;

	template<auto V1, auto V2>
	NIK_POLICY bool nik_name(NIK_PREFIX, V_not_equal_VxV)	= NIK_MODULE::template V_not_equal_VxV<V1, V2>;

	//

	template<auto U1, auto U2>
	NIK_POLICY bool nik_name(NIK_PREFIX, V_equal_UxU)	= NIK_MODULE::template V_equal_UxU<U1, U2>;

	template<auto U1, auto U2>
	NIK_POLICY bool nik_name(NIK_PREFIX, V_not_equal_UxU)	= NIK_MODULE::template V_not_equal_UxU<U1, U2>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identifiers (convenience aliases):

/***********************************************************************************************************************/

	template<typename T>
	NIK_POLICY bool nik_name(NIK_PREFIX, V_equals_void)	= NIK_MODULE::template V_equals_void<T>;

	template<typename T>
	NIK_POLICY bool nik_name(NIK_PREFIX, V_equals_char_ptr)	= NIK_MODULE::template V_equals_char_ptr<T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

