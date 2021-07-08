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

// function alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomic functions:

/***********************************************************************************************************************/

// identity:

	using nik_name(NIK_PREFIX, S_id)				= typename NIK_MODULE::S_id;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_id)			= NIK_MODULE::U_id;

	template<typename T>
	NIK_POLICY auto nik_name(NIK_PREFIX, id)			= NIK_MODULE::template id<T>;

// constants:

	template<auto V>
	using nik_name(NIK_PREFIX, S_constant)				= typename NIK_MODULE::template S_constant<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_constant)		= NIK_MODULE::template U_constant<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, constant)			= NIK_MODULE::template constant<V>;

// arithmetic operators:

	using nik_name(NIK_PREFIX, S_add)				= typename NIK_MODULE::S_add;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_add)			= NIK_MODULE::U_add;

	template<typename T, typename U>
	NIK_POLICY auto nik_name(NIK_PREFIX, add)			= NIK_MODULE::template add<T, U>;

	using nik_name(NIK_PREFIX, S_subtract)				= typename NIK_MODULE::S_subtract;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_subtract)		= NIK_MODULE::U_subtract;

	template<typename T, typename U>
	NIK_POLICY auto nik_name(NIK_PREFIX, subtract)			= NIK_MODULE::template subtract<T, U>;

	using nik_name(NIK_PREFIX, S_multiply)				= typename NIK_MODULE::S_multiply;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_multiply)		= NIK_MODULE::U_multiply;

	template<typename T, typename U>
	NIK_POLICY auto nik_name(NIK_PREFIX, multiply)			= NIK_MODULE::template multiply<T, U>;

	using nik_name(NIK_PREFIX, S_divide)				= typename NIK_MODULE::S_divide;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_divide)			= NIK_MODULE::U_divide;

	template<typename T, typename U>
	NIK_POLICY auto nik_name(NIK_PREFIX, divide)			= NIK_MODULE::template divide<T, U>;

	using nik_name(NIK_PREFIX, S_modulo)				= typename NIK_MODULE::S_modulo;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_modulo)			= NIK_MODULE::U_modulo;

	template<typename T, typename U>
	NIK_POLICY auto nik_name(NIK_PREFIX, modulo)			= NIK_MODULE::template modulo<T, U>;

	//

	template<auto V>
	using nik_name(NIK_PREFIX, S_add_by)				= typename NIK_MODULE::template S_add_by<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_add_by)			= NIK_MODULE::template U_add_by<V>;

	template<typename T, auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, add_by)			= NIK_MODULE::template add_by<T, V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_subtract_by)			= typename NIK_MODULE::template S_subtract_by<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_subtract_by)		= NIK_MODULE::template U_subtract_by<V>;

	template<typename T, auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, subtract_by)		= NIK_MODULE::template subtract_by<T, V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_multiply_by)			= typename NIK_MODULE::template S_multiply_by<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_multiply_by)		= NIK_MODULE::template U_multiply_by<V>;

	template<typename T, auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, multiply_by)		= NIK_MODULE::template multiply_by<T, V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_divide_by)				= typename NIK_MODULE::template S_divide_by<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_divide_by)		= NIK_MODULE::template U_divide_by<V>;

	template<typename T, auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, divide_by)			= NIK_MODULE::template divide_by<T, V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_modulo_by)				= typename NIK_MODULE::template S_modulo_by<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_modulo_by)		= NIK_MODULE::template U_modulo_by<V>;

	template<typename T, auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, modulo_by)			= NIK_MODULE::template modulo_by<T, V>;

// comparative operators:

	using nik_name(NIK_PREFIX, S_max)				= typename NIK_MODULE::S_max;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_max)			= NIK_MODULE::U_max;

	template<typename T, typename U>
	NIK_POLICY auto nik_name(NIK_PREFIX, max)			= NIK_MODULE::template max<T, U>;

	using nik_name(NIK_PREFIX, S_min)				= typename NIK_MODULE::S_min;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_min)			= NIK_MODULE::U_min;

	template<typename T, typename U>
	NIK_POLICY auto nik_name(NIK_PREFIX, min)			= NIK_MODULE::template min<T, U>;

