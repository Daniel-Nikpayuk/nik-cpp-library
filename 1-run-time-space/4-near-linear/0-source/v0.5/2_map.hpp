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

// spec:

	template<typename, typename, typename, typename> class map_specification;

	template
	<
		typename OutType, typename OutAttr, typename OutIval, typename OutNext,
		typename InType, typename InAttr, typename InIval,
			typename InAxis, typename InVal, typename InNext, typename InPeek,
		typename EndType, typename EndAttr, typename EndNext, typename EndPrev,

		typename ActFunction
	>
	class map_specification
	<
		_out      < OutType , OutAttr , OutIval , OutNext                           >,
		_in       < InType  , InAttr  , InIval  , InAxis  , InVal , InNext , InPeek >,
		_end      < EndType , EndAttr , EndNext , EndPrev                           >,

		_function < ActFunction                                                     >
	>
	{
		public:

			using out_type					= typename OutType::type;
			using in_type					= typename InType::type;
			using end_type					= typename EndType::type;

			using return_type				= out_type;
			static constexpr auto return_value		= out_ref; // ?

		private:

				// "deref" is dependent on the input (it might not even deref)

			static constexpr auto out_ref			= 
			static constexpr auto out_imm_ref		= 
			static constexpr auto out_deref			= 
			static constexpr auto out_inc			= 
			static constexpr bool out_is_left_open		= 
			static constexpr bool out_is_right_open		= 
			static constexpr bool out_is_right_closed	= 

			static constexpr auto in_ref			= 
			static constexpr auto in_imm_ref		= 
			static constexpr auto in_imm_deref		= 
			static constexpr auto in_inc			= 
			static constexpr bool in_is_left_open		= 
			static constexpr bool in_is_right_open		= 
			static constexpr bool in_is_right_closed	= 

			static constexpr auto end_ref			= 
			static constexpr auto end_imm_ref		= 
			static constexpr auto end_inc			= 
			static constexpr auto end_dec			= 

			static constexpr bool is_bidirectional_last	= 
			static constexpr auto is_equal			= function_module::template equal<>;
			static constexpr auto act_f			= ActFunction::value;

		public:

			using signature					= one_cycle
									<
										out_object < obj_type<out_obj> >,
										in_object  < obj_type<in_obj>  >,
										end_object < obj_type<end_obj> >
									>;

			// map:

				//     ival meet: (out is right closed) or (in is right closed) ?
				// out ival meet: (out is right open) and (in is right closed) ?
				//  in ival meet: (in is right open) and (out is right closed) ?

			static constexpr auto out_next			= assign<out_ref, out_inc, out_imm_ref>;
			static constexpr bool is_out_next_before	= out_is_left_open;
			static constexpr bool is_out_next_after		= out_is_right_open && in_is_right_closed;

			static constexpr auto in_next			= assign<in_ref, in_inc, in_imm_ref>;
			static constexpr bool is_in_next_before		= in_is_left_open;
			static constexpr bool is_in_next_after		= in_is_right_open && out_is_right_closed;

			static constexpr auto end_next			= assign<end_ref, end_inc, end_imm_ref>;
			static constexpr bool is_end_next_after		= is_bidirectional_last;

			static constexpr auto end_prevous		= assign<end_ref, end_dec, end_imm_ref>;
			static constexpr bool is_end_previous_before	= is_bidirectional_last;

			static constexpr auto loop_predicate		= test<is_equal, in_imm_ref, end_imm_ref>;
			static constexpr auto loop_break		= _id_;

			static constexpr auto act_function		= assign<out_deref, act_f, in_imm_deref>;
			static constexpr bool is_act_function_after	= out_is_right_closed || in_is_right_closed;
	};

/*
	// out:

	//	using out_attr				= typename OutAttr::type;

	//	using out_obj				= out_object		< out_type , out_attr		>;
	//	using out_ref_obj			= obj_to_direct		< out_obj			>;
	//	using out_imm_ref_obj			= obj_to_immutable	< dout_obj			>;

	//	static constexpr Interval out_ival	= OutIval::value;
	//	static constexpr auto out_cdr		= iterate<OutCdr::value, out_type>;

	// in:

	//	using in_attr				= typename InAttr::type;

	//	using in_obj				= in_object		< in_type	, in_attr	>;
	//	using din_obj				= obj_to_direct		< in_obj			>;
	//	using cin_obj				= obj_to_immutable	< in_obj			>;
	//	using cdin_obj				= obj_to_immutable	< din_obj			>;

	//	static constexpr Interval in_ival	= InIval::value;
	//	static constexpr Axis in_axis		= InAxis::value;
	//	static constexpr auto in_car		= InCar::value;
	//	static constexpr auto in_cdr		= iterate<InCdr::value, in_type>;
	//	static constexpr auto in_peek		= iterate<InPeek::value, in_type>;

	// end:

	//	using end_attr				= typename EndAttr::type;

	//	using end_obj				= end_object		< end_type	, end_attr	>;
	//	using dend_obj				= obj_to_direct		< end_obj			>;
	//	using cdend_obj				= obj_to_immutable	< dend_obj			>;

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

