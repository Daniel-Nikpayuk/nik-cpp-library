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

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomics:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identity:

/***********************************************************************************************************************/

	struct S_id
	{
		template<typename T>
		static constexpr T result(T v)				{ return v; }
	};

	static constexpr auto U_id = functor_module::template U_type_T<S_id>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// constants:

/***********************************************************************************************************************/

	template<auto V>
	struct S_constant
	{
		static constexpr auto result()				{ return V; }
	};

	template<auto V>
	static constexpr auto U_constant = functor_module::template U_type_T<S_constant<V>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// arithmetic operators:

/***********************************************************************************************************************/

	struct S_add
	{
		template<typename T, typename U>
		static constexpr T result(T v1, U v2)			{ return v1 + v2; }
	};

	static constexpr auto U_add = functor_module::template U_type_T<S_add>;

/***********************************************************************************************************************/

	struct S_subtract
	{
		template<typename T, typename U>
		static constexpr T result(T v1, U v2)			{ return v1 - v2; }
	};

	static constexpr auto U_subtract = functor_module::template U_type_T<S_subtract>;

/***********************************************************************************************************************/

	struct S_multiply
	{
		template<typename T, typename U>
		static constexpr T result(T v1, U v2)			{ return v1 * v2; }
	};

	static constexpr auto U_multiply = functor_module::template U_type_T<S_multiply>;

/***********************************************************************************************************************/

	struct S_divide
	{
		template<typename T, typename U>
		static constexpr T result(T v1, U v2)			{ return v1 / v2; }
	};

	static constexpr auto U_divide = functor_module::template U_type_T<S_divide>;

/***********************************************************************************************************************/

	struct S_modulo
	{
		template<typename T, typename U>
		static constexpr T result(T v1, U v2)			{ return v1 % v2; }
	};

	static constexpr auto U_modulo = functor_module::template U_type_T<S_modulo>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_add_by
	{
		template<typename T>
		static constexpr T result(T v)				{ return v + V; }
	};

	template<auto V>
	static constexpr auto U_add_by = functor_module::template U_type_T<S_add_by<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_subtract_by
	{
		template<typename T>
		static constexpr T result(T v)				{ return v - V; }
	};

	template<auto V>
	static constexpr auto U_subtract_by = functor_module::template U_type_T<S_subtract_by<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_multiply_by
	{
		template<typename T>
		static constexpr T result(T v)				{ return v * V; }
	};

	template<auto V>
	static constexpr auto U_multiply_by = functor_module::template U_type_T<S_multiply_by<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_divide_by
	{
		template<typename T>
		static constexpr T result(T v)				{ return v / V; }
	};

	template<auto V>
	static constexpr auto U_divide_by = functor_module::template U_type_T<S_divide_by<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_modulo_by
	{
		template<typename T>
		static constexpr T result(T v)				{ return v % V; }
	};

	template<auto V>
	static constexpr auto U_modulo_by = functor_module::template U_type_T<S_modulo_by<V>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// comparative operators:

/***********************************************************************************************************************/

	struct S_max
	{
		template<typename T, typename U>
		static constexpr T result(T v1, U v2)			{ return v1 > v2 ? v1 : v2; }
	};

	static constexpr auto U_max = functor_module::template U_type_T<S_max>;

/***********************************************************************************************************************/

	struct S_min
	{
		template<typename T, typename U>
		static constexpr T result(T v1, U v2)			{ return v1 < v2 ? v1 : v2; }
	};

	static constexpr auto U_min = functor_module::template U_type_T<S_min>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

	struct S_equal
	{
		template<typename T, typename U>
		static constexpr bool result(T v1, U v2)		{ return (v1 == v2); }
	};

	static constexpr auto U_equal = functor_module::template U_type_T<S_equal>;

/***********************************************************************************************************************/

	struct S_not_equal
	{
		template<typename T, typename U>
		static constexpr bool result(T v1, U v2)		{ return (v1 != v2); }
	};

	static constexpr auto U_not_equal = functor_module::template U_type_T<S_not_equal>;

/***********************************************************************************************************************/

	struct S_less_than
	{
		template<typename T, typename U>
		static constexpr bool result(T v1, U v2)		{ return (v1 < v2); }
	};

	static constexpr auto U_less_than = functor_module::template U_type_T<S_less_than>;

/***********************************************************************************************************************/

	struct S_less_than_or_equal
	{
		template<typename T, typename U>
		static constexpr bool result(T v1, U v2)		{ return (v1 <= v2); }
	};

	static constexpr auto U_less_than_or_equal = functor_module::template U_type_T<S_less_than_or_equal>;

/***********************************************************************************************************************/

	struct S_greater_than
	{
		template<typename T, typename U>
		static constexpr bool result(T v1, U v2)		{ return (v1 > v2); }
	};

	static constexpr auto U_greater_than = functor_module::template U_type_T<S_greater_than>;

/***********************************************************************************************************************/

	struct S_greater_than_or_equal
	{
		template<typename T, typename U>
		static constexpr bool result(T v1, U v2)		{ return (v1 >= v2); }
	};

	static constexpr auto U_greater_than_or_equal = functor_module::template U_type_T<S_greater_than_or_equal>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_is_value
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v == V); }
	};

	template<auto V>
	static constexpr auto U_is_value = functor_module::template U_type_T<S_is_value<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_not_value
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v != V); }
	};

	template<auto V>
	static constexpr auto U_not_value = functor_module::template U_type_T<S_not_value<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_is_less_than
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v < V); }
	};

	template<auto V>
	static constexpr auto U_is_less_than = functor_module::template U_type_T<S_is_less_than<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_is_less_than_or_equal
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v <= V); }
	};

	template<auto V>
	static constexpr auto U_is_less_than_or_equal = functor_module::template U_type_T<S_is_less_than_or_equal<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_is_greater_than
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v > V); }
	};

	template<auto V>
	static constexpr auto U_is_greater_than = functor_module::template U_type_T<S_is_greater_than<V>>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_is_greater_than_or_equal
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v >= V); }
	};

	template<auto V>
	static constexpr auto U_is_greater_than_or_equal = functor_module::template U_type_T<S_is_greater_than_or_equal<V>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// boolean operators:

