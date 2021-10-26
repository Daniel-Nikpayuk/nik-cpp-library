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

// reference alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

	template<typename T>
	NIK_POLICY bool nik_name(NIK_PREFIX, V_is_reference_T)		= NIK_MODULE::template V_is_reference_T<T>;

/***********************************************************************************************************************/

// specifiers:

	using nik_name(NIK_PREFIX, Reference)				= typename NIK_MODULE::Reference;

	template<auto V>
	NIK_POLICY bool nik_name(NIK_PREFIX, is_to_reference)		= NIK_MODULE::template is_to_reference<V>;

	template<auto V>
	NIK_POLICY bool nik_name(NIK_PREFIX, is_from_reference)		= NIK_MODULE::template is_from_reference<V>;

/***********************************************************************************************************************/

// modify:

	template<typename T, auto V>
	using nik_name(NIK_PREFIX, T_reference_modify_TxV)	= typename NIK_MODULE::template T_reference_modify_TxV<T, V>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

