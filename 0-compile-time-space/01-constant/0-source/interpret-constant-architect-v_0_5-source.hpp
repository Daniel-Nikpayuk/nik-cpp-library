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

// constant source:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

	struct _nt_					{ };	// (not a typename)

	static constexpr void _na_()			{ }	// (not an auto)

	template<typename...>
	using _NA_					= _nt_;	// (not a typename template)

	template<auto...>
	using _NB_					= _nt_;	// (not an auto template)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// numeric:

	// [0-10]:

	using key_type = unsigned char;

	static constexpr key_type _zero		=   0;
	static constexpr key_type _one		=   1;
	static constexpr key_type _two		=   2;
	static constexpr key_type _three	=   3;
	static constexpr key_type _four		=   4;
	static constexpr key_type _five		=   5;
	static constexpr key_type _six		=   6;
	static constexpr key_type _seven	=   7;
	static constexpr key_type _eight	=   8;
	static constexpr key_type _nine		=   9;
	static constexpr key_type _ten		=  10;

	// [2^0-2^9]:

	using index_type = unsigned short;

	static constexpr index_type _2_0	=   1;
	static constexpr index_type _2_1	=   2;
	static constexpr index_type _2_2	=   4;
	static constexpr index_type _2_3	=   8;
	static constexpr index_type _2_4	=  16;
	static constexpr index_type _2_5	=  32;
	static constexpr index_type _2_6	=  64;
	static constexpr index_type _2_7	= 128;
	static constexpr index_type _2_8	= 256;
	static constexpr index_type _2_9	= 512;

	using depth_type = unsigned short;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// builtin types:

	static constexpr auto U_void			= cache_module::template U_type_T<void>;
	static constexpr auto U_char			= cache_module::template U_type_T<char>;
	static constexpr auto U_char_ptr		= cache_module::template U_type_T<char*>;

	static constexpr auto U_unsigned_char		= cache_module::template U_type_T<unsigned char>;
	static constexpr auto U_signed_char		= cache_module::template U_type_T<signed char>;

	static constexpr auto U_unsigned_short		= cache_module::template U_type_T<unsigned short>;
	static constexpr auto U_signed_short		= cache_module::template U_type_T<signed short>;

	static constexpr auto U_unsigned_int		= cache_module::template U_type_T<unsigned int>;
	static constexpr auto U_signed_int		= cache_module::template U_type_T<signed int>;

	static constexpr auto U_unsigned_long		= cache_module::template U_type_T<unsigned long>;
	static constexpr auto U_signed_long		= cache_module::template U_type_T<signed long>;

	static constexpr auto U_unsigned_long_long	= cache_module::template U_type_T<unsigned long long>;
	static constexpr auto U_signed_long_long	= cache_module::template U_type_T<signed long long>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

