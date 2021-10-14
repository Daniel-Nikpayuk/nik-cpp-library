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

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// members:

/***********************************************************************************************************************/

public:

	template<typename... Ts> using _map_out		= _members_specification < _map<NLMember::out> , Ts... >;
	template<typename... Ts> using _map_in		= _members_specification < _map<NLMember::in > , Ts... >;
	template<typename... Ts> using _map_end		= _members_specification < _map<NLMember::end> , Ts... >;

	// in, end:

	template<typename... Ts> using _map_in_end	= _members_specification
	<
		_map
		<
			NLMember::in  ,
			NLMember::end

		>, Ts...
	>;

	// out, in:

	template<typename... Ts> using _map_out_in	= _members_specification
	<
		_map
		<
			NLMember::out ,
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
		auto NextFunc , typename NextArgs ,
		auto RetFunc  , typename RetArgs
	>
	class _members_specification
	<
		_map   < NLMember::out            >,

		_type  < Type                     >,
		_ival  < Ival                     >,
		_next  < NextFunc      , NextArgs >,
		_apply < RetFunc       , RetArgs  >
	>
	{
		public:

			using name				= _map<NLMember::out>;
			using type				= Type;

			static constexpr auto loop_break	= function_module::U_id;

			template<typename Signature>
			static constexpr auto next_assign	= resolve_assign<NextFunc, NextArgs, Signature>;

			template<typename Signature>
			static constexpr auto return_function	= resolve_apply<RetFunc, RetArgs, Signature>;

			static constexpr bool is_left_open	= V_is_left_open<Ival>;
			static constexpr bool is_right_open	= V_is_right_open<Ival>;
			static constexpr bool is_right_closed	= V_is_right_closed<Ival>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// in:

	template
	<
		typename Type ,
		Interval Ival ,
		auto ValFunc  , typename ValArgs  ,
		auto NextFunc , typename NextArgs ,
		auto Axis
	>
	class _members_specification
	<
		_map   < NLMember::in            >,

		_type  < Type                    >,
		_ival  < Ival                    >,
		_value < ValFunc      , ValArgs  >,
		_next  < NextFunc     , NextArgs >,
		_axis  < Axis                    >
	>
	{
		public:

			using name				= _map<NLMember::in>;
			using type				= Type;

			template<typename Signature>
			static constexpr auto value_assign	= resolve_assign<ValFunc, ValArgs, Signature>;

			template<typename Signature>
			static constexpr auto next_assign	= resolve_assign<NextFunc, NextArgs, Signature>;

			static constexpr bool is_left_open	= V_is_left_open<Ival>;
			static constexpr bool is_right_open	= V_is_right_open<Ival>;
			static constexpr bool is_right_closed	= V_is_right_closed<Ival>;

			static constexpr bool is_unidirectional = V_is_unidirectional<Axis>;
			static constexpr bool is_bidirectional	= V_is_bidirectional<Axis>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// end:

	template
	<
		typename Type ,
		auto NextFunc , typename NextArgs ,
		auto PrevFunc , typename PrevArgs
	>
	class _members_specification
	<
		_map  < NLMember::end            >,

		_type < Type                     >,
		_next < NextFunc      , NextArgs >,
		_prev < PrevFunc      , PrevArgs >
	>
	{
		public:

			using name				= _map<NLMember::end>;
			using type				= Type;

			template<typename Signature>
			static constexpr auto next_assign	= resolve_assign<NextFunc, NextArgs, Signature>;

			template<typename Signature>
			static constexpr auto prev_assign	= resolve_assign<PrevFunc, PrevArgs, Signature>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// in, end (loop pred, loop peek):

	template
	<
		typename OutSpec , typename InSpec   ,
		auto LoopPred    , typename LoopArgs ,
		auto PeekPred
	>
	class _members_specification
	<
		_map   < NLMember::in , NLMember::end >,

		_specs < OutSpec      , InSpec        >,
		_test  < LoopPred     , LoopArgs      >,
		_peek  < PeekPred                     >
	>
	{
		private:

			static constexpr bool is_last			= OutSpec::is_right_closed   && InSpec::is_right_open;
			static constexpr bool is_uni_last		=  InSpec::is_unidirectional && is_last;

			static constexpr auto LoopTest			= boolean_module::template V_if_then_else_VxV
									<
										is_uni_last, PeekPred, LoopPred
									>;

		public:

			using name					= _map<NLMember::in, NLMember::end>;

			template<typename Signature>
			static constexpr auto loop_test			= resolve_test<LoopTest, LoopArgs, Signature>;

			static constexpr bool is_end_prev_before	=  InSpec::is_bidirectional && is_last;
			static constexpr bool is_end_next_after		=  InSpec::is_bidirectional && is_last;
	};

/***********************************************************************************************************************/

	template
	<
		auto LoopPred , typename LoopArgs ,
		auto PeekPred
	>
	class _members_specification
	<
		_map  < NLMember::in , NLMember::end >,

		_test < LoopPred     , LoopArgs      >,
		_peek < PeekPred                     >
	>
	{
		public:

			template<typename OutSpec, typename InSpec>
			using result = _map_in_end
			<
				_specs  < OutSpec  , InSpec   >,
				_test   < LoopPred , LoopArgs >,
				_peek   < PeekPred            >
			>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, in (map assign):

	template
	<
		typename OutSpec , typename InSpec  ,
		auto MapFunc     , typename MapArgs
	>
	class _members_specification
	<
		_map    < NLMember::out , NLMember::in >,

		_specs  < OutSpec       , InSpec       >,
		_assign < MapFunc       , MapArgs      >
	>
	{
		public:

			using name					= _map<NLMember::out, NLMember::in>;

			template<typename Signature>
			static constexpr auto map_assign		= resolve_assign<MapFunc, MapArgs, Signature>;

			static constexpr bool is_out_next_after		= OutSpec::is_right_open    &&  InSpec::is_right_closed;
			static constexpr bool is_in_next_after		=  InSpec::is_right_open    && OutSpec::is_right_closed;
			static constexpr bool is_map_assign_after	= OutSpec::is_right_closed  ||  InSpec::is_right_closed;
	};

/***********************************************************************************************************************/

	template
	<
		auto MapFunc , typename MapArgs
	>
	class _members_specification
	<
		_map    < NLMember::out , NLMember::in >,

		_assign < MapFunc       , MapArgs      >
	>
	{
		public:

			template<typename OutSpec, typename InSpec>
			using result = _map_out_in
			<
				_specs  < OutSpec , InSpec  >,
				_assign < MapFunc , MapArgs >
			>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specification:

	template
	<
		typename OutSpec   ,
		typename InSpec    ,
		typename EndSpec   ,

		typename InEndSpec ,
		typename OutInSpec
	>
	class map_specification
	{
		public:

			using out_type					= typename OutSpec::type;
			using in_type					= typename InSpec::type;
			using end_type					= typename EndSpec::type;
			using return_type				= out_type;

			using signature					= resolve_signature
									<
										out_type ,
										in_type  ,
										end_type
									>;

		private:

			using in_end_spec				= typename InEndSpec::template result<OutSpec, InSpec>;
			using out_in_spec				= typename OutInSpec::template result<OutSpec, InSpec>;

		public:

			static constexpr auto out_next			= OutSpec::template next_assign<signature>;
			static constexpr bool is_out_next_before	= OutSpec::is_left_open;
			static constexpr bool is_out_next_after		= out_in_spec::is_out_next_after;

			//

			static constexpr auto in_next			= InSpec::template next_assign<signature>;
			static constexpr bool is_in_next_before		= InSpec::is_left_open;
			static constexpr bool is_in_next_after		= out_in_spec::is_in_next_after;

			//

			static constexpr auto end_next			= EndSpec::template next_assign<signature>;
			static constexpr bool is_end_next_after		= in_end_spec::is_end_next_after;

			static constexpr auto end_prev			= EndSpec::template prev_assign<signature>;
			static constexpr bool is_end_prev_before	= in_end_spec::is_end_prev_before;

			//

			static constexpr auto loop_predicate		= in_end_spec::template loop_test<signature>;
			static constexpr auto loop_break		= OutSpec::loop_break;

			//

			static constexpr auto act_function		= out_in_spec::template map_assign<signature>;
			static constexpr bool is_act_function_after	= out_in_spec::is_map_assign_after;

			//

			static constexpr auto return_value		= OutSpec::template return_function<signature>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// refinement:

/***********************************************************************************************************************/

	template
	<
		typename Type,
		auto MapFunc,

		typename OutType	= Type*,
		auto OutIval		= Interval::closing,
		auto OutNext		= increment,
		typename OutNextArgs	= increment_arg<SignMember::member_0>,
		auto OutRet		= select,
		typename OutRetArgs	= select_arg<SignMember::member_0>,

		typename InType		= Type*,
		auto InIval		= Interval::closing,
		auto ValFunc		= ignore,
		typename ValFuncArgs	= ignore_arg,
		auto InNext		= increment,
		typename InNextArgs	= increment_arg<SignMember::member_1>,
		auto InAxis		= Axis::bidirectional,

		typename EndType	= Type*,
		auto EndNext		= increment,
		typename EndNextArgs	= increment_arg<SignMember::member_2>,
		auto EndPrev		= decrement,
		typename EndPrevArgs	= decrement_arg<SignMember::member_2>,

		auto LoopPred		= is_end,
		typename LoopPredArgs	= is_end_args<SignMember::member_1, SignMember::member_2>,
		auto PeekPred		= is_peek_end,

		typename MapFuncArgs	= default_map_args<SignMember::member_0, SignMember::member_1>
	>
	using default_map_spec = map_specification
	<
		_map_out
		<
			_type   < OutType                 >,
			_ival   < OutIval                 >,
			_next   < OutNext  , OutNextArgs  >,
			_apply  < OutRet   , OutRetArgs   >
		>,

		_map_in
		<
			_type   < InType                  >,
			_ival   < InIval                  >,
			_value  < ValFunc  , ValFuncArgs  >,
			_next   < InNext   , InNextArgs   >,
			_axis   < InAxis                  >
		>,

		_map_end
		<
			_type   < EndType                 >,
			_next   < EndNext  , EndNextArgs  >,
			_prev   < EndPrev  , EndPrevArgs  >
		>,

		_map_in_end
		<
			_test   < LoopPred , LoopPredArgs >,
			_peek   < PeekPred                >
		>,

		_map_out_in
		<
			_assign < MapFunc  , MapFuncArgs  >
		>
	>;

/***********************************************************************************************************************/

	template
	<
		typename Type,
		auto MapFunc,

		typename OutType	= Type*,
		auto OutIval		= Interval::closing,
		auto OutNext		= increment,
		typename OutNextArgs	= increment_arg<SignMember::member_0>,
		auto OutRet		= select,
		typename OutRetArgs	= select_arg<SignMember::member_0>,

		typename InType		= Type,
		auto InIval		= Interval::closing,
		auto ValFunc		= ignore,
		typename ValFuncArgs	= ignore_arg,
		auto InNext		= increment,
		typename InNextArgs	= increment_arg<SignMember::member_1>,
		auto InAxis		= Axis::bidirectional,

		typename EndType	= Type,
		auto EndNext		= increment,
		typename EndNextArgs	= increment_arg<SignMember::member_2>,
		auto EndPrev		= decrement,
		typename EndPrevArgs	= decrement_arg<SignMember::member_2>,

		auto LoopPred		= is_end,
		typename LoopPredArgs	= is_end_args<SignMember::member_1, SignMember::member_2>,
		auto PeekPred		= is_peek_end,

		typename MapFuncArgs	= range_map_args<SignMember::member_0, SignMember::member_1>
	>
	using range_map_spec = map_specification
	<
		_map_out
		<
			_type   < OutType                 >,
			_ival   < OutIval                 >,
			_next   < OutNext  , OutNextArgs  >,
			_apply  < OutRet   , OutRetArgs   >
		>,

		_map_in
		<
			_type   < InType                  >,
			_ival   < InIval                  >,
			_value  < ValFunc  , ValFuncArgs  >,
			_next   < InNext   , InNextArgs   >,
			_axis   < InAxis                  >
		>,

		_map_end
		<
			_type   < EndType                 >,
			_next   < EndNext  , EndNextArgs  >,
			_prev   < EndPrev  , EndPrevArgs  >
		>,

		_map_in_end
		<
			_test   < LoopPred , LoopPredArgs >,
			_peek   < PeekPred                >
		>,

		_map_out_in
		<
			_assign < MapFunc  , MapFuncArgs  >
		>
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

