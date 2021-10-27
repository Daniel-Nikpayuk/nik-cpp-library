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

// attributes:

	using nik_name(NIK_PREFIX, Argument)				= typename NIK_MODULE::Argument;

	//

	template<auto p>
	NIK_POLICY bool nik_name(NIK_PREFIX, arg_is_to_const)		= NIK_MODULE::template arg_is_to_const<p>;

	template<auto p>
	NIK_POLICY bool nik_name(NIK_PREFIX, arg_is_from_const)		= NIK_MODULE::template arg_is_from_const<p>;

	template<auto p>
	NIK_POLICY bool nik_name(NIK_PREFIX, arg_is_to_reference)	= NIK_MODULE::template arg_is_to_reference<p>;

	template<auto p>
	NIK_POLICY bool nik_name(NIK_PREFIX, arg_is_from_reference)	= NIK_MODULE::template arg_is_from_reference<p>;

	//

	template<auto p>
	NIK_POLICY bool nik_name(NIK_PREFIX, arg_is_to_val)		= NIK_MODULE::template arg_is_to_val<p>;

	template<auto p>
	NIK_POLICY bool nik_name(NIK_PREFIX, arg_is_to_ref)		= NIK_MODULE::template arg_is_to_ref<p>;

	template<auto p>
	NIK_POLICY bool nik_name(NIK_PREFIX, arg_is_to_cval)		= NIK_MODULE::template arg_is_to_cval<p>;

	template<auto p>
	NIK_POLICY bool nik_name(NIK_PREFIX, arg_is_to_cref)		= NIK_MODULE::template arg_is_to_cref<p>;

/***********************************************************************************************************************/

// modify:

	template<typename T, auto V>
	using nik_name(NIK_PREFIX, T_arg_modify_TxV)		= typename NIK_MODULE::template T_arg_modify_TxV<T, V>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatchers:

/***********************************************************************************************************************/

// specialize:

	template<auto J, typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, specialize)		= NIK_MODULE::template specialize<J, Ts...>;

/***********************************************************************************************************************/

// resolve:

	template<auto J, typename List>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve)			= NIK_MODULE::template resolve<J, List>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomic functions:

/***********************************************************************************************************************/

// identity:

	using nik_name(NIK_PREFIX, F_id)				= typename NIK_MODULE::F_id;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_id)			= NIK_MODULE::J_id;

// constants:

	template<auto V>
	using nik_name(NIK_PREFIX, F_constant_V)			= typename NIK_MODULE::template F_constant_V<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, J_constant_V)		= NIK_MODULE::template J_constant_V<V>;

// arithmetic operators:

	using nik_name(NIK_PREFIX, F_add)				= typename NIK_MODULE::F_add;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_add)			= NIK_MODULE::J_add;

	using nik_name(NIK_PREFIX, F_subtract)				= typename NIK_MODULE::F_subtract;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_subtract)		= NIK_MODULE::J_subtract;

	using nik_name(NIK_PREFIX, F_multiply)				= typename NIK_MODULE::F_multiply;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_multiply)		= NIK_MODULE::J_multiply;

	using nik_name(NIK_PREFIX, F_divide)				= typename NIK_MODULE::F_divide;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_divide)			= NIK_MODULE::J_divide;

	using nik_name(NIK_PREFIX, F_modulo)				= typename NIK_MODULE::F_modulo;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_modulo)			= NIK_MODULE::J_modulo;

	//

	template<auto V>
	using nik_name(NIK_PREFIX, F_add_by_V)				= typename NIK_MODULE::template F_add_by_V<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, J_add_by_V)		= NIK_MODULE::template J_add_by_V<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, F_subtract_by_V)			= typename NIK_MODULE::template F_subtract_by_V<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, J_subtract_by_V)		= NIK_MODULE::template J_subtract_by_V<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, F_multiply_by_V)			= typename NIK_MODULE::template F_multiply_by_V<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, J_multiply_by_V)		= NIK_MODULE::template J_multiply_by_V<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, F_divide_by_V)			= typename NIK_MODULE::template F_divide_by_V<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, J_divide_by_V)		= NIK_MODULE::template J_divide_by_V<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, F_modulo_by_V)			= typename NIK_MODULE::template F_modulo_by_V<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, J_modulo_by_V)		= NIK_MODULE::template J_modulo_by_V<V>;

// comparative operators:

	using nik_name(NIK_PREFIX, F_max)				= typename NIK_MODULE::F_max;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_max)			= NIK_MODULE::J_max;

	using nik_name(NIK_PREFIX, F_min)				= typename NIK_MODULE::F_min;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_min)			= NIK_MODULE::J_min;

