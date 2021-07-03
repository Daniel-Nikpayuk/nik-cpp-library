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

// define macros:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// one cycle accessors:

/***********************************************************************************************************************/

// out, end:

	#define NIK_DECLARE_OUT_END_ONE_CYCLE_ACCESSOR(_name_, _arg_)							\
															\
		template												\
		<													\
			typename OutType,										\
			typename EndType										\
		>													\
		static constexpr auto & _name_										\
		(													\
			one_cycle_signature										\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >									\
															\
			> & _arg_											\
		)

	#define NIK_DECLARE_OUT_END_ONE_CYCLE_FRIEND(_name_)								\
															\
		friend auto & module::_name_										\
		<													\
			OutType,											\
			EndType												\
		>													\
		(													\
			one_cycle_signature										\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >									\
			> &												\
		)

/***********************************************************************************************************************/

// out, in, end:

	#define NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(_name_, _arg_)						\
															\
		template												\
		<													\
			typename OutType,										\
			typename InType,										\
			typename EndType										\
		>													\
		static constexpr auto & _name_										\
		(													\
			one_cycle_signature										\
			<												\
				_out_object < OutType >,								\
				_in_object  < InType  >,								\
				_end_object < EndType >									\
															\
			> & _arg_											\
		)

	#define NIK_DECLARE_OUT_IN_END_ONE_CYCLE_FRIEND(_name_)								\
															\
		friend auto & module::_name_										\
		<													\
			OutType,											\
			InType,												\
			EndType												\
		>													\
		(													\
			one_cycle_signature										\
			<												\
				_out_object < OutType >,								\
				_in_object  < InType  >,								\
				_end_object < EndType >									\
			> &												\
		)

/***********************************************************************************************************************/

// out, car in, cdr in, end:

	#define NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR(_name_, _arg_)					\
															\
		template												\
		<													\
			typename OutType,										\
			typename CarInType,										\
			typename CdrInType,										\
			typename EndType										\
		>													\
		static constexpr auto & _name_										\
		(													\
			one_cycle_signature										\
			<												\
				_out_object    < OutType   >,								\
				_car_in_object < CarInType >,								\
				_cdr_in_object < CdrInType >,								\
				_end_object    < EndType   >								\
															\
			> & _arg_											\
		)

	#define NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND(_name_)						\
															\
		friend auto & module::_name_										\
		<													\
			OutType,											\
			CarInType,											\
			CdrInType,											\
			EndType												\
		>													\
		(													\
			one_cycle_signature										\
			<												\
				_out_object    < OutType   >,								\
				_car_in_object < CarInType >,								\
				_cdr_in_object < CdrInType >,								\
				_end_object    < EndType   >								\
			> &												\
		)

/***********************************************************************************************************************/

// out, end, msg:

	#define NIK_DECLARE_OUT_END_MSG_ONE_CYCLE_ACCESSOR(_name_, _arg_)						\
															\
		template												\
		<													\
			typename OutType,										\
			typename EndType,										\
			typename MsgType										\
		>													\
		static constexpr auto & _name_										\
		(													\
			one_cycle_signature										\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >,								\
				_msg_object < MsgType >									\
															\
			> & _arg_											\
		)

	#define NIK_DECLARE_OUT_END_MSG_ONE_CYCLE_FRIEND(_name_)							\
															\
		friend auto & module::_name_										\
		<													\
			OutType,											\
			EndType,											\
			MsgType												\
		>													\
		(													\
			one_cycle_signature										\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >,								\
				_msg_object < MsgType >									\
			> &												\
		)

/***********************************************************************************************************************/

// out, in, end, msg:

	#define NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR(_name_, _arg_)						\
															\
		template												\
		<													\
			typename OutType,										\
			typename InType,										\
			typename EndType,										\
			typename MsgType										\
		>													\
		static constexpr auto & _name_										\
		(													\
			one_cycle_signature										\
			<												\
				_out_object < OutType >,								\
				_in_object  < InType  >,								\
				_end_object < EndType >,								\
				_msg_object < MsgType >									\
															\
			> & _arg_											\
		)

	#define NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND(_name_)							\
															\
		friend auto & module::_name_										\
		<													\
			OutType,											\
			InType,												\
			EndType,											\
			MsgType												\
		>													\
		(													\
			one_cycle_signature										\
			<												\
				_out_object < OutType >,								\
				_in_object  < InType  >,								\
				_end_object < EndType >,								\
				_msg_object < MsgType >									\
			> &												\
		)

/***********************************************************************************************************************/

