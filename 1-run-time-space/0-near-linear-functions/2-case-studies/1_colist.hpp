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

// colist:

	using namespace function_space;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

	struct S_is_five		{ template<auto x> static constexpr bool result = (x == 5); };
	struct S_otherwise		{ template<auto x> static constexpr bool result = true; };

	struct S_square			{ template<auto x> static constexpr auto result = x*x; };
	struct S_plus_five		{ template<auto x> static constexpr auto result = x+5; };

	//

	constexpr auto is_five		= U_type_T<S_is_five>;
	constexpr auto otherwise	= U_type_T<S_otherwise>;

	constexpr auto square		= U_type_T<S_square>;
	constexpr auto plus_five	= U_type_T<S_plus_five>;

	//

	template<auto x, auto y>
	constexpr auto func = machine_space::pack_colist
	<
		x,		y,		false, // default

		is_five,	square,
		otherwise,	plus_five
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