/***********************************************************************************************************************/

	struct S_conjunction
	{
		static constexpr bool result(bool b1, bool b2)		{ return b1 && b2; }
	};

	static constexpr auto U_conjunction = functor_module::template U_type_T<S_conjunction>;

/***********************************************************************************************************************/

	struct S_disjunction
	{
		static constexpr bool result(bool b1, bool b2)		{ return b1 || b2; }
	};

	static constexpr auto U_disjunction = functor_module::template U_type_T<S_disjunction>;

/***********************************************************************************************************************/

	struct S_implication
	{
		static constexpr bool result(bool b1, bool b2)		{ return b1 || !b2; }
	};

	static constexpr auto U_implication = functor_module::template U_type_T<S_implication>;

/***********************************************************************************************************************/

	struct S_equivalence
	{
		static constexpr bool result(bool b1, bool b2)		{ return (b1 || !b2) && (!b1 || b2); }
	};

	static constexpr auto U_equivalence = functor_module::template U_type_T<S_equivalence>;

/***********************************************************************************************************************/

	struct S_negation
	{
		static constexpr bool result(bool b)			{ return !b; }
	};

	static constexpr auto U_negation = functor_module::template U_type_T<S_negation>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dereference operators:

/***********************************************************************************************************************/

	struct S_dereference
	{
		template<typename T>
		static constexpr auto & result(T & v)			{ return *v; }
	};

	static constexpr auto U_dereference = functor_module::template U_type_T<S_dereference>;

/***********************************************************************************************************************/

	struct S_cdereference
	{
		template<typename T>
		static constexpr const auto & result(const T & v)	{ return *v; }
	};

	static constexpr auto U_cdereference = functor_module::template U_type_T<S_cdereference>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// evaluation operators:

/***********************************************************************************************************************/

// apply:

	template<auto uf, typename T>
	static constexpr auto apply(T v)
	{
		using SF = functor_module::template T_type_U<uf>;

		return SF::template result<T>(v);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

/***********************************************************************************************************************/

	struct S_is_id_keyword
	{
		template<auto f>
		static constexpr bool result = functor_module::template V_equal_VxV<f, U_id>;
	};

	static constexpr auto U_is_id_keyword = functor_module::template U_type_T<S_is_id_keyword>;

	template<auto f>
	static constexpr bool is_id_keyword = S_is_id_keyword::template result<f>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// postcompose:

/***********************************************************************************************************************/

private:

	template<typename SF1, typename SF2>
	struct S_postcomposition
	{
		template<typename... Ts>
		static constexpr auto result(Ts... vs)
		{
			using mid_type = decltype(SF2::template result<Ts...>(vs...));

			return SF1::template result<mid_type>(SF2::template result<Ts...>(vs...));
		}
	};

public:

	struct S_postcompose
	{
		template<auto uf, auto ug>
		static constexpr auto result = functor_module::template U_type_T
		<
			S_postcomposition
			<
				functor_module::template T_type_U<uf>,
				functor_module::template T_type_U<ug>
			>
		>;
	};

	static constexpr auto U_postcompose = functor_module::template U_type_T<S_postcompose>;

	template<auto uf, auto ug>
	static constexpr auto postcompose = S_postcompose::template result<uf, ug>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// precompose:

/***********************************************************************************************************************/

	struct S_precompose
	{
		template<auto uf, auto ug>
		static constexpr auto result = S_postcompose::template result<ug, uf>;
	};

	static constexpr auto U_precompose = functor_module::template U_type_T<S_precompose>;

	template<auto uf, auto ug>
	static constexpr auto precompose = S_precompose::template result<uf, ug>;

/***********************************************************************************************************************/

// chain precompose:

	template<auto uf0, auto... ufs>
	static constexpr auto chain_precompose = pack_module::template roll<500, U_precompose, uf0, ufs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// optimized composition:

/***********************************************************************************************************************/

// opt postcompose:

	struct S_opt_postcompose
	{
		template<auto uf, auto ug>
		static constexpr auto f_result()
		{
			if constexpr      (is_id_keyword<uf, U_id>)	return ug;
			else if constexpr (is_id_keyword<ug, U_id>)	return uf;
			else						return postcompose<uf, ug>;
		};

		template<auto uf, auto ug>
		static constexpr auto result = f_result<uf, ug>();
	};

	static constexpr auto U_opt_postcompose = functor_module::template U_type_T<S_opt_postcompose>;

	template<auto uf, auto ug>
	static constexpr auto opt_postcompose = S_opt_postcompose::template f_result<uf, ug>();

/***********************************************************************************************************************/

// opt precompose:

	struct S_opt_precompose
	{
		template<auto uf, auto ug>
		static constexpr auto result = S_opt_postcompose::template f_result<ug, uf>();
	};

	static constexpr auto U_opt_precompose = functor_module::template U_type_T<S_opt_precompose>;

	template<auto uf, auto ug>	// S_opt_postcompose, not S_opt_precompose
	static constexpr auto opt_precompose = S_opt_postcompose::template f_result<ug, uf>();

/***********************************************************************************************************************/

// opt chain precompose:

	template<auto uf0, auto... ufs>
	static constexpr auto opt_chain_precompose = pack_module::template roll<500, U_opt_precompose, uf0, ufs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

