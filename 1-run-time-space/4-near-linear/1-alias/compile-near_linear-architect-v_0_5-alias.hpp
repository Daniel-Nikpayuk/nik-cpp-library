/************************************************************************************************************************
**
** Copyright 2021-2022 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

// near linear alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// objects:

/***********************************************************************************************************************/

// members:

	using nik_name(NIK_PREFIX, OneCycleMember)			= typename NIK_MODULE::OneCycleMember;

	template<auto m>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_out)			= NIK_MODULE::template V_is_out<m>;

	template<auto m>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_in)			= NIK_MODULE::template V_is_in<m>;

	template<auto m>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_car_in)		= NIK_MODULE::template V_is_car_in<m>;

	template<auto m>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_cdr_in)		= NIK_MODULE::template V_is_cdr_in<m>;

	template<auto m>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_end)			= NIK_MODULE::template V_is_end<m>;

	template<auto m>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_aux)			= NIK_MODULE::template V_is_aux<m>;

	template<auto m>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_msg)			= NIK_MODULE::template V_is_msg<m>;

// kinds:

	template<typename T>
	using nik_name(NIK_PREFIX, _out_object)			= typename NIK_MODULE::template _out_object<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, _in_object)			= typename NIK_MODULE::template _in_object<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, _car_in_object)		= typename NIK_MODULE::template _car_in_object<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, _cdr_in_object)		= typename NIK_MODULE::template _cdr_in_object<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, _end_object)			= typename NIK_MODULE::template _end_object<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, _aux_object)			= typename NIK_MODULE::template _aux_object<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, _msg_object)			= typename NIK_MODULE::template _msg_object<T>;

/***********************************************************************************************************************/

// interval:

	using nik_name(NIK_PREFIX, Interval)				= typename NIK_MODULE::Interval;

	//

	template<Interval interval>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_open)			= NIK_MODULE::template V_is_open<interval>;

	template<Interval interval>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_closing)		= NIK_MODULE::template V_is_closing<interval>;

	template<Interval interval>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_closed)		= NIK_MODULE::template V_is_closed<interval>;

	template<Interval interval>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_opening)		= NIK_MODULE::template V_is_opening<interval>;

	//

	template<Interval interval>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_left_open)		= NIK_MODULE::template V_is_left_open<interval>;

	template<Interval interval>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_left_closed)		= NIK_MODULE::template V_is_left_closed<interval>;

	template<Interval interval>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_right_open)		= NIK_MODULE::template V_is_right_open<interval>;

	template<Interval interval>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_right_closed)		= NIK_MODULE::template V_is_right_closed<interval>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// direction:

/***********************************************************************************************************************/

	using nik_name(NIK_PREFIX, Direction)				= typename NIK_MODULE::Direction;

	// is required to accept external input.

	template<auto direction>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_forward)		= NIK_MODULE::template V_is_forward<direction>;

	template<auto direction>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_backward)		= NIK_MODULE::template V_is_backward<direction>;

/***********************************************************************************************************************/

// iterate:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// axis:

/***********************************************************************************************************************/

	using nik_name(NIK_PREFIX, Axis)				= typename NIK_MODULE::Axis;

	//

	template<Axis axis>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_unidirectional)	= NIK_MODULE::template V_is_unidirectional<axis>;

	template<Axis axis>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_bidirectional)	= NIK_MODULE::template V_is_bidirectional<axis>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// loop interval functions:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// unary:

	// before:

	template<bool p, auto n>
	NIK_POLICY auto nik_name(NIK_PREFIX, boolean_before_loop)	= NIK_MODULE::template boolean_before_loop<p, n>;

	template<Interval i, auto n>
	NIK_POLICY auto nik_name(NIK_PREFIX, interval_before_loop)	= NIK_MODULE::template interval_before_loop<i, n>;

	// after:

	template<bool p, auto ac>
	NIK_POLICY auto nik_name(NIK_PREFIX, boolean_after_loop)	= NIK_MODULE::template boolean_after_loop<p, ac>;

	template<Interval i, auto ac>
	NIK_POLICY auto nik_name(NIK_PREFIX, interval_after_loop)	= NIK_MODULE::template interval_after_loop<i, ac>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// binary:

	template<Interval iv1, Interval iv2>
	NIK_POLICY auto nik_name(NIK_PREFIX, or_right_closed)		= NIK_MODULE::template or_right_closed<iv1, iv2>;

	template<Interval iv, bool m>
	NIK_POLICY auto nik_name(NIK_PREFIX, right_open_and)		= NIK_MODULE::template right_open_and<iv, m>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// trinary:

	template<Interval iv, bool m>
	NIK_POLICY auto nik_name(NIK_PREFIX, right_closed_or)		= NIK_MODULE::template right_closed_or<iv, m>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// list inductor specs:

/***********************************************************************************************************************/

// root:

	template<auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, before_loop)		= NIK_MODULE::template before_loop<N>;

	//

	template<auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, before_value)		= NIK_MODULE::template before_value<N>;

	template<auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, after_value)		= NIK_MODULE::template after_value<N>;

	template<auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, before_act)		= NIK_MODULE::template before_act<N>;

	template<auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, after_act)			= NIK_MODULE::template after_act<N>;

	template<auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, before_combine)		= NIK_MODULE::template before_combine<N>;

	template<auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, after_combine)		= NIK_MODULE::template after_combine<N>;

	template<auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, before_next)		= NIK_MODULE::template before_next<N>;

	template<auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, after_next)		= NIK_MODULE::template after_next<N>;

	//

	template<auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, after_loop)		= NIK_MODULE::template after_loop<N>;

/***********************************************************************************************************************/

// stem:

	template<auto P, auto B, auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, stem_before_loop)		= NIK_MODULE::template stem_before_loop
									<
										P, B, N
									>;

	//

	template<auto P, auto B, auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, stem_before_value)		= NIK_MODULE::template stem_before_value
									<
										P, B, N
									>;

	template<auto P, auto B, auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, stem_after_value)		= NIK_MODULE::template stem_after_value
									<
										P, B, N
									>;

	template<auto P, auto B, auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, stem_before_act)		= NIK_MODULE::template stem_before_act
									<
										P, B, N
									>;

	template<auto P, auto B, auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, stem_after_act)		= NIK_MODULE::template stem_after_act
									<
										P, B, N
									>;

	template<auto P, auto B, auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, stem_before_combine)	= NIK_MODULE::template stem_before_combine
									<
										P, B, N
									>;

	template<auto P, auto B, auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, stem_after_combine)	= NIK_MODULE::template stem_after_combine
									<
										P, B, N
									>;

	template<auto P, auto B, auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, stem_before_next)		= NIK_MODULE::template stem_before_next
									<
										P, B, N
									>;

	template<auto P, auto B, auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, stem_after_next)		= NIK_MODULE::template stem_after_next
									<
										P, B, N
									>;

	//

	template<auto P, auto B, auto N = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, stem_after_loop)		= NIK_MODULE::template stem_after_loop
									<
										P, B, N
									>;

/***********************************************************************************************************************/

// costem:

	template<auto P, auto N, auto B = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, costem_before_loop)	= NIK_MODULE::template costem_before_loop
									<
										P, N, B
									>;

	//

	template<auto P, auto N, auto B = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, costem_before_value)	= NIK_MODULE::template costem_before_value
									<
										P, N, B
									>;

	template<auto P, auto N, auto B = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, costem_after_value)	= NIK_MODULE::template costem_after_value
									<
										P, N, B
									>;

	template<auto P, auto N, auto B = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, costem_before_act)		= NIK_MODULE::template costem_before_act
									<
										P, N, B
									>;

	template<auto P, auto N, auto B = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, costem_after_act)		= NIK_MODULE::template costem_after_act
									<
										P, N, B
									>;

	template<auto P, auto N, auto B = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, costem_before_combine)	= NIK_MODULE::template costem_before_combine
									<
										P, N, B
									>;

	template<auto P, auto N, auto B = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, costem_after_combine)	= NIK_MODULE::template costem_after_combine
									<
										P, N, B
									>;

	template<auto P, auto N, auto B = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, costem_before_next)	= NIK_MODULE::template costem_before_next
									<
										P, N, B
									>;

	template<auto P, auto N, auto B = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, costem_after_next)		= NIK_MODULE::template costem_after_next
									<
										P, N, B
									>;

	//

	template<auto P, auto N, auto B = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, costem_after_loop)		= NIK_MODULE::template costem_after_loop
									<
										P, N, B
									>;

/***********************************************************************************************************************/

