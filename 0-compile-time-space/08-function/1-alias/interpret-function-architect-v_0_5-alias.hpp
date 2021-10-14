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

	using nik_name(NIK_PREFIX, T_id__F)				= typename NIK_MODULE::T_id__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_id__F)			= NIK_MODULE::U_id__F;

// constants:

	template<auto V>
	using nik_name(NIK_PREFIX, T_constant__F)			= typename NIK_MODULE::template T_constant__F<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_constant__F)		= NIK_MODULE::template U_constant__F<V>;

// arithmetic operators:

	using nik_name(NIK_PREFIX, T_add__F)				= typename NIK_MODULE::T_add__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_add__F)			= NIK_MODULE::U_add__F;

	using nik_name(NIK_PREFIX, T_subtract__F)			= typename NIK_MODULE::T_subtract__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_subtract__F)		= NIK_MODULE::U_subtract__F;

	using nik_name(NIK_PREFIX, T_multiply__F)			= typename NIK_MODULE::T_multiply__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_multiply__F)		= NIK_MODULE::U_multiply__F;

	using nik_name(NIK_PREFIX, T_divide__F)				= typename NIK_MODULE::T_divide__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_divide__F)		= NIK_MODULE::U_divide__F;

	using nik_name(NIK_PREFIX, T_modulo__F)				= typename NIK_MODULE::T_modulo__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_modulo__F)		= NIK_MODULE::U_modulo__F;

	//

	template<auto V>
	using nik_name(NIK_PREFIX, T_add_by__F)				= typename NIK_MODULE::template T_add_by__F<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_add_by__F)		= NIK_MODULE::template U_add_by__F<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, T_subtract_by__F)			= typename NIK_MODULE::template T_subtract_by__F<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_subtract_by__F)		= NIK_MODULE::template U_subtract_by__F<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, T_multiply_by__F)			= typename NIK_MODULE::template T_multiply_by__F<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_multiply_by__F)		= NIK_MODULE::template U_multiply_by__F<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, T_divide_by__F)			= typename NIK_MODULE::template T_divide_by__F<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_divide_by__F)		= NIK_MODULE::template U_divide_by__F<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, T_modulo_by__F)			= typename NIK_MODULE::template T_modulo_by__F<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_modulo_by__F)		= NIK_MODULE::template U_modulo_by__F<V>;

// comparative operators:

	using nik_name(NIK_PREFIX, T_max__F)				= typename NIK_MODULE::T_max__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_max__F)			= NIK_MODULE::U_max__F;

	using nik_name(NIK_PREFIX, T_min__F)				= typename NIK_MODULE::T_min__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_min__F)			= NIK_MODULE::U_min__F;

// predicates:

	using nik_name(NIK_PREFIX, T_equal__F)				= typename NIK_MODULE::T_equal__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_equal__F)		= NIK_MODULE::U_equal__F;

	using nik_name(NIK_PREFIX, T_not_equal__F)			= typename NIK_MODULE::T_not_equal__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_not_equal__F)		= NIK_MODULE::U_not_equal__F;

	using nik_name(NIK_PREFIX, T_less_than__F)			= typename NIK_MODULE::T_less_than__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_less_than__F)		= NIK_MODULE::U_less_than__F;

	using nik_name(NIK_PREFIX, T_less_than_or_equal__F)		= typename NIK_MODULE::T_less_than_or_equal__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_less_than_or_equal__F)	= NIK_MODULE::U_less_than_or_equal__F;

	using nik_name(NIK_PREFIX, T_greater_than__F)			= typename NIK_MODULE::T_greater_than__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_greater_than__F)		= NIK_MODULE::U_greater_than__F;

	using nik_name(NIK_PREFIX, T_greater_than_or_equal__F)		= typename NIK_MODULE::T_greater_than_or_equal__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_greater_than_or_equal__F) = NIK_MODULE::U_greater_than_or_equal__F;

	//

	template<auto V>
	using nik_name(NIK_PREFIX, T_is_value__F)			= typename NIK_MODULE::template T_is_value__F<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_value__F)		= NIK_MODULE::template U_is_value__F<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, T_not_value__F)			= typename NIK_MODULE::template T_not_value__F<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_not_value__F)		= NIK_MODULE::template U_not_value__F<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, T_is_less_than__F)			= typename NIK_MODULE::template T_is_less_than__F<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_less_than__F)		= NIK_MODULE::template U_is_less_than__F<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, T_is_less_than_or_equal__F)		= typename NIK_MODULE::template T_is_less_than_or_equal__F<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_less_than_or_equal__F) = NIK_MODULE::template U_is_less_than_or_equal__F<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, T_is_greater_than__F)		= typename NIK_MODULE::template T_is_greater_than__F<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_greater_than__F)	= NIK_MODULE::template U_is_greater_than__F<V>;

	template<auto V>
	using nik_name(NIK_PREFIX, T_is_greater_than_or_equal__F)	= typename NIK_MODULE::template T_is_greater_than_or_equal__F<V>;

	template<auto V>
	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_greater_than_or_equal__F) = NIK_MODULE::template U_is_greater_than_or_equal__F<V>;

