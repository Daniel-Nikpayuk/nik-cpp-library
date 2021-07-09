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

	template<typename T>
	static constexpr auto id = S_id::template result<T>;

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

	template<auto V>
	static constexpr auto constant = S_constant<V>::result;

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

	template<typename T, typename U>
	static constexpr auto add = S_add::template result<T, U>;

/***********************************************************************************************************************/

	struct S_subtract
	{
		template<typename T, typename U>
		static constexpr T result(T v1, U v2)			{ return v1 - v2; }
	};

	static constexpr auto U_subtract = functor_module::template U_type_T<S_subtract>;

	template<typename T, typename U>
	static constexpr auto subtract = S_subtract::template result<T, U>;

/***********************************************************************************************************************/

	struct S_multiply
	{
		template<typename T, typename U>
		static constexpr T result(T v1, U v2)			{ return v1 * v2; }
	};

	static constexpr auto U_multiply = functor_module::template U_type_T<S_multiply>;

	template<typename T, typename U>
	static constexpr auto multiply = S_multiply::template result<T, U>;

/***********************************************************************************************************************/

	struct S_divide
	{
		template<typename T, typename U>
		static constexpr T result(T v1, U v2)			{ return v1 / v2; }
	};

	static constexpr auto U_divide = functor_module::template U_type_T<S_divide>;

	template<typename T, typename U>
	static constexpr auto divide = S_divide::template result<T, U>;

/***********************************************************************************************************************/

	struct S_modulo
	{
		template<typename T, typename U>
		static constexpr T result(T v1, U v2)			{ return v1 % v2; }
	};

	static constexpr auto U_modulo = functor_module::template U_type_T<S_modulo>;

	template<typename T, typename U>
	static constexpr auto modulo = S_modulo::template result<T, U>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_add_by
	{
		template<typename T>
		static constexpr T result(T v)				{ return v + V; }
	};

	template<auto V>
	static constexpr auto U_add_by = functor_module::template U_type_T<S_add_by<V>>;

	template<typename T, auto V>
	static constexpr auto add_by = S_add_by<V>::template result<T>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_subtract_by
	{
		template<typename T>
		static constexpr T result(T v)				{ return v - V; }
	};

	template<auto V>
	static constexpr auto U_subtract_by = functor_module::template U_type_T<S_subtract_by<V>>;

	template<typename T, auto V>
	static constexpr auto subtract_by = S_subtract_by<V>::template result<T>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_multiply_by
	{
		template<typename T>
		static constexpr T result(T v)				{ return v * V; }
	};

	template<auto V>
	static constexpr auto U_multiply_by = functor_module::template U_type_T<S_multiply_by<V>>;

	template<typename T, auto V>
	static constexpr auto multiply_by = S_multiply_by<V>::template result<T>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_divide_by
	{
		template<typename T>
		static constexpr T result(T v)				{ return v / V; }
	};

	template<auto V>
	static constexpr auto U_divide_by = functor_module::template U_type_T<S_divide_by<V>>;

	template<typename T, auto V>
	static constexpr auto divide_by = S_divide_by<V>::template result<T>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_modulo_by
	{
		template<typename T>
		static constexpr T result(T v)				{ return v % V; }
	};

	template<auto V>
	static constexpr auto U_modulo_by = functor_module::template U_type_T<S_modulo_by<V>>;

	template<typename T, auto V>
	static constexpr auto modulo_by = S_modulo_by<V>::template result<T>;

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

	template<typename T, typename U>
	static constexpr auto max = S_max::template result<T, U>;

/***********************************************************************************************************************/

	struct S_min
	{
		template<typename T, typename U>
		static constexpr T result(T v1, U v2)			{ return v1 < v2 ? v1 : v2; }
	};

	static constexpr auto U_min = functor_module::template U_type_T<S_min>;

	template<typename T, typename U>
	static constexpr auto min = S_min::template result<T, U>;

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

	template<typename T, typename U>
	static constexpr auto equal = S_equal::template result<T, U>;

/***********************************************************************************************************************/

	struct S_not_equal
	{
		template<typename T, typename U>
		static constexpr bool result(T v1, U v2)		{ return (v1 != v2); }
	};

	static constexpr auto U_not_equal = functor_module::template U_type_T<S_not_equal>;

	template<typename T, typename U>
	static constexpr auto not_equal = S_not_equal::template result<T, U>;

/***********************************************************************************************************************/

	struct S_less_than
	{
		template<typename T, typename U>
		static constexpr bool result(T v1, U v2)		{ return (v1 < v2); }
	};

	static constexpr auto U_less_than = functor_module::template U_type_T<S_less_than>;

	template<typename T, typename U>
	static constexpr auto less_than = S_less_than::template result<T, U>;

/***********************************************************************************************************************/

	struct S_less_than_or_equal
	{
		template<typename T, typename U>
		static constexpr bool result(T v1, U v2)		{ return (v1 <= v2); }
	};

	static constexpr auto U_less_than_or_equal = functor_module::template U_type_T<S_less_than_or_equal>;

	template<typename T, typename U>
	static constexpr auto less_than_or_equal = S_less_than_or_equal::template result<T, U>;

