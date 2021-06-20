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

// one cycle specifications:

/*
	P - Policy
	B - Break
	N - Next	N1 - Next1	N2 - Next2
*/

/***********************************************************************************************************************/

namespace nlfs_6
{
	using namespace nlfs_5;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// list inductor specs:

/***********************************************************************************************************************/

// root:

	template<auto N = _id_>	using before_loop		= cp_lift<N>;

	//

	template<auto N = _id_>	using before_value		= cp_lift<N>;
	template<auto N = _id_>	using after_value		= cp_lift<N>;

	template<auto N = _id_>	using before_act		= cp_lift<N>;
	template<auto N = _id_>	using after_act			= cp_lift<N>;

	template<auto N = _id_>	using before_combine		= cp_lift<N>;
	template<auto N = _id_>	using after_combine		= cp_lift<N>;

	template<auto N = _id_>	using before_next		= cp_lift<N>;
	template<auto N = _id_>	using after_next		= cp_lift<N>;

	//

	template<auto N = _id_>	using after_loop		= cp_lift<N>;

/***********************************************************************************************************************/

// stem:

	template<auto P, auto B, auto N = _id_> using stem_before_loop		= cp_stem<P, B, N>;

	//

	template<auto P, auto B, auto N = _id_> using stem_before_value		= cp_stem<P, B, N>;
	template<auto P, auto B, auto N = _id_> using stem_after_value		= cp_stem<P, B, N>;

	template<auto P, auto B, auto N = _id_> using stem_before_act		= cp_stem<P, B, N>;
	template<auto P, auto B, auto N = _id_> using stem_after_act		= cp_stem<P, B, N>;

	template<auto P, auto B, auto N = _id_> using stem_before_combine	= cp_stem<P, B, N>;
	template<auto P, auto B, auto N = _id_> using stem_after_combine	= cp_stem<P, B, N>;

	template<auto P, auto B, auto N = _id_> using stem_before_next		= cp_stem<P, B, N>;
	template<auto P, auto B, auto N = _id_> using stem_after_next		= cp_stem<P, B, N>;

	//

	template<auto P, auto B, auto N = _id_> using stem_after_loop		= cp_stem<P, B, N>;

/***********************************************************************************************************************/

// costem:

	template<auto P, auto N, auto B = _id_> using costem_before_loop	= cp_costem<P, N, B>;

	//                                                                                         

	template<auto P, auto N, auto B = _id_> using costem_before_value	= cp_costem<P, N, B>;
	template<auto P, auto N, auto B = _id_> using costem_after_value	= cp_costem<P, N, B>;

	template<auto P, auto N, auto B = _id_> using costem_before_act		= cp_costem<P, N, B>;
	template<auto P, auto N, auto B = _id_> using costem_after_act		= cp_costem<P, N, B>;

	template<auto P, auto N, auto B = _id_> using costem_before_combine	= cp_costem<P, N, B>;
	template<auto P, auto N, auto B = _id_> using costem_after_combine	= cp_costem<P, N, B>;

	template<auto P, auto N, auto B = _id_> using costem_before_next	= cp_costem<P, N, B>;
	template<auto P, auto N, auto B = _id_> using costem_after_next		= cp_costem<P, N, B>;

	//                                                                                         

	template<auto P, auto N, auto B = _id_> using costem_after_loop		= cp_costem<P, N, B>;

/***********************************************************************************************************************/

// distem:

	template<auto P, auto N1, auto N2 = _id_> using distem_before_loop	= cp_distem<P, N1, N2>;

	//

	template<auto P, auto N1, auto N2 = _id_> using distem_before_value	= cp_distem<P, N1, N2>;
	template<auto P, auto N1, auto N2 = _id_> using distem_after_value	= cp_distem<P, N1, N2>;

	template<auto P, auto N1, auto N2 = _id_> using distem_before_act	= cp_distem<P, N1, N2>;
	template<auto P, auto N1, auto N2 = _id_> using distem_after_act	= cp_distem<P, N1, N2>;

	template<auto P, auto N1, auto N2 = _id_> using distem_before_combine	= cp_distem<P, N1, N2>;
	template<auto P, auto N1, auto N2 = _id_> using distem_after_combine	= cp_distem<P, N1, N2>;

	template<auto P, auto N1, auto N2 = _id_> using distem_before_next	= cp_distem<P, N1, N2>;
	template<auto P, auto N1, auto N2 = _id_> using distem_after_next	= cp_distem<P, N1, N2>;

	//

	template<auto P, auto N1, auto N2 = _id_> using distem_after_loop	= cp_distem<P, N1, N2>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// list operator specs:

/***********************************************************************************************************************/

// out:

	template<typename Spec> using out_type_					= typename Spec::out_type;

	template<typename Spec> constexpr auto out_ival_			= Spec::out_ival;
	template<typename Spec> constexpr auto out_ival_meet_			= Spec::out_ival_meet;
	template<typename Spec> constexpr auto out_next_			= Spec::out_next;

/***********************************************************************************************************************/

// in:

	template<typename Spec> using in_type_					= typename Spec::in_type;

	template<typename Spec> constexpr auto in_ival_				= Spec::in_ival;
	template<typename Spec> constexpr auto in_ival_meet_			= Spec::in_ival_meet;
	template<typename Spec> constexpr auto in_next_				= Spec::in_next;

/***********************************************************************************************************************/

// car in:

	template<typename Spec> using car_in_type_				= typename Spec::car_in_type;