// boolean operators:

	using nik_name(NIK_PREFIX, T_conjunction__F)			= typename NIK_MODULE::T_conjunction__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_conjunction__F)		= NIK_MODULE::U_conjunction__F;

	using nik_name(NIK_PREFIX, T_disjunction__F)			= typename NIK_MODULE::T_disjunction__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_disjunction__F)		= NIK_MODULE::U_disjunction__F;

	using nik_name(NIK_PREFIX, T_implication__F)			= typename NIK_MODULE::T_implication__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_implication__F)		= NIK_MODULE::U_implication__F;

	using nik_name(NIK_PREFIX, T_equivalence__F)			= typename NIK_MODULE::T_equivalence__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_equivalence__F)		= NIK_MODULE::U_equivalence__F;

	using nik_name(NIK_PREFIX, T_negation__F)			= typename NIK_MODULE::T_negation__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_negation__F)		= NIK_MODULE::U_negation__F;

// dereference operators:

	using nik_name(NIK_PREFIX, T_dereference__F)			= typename NIK_MODULE::T_dereference__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_dereference__F)		= NIK_MODULE::U_dereference__F;

	using nik_name(NIK_PREFIX, T_cdereference__F)			= typename NIK_MODULE::T_cdereference__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_cdereference__F)		= NIK_MODULE::U_cdereference__F;

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

	using nik_name(NIK_PREFIX, T_is_id_keyword__F)			= typename NIK_MODULE::T_is_id_keyword__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_id_keyword__F)	= NIK_MODULE::U_is_id_keyword__F;

	template<auto f>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_id_keyword)		= NIK_MODULE::template is_id_keyword<f>;

/***********************************************************************************************************************/

// composition operators:

	using nik_name(NIK_PREFIX, T_postcompose__F)			= typename NIK_MODULE::T_postcompose__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_postcompose__F)		= NIK_MODULE::U_postcompose__F;

	template<auto uf1, auto uf2>
	NIK_POLICY auto nik_name(NIK_PREFIX, postcompose)		= NIK_MODULE::template postcompose<uf1, uf2>;

	using nik_name(NIK_PREFIX, T_precompose__F)			= typename NIK_MODULE::T_precompose__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_precompose__F)		= NIK_MODULE::U_precompose__F;

	template<auto uf1, auto uf2>
	NIK_POLICY auto nik_name(NIK_PREFIX, precompose)		= NIK_MODULE::template precompose<uf1, uf2>;

	template<auto uf0, auto... ufs>
	NIK_POLICY auto nik_name(NIK_PREFIX, chain_precompose)		= NIK_MODULE::template chain_precompose<uf0, ufs...>;

/***********************************************************************************************************************/

// optimized composition operators:

	using nik_name(NIK_PREFIX, T_opt_postcompose__F)		= typename NIK_MODULE::T_opt_postcompose__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_opt_postcompose__F)	= NIK_MODULE::U_opt_postcompose__F;

	template<auto uf1, auto uf2>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_postcompose)		= NIK_MODULE::template opt_postcompose<uf1, uf2>;

	using nik_name(NIK_PREFIX, T_opt_precompose__F)			= typename NIK_MODULE::T_opt_precompose__F;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_opt_precompose__F)	= NIK_MODULE::U_opt_precompose__F;

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