/***********************************************************************************************************************/

	struct S_greater_than
	{
		template<typename T, typename U>
		static constexpr bool result(T v1, U v2)		{ return (v1 > v2); }
	};

	static constexpr auto U_greater_than = functor_module::template U_type_T<S_greater_than>;

	template<typename T, typename U>
	static constexpr auto greater_than = S_greater_than::template result<T, U>;

/***********************************************************************************************************************/

	struct S_greater_than_or_equal
	{
		template<typename T, typename U>
		static constexpr bool result(T v1, U v2)		{ return (v1 >= v2); }
	};

	static constexpr auto U_greater_than_or_equal = functor_module::template U_type_T<S_greater_than_or_equal>;

	template<typename T, typename U>
	static constexpr auto greater_than_or_equal = S_greater_than_or_equal::template result<T, U>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_is_value
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v == V); }
	};

	template<auto V>
	static constexpr auto U_is_value = functor_module::template U_type_T<S_is_value<V>>;

	template<typename T, auto V>
	static constexpr auto is_value = S_is_value<V>::template result<T>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_not_value
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v != V); }
	};

	template<auto V>
	static constexpr auto U_not_value = functor_module::template U_type_T<S_not_value<V>>;

	template<typename T, auto V>
	static constexpr auto not_value = S_not_value<V>::template result<T>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_is_less_than
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v < V); }
	};

	template<auto V>
	static constexpr auto U_is_less_than = functor_module::template U_type_T<S_is_less_than<V>>;

	template<typename T, auto V>
	static constexpr auto is_less_than = S_is_less_than<V>::template result<T>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_is_less_than_or_equal
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v <= V); }
	};

	template<auto V>
	static constexpr auto U_is_less_than_or_equal = functor_module::template U_type_T<S_is_less_than_or_equal<V>>;

	template<typename T, auto V>
	static constexpr auto is_less_than_or_equal = S_is_less_than_or_equal<V>::template result<T>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_is_greater_than
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v > V); }
	};

	template<auto V>
	static constexpr auto U_is_greater_than = functor_module::template U_type_T<S_is_greater_than<V>>;

	template<typename T, auto V>
	static constexpr auto is_greater_than = S_is_greater_than<V>::template result<T>;

/***********************************************************************************************************************/

	template<auto V>
	struct S_is_greater_than_or_equal
	{
		template<typename T>
		static constexpr bool result(T v)			{ return (v >= V); }
	};

	template<auto V>
	static constexpr auto U_is_greater_than_or_equal = functor_module::template U_type_T<S_is_greater_than_or_equal<V>>;

	template<typename T, auto V>
	static constexpr auto is_greater_than_or_equal = S_is_greater_than_or_equal<V>::template result<T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// boolean operators:

/***********************************************************************************************************************/

	struct S_conjunction
	{
		static constexpr bool result(bool b1, bool b2)		{ return b1 && b2; }
	};

	static constexpr auto U_conjunction = functor_module::template U_type_T<S_conjunction>;
	
	static constexpr auto conjunction = S_conjunction::result;

/***********************************************************************************************************************/

	struct S_disjunction
	{
		static constexpr bool result(bool b1, bool b2)		{ return b1 || b2; }
	};

	static constexpr auto U_disjunction = functor_module::template U_type_T<S_disjunction>;
	
	static constexpr auto disjunction = S_disjunction::result;

/***********************************************************************************************************************/

	struct S_implication
	{
		static constexpr bool result(bool b1, bool b2)		{ return b1 || !b2; }
	};

	static constexpr auto U_implication = functor_module::template U_type_T<S_implication>;
	
	static constexpr auto implication = S_implication::result;

/***********************************************************************************************************************/

	struct S_equivalence
	{
		static constexpr bool result(bool b1, bool b2)		{ return (b1 || !b2) && (!b1 || b2); }
	};

	static constexpr auto U_equivalence = functor_module::template U_type_T<S_equivalence>;
	
	static constexpr auto equivalence = S_equivalence::result;

/***********************************************************************************************************************/

	struct S_negation
	{
		static constexpr bool result(bool b)			{ return !b; }
	};

	static constexpr auto U_negation = functor_module::template U_type_T<S_negation>;
	
	static constexpr auto negation = S_negation::result;

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

	template<typename T>
	static constexpr auto dereference = S_dereference::template result<T>;

/***********************************************************************************************************************/

	struct S_cdereference
	{
		template<typename T>
		static constexpr const auto & result(const T & v)	{ return *v; }
	};

	static constexpr auto U_cdereference = functor_module::template U_type_T<S_cdereference>;

	template<typename T>
	static constexpr auto cdereference = S_cdereference::template result<T>;

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

// compose:

/***********************************************************************************************************************/

private:

	template<typename SF1, typename SF2>
	struct S_compose
	{
		template<typename T>
		static constexpr auto result(T v)
		{
			return SF1::template result
			<
				decltype(SF2::template result<T>(v))
			>
			(
				SF2::template result<T>(v)
			);
		}
	};

public:

	template<auto uf1, auto uf2>
	static constexpr auto compose = functor_module::template U_type_T
	<
		S_compose
		<
			functor_module::template T_type_U<uf1>,
			functor_module::template T_type_U<uf2>
		>
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

