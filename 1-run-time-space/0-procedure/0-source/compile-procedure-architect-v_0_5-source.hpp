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

// procedure source:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomics:

/***********************************************************************************************************************/

// identity:

	template<typename T>
	static constexpr auto id = S_id::template result<T>;

/***********************************************************************************************************************/

// constants:

	template<auto V>
	static constexpr auto constant = S_constant<V>::result;

/***********************************************************************************************************************/

// arithmetic operators:

	template<typename T, typename U>
	static constexpr auto add = S_add::template result<T, U>;

	template<typename T, typename U>
	static constexpr auto subtract = S_subtract::template result<T, U>;

	template<typename T, typename U>
	static constexpr auto multiply = S_multiply::template result<T, U>;

	template<typename T, typename U>
	static constexpr auto divide = S_divide::template result<T, U>;

	template<typename T, typename U>
	static constexpr auto modulo = S_modulo::template result<T, U>;

	template<typename T, auto V>
	static constexpr auto add_by = S_add_by<V>::template result<T>;

	template<typename T, auto V>
	static constexpr auto subtract_by = S_subtract_by<V>::template result<T>;

	template<typename T, auto V>
	static constexpr auto multiply_by = S_multiply_by<V>::template result<T>;

	template<typename T, auto V>
	static constexpr auto divide_by = S_divide_by<V>::template result<T>;

	template<typename T, auto V>
	static constexpr auto modulo_by = S_modulo_by<V>::template result<T>;

/***********************************************************************************************************************/

// comparative operators:

	template<typename T, typename U>
	static constexpr auto max = S_max::template result<T, U>;

	template<typename T, typename U>
	static constexpr auto min = S_min::template result<T, U>;

/***********************************************************************************************************************/

// predicates:

	template<typename T, typename U>
	static constexpr auto equal = S_equal::template result<T, U>;

	template<typename T, typename U>
	static constexpr auto not_equal = S_not_equal::template result<T, U>;

	template<typename T, typename U>
	static constexpr auto less_than = S_less_than::template result<T, U>;

	template<typename T, typename U>
	static constexpr auto less_than_or_equal = S_less_than_or_equal::template result<T, U>;

	template<typename T, typename U>
	static constexpr auto greater_than = S_greater_than::template result<T, U>;

	template<typename T, typename U>
	static constexpr auto greater_than_or_equal = S_greater_than_or_equal::template result<T, U>;

	template<typename T, auto V>
	static constexpr auto is_value = S_is_value<V>::template result<T>;

	template<typename T, auto V>
	static constexpr auto not_value = S_not_value<V>::template result<T>;

	template<typename T, auto V>
	static constexpr auto is_less_than = S_is_less_than<V>::template result<T>;

	template<typename T, auto V>
	static constexpr auto is_less_than_or_equal = S_is_less_than_or_equal<V>::template result<T>;

	template<typename T, auto V>
	static constexpr auto is_greater_than = S_is_greater_than<V>::template result<T>;

	template<typename T, auto V>
	static constexpr auto is_greater_than_or_equal = S_is_greater_than_or_equal<V>::template result<T>;

/***********************************************************************************************************************/

// boolean operators:

	static constexpr auto conjunction = S_conjunction::result;

	static constexpr auto disjunction = S_disjunction::result;

	static constexpr auto implication = S_implication::result;

	static constexpr auto equivalence = S_equivalence::result;

	static constexpr auto negation = S_negation::result;

/***********************************************************************************************************************/

// dereference operators:

	template<typename T>
	static constexpr auto dereference = S_dereference::template result<T>;

	template<typename T>
	static constexpr auto cdereference = S_cdereference::template result<T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// reflection:

/***********************************************************************************************************************/

// match:

	struct S_is_function
	{
		template<typename T>
		static constexpr bool f_result(T) { return false; }

		template<typename OutType, typename... InTypes>
		static constexpr bool f_result(OutType(*f)(InTypes...)) { return true; }

		template<auto f>
		static constexpr bool result = f_result(f);
	};

	static constexpr auto U_is_function = U_type_T<S_is_function>;

	template<auto f>
	static constexpr bool is_function = S_is_function::f_result(f);