// predicates:

	using nik_name(NIK_PREFIX, S_equal)				= typename NIK_MODULE::S_equal;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_equal)			= NIK_MODULE::U_equal;

	template<typename T, typename U>
	NIK_POLICY auto nik_name(NIK_PREFIX, equal)			= NIK_MODULE::template equal<T, U>;

	using nik_name(NIK_PREFIX, S_not_equal)				= typename NIK_MODULE::S_not_equal;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_not_equal)		= NIK_MODULE::U_not_equal;

	template<typename T, typename U>
	NIK_POLICY auto nik_name(NIK_PREFIX, not_equal)			= NIK_MODULE::template not_equal<T, U>;

	using nik_name(NIK_PREFIX, S_less_than)				= typename NIK_MODULE::S_less_than;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_less_than)		= NIK_MODULE::U_less_than;

	template<typename T, typename U>
	NIK_POLICY auto nik_name(NIK_PREFIX, less_than)			= NIK_MODULE::template less_than<T, U>;

	using nik_name(NIK_PREFIX, S_less_than_or_equal)		= typename NIK_MODULE::S_less_than_or_equal;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_less_than_or_equal)	= NIK_MODULE::U_less_than_or_equal;

	template<typename T, typename U>
	NIK_POLICY auto nik_name(NIK_PREFIX, less_than_or_equal)	= NIK_MODULE::template less_than_or_equal<T, U>;

	using nik_name(NIK_PREFIX, S_greater_than)			= typename NIK_MODULE::S_greater_than;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_greater_than)		= NIK_MODULE::U_greater_than;

	template<typename T, typename U>
	NIK_POLICY auto nik_name(NIK_PREFIX, greater_than)		= NIK_MODULE::template greater_than<T, U>;

	using nik_name(NIK_PREFIX, S_greater_than_or_equal)		= typename NIK_MODULE::S_greater_than_or_equal;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_greater_than_or_equal)	= NIK_MODULE::U_greater_than_or_equal;

	template<typename T, typename U>
	NIK_POLICY auto nik_name(NIK_PREFIX, greater_than_or_equal)	= NIK_MODULE::template greater_than_or_equal<T, U>;

	//

	template<auto V>
	using nik_name(NIK_PREFIX, S_is_value)				= typename NIK_MODULE::template S_is_value<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_value)		= NIK_MODULE::template U_is_value<V>;

	template<typename T, auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_value)			= NIK_MODULE::template is_value<T, V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_not_value)				= typename NIK_MODULE::template S_not_value<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_not_value)		= NIK_MODULE::template U_not_value<V>;

	template<typename T, auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, not_value)			= NIK_MODULE::template not_value<T, V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_is_less_than)			= typename NIK_MODULE::template S_is_less_than<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_less_than)		= NIK_MODULE::template U_is_less_than<V>;

	template<typename T, auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_less_than)		= NIK_MODULE::template is_less_than<T, V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_is_less_than_or_equal)	= typename NIK_MODULE::template S_is_less_than_or_equal<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_less_than_or_equal)	= NIK_MODULE::template U_is_less_than_or_equal<V>;

	template<typename T, auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_less_than_or_equal)	= NIK_MODULE::template is_less_than_or_equal<T, V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_is_greater_than)			= typename NIK_MODULE::template S_is_greater_than<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_greater_than)		= NIK_MODULE::template U_is_greater_than<V>;

	template<typename T, auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_greater_than)		= NIK_MODULE::template is_greater_than<T, V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_is_greater_than_or_equal)	= typename NIK_MODULE::template S_is_greater_than_or_equal<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_greater_than_or_equal) = NIK_MODULE::template U_is_greater_than_or_equal<V>;

	template<typename T, auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_greater_than_or_equal)	= NIK_MODULE::template is_greater_than_or_equal<T, V>;

