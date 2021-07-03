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

// one cycle map:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// spec:

private:

//	template<typename Spec>
//	static constexpr auto one_cycle_map = opt_do_chain_compose
//	<
//		precycle
//		<
//			boolean_before_loop < is_bidir_last_<Spec>    , end_prev_<Spec>   >,
//			boolean_before_loop < out_is_left_open_<Spec> , out_next_<Spec>   >,
//			boolean_before_loop < in_is_left_open_<Spec>  , in_next_<Spec>    >
//	
//		>, cycle
//		<
//			stem_before_value   < loop_pred_<Spec>     , loop_break_<Spec> >,
//			before_act          < act_func_<Spec>                          >,
//			before_next         < out_next_<Spec>                          >,
//			before_next         < in_next_<Spec>                           >
//	
//		>, postcycle
//		<
//			boolean_after_loop  < ival_meet_<Spec>     , act_func_<Spec>   >,
//			boolean_after_loop  < out_ival_meet_<Spec> , out_next_<Spec>   >,
//			boolean_after_loop  < in_ival_meet_<Spec>  , in_next_<Spec>    >,
//			boolean_after_loop  < is_bidir_last_<Spec> , end_next_<Spec>   >
//		>
//	>;

	// map:

		//     ival meet: (out is right closed) or (in is right closed) ?
		// out ival meet: (out is right open) and (in is right closed) ?
		//  in ival meet: (in is right open) and (out is right closed) ?

/***********************************************************************************************************************/

// refinement:

/*
	template<typename, typename, typename, typename> struct map_specification;

	template
	<
		typename OutType, typename OutAttr, typename OutIval, typename OutCdr,
		typename InType, typename InAttr, typename InIval,
			typename InAxis, typename InCar, typename InCdr, typename InPeek,
		typename EndType, typename EndAttr, typename EndCdr, typename EndRCdr,

		typename ActFunction
	>
	struct map_specification
	<
		_out      < OutType , OutAttr , OutIval , OutCdr                           >,
		_in       < InType  , InAttr  , InIval  , InAxis  , InCar , InCdr , InPeek >,
		_end      < EndType , EndAttr , EndCdr  , EndRCdr                          >,

		_function < ActFunction                                                    >
	>
	{
	// out:

		using out_type				= typename OutType::type;
		using out_attr				= typename OutAttr::type;

	//	using out_obj				= out_object		< out_type , out_attr		>;
	//	using dout_obj				= obj_to_direct		< out_obj			>;
	//	using cdout_obj				= obj_to_immutable	< dout_obj			>;

	//	static constexpr Interval out_ival	= OutIval::value;
	//	static constexpr auto out_cdr		= iterate<OutCdr::value, out_type>;

	// in:

	//	using in_type				= typename InType::type;
	//	using in_attr				= typename InAttr::type;

	//	using in_obj				= in_object		< in_type	, in_attr	>;
	//	using din_obj				= obj_to_direct		< in_obj			>;
	//	using cin_obj				= obj_to_immutable	< in_obj			>;
	//	using cdin_obj				= obj_to_immutable	< din_obj			>;

	//	static constexpr Interval in_ival	= InIval::value;
	//	static constexpr Axis in_axis		= InAxis::value;
	//	static constexpr auto in_car		= InCar::value;
	//	static constexpr auto in_cdr		= iterate<InCdr::value, in_type>;
	//	static constexpr auto in_peek		= iterate<InPeek::value, in_type>;

	// end:

	//	using end_type				= typename EndType::type;
	//	using end_attr				= typename EndAttr::type;

	//	using end_obj				= end_object		< end_type	, end_attr	>;
	//	using dend_obj				= obj_to_direct		< end_obj			>;
	//	using cdend_obj				= obj_to_immutable	< dend_obj			>;

	//	static constexpr auto end_cdr		= iterate<EndCdr::value, end_type>;
	//	static constexpr auto end_rcdr		= iterate<EndRCdr::value, end_type>;

	// signature:

	//	using signature				= one_cycle_signature
	//						<
	//							out_object	< obj_type<out_obj>		>,
	//							in_object	< obj_type<in_obj>		>,
	//							end_object	< obj_type<end_obj>		>
	//						>;

	// return:

	//	using return_type			= out_type;

	//	static constexpr auto
	//		return_constructor		= one_cycle_f_out<_id_, dout_obj, signature>;

	// function:

	//	static constexpr auto act_f		= ActFunction::value;

	// atomic filters:

	//	static constexpr auto value_act_f	= V_do_compose_opt<in_car, act_f>;

	//	static constexpr auto act_function	= one_cycle_assign
	//						<
	//							out_obj, value_act_f, cin_obj, signature
	//						>;
	//	static constexpr auto out_next		= one_cycle_assign
	//						<
	//							dout_obj, out_cdr, cdout_obj, signature
	//						>;
	//	static constexpr auto in_next		= one_cycle_assign
	//						<
	//							din_obj, in_cdr, cdin_obj, signature
	//						>;
	//	static constexpr auto end_next		= one_cycle_assign
	//						<
	//							dend_obj, end_cdr, cdend_obj, signature
	//						>;
	//	static constexpr auto end_previous	= one_cycle_assign
	//						<
	//							dend_obj, end_rcdr, cdend_obj, signature
	//						>;

	// composite filters:

	//	1. For each left endpoint, if open, then iterate.
	//	2. Evaluate the common (closing) loop.
	//	3. If there exists any right endpoint, which is closed, then act/combine.
	//	4. If (3), then for each right endpoint, when open, iterate.

	//	static constexpr bool ival_meet		= or_right_closed	< out_ival	, in_ival	>;
	//	static constexpr bool out_ival_meet	= right_open_and	< out_ival	, ival_meet	>;
	//	static constexpr bool in_ival_meet	= right_open_and	< in_ival	, ival_meet	>;

	//	static constexpr bool is_unidir		= V_is_unidirectional	< in_axis			>;
	//	static constexpr bool is_uni_last	= V_boolean_and		< is_unidir	, in_ival_meet	>;

	//	static constexpr bool is_bidir		= V_is_bidirectional	< in_axis			>;
	//	static constexpr bool is_bi_last	= V_boolean_and		< is_bidir	, in_ival_meet	>;

	//	static constexpr auto end_f		= V_if_then_else
	//						  < is_uni_last		, in_peek	, _id_		>;
	//	static constexpr auto loop_predicate	= one_cycle_equals
	//						<
	//							end_f, cdin_obj, cdend_obj, signature
	//						>;
	};
*/