// distem:

	template<auto P, auto N1, auto N2 = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, distem_before_loop)	= NIK_MODULE::template distem_before_loop
									<
										P, N1, N2
									>;

	//

	template<auto P, auto N1, auto N2 = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, distem_before_value)	= NIK_MODULE::template distem_before_value
									<
										P, N1, N2
									>;

	template<auto P, auto N1, auto N2 = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, distem_after_value)	= NIK_MODULE::template distem_after_value
									<
										P, N1, N2
									>;

	template<auto P, auto N1, auto N2 = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, distem_before_act)		= NIK_MODULE::template distem_before_act
									<
										P, N1, N2
									>;

	template<auto P, auto N1, auto N2 = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, distem_after_act)		= NIK_MODULE::template distem_after_act
									<
										P, N1, N2
									>;

	template<auto P, auto N1, auto N2 = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, distem_before_combine)	= NIK_MODULE::template distem_before_combine
									<
										P, N1, N2
									>;

	template<auto P, auto N1, auto N2 = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, distem_after_combine)	= NIK_MODULE::template distem_after_combine
									<
										P, N1, N2
									>;

	template<auto P, auto N1, auto N2 = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, distem_before_next)	= NIK_MODULE::template distem_before_next
									<
										P, N1, N2
									>;

	template<auto P, auto N1, auto N2 = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, distem_after_next)		= NIK_MODULE::template distem_after_next
									<
										P, N1, N2
									>;

	//

	template<auto P, auto N1, auto N2 = NIK_COMPOSE::_id_>
	NIK_POLICY auto nik_name(NIK_PREFIX, distem_after_loop)		= NIK_MODULE::template distem_after_loop
									<
										P, N1, N2
									>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// list operator specs:

/***********************************************************************************************************************/

// out:

	template<typename Spec>
	using nik_name(NIK_PREFIX, out_type_)				= typename NIK_MODULE::template out_type_<Spec>;

	//

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, out_ival_)			= NIK_MODULE::template out_ival_<Spec>;

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, out_ival_meet_)		= NIK_MODULE::template out_ival_meet_<Spec>;

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, out_next_)			= NIK_MODULE::template out_next_<Spec>;

/***********************************************************************************************************************/

// in:

	template<typename Spec>
	using nik_name(NIK_PREFIX, in_type_)				= typename NIK_MODULE::template in_type_<Spec>;

	//

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, in_ival_)			= NIK_MODULE::template in_ival_<Spec>;

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, in_ival_meet_)		= NIK_MODULE::template in_ival_meet_<Spec>;

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, in_next_)			= NIK_MODULE::template in_next_<Spec>;

/***********************************************************************************************************************/

// car in:

	template<typename Spec>
	using nik_name(NIK_PREFIX, car_in_type_)			= typename NIK_MODULE::template car_in_type_<Spec>;

	//

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, car_in_ival_)		= NIK_MODULE::template car_in_ival_<Spec>;

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, car_in_ival_meet_)		= NIK_MODULE::template car_in_ival_meet_<Spec>;

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, car_in_next_)		= NIK_MODULE::template car_in_next_<Spec>;

/***********************************************************************************************************************/

// cdr in:

	template<typename Spec>
	using nik_name(NIK_PREFIX, cdr_in_type_)			= typename NIK_MODULE::template cdr_in_type_<Spec>;

	//

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, cdr_in_ival_)		= NIK_MODULE::template cdr_in_ival_<Spec>;

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, cdr_in_ival_meet_)		= NIK_MODULE::template cdr_in_ival_meet_<Spec>;

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, cdr_in_next_)		= NIK_MODULE::template cdr_in_next_<Spec>;

/***********************************************************************************************************************/

// end:

	template<typename Spec>
	using nik_name(NIK_PREFIX, end_type_)				= typename NIK_MODULE::template end_type_<Spec>;

	//

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, end_next_)			= NIK_MODULE::template end_next_<Spec>;

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, end_prev_)			= NIK_MODULE::template end_prev_<Spec>;

/***********************************************************************************************************************/

// aux:

//	template<typename Spec>
//	using nik_name(NIK_PREFIX, aux_type_)				= typename NIK_MODULE::template aux_type_<Spec>;

/***********************************************************************************************************************/

// msg:

//	template<typename Spec>
//	using nik_name(NIK_PREFIX, msg_type_)				= typename NIK_MODULE::template msg_type_<Spec>;

/***********************************************************************************************************************/

// signature:

	template<typename Spec>
	using nik_name(NIK_PREFIX, signature_)				= typename NIK_MODULE::template signature_<Spec>;

/***********************************************************************************************************************/

// return:

	template<typename Spec>
	using nik_name(NIK_PREFIX, return_type_)			= typename NIK_MODULE::template return_type_<Spec>;

	//

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, return_value_)		= NIK_MODULE::template return_value_<Spec>;

/***********************************************************************************************************************/

// predicate:

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, ival_meet_)		= NIK_MODULE::template ival_meet_<Spec>;

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_bi_last_)		= NIK_MODULE::template is_bi_last_<Spec>;

/***********************************************************************************************************************/

// function:

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, loop_pred_)		= NIK_MODULE::template loop_pred_<Spec>;

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, loop_break_)		= NIK_MODULE::template loop_break_<Spec>;

	//

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, value_pred_)		= NIK_MODULE::template value_pred_<Spec>;

