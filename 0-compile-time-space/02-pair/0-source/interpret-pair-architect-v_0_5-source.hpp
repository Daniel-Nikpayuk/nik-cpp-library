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

// pair source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

public:

	template<typename T1, typename T2>
	struct pair
	{
		T1 v1;
		T2 v2;

		constexpr pair(const T1 & _v1, const T2 & _v2) : v1(_v1), v2(_v2) { }
	};

	// constructor:

	template<auto v1, auto v2>
	static constexpr pair<decltype(v1), decltype(v2)> cons() { return pair(v1, v2); }

	// accessors:

	template<typename T1, typename T2>
	using pair_type = pair<T1, T2> (*)();

	template<auto p>
	static constexpr auto car = p().v1;

	template<auto p>
	static constexpr auto cdr = p().v2;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

