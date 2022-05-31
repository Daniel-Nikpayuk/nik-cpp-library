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

// types:

/***********************************************************************************************************************/

// builtin:

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

// pack:

	NIK_POLICY auto nik_name(NIK_PREFIX, U_null_Ts)			= NIK_MODULE::U_null_Ts;
	NIK_POLICY auto nik_name(NIK_PREFIX, U_null_Vs)			= NIK_MODULE::U_null_Vs;
	NIK_POLICY auto nik_name(NIK_PREFIX, U_null_As)			= NIK_MODULE::U_null_As;
	NIK_POLICY auto nik_name(NIK_PREFIX, U_null_Bs)			= NIK_MODULE::U_null_Bs;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// generic:

/***********************************************************************************************************************/

	using nik_name(NIK_PREFIX, ConstantKey)			= typename NIK_MODULE::ConstantKey;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_ConstantApply)	= NIK_MODULE::U_ConstantApply;

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, constant_apply)	= NIK_MODULE::template constant_apply<Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

