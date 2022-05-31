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

// pair:

/***********************************************************************************************************************/

	template<typename T1, typename T2>
	using nik_name(NIK_PREFIX, pair)		= typename NIK_MODULE::template pair<T1, T2>;

	// C++17:

	template<auto v1, auto v2>
	NIK_POLICY auto nik_name(NIK_PREFIX, ce_pair)	= NIK_MODULE::template ce_pair<v1, v2>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// generic:

/***********************************************************************************************************************/

	using nik_name(NIK_PREFIX, PairKey)			= typename NIK_MODULE::PairKey;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_PairApply)	= NIK_MODULE::U_PairApply;

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, pair_apply)	= NIK_MODULE::template pair_apply<Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

