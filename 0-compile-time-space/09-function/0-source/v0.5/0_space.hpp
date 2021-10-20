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

// space source:

	// Function templates assume the ability to deduce the output type (auto).
	// The alternative explicit description of both input and output types,
	// which would lead to chains of type descriptions when composing such
	// templates.

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomics:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identity:

/***********************************************************************************************************************/

	struct F_id
	{
		template<typename T>
		static constexpr auto result(T v)			{ return v; }
	};

	static constexpr auto J_id = cache_module::template U_type_T<F_id>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// constants:

/***********************************************************************************************************************/

	template<auto V>
	struct F_constant_V
	{
		static constexpr auto result()				{ return V; }
	};

	template<auto V>
	static constexpr auto J_constant_V = cache_module::template U_type_T<F_constant_V<V>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// arithmetic operators:

/***********************************************************************************************************************/

	struct F_add
	{
		template<typename T1, typename T2>
		static constexpr auto result(T1 v1, T2 v2)		{ return v1 + v2; }
	};

	static constexpr auto J_add = cache_module::template U_type_T<F_add>;

/***********************************************************************************************************************/

	struct F_subtract
	{
		template<typename T1, typename T2>
		static constexpr auto result(T1 v1, T2 v2)		{ return v1 - v2; }
	};

	static constexpr auto J_subtract = cache_module::template U_type_T<F_subtract>;

/***********************************************************************************************************************/

	struct F_multiply
	{
		template<typename T1, typename T2>
		static constexpr auto result(T1 v1, T2 v2)		{ return v1 * v2; }
	};

	static constexpr auto J_multiply = cache_module::template U_type_T<F_multiply>;

/***********************************************************************************************************************/

	struct F_divide
	{
		template<typename T1, typename T2>
		static constexpr auto result(T1 v1, T2 v2)		{ return v1 / v2; }
	};

	static constexpr auto J_divide = cache_module::template U_type_T<F_divide>;

/***********************************************************************************************************************/

	struct F_modulo
	{
		template<typename T1, typename T2>
		static constexpr auto result(T1 v1, T2 v2)		{ return v1 % v2; }
	};

	static constexpr auto J_modulo = cache_module::template U_type_T<F_modulo>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_add_by_V
	{
		template<typename T>
		static constexpr auto result(T v)			{ return v + V; }
	};

	template<auto V>
	static constexpr auto J_add_by_V = cache_module::template U_type_T<F_add_by_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_subtract_by_V
	{
		template<typename T>
		static constexpr auto result(T v)			{ return v - V; }
	};

	template<auto V>
	static constexpr auto J_subtract_by_V = cache_module::template U_type_T<F_subtract_by_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_multiply_by_V
	{
		template<typename T>
		static constexpr auto result(T v)			{ return v * V; }
	};

	template<auto V>
	static constexpr auto J_multiply_by_V = cache_module::template U_type_T<F_multiply_by_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_divide_by_V
	{
		template<typename T>
		static constexpr auto result(T v)			{ return v / V; }
	};

	template<auto V>
	static constexpr auto J_divide_by_V = cache_module::template U_type_T<F_divide_by_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_modulo_by_V
	{
		template<typename T>
		static constexpr auto result(T v)			{ return v % V; }
	};

	template<auto V>
	static constexpr auto J_modulo_by_V = cache_module::template U_type_T<F_modulo_by_V<V>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// comparative operators:

/***********************************************************************************************************************/

	struct F_max
	{
		template<typename T1, typename T2>
		static constexpr auto result(T1 v1, T2 v2)		{ return (v1 > v2) ? v1 : v2; }
	};

	static constexpr auto J_max = cache_module::template U_type_T<F_max>;

/***********************************************************************************************************************/

	struct F_min
	{
		template<typename T1, typename T2>
		static constexpr auto result(T1 v1, T2 v2)		{ return (v1 < v2) ? v1 : v2; }
	};

	static constexpr auto J_min = cache_module::template U_type_T<F_min>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

	struct F_equal
	{
		template<typename T1, typename T2>
		static constexpr bool result(T1 v1, T2 v2)		{ return (v1 == v2); }
	};

	static constexpr auto J_equal = cache_module::template U_type_T<F_equal>;

