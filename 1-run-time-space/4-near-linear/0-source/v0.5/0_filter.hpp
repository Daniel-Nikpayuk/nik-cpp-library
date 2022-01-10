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

// filter source:

	// This component provides tools to refine the engine down to near linear functions.

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// enumeration filters (level 0):

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// algorithms:

/***********************************************************************************************************************/

	enum struct NLAlgorithm
	{
		generic,

		repeat,
		map,
		fold,
		find_first,
		find_all,
		zip,
		fasten,
		glide,

		dimension // filler
	};

	template<NLAlgorithm a> static constexpr bool V_is_repeat    	= (a == NLAlgorithm::repeat);
	template<NLAlgorithm a> static constexpr bool V_is_map       	= (a == NLAlgorithm::map);
	template<NLAlgorithm a> static constexpr bool V_is_fold      	= (a == NLAlgorithm::fold);
	template<NLAlgorithm a> static constexpr bool V_is_find_first	= (a == NLAlgorithm::find_first);
	template<NLAlgorithm a> static constexpr bool V_is_find_all  	= (a == NLAlgorithm::find_all);
	template<NLAlgorithm a> static constexpr bool V_is_zip       	= (a == NLAlgorithm::zip);
	template<NLAlgorithm a> static constexpr bool V_is_fasten    	= (a == NLAlgorithm::fasten);
	template<NLAlgorithm a> static constexpr bool V_is_glide     	= (a == NLAlgorithm::glide);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// members:

/***********************************************************************************************************************/

	enum struct NLMember
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

	template<NLMember m> static constexpr bool V_is_out		= (m == NLMember::out);
	template<NLMember m> static constexpr bool V_is_in		= (m == NLMember::in);
	template<NLMember m> static constexpr bool V_is_car_in		= (m == NLMember::car_in);
	template<NLMember m> static constexpr bool V_is_cdr_in		= (m == NLMember::cdr_in);
	template<NLMember m> static constexpr bool V_is_end		= (m == NLMember::end);
	template<NLMember m> static constexpr bool V_is_aux		= (m == NLMember::aux);
	template<NLMember m> static constexpr bool V_is_msg		= (m == NLMember::msg);

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

// algorithm filters (level 1):

/***********************************************************************************************************************/

	template<NLMember... Ms>			struct _map		{ };

	template<typename T>				struct _type		{ };
	template<Interval V>				struct _ival		{ };
	template<Axis V>				struct _axis		{ };
	template<auto UFunc>				struct _peek		{ };

	template<auto... Members>			struct _members		{ };
	template<typename... Attrs>			struct _attrs		{ };
	template<typename... Specs>			struct _specs		{ };

	template<auto UFunc, typename Args>		struct _value		{ };
	template<auto UFunc, typename Args>		struct _next		{ };
	template<auto UFunc, typename Args>		struct _prev		{ };
	template<auto UFunc, typename Args>		struct _test		{ };
	template<auto UFunc, typename Args>		struct _apply		{ };
	template<auto UFunc, typename Args>		struct _assign		{ };

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// near linear filters (level 2):

/***********************************************************************************************************************/

	template<typename...> struct _members_specification;

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

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// common configurations:

/***********************************************************************************************************************/

private:

	using uchar = unsigned char;
	using schar = signed char;

public:

// next:

	static constexpr auto increment = function_module::template U_add_by<uchar{1}>;

	template<auto sign_member_x>
	using increment_arg = _sign_facade
	<
		sign_arg_as_ref<sign_member_x>,
		sign_arg_as_cref<sign_member_x>
	>;

// prev:

	static constexpr auto decrement = function_module::template U_add_by<schar{-1}>;

	template<auto sign_member_x>
	using decrement_arg = _sign_facade
	<
		sign_arg_as_ref<sign_member_x>,
		sign_arg_as_cref<sign_member_x>
	>;

// is end:

	static constexpr auto is_end = function_module::U_equal;

	template<auto sign_member_x, auto sign_member_y>
	using is_end_args = _sign_facade
	<
		sign_arg_as_cref<sign_member_x>,
		sign_arg_as_cref<sign_member_y>
	>;

// is peek end:

	struct S_is_peek_end
	{
		template<typename T, typename U>
		static constexpr bool result(T v1, U v2) { return ((v1+1) == v2); }
	};

	static constexpr auto U_is_peek_end = functor_module::template U_type_T<S_is_peek_end>;
	static constexpr auto is_peek_end = U_is_peek_end;

// value:

	static constexpr auto ignore = function_module::U_id;

	using ignore_arg = _sign_facade<void>;

// return:

	static constexpr auto select = function_module::U_id;

	template<auto sign_member_x>
	using select_arg = _sign_facade
	<
		sign_arg_as_ref<sign_member_x>,
		sign_arg_as_cref<sign_member_x>
	>;

/***********************************************************************************************************************/

// map:

	template<auto sign_member_x, auto sign_member_y>
	using default_map_args = _sign_facade
	<
		sign_arg_as_deref<sign_member_x>,
		sign_arg_as_cderef<sign_member_y>
	>;

	template<auto sign_member_x, auto sign_member_y>
	using range_map_args = _sign_facade
	<
		sign_arg_as_deref<sign_member_x>,
		sign_arg_as_cref<sign_member_y>
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