/*
	template<typename, typename, typename, typename> struct map_specification;

	template
	<
		typename OutType, typename OutAttr, typename OutIval, typename OutCdr,
		typename InType, typename InAttr, typename InIval,
			typename InAxis, typename InCar, typename InCdr, typename InPeek,
		typename EndType, typename EndAttr, typename EndCdr, typename EndRCdr,

		typename ActFunction
	>
	struct map_specification
	<
		_out		< OutType , OutAttr , OutIval , OutCdr					>,
		_in		< InType  , InAttr  , InIval  , InAxis  , InCar , InCdr , InPeek	>,
		_end		< EndType , EndAttr , EndCdr  , EndRCdr					>,

		_function	< ActFunction								>
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

	// signature:

		using signature				= one_cycle_signature
							<
								out_object	< obj_type<out_obj>		>,
								in_object	< obj_type<in_obj>		>,
								end_object	< obj_type<end_obj>		>
							>;

	// return:

		using return_type			= out_type;

		static constexpr auto
			return_constructor		= one_cycle_f_out<_id_, dout_obj, signature>;

	// function:

		static constexpr auto act_f		= ActFunction::value;

	// atomic filters:

		static constexpr auto value_act_f	= V_do_compose_opt<in_car, act_f>;

		static constexpr auto act_function	= one_cycle_assign
							<
								out_obj, value_act_f, cin_obj, signature
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
	};
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// resolution:

/***********************************************************************************************************************/

/*
	template
	<
		typename Type,
		auto map_function,

		auto OutIval		= Interval::closing,
		auto OutDir		= Direction::forward,

		auto InIval		= Interval::closing,
		auto InDir		= Direction::forward,
		auto InRDir		= Direction::backward,
		auto InAxis		= Axis::bidirectional
	>
	using map_spec			= map_specification
	<
		_out
		<
			_type		< Type*		>,
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

		_function
		<
			_act_f		< map_function	>
		>
	>;
*/

/***********************************************************************************************************************/

/*
	template
	<
		typename Type,
		auto map_function,

		auto OutIval		= Interval::closing,
		auto OutDir		= Direction::forward,

		auto InIval		= Interval::closing,
		auto InDir		= Direction::forward,
		auto InRDir		= Direction::backward
	>
	using range_map_spec		= map_specification
	<
		_out
		<
			_type		< Type*			>,
			_attr		< rw_iterator		>,
			_ival		< OutIval		>,
			_next		< OutDir		>
		>,

		_in
		<
			_type		< Type			>,
			_attr		< rw_range		>,
			_ival		< InIval		>,
			_axis		< Axis::bidirectional	>,
			_value		< _id_			>,
			_next		< InDir			>,
			_peek		< InDir			>
		>,

		_end
		<
			_type		< Type			>,
			_attr		< rw_range		>,
			_next		< InDir			>,
			_prev		< InRDir		>
		>,

		_function
		<
			_act_f		< map_function		>
		>
	>;
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
private:

	template
	<
		typename DOutType, typename IOutType,
		typename InType, typename EndType,

		auto function,

		auto dout		= dout<DOutType, InType, EndType>	,
		auto iout		= iout<DOutType, InType, EndType>	,
		auto in			= din<DOutType, InType, EndType>	,
		auto end		= dend<DOutType, InType, EndType>	,

		auto is_equal		= equal<InType, EndType>		,
		auto halt		= _id_					,
		auto out_increment	= add_by<DOutType, 1>			,
		auto in_increment	= add_by<InType, 1>
	>
	static constexpr auto U_map = chain_endopose
	<
		stem
		<
			test   < is_equal , in            , end  >,

			halt,
			assign < iout     , function      , in   >
		>,

		chain_lift
		<
			assign < dout     , out_increment , dout >,
			assign < in       , in_increment  , in   >
		>
	>;

public:

	template<auto f, typename OutType, typename InType, typename EndType>
	static constexpr OutType make_range(OutType out, InType in, EndType end)
	{
		using IOutType	= decltype(*out);
		using signature	= one_cycle<OutType, InType, EndType>;
		auto s		= signature(out, in, end);
		auto result	= dout<OutType, InType, EndType>;
		auto map	= close_cycle<U_map<OutType, IOutType, InType, EndType, f>, signature>;

		return result(map(s));
	}
*/