/***********************************************************************************************************************/

	struct F_not_equal
	{
		template<typename T1, typename T2>
		static constexpr bool result(T1 v1, T2 v2)		{ return (v1 != v2); }
	};

	static constexpr auto J_not_equal = cache_module::template U_type_T<F_not_equal>;

/***********************************************************************************************************************/

	struct F_less_than
	{
		template<typename T1, typename T2>
		static constexpr bool result(T1 v1, T2 v2)		{ return (v1 < v2); }
	};

	static constexpr auto J_less_than = cache_module::template U_type_T<F_less_than>;

/***********************************************************************************************************************/

	struct F_less_than_or_equal
	{
		template<typename T1, typename T2>
		static constexpr bool result(T1 v1, T2 v2)		{ return (v1 <= v2); }
	};

	static constexpr auto J_less_than_or_equal = cache_module::template U_type_T<F_less_than_or_equal>;

/***********************************************************************************************************************/

	struct F_greater_than
	{
		template<typename T1, typename T2>
		static constexpr bool result(T1 v1, T2 v2)		{ return (v1 > v2); }
	};

	static constexpr auto J_greater_than = cache_module::template U_type_T<F_greater_than>;

/***********************************************************************************************************************/

	struct F_greater_than_or_equal
	{
		template<typename T1, typename T2>
		static constexpr bool result(T1 v1, T2 v2)		{ return (v1 >= v2); }
	};

	static constexpr auto J_greater_than_or_equal = cache_module::template U_type_T<F_greater_than_or_equal>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_is_value_V
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v == V); }
	};

	template<auto V>
	static constexpr auto J_is_value_V = cache_module::template U_type_T<F_is_value_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_not_value_V
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v != V); }
	};

	template<auto V>
	static constexpr auto J_not_value_V = cache_module::template U_type_T<F_not_value_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_is_less_than_V
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v < V); }
	};

	template<auto V>
	static constexpr auto J_is_less_than_V = cache_module::template U_type_T<F_is_less_than_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_is_less_than_or_equal_V
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v <= V); }
	};

	template<auto V>
	static constexpr auto J_is_less_than_or_equal_V = cache_module::template U_type_T<F_is_less_than_or_equal_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_is_greater_than_V
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v > V); }
	};

	template<auto V>
	static constexpr auto J_is_greater_than_V = cache_module::template U_type_T<F_is_greater_than_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_is_greater_than_or_equal_V
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v >= V); }
	};

	template<auto V>
	static constexpr auto J_is_greater_than_or_equal_V = cache_module::template U_type_T<F_is_greater_than_or_equal_V<V>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// boolean operators:

/***********************************************************************************************************************/

	struct F_conjunction
	{
		static constexpr bool result(bool b1, bool b2)		{ return b1 && b2; }
	};

	static constexpr auto J_conjunction = cache_module::template U_type_T<F_conjunction>;

/***********************************************************************************************************************/

	struct F_disjunction
	{
		static constexpr bool result(bool b1, bool b2)		{ return b1 || b2; }
	};

	static constexpr auto J_disjunction = cache_module::template U_type_T<F_disjunction>;

/***********************************************************************************************************************/

	struct F_implication
	{
		static constexpr bool result(bool b1, bool b2)		{ return b1 || !b2; }
	};

	static constexpr auto J_implication = cache_module::template U_type_T<F_implication>;

/***********************************************************************************************************************/

	struct F_equivalence
	{
		static constexpr bool result(bool b1, bool b2)		{ return (b1 || !b2) && (!b1 || b2); }
	};

	static constexpr auto J_equivalence = cache_module::template U_type_T<F_equivalence>;

/***********************************************************************************************************************/

	struct F_negation
	{
		static constexpr bool result(bool b)			{ return !b; }
	};

	static constexpr auto J_negation = cache_module::template U_type_T<F_negation>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dereference operator:

