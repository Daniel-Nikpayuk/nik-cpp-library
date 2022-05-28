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
		nik_ces auto result(T v)			{ return v; }
	};

	nik_ces auto J_id = store_module::template U_store_T<F_id>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// constants:

/***********************************************************************************************************************/

	template<auto V>
	struct F_constant_V
	{
		nik_ces auto result()				{ return V; }
	};

	template<auto V>
	nik_ces auto J_constant_V = store_module::template U_store_T<F_constant_V<V>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// arithmetic operators:

/***********************************************************************************************************************/

	struct F_add
	{
		template<typename T1, typename T2>
		nik_ces auto result(T1 v1, T2 v2)		{ return v1 + v2; }
	};

	nik_ces auto J_add = store_module::template U_store_T<F_add>;

/***********************************************************************************************************************/

	struct F_subtract
	{
		template<typename T1, typename T2>
		nik_ces auto result(T1 v1, T2 v2)		{ return v1 - v2; }
	};

	nik_ces auto J_subtract = store_module::template U_store_T<F_subtract>;

/***********************************************************************************************************************/

	struct F_multiply
	{
		template<typename T1, typename T2>
		nik_ces auto result(T1 v1, T2 v2)		{ return v1 * v2; }
	};

	nik_ces auto J_multiply = store_module::template U_store_T<F_multiply>;

/***********************************************************************************************************************/

	struct F_divide
	{
		template<typename T1, typename T2>
		nik_ces auto result(T1 v1, T2 v2)		{ return v1 / v2; }
	};

	nik_ces auto J_divide = store_module::template U_store_T<F_divide>;

/***********************************************************************************************************************/

	struct F_modulo
	{
		template<typename T1, typename T2>
		nik_ces auto result(T1 v1, T2 v2)		{ return v1 % v2; }
	};

	nik_ces auto J_modulo = store_module::template U_store_T<F_modulo>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_add_by_V
	{
		template<typename T>
		nik_ces auto result(T v)			{ return v + V; }
	};

	template<auto V>
	nik_ces auto J_add_by_V = store_module::template U_store_T<F_add_by_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_subtract_by_V
	{
		template<typename T>
		nik_ces auto result(T v)			{ return v - V; }
	};

	template<auto V>
	nik_ces auto J_subtract_by_V = store_module::template U_store_T<F_subtract_by_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_multiply_by_V
	{
		template<typename T>
		nik_ces auto result(T v)			{ return v * V; }
	};

	template<auto V>
	nik_ces auto J_multiply_by_V = store_module::template U_store_T<F_multiply_by_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_divide_by_V
	{
		template<typename T>
		nik_ces auto result(T v)			{ return v / V; }
	};

	template<auto V>
	nik_ces auto J_divide_by_V = store_module::template U_store_T<F_divide_by_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_modulo_by_V
	{
		template<typename T>
		nik_ces auto result(T v)			{ return v % V; }
	};

	template<auto V>
	nik_ces auto J_modulo_by_V = store_module::template U_store_T<F_modulo_by_V<V>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// comparative operators:

/***********************************************************************************************************************/

	struct F_max
	{
		template<typename T1, typename T2>
		nik_ces auto result(T1 v1, T2 v2)		{ return (v1 > v2) ? v1 : v2; }
	};

	nik_ces auto J_max = store_module::template U_store_T<F_max>;

/***********************************************************************************************************************/

	struct F_min
	{
		template<typename T1, typename T2>
		nik_ces auto result(T1 v1, T2 v2)		{ return (v1 < v2) ? v1 : v2; }
	};

	nik_ces auto J_min = store_module::template U_store_T<F_min>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

	struct F_equal
	{
		template<typename T1, typename T2>
		nik_ces bool result(T1 v1, T2 v2)		{ return (v1 == v2); }
	};

	nik_ces auto J_equal = store_module::template U_store_T<F_equal>;