/***********************************************************************************************************************/

// arity:

	struct S_arity
	{
		template<typename OutType, typename... InTypes>
		static constexpr auto f_result(OutType(*f)(InTypes...))
		{
			return sizeof...(InTypes);
		}

		template<auto f>
		static constexpr auto result = f_result(f);
	};

	static constexpr auto U_arity = U_type_T<S_arity>;

	template<auto f>
	static constexpr auto arity = S_arity::f_result(f);

/***********************************************************************************************************************/

// is n-ary:

	struct S_is_n_ary
	{
		template<auto f, auto n>
		static constexpr bool result = (S_arity::f_result(f) == n);
	};

	static constexpr auto U_is_n_ary = U_type_T<S_is_n_ary>;

	template<auto f, auto n>
	static constexpr bool is_n_ary = (S_arity::f_result(f) == n);

/***********************************************************************************************************************/

// out type:

	struct S_out_type
	{
		template<typename OutType, typename... InTypes>
		static constexpr auto f_result(OutType(*f)(InTypes...))
		{
			return U_type_T<OutType>;
		}

		template<auto f>
		static constexpr auto result = f_result(f);
	};

	static constexpr auto U_out_type = U_type_T<S_out_type>;

	template<auto f>
	using out_type = T_type_U
	<
		S_out_type::f_result(f)
	>;

/***********************************************************************************************************************/

// in type:

	struct S_in_type
	{
		template<auto depth, auto pos, typename OutType, typename... InTypes>
		static constexpr auto f_result(OutType(*f)(InTypes...))
		{
			return pack_module::at<depth, pos, U_type_T<InTypes>...>;
		}

		template<auto depth, auto pos, auto f>
		static constexpr auto result = f_result<depth, pos>(f);
	};

	static constexpr auto U_in_type = U_type_T<S_in_type>;

	template<auto f, depth_type pos = 0, depth_type depth = 500>
	using in_type = T_type_U
	<
		S_in_type::template f_result<depth, pos>(f)
	>;

/***********************************************************************************************************************/

// in types:

	struct S_in_types
	{
		template<typename OutType, typename... InTypes>
		static constexpr auto f_result(OutType(*f)(InTypes...))
		{
			return U_pack_Vs
			<
				U_type_T<InTypes>...
			>;
		}

		template<auto f>
		static constexpr auto result = f_result(f);
	};

	static constexpr auto U_in_types = U_type_T<S_in_types>;

	template<auto f>
	using in_types = T_type_U
	<
		S_in_types::f_result(f)
	>;

/***********************************************************************************************************************/

// in types left:

	struct S_in_types_left
	{
		template<auto depth, auto pos, typename OutType, typename... InTypes>
		static constexpr auto f_result(OutType(*f)(InTypes...))
		{
			return pack_module::left<depth, pos, U_type_T<InTypes>...>;
		}

		template<auto depth, auto pos, auto f>
		static constexpr auto result = f_result<depth, pos>(f);
	};

	static constexpr auto U_in_types_left = U_type_T<S_in_types_left>;

	template<auto f, depth_type pos, depth_type depth = 500>
	using in_types_left = T_type_U
	<
		S_in_types_left::template f_result<depth, pos>(f)
	>;

/***********************************************************************************************************************/

// in types right:

	struct S_in_types_right
	{
		template<auto depth, auto pos, typename OutType, typename... InTypes>
		static constexpr auto f_result(OutType(*f)(InTypes...))
		{
			return pack_module::right<depth, pos, U_type_T<InTypes>...>;
		}

		template<auto depth, auto pos, auto f>
		static constexpr auto result = f_result<depth, pos>(f);
	};

	static constexpr auto U_in_types_right = U_type_T<S_in_types_right>;

	template<auto f, depth_type pos, depth_type depth = 500>
	using in_types_right = T_type_U
	<
		S_in_types_right::template f_result<depth, pos>(f)
	>;

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

