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

	struct E_id
	{
		template<typename T>
		static constexpr auto result(T v)			{ return v; }
	};

	static constexpr auto F_id = cache_module::template U_type_T<E_id>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// constants:

/***********************************************************************************************************************/

	template<auto V>
	struct E_constant_V
	{
		static constexpr auto result()				{ return V; }
	};

	template<auto V>
	static constexpr auto F_constant_V = cache_module::template U_type_T<E_constant_V<V>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// arithmetic operators:

/***********************************************************************************************************************/

	struct E_add
	{
		template<typename T1, typename T2>
		static constexpr auto result(T1 v1, T2 v2)		{ return v1 + v2; }
	};

	static constexpr auto F_add = cache_module::template U_type_T<E_add>;

/***********************************************************************************************************************/

	struct E_subtract
	{
		template<typename T1, typename T2>
		static constexpr auto result(T1 v1, T2 v2)		{ return v1 - v2; }
	};

	static constexpr auto F_subtract = cache_module::template U_type_T<E_subtract>;

/***********************************************************************************************************************/

	struct E_multiply
	{
		template<typename T1, typename T2>
		static constexpr auto result(T1 v1, T2 v2)		{ return v1 * v2; }
	};

	static constexpr auto F_multiply = cache_module::template U_type_T<E_multiply>;

/***********************************************************************************************************************/

	struct E_divide
	{
		template<typename T1, typename T2>
		static constexpr auto result(T1 v1, T2 v2)		{ return v1 / v2; }
	};

	static constexpr auto F_divide = cache_module::template U_type_T<E_divide>;

/***********************************************************************************************************************/

	struct E_modulo
	{
		template<typename T1, typename T2>
		static constexpr auto result(T1 v1, T2 v2)		{ return v1 % v2; }
	};

	static constexpr auto F_modulo = cache_module::template U_type_T<E_modulo>;

/***********************************************************************************************************************/

	template<auto V>
	struct E_add_by_V
	{
		template<typename T>
		static constexpr auto result(T v)			{ return v + V; }
	};

	template<auto V>
	static constexpr auto F_add_by_V = cache_module::template U_type_T<E_add_by_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct E_subtract_by_V
	{
		template<typename T>
		static constexpr auto result(T v)			{ return v - V; }
	};

	template<auto V>
	static constexpr auto F_subtract_by_V = cache_module::template U_type_T<E_subtract_by_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct E_multiply_by_V
	{
		template<typename T>
		static constexpr auto result(T v)			{ return v * V; }
	};

	template<auto V>
	static constexpr auto F_multiply_by_V = cache_module::template U_type_T<E_multiply_by_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct E_divide_by_V
	{
		template<typename T>
		static constexpr auto result(T v)			{ return v / V; }
	};

	template<auto V>
	static constexpr auto F_divide_by_V = cache_module::template U_type_T<E_divide_by_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct E_modulo_by_V
	{
		template<typename T>
		static constexpr auto result(T v)			{ return v % V; }
	};

	template<auto V>
	static constexpr auto F_modulo_by_V = cache_module::template U_type_T<E_modulo_by_V<V>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// comparative operators:

/***********************************************************************************************************************/

	struct E_max
	{
		template<typename T1, typename T2>
		static constexpr auto result(T1 v1, T2 v2)		{ return v1 > v2 ? v1 : v2; }
	};

	static constexpr auto F_max = cache_module::template U_type_T<E_max>;

/***********************************************************************************************************************/

	struct E_min
	{
		template<typename T1, typename T2>
		static constexpr auto result(T1 v1, T2 v2)		{ return v1 < v2 ? v1 : v2; }
	};

	static constexpr auto F_min = cache_module::template U_type_T<E_min>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

	struct E_equal
	{
		template<typename T1, typename T2>
		static constexpr bool result(T1 v1, T2 v2)		{ return (v1 == v2); }
	};

	static constexpr auto F_equal = cache_module::template U_type_T<E_equal>;