// out, car in, cdr in, end, msg:

	#define NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR(_name_, _arg_)					\
															\
		template												\
		<													\
			typename OutType,										\
			typename CarInType,										\
			typename CdrInType,										\
			typename EndType,										\
			typename MsgType										\
		>													\
		static constexpr auto & _name_										\
		(													\
			one_cycle_signature										\
			<												\
				_out_object    < OutType   >,								\
				_car_in_object < CarInType >,								\
				_cdr_in_object < CdrInType >,								\
				_end_object    < EndType   >,								\
				_msg_object    < MsgType   >								\
															\
			> & _arg_											\
		)

	#define NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND(_name_)						\
															\
		friend auto & module::_name_										\
		<													\
			OutType,											\
			CarInType,											\
			CdrInType,											\
			EndType,											\
			MsgType												\
		>													\
		(													\
			one_cycle_signature										\
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

	#define NIK_DECLARE_OUT_END_AUX_ONE_CYCLE_ACCESSOR(_name_, _arg_)						\
															\
		template												\
		<													\
			typename OutType,										\
			typename EndType,										\
			typename AuxType										\
		>													\
		static constexpr auto & _name_										\
		(													\
			one_cycle_signature										\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >,								\
				_aux_object < AuxType >									\
															\
			> & _arg_											\
		)

	#define NIK_DECLARE_OUT_END_AUX_ONE_CYCLE_FRIEND(_name_)							\
															\
		friend auto & module::_name_										\
		<													\
			OutType,											\
			EndType,											\
			AuxType												\
		>													\
		(													\
			one_cycle_signature										\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >,								\
				_aux_object < AuxType >									\
			> &												\
		)

/***********************************************************************************************************************/

// out, in, end, aux:

	#define NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR(_name_, _arg_)						\
															\
		template												\
		<													\
			typename OutType,										\
			typename InType,										\
			typename EndType,										\
			typename AuxType										\
		>													\
		static constexpr auto & _name_										\
		(													\
			one_cycle_signature										\
			<												\
				_out_object < OutType >,								\
				_in_object  < InType  >,								\
				_end_object < EndType >,								\
				_aux_object < AuxType >									\
															\
			> & _arg_											\
		)

	#define NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND(_name_)							\
															\
		friend auto & module::_name_										\
		<													\
			OutType,											\
			InType,												\
			EndType,											\
			AuxType												\
		>													\
		(													\
			one_cycle_signature										\
			<												\
				_out_object < OutType >,								\
				_in_object  < InType  >,								\
				_end_object < EndType >,								\
				_aux_object < AuxType >									\
			> &												\
		)

/***********************************************************************************************************************/

// out, car in, cdr in, end, aux:

	#define NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR(_name_, _arg_)					\
															\
		template												\
		<													\
			typename OutType,										\
			typename CarInType,										\
			typename CdrInType,										\
			typename EndType,										\
			typename AuxType										\
		>													\
		static constexpr auto & _name_										\
		(													\
			one_cycle_signature										\
			<												\
				_out_object    < OutType   >,								\
				_car_in_object < CarInType >,								\
				_cdr_in_object < CdrInType >,								\
				_end_object    < EndType   >,								\
				_aux_object    < AuxType   >								\
															\
			> & _arg_											\
		)

	#define NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND(_name_)						\
															\
		friend auto & module::_name_										\
		<													\
			OutType,											\
			CarInType,											\
			CdrInType,											\
			EndType,											\
			AuxType												\
		>													\
		(													\
			one_cycle_signature										\
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

	#define NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR(_name_, _arg_)						\
															\
		template												\
		<													\
			typename OutType,										\
			typename EndType,										\
			typename AuxType,										\
			typename MsgType										\
		>													\
		static constexpr auto & _name_										\
		(													\
			one_cycle_signature										\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >,								\
				_aux_object < AuxType >,								\
				_msg_object < MsgType >									\
															\
			> & _arg_											\
		)

	#define NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND(_name_)							\
															\
		friend auto & module::_name_										\
		<													\
			OutType,											\
			EndType,											\
			AuxType,											\
			MsgType												\
		>													\
		(													\
			one_cycle_signature										\
			<												\
				_out_object < OutType >,								\
				_end_object < EndType >,								\
				_aux_object < AuxType >,								\
				_msg_object < MsgType >									\
			> &												\
		)

/***********************************************************************************************************************/

// out, in, end, aux, msg:

	#define NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(_name_, _arg_)					\
															\
		template												\
		<													\
			typename OutType,										\
			typename InType,										\
			typename EndType,										\
			typename AuxType,										\
			typename MsgType										\
		>													\
		static constexpr auto & _name_										\
		(													\
			one_cycle_signature										\
			<												\
				_out_object < OutType >,								\
				_in_object  < InType  >,								\
				_end_object < EndType >,								\
				_aux_object < AuxType >,								\
				_msg_object < MsgType >									\
															\
			> & _arg_											\
		)

	#define NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(_name_)							\
															\
		friend auto & module::_name_										\
		<													\
			OutType,											\
			InType,												\
			EndType,											\
			AuxType,											\
			MsgType												\
		>													\
		(													\
			one_cycle_signature										\
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

	#define NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(_name_, _arg_)				\
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
		static constexpr auto & _name_										\
		(													\
			one_cycle_signature										\
			<												\
				_out_object    < OutType   >,								\
				_car_in_object < CarInType >,								\
				_cdr_in_object < CdrInType >,								\
				_end_object    < EndType   >,								\
				_aux_object    < AuxType   >,								\
				_msg_object    < MsgType   >								\
															\
			> & _arg_											\
		)

	#define NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(_name_)					\
															\
		friend auto & module::_name_										\
		<													\
			OutType,											\
			CarInType,											\
			CdrInType,											\
			EndType,											\
			AuxType,											\
			MsgType												\
		>													\
		(													\
			one_cycle_signature										\
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

