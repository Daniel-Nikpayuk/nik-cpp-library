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

// constant alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

	NIK_POLICY auto nik_name(NIK_PREFIX, _na_)			= NIK_MODULE::_na_;

	using nik_name(NIK_PREFIX, _nt_)				= typename NIK_MODULE::_nt_;

	template<auto... Vs>
	using nik_name(NIK_PREFIX, _NA_)				= typename NIK_MODULE::template _NA_<Vs...>;

	template<typename... Ts>
	using nik_name(NIK_PREFIX, _NT_)				= typename NIK_MODULE::template _NT_<Ts...>;

	template<template<auto...> class... Cs>
	using nik_name(NIK_PREFIX, _NC_)				= typename NIK_MODULE::template _NC_<Cs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// numeric:

	using key_type							= typename NIK_MODULE::key_type;

	NIK_POLICY auto nik_name(NIK_PREFIX, _zero)			= NIK_MODULE::_zero;
	NIK_POLICY auto nik_name(NIK_PREFIX, _one)			= NIK_MODULE::_one;
	NIK_POLICY auto nik_name(NIK_PREFIX, _two)			= NIK_MODULE::_two;
	NIK_POLICY auto nik_name(NIK_PREFIX, _three)			= NIK_MODULE::_three;
	NIK_POLICY auto nik_name(NIK_PREFIX, _four)			= NIK_MODULE::_four;
	NIK_POLICY auto nik_name(NIK_PREFIX, _five)			= NIK_MODULE::_five;
	NIK_POLICY auto nik_name(NIK_PREFIX, _six)			= NIK_MODULE::_six;
	NIK_POLICY auto nik_name(NIK_PREFIX, _seven)			= NIK_MODULE::_seven;
	NIK_POLICY auto nik_name(NIK_PREFIX, _eight)			= NIK_MODULE::_eight;
	NIK_POLICY auto nik_name(NIK_PREFIX, _nine)			= NIK_MODULE::_nine;
	NIK_POLICY auto nik_name(NIK_PREFIX, _ten)			= NIK_MODULE::_ten;

	using index_type						= typename NIK_MODULE::index_type;

	NIK_POLICY auto nik_name(NIK_PREFIX,_2_0)			= NIK_MODULE::_2_0;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_1)			= NIK_MODULE::_2_1;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_2)			= NIK_MODULE::_2_2;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_3)			= NIK_MODULE::_2_3;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_4)			= NIK_MODULE::_2_4;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_5)			= NIK_MODULE::_2_5;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_6)			= NIK_MODULE::_2_6;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_7)			= NIK_MODULE::_2_7;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_8)			= NIK_MODULE::_2_8;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_9)			= NIK_MODULE::_2_9;

	using depth_type						= typename NIK_MODULE::depth_type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// builtin types:

	NIK_POLICY auto nik_name(NIK_PREFIX, U_void)			= NIK_MODULE::U_void;
	NIK_POLICY auto nik_name(NIK_PREFIX, U_char)			= NIK_MODULE::U_char;
	NIK_POLICY auto nik_name(NIK_PREFIX, U_char_ptr)		= NIK_MODULE::U_char_ptr;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_unsigned_char)		= NIK_MODULE::U_unsigned_char;
	NIK_POLICY auto nik_name(NIK_PREFIX, U_signed_char)		= NIK_MODULE::U_signed_char;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_unsigned_short)		= NIK_MODULE::U_unsigned_short;
	NIK_POLICY auto nik_name(NIK_PREFIX, U_signed_short)		= NIK_MODULE::U_signed_short;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_unsigned_int)		= NIK_MODULE::U_unsigned_int;
	NIK_POLICY auto nik_name(NIK_PREFIX, U_signed_int)		= NIK_MODULE::U_signed_int;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_unsigned_long)		= NIK_MODULE::U_unsigned_long;
	NIK_POLICY auto nik_name(NIK_PREFIX, U_signed_long)		= NIK_MODULE::U_signed_long;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_unsigned_long_long)	= NIK_MODULE::U_unsigned_long_long;
	NIK_POLICY auto nik_name(NIK_PREFIX, U_signed_long_long)	= NIK_MODULE::U_signed_long_long;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