/***********************************************************************************************************************/

	struct E_not_equal
	{
		template<typename T1, typename T2>
		static constexpr bool result(T1 v1, T2 v2)		{ return (v1 != v2); }
	};

	static constexpr auto F_not_equal = cache_module::template U_type_T<E_not_equal>;

/***********************************************************************************************************************/

	struct E_less_than
	{
		template<typename T1, typename T2>
		static constexpr bool result(T1 v1, T2 v2)		{ return (v1 < v2); }
	};

	static constexpr auto F_less_than = cache_module::template U_type_T<E_less_than>;

/***********************************************************************************************************************/

	struct E_less_than_or_equal
	{
		template<typename T1, typename T2>
		static constexpr bool result(T1 v1, T2 v2)		{ return (v1 <= v2); }
	};

	static constexpr auto F_less_than_or_equal = cache_module::template U_type_T<E_less_than_or_equal>;

/***********************************************************************************************************************/

	struct E_greater_than
	{
		template<typename T1, typename T2>
		static constexpr bool result(T1 v1, T2 v2)		{ return (v1 > v2); }
	};

	static constexpr auto F_greater_than = cache_module::template U_type_T<E_greater_than>;

/***********************************************************************************************************************/

	struct E_greater_than_or_equal
	{
		template<typename T1, typename T2>
		static constexpr bool result(T1 v1, T2 v2)		{ return (v1 >= v2); }
	};

	static constexpr auto F_greater_than_or_equal = cache_module::template U_type_T<E_greater_than_or_equal>;

/***********************************************************************************************************************/

	template<auto V>
	struct E_is_value_V
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v == V); }
	};

	template<auto V>
	static constexpr auto F_is_value_V = cache_module::template U_type_T<E_is_value_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct E_not_value_V
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v != V); }
	};

	template<auto V>
	static constexpr auto F_not_value_V = cache_module::template U_type_T<E_not_value_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct E_is_less_than_V
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v < V); }
	};

	template<auto V>
	static constexpr auto F_is_less_than_V = cache_module::template U_type_T<E_is_less_than_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct E_is_less_than_or_equal_V
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v <= V); }
	};

	template<auto V>
	static constexpr auto F_is_less_than_or_equal_V = cache_module::template U_type_T<E_is_less_than_or_equal_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct E_is_greater_than_V
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v > V); }
	};

	template<auto V>
	static constexpr auto F_is_greater_than_V = cache_module::template U_type_T<E_is_greater_than_V<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct E_is_greater_than_or_equal_V
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v >= V); }
	};

	template<auto V>
	static constexpr auto F_is_greater_than_or_equal_V = cache_module::template U_type_T<E_is_greater_than_or_equal_V<V>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// boolean operators:

/***********************************************************************************************************************/

	struct E_conjunction
	{
		static constexpr bool result(bool b1, bool b2)		{ return b1 && b2; }
	};

	static constexpr auto F_conjunction = cache_module::template U_type_T<E_conjunction>;

/***********************************************************************************************************************/

	struct E_disjunction
	{
		static constexpr bool result(bool b1, bool b2)		{ return b1 || b2; }
	};

	static constexpr auto F_disjunction = cache_module::template U_type_T<E_disjunction>;

/***********************************************************************************************************************/

	struct E_implication
	{
		static constexpr bool result(bool b1, bool b2)		{ return b1 || !b2; }
	};

	static constexpr auto F_implication = cache_module::template U_type_T<E_implication>;

/***********************************************************************************************************************/

	struct E_equivalence
	{
		static constexpr bool result(bool b1, bool b2)		{ return (b1 || !b2) && (!b1 || b2); }
	};

	static constexpr auto F_equivalence = cache_module::template U_type_T<E_equivalence>;

/***********************************************************************************************************************/

	struct E_negation
	{
		static constexpr bool result(bool b)			{ return !b; }
	};

	static constexpr auto F_negation = cache_module::template U_type_T<E_negation>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dereference operators:

/***********************************************************************************************************************/

	struct E_dereference
	{
		template<typename T>
		static constexpr auto & result(T & v)			{ return *v; }
	};

	static constexpr auto F_dereference = cache_module::template U_type_T<E_dereference>;

