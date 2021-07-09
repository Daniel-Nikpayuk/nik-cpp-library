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

// composition operators:

	using nik_name(NIK_PREFIX, S_precompose)			= typename NIK_MODULE::S_precompose;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_precompose)		= NIK_MODULE::U_precompose;

	template<auto uf1, auto uf2>
	NIK_POLICY auto nik_name(NIK_PREFIX, precompose)		= NIK_MODULE::template precompose<uf1, uf2>;

	using nik_name(NIK_PREFIX, S_postcompose)			= typename NIK_MODULE::S_postcompose;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_postcompose)		= NIK_MODULE::U_postcompose;

	template<auto uf1, auto uf2>
	NIK_POLICY auto nik_name(NIK_PREFIX, postcompose)		= NIK_MODULE::template postcompose<uf1, uf2>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatchers:

/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

