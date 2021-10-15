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

// dereference operators:

	using nik_name(NIK_PREFIX, F_dereference)			= typename NIK_MODULE::F_dereference;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_dereference)		= NIK_MODULE::J_dereference;

	using nik_name(NIK_PREFIX, F_cdereference)			= typename NIK_MODULE::F_cdereference;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_cdereference)		= NIK_MODULE::J_cdereference;

// evaluation operators:

	using nik_name(NIK_PREFIX, F_apply)				= typename NIK_MODULE::F_apply;

	NIK_POLICY auto nik_name(NIK_PREFIX, J_apply)			= NIK_MODULE::J_apply;

	template<auto uf, typename... Ts>
	inline NIK_POLICY auto nik_name(NIK_PREFIX, apply)(Ts... vs)
	{
		return NIK_MODULE::template apply<uf, Ts...>(vs...);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/

// keywords:

	using nik_name(NIK_PREFIX, E_is_id_keyword)			= typename NIK_MODULE::E_is_id_keyword;

	NIK_POLICY auto nik_name(NIK_PREFIX, I_is_id_keyword)		= NIK_MODULE::I_is_id_keyword;

	template<auto f>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_id_keyword)		= NIK_MODULE::template is_id_keyword<f>;

/***********************************************************************************************************************/

// composition operators:

	using nik_name(NIK_PREFIX, E_postcompose)			= typename NIK_MODULE::E_postcompose;

	NIK_POLICY auto nik_name(NIK_PREFIX, I_postcompose)		= NIK_MODULE::I_postcompose;

	template<auto uf1, auto uf2>
	NIK_POLICY auto nik_name(NIK_PREFIX, postcompose)		= NIK_MODULE::template postcompose<uf1, uf2>;

	using nik_name(NIK_PREFIX, E_precompose)			= typename NIK_MODULE::E_precompose;

	NIK_POLICY auto nik_name(NIK_PREFIX, I_precompose)		= NIK_MODULE::I_precompose;

	template<auto uf1, auto uf2>
	NIK_POLICY auto nik_name(NIK_PREFIX, precompose)		= NIK_MODULE::template precompose<uf1, uf2>;

	template<auto uf0, auto... ufs>
	NIK_POLICY auto nik_name(NIK_PREFIX, chain_precompose)		= NIK_MODULE::template chain_precompose<uf0, ufs...>;

/***********************************************************************************************************************/

// optimized composition operators:

	using nik_name(NIK_PREFIX, E_opt_postcompose)			= typename NIK_MODULE::E_opt_postcompose;

	NIK_POLICY auto nik_name(NIK_PREFIX, I_opt_postcompose)		= NIK_MODULE::I_opt_postcompose;

	template<auto uf1, auto uf2>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_postcompose)		= NIK_MODULE::template opt_postcompose<uf1, uf2>;

	using nik_name(NIK_PREFIX, E_opt_precompose)			= typename NIK_MODULE::E_opt_precompose;

	NIK_POLICY auto nik_name(NIK_PREFIX, I_opt_precompose)		= NIK_MODULE::I_opt_precompose;

	template<auto uf1, auto uf2>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_precompose)		= NIK_MODULE::template opt_precompose<uf1, uf2>;

	template<auto uf0, auto... ufs>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_chain_precompose)	= NIK_MODULE::template opt_chain_precompose<uf0, ufs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatchers:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// enumeration filters (level 0):

/***********************************************************************************************************************/

// attributes:

	using nik_name(NIK_PREFIX, Mutability)				= typename NIK_MODULE::Mutability;

	using nik_name(NIK_PREFIX, Denotation)				= typename NIK_MODULE::Denotation;

	//

	template<auto m>
	NIK_POLICY bool nik_name(NIK_PREFIX, is_immutable)		= NIK_MODULE::template is_immutable<m>;

	template<auto m>
	NIK_POLICY bool nik_name(NIK_PREFIX, is_variable)		= NIK_MODULE::template is_variable<m>;

	//

	template<auto d>
	NIK_POLICY bool nik_name(NIK_PREFIX, is_by_value)		= NIK_MODULE::template is_by_value<d>;

	template<auto d>
	NIK_POLICY bool nik_name(NIK_PREFIX, is_by_reference)		= NIK_MODULE::template is_by_reference<d>;

/***********************************************************************************************************************/

// attribute filters (level 1):

/***********************************************************************************************************************/

	template<auto m, auto d>
	using nik_name(NIK_PREFIX, _attributes)				= typename NIK_MODULE::template _attributes<m, d>;

	//

	using nik_name(NIK_PREFIX, attr_by_val)				= typename NIK_MODULE::attr_by_val;
	using nik_name(NIK_PREFIX, attr_by_ref)				= typename NIK_MODULE::attr_by_ref;
	using nik_name(NIK_PREFIX, attr_by_cval)			= typename NIK_MODULE::attr_by_cval;
	using nik_name(NIK_PREFIX, attr_by_cref)			= typename NIK_MODULE::attr_by_cref;

/***********************************************************************************************************************/

// member argument filters (level 2):

/***********************************************************************************************************************/

	template<typename T, typename A>
	using nik_name(NIK_PREFIX, _argument)				= typename NIK_MODULE::template _argument<T, A>;

	//

	template<typename T>
	using nik_name(NIK_PREFIX, arg_by_val)				= typename NIK_MODULE::template arg_by_val<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, arg_by_ref)				= typename NIK_MODULE::template arg_by_ref<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, arg_by_cval)				= typename NIK_MODULE::template arg_by_cval<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, arg_by_cref)				= typename NIK_MODULE::template arg_by_cref<T>;

/***********************************************************************************************************************/

// facade filters (level 3):

/***********************************************************************************************************************/

	template<typename... Args>
	using nik_name(NIK_PREFIX, _facade)				= typename NIK_MODULE::template _facade<Args...>;

/***********************************************************************************************************************/

// sign:

	template<typename Arg>
	using nik_name(NIK_PREFIX, sign_type)				= typename NIK_MODULE::template sign_type<Arg>;

/***********************************************************************************************************************/

// resolve:

	template<auto ufunc, typename Facade>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve)			= NIK_MODULE::template resolve<ufunc, Facade>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

