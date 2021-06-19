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

// at:

	template<typename List, auto pos, auto depth = 500>
	NIK_POLICY auto nik_name(NIK_PREFIX, list_at)		= NIK_MODULE::template list_at<List, pos, depth>;

/***********************************************************************************************************************/

// left:

	template<typename List, auto pos, auto depth = 500>
	NIK_POLICY auto nik_name(NIK_PREFIX, list_left)		= NIK_MODULE::template list_left<List, pos, depth>;

/***********************************************************************************************************************/

// right:

	template<typename List, auto pos, auto depth = 500>
	NIK_POLICY auto nik_name(NIK_PREFIX, list_right)	= NIK_MODULE::template list_right<List, pos, depth>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

