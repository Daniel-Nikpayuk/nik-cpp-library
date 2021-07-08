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

// compose source:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

/***********************************************************************************************************************/

	struct S_is_id_keyword
	{
		template<auto f>
		static constexpr bool result = V_equal_VxV<f, U_id>;
	};

	static constexpr auto U_is_id_keyword = U_type_T<S_is_id_keyword>;

	template<auto f>
	static constexpr bool is_id_keyword = S_is_id_keyword::template result<f>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// composition:

/***********************************************************************************************************************/

// safe compose:

	struct S_safe_compose
	{
		template<typename, typename> struct S_pattern_match;

		template<typename FOutType, typename CType, typename... GInTypes>
		struct S_pattern_match<FOutType(*)(CType), CType(*)(GInTypes...)>
		{
			template<auto f, auto g>
			static constexpr FOutType result(GInTypes... args) { return f(g(args...)); }
		};

		template<auto f, auto g>
		static constexpr auto result = S_pattern_match<decltype(f), decltype(g)>::template result<f, g>;
	};

	static constexpr auto U_safe_compose = U_type_T<S_safe_compose>;

	template<auto f, auto g>
	static constexpr auto safe_compose = S_safe_compose::template result<f, g>;

/***********************************************************************************************************************/

// safe do compose:

	struct S_safe_do_compose
	{
		template<auto f, auto g>
		static constexpr auto result = S_safe_compose::template result<g, f>;
	};

	static constexpr auto U_safe_do_compose = U_type_T<S_safe_do_compose>;

	template<auto f, auto g>
	static constexpr auto safe_do_compose = S_safe_compose::template result<g, f>;

/***********************************************************************************************************************/

// compose:

	struct S_compose
	{
		template<auto f, auto g>
		static constexpr out_type<f> result(in_type<g> x) { return f(g(x)); }
	};

	static constexpr auto U_compose = U_type_T<S_compose>;

	template<auto f, auto g>
	static constexpr auto compose = S_compose::template result<f, g>;

/***********************************************************************************************************************/

// do compose:

	struct S_do_compose
	{
		template<auto f, auto g>
		static constexpr out_type<g> result(in_type<f> x) { return g(f(x)); }
	};

	static constexpr auto U_do_compose = U_type_T<S_do_compose>;

	template<auto f, auto g>
	static constexpr auto do_compose = S_do_compose::template result<f, g>;

/***********************************************************************************************************************/

// do chain compose:

	template<auto f0, auto... fs>
	static constexpr auto do_chain_compose = pack_module::template roll<500, U_do_compose, f0, fs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// optimized composition:

/***********************************************************************************************************************/

// opt compose:

	struct S_opt_compose
	{
		template<auto f, auto g>
		static constexpr auto f_result()
		{
			if constexpr      (is_id_keyword<f>)	return g;
			else if constexpr (is_id_keyword<g>)	return f;
			else					return compose<f, g>;
		};

		template<auto f, auto g>
		static constexpr auto result = f_result<f, g>();
	};

	static constexpr auto U_opt_compose = U_type_T<S_opt_compose>;

	template<auto f, auto g>
	static constexpr auto opt_compose = S_opt_compose::template f_result<f, g>();

/***********************************************************************************************************************/

// opt do compose:

	struct S_opt_do_compose
	{
		template<auto f, auto g>
		static constexpr auto result = S_opt_compose::template f_result<g, f>();
	};

	static constexpr auto U_opt_do_compose = U_type_T<S_opt_do_compose>;

	template<auto f, auto g>	// S_opt_compose, not S_opt_do_compose
	static constexpr auto opt_do_compose = S_opt_compose::template f_result<g, f>();

/***********************************************************************************************************************/

// opt do chain compose:

	template<auto f0, auto... fs>
	static constexpr auto opt_do_chain_compose = pack_module::template roll<500, U_opt_do_compose, f0, fs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// subcomposition:

/***********************************************************************************************************************/

	struct S_subcompose
	{
		template<typename, typename, typename> struct S_pattern_match;

		template<auto... FTypesL, auto... FTypesR, auto... GTypes>
		struct S_pattern_match<auto_pack<FTypesL...>, auto_pack<FTypesR...>, auto_pack<GTypes...>>
		{
			template<auto f, auto g>
			static constexpr out_type<f> result
			(
				T_type_U<FTypesL>... f_args_l,
				T_type_U<GTypes>... g_args,
				T_type_U<FTypesR>... f_args_r
			)
			{
				return f(f_args_l..., g(g_args...), f_args_r...);
			}
		};

		template<auto f, auto g, auto pos>
		static constexpr auto result = S_pattern_match
		<
			in_types_left<f, pos>,
			in_types_right<f, pos+1>,
			in_types<g>

		>::template result<f, g>;
	};

	static constexpr auto U_subcompose = U_type_T<S_subcompose>;

	template<auto f, auto g, auto pos>
	static constexpr auto subcompose = S_subcompose::template result<f, g, pos>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// higher orders:

/***********************************************************************************************************************/

// test:

	template<auto op, auto l0, auto... ls>
	static constexpr bool test(in_type<l0> x)
	{
		return op(l0(x), ls(x)...);
	}

/***********************************************************************************************************************/

// assign:

	template<auto r, auto op, auto... ls>
	static constexpr in_type<r> assign(in_type<r> x)
	{
		r(x) = op(ls(x)...);

		return x;
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

