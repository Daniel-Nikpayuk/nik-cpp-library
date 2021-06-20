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

// iterator traits:

	// These form a value system for which the interface---to be
	// defined in the following source code---should not contradict.

/***********************************************************************************************************************/

namespace nlfs_4
{
	using namespace nlfs_3;

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

	template<Interval interval> constexpr bool V_is_open		= (interval == Interval::open);
	template<Interval interval> constexpr bool V_is_closing		= (interval == Interval::closing);
	template<Interval interval> constexpr bool V_is_closed		= (interval == Interval::closed);
	template<Interval interval> constexpr bool V_is_opening		= (interval == Interval::opening);

	template<Interval interval, auto> using S_is_open		= S_boolean<V_is_open<interval>>;
	template<Interval interval, auto> using S_is_closing		= S_boolean<V_is_closing<interval>>;
	template<Interval interval, auto> using S_is_closed		= S_boolean<V_is_closed<interval>>;
	template<Interval interval, auto> using S_is_opening		= S_boolean<V_is_opening<interval>>;

/***********************************************************************************************************************/

	template<Interval interval> constexpr bool V_is_left_open	= (V_is_open<interval> || V_is_opening<interval>);
	template<Interval interval> constexpr bool V_is_left_closed	= (V_is_closing<interval> || V_is_closed<interval>);
	template<Interval interval> constexpr bool V_is_right_open	= (V_is_open<interval> || V_is_closing<interval>);
	template<Interval interval> constexpr bool V_is_right_closed	= (V_is_closed<interval> || V_is_opening<interval>);

	template<Interval interval, auto> using S_is_left_open		= S_boolean<V_is_left_open<interval>>;
	template<Interval interval, auto> using S_is_left_closed	= S_boolean<V_is_left_closed<interval>>;
	template<Interval interval, auto> using S_is_right_open		= S_boolean<V_is_right_open<interval>>;
	template<Interval interval, auto> using S_is_right_closed	= S_boolean<V_is_right_closed<interval>>;

/***********************************************************************************************************************/

	template<auto, auto> using return_open				= S_value_V<Interval::open>;
	template<auto, auto> using return_closing			= S_value_V<Interval::closing>;
	template<auto, auto> using return_closed			= S_value_V<Interval::closed>;
	template<auto, auto> using return_opening			= S_value_V<Interval::opening>;

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

	template<auto direction> constexpr bool V_is_forward		= V_equal_VxV<direction, Direction::forward>;
	template<auto direction> constexpr bool V_is_backward		= V_equal_VxV<direction, Direction::backward>;

	//

	template<auto direction, auto> using S_is_forward		= S_boolean<V_is_forward<direction>>;
	template<auto direction, auto> using S_is_backward		= S_boolean<V_is_backward<direction>>;

/***********************************************************************************************************************/

// iterate:

	template<auto, auto U> using return_add_by		= S_value_V<add_by<T_type_U<U>,  1>>;
	template<auto, auto U> using return_subtract_by		= S_value_V<add_by<T_type_U<U>, -1>>;

	template<auto f, typename Type>
	constexpr auto iterate = V_colist_Bs
	<
		f, _na_,		f, U_type_T<Type>,

		S_is_forward,		return_add_by,
		S_is_backward,		return_subtract_by,
		otherwise,		return_function
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

	template<Axis axis> constexpr bool V_is_unidirectional		= (axis == Axis::unidirectional);
	template<Axis axis> constexpr bool V_is_bidirectional		= (axis == Axis::bidirectional);

	//

	template<Axis axis, auto> using S_is_unidirectional		= S_boolean<V_is_unidirectional<axis>>;
	template<Axis axis, auto> using S_is_bidirectional		= S_boolean<V_is_bidirectional<axis>>;

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

		template
		<
			bool predicate, auto next_f
		>
		using boolean_before_loop = cp_if_then_else
		<
			predicate, next_f
		>;

		template
		<
			Interval i, auto next_f
		>
		using interval_before_loop = boolean_before_loop
		<
			V_is_left_open<i>, next_f
		>;

	// after:

		template
		<
			bool predicate, auto act_combine_f
		>
		using boolean_after_loop = cp_if_then_else
		<
			predicate, act_combine_f
		>;

		template
		<
			Interval i, auto act_combine_f
		>
		using interval_after_loop = boolean_after_loop
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
		constexpr bool or_right_closed =		V_is_right_closed<ival1>		||
								V_is_right_closed<ival2>		;

		template<Interval ival, bool meet>
		constexpr bool right_open_and =			V_is_right_open<ival>			&&
								meet					;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// trinary:

		template<Interval ival, bool meet>
		constexpr bool right_closed_or =		V_is_right_closed<ival>			||
								meet					;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

