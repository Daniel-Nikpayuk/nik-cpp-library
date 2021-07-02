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

// one cycle source:

	// This component provides "inductor" specifications for the core one cycle algorithms.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// loop specs:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// precycle specs:

/***********************************************************************************************************************/

// before loop:

	template<bool predicate, auto next_f>
	static constexpr auto boolean_before_loop = lift
	<
		boolean_module::template V_if_then_else_VxV
		<
			predicate, next_f, _id_
		>
	>;

/***********************************************************************************************************************/

// precycle:

	template<auto... cs>
	static constexpr auto precycle = opt_chain_endopose<cs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// cycle specs:

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
/***********************************************************************************************************************/

// postcycle specs:

/***********************************************************************************************************************/

// after loop:

	template<bool predicate, auto act_combine_f>
	static constexpr auto boolean_after_loop = lift
	<
		boolean_module::template V_if_then_else_VxV
		<
			predicate, act_combine_f, _id_
		>
	>;

/***********************************************************************************************************************/

// postcycle:

	template<auto... cs>
	static constexpr auto postcycle = opt_chain_endopose<cs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// operator specs:

/***********************************************************************************************************************/

// signature:

	template<typename Spec> using signature_				= typename Spec::signature;

/***********************************************************************************************************************/

// out:

	template<typename Spec> using out_type_					= typename Spec::out_type;

	template<typename Spec> static constexpr bool is_out_next_before_	= Spec::is_out_next_before;
	template<typename Spec> static constexpr bool is_out_next_after_	= Spec::is_out_next_after;
	template<typename Spec> static constexpr auto out_next_			= Spec::out_next;

/***********************************************************************************************************************/

// in:

	template<typename Spec> using in_type_					= typename Spec::in_type;

	template<typename Spec> static constexpr bool is_in_next_before_	= Spec::is_in_next_before;
	template<typename Spec> static constexpr bool is_in_next_after_		= Spec::is_in_next_after;
	template<typename Spec> static constexpr auto in_next_			= Spec::in_next;

/***********************************************************************************************************************/

// car in:

	template<typename Spec> using car_in_type_				= typename Spec::car_in_type;

	template<typename Spec> static constexpr bool is_car_in_next_before_	= Spec::is_car_in_next_before;
	template<typename Spec> static constexpr bool is_car_in_next_after_	= Spec::is_car_in_next_after;
	template<typename Spec> static constexpr auto car_in_next_		= Spec::car_in_next;

/***********************************************************************************************************************/

// cdr in:

	template<typename Spec> using cdr_in_type_				= typename Spec::cdr_in_type;

	template<typename Spec> static constexpr bool is_cdr_in_next_before_	= Spec::is_cdr_in_next_before;
	template<typename Spec> static constexpr bool is_cdr_in_next_after_	= Spec::is_cdr_in_next_after;
	template<typename Spec> static constexpr auto cdr_in_next_		= Spec::cdr_in_next;

/***********************************************************************************************************************/

// end:

	template<typename Spec> using end_type_					= typename Spec::end_type;

	template<typename Spec> static constexpr bool is_end_prev_before_	= Spec::is_end_previous_before;
	template<typename Spec> static constexpr auto end_prev_			= Spec::end_previous;

	template<typename Spec> static constexpr bool is_end_next_after_	= Spec::is_end_next_after;
	template<typename Spec> static constexpr auto end_next_			= Spec::end_next;

/***********************************************************************************************************************/

// aux:

//	template<typename Spec> using aux_type_					= typename Spec::aux_type;

/***********************************************************************************************************************/

// msg:

//	template<typename Spec> using msg_type_					= typename Spec::msg_type;

/***********************************************************************************************************************/

// return:

	template<typename Spec> using return_type_				= typename Spec::return_type;

	template<typename Spec> static constexpr auto return_value_		= Spec::return_value;

/***********************************************************************************************************************/

// loop:

	template<typename Spec> static constexpr bool is_loop_break_after_	= Spec::is_loop_break_after;
	template<typename Spec> static constexpr auto loop_pred_		= Spec::loop_predicate;
	template<typename Spec> static constexpr auto loop_break_		= Spec::loop_break;

/***********************************************************************************************************************/

// value:

	template<typename Spec> static constexpr auto value_pred_		= Spec::value_predicate;

