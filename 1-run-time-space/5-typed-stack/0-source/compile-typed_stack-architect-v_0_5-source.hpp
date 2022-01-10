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

// constant source:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

	static constexpr void _na_()			{ }	// (not an auto)

	struct _nt_					{ };	// (not a typename)

	template<auto...>
	using _NA_					= _nt_;	// (not an auto template)

	template<typename...>
	using _NT_					= _nt_;	// (not a typename template)

	template<template<auto...> class...>
	using _NC_					= _nt_;	// (not a typename template)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// numeric:

	// [0-10]:

	using index_type = unsigned char;

	static constexpr index_type _zero	=   0;
	static constexpr index_type _one	=   1;
	static constexpr index_type _two	=   2;
	static constexpr index_type _three	=   3;
	static constexpr index_type _four	=   4;
	static constexpr index_type _five	=   5;
	static constexpr index_type _six	=   6;
	static constexpr index_type _seven	=   7;
	static constexpr index_type _eight	=   8;
	static constexpr index_type _nine	=   9;
	static constexpr index_type _ten	=  10;

	// [2^0-2^9]:

	using depth_type = unsigned short;

	static constexpr depth_type _2_0	=   1;
	static constexpr depth_type _2_1	=   2;
	static constexpr depth_type _2_2	=   4;
	static constexpr depth_type _2_3	=   8;
	static constexpr depth_type _2_4	=  16;
	static constexpr depth_type _2_5	=  32;
	static constexpr depth_type _2_6	=  64;
	static constexpr depth_type _2_7	= 128;
	static constexpr depth_type _2_8	= 256;
	static constexpr depth_type _2_9	= 512;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// builtin types:

	static constexpr auto U_void			= functor_module::template U_type_T<void>;
	static constexpr auto U_char			= functor_module::template U_type_T<char>;
	static constexpr auto U_char_ptr		= functor_module::template U_type_T<char*>;

	static constexpr auto U_unsigned_char		= functor_module::template U_type_T<unsigned char>;
	static constexpr auto U_signed_char		= functor_module::template U_type_T<signed char>;

	static constexpr auto U_unsigned_short		= functor_module::template U_type_T<unsigned short>;
	static constexpr auto U_signed_short		= functor_module::template U_type_T<signed short>;

	static constexpr auto U_unsigned_int		= functor_module::template U_type_T<unsigned int>;
	static constexpr auto U_signed_int		= functor_module::template U_type_T<signed int>;

	static constexpr auto U_unsigned_long		= functor_module::template U_type_T<unsigned long>;
	static constexpr auto U_signed_long		= functor_module::template U_type_T<signed long>;

	static constexpr auto U_unsigned_long_long	= functor_module::template U_type_T<unsigned long long>;
	static constexpr auto U_signed_long_long	= functor_module::template U_type_T<signed long long>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

