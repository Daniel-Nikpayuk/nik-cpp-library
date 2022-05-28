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

// pack alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block machines:

/***********************************************************************************************************************/

// at:

	template<auto d, auto n, auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, at)		= NIK_MODULE::template at<d, n, Vs...>;

// right:

	template<auto d, auto n, auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, right)	= NIK_MODULE::template right<d, n, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// permutatic machines:

/***********************************************************************************************************************/

// erase:

	template<auto d, auto pos, auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, erase)	= NIK_MODULE::template erase<d, pos, Vs...>;

// insert:

	template<auto d, auto pos, auto obj, auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, insert)	= NIK_MODULE::template insert<d, pos, obj, Vs...>;

// replace:

	template<auto d, auto pos, auto obj, auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, replace)	= NIK_MODULE::template replace<d, pos, obj, Vs...>;

// left:

	template<auto d, auto n, auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, left)		= NIK_MODULE::template left<d, n, Vs...>;

// roll:

	template<auto d, auto uact, auto V0, auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, roll)		= NIK_MODULE::template roll<d, uact, V0, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