/***********************************************************************************************************************/

	struct E_cdereference
	{
		template<typename T>
		static constexpr const auto & result(const T & v)	{ return *v; }
	};

	static constexpr auto F_cdereference = cache_module::template U_type_T<E_cdereference>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// evaluation operators:

/***********************************************************************************************************************/

// apply:

	struct E_apply
	{
		template<auto uf, typename... Ts>
		static constexpr auto result(Ts... vs)
		{
			using SF = cache_module::template T_type_U<uf>;

			return SF::template result<Ts...>(vs...);
		}
	};

	static constexpr auto F_apply = cache_module::template U_type_T<E_apply>;

	template<auto uf, typename... Ts>
	static constexpr auto apply(Ts... vs)
	{
		return E_apply::template result<uf, Ts...>(vs...);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

/***********************************************************************************************************************/

	struct G_is_id_keyword
	{
		template<auto f>
		static constexpr bool result = cache_module::template V_equal_VxV<f, F_id>;
	};

	static constexpr auto H_is_id_keyword = cache_module::template U_type_T<G_is_id_keyword>;

	template<auto f>
	static constexpr bool is_id_keyword = G_is_id_keyword::template result<f>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// postcompose:

/***********************************************************************************************************************/

private:

	template<typename SF1, typename SF2>
	struct E_postcomposition_TxT
	{
		template<typename... Ts>
		static constexpr auto result(Ts... vs)
		{
			using mid_type = decltype(SF2::template result<Ts...>(vs...));

			return SF1::template result<mid_type>(SF2::template result<Ts...>(vs...));
		}
	};

public:

	struct G_postcompose
	{
		template<auto uf, auto ug>
		static constexpr auto result = cache_module::template U_type_T
		<
			E_postcomposition_TxT
			<
				cache_module::template T_type_U<uf>,
				cache_module::template T_type_U<ug>
			>
		>;
	};

	static constexpr auto H_postcompose = cache_module::template U_type_T<G_postcompose>;

	template<auto uf, auto ug>
	static constexpr auto postcompose = G_postcompose::template result<uf, ug>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// precompose:

/***********************************************************************************************************************/

	struct G_precompose
	{
		template<auto uf, auto ug>
		static constexpr auto result = G_postcompose::template result<ug, uf>;
	};

	static constexpr auto H_precompose = cache_module::template U_type_T<G_precompose>;

	template<auto uf, auto ug>
	static constexpr auto precompose = G_precompose::template result<uf, ug>;

/***********************************************************************************************************************/

// chain precompose:

	template<auto uf0, auto... ufs>
	static constexpr auto chain_precompose = pack_module::template roll<500, H_precompose, uf0, ufs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// optimized composition:

/***********************************************************************************************************************/

// opt postcompose:

	struct G_opt_postcompose
	{
		template<auto uf, auto ug>
		static constexpr auto f_result()
		{
			if constexpr      (is_id_keyword<uf, F_id>)	return ug;
			else if constexpr (is_id_keyword<ug, F_id>)	return uf;
			else						return postcompose<uf, ug>;
		};

		template<auto uf, auto ug>
		static constexpr auto result = f_result<uf, ug>();
	};

	static constexpr auto H_opt_postcompose = cache_module::template U_type_T<G_opt_postcompose>;

	template<auto uf, auto ug>
	static constexpr auto opt_postcompose = G_opt_postcompose::template f_result<uf, ug>();

/***********************************************************************************************************************/

// opt precompose:

	struct G_opt_precompose
	{
		template<auto uf, auto ug>
		static constexpr auto result = G_opt_postcompose::template f_result<ug, uf>();
	};

	static constexpr auto H_opt_precompose = cache_module::template U_type_T<G_opt_precompose>;

	template<auto uf, auto ug>	// G_opt_postcompose, not G_opt_precompose
	static constexpr auto opt_precompose = G_opt_postcompose::template f_result<ug, uf>();

/***********************************************************************************************************************/

// opt chain precompose:

	template<auto uf0, auto... ufs>
	static constexpr auto opt_chain_precompose = pack_module::template roll<500, H_opt_precompose, uf0, ufs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

