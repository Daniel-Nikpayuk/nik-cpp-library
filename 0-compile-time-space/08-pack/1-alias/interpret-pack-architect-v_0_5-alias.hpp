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

// pack alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block machines:

/***********************************************************************************************************************/

// pack at:

	template<auto d, auto n, auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, pack_at)		= NIK_MODULE::template pack_at<d, n, Vs...>;

// pack right:

	template<auto d, auto n, auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, pack_right)	= NIK_MODULE::template pack_right<d, n, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// permutatic machines:

/***********************************************************************************************************************/

// pack erase:

	template<auto d, auto pos, auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, pack_erase)	= NIK_MODULE::template pack_erase<d, pos, Vs...>;

// pack insert:

	template<auto d, auto pos, auto obj, auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, pack_insert)	= NIK_MODULE::template pack_insert<d, pos, obj, Vs...>;

// pack replace:

	template<auto d, auto pos, auto obj, auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, pack_replace)	= NIK_MODULE::template pack_replace<d, pos, obj, Vs...>;

// pack left:

	template<auto d, auto n, auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, pack_left)		= NIK_MODULE::template pack_left<d, n, Vs...>;

// pack roll:

	template<auto d, auto uact, auto V0, auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, pack_roll)		= NIK_MODULE::template pack_roll<d, uact, V0, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