//	template<typename Spec>
//	NIK_POLICY auto nik_name(NIK_PREFIX, value_break_)		= NIK_MODULE::template value_break_<Spec>;

//	template<typename Spec>
//	NIK_POLICY auto nik_name(NIK_PREFIX, value_func_)		= NIK_MODULE::template value_func_<Spec>;

	//

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, act_pred_)			= NIK_MODULE::template act_pred_<Spec>;

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, act_break_)		= NIK_MODULE::template act_break_<Spec>;

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, act_func_)			= NIK_MODULE::template act_func_<Spec>;

	//

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, combine_func_)		= NIK_MODULE::template combine_func_<Spec>;

	//

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, post_pred_)		= NIK_MODULE::template post_pred_<Spec>;

	template<typename Spec>
	NIK_POLICY auto nik_name(NIK_PREFIX, post_func_)		= NIK_MODULE::template post_func_<Spec>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// subspecifications:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// object specs:

/***********************************************************************************************************************/

/*
	template<typename ObjSpec>
	using nik_name(NIK_PREFIX, spec_type_)				= typename NIK_MODULE::template spec_type_<Spec>;

	template<typename ObjSpec>
	NIK_POLICY auto nik_name(NIK_PREFIX, spec_ival_)		= NIK_MODULE::template spec_ival_<Spec>;

	template<typename ObjSpec>
	NIK_POLICY auto nik_name(NIK_PREFIX, spec_pred_)		= NIK_MODULE::template spec_pred_<Spec>;

	template<typename ObjSpec>
	NIK_POLICY auto nik_name(NIK_PREFIX, spec_func_)		= NIK_MODULE::template spec_func_<Spec>;
*/

/***********************************************************************************************************************/

/*
	template<typename Type, auto Interval = _na_>
	struct _object

	template<typename Type, auto Interval>
	using nik_name(NIK_PREFIX, _out_obj)				= typename NIK_MODULE::template _out_obj<Spec>;

	template<typename Type, auto Interval>
	using nik_name(NIK_PREFIX, _in_obj)				= typename NIK_MODULE::template _in_obj<Spec>;

	template<typename Type, auto Interval>
	using nik_name(NIK_PREFIX, _end_obj)				= typename NIK_MODULE::template _end_obj<Spec>;
*/

/***********************************************************************************************************************/

/*
	template<typename Type, auto Cons>
	struct _return
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// break (messages):

/***********************************************************************************************************************/

	using nik_name(NIK_PREFIX, Break)				= typename NIK_MODULE::Break;

	// predicates:

	NIK_POLICY auto nik_name(NIK_PREFIX, is_before_value)		= NIK_MODULE::is_before_value;
	NIK_POLICY auto nik_name(NIK_PREFIX, is_after_value)		= NIK_MODULE::is_after_value;

	NIK_POLICY auto nik_name(NIK_PREFIX, is_before_act)		= NIK_MODULE::is_before_act;
	NIK_POLICY auto nik_name(NIK_PREFIX, is_after_act)		= NIK_MODULE::is_after_act;

	NIK_POLICY auto nik_name(NIK_PREFIX, is_before_combine)		= NIK_MODULE::is_before_combine;
	NIK_POLICY auto nik_name(NIK_PREFIX, is_after_combine)		= NIK_MODULE::is_after_combine;

	NIK_POLICY auto nik_name(NIK_PREFIX, is_before_next)		= NIK_MODULE::is_before_next;
	NIK_POLICY auto nik_name(NIK_PREFIX, is_after_next)		= NIK_MODULE::is_after_next;

	// constants:

	NIK_POLICY auto nik_name(NIK_PREFIX, br_before_value)		= NIK_MODULE::br_before_value;
	NIK_POLICY auto nik_name(NIK_PREFIX, br_after_value)		= NIK_MODULE::br_after_value;

	NIK_POLICY auto nik_name(NIK_PREFIX, br_before_act)		= NIK_MODULE::br_before_act;
	NIK_POLICY auto nik_name(NIK_PREFIX, br_after_act)		= NIK_MODULE::br_after_act;

	NIK_POLICY auto nik_name(NIK_PREFIX, br_before_combine)		= NIK_MODULE::br_before_combine;
	NIK_POLICY auto nik_name(NIK_PREFIX, br_after_combine)		= NIK_MODULE::br_after_combine;

	NIK_POLICY auto nik_name(NIK_PREFIX, br_before_next)		= NIK_MODULE::br_before_next;
	NIK_POLICY auto nik_name(NIK_PREFIX, br_after_next)		= NIK_MODULE::br_after_next;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

