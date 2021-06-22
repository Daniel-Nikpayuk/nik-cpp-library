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

// one cycle find:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// find first:

/***********************************************************************************************************************/

// spec:

private:

	template<typename Spec>
	return_type_<Spec> find_first(in_type_<Spec> i, in_type_<Spec> e)
	{
		constexpr auto find_first_f = cycle_inductor
		<
			precycle
			<
				signature_<Spec>,

				interval_before_loop	< in_ival_<Spec>	, in_next_<Spec>	>

			>, cycle
			<
				signature_<Spec>,

				stem_before_value	< loop_pred_<Spec>	, loop_break_<Spec>	>,
				stem_before_act		< act_pred_<Spec>	, act_break_<Spec>	>,
				before_next		< in_next_<Spec>				>

			>, postcycle
			<
				signature_<Spec>,

				costem_after_loop	< post_pred_<Spec>	, _id_			>,
				interval_after_loop	< in_ival_<Spec>	, post_func_<Spec>	>
			>
		>;

		signature_<Spec> s(e, i, e);

		return return_cons_<Spec>(find_first_f(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<typename, typename, typename, typename, typename> struct find_first_specification;

/*
	template
	<
		typename OutType, typename OutAttr,
		typename InType, typename InAttr, typename InIval, typename InCar, typename InCdr,
		typename EndType, typename EndAttr,
		typename MsgType, typename MsgAttr,

		typename ActPredicate
	>
	struct find_first_specification
	<
		_out		< OutType , OutAttr				>,
		_in		< InType  , InAttr  , InIval  , InCar , InCdr	>,
		_end		< EndType , EndAttr				>,
		_msg		< MsgType , MsgAttr				>,

		_function	< ActPredicate					>
	>
	{
	// out:

		using out_type				= typename OutType::type;
		using out_attr				= typename OutAttr::type;

		using out_obj				= out_object		< out_type , out_attr		>;
		using dout_obj				= obj_to_direct		< out_obj			>;

	// in:

		using in_type				= typename InType::type;
		using in_attr				= typename InAttr::type;

		using in_obj				= in_object		< in_type	, in_attr	>;
		using din_obj				= obj_to_direct		< in_obj			>;
		using cin_obj				= obj_to_immutable	< in_obj			>;
		using cdin_obj				= obj_to_immutable	< din_obj			>;

		static constexpr Interval in_ival	= InIval::value;
		static constexpr auto in_car		= InCar::value;
		static constexpr auto in_cdr		= iterate<InCdr::value, in_type>;

	// end:

		using end_type				= typename EndType::type;
		using end_attr				= typename EndAttr::type;

		using end_obj				= end_object		< end_type	, end_attr	>;
		using dend_obj				= obj_to_direct		< end_obj			>;
		using cdend_obj				= obj_to_immutable	< dend_obj			>;

	// msg:

		using msg_type				= typename MsgType::type;
		using msg_attr				= typename MsgAttr::type;

		using msg_obj				= msg_object		< msg_type	, msg_attr	>;
		using dmsg_obj				= obj_to_direct		< msg_obj			>;
		using vmsg_obj				= obj_to_void_type	< msg_obj			>;
		using cdmsg_obj				= obj_to_immutable	< dmsg_obj			>;

	// signature:

		using signature				= one_cycle_signature
							<
								out_object	< obj_type<out_obj>		>,
								in_object	< obj_type<in_obj>		>,
								end_object	< obj_type<end_obj>		>,
								msg_object	< obj_type<msg_obj>		>
							>;

	// pair:

		using car_obj				= car_object		< out_type			>;
		using cdr_obj				= cdr_object		< msg_type			>;

		using pair_type				= pair_signature	< car_obj	, cdr_obj	>;

		static constexpr auto p_cons		= pair_cons<car_obj, cdr_obj>;

	// return:

		using return_type			= pair_type;

		static constexpr auto at_out		= one_cycle_f_out<_id_, dout_obj, signature>;
		static constexpr auto at_msg		= one_cycle_f_msg<_id_, dmsg_obj, signature>;
		static constexpr auto
			return_constructor		= sign_bicast<p_cons, at_out, at_msg, signature>;

	// function:

		static constexpr auto act_p		= ActPredicate::value;

	// atomic filters:

		static constexpr auto value_act_p	= V_do_compose_opt<in_car, act_p>;

		static constexpr auto loop_predicate	= one_cycle_equals
							<
								_id_, cdin_obj, cdend_obj, signature
							>;
		static constexpr auto loop_break	= one_cycle_assign
							<
								dmsg_obj, br_before_value, vmsg_obj, signature
							>;
		static constexpr auto act_predicate	= one_cycle_match
							<
								value_act_p, cin_obj, signature
							>;
		static constexpr auto act_break1	= one_cycle_assign
							<
								dout_obj, _id_, cdin_obj, signature
							>;
		static constexpr auto act_break2	= one_cycle_assign
							<
								dmsg_obj, br_before_act, vmsg_obj, signature
							>;
		static constexpr auto act_break		= V_do_compose_opt<act_break1, act_break2>;
		static constexpr auto in_next		= one_cycle_assign
							<
								din_obj, in_cdr, cdin_obj, signature
							>;

	// composite filters:

		// A post match only makes sense
		// when no loop match is found.

		static constexpr auto post_predicate	= one_cycle_match
							<
								is_before_value, cdmsg_obj, signature
							>;
		static constexpr auto post_function	= postcycle
							<
								signature,

								stem_after_loop < act_predicate , act_break >
							>;
	};
*/

/***********************************************************************************************************************/

/*
	template
	<
		typename Type,
		auto find_function,

		auto Ival		= Interval::closing,
		auto Dir		= Direction::forward
	>
	using find_first_spec		= find_first_specification
	<
		_out
		<
			_type		< Type*		>,
			_attr		< rw_constant	>
		>,

		_in
		<
			_type		< Type*		>,
			_attr		< rw_iterator	>,
			_ival		< Ival		>,
			_value		< _id_		>,
			_next		< Dir		>
		>,

		_end
		<
			_type		< Type*		>,
			_attr		< rw_iterator	>
		>,

		_msg
		<
			_type		< Break		>,
			_attr		< rw_constant	>
		>,

		_function
		<
			_act_p		< find_function	>
		>
	>;
*/

/***********************************************************************************************************************/

/*
	template
	<
		typename Type,
		auto find_function,

		auto Ival		= Interval::closing,
		auto Dir		= Direction::forward
	>
	using range_find_first_spec	= find_first_specification
	<
		_out
		<
			_type		< Type		>,
			_attr		< rw_constant	>
		>,

		_in
		<
			_type		< Type		>,
			_attr		< rw_range	>,
			_ival		< Ival		>,
			_value		< _id_		>,
			_next		< Dir		>
		>,

		_end
		<
			_type		< Type		>,
			_attr		< rw_range	>
		>,

		_msg
		<
			_type		< Break		>,
			_attr		< rw_constant	>
		>,

		_function
		<
			_act_p		< find_function	>
		>
	>;
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// find all:

/***********************************************************************************************************************/

// spec:

private:

	template<typename Spec>
	return_type_<Spec> find_all(out_type_<Spec> o, in_type_<Spec> i, end_type_<Spec> e)
	{
		constexpr auto find_all_f = cycle_inductor
		<
			precycle
			<
				signature_<Spec>,

				boolean_before_loop	< is_bi_last_<Spec>	, end_prev_<Spec>	>,

				interval_before_loop	< out_ival_<Spec>	, out_next_<Spec>	>,
				interval_before_loop	< in_ival_<Spec>	, in_next_<Spec>	>

			>, cycle
			<
				signature_<Spec>,

				stem_before_value	< loop_pred_<Spec>	, _id_			>,
				before_value		< value_pred_<Spec>				>,
				distem_before_act	< act_pred_<Spec>	, act_func_<Spec>	>,
				distem_before_next	< act_pred_<Spec>	, out_next_<Spec>	>,
				before_next		< in_next_<Spec>				>

			>, postcycle
			<
				signature_<Spec>,

				boolean_after_loop	< ival_meet_<Spec>	, post_func_<Spec>	>,
				boolean_after_loop	< out_ival_meet_<Spec>	, out_next_<Spec>	>,
				boolean_after_loop	< in_ival_meet_<Spec>	, in_next_<Spec>	>,

				boolean_after_loop	< is_bi_last_<Spec>	, end_next_<Spec>	>
			>
		>;

		signature_<Spec> s(o, i, e, false);

		return return_cons_<Spec>(find_all_f(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	template<typename, typename, typename, typename, typename> struct find_all_specification;

	template
	<
		typename OutType, typename OutAttr, typename OutIval, typename OutCdr,
		typename InType, typename InAttr, typename InIval,
			typename InAxis, typename InCar, typename InCdr, typename InPeek,
		typename EndType, typename EndAttr, typename EndCdr, typename EndRCdr,
		typename AuxType, typename AuxAttr,

		typename ValuePredicate
	>
	struct find_all_specification
	<
		_out		< OutType , OutAttr , OutIval , OutCdr					>,
		_in		< InType  , InAttr  , InIval  , InAxis  , InCar , InCdr , InPeek	>,
		_end		< EndType , EndAttr , EndCdr  , EndRCdr					>,
		_aux		< AuxType , AuxAttr							>,

		_function	< ValuePredicate							>
	>
	{
	// out:

		using out_type				= typename OutType::type;
		using out_attr				= typename OutAttr::type;

		using out_obj				= out_object		< out_type , out_attr		>;
		using dout_obj				= obj_to_direct		< out_obj			>;
		using cdout_obj				= obj_to_immutable	< dout_obj			>;

		static constexpr Interval out_ival	= OutIval::value;
		static constexpr auto out_cdr		= iterate<OutCdr::value, out_type>;

	// in:

		using in_type				= typename InType::type;
		using in_attr				= typename InAttr::type;

		using in_obj				= in_object		< in_type	, in_attr	>;
		using din_obj				= obj_to_direct		< in_obj			>;
		using cin_obj				= obj_to_immutable	< in_obj			>;
		using cdin_obj				= obj_to_immutable	< din_obj			>;

		static constexpr Interval in_ival	= InIval::value;
		static constexpr Axis in_axis		= InAxis::value;
		static constexpr auto in_car		= InCar::value;
		static constexpr auto in_cdr		= iterate<InCdr::value, in_type>;
		static constexpr auto in_peek		= iterate<InPeek::value, in_type>;

	// end:

		using end_type				= typename EndType::type;
		using end_attr				= typename EndAttr::type;

		using end_obj				= end_object		< end_type	, end_attr	>;
		using dend_obj				= obj_to_direct		< end_obj			>;
		using cdend_obj				= obj_to_immutable	< dend_obj			>;

		static constexpr auto end_cdr		= iterate<EndCdr::value, end_type>;
		static constexpr auto end_rcdr		= iterate<EndRCdr::value, end_type>;

	// aux:

		using aux_type				= typename AuxType::type;
		using aux_attr				= typename AuxAttr::type;

		using aux_obj				= aux_object		< aux_type	, aux_attr	>;
		using caux_obj				= obj_to_immutable	< aux_obj			>;

	// signature:

		using signature				= one_cycle_signature
							<
								out_object	< obj_type<out_obj>		>,
								in_object	< obj_type<in_obj>		>,
								end_object	< obj_type<end_obj>		>,
								aux_object	< obj_type<aux_obj>		>
							>;

	// return:

		using return_type			= out_type;

		static constexpr auto
			return_constructor		= one_cycle_f_out<_id_, dout_obj, signature>;

	// function:

		static constexpr auto value_p		= ValuePredicate::value;

	// atomic filters:

		static constexpr auto value_act_p	= V_do_compose_opt<in_car, value_p>;

		static constexpr auto value_predicate	= one_cycle_assign
							<
								aux_obj, value_act_p, cin_obj, signature
							>;
		static constexpr auto act_predicate	= one_cycle_match
							<
								_id_, caux_obj, signature
							>;
		static constexpr auto act_function	= one_cycle_assign
							<
								out_obj, _id_, cdin_obj, signature
							>;
		static constexpr auto out_next		= one_cycle_assign
							<
								dout_obj, out_cdr, cdout_obj, signature
							>;
		static constexpr auto in_next		= one_cycle_assign
							<
								din_obj, in_cdr, cdin_obj, signature
							>;
		static constexpr auto end_next		= one_cycle_assign
							<
								dend_obj, end_cdr, cdend_obj, signature
							>;
		static constexpr auto end_previous	= one_cycle_assign
							<
								dend_obj, end_rcdr, cdend_obj, signature
							>;

	// composite filters:

	//	1. For each left endpoint, if open, then iterate.
	//	2. Evaluate the common (closing) loop.
	//	3. If there exists any right endpoint, which is closed, then act/combine.
	//	4. If (3), then for each right endpoint, when open, iterate.

		static constexpr bool ival_meet		= or_right_closed	< out_ival	, in_ival	>;
		static constexpr bool out_ival_meet	= right_open_and	< out_ival	, ival_meet	>;
		static constexpr bool in_ival_meet	= right_open_and	< in_ival	, ival_meet	>;

		static constexpr bool is_unidir		= V_is_unidirectional	< in_axis			>;
		static constexpr bool is_uni_last	= V_boolean_and		< is_unidir	, in_ival_meet	>;

		static constexpr bool is_bidir		= V_is_bidirectional	< in_axis			>;
		static constexpr bool is_bi_last	= V_boolean_and		< is_bidir	, in_ival_meet	>;

		static constexpr auto end_f		= V_if_then_else
							  < is_uni_last		, in_peek	, _id_		>;
		static constexpr auto loop_predicate	= one_cycle_equals
							<
								end_f, cdin_obj, cdend_obj, signature
							>;

		//

		static constexpr auto post_function	= postcycle
							<
								signature,

								stem_after_loop < act_predicate , act_function >
							>;
	};
*/

/***********************************************************************************************************************/

/*
	template
	<
		typename Type,
		auto find_function,

		auto OutIval		= Interval::closing,
		auto OutDir		= Direction::forward,

		auto InIval		= Interval::closing,
		auto InDir		= Direction::forward,
		auto InRDir		= Direction::backward,
		auto InAxis		= Axis::bidirectional
	>
	using find_all_spec		= find_all_specification
	<
		_out
		<
			_type		< Type**	>,
			_attr		< rw_iterator	>,
			_ival		< OutIval	>,
			_next		< OutDir	>
		>,

		_in
		<
			_type		< Type*		>,
			_attr		< rw_iterator	>,
			_ival		< InIval	>,
			_axis		< InAxis	>,
			_value		< _id_		>,
			_next		< InDir		>,
			_peek		< InDir		>
		>,

		_end
		<
			_type		< Type*		>,
			_attr		< rw_iterator	>,
			_next		< InDir		>,
			_prev		< InRDir	>
		>,

		_aux
		<
			_type		< bool		>,
			_attr		< rw_constant	>
		>,

		_function
		<
			_value_p	< find_function	>
		>
	>;
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

