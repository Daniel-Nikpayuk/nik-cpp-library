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

// constants:

	template<auto V>
	using nik_name(NIK_PREFIX, S_constant)				= typename NIK_MODULE::template S_constant<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_constant)		= NIK_MODULE::template U_constant<V>;

// arithmetic operators:

	using nik_name(NIK_PREFIX, S_add)				= typename NIK_MODULE::S_add;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_add)			= NIK_MODULE::U_add;

	using nik_name(NIK_PREFIX, S_subtract)				= typename NIK_MODULE::S_subtract;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_subtract)		= NIK_MODULE::U_subtract;

	using nik_name(NIK_PREFIX, S_multiply)				= typename NIK_MODULE::S_multiply;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_multiply)		= NIK_MODULE::U_multiply;

	using nik_name(NIK_PREFIX, S_divide)				= typename NIK_MODULE::S_divide;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_divide)			= NIK_MODULE::U_divide;

	using nik_name(NIK_PREFIX, S_modulo)				= typename NIK_MODULE::S_modulo;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_modulo)			= NIK_MODULE::U_modulo;

	//

	template<auto V>
	using nik_name(NIK_PREFIX, S_add_by)				= typename NIK_MODULE::template S_add_by<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_add_by)			= NIK_MODULE::template U_add_by<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_subtract_by)			= typename NIK_MODULE::template S_subtract_by<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_subtract_by)		= NIK_MODULE::template U_subtract_by<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_multiply_by)			= typename NIK_MODULE::template S_multiply_by<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_multiply_by)		= NIK_MODULE::template U_multiply_by<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_divide_by)				= typename NIK_MODULE::template S_divide_by<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_divide_by)		= NIK_MODULE::template U_divide_by<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_modulo_by)				= typename NIK_MODULE::template S_modulo_by<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_modulo_by)		= NIK_MODULE::template U_modulo_by<V>;

// comparative operators:

	using nik_name(NIK_PREFIX, S_max)				= typename NIK_MODULE::S_max;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_max)			= NIK_MODULE::U_max;

	using nik_name(NIK_PREFIX, S_min)				= typename NIK_MODULE::S_min;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_min)			= NIK_MODULE::U_min;

// predicates:

	using nik_name(NIK_PREFIX, S_equal)				= typename NIK_MODULE::S_equal;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_equal)			= NIK_MODULE::U_equal;

	using nik_name(NIK_PREFIX, S_not_equal)				= typename NIK_MODULE::S_not_equal;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_not_equal)		= NIK_MODULE::U_not_equal;

	using nik_name(NIK_PREFIX, S_less_than)				= typename NIK_MODULE::S_less_than;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_less_than)		= NIK_MODULE::U_less_than;

	using nik_name(NIK_PREFIX, S_less_than_or_equal)		= typename NIK_MODULE::S_less_than_or_equal;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_less_than_or_equal)	= NIK_MODULE::U_less_than_or_equal;

	using nik_name(NIK_PREFIX, S_greater_than)			= typename NIK_MODULE::S_greater_than;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_greater_than)		= NIK_MODULE::U_greater_than;

	using nik_name(NIK_PREFIX, S_greater_than_or_equal)		= typename NIK_MODULE::S_greater_than_or_equal;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_greater_than_or_equal)	= NIK_MODULE::U_greater_than_or_equal;

	//

	template<auto V>
	using nik_name(NIK_PREFIX, S_is_value)				= typename NIK_MODULE::template S_is_value<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_value)		= NIK_MODULE::template U_is_value<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_not_value)				= typename NIK_MODULE::template S_not_value<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_not_value)		= NIK_MODULE::template U_not_value<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_is_less_than)			= typename NIK_MODULE::template S_is_less_than<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_less_than)		= NIK_MODULE::template U_is_less_than<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_is_less_than_or_equal)	= typename NIK_MODULE::template S_is_less_than_or_equal<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_less_than_or_equal)	= NIK_MODULE::template U_is_less_than_or_equal<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_is_greater_than)			= typename NIK_MODULE::template S_is_greater_than<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_greater_than)		= NIK_MODULE::template U_is_greater_than<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, S_is_greater_than_or_equal)	= typename NIK_MODULE::template S_is_greater_than_or_equal<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_greater_than_or_equal) = NIK_MODULE::template U_is_greater_than_or_equal<V>;

