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

#include<cstdio>

	using utype = unsigned;

/***********************************************************************************************************************/

	constexpr void print_numeric_macro(const char *indent, utype num)
	{
		printf("_l_ ## %s%u _r_,", indent, num);
	}

/***********************************************************************************************************************/

	constexpr const char *n  =   "";
	constexpr const char *s  =  " ";
	constexpr const char *ss = "  ";

	constexpr void print_formatted_line(const char *indent, utype b, utype e)
	{
		printf("%s", indent);

		while (b + 1 < e)
		{
			const char *space = (b < 10) ? ss : (b < 100) ? s : n;

			print_numeric_macro(space, b++);
			printf("\t\t");
		}

		const char *space = (b < 10) ? ss : (b < 100) ? s : n;

		print_numeric_macro(space, b);

		printf("\t\t\t\\\n");
	}

/***********************************************************************************************************************/

	constexpr void print_formatted_range(const char *indent, utype e, utype cap = 4)
	{
		utype b = 0;

		for (utype c = cap; c < e; b = c, c += cap)
			print_formatted_line(indent, b, c);

		print_formatted_line(indent, b, e);
	}

/***********************************************************************************************************************/

