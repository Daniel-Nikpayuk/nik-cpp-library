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

// map source:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

//	template<>
//	static constexpr auto make_assign()
//	{
//		return assign<>;
//	}

// spec:

	template<typename, typename, typename, typename> class map_specification;

	template
	<
		typename OutType  , typename OutIval   , typename OutNext ,
		typename InType   , typename InIval    , typename InVal   ,
		                    typename InNext    , typename InAxis  ,
		                    typename InPeek    ,
		typename EndType  , typename EndNext   , typename EndPrev ,

		typename LoopTest , typename LoopBreak , typename MapAsgn
	>
	class map_specification
	<
		_out  < OutType  , OutIval   , OutNext                            >,
		_in   < InType   , InIval    , InVal   , InNext , InAxis , InPeek >,
		_end  < EndType  , EndNext   , EndPrev                            >,

		_algo < LoopTest , LoopBreak , MapAsgn                            >
	>
	{
		public:

			using out_type					= typename OutType::type;
			using in_type					= typename InType::type;
			using end_type					= typename EndType::type;
			using return_type				= out_type;

			using signature					= nik_signature_signature
									<
										out_type ,
										in_type  ,
										end_type
									>;

		public:

		//	static constexpr auto out_next			= make_assign
		//							<
		//								OutNext::ufunction,
		//								OutNext::member,
		//								signature

		//							>(OutNext::uarguments);
		//	static constexpr bool is_out_next_before	= _out_is_left_open;
		//	static constexpr bool is_out_next_after		= _out_is_right_open && _in_is_right_closed;

		//	//

		//	static constexpr auto in_next			= assign
		//							<
		//								_in_next_l, _in_next, _in_next_r
		//							>;
		//	static constexpr bool is_in_next_before		= _in_is_left_open;
		//	static constexpr bool is_in_next_after		= _in_is_right_open && _out_is_right_closed;

		//	//

		//	static constexpr auto end_next			= assign
		//							<
		//								_end_next_l, _end_next, _end_next_r
		//							>;
		//	static constexpr bool is_end_next_after		= _is_bidirectional && _is_last;

		//	static constexpr auto end_prevous		= assign
		//							<
		//								_end_prev_l, _end_prev, _end_prev_r
		//							>;
		//	static constexpr bool is_end_previous_before	= _is_bidirectional && _is_last;

		//	//

		//	static constexpr auto loop_predicate		= test // is unidir_last ?
		//							<
		//								_is_equal, is_equal_r1, _is_equal_r2
		//							>;
		//	static constexpr auto loop_break		= LoopBreak::function;

		//	//

		//	static constexpr auto act_function		= assign
		//							<
		//								_map_func_l, _map_func, _map_func_r
		//							>;
		//	static constexpr bool is_act_function_after	= _out_is_right_closed || _in_is_right_closed;

		//	//

		//	static constexpr auto return_value		= _out_next_l;

		private:

		//	using out_next_args				= typename OutNext::arguments;
		//	using in_next_args				= typename InNext::arguments;
		//	using end_next_args				= typename EndNext::arguments;
		//	using end_prev_args				= typename EndPrev::arguments;
		//	using loop_pred_args				= typename LoopPred::arguments;
		//	using map_func_args				= typename MapAsgn::arguments;

		// don't implement these here,
		// use functions in filter.
		// more robust as we don't
		// want to predefine the
		// argument size.

		//	static constexpr auto _out_next_l		= out_f<signature, out_next_args::l_attributes>;
		//	static constexpr auto _out_next_r		= out_f<signature, out_next_args::r_attributes>;
		//	static constexpr auto _out_next			= make_next_function
		//							<
		//								OutNext::direction,
		//								OutNext::ufunction,
		//								_out_next_l, _out_next_r
		//							>;
		//	static constexpr bool _out_is_left_open		= is_left_open<OutIval::value>;
		//	static constexpr bool _out_is_right_open	= is_right_open<OutIval::value>;
		//	static constexpr bool _out_is_right_closed	= is_right_closed<OutIval::value>;

		//	static constexpr auto _in_next_l		= in_f<signature, in_next_args::l_attributes>;
		//	static constexpr auto _in_next_r		= in_f<signature, in_next_args::r_attributes>;
		//	static constexpr auto _in_next			= make_next_function
		//							<
		//								InNext::direction,
		//								InNext::ufunction,
		//								_in_next_l, _in_next_r
		//							>;
		//	static constexpr bool _in_is_left_open		= is_left_open<InIval::value>;
		//	static constexpr bool _in_is_right_open		= is_right_open<InIval::value>;
		//	static constexpr bool _in_is_right_closed	= is_right_closed<InIval::value>;

		//	static constexpr auto _end_next_l		= end_f<signature, end_next_args::l_attributes>;
		//	static constexpr auto _end_next_r		= end_f<signature, end_next_args::r_attributes>;
		//	static constexpr auto _end_next			= make_unary_function
		//							<
		//								EndNext::ufunction,
		//								EndNext::direction,
		//								_end_next_l, _end_next_r
		//							>;
		//	static constexpr auto _end_prev_l		= end_f<signature, end_prev_args::l_attributes>;
		//	static constexpr auto _end_prev_r		= end_f<signature, end_prev_args::r_attributes>;
		//	static constexpr auto _end_prev			= make_unary_function
		//							<
		//								EndPrev::ufunction,
		//								EndPrev::direction,
		//								_end_prev_l, _end_prev_r
		//							>;

		//	static constexpr bool _is_bidirectional		= is_bidirectional<InAxis::value>;
		//	static constexpr bool _is_last			= is_last<OutIval::value, InIval::value>;

		//	static constexpr auto _loop_pred_r1		= in_f<signature, loop_pred_args::r1_attributes>;
		//	static constexpr auto _loop_pred_r2		= end_f<signature, loop_pred_args::r2_attributes>;
		//	static constexpr auto _loop_pred		= make_binary_predicate
		//							<
		//								LoopPred::ufunction,
		//								_loop_pred_r1, _loop_pred_r2
		//							>;

		//	static constexpr auto _map_func_r1		= out_f<signature, map_func_args::r1_attributes>;
		//	static constexpr auto _map_func_r2		= in_f<signature, map_func_args::r2_attributes>;
		//	static constexpr auto _map_func			= make_binary_function
		//							<
		//								out_type, in_type, MapAsgn
		//								_map_func_r1, _map_func_r2
		//							>;

		public:

		//	static constexpr auto out_next			= assign
		//							<
		//								_out_next_l, _out_next, _out_next_r
		//							>;
		//	static constexpr bool is_out_next_before	= _out_is_left_open;
		//	static constexpr bool is_out_next_after		= _out_is_right_open && _in_is_right_closed;

		//	//

		//	static constexpr auto in_next			= assign
		//							<
		//								_in_next_l, _in_next, _in_next_r
		//							>;
		//	static constexpr bool is_in_next_before		= _in_is_left_open;
		//	static constexpr bool is_in_next_after		= _in_is_right_open && _out_is_right_closed;

		//	//

		//	static constexpr auto end_next			= assign
		//							<
		//								_end_next_l, _end_next, _end_next_r
		//							>;
		//	static constexpr bool is_end_next_after		= _is_bidirectional && _is_last;

		//	static constexpr auto end_prevous		= assign
		//							<
		//								_end_prev_l, _end_prev, _end_prev_r
		//							>;
		//	static constexpr bool is_end_previous_before	= _is_bidirectional && _is_last;

		//	//

		//	static constexpr auto loop_predicate		= test // is unidir_last ?
		//							<
		//								_is_equal, is_equal_r1, _is_equal_r2
		//							>;
		//	static constexpr auto loop_break		= LoopBreak::function;

		//	//

		//	static constexpr auto act_function		= assign
		//							<
		//								_map_func_l, _map_func, _map_func_r
		//							>;
		//	static constexpr bool is_act_function_after	= _out_is_right_closed || _in_is_right_closed;

		//	//

		//	static constexpr auto return_value		= _out_next_l;
	};

