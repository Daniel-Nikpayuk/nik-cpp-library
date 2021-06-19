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

// boolean alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// conditionals:

	// VxV -> V:

	template<bool is_br, auto ante, auto conse>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_if_then_else_VxV) =
		NIK_MODULE::template V_if_then_else_VxV<is_br, ante, conse>;

	// VxV -> T:

	template<bool is_br, auto ante, auto conse>
	using nik_name(NIK_PREFIX, T_if_then_else_VxV) =
		typename NIK_MODULE::template T_if_then_else_VxV<is_br, ante, conse>;

	// TxT -> T:

	template<bool is_br, typename Ante, typename Conse>
	using nik_name(NIK_PREFIX, T_if_then_else_TxT) =
		typename NIK_MODULE::template T_if_then_else_TxT<is_br, Ante, Conse>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

