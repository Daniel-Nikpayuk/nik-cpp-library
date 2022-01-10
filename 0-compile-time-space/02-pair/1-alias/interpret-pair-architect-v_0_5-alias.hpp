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

// pair alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// pair:

	template<typename T1, typename T2>
	using nik_name(NIK_PREFIX, pair)		= typename NIK_MODULE::template pair<T1, T2>;

	// constructor:

	template<auto v1, auto v2>
	NIK_POLICY auto nik_name(NIK_PREFIX, cons)	= NIK_MODULE::template cons<v1, v2>;

	// accessors:

	template<typename T1, typename T2>
	using nik_name(NIK_PREFIX, pair_type)		= typename NIK_MODULE::template pair_type<T1, T2>;

	template<auto p>
	NIK_POLICY auto nik_name(NIK_PREFIX, car)	= NIK_MODULE::template car<p>;

	template<auto p>
	NIK_POLICY auto nik_name(NIK_PREFIX, cdr)	= NIK_MODULE::template cdr<p>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

