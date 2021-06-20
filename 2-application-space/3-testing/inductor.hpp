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

#include<cstdio>
#include"inductor_modules.hpp"

/***********************************************************************************************************************/

namespace ocli_testing
{
	using namespace list_operators;

/***********************************************************************************************************************/

	constexpr char c73() { return char(73); }

	//

	template<typename Type>
	constexpr Type square(Type x) { return x*x; }

//	template<auto cont>
//	using cp_square = return_precomposition<square<int>, cont>;

	//

	template<typename Type>
	constexpr Type twice(Type x) { return 2*x; }

//	template<auto cont>
//	using cp_twice = return_precomposition<twice<int>, cont>;

/***********************************************************************************************************************/

	void _void_() { }

	int main(int argc, char *argv[])
	{

	//	constexpr auto t = U_type_T<int*>;

	//	printf("%s\n", V_is_pointer_T<T_type_U<t>> ? "true" : "false");
	//	printf("%s\n", V_is_reference_T<T_type_U<t>> ? "true" : "false");

	//	printf("%s\n", V_equal_TxT<out_type<_void_>, void> ? "true" : "false");
	//	printf("%s\n", V_equal_TxT<in_type<_void_>, void> ? "true" : "false");

	//	printf("%s\n", V_equal_TxT<out_type<c73>, void> ? "true" : "false");
	//	printf("%s\n", V_equal_TxT<in_type<c73>, void> ? "true" : "false");

	//	printf("%s\n", V_equal_TxT<int, int> ? "true" : "false");
	//	printf("%s\n", V_equal_TxT<int, int*> ? "true" : "false");
	//	printf("%s\n", V_equal_TxT<int, int&> ? "true" : "false");
	//	printf("%s\n", V_equal_TxT<int*, int&> ? "true" : "false");
	//	printf("%s\n", V_equal_TxT<int&, int&> ? "true" : "false");

	//	printf("%s\n", V_value_S<S_is_id_keyword_or_cast<5>> ? "true" : "false");
	//	printf("%s\n", V_value_S<S_is_id_keyword_or_cast<twice<int>>> ? "true" : "false");
	//	printf("%s\n", V_value_S<S_is_id_keyword_or_cast<id<int>>> ? "true" : "false");
	//	printf("%s\n", V_value_S<S_is_id_keyword_or_cast<_id_>> ? "true" : "false");
	//	printf("%s\n", V_value_S<S_is_id_keyword_or_cast<_void_>> ? "true" : "false");
	//	printf("%s\n", V_value_S<S_is_id_keyword_or_cast<c73>> ? "true" : "false");

	//	using cp_f		= S__T_cp_endopose_FxF__V<cp_square, cp_twice>;
	//	using cp_g		= S__T_cp_endopose_FxF__V<cp_twice, cp_square>;

	//	constexpr auto f	= V_value_S<cp_f::result<id<int>>>;
	//	constexpr auto g	= V_value_S<cp_g::result<id<int>>>;
	//	printf("%d\n", f(5)); // prints: 50
	//	printf("%d\n", g(5)); // prints: 100

	//	using cp_h		= S_cp_function_opt<twice<int>, _id_>;
	//	using cp_i		= S_cp_function_opt<_id_, _id_>;

	//	constexpr auto h	= V_value_S<cp_h>;
	//	constexpr auto i	= V_value_S<cp_i>;

	//	printf("%s\n", V_value_S<S_is_id_keyword_or_cast<h>> ? "true" : "false");
	//	printf("%s\n", V_value_S<S_is_id_keyword_or_cast<i>> ? "true" : "false");

	//	printf("%d\n", h(5)); // prints: 50

		return 0;
	}

/***********************************************************************************************************************/

}

