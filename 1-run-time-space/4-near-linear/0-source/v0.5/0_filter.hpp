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

// filter source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// signature arguments:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

/***********************************************************************************************************************/

	enum struct Mutability
	{
		immutable,
		variable,

		dimension // filler
	};

	enum struct Denotation
	{
		reference,
		dereference,

		dimension // filler
	};

/***********************************************************************************************************************/

	template<Mutability m>
	static constexpr bool V_is_immutable			= (m == Mutability::immutable);

	template<Mutability m>
	static constexpr bool V_is_variable			= (m == Mutability::variable);

	//

	template<Denotation d>
	static constexpr bool V_is_reference			= (d == Denotation::reference);

	template<Denotation d>
	static constexpr bool V_is_dereference			= (d == Denotation::dereference);

/***********************************************************************************************************************/

	template<Mutability m, Denotation d>
	static constexpr bool V_is_immutable_reference		= (V_is_immutable<m> && V_is_reference<d>);

	template<Mutability m, Denotation d>
	static constexpr bool V_is_immutable_dereference	= (V_is_immutable<m> && V_is_dereference<d>);

	template<Mutability m, Denotation d>
	static constexpr bool V_is_variable_reference		= (V_is_variable<m> && V_is_reference<d>);

	template<Mutability m, Denotation d>
	static constexpr bool V_is_variable_dereference		= (V_is_variable<m> && V_is_dereference<d>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attribute specifications:

/***********************************************************************************************************************/

	template
	<
		Mutability Mutate,
		Denotation Denote,
		auto...
	>
	struct _argument_attributes
	{
		static constexpr Mutability mutate		= Mutate;
		static constexpr Denotation denote		= Denote;
	};

	//

	using imm_ref_arg_attr		= _argument_attributes < Mutability::immutable , Denotation::reference   >;
	using imm_deref_arg_attr	= _argument_attributes < Mutability::immutable , Denotation::dereference >;
	using var_ref_arg_attr		= _argument_attributes < Mutability::variable  , Denotation::reference   >;
	using var_deref_arg_attr	= _argument_attributes < Mutability::variable  , Denotation::dereference >;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// argument specifications:

/***********************************************************************************************************************/

	template<typename = void, typename = void> struct _argument		{ };

	//

	template<typename Type = void> using imm_ref_arg		= _argument < Type , imm_ref_arg_attr   >;
	template<typename Type = void> using imm_deref_arg		= _argument < Type , imm_deref_arg_attr >;
	template<typename Type = void> using var_ref_arg		= _argument < Type , var_ref_arg_attr   >;
	template<typename Type = void> using var_deref_arg		= _argument < Type , var_deref_arg_attr >;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attribute specifications:

/***********************************************************************************************************************/

	template
	<
		OneCycleMember Member,
		Interval Ival
	>
	struct _one_cycle_object_attributes
	{
		static constexpr OneCycleMember member	= Member;
		static constexpr Interval interval	= Ival;
	};

	//

	template<Interval ival>
	using _out_obj_attr			= _one_cycle_object_attributes<OneCycleMember::out, ival>;

	template<Interval ival>
	using _in_obj_attr			= _one_cycle_object_attributes<OneCycleMember::in, ival>;

	template<Interval ival>
	using _car_in_obj_attr			= _one_cycle_object_attributes<OneCycleMember::car_in, ival>;

	template<Interval ival>
	using _cdr_in_obj_attr			= _one_cycle_object_attributes<OneCycleMember::cdr_in, ival>;

	template<Interval ival>
	using _end_obj_attr			= _one_cycle_object_attributes<OneCycleMember::end, ival>;

	template<Interval ival>
	using _aux_obj_attr			= _one_cycle_object_attributes<OneCycleMember::aux, ival>;

	template<Interval ival>
	using _msg_obj_attr			= _one_cycle_object_attributes<OneCycleMember::msg, ival>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// object specifications:

/***********************************************************************************************************************/

	template<typename Type, Interval ival> using _out_object	= _object < Type , _out_obj_attr<ival>    >;
	template<typename Type, Interval ival> using _in_object		= _object < Type , _in_obj_attr<ival>     >;
	template<typename Type, Interval ival> using _car_in_object	= _object < Type , _car_in_obj_attr<ival> >;
	template<typename Type, Interval ival> using _cdr_in_object	= _object < Type , _cdr_in_obj_attr<ival> >;
	template<typename Type, Interval ival> using _end_object	= _object < Type , _end_obj_attr<ival>    >;
	template<typename Type, Interval ival> using _aux_object	= _object < Type , _aux_obj_attr<ival>    >;
	template<typename Type, Interval ival> using _msg_object	= _object < Type , _msg_obj_attr<ival>    >;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// near linear source:

	// This component provides tools to refine the engine down to near linear functions.

public:

	// map:

		//     ival meet: (out is right closed) or (in is right closed) ?
		// out ival meet: (out is right open) and (in is right closed) ?
		//  in ival meet: (in is right open) and (out is right closed) ?

	// find all:

		//     ival meet: (out is right closed) or (in is right closed) ?
		// out ival meet: (out is right open) and (in is right closed) ?
		//  in ival meet: (in is right open) and (out is right closed) ?

	// zip:

		//     in ival meet: (car in is right closed) or (cdr in is right closed) ?
		//        ival meet: (out is right closed) or (car in is right closed) or (cdr in is right closed) ?
		//    out ival meet: (out is right open) and (car in or cdr in is right closed) ?
		// car in ival meet: (car in is right open) and (out or cdr in is right closed) ?
		// cdr in ival meet: (cdr in is right open) and (out or car in is right closed) ?

	// fasten:

		//     in ival meet: (car in is right closed) or (cdr in is right closed) ?
		//        ival meet: (out is right closed) or (car in is right closed) or (cdr in is right closed) ?
		//    out ival meet: (out is right open) and (car in or cdr in is right closed) ?
		// car in ival meet: (car in is right open) and (out or cdr in is right closed) ?
		// cdr in ival meet: (cdr in is right open) and (out or car in is right closed) ?

	// glide:

		//        ival meet: (car in is right closed) or (cdr in is right closed) ?
		// car in ival meet: (car in is right open) and (cdr in is right closed) ?
		// cdr in ival meet: (cdr in is right open) and (car in is right closed) ?

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
