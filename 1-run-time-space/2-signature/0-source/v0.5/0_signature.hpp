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

// signature source:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<typename...> class signature;

	// prevents name clashes:

	template<typename... Ts>
	using resolve_signature = signature<Ts...>;

/***********************************************************************************************************************/

// accessors:

	// members 0-5:

		NIK_DEFINE_ACCESSORS(0)
		NIK_DEFINE_ACCESSORS(1)
		NIK_DEFINE_ACCESSORS(2)
		NIK_DEFINE_ACCESSORS(3)
		NIK_DEFINE_ACCESSORS(4)
		NIK_DEFINE_ACCESSORS(5)

/***********************************************************************************************************************/

// signatures:

	// specializations 1-6:

		NIK_DEFINE_SIGNATURE(1)
		NIK_DEFINE_SIGNATURE(2)
		NIK_DEFINE_SIGNATURE(3)
		NIK_DEFINE_SIGNATURE(4)
		NIK_DEFINE_SIGNATURE(5)
		NIK_DEFINE_SIGNATURE(6)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

