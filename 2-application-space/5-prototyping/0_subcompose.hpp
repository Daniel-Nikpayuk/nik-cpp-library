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

// subcompose (experimental):

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

//	template<typename T>
//	constexpr auto id_comp = compose<id<T>, id<T>>;

/***********************************************************************************************************************/

//	using list_A = auto_pack<5, 3, 17, -9, 12>;

//	constexpr auto U_list_B = list_space::list_left<list_A, 0>;
//	constexpr auto U_list_C = list_space::list_right<list_A, 0>;
	
	//	printf(U_list_C);

/***********************************************************************************************************************/

	template<typename... FTypesL, auto f, typename... GTypes, auto g, typename... FTypesR>
	constexpr out_type<f> subcompose(FTypesL... f_args_l, GTypes... g_args, FTypesR... f_args_r)
	{
		return f(f_args_l..., g(g_args...), f_args_r...);
	}

	template<auto f, auto g, auto... uftypesl, auto... uftypesr, auto... ugtypes>
	constexpr auto f_subcompose
	(
		void(*)(auto_pack<uftypesl...> *),
		void(*)(auto_pack<uftypesr...> *),
		void(*)(auto_pack<ugtypes...>  *)
	)
	{
		return subcompose<T_type_U<uftypesl>..., f, T_type_U<ugtypes>..., g, T_type_U<uftypesr>...>;
	}

	template<auto f, auto g, auto pos>
	constexpr auto V_subcompose = f_subcompose<f, g>(in_types_left<f, pos>, in_types_right<f, pos+1>, in_types<g>);

/***********************************************************************************************************************/

	void print_int(int i) { printf("%d\n", i); }

	constexpr auto sq_print = do_compose<square<int>, print_int>;

	template<typename T>
	constexpr auto add_then_sq = safe_do_compose<add<T>, square<T>>;

	constexpr auto add_then_sq_print = safe_do_compose<add_then_sq<int>, print_int>;

	//	sq_print(5);
	//	printf("%d\n", add_then_sq<int>(5, 3));

/***********************************************************************************************************************/

	template<typename T>
	constexpr T square(T x)		{ return x*x; }

	template<typename T>
	constexpr auto sq_then_add	= V_subcompose // compose at arg 0
					<
						add<T>, square<T>, 0
					>;
	template<typename T>
	constexpr auto sum_of_squares	= V_subcompose // compose at arg 1
					<
						sq_then_add<T>, square<T>, 1

					>;

	//	printf("%d\n", sum_of_squares<int>(5, 3)); // prints: 34

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