// boolean operators:

	using nik_name(NIK_PREFIX, S_conjunction)			= typename NIK_MODULE::S_conjunction;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_conjunction)		= NIK_MODULE::U_conjunction;

	NIK_POLICY auto nik_name(NIK_PREFIX, conjunction)		= NIK_MODULE::conjunction;

	using nik_name(NIK_PREFIX, S_disjunction)			= typename NIK_MODULE::S_disjunction;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_disjunction)		= NIK_MODULE::U_disjunction;

	NIK_POLICY auto nik_name(NIK_PREFIX, disjunction)		= NIK_MODULE::disjunction;

	using nik_name(NIK_PREFIX, S_implication)			= typename NIK_MODULE::S_implication;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_implication)		= NIK_MODULE::U_implication;

	NIK_POLICY auto nik_name(NIK_PREFIX, implication)		= NIK_MODULE::implication;

	using nik_name(NIK_PREFIX, S_equivalence)			= typename NIK_MODULE::S_equivalence;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_equivalence)		= NIK_MODULE::U_equivalence;

	NIK_POLICY auto nik_name(NIK_PREFIX, equivalence)		= NIK_MODULE::equivalence;

	using nik_name(NIK_PREFIX, S_negation)				= typename NIK_MODULE::S_negation;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_negation)		= NIK_MODULE::U_negation;

	NIK_POLICY auto nik_name(NIK_PREFIX, negation)			= NIK_MODULE::negation;

// dereference operators:

	using nik_name(NIK_PREFIX, S_dereference)			= typename NIK_MODULE::S_dereference;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_dereference)		= NIK_MODULE::U_dereference;

	template<typename T>
	NIK_POLICY auto nik_name(NIK_PREFIX, dereference)		= NIK_MODULE::template dereference<T>;

	using nik_name(NIK_PREFIX, S_cdereference)			= typename NIK_MODULE::S_cdereference;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_cdereference)		= NIK_MODULE::U_cdereference;

	template<typename T>
	NIK_POLICY auto nik_name(NIK_PREFIX, cdereference)		= NIK_MODULE::template cdereference<T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// reflection:

/***********************************************************************************************************************/

// match:

	using nik_name(NIK_PREFIX, S_is_function)			= typename NIK_MODULE::S_is_function;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_function)		= NIK_MODULE::U_is_function;

	template<auto f>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_function)		= NIK_MODULE::template is_function<f>;

// arity:

	using nik_name(NIK_PREFIX, S_arity)				= typename NIK_MODULE::S_arity;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_arity)			= NIK_MODULE::U_arity;

	template<auto f>
	NIK_POLICY auto nik_name(NIK_PREFIX, arity)			= NIK_MODULE::template arity<f>;

// is n-ary:

	using nik_name(NIK_PREFIX, S_is_n_ary)				= typename NIK_MODULE::S_is_n_ary;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_n_ary)		= NIK_MODULE::U_is_n_ary;

	template<auto f, auto n>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_n_ary)			= NIK_MODULE::template is_n_ary<f, n>;

// out type:

	using nik_name(NIK_PREFIX, S_out_type)				= typename NIK_MODULE::S_out_type;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_out_type)		= NIK_MODULE::U_out_type;

	template<auto f>
	using nik_name(NIK_PREFIX, out_type)				= typename NIK_MODULE::template out_type<f>;

// in type:

	using nik_name(NIK_PREFIX, S_in_type)				= typename NIK_MODULE::S_in_type;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_in_type)			= NIK_MODULE::U_in_type;

	template<auto f, auto pos = 0, auto depth = 500>
	using nik_name(NIK_PREFIX, in_type)				= typename NIK_MODULE::template
										in_type<f, pos, depth>;

// in types:

	using nik_name(NIK_PREFIX, S_in_types)				= typename NIK_MODULE::S_in_types;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_in_types)		= NIK_MODULE::U_in_types;

	template<auto f>
	using nik_name(NIK_PREFIX, in_types)				= typename NIK_MODULE::template in_types<f>;

// in types left:

	using nik_name(NIK_PREFIX, S_in_types_left)			= typename NIK_MODULE::S_in_types_left;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_in_types_left)		= NIK_MODULE::U_in_types_left;

	template<auto f, auto pos, auto depth = 500>
	using nik_name(NIK_PREFIX, in_types_left)			= typename NIK_MODULE::template
										in_types_left<f, pos, depth>;

// in types right:

	using nik_name(NIK_PREFIX, S_in_types_right)			= typename NIK_MODULE::S_in_types_right;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_in_types_right)		= NIK_MODULE::U_in_types_right;

	template<auto f, auto pos, auto depth = 500>
	using nik_name(NIK_PREFIX, in_types_right)			= typename NIK_MODULE::template
										in_types_right<f, pos, depth>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