// predicates:

	using nik_name(NIK_PREFIX, F_equal)				= typename NIK_MODULE::F_equal;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_equal)			= NIK_MODULE::J_equal;

	using nik_name(NIK_PREFIX, F_not_equal)				= typename NIK_MODULE::F_not_equal;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_not_equal)		= NIK_MODULE::J_not_equal;

	using nik_name(NIK_PREFIX, F_less_than)				= typename NIK_MODULE::F_less_than;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_less_than)		= NIK_MODULE::J_less_than;

	using nik_name(NIK_PREFIX, F_less_than_or_equal)		= typename NIK_MODULE::F_less_than_or_equal;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_less_than_or_equal)	= NIK_MODULE::J_less_than_or_equal;

	using nik_name(NIK_PREFIX, F_greater_than)			= typename NIK_MODULE::F_greater_than;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_greater_than)		= NIK_MODULE::J_greater_than;

	using nik_name(NIK_PREFIX, F_greater_than_or_equal)		= typename NIK_MODULE::F_greater_than_or_equal;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_greater_than_or_equal)	= NIK_MODULE::J_greater_than_or_equal;

	//

	template<auto V>
	using nik_name(NIK_PREFIX, F_is_value_V)			= typename NIK_MODULE::template F_is_value_V<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, J_is_value_V)		= NIK_MODULE::template J_is_value_V<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, F_not_value_V)			= typename NIK_MODULE::template F_not_value_V<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, J_not_value_V)		= NIK_MODULE::template J_not_value_V<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, F_is_less_than_V)			= typename NIK_MODULE::template F_is_less_than_V<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, J_is_less_than_V)		= NIK_MODULE::template J_is_less_than_V<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, F_is_less_than_or_equal_V)		= typename NIK_MODULE::template F_is_less_than_or_equal_V<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, J_is_less_than_or_equal_V)	= NIK_MODULE::template J_is_less_than_or_equal_V<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, F_is_greater_than_V)			= typename NIK_MODULE::template F_is_greater_than_V<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, J_is_greater_than_V)	= NIK_MODULE::template J_is_greater_than_V<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, F_is_greater_than_or_equal_V)	= typename NIK_MODULE::template F_is_greater_than_or_equal_V<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, J_is_greater_than_or_equal_V) = NIK_MODULE::template J_is_greater_than_or_equal_V<V>;

// boolean operators:

	using nik_name(NIK_PREFIX, F_conjunction)			= typename NIK_MODULE::F_conjunction;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_conjunction)		= NIK_MODULE::J_conjunction;

	using nik_name(NIK_PREFIX, F_disjunction)			= typename NIK_MODULE::F_disjunction;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_disjunction)		= NIK_MODULE::J_disjunction;

	using nik_name(NIK_PREFIX, F_implication)			= typename NIK_MODULE::F_implication;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_implication)		= NIK_MODULE::J_implication;

	using nik_name(NIK_PREFIX, F_equivalence)			= typename NIK_MODULE::F_equivalence;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_equivalence)		= NIK_MODULE::J_equivalence;

	using nik_name(NIK_PREFIX, F_negation)				= typename NIK_MODULE::F_negation;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_negation)		= NIK_MODULE::J_negation;

// dereference operator:

	using nik_name(NIK_PREFIX, F_dereference)			= typename NIK_MODULE::F_dereference;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_dereference)		= NIK_MODULE::J_dereference;

// evaluation operator:

	template<auto J>
	using nik_name(NIK_PREFIX, F_apply_J)				= typename NIK_MODULE::template F_apply_J<J>;

	template<auto J>
	NIK_POLICY auto nik_name(NIK_PREFIX, J_apply_J)			= NIK_MODULE::template J_apply_J<J>;

	template<auto J, typename... Ts>
	inline NIK_POLICY auto nik_name(NIK_PREFIX, apply)(Ts... vs)
	{
		return NIK_MODULE::template apply<J, Ts...>(vs...);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/

// keywords:

	using nik_name(NIK_PREFIX, E_is_id_keyword)			= typename NIK_MODULE::E_is_id_keyword;

	NIK_POLICY auto nik_name(NIK_PREFIX, I_is_id_keyword)		= NIK_MODULE::I_is_id_keyword;

	template<auto J>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_id_keyword)		= NIK_MODULE::template is_id_keyword<J>;

/***********************************************************************************************************************/

// composition operators:

	using nik_name(NIK_PREFIX, E_postcompose)			= typename NIK_MODULE::E_postcompose;

	NIK_POLICY auto nik_name(NIK_PREFIX, I_postcompose)		= NIK_MODULE::I_postcompose;

	template<auto J1, auto J2>
	NIK_POLICY auto nik_name(NIK_PREFIX, postcompose)		= NIK_MODULE::template postcompose<J1, J2>;

	using nik_name(NIK_PREFIX, E_precompose)			= typename NIK_MODULE::E_precompose;

	NIK_POLICY auto nik_name(NIK_PREFIX, I_precompose)		= NIK_MODULE::I_precompose;

	template<auto J1, auto J2>
	NIK_POLICY auto nik_name(NIK_PREFIX, precompose)		= NIK_MODULE::template precompose<J1, J2>;

	template<auto J0, auto... Js>
	NIK_POLICY auto nik_name(NIK_PREFIX, chain_precompose)		= NIK_MODULE::template chain_precompose<J0, Js...>;

/***********************************************************************************************************************/

// optimized composition operators:

	using nik_name(NIK_PREFIX, E_opt_postcompose)			= typename NIK_MODULE::E_opt_postcompose;

	NIK_POLICY auto nik_name(NIK_PREFIX, I_opt_postcompose)		= NIK_MODULE::I_opt_postcompose;

	template<auto J1, auto J2>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_postcompose)		= NIK_MODULE::template opt_postcompose<J1, J2>;

	using nik_name(NIK_PREFIX, E_opt_precompose)			= typename NIK_MODULE::E_opt_precompose;

	NIK_POLICY auto nik_name(NIK_PREFIX, I_opt_precompose)		= NIK_MODULE::I_opt_precompose;

	template<auto J1, auto J2>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_precompose)		= NIK_MODULE::template opt_precompose<J1, J2>;

	template<auto J0, auto... Js>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_chain_precompose)	= NIK_MODULE::template opt_chain_precompose<J0, Js...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