/*
	//	static constexpr auto out_cdr		= iterate<OutCdr::value, out_type>;
	//	static constexpr auto in_cdr		= iterate<InCdr::value, in_type>;
	//	static constexpr auto in_peek		= iterate<InPeek::value, in_type>;
	//	static constexpr auto end_cdr		= iterate<EndCdr::value, end_type>;
	//	static constexpr auto end_rcdr		= iterate<EndRCdr::value, end_type>;

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

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// refinement:

/***********************************************************************************************************************/

/*
	// new:

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
	using map_spec = map_specification
	<
		_out
		<
			_type   < OutType                     >,
			_ival   < OutInterval                 >,
			_next   < OutNext     , OutNextArgs   >
		>,

		_in
		<
			_type   < InType                      >,
			_ival   < InInterval                  >,
			_value  < ValFunc     , ValFuncArgs   >,
			_next   < InNext      , InNextArgs    >,
			_axis   < InAxis                      >,
			_peek   < InPeek      , InPeekArgs    >
		>,

		_end
		<
			_type   < EndType                     >,
			_next   < EndNext     , EndNextArgs   >,
			_prev   < EndPrev     , EndPrevArgs   >
		>,

		_algo
		<
			_test   < LoopPred    , LoopPredArgs  >,
			_apply  < LoopBreak                   >
			_assign < MapFunc     , MapArgs       >
		>
	>;
*/

/*
	// old:

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

