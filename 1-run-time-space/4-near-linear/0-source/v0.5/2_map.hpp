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

// members:

/***********************************************************************************************************************/

public:

	template<typename... Ts> using _map_out		= _members_specification < _map<NLMember::out> , Ts... >;
	template<typename... Ts> using _map_in		= _members_specification < _map<NLMember::in > , Ts... >;
	template<typename... Ts> using _map_end		= _members_specification < _map<NLMember::end> , Ts... >;

	// out, in, end:

	template<typename... Ts> using _map_in_end	= _members_specification
	<
		_map
		<
			NLMember::in,
			NLMember::end

		>, Ts...
	>;

	template<typename... Ts> using _map_out_in	= _members_specification
	<
		_map
		<
			NLMember::out,
			NLMember::in

		>, Ts...
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out:

	template
	<
		typename Type ,
		Interval Ival ,
		auto NextFunc , typename NextMems , typename NextAttrs ,
		auto ApplFunc , typename ApplMems , typename ApplAttrs
	>
	class _members_specification
	<
		_map   < NLMember::out                       >,

		_type  < Type                                >,
		_ival  < Ival                                >,
		_next  < NextFunc      , NextMems, NextAttrs >,
		_apply < ApplFunc      , ApplMems, ApplAttrs >
	>
	{
		public:

			using name				= _map<NLMember::out>;
			using type				= Type;

			template<typename Signature>
			static constexpr auto next_assign	= make_assign
								<
									NextFunc, NextMems,
									NextAttrs, Signature
								>;

			static constexpr bool is_left_open	= V_is_left_open<Ival>;
			static constexpr bool is_right_open	= V_is_right_open<Ival>;
			static constexpr bool is_right_closed	= V_is_right_closed<Ival>;

			template<typename Signature>
			static constexpr auto loop_break	= make_apply
								<
									ApplFunc, ApplMems,
									ApplAttrs, Signature
								>;
	};

/***********************************************************************************************************************/

// in:

	template
	<
		typename Type ,
		Interval Ival ,
		auto ValFunc  , typename ValMems  , typename ValAttrs  ,
		auto NextFunc , typename NextMems , typename NextAttrs ,
		auto Axis     ,
		auto PeekFunc , typename PeekMems , typename PeekAttrs
	>
	class _members_specification
	<
		_map   < NLMember::in                        >,

		_type  < Type                                >,
		_ival  < Ival                                >,
		_value < ValFunc      , ValMems  , ValAttrs  >,
		_next  < NextFunc     , NextMems , NextAttrs >,
		_axis  < Axis                                >,
		_peek  < PeekFunc     , PeekMems , PeekAttrs >
	>
	{
		public:

			using name				= _map<NLMember::in>;
			using type				= Type;

			template<typename Signature>
			static constexpr auto value_assign	= make_assign
								<
									ValFunc, ValMems,
									ValAttrs, Signature
								>;

			template<typename Signature>
			static constexpr auto next_assign	= make_assign
								<
									NextFunc, NextMems,
									NextAttrs, Signature
								>;

			template<typename Signature>
			static constexpr auto peek_test		= make_test
								<
									PeekFunc, PeekMems,
									PeekAttrs, Signature
								>;

			static constexpr bool is_left_open	= V_is_left_open<Ival>;
			static constexpr bool is_right_open	= V_is_right_open<Ival>;
			static constexpr bool is_right_closed	= V_is_right_closed<Ival>;

			static constexpr bool is_bidirectional	= V_is_bidirectional<Axis>;
	};

/***********************************************************************************************************************/

// end:

	template
	<
		typename Type ,
		auto NextFunc , typename NextMems , typename NextAttrs ,
		auto PrevFunc , typename PrevMems , typename PrevAttrs
	>
	class _members_specification
	<
		_map   < NLMember::end                        >,

		_type  < Type                                 >,
		_next  < NextFunc      , NextMems , NextAttrs >,
		_prev  < PrevFunc      , PrevMems , PrevAttrs >
	>
	{
		public:

			using name				= _map<NLMember::end>;
			using type				= Type;

			template<typename Signature>
			static constexpr auto next_assign	= make_assign
								<
									NextFunc, NextMems,
									NextAttrs, Signature
								>;

			template<typename Signature>
			static constexpr auto prev_assign	= make_assign
								<
									PrevFunc, PrevMems,
									PrevAttrs, Signature
								>;
	};

