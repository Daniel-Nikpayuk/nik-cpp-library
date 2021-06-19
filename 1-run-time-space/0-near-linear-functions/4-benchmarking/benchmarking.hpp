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

// benchmarking:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<typename OutIter, typename InType>
	auto make_range(OutIter o, InType i, InType e)
	{
		while (i != e) *(o++) = square<InType>(i++);
	}

	template<typename InIter>
	static constexpr void make_range(InIter i, InIter e)
	{
		using Type = T_pointer_type_T<InIter>;

		for (Type k = 0; i != e; ++i, ++k)
		{
			*i = k;
		}
	}

/***********************************************************************************************************************/

	template<typename InIter>
	static constexpr void print_array(InIter i, InIter e)
	{
		using Type		= pointer_type<InIter>;

		while (i != e) print<Type>(*(i++));
		printf("%s", "\n");
	}