/***********************************************************************************************************************/

	struct F_not_equal
	{
		template<typename T1, typename T2>
		nik_ces bool result(T1 v1, T2 v2)		{ return (v1 != v2); }
	};

	nik_ces auto J_not_equal = store_module::template U_store_T<F_not_equal>;

/***********************************************************************************************************************/

	struct F_less_than
	{
		template<typename T1, typename T2>
		nik_ces bool result(T1 v1, T2 v2)		{ return (v1 < v2); }
	};

	nik_ces auto J_less_than = store_module::template U_store_T<F_less_than>;

/***********************************************************************************************************************/

	struct F_less_than_or_equal
	{
		template<typename T1, typename T2>
		nik_ces bool result(T1 v1, T2 v2)		{ return (v1 <= v2); }
	};

	nik_ces auto J_less_than_or_equal = store_module::template U_store_T<F_less_than_or_equal>;

/***********************************************************************************************************************/

	struct F_greater_than
	{
		template<typename T1, typename T2>
		nik_ces bool result(T1 v1, T2 v2)		{ return (v1 > v2); }
	};

	nik_ces auto J_greater_than = store_module::template U_store_T<F_greater_than>;

/***********************************************************************************************************************/

	struct F_greater_than_or_equal
	{
		template<typename T1, typename T2>
		nik_ces bool result(T1 v1, T2 v2)		{ return (v1 >= v2); }
	};

	nik_ces auto J_greater_than_or_equal = store_module::template U_store_T<F_greater_than_or_equal>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_is_value_V
	{
		template<typename T>
		nik_ces bool result(T v)			{ return (v == V); }
	};

	template<auto V>
	nik_ces auto J_is_value_V = store_module::template U_store_T<F_is_value_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_not_value_V
	{
		template<typename T>
		nik_ces bool result(T v)			{ return (v != V); }
	};

	template<auto V>
	nik_ces auto J_not_value_V = store_module::template U_store_T<F_not_value_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_is_less_than_V
	{
		template<typename T>
		nik_ces bool result(T v)			{ return (v < V); }
	};

	template<auto V>
	nik_ces auto J_is_less_than_V = store_module::template U_store_T<F_is_less_than_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_is_less_than_or_equal_V
	{
		template<typename T>
		nik_ces bool result(T v)			{ return (v <= V); }
	};

	template<auto V>
	nik_ces auto J_is_less_than_or_equal_V = store_module::template U_store_T<F_is_less_than_or_equal_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_is_greater_than_V
	{
		template<typename T>
		nik_ces bool result(T v)			{ return (v > V); }
	};

	template<auto V>
	nik_ces auto J_is_greater_than_V = store_module::template U_store_T<F_is_greater_than_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct F_is_greater_than_or_equal_V
	{
		template<typename T>
		nik_ces bool result(T v)			{ return (v >= V); }
	};

	template<auto V>
	nik_ces auto J_is_greater_than_or_equal_V = store_module::template U_store_T<F_is_greater_than_or_equal_V<V>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// boolean operators:

/***********************************************************************************************************************/

	struct F_conjunction
	{
		nik_ces bool result(bool b1, bool b2)		{ return b1 && b2; }
	};

	nik_ces auto J_conjunction = store_module::template U_store_T<F_conjunction>;

/***********************************************************************************************************************/

	struct F_disjunction
	{
		nik_ces bool result(bool b1, bool b2)		{ return b1 || b2; }
	};

	nik_ces auto J_disjunction = store_module::template U_store_T<F_disjunction>;

/***********************************************************************************************************************/

	struct F_implication
	{
		nik_ces bool result(bool b1, bool b2)		{ return b1 || !b2; }
	};

	nik_ces auto J_implication = store_module::template U_store_T<F_implication>;

/***********************************************************************************************************************/

	struct F_equivalence
	{
		nik_ces bool result(bool b1, bool b2)		{ return (b1 || !b2) && (!b1 || b2); }
	};

	nik_ces auto J_equivalence = store_module::template U_store_T<F_equivalence>;