// boolean operators:

	using nik_name(NIK_PREFIX, S_conjunction)			= typename NIK_MODULE::S_conjunction;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_conjunction)		= NIK_MODULE::U_conjunction;

	using nik_name(NIK_PREFIX, S_disjunction)			= typename NIK_MODULE::S_disjunction;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_disjunction)		= NIK_MODULE::U_disjunction;

	using nik_name(NIK_PREFIX, S_implication)			= typename NIK_MODULE::S_implication;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_implication)		= NIK_MODULE::U_implication;

	using nik_name(NIK_PREFIX, S_equivalence)			= typename NIK_MODULE::S_equivalence;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_equivalence)		= NIK_MODULE::U_equivalence;

	using nik_name(NIK_PREFIX, S_negation)				= typename NIK_MODULE::S_negation;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_negation)		= NIK_MODULE::U_negation;

// dereference operators:

	using nik_name(NIK_PREFIX, S_dereference)			= typename NIK_MODULE::S_dereference;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_dereference)		= NIK_MODULE::U_dereference;

	using nik_name(NIK_PREFIX, S_cdereference)			= typename NIK_MODULE::S_cdereference;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_cdereference)		= NIK_MODULE::U_cdereference;

// evaluation operators:

	template<auto uf, typename T>
	inline NIK_POLICY auto nik_name(NIK_PREFIX, apply)(T v)
	{
		return NIK_MODULE::template apply<uf, T>(v);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/

// keywords:

	using nik_name(NIK_PREFIX, S_is_id_keyword)			= typename NIK_MODULE::S_is_id_keyword;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_id_keyword)		= NIK_MODULE::U_is_id_keyword;

	template<auto f>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_id_keyword)		= NIK_MODULE::template is_id_keyword<f>;

/***********************************************************************************************************************/

// composition operators:

	using nik_name(NIK_PREFIX, S_postcompose)			= typename NIK_MODULE::S_postcompose;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_postcompose)		= NIK_MODULE::U_postcompose;

	template<auto uf1, auto uf2>
	NIK_POLICY auto nik_name(NIK_PREFIX, postcompose)		= NIK_MODULE::template postcompose<uf1, uf2>;

	using nik_name(NIK_PREFIX, S_precompose)			= typename NIK_MODULE::S_precompose;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_precompose)		= NIK_MODULE::U_precompose;

	template<auto uf1, auto uf2>
	NIK_POLICY auto nik_name(NIK_PREFIX, precompose)		= NIK_MODULE::template precompose<uf1, uf2>;

	template<auto uf0, auto... ufs>
	NIK_POLICY auto nik_name(NIK_PREFIX, chain_precompose)		= NIK_MODULE::template chain_precompose<uf0, ufs...>;

/***********************************************************************************************************************/

// optimized composition operators:

	using nik_name(NIK_PREFIX, S_opt_postcompose)			= typename NIK_MODULE::S_opt_postcompose;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_opt_postcompose)		= NIK_MODULE::U_opt_postcompose;

	template<auto uf1, auto uf2>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_postcompose)		= NIK_MODULE::template opt_postcompose<uf1, uf2>;

	using nik_name(NIK_PREFIX, S_opt_precompose)			= typename NIK_MODULE::S_opt_precompose;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_opt_precompose)		= NIK_MODULE::U_opt_precompose;

	template<auto uf1, auto uf2>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_precompose)		= NIK_MODULE::template opt_precompose<uf1, uf2>;

	template<auto uf0, auto... ufs>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_chain_precompose)	= NIK_MODULE::template
										opt_chain_precompose<uf0, ufs...>;

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

