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

// define macros source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// one cycle accessors:

/***********************************************************************************************************************/

// member:

	#define NIK_VARIABLE()												\
															\

	#define NIK_IMMUTABLE()												\
															\
		const

	#define NIK_MEMBER_VARIABLE(_name_)										\
															\
		_name_ ## _ref

	#define NIK_MEMBER_IMMUTABLE(_name_)										\
															\
		_name_ ## _cref

/***********************************************************************************************************************/

// out, end:

	#define NIK_DEFINE_OUT_END_ONE_CYCLE_ACCESSOR(_name_, _note_)							\
															\
		template												\
		<													\
			typename OutType,										\
			typename EndType										\
		>													\
		static constexpr NIK_ ## _note_() auto & NIK_MEMBER_ ## _note_(_name_)					\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >									\
															\
			> & s												\
															\
		) { return s._name_; }

	#define NIK_DEFINE_OUT_END_ONE_CYCLE_FRIEND(_name_, _note_)							\
															\
		friend NIK_ ## _note_() auto & module::NIK_MEMBER_ ## _note_(_name_)					\
		<													\
			OutType,											\
			EndType												\
		>													\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >									\
			> &												\
		)

/***********************************************************************************************************************/

// out, in, end:

	#define NIK_DEFINE_OUT_IN_END_ONE_CYCLE_ACCESSOR(_name_, _note_)						\
															\
		template												\
		<													\
			typename OutType,										\
			typename InType,										\
			typename EndType										\
		>													\
		static constexpr NIK_ ## _note_() auto & NIK_MEMBER_ ## _note_(_name_)					\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_in_object  < InType  >,								\
				_end_object < EndType >									\
			> & s												\
															\
		) { return s._name_; }

	#define NIK_DEFINE_OUT_IN_END_ONE_CYCLE_FRIEND(_name_, _note_)							\
															\
		friend NIK_ ## _note_() auto & module::NIK_MEMBER_ ## _note_(_name_)					\
		<													\
			OutType,											\
			InType,												\
			EndType												\
		>													\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_in_object  < InType  >,								\
				_end_object < EndType >									\
			> &												\
															\
		)

/***********************************************************************************************************************/

// out, car in, cdr in, end:

	#define NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR(_name_, _note_)					\
															\
		template												\
		<													\
			typename OutType,										\
			typename CarInType,										\
			typename CdrInType,										\
			typename EndType										\
		>													\
		static constexpr NIK_ ## _note_() auto & NIK_MEMBER_ ## _note_(_name_)					\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object    < OutType   >,								\
				_car_in_object < CarInType >,								\
				_cdr_in_object < CdrInType >,								\
				_end_object    < EndType   >								\
															\
			> & s												\
															\
		) { return s._name_; }

	#define NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND(_name_, _note_)					\
															\
		friend NIK_ ## _note_() auto & module::NIK_MEMBER_ ## _note_(_name_)					\
		<													\
			OutType,											\
			CarInType,											\
			CdrInType,											\
			EndType												\
		>													\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object    < OutType   >,								\
				_car_in_object < CarInType >,								\
				_cdr_in_object < CdrInType >,								\
				_end_object    < EndType   >								\
			> &												\
		)

/***********************************************************************************************************************/

// out, end, msg:

	#define NIK_DEFINE_OUT_END_MSG_ONE_CYCLE_ACCESSOR(_name_, _note_)						\
															\
		template												\
		<													\
			typename OutType,										\
			typename EndType,										\
			typename MsgType										\
		>													\
		static constexpr NIK_ ## _note_() auto & NIK_MEMBER_ ## _note_(_name_)					\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >,								\
				_msg_object < MsgType >									\
															\
			> & s												\
															\
		) { return s._name_; }

	#define NIK_DEFINE_OUT_END_MSG_ONE_CYCLE_FRIEND(_name_, _note_)							\
															\
		friend NIK_ ## _note_() auto & module::NIK_MEMBER_ ## _note_(_name_)					\
		<													\
			OutType,											\
			EndType,											\
			MsgType												\
		>													\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >,								\
				_msg_object < MsgType >									\
			> &												\
		)

/***********************************************************************************************************************/

