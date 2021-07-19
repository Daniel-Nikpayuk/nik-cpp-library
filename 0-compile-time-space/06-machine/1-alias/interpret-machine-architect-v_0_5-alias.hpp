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

// machine alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatches:

/***********************************************************************************************************************/

// block:

	using nik_name(NIK_PREFIX, block_machine)		= typename NIK_MODULE::BD;

// variadic:

	using nik_name(NIK_PREFIX, variadic_machine)		= typename NIK_MODULE::VD;

// permutatic:

	using nik_name(NIK_PREFIX, permutatic_machine)		= typename NIK_MODULE::PD;

// distributic:

	using nik_name(NIK_PREFIX, distributic_machine)		= typename NIK_MODULE::DD;

// near linear:

	using nik_name(NIK_PREFIX, near_linear_machine)		= typename NIK_MODULE::ND;

// register:

	using nik_name(NIK_PREFIX, register_machine)		= typename NIK_MODULE::RD;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// start:

	template<typename n, auto c, auto d, auto i, auto j, auto... Vs>
	inline static constexpr auto start()
	{
		return NIK_MODULE::template start<n, c, d, i, j, Vs...>();
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