/***********************************************************************************************************************/

// act:

	template<typename Spec> static constexpr auto act_pred_			= Spec::act_predicate;
	template<typename Spec> static constexpr auto act_break_		= Spec::act_break;

	template<typename Spec> static constexpr bool is_act_func_after_	= Spec::is_act_function_after;
	template<typename Spec> static constexpr auto act_func_			= Spec::act_function;

/***********************************************************************************************************************/

// combine:

	template<typename Spec> static constexpr bool is_combine_func_after_	= Spec::is_combine_function_after;
	template<typename Spec> static constexpr auto combine_func_		= Spec::combine_function;

/***********************************************************************************************************************/

// post:

	template<typename Spec> static constexpr bool is_post_func_after_	= Spec::is_post_function_after;
	template<typename Spec> static constexpr auto post_func_		= Spec::post_function;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// repeat:

/***********************************************************************************************************************/

// spec:

private:

	template<typename Spec>
	static constexpr auto one_cycle_repeat = opt_do_chain_compose
	<
		precycle
		<
			boolean_before_loop < is_out_next_before_<Spec> , out_next_<Spec>   >

		>, cycle
		<
			stem_before_value   < loop_pred_<Spec>          , loop_break_<Spec> >,
			before_act          < act_func_<Spec>                               >,
			before_next         < out_next_<Spec>                               >

		>, postcycle
		<
			boolean_after_loop  < is_act_func_after_<Spec>  , act_func_<Spec>   >
		>
	>;

/***********************************************************************************************************************/

// generic:

