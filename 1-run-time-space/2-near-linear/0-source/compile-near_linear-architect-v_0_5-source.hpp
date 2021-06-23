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

// near linear source:

	// This component provides tools to refine the engine down to near linear functions.

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interval:

/***********************************************************************************************************************/

	enum struct Interval
	{
		open,
		closing,
		closed,
		opening,

		dimension // filler
	};

/***********************************************************************************************************************/

	template<Interval interval>
	static constexpr bool V_is_open			= (interval == Interval::open);

	template<Interval interval>
	static constexpr bool V_is_closing		= (interval == Interval::closing);

	template<Interval interval>
	static constexpr bool V_is_closed		= (interval == Interval::closed);

	template<Interval interval>
	static constexpr bool V_is_opening		= (interval == Interval::opening);

/***********************************************************************************************************************/

	template<Interval interval>
	static constexpr bool V_is_left_open		= (V_is_open<interval> || V_is_opening<interval>);

	template<Interval interval>
	static constexpr bool V_is_left_closed		= (V_is_closing<interval> || V_is_closed<interval>);

	template<Interval interval>
	static constexpr bool V_is_right_open		= (V_is_open<interval> || V_is_closing<interval>);

	template<Interval interval>
	static constexpr bool V_is_right_closed		= (V_is_closed<interval> || V_is_opening<interval>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// direction:

/***********************************************************************************************************************/

	enum struct Direction
	{
		forward,
		backward,

		dimension // filler
	};

/***********************************************************************************************************************/

	// is required to accept external input.

	template<auto direction>
	static constexpr bool V_is_forward		= functor_module::template V_equal_VxV
							<
								direction, Direction::forward
							>;

	template<auto direction>
	static constexpr bool V_is_backward		= functor_module::template V_equal_VxV
							<
								direction, Direction::backward
							>;

/***********************************************************************************************************************/

// iterate:

/*
	template<auto, auto U> using return_add_by		= S_value_V<add_by<T_type_U<U>,  1>>;
	template<auto, auto U> using return_subtract_by		= S_value_V<add_by<T_type_U<U>, -1>>;

	template<auto f, typename Type>
	static constexpr auto iterate = V_colist_Bs
	<
		f, _na_,		f, U_type_T<Type>,

		S_is_forward,		return_add_by,
		S_is_backward,		return_subtract_by,
		otherwise,		return_function
	>;
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// axis:

/***********************************************************************************************************************/

	enum struct Axis
	{
		unidirectional,
		bidirectional,

		dimension // filler
	};

/***********************************************************************************************************************/

	template<Axis axis>
	static constexpr bool V_is_unidirectional	= (axis == Axis::unidirectional);

	template<Axis axis>
	static constexpr bool V_is_bidirectional	= (axis == Axis::bidirectional);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// loop interval functions:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// unary:

/*
	open:    () = (  & [)
	closing: [) =      [)
	closed:  [] = [) &  ]
	opening: (] = (  & [) &  ]


	1. For the left endpoint, if open, then iterate.
	2. Evaluate the common (closing) loop.
	3. For the right endpoint, if closed, then act/combine.
*/

	// before:

		template<bool predicate, auto next_f>
		static constexpr auto boolean_before_loop = lift
		<
			boolean_module::template V_if_then_else_VxV
			<
				predicate, next_f, _id_
			>
		>;

		template<Interval i, auto next_f>
		static constexpr auto interval_before_loop = boolean_before_loop
		<
			V_is_left_open<i>, next_f
		>;

	// after:

		template<bool predicate, auto act_combine_f>
		static constexpr auto boolean_after_loop = lift
		<
			boolean_module::template V_if_then_else_VxV
			<
				predicate, act_combine_f, _id_
			>
		>;

		template<Interval i, auto act_combine_f>
		static constexpr auto interval_after_loop = boolean_after_loop
		<
			V_is_right_closed<i>, act_combine_f
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// binary:

/*
	() /\ () = ()  =>  (),() = (,( & [)
	() /\ [) = [)  =>  (),[) = (,  & [)
	() /\ [] = []  =>  (),[] = (,  & [) & ],] & ), 			(out iterator equals end requires last)
	() /\ (] = (]  =>  (),(] = (,( & [) & ],] & ), 			(out iterator equals end requires last)

	[) /\ () = [)  =>  [),() =  ,( & [)
	[) /\ [) = [)  =>  [),[) =     & [)
	[) /\ [] = []  =>  [),[] =     & [) & ],] & ), 			(out iterator equals end requires last)
	[) /\ (] = []  =>  [),(] =  ,( & [) & ],] & ), 			(out iterator equals end requires last)

	[] /\ () = []  =>  [],() =  ,( & [) & ],] &  ,)			(in iterator equals end requires last)
	[] /\ [) = []  =>  [],[) =     & [) & ],] &  ,)			(in iterator equals end requires last)
	[] /\ [] = []  =>  [],[] =     & [) & ],]
	[] /\ (] = []  =>  [],(] =  ,( & [) & ],]

	(] /\ () = (]  =>  (],() = (,( & [) & ],] &  ,)			(in iterator equals end requires last)
	(] /\ [) = []  =>  (],[) = (,  & [) & ],] &  ,)			(in iterator equals end requires last)
	(] /\ [] = []  =>  (],[] = (,  & [) & ],]
	(] /\ (] = (]  =>  (],(] = (,( & [) & ],]


	1. For each left endpoint, if open, then iterate.
	2. Evaluate the common (closing) loop.
	3. If there exists any right endpoint, which is closed, then act/combine.
	4. If (3), then for each right endpoint, when open, iterate.
*/

		template<Interval ival1, Interval ival2>
		static constexpr bool or_right_closed		= (V_is_right_closed<ival1> || V_is_right_closed<ival2>);

		template<Interval ival, bool meet>
		static constexpr bool right_open_and		= (V_is_right_open<ival> && meet);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// trinary:

		template<Interval ival, bool meet>
		static constexpr bool right_closed_or		= (V_is_right_closed<ival> || meet);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// list inductor specs:

/***********************************************************************************************************************/

// root:

	template<auto N = _id_>	static constexpr auto before_loop		= lift<N>;

	//

	template<auto N = _id_>	static constexpr auto before_value		= lift<N>;
	template<auto N = _id_>	static constexpr auto after_value		= lift<N>;

	template<auto N = _id_>	static constexpr auto before_act		= lift<N>;
	template<auto N = _id_>	static constexpr auto after_act			= lift<N>;

	template<auto N = _id_>	static constexpr auto before_combine		= lift<N>;
	template<auto N = _id_>	static constexpr auto after_combine		= lift<N>;

	template<auto N = _id_>	static constexpr auto before_next		= lift<N>;
	template<auto N = _id_>	static constexpr auto after_next		= lift<N>;

	//

	template<auto N = _id_>	static constexpr auto after_loop		= lift<N>;

/***********************************************************************************************************************/

// stem:

	template<auto P, auto B, auto N = _id_> static constexpr auto stem_before_loop		= stem<P, B, N>;

	//

	template<auto P, auto B, auto N = _id_> static constexpr auto stem_before_value		= stem<P, B, N>;
	template<auto P, auto B, auto N = _id_> static constexpr auto stem_after_value		= stem<P, B, N>;

	template<auto P, auto B, auto N = _id_> static constexpr auto stem_before_act		= stem<P, B, N>;
	template<auto P, auto B, auto N = _id_> static constexpr auto stem_after_act		= stem<P, B, N>;

	template<auto P, auto B, auto N = _id_> static constexpr auto stem_before_combine	= stem<P, B, N>;
	template<auto P, auto B, auto N = _id_> static constexpr auto stem_after_combine	= stem<P, B, N>;

	template<auto P, auto B, auto N = _id_> static constexpr auto stem_before_next		= stem<P, B, N>;
	template<auto P, auto B, auto N = _id_> static constexpr auto stem_after_next		= stem<P, B, N>;

	//

	template<auto P, auto B, auto N = _id_> static constexpr auto stem_after_loop		= stem<P, B, N>;

/***********************************************************************************************************************/

// costem:

	template<auto P, auto N, auto B = _id_> static constexpr auto costem_before_loop	= costem<P, N, B>;

	//

	template<auto P, auto N, auto B = _id_> static constexpr auto costem_before_value	= costem<P, N, B>;
	template<auto P, auto N, auto B = _id_> static constexpr auto costem_after_value	= costem<P, N, B>;

	template<auto P, auto N, auto B = _id_> static constexpr auto costem_before_act		= costem<P, N, B>;
	template<auto P, auto N, auto B = _id_> static constexpr auto costem_after_act		= costem<P, N, B>;

	template<auto P, auto N, auto B = _id_> static constexpr auto costem_before_combine	= costem<P, N, B>;
	template<auto P, auto N, auto B = _id_> static constexpr auto costem_after_combine	= costem<P, N, B>;

	template<auto P, auto N, auto B = _id_> static constexpr auto costem_before_next	= costem<P, N, B>;
	template<auto P, auto N, auto B = _id_> static constexpr auto costem_after_next		= costem<P, N, B>;

	//

	template<auto P, auto N, auto B = _id_> static constexpr auto costem_after_loop		= costem<P, N, B>;

/***********************************************************************************************************************/

// distem:

	template<auto P, auto N1, auto N2 = _id_> static constexpr auto distem_before_loop	= distem<P, N1, N2>;

	//

	template<auto P, auto N1, auto N2 = _id_> static constexpr auto distem_before_value	= distem<P, N1, N2>;
	template<auto P, auto N1, auto N2 = _id_> static constexpr auto distem_after_value	= distem<P, N1, N2>;

	template<auto P, auto N1, auto N2 = _id_> static constexpr auto distem_before_act	= distem<P, N1, N2>;
	template<auto P, auto N1, auto N2 = _id_> static constexpr auto distem_after_act	= distem<P, N1, N2>;

	template<auto P, auto N1, auto N2 = _id_> static constexpr auto distem_before_combine	= distem<P, N1, N2>;
	template<auto P, auto N1, auto N2 = _id_> static constexpr auto distem_after_combine	= distem<P, N1, N2>;

	template<auto P, auto N1, auto N2 = _id_> static constexpr auto distem_before_next	= distem<P, N1, N2>;
	template<auto P, auto N1, auto N2 = _id_> static constexpr auto distem_after_next	= distem<P, N1, N2>;

	//

	template<auto P, auto N1, auto N2 = _id_> static constexpr auto distem_after_loop	= distem<P, N1, N2>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// list operator specs:

/***********************************************************************************************************************/

// out:

	template<typename Spec> using out_type_					= typename Spec::out_type;

	template<typename Spec> static constexpr auto out_ival_			= Spec::out_ival;
	template<typename Spec> static constexpr auto out_ival_meet_		= Spec::out_ival_meet;
	template<typename Spec> static constexpr auto out_next_			= Spec::out_next;

/***********************************************************************************************************************/

// in:

	template<typename Spec> using in_type_					= typename Spec::in_type;

	template<typename Spec> static constexpr auto in_ival_			= Spec::in_ival;
	template<typename Spec> static constexpr auto in_ival_meet_		= Spec::in_ival_meet;
	template<typename Spec> static constexpr auto in_next_			= Spec::in_next;

/***********************************************************************************************************************/

// car in:

	template<typename Spec> using car_in_type_				= typename Spec::car_in_type;

	template<typename Spec> static constexpr auto car_in_ival_		= Spec::car_in_ival;
	template<typename Spec> static constexpr auto car_in_ival_meet_		= Spec::car_in_ival_meet;
	template<typename Spec> static constexpr auto car_in_next_		= Spec::car_in_next;

/***********************************************************************************************************************/

// cdr in:

	template<typename Spec> using cdr_in_type_				= typename Spec::cdr_in_type;

	template<typename Spec> static constexpr auto cdr_in_ival_		= Spec::cdr_in_ival;
	template<typename Spec> static constexpr auto cdr_in_ival_meet_		= Spec::cdr_in_ival_meet;
	template<typename Spec> static constexpr auto cdr_in_next_		= Spec::cdr_in_next;

/***********************************************************************************************************************/

// end:

	template<typename Spec> using end_type_					= typename Spec::end_type;

	template<typename Spec> static constexpr auto end_next_			= Spec::end_next;
	template<typename Spec> static constexpr auto end_prev_			= Spec::end_previous;

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

	template<typename Spec> static constexpr auto return_value_		= Spec::return_value;

/***********************************************************************************************************************/

// predicate:

	template<typename Spec> static constexpr bool ival_meet_		= Spec::ival_meet;
	template<typename Spec> static constexpr bool is_bi_last_		= Spec::is_bi_last;

/***********************************************************************************************************************/

// function:

	template<typename Spec> static constexpr auto loop_pred_		= Spec::loop_predicate;
	template<typename Spec> static constexpr auto loop_break_		= Spec::loop_break;

	template<typename Spec> static constexpr auto value_pred_		= Spec::value_predicate;
//	template<typename Spec> static constexpr auto value_break_		= Spec::value_break;
//	template<typename Spec> static constexpr auto value_func_		= Spec::value_function;

	template<typename Spec> static constexpr auto act_pred_			= Spec::act_predicate;
	template<typename Spec> static constexpr auto act_break_		= Spec::act_break;
	template<typename Spec> static constexpr auto act_func_			= Spec::act_function;

	template<typename Spec> static constexpr auto combine_func_		= Spec::combine_function;

	template<typename Spec> static constexpr auto post_pred_		= Spec::post_predicate;
	template<typename Spec> static constexpr auto post_func_		= Spec::post_function;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// subspecifications:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// object specs:

/***********************************************************************************************************************/

/*
	template<typename ObjSpec> using spec_type_	= typename ObjSpec::type;

	template<typename ObjSpec>
	static constexpr auto spec_ival_		= ObjSpec::interval;

	template<typename ObjSpec>
	static constexpr auto spec_pred_		= ObjSpec::predicate;

	template<typename ObjSpec>
	static constexpr auto spec_func_		= ObjSpec::function;
*/

/***********************************************************************************************************************/

/*
	template<typename Type, auto Interval = _na_>
	struct _object
	{
		using type						= Type;

		static constexpr auto interval				= Interval;
	};

	template<typename Type, auto Interval>
	using _out_obj					= _object<Type, Interval>;

	template<typename Type, auto Interval>
	using _in_obj					= _object<Type, Interval>;

	template<typename Type, auto Interval>
	using _end_obj					= _object<Type, Interval>;
*/

/***********************************************************************************************************************/

/*
	template<typename Type, auto Cons>
	struct _return
	{
		using type						= Type;

		static constexpr auto function				= Cons;
	};
*/

/***********************************************************************************************************************/

/*
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
*/

/***********************************************************************************************************************/

/*
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
*/

/***********************************************************************************************************************/

/*
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
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// break (messages):

/***********************************************************************************************************************/

	enum struct Break
	{
		before_value,
		after_value,

		before_act1,
		before_act2,
		before_act,
		after_act,

		before_combine1,
		before_combine2,
		before_combine,
		after_combine,

		before_next,
		after_next,

		dimension // filler
	};

	// predicates:

		// value:

			static constexpr auto is_before_value		= function_module::template is_value
									<
										Break, Break::before_value
									>;

			static constexpr auto is_after_value		= function_module::template is_value
									<
										Break, Break::after_value
									>;

		// act:

			static constexpr auto is_before_act		= function_module::template is_value
									<
										Break, Break::before_act
									>;

			static constexpr auto is_after_act		= function_module::template is_value
									<
										Break, Break::after_act
									>;

		// combine:

			static constexpr auto is_before_combine		= function_module::template is_value
									<
										Break, Break::before_combine
									>;

			static constexpr auto is_after_combine		= function_module::template is_value
									<
										Break, Break::after_combine
									>;

		// next:

			static constexpr auto is_before_next		= function_module::template is_value
									<
										Break, Break::before_next
									>;

			static constexpr auto is_after_next		= function_module::template is_value
									<
										Break, Break::after_next
									>;

	// constants:

		// value:

			static constexpr auto br_before_value		= function_module::template constant
									<
										Break::before_value
									>;

			static constexpr auto br_after_value		= function_module::template constant
									<
										Break::after_value
									>;

		// act:

			static constexpr auto br_before_act		= function_module::template constant
									<
										Break::before_act
									>;

			static constexpr auto br_after_act		= function_module::template constant
									<
										Break::after_act
									>;

		// combine:

			static constexpr auto br_before_combine		= function_module::template constant
									<
										Break::before_combine
									>;

			static constexpr auto br_after_combine		= function_module::template constant
									<
										Break::after_combine
									>;

		// next:

			static constexpr auto br_before_next		= function_module::template constant
									<
										Break::before_next
									>;

			static constexpr auto br_after_next		= function_module::template constant
									<
										Break::after_next
									>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// loop:

/***********************************************************************************************************************/

// precycle:

	template<auto... cs>
	static constexpr auto precycle = opt_chain_endopose<cs...>;

/***********************************************************************************************************************/

// cycle:

private:
	
	template<auto... cs>
	static constexpr auto f_cycle()
	{
		constexpr auto endo = opt_chain_endopose<cs...>;

		return close_cycle
		<
			endo,
			function_module::template out_type<endo>
		>;
	}

public:

	template<auto... cs>
	static constexpr auto cycle = f_cycle<cs...>();

/***********************************************************************************************************************/

// postcycle:

	template<auto... cs>
	static constexpr auto postcycle = opt_chain_endopose<cs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

