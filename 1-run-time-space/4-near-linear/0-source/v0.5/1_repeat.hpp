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

// repeat source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// spec:

private:

//	template<typename Spec>
//	static constexpr auto one_cycle_repeat = opt_do_chain_compose
//	<
//		precycle
//		<
//			boolean_before_loop < out_is_left_open_<Spec>    , out_next_<Spec>   >
//	
//		>, cycle
//		<
//			stem_before_value   < loop_pred_<Spec>           , loop_break_<Spec> >,
//			before_act          < act_func_<Spec>                                >,
//			before_next         < out_next_<Spec>                                >
//	
//		>, postcycle
//		<
//			boolean_after_loop  < out_is_right_closed_<Spec> , act_func_<Spec>   >
//		>
//	>;

/***********************************************************************************************************************/

	template
	<
		typename OutObjSpec, typename EndObjSpec, typename InObjSpec, typename ReturnObjSpec,
		typename LoopPredSpec, typename ActFuncSpec, typename OutNextSpec
	>
	class repeat_specification
	{
		// out_type_<Spec>:

			using out_type					= spec_type_<OutObjSpec>;

		// out_ival_<Spec>:

			static constexpr Interval out_interval		= spec_ival_<OutObjSpec>;

		// end_type_<Spec>:

			using end_type					= spec_type_<EndObjSpec>;

		// in_type_<Spec>:

			using in_type					= spec_type_<InObjSpec>;

		// return_type_<Spec>:

			using return_type				= spec_type_<ReturnObjSpec>;

		// signature_<Spec>:

			using signature					= one_cycle_signature
									<
										out_object	< out_type		>,
										in_object	< in_type		>,
										end_object	< end_type		>
									>;

		// loop_pred_<Spec>:

			static constexpr auto loop_predicate		= spec_pred_<LoopPredSpec>;

		// act_func_<Spec>:

			static constexpr auto act_function		= spec_func_<ActFuncSpec>;

		// out_next_<Spec>:

			static constexpr auto out_next			= spec_func_<OutNextSpec>;

		// return_cons_<Spec>:

			static constexpr auto return_constructor	= spec_func_<ReturnObjSpec>;
	};

/***********************************************************************************************************************/

/*
	template
	<
		typename Type,

		auto OutIval		= Interval::closing,
		auto OutCdr		= Direction::forward,

		typename OutNext	= ,

		auto Equal		= equal<Type>,
		auto Assign		= assign<Type, Type>
	>
	using repeat_spec		= repeat_specification
	<
		_out
		<
			_type		< Type*					>,
			_ival		< OutIval				>,

		>, _end
		<
			_type		< Type*					>,

		>, _in
		<
			_type		< Type					>,
		>,

		out_next
		<
			_apply		< OutNext::template apply	, OutNext::assign	>,
			_left		< OutNext::left_func		, OutNext::left_out	>,
			_right		< OutNext::right_func		, OutNext::right_out	>
		>,

		_loop_predicate
		<
			_cast		< one_cycle_bicast	, equal_f	>,
			_left		< _id_			, cdout_obj	>,
			_right		< _id_			, cdend_obj	>
		>,

		_act_function
		<
			_apply		< one_cycle_biapply	, assign_f	>,
			_left		< _id_			, out_obj	>,
			_right		< _id_			, cin_obj	>
		>,

		_return_constructor
		<
			_cast		< one_cycle_f_out			>,
			_arg		< <_id_, dout_obj, signature>;
		>
	>;
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