/***********************************************************************************************************************/

	struct F_dereference
	{
		template<typename T>
		static constexpr auto & result(T & v)			{ return *v; }
	};

	static constexpr auto J_dereference = cache_module::template U_type_T<F_dereference>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// evaluation operator:

	// It could be argued that a function template apply operator is redundant and unnecessary
	// given that it could be factored as the function template resolve (specialization) operator
	// followed by the procedural apply operator, but because function template apply allows for
	// argument type deduction it is in fact semantically distinct and worth defining here.

/***********************************************************************************************************************/

// apply:

	template<auto J>
	struct F_apply_J
	{
		template<typename... Ts>
		static constexpr auto result(Ts... vs)
		{
			using F = cache_module::template T_type_U<J>;

			return F::template result<Ts...>(vs...);
		}
	};

	template<auto J>
	static constexpr auto J_apply_J = cache_module::template U_type_T<F_apply_J<J>>;

	template<auto J, typename... Ts>
	static constexpr auto apply(Ts... vs)
	{
		return F_apply_J<J>::template result<Ts...>(vs...);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

/***********************************************************************************************************************/

	struct E_is_id_keyword
	{
		template<auto J>
		static constexpr bool result = cache_module::template V_equal_VxV<J, J_id>;
	};

	static constexpr auto I_is_id_keyword = cache_module::template U_type_T<E_is_id_keyword>;

	template<auto J>
	static constexpr bool is_id_keyword = E_is_id_keyword::template result<J>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// postcompose:

/***********************************************************************************************************************/

private:

	template<typename F1, typename F2>
	struct F_postcomposition_TxT
	{
		template<typename... Ts>
		static constexpr auto result(Ts... vs)
		{
			using mid_type = decltype(F2::template result<Ts...>(vs...));

			return F1::template result<mid_type>(F2::template result<Ts...>(vs...));
		}
	};

public:

	struct E_postcompose
	{
		template<auto J1, auto J2>
		static constexpr auto result = cache_module::template U_type_T
		<
			F_postcomposition_TxT
			<
				cache_module::template T_type_U<J1>,
				cache_module::template T_type_U<J2>
			>
		>;
	};

	static constexpr auto I_postcompose = cache_module::template U_type_T<E_postcompose>;

	template<auto J1, auto J2>
	static constexpr auto postcompose = E_postcompose::template result<J1, J2>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// precompose:

/***********************************************************************************************************************/

	struct E_precompose
	{
		template<auto J1, auto J2>
		static constexpr auto result = E_postcompose::template result<J2, J1>;
	};

	static constexpr auto I_precompose = cache_module::template U_type_T<E_precompose>;

	template<auto J1, auto J2>
	static constexpr auto precompose = E_precompose::template result<J1, J2>;

/***********************************************************************************************************************/

// chain precompose:

	template<auto J0, auto... Js>
	static constexpr auto chain_precompose = pack_module::template roll<500, I_precompose, J0, Js...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// optimized composition:

/***********************************************************************************************************************/

// opt postcompose:

	struct E_opt_postcompose
	{
		template<auto J1, auto J2>
		static constexpr auto f_result()
		{
			if constexpr      (is_id_keyword<J1, J_id>)	return J2;
			else if constexpr (is_id_keyword<J2, J_id>)	return J1;
			else						return postcompose<J1, J2>;
		};

		template<auto J1, auto J2>
		static constexpr auto result = f_result<J1, J2>();
	};

	static constexpr auto I_opt_postcompose = cache_module::template U_type_T<E_opt_postcompose>;

	template<auto J1, auto J2>
	static constexpr auto opt_postcompose = E_opt_postcompose::template f_result<J1, J2>();

/***********************************************************************************************************************/

// opt precompose:

	struct E_opt_precompose
	{
		template<auto J1, auto J2>
		static constexpr auto result = E_opt_postcompose::template f_result<J2, J1>();
	};

	static constexpr auto I_opt_precompose = cache_module::template U_type_T<E_opt_precompose>;

	template<auto J1, auto J2>	// E_opt_postcompose, not E_opt_precompose
	static constexpr auto opt_precompose = E_opt_postcompose::template f_result<J2, J1>();

/***********************************************************************************************************************/

// opt chain precompose:

	template<auto J0, auto... Js>
	static constexpr auto opt_chain_precompose = pack_module::template roll<500, I_opt_precompose, J0, Js...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