// out, in, end, msg:

	#define NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR(_name_, _note_)						\
															\
		template												\
		<													\
			typename OutType,										\
			typename InType,										\
			typename EndType,										\
			typename MsgType										\
		>													\
		static constexpr NIK_ ## _note_() auto & NIK_MEMBER_ ## _note_(_name_)					\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_in_object  < InType  >,								\
				_end_object < EndType >,								\
				_msg_object < MsgType >									\
															\
			> & s												\
															\
		) { return s._name_; }

	#define NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND(_name_, _note_)						\
															\
		friend NIK_ ## _note_() auto & module::NIK_MEMBER_ ## _note_(_name_)					\
		<													\
			OutType,											\
			InType,												\
			EndType,											\
			MsgType												\
		>													\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_in_object  < InType  >,								\
				_end_object < EndType >,								\
				_msg_object < MsgType >									\
			> &												\
		)

/***********************************************************************************************************************/

// out, car in, cdr in, end, msg:

	#define NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR(_name_, _note_)					\
															\
		template												\
		<													\
			typename OutType,										\
			typename CarInType,										\
			typename CdrInType,										\
			typename EndType,										\
			typename MsgType										\
		>													\
		static constexpr NIK_ ## _note_() auto & NIK_MEMBER_ ## _note_(_name_)					\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object    < OutType   >,								\
				_car_in_object < CarInType >,								\
				_cdr_in_object < CdrInType >,								\
				_end_object    < EndType   >,								\
				_msg_object    < MsgType   >								\
															\
			> & s												\
															\
		) { return s._name_; }

	#define NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND(_name_, _note_)					\
															\
		friend NIK_ ## _note_() auto & module::NIK_MEMBER_ ## _note_(_name_)					\
		<													\
			OutType,											\
			CarInType,											\
			CdrInType,											\
			EndType,											\
			MsgType												\
		>													\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object    < OutType   >,								\
				_car_in_object < CarInType >,								\
				_cdr_in_object < CdrInType >,								\
				_end_object    < EndType   >,								\
				_msg_object    < MsgType   >								\
			> &												\
		)

/***********************************************************************************************************************/

// out, end, aux:

	#define NIK_DEFINE_OUT_END_AUX_ONE_CYCLE_ACCESSOR(_name_, _note_)						\
															\
		template												\
		<													\
			typename OutType,										\
			typename EndType,										\
			typename AuxType										\
		>													\
		static constexpr NIK_ ## _note_() auto & NIK_MEMBER_ ## _note_(_name_)					\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >,								\
				_aux_object < AuxType >									\
															\
			> & s												\
															\
		) { return s._name_; }

	#define NIK_DEFINE_OUT_END_AUX_ONE_CYCLE_FRIEND(_name_, _note_)							\
															\
		friend NIK_ ## _note_() auto & module::NIK_MEMBER_ ## _note_(_name_)					\
		<													\
			OutType,											\
			EndType,											\
			AuxType												\
		>													\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >,								\
				_aux_object < AuxType >									\
			> &												\
		)

/***********************************************************************************************************************/

// out, in, end, aux:

	#define NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR(_name_, _note_)						\
															\
		template												\
		<													\
			typename OutType,										\
			typename InType,										\
			typename EndType,										\
			typename AuxType										\
		>													\
		static constexpr NIK_ ## _note_() auto & NIK_MEMBER_ ## _note_(_name_)					\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_in_object  < InType  >,								\
				_end_object < EndType >,								\
				_aux_object < AuxType >									\
															\
			> & s												\
															\
		) { return s._name_; }

	#define NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND(_name_, _note_)						\
															\
		friend NIK_ ## _note_() auto & module::NIK_MEMBER_ ## _note_(_name_)					\
		<													\
			OutType,											\
			InType,												\
			EndType,											\
			AuxType												\
		>													\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_in_object  < InType  >,								\
				_end_object < EndType >,								\
				_aux_object < AuxType >									\
			> &												\
		)

/***********************************************************************************************************************/

