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

// near linear induction:

/*
	ch - continuation halting
	cp - continuation passing
*/

// run time (compatible) stem lattice:

/*
	pf - policy_f		p1f  - policy1_f	p2f  - policy2_f
	bf - break_f		b1f  - break1_f		b2f  - break2_f
	nf - next_f		n1f  - next1_f		n2f  - next2_f
				n11f - next11_f		n2f - next2_f
				n12f - next12_f
	cf - cont_f
*/

/***********************************************************************************************************************/

namespace nlfs_2
{
	using namespace nlfs_1;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// continuation passing constructors:

	// These constructors require out/in types as
	// their inferences cannot be guaranteed (_id_).

	// Pattern matching against arg type lists
	// clarifies the intended signature.

/***********************************************************************************************************************/

// lift:

		// The only complication here is when both f, cont_f == _id_,
		// then we need a way of infering the Type.

	template<auto f, typename ArgTypes = function_types<f>> struct cp_lift;

	template<auto f, template<auto...> class ListName, auto OutType, auto InTypes...>
	struct cp_lift<f, ListName<OutType, InTypes...>>
	{
		template<auto composed_f>
		using let_result = T_colist_Bs
		<
			composed_f, _na_,		OutType, composed_f,

			S_is_id_keyword,		return_id,
			otherwise,			return_right_function
		>;

		template<auto cont_f>
		static constexpr OutType (*result)(InTypes...) = V_value_S
		<
			let_result<V_compose_opt<cont_f, f>>
		>;
	};

	//

	template
	<
		bool predicate,
		auto function1,
		auto function2		= _id_,
		typename ArgTypes	= function_types<V_if_then_else<predicate, function1, function2>>
	>
	using cp_if_then_else = cp_lift<V_if_then_else<predicate, function1, function2>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// stem:

/***********************************************************************************************************************/