/***********************************************************************************************************************/

	struct F_negation
	{
		nik_ces bool result(bool b)			{ return !b; }
	};

	nik_ces auto J_negation = store_module::template U_store_T<F_negation>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dereference operator:

/***********************************************************************************************************************/

	struct F_dereference
	{
		template<typename T>
		nik_ces auto & result(T & v)			{ return *v; }
	};

	nik_ces auto J_dereference = store_module::template U_store_T<F_dereference>;

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
		nik_ces auto result(Ts... vs)
		{
			using F = store_module::template T_store_U<J>;

			return F::template result<Ts...>(vs...);
		}
	};

	template<auto J>
	nik_ces auto J_apply_J = store_module::template U_store_T<F_apply_J<J>>;

	template<auto J, typename... Ts>
	nik_ces auto apply(Ts... vs)
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
		nik_ces bool result = store_module::template V_equal_VxV<J, J_id>;
	};

	nik_ces auto I_is_id_keyword = store_module::template U_store_T<E_is_id_keyword>;

	template<auto J>
	nik_ces bool is_id_keyword = E_is_id_keyword::template result<J>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// postcompose:

/***********************************************************************************************************************/

private:

	template<typename F1, typename F2>
	struct F_postcomposition_TxT
	{
		template<typename... Ts>
		nik_ces auto result(Ts... vs)
		{
			using mid_type = decltype(F2::template result<Ts...>(vs...));

			return F1::template result<mid_type>(F2::template result<Ts...>(vs...));
		}
	};

public:

	struct E_postcompose
	{
		template<auto J1, auto J2>
		nik_ces auto result = store_module::template U_store_T
		<
			F_postcomposition_TxT
			<
				store_module::template T_store_U<J1>,
				store_module::template T_store_U<J2>
			>
		>;
	};

	nik_ces auto I_postcompose = store_module::template U_store_T<E_postcompose>;

	template<auto J1, auto J2>
	nik_ces auto postcompose = E_postcompose::template result<J1, J2>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// precompose:

/***********************************************************************************************************************/

	struct E_precompose
	{
		template<auto J1, auto J2>
		nik_ces auto result = E_postcompose::template result<J2, J1>;
	};

	nik_ces auto I_precompose = store_module::template U_store_T<E_precompose>;

	template<auto J1, auto J2>
	nik_ces auto precompose = E_precompose::template result<J1, J2>;

/***********************************************************************************************************************/

// chain precompose:

	template<auto J0, auto... Js>
	nik_ces auto chain_precompose = pack_module::template roll<500, I_precompose, J0, Js...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// optimized composition:

/***********************************************************************************************************************/

// opt postcompose:

	struct E_opt_postcompose
	{
		template<auto J1, auto J2>
		nik_ces auto f_result()
		{
			if constexpr      (is_id_keyword<J1, J_id>)	return J2;
			else if constexpr (is_id_keyword<J2, J_id>)	return J1;
			else						return postcompose<J1, J2>;
		};

		template<auto J1, auto J2>
		nik_ces auto result = f_result<J1, J2>();
	};

	nik_ces auto I_opt_postcompose = store_module::template U_store_T<E_opt_postcompose>;

	template<auto J1, auto J2>
	nik_ces auto opt_postcompose = E_opt_postcompose::template f_result<J1, J2>();

/***********************************************************************************************************************/

// opt precompose:

	struct E_opt_precompose
	{
		template<auto J1, auto J2>
		nik_ces auto result = E_opt_postcompose::template f_result<J2, J1>();
	};

	nik_ces auto I_opt_precompose = store_module::template U_store_T<E_opt_precompose>;

	template<auto J1, auto J2>	// E_opt_postcompose, not E_opt_precompose
	nik_ces auto opt_precompose = E_opt_postcompose::template f_result<J2, J1>();

/***********************************************************************************************************************/

// opt chain precompose:

	template<auto J0, auto... Js>
	nik_ces auto opt_chain_precompose = pack_module::template roll<500, I_opt_precompose, J0, Js...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