// out, car in, cdr in, end, aux:

	#define NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR(_name_, _note_)					\
															\
		template												\
		<													\
			typename OutType,										\
			typename CarInType,										\
			typename CdrInType,										\
			typename EndType,										\
			typename AuxType										\
		>													\
		static constexpr NIK_ ## _note_() auto & NIK_MEMBER_ ## _note_(_name_)					\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object    < OutType   >,								\
				_car_in_object < CarInType >,								\
				_cdr_in_object < CdrInType >,								\
				_end_object    < EndType   >,								\
				_aux_object    < AuxType   >								\
															\
			> & s												\
															\
		) { return s._name_; }

	#define NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND(_name_, _note_)					\
															\
		friend NIK_ ## _note_() auto & module::NIK_MEMBER_ ## _note_(_name_)					\
		<													\
			OutType,											\
			CarInType,											\
			CdrInType,											\
			EndType,											\
			AuxType												\
		>													\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object    < OutType   >,								\
				_car_in_object < CarInType >,								\
				_cdr_in_object < CdrInType >,								\
				_end_object    < EndType   >,								\
				_aux_object    < AuxType   >								\
			> &												\
		)

/***********************************************************************************************************************/

// out, end, aux, msg:

	#define NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR(_name_, _note_)						\
															\
		template												\
		<													\
			typename OutType,										\
			typename EndType,										\
			typename AuxType,										\
			typename MsgType										\
		>													\
		static constexpr NIK_ ## _note_() auto & NIK_MEMBER_ ## _note_(_name_)					\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >,								\
				_aux_object < AuxType >,								\
				_msg_object < MsgType >									\
															\
			> & s												\
															\
		) { return s._name_; }

	#define NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND(_name_, _note_)						\
															\
		friend NIK_ ## _note_() auto & module::NIK_MEMBER_ ## _note_(_name_)					\
		<													\
			OutType,											\
			EndType,											\
			AuxType,											\
			MsgType												\
		>													\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >,								\
				_aux_object < AuxType >,								\
				_msg_object < MsgType >									\
			> &												\
		)

/***********************************************************************************************************************/

// out, in, end, aux, msg:

	#define NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(_name_, _note_)					\
															\
		template												\
		<													\
			typename OutType,										\
			typename InType,										\
			typename EndType,										\
			typename AuxType,										\
			typename MsgType										\
		>													\
		static constexpr NIK_ ## _note_() auto & NIK_MEMBER_ ## _note_(_name_)					\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_in_object  < InType  >,								\
				_end_object < EndType >,								\
				_aux_object < AuxType >,								\
				_msg_object < MsgType >									\
															\
			> & s												\
															\
		) { return s._name_; }

	#define NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(_name_, _note_)						\
															\
		friend NIK_ ## _note_() auto & module::NIK_MEMBER_ ## _note_(_name_)					\
		<													\
			OutType,											\
			InType,												\
			EndType,											\
			AuxType,											\
			MsgType												\
		>													\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object < OutType >,								\
				_in_object  < InType  >,								\
				_end_object < EndType >,								\
				_aux_object < AuxType >,								\
				_msg_object < MsgType >									\
			> &												\
		)

/***********************************************************************************************************************/

// out, car in, cdr in, end, aux, msg:

	#define NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(_name_, _note_)				\
															\
		template												\
		<													\
			typename OutType,										\
			typename CarInType,										\
			typename CdrInType,										\
			typename EndType,										\
			typename AuxType,										\
			typename MsgType										\
		>													\
		static constexpr NIK_ ## _note_() auto & NIK_MEMBER_ ## _note_(_name_)					\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object    < OutType   >,								\
				_car_in_object < CarInType >,								\
				_cdr_in_object < CdrInType >,								\
				_end_object    < EndType   >,								\
				_aux_object    < AuxType   >,								\
				_msg_object    < MsgType   >								\
															\
			> & s												\
															\
		) { return s._name_; }

	#define NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(_name_, _note_)				\
															\
		friend NIK_ ## _note_() auto & module::NIK_MEMBER_ ## _note_(_name_)					\
		<													\
			OutType,											\
			CarInType,											\
			CdrInType,											\
			EndType,											\
			AuxType,											\
			MsgType												\
		>													\
		(													\
			NIK_ ## _note_() one_cycle_signature								\
			<												\
				_out_object    < OutType   >,								\
				_car_in_object < CarInType >,								\
				_cdr_in_object < CdrInType >,								\
				_end_object    < EndType   >,								\
				_aux_object    < AuxType   >,								\
				_msg_object    < MsgType   >								\
			> &												\
		)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

