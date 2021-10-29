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

// list alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

	template<typename T>
	NIK_POLICY bool nik_name(NIK_PREFIX, V_is_list_T)		= NIK_MODULE::template V_is_list_T<T>;

/***********************************************************************************************************************/

// pattern match:

	template<typename T>
	using nik_name(NIK_PREFIX, pattern_match_list)		= typename NIK_MODULE::template pattern_match_list<T>;

/***********************************************************************************************************************/

// at:

	template<typename List, auto pos, auto depth = 500>
	NIK_POLICY auto nik_name(NIK_PREFIX, at)		= NIK_MODULE::template at<List, pos, depth>;

/***********************************************************************************************************************/

// left:

	template<typename List, auto pos, auto depth = 500>
	NIK_POLICY auto nik_name(NIK_PREFIX, left)		= NIK_MODULE::template left<List, pos, depth>;

/***********************************************************************************************************************/

// right:

	template<typename List, auto pos, auto depth = 500>
	NIK_POLICY auto nik_name(NIK_PREFIX, right)	= NIK_MODULE::template right<List, pos, depth>;

/***********************************************************************************************************************/

// name:

	template<typename List>
	NIK_POLICY auto nik_name(NIK_PREFIX, name)	= NIK_MODULE::template name<List>;

/***********************************************************************************************************************/

// catenate:

	template<typename L1, typename L2, typename... Ls>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_catenate_TxTxTs)	= NIK_MODULE::template U_catenate_TxTxTs<L1, L2, Ls...>;

/***********************************************************************************************************************/

// zip:

	template<typename Op, typename L1, typename L2, typename... Ls>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_zip_TxTxTxTs)	= NIK_MODULE::template U_zip_TxTxTxTs<Op, L1, L2, Ls...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