	template<typename Spec> constexpr auto car_in_ival_			= Spec::car_in_ival;
	template<typename Spec> constexpr auto car_in_ival_meet_		= Spec::car_in_ival_meet;
	template<typename Spec> constexpr auto car_in_next_			= Spec::car_in_next;

/***********************************************************************************************************************/

// cdr in:

	template<typename Spec> using cdr_in_type_				= typename Spec::cdr_in_type;

	template<typename Spec> constexpr auto cdr_in_ival_			= Spec::cdr_in_ival;
	template<typename Spec> constexpr auto cdr_in_ival_meet_		= Spec::cdr_in_ival_meet;
	template<typename Spec> constexpr auto cdr_in_next_			= Spec::cdr_in_next;

/***********************************************************************************************************************/

// end:

	template<typename Spec> using end_type_					= typename Spec::end_type;

	template<typename Spec> constexpr auto end_next_			= Spec::end_next;
	template<typename Spec> constexpr auto end_prev_			= Spec::end_previous;

/***********************************************************************************************************************/

// aux:

//	template<typename Spec> using aux_type_					= typename Spec::aux_type;

/***********************************************************************************************************************/

// msg:

//	template<typename Spec> using msg_type_					= typename Spec::msg_type;

/***********************************************************************************************************************/

// signature:

	template<typename Spec> using signature_				= typename Spec::signature;

/***********************************************************************************************************************/

// return:

	template<typename Spec> using return_type_				= typename Spec::return_type;

	template<typename Spec> constexpr auto return_cons_			= Spec::return_constructor;

/***********************************************************************************************************************/

// predicate:

	template<typename Spec> constexpr bool ival_meet_			= Spec::ival_meet;
	template<typename Spec> constexpr bool is_bi_last_			= Spec::is_bi_last;

/***********************************************************************************************************************/

// function:

	template<typename Spec> constexpr auto loop_pred_			= Spec::loop_predicate;
	template<typename Spec> constexpr auto loop_break_			= Spec::loop_break;

	template<typename Spec> constexpr auto value_pred_			= Spec::value_predicate;
//	template<typename Spec> constexpr auto value_break_			= Spec::value_break;
//	template<typename Spec> constexpr auto value_func_			= Spec::value_function;

	template<typename Spec> constexpr auto act_pred_			= Spec::act_predicate;
	template<typename Spec> constexpr auto act_break_			= Spec::act_break;
	template<typename Spec> constexpr auto act_func_			= Spec::act_function;

	template<typename Spec> constexpr auto combine_func_			= Spec::combine_function;

	template<typename Spec> constexpr auto post_pred_			= Spec::post_predicate;
	template<typename Spec> constexpr auto post_func_			= Spec::post_function;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// subspecifications:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// object specs:

/***********************************************************************************************************************/

	template<typename ObjSpec> using spec_type_			= typename ObjSpec::type;

	template<typename ObjSpec> constexpr auto spec_ival_		= ObjSpec::interval;
	template<typename ObjSpec> constexpr auto spec_pred_		= ObjSpec::predicate;
	template<typename ObjSpec> constexpr auto spec_func_		= ObjSpec::function;

/***********************************************************************************************************************/

	template<typename Type, auto Interval = _na_>
	struct _object
	{
		using type						= Type;

		static constexpr auto interval				= Interval;
	};

	template<typename Type, auto Interval> using _out_obj		= _object<Type, Interval>;
	template<typename Type, auto Interval> using _in_obj		= _object<Type, Interval>;
	template<typename Type, auto Interval> using _end_obj		= _object<Type, Interval>;

/***********************************************************************************************************************/

	template<typename Type, auto Cons>
	struct _return
	{
		using type						= Type;

		static constexpr auto function				= Cons;
	};

/***********************************************************************************************************************/

	template
	<
		auto left_f		= _id_,
		typename left_attr	= cdout_attr,
		auto right_f		= _id_,
		typename right_attr	= cdend_attr,

		template
		<
			auto,
			auto, typename,
			auto, typename,
			typename

		> class cast		= one_cycle_bicast,
		auto equal_f		= equal<Type>
	>
	struct _loop_predicate
	{
		template<typename signature>
		static constexpr auto predicate = cast
		<
			equal_f,
			left_f, left_attr,
			right_f, right_attr,
			signature
		>;
	};

/***********************************************************************************************************************/

	template
	<
		auto left_f		= _id_,
		typename left_attr	= out_attr,
		auto right_f		= _id_,
		typename right_attr	= cin_attr,

		template
		<
			auto,
			auto, typename,
			auto, typename,
			typename

		> class apply		= one_cycle_biapply,
		auto equal_f		= equal<Type>
	>
	struct _act_function
	{
		template<typename signature>
		static constexpr auto predicate = apply
		<
			equal_f,
			left_f, left_attr,
			right_f, right_attr,
			signature
		>;
	};

/***********************************************************************************************************************/

	template
	<
		auto left_f		= _id_,
		typename left_attr	= in_attr,
		auto right_f		= _id_,
		typename right_attr	= cin_attr,

		template
		<
			auto,
			auto, typename,
			auto, typename,
			typename

		> class apply		= one_cycle_biapply,
		auto equal_f		= equal<Type>
	>
	struct _next_function
	{
		template<typename signature>
		static constexpr auto predicate = apply
		<
			equal_f,
			left_f, left_attr,
			right_f, right_attr,
			signature
		>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

