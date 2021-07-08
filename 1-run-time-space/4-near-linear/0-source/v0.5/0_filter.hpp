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

	// This component provides tools to refine the engine down to near linear functions.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// enumeration filters (level 0):

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// members:

/***********************************************************************************************************************/

	enum struct Member
	{
		out,
		in,
		car_in,
		cdr_in,
		end,
		aux,
		msg,

		dimension // filler
	};

	template<Member m> static constexpr bool V_is_out		= (m == Member::out);
	template<Member m> static constexpr bool V_is_in		= (m == Member::in);
	template<Member m> static constexpr bool V_is_car_in		= (m == Member::car_in);
	template<Member m> static constexpr bool V_is_cdr_in		= (m == Member::cdr_in);
	template<Member m> static constexpr bool V_is_end		= (m == Member::end);
	template<Member m> static constexpr bool V_is_aux		= (m == Member::aux);
	template<Member m> static constexpr bool V_is_msg		= (m == Member::msg);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attributes:

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

// attribute filters (level 1):

/***********************************************************************************************************************/

	template<Mutability Mutate, Denotation Denote>
	struct _attributes
	{
		static constexpr Mutability mutate = Mutate;
		static constexpr Denotation denote = Denote;
	};

	//

	using attr_ref		= _attributes < Mutability::variable  , Denotation::reference   >;
	using attr_deref	= _attributes < Mutability::variable  , Denotation::dereference >;
	using attr_cref		= _attributes < Mutability::immutable , Denotation::reference   >;
	using attr_cderef	= _attributes < Mutability::immutable , Denotation::dereference >;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// argument filters (level 2):

/***********************************************************************************************************************/

	template<typename LAttr, typename... RAttrs> struct _arguments { };

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// algorithm filters (level 3):

/***********************************************************************************************************************/

	template<typename T>	struct _type		{ using type = T; };
	template<Interval V>	struct _ival		{ static constexpr auto value = V; };
	template<Axis V>	struct _axis		{ static constexpr auto value = V; };

	template<auto UFunc, typename Args>
	struct _value
	{
		static constexpr auto ufunction		= UFunc;
		static constexpr auto uarguments	= functor_module::template U_type_T<Args>;
	};

	template<auto UFunc, Direction Dir, typename Args>
	struct _next
	{
		static constexpr auto ufunction		= UFunc;
		static constexpr auto direction		= Dir;
		static constexpr auto uarguments	= functor_module::template U_type_T<Args>;
	};

	template<auto UFunc, Direction Dir, typename Args>
	struct _prev
	{
		static constexpr auto ufunction		= UFunc;
		static constexpr auto direction		= Dir;
		static constexpr auto uarguments	= functor_module::template U_type_T<Args>;
	};

	template<auto UFunc, Direction Dir, typename Args>
	struct _peek
	{
		static constexpr auto ufunction		= UFunc;
		static constexpr auto direction		= Dir;
		static constexpr auto uarguments	= functor_module::template U_type_T<Args>;
	};

	template<auto UFunc, typename Args>
	struct _test
	{
		static constexpr auto ufunction		= UFunc;
		static constexpr auto uarguments	= functor_module::template U_type_T<Args>;
	};

	template<auto UFunc, typename Args>
	struct _apply
	{
		static constexpr auto ufunction		= UFunc;
		static constexpr auto uarguments	= functor_module::template U_type_T<Args>;
	};

	template<auto UFunc, typename Args>
	struct _assign
	{
		static constexpr auto ufunction		= UFunc;
		static constexpr auto uarguments	= functor_module::template U_type_T<Args>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// near linear filters (level 4):

/***********************************************************************************************************************/

	template<typename...> struct _out	{ };
	template<typename...> struct _in	{ };
	template<typename...> struct _end	{ };
	template<typename...> struct _algo	{ };

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatchers:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interval:

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

	//	template<bool predicate, auto next_f>
	//	static constexpr auto boolean_before_loop = lift
	//	<
	//		boolean_module::template V_if_then_else_VxV
	//		<
	//			predicate, next_f, _id_
	//		>
	//	>;

	//	template<Interval i, auto next_f>
	//	static constexpr auto interval_before_loop = boolean_before_loop
	//	<
	//		V_is_left_open<i>, next_f
	//	>;

	// after:

	//	template<bool predicate, auto act_combine_f>
	//	static constexpr auto boolean_after_loop = lift
	//	<
	//		boolean_module::template V_if_then_else_VxV
	//		<
	//			predicate, act_combine_f, _id_
	//		>
	//	>;

	//	template<Interval i, auto act_combine_f>
	//	static constexpr auto interval_after_loop = boolean_after_loop
	//	<
	//		V_is_right_closed<i>, act_combine_f
	//	>;

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

	//	template<Interval ival1, Interval ival2>
	//	static constexpr bool or_right_closed		= (V_is_right_closed<ival1> || V_is_right_closed<ival2>);

	//	template<Interval ival, bool meet>
	//	static constexpr bool right_open_and		= (V_is_right_open<ival> && meet);

/***********************************************************************************************************************/

// trinary:

	//	template<Interval ival, bool meet>
	//	static constexpr bool right_closed_or		= (V_is_right_closed<ival> || meet);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// direction:

/***********************************************************************************************************************/

//	template<auto, auto U> using return_add_by		= S_value_V<add_by<T_type_U<U>,  1>>;
//	template<auto, auto U> using return_subtract_by		= S_value_V<add_by<T_type_U<U>, -1>>;

//	template<auto f, typename Type>
//	static constexpr auto iterate = V_colist_Bs
//	<
//		f, _na_,		f, U_type_T<Type>,

//		S_is_forward,		return_add_by,
//		S_is_backward,		return_subtract_by,
//		otherwise,		return_function
//	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// axis:

/***********************************************************************************************************************/

	// is_bidirectional // ?

	// is_last // ?

/***********************************************************************************************************************/

	// out_f

	// in_f

	// end_f

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// algorithm:

/***********************************************************************************************************************/

// members:

	// out:

	//	template<typename Sign, typename Attr>
	//	static constexpr out_f = 

	// in:

	//	template<typename Sign, typename Attr>
	//	static constexpr in_f = 

/***********************************************************************************************************************/

// make function:

	//	template<auto uf, auto l, auto r>
	//	static constexpr auto make_unary_function = 

	//	template<auto uf, auto l, auto r1, auto r2>
	//	static constexpr auto make_binary_function = 

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

