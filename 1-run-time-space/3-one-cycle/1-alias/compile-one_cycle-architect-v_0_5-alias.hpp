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

// one cycle alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// loop:

/***********************************************************************************************************************/

// precycle:

	template<auto... cs>
	NIK_POLICY auto nik_name(NIK_PREFIX, precycle)			= NIK_MODULE::template precycle<cs...>;

// cycle:

	template<auto... cs>
	NIK_POLICY auto nik_name(NIK_PREFIX, cycle)			= NIK_MODULE::template cycle<cs...>;

// postcycle:

	template<auto... cs>
	NIK_POLICY auto nik_name(NIK_PREFIX, postcycle)			= NIK_MODULE::template postcycle<cs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// repeat:

	template<typename Spec>
	NIK_POLICY return_type_<Spec> (*nik_name(NIK_PREFIX, repeat))
		(out_type_<Spec>, end_type_<Spec>, in_type_<Spec>) =
			NIK_MODULE::template repeat<Spec>;

/***********************************************************************************************************************/

// map:

	template<typename Spec>
	NIK_POLICY return_type_<Spec> (*nik_name(NIK_PREFIX, map))
		(out_type_<Spec>, in_type_<Spec>, end_type_<Spec>) =
			NIK_MODULE::template map<Spec>;

/***********************************************************************************************************************/

// fold:

	template<typename Spec>
	NIK_POLICY return_type_<Spec> (*nik_name(NIK_PREFIX, fold))
		(out_type_<Spec>, in_type_<Spec>, end_type_<Spec>) =
			NIK_MODULE::template fold<Spec>;

/***********************************************************************************************************************/

// find first:

	template<typename Spec>
	NIK_POLICY return_type_<Spec> (*nik_name(NIK_PREFIX, find_first))
		(in_type_<Spec>, in_type_<Spec>) =
			NIK_MODULE::template find_first<Spec>;

/***********************************************************************************************************************/

// find all:

	template<typename Spec>
	NIK_POLICY return_type_<Spec> (*nik_name(NIK_PREFIX, find_all))
		(out_type_<Spec>, in_type_<Spec>, end_type_<Spec>) =
			NIK_MODULE::template find_all<Spec>;

/***********************************************************************************************************************/

// zip:

	template<typename Spec>
	NIK_POLICY return_type_<Spec> (*nik_name(NIK_PREFIX, zip))
		(out_type_<Spec>, car_in_type_<Spec>, cdr_in_type_<Spec>, end_type_<Spec>) =
			NIK_MODULE::template zip<Spec>;

/***********************************************************************************************************************/

// fasten:

	template<typename Spec>
	NIK_POLICY return_type_<Spec> (*nik_name(NIK_PREFIX, fasten))
		(out_type_<Spec>, car_in_type_<Spec>, cdr_in_type_<Spec>, end_type_<Spec>) =
			NIK_MODULE::template fasten<Spec>;

/***********************************************************************************************************************/

// glide:

	template<typename Spec>
	NIK_POLICY return_type_<Spec> (*nik_name(NIK_PREFIX, glide))
		(out_type_<Spec>, car_in_type_<Spec>, cdr_in_type_<Spec>, end_type_<Spec>) =
			NIK_MODULE::template glide<Spec>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