public:

	template<typename Spec>
	return_type_<Spec> repeat(out_type_<Spec> b, end_type_<Spec> e, in_type_<Spec> c)
	{
		auto s = signature_<Spec>(b, c, e);

		return return_value_<Spec>(one_cycle_repeat<Spec>(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// map:

/***********************************************************************************************************************/

// spec:

private:

	template<typename Spec>
	static constexpr auto one_cycle_map = opt_do_chain_compose
	<
		precycle
		<
			boolean_before_loop < is_end_prev_before_<Spec> , end_prev_<Spec>   >,
			boolean_before_loop < is_out_next_before_<Spec> , out_next_<Spec>   >,
			boolean_before_loop < is_in_next_before_<Spec>  , in_next_<Spec>    >

		>, cycle
		<
			stem_before_value   < loop_pred_<Spec>          , loop_break_<Spec> >,
			before_act          < act_func_<Spec>                               >,
			before_next         < out_next_<Spec>                               >,
			before_next         < in_next_<Spec>                                >

		>, postcycle
		<
			boolean_after_loop  < is_act_func_after_<Spec>  , act_func_<Spec>   >,
			boolean_after_loop  < is_out_next_after_<Spec>  , out_next_<Spec>   >,
			boolean_after_loop  < is_in_next_after_<Spec>   , in_next_<Spec>    >,
			boolean_after_loop  < is_end_next_after_<Spec>  , end_next_<Spec>   >
		>
	>;

/***********************************************************************************************************************/

// generic:

public:

	template<typename Spec>
	static constexpr return_type_<Spec> map(out_type_<Spec> o, in_type_<Spec> i, end_type_<Spec> e)
	{
		auto s = signature_<Spec>(o, i, e);

		return return_value_<Spec>(one_cycle_map<Spec>(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// fold:

/***********************************************************************************************************************/

// spec:

private:

	template<typename Spec>
	static constexpr auto one_cycle_fold = opt_do_chain_compose
	<
		precycle
		<
			boolean_before_loop < is_in_next_before_<Spec>     , in_next_<Spec>      >

		>, cycle
		<
			stem_before_value   < loop_pred_<Spec>             , loop_break_<Spec>   >,
			before_combine      < combine_func_<Spec>                                >,
			before_next         < in_next_<Spec>                                     >

		>, postcycle
		<
			boolean_after_loop  < is_combine_func_after_<Spec> , combine_func_<Spec> >
		>
	>;

/***********************************************************************************************************************/

// generic:

public:

	template<typename Spec>
	return_type_<Spec> fold(out_type_<Spec> o, in_type_<Spec> i, end_type_<Spec> e)
	{
		auto s = signature_<Spec>(o, i, e);

		return return_value_<Spec>(one_cycle_fold<Spec>(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// find:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// find first:

/***********************************************************************************************************************/

// spec:

private:

	template<typename Spec>
	static constexpr auto one_cycle_find_first = opt_do_chain_compose
	<
		precycle
		<
			boolean_before_loop < is_in_next_before_<Spec>   , in_next_<Spec>    >

		>, cycle
		<
			stem_before_value   < loop_pred_<Spec>           , loop_break_<Spec> >,
			stem_before_act     < act_pred_<Spec>            , act_break_<Spec>  >,
			before_next         < in_next_<Spec>                                 >

		>, postcycle
		<
			costem_after_loop   < is_loop_break_after_<Spec> , loop_break_<Spec> >,
			boolean_after_loop  < is_post_func_after_<Spec>  , post_func_<Spec>  >
		>
	>;

/***********************************************************************************************************************/

// generic:

public:

	template<typename Spec>
	return_type_<Spec> find_first(in_type_<Spec> i, in_type_<Spec> e)
	{
		auto s = signature_<Spec>(e, i, e);

		return return_value_<Spec>(one_cycle_find_first<Spec>(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// find all:

/***********************************************************************************************************************/

// spec:

private:

	template<typename Spec>
	static constexpr auto one_cycle_find_all = opt_do_chain_compose
	<
		precycle
		<
			boolean_before_loop < is_end_prev_before_<Spec> , end_prev_<Spec>   >,
			boolean_before_loop < is_out_next_before_<Spec> , out_next_<Spec>   >,
			boolean_before_loop < is_in_next_before_<Spec>  , in_next_<Spec>    >

		>, cycle
		<
			stem_before_value   < loop_pred_<Spec>          , loop_break_<Spec> >,
			before_value        < value_pred_<Spec>                             >,
			distem_before_act   < act_pred_<Spec>           , act_func_<Spec>   >,
			distem_before_next  < act_pred_<Spec>           , out_next_<Spec>   >,
			before_next         < in_next_<Spec>                                >

		>, postcycle
		<
			boolean_after_loop  < is_post_func_after_<Spec> , post_func_<Spec>  >,
			boolean_after_loop  < is_out_next_after_<Spec>  , out_next_<Spec>   >,
			boolean_after_loop  < is_in_next_after_<Spec>   , in_next_<Spec>    >,
			boolean_after_loop  < is_end_next_after_<Spec>  , end_next_<Spec>   >
		>
	>;

/***********************************************************************************************************************/

// generic:

public:

	template<typename Spec>
	return_type_<Spec> find_all(out_type_<Spec> o, in_type_<Spec> i, end_type_<Spec> e)
	{
		auto s = signature_<Spec>(o, i, e, false);

		return return_value_<Spec>(one_cycle_find_all<Spec>(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// zip (bimap):

/***********************************************************************************************************************/

// spec:

private:

	template<typename Spec>
	static constexpr auto one_cycle_zip = opt_do_chain_compose
	<
		precycle
		<
			boolean_before_loop < is_end_prev_before_<Spec>    , end_prev_<Spec>    >,
			boolean_before_loop < is_out_next_before_<Spec>    , out_next_<Spec>    >,
			boolean_before_loop < is_car_in_next_before_<Spec> , car_in_next_<Spec> >,
			boolean_before_loop < is_cdr_in_next_before_<Spec> , cdr_in_next_<Spec> >

		>, cycle
		<
			stem_before_value   < loop_pred_<Spec>             , loop_break_<Spec>  >,
			before_act          < act_func_<Spec>                                   >,
			before_next         < out_next_<Spec>                                   >,
			before_next         < car_in_next_<Spec>                                >,
			before_next         < cdr_in_next_<Spec>                                >

		>, postcycle
		<
			boolean_after_loop  < is_act_func_after_<Spec>     , act_func_<Spec>    >,
			boolean_after_loop  < is_out_next_after_<Spec>     , out_next_<Spec>    >,
			boolean_after_loop  < is_car_in_next_after_<Spec>  , car_in_next_<Spec> >,
			boolean_after_loop  < is_cdr_in_next_after_<Spec>  , cdr_in_next_<Spec> >,
			boolean_after_loop  < is_end_next_after_<Spec>     , end_next_<Spec>    >
		>
	>;

/***********************************************************************************************************************/

// generic:

public:

	template<typename Spec>
	return_type_<Spec> zip(out_type_<Spec> o, car_in_type_<Spec> i1, cdr_in_type_<Spec> i2, end_type_<Spec> e2)
	{
		auto s = signature_<Spec>(o, i1, i2, e2);

		return return_value_<Spec>(one_cycle_zip<Spec>(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// fasten:

/***********************************************************************************************************************/

// spec:

private:

	template<typename Spec>
	static constexpr auto one_cycle_fasten = opt_do_chain_compose
	<
		precycle
		<
			boolean_before_loop < is_end_prev_before_<Spec>    , end_prev_<Spec>     >,
			boolean_before_loop < is_out_next_before_<Spec>    , out_next_<Spec>     >,
			boolean_before_loop < is_car_in_next_before_<Spec> , car_in_next_<Spec>  >,
			boolean_before_loop < is_cdr_in_next_before_<Spec> , cdr_in_next_<Spec>  >

		>, cycle
		<
			stem_before_value   < loop_pred_<Spec>             , loop_break_<Spec>   >,
			before_act          < act_func_<Spec>                                    >,
			before_combine      < combine_func_<Spec>                                >,
			before_next         < out_next_<Spec>                                    >,
			before_next         < car_in_next_<Spec>                                 >,
			before_next         < cdr_in_next_<Spec>                                 >

		>, postcycle
		<
			boolean_after_loop  < is_act_func_after_<Spec>     , act_func_<Spec>     >,
			boolean_after_loop  < is_combine_func_after_<Spec> , combine_func_<Spec> >,
			boolean_after_loop  < is_out_next_after_<Spec>     , out_next_<Spec>     >,
			boolean_after_loop  < is_car_in_next_after_<Spec>  , car_in_next_<Spec>  >,
			boolean_after_loop  < is_cdr_in_next_after_<Spec>  , cdr_in_next_<Spec>  >,
			boolean_after_loop  < is_end_next_after_<Spec>     , end_next_<Spec>     >
		>
	>;

/***********************************************************************************************************************/

// generic:

public:

	template<typename Spec>
	return_type_<Spec> fasten(out_type_<Spec> o, car_in_type_<Spec> i1, cdr_in_type_<Spec> i2, end_type_<Spec> e2)
	{
		auto s = signature_<Spec>(o, i1, i2, e2);

		return return_value_<Spec>(one_cycle_fasten<Spec>(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// glide (bifold):

/***********************************************************************************************************************/

// spec:

private:

	template<typename Spec>
	static constexpr auto one_cycle_glide = opt_do_chain_compose
	<
		precycle
		<
			boolean_before_loop < is_end_prev_before_<Spec>    , end_prev_<Spec>     >,
			boolean_before_loop < is_car_in_next_before_<Spec> , car_in_next_<Spec>  >,
			boolean_before_loop < is_cdr_in_next_before_<Spec> , cdr_in_next_<Spec>  >

		>, cycle
		<
			stem_before_value   < loop_pred_<Spec>             , loop_break_<Spec>   >,
			before_act          < act_func_<Spec>                                    >,
			before_combine      < combine_func_<Spec>                                >,
			before_next         < car_in_next_<Spec>                                 >,
			before_next         < cdr_in_next_<Spec>                                 >

		>, postcycle
		<
			boolean_after_loop  < is_act_func_after_<Spec>     , act_func_<Spec>     >,
			boolean_after_loop  < is_combine_func_after_<Spec> , combine_func_<Spec> >,
			boolean_after_loop  < is_car_in_next_after_<Spec>  , car_in_next_<Spec>  >,
			boolean_after_loop  < is_cdr_in_next_after_<Spec>  , cdr_in_next_<Spec>  >,
			boolean_after_loop  < is_end_next_after_<Spec>     , end_next_<Spec>     >
		>
	>;

/***********************************************************************************************************************/

// generic:

public:

	template<typename Spec>
	return_type_<Spec> glide(out_type_<Spec> o, car_in_type_<Spec> i1, cdr_in_type_<Spec> i2, end_type_<Spec> e2)
	{
		auto s = signature_<Spec>(o, i1, i2, e2);

		return return_value_<Spec>(one_cycle_glide<Spec>(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