/***********************************************************************************************************************/

// in, end (loop test):

	template
	<
		typename InSpec , typename EndSpec  ,
		auto LoopPred   , typename LoopMems , typename LoopAttrs
	>
	class _members_specification
	<
		_map   < NLMember::in , NLMember::end             >,

		_specs < InSpec       , EndSpec                   >,
		_test  < LoopPred     , LoopMems      , LoopAttrs >
	>
	{
		public:

			using name				= _map<NLMember::in, NLMember::end>;

			template<typename Signature>
			static constexpr auto loop_test		= make_test
								<
									LoopPred, LoopMems,
									LoopAttrs, Signature
								>;
	};

/***********************************************************************************************************************/

// out, in (map assign):

	template
	<
		typename OutSpec , typename InSpec  ,
		auto MapFunc     , typename MapMems , typename MapAttrs
	>
	class _members_specification
	<
		_map    < NLMember::out , NLMember::in            >,

		_specs  < OutSpec       , InSpec                  >,
		_assign < MapFunc       , MapMems      , MapAttrs >
	>
	{
		public:

			using name					= _map<NLMember::end>;

			static constexpr bool is_last			= true; // OutSpec, InSpec;

			static constexpr bool is_out_next_after		= OutSpec::is_right_open &&  InSpec::is_right_closed;
			static constexpr bool is_in_next_after		=  InSpec::is_right_open && OutSpec::is_right_closed;

			static constexpr bool is_end_next_after		= InSpec::is_bidirectional && is_last;
			static constexpr bool is_end_previous_before	= InSpec::is_bidirectional && is_last;

			template<typename Signature>
			static constexpr auto map_assign		= make_assign
									<
										MapFunc, MapMems,
										MapAttrs, Signature
									>;
		//	static constexpr bool is_map_assign_after	= _out_is_right_closed || _in_is_right_closed;
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
*/

/***********************************************************************************************************************/

// specification:

	template
	<
		typename OutSpec  ,
		typename InSpec   ,
		typename EndSpec  ,

		typename AlgoSpec
	>
	class map_specification
	{
		public:

			using out_type					= typename OutSpec::type;
			using in_type					= typename InSpec::type;
			using end_type					= typename EndSpec::type;
			using return_type				= out_type;

			using signature					= make_signature
									<
										out_type ,
										in_type  ,
										end_type
									>;

		private:

			using InEndSpec					= _map_in_end
									<
										_specs<InSpec, EndSpec>
									>;
			using OutInSpec					= _map_out_in
									<
										_specs<OutSpec, InSpec>
									>;

		public:

			static constexpr auto out_next			= OutSpec::next_assign;
			static constexpr bool is_out_next_before	= OutSpec::is_left_open;
			static constexpr auto loop_break		= OutSpec::template loop_break<signature>;

			//

			static constexpr auto in_next			= InSpec::next_assign;
			static constexpr bool is_in_next_before		= InSpec::is_left_open;

			//

			static constexpr auto end_next			= EndSpec::next_assign;
			static constexpr auto end_previous		= EndSpec::previous_assign;

			//

			static constexpr auto loop_predicate		= InEndSpec::template loop_test<signature>;

			//

			static constexpr bool is_out_next_after		= OutInSpec::is_out_next_after;
			static constexpr bool is_in_next_after		= OutInSpec::is_in_next_after;
			static constexpr bool is_end_next_after		= OutInSpec::is_end_next_after;
			static constexpr bool is_end_previous_before	= OutInSpec::is_end_previous_before;

			static constexpr auto act_function		= OutInSpec::template map_assign<signature>;
			static constexpr bool is_act_function_after	= OutInSpec::is_map_assign_after;

			//

		//	static constexpr auto return_value		= _out_next_l;
	};

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

