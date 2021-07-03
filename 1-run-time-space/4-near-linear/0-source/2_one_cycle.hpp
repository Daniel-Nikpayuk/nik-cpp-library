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

// one cycle:

//	filters (accessors):

//		i(...) - identity
//		d(...) - dereference

	// temporary:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// objects:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// members:

/***********************************************************************************************************************/

	enum struct OneCycleMember
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

	template<OneCycleMember m> static constexpr bool V_is_out		= (m == OneCycleMember::out);
	template<OneCycleMember m> static constexpr bool V_is_in		= (m == OneCycleMember::in);
	template<OneCycleMember m> static constexpr bool V_is_car_in		= (m == OneCycleMember::car_in);
	template<OneCycleMember m> static constexpr bool V_is_cdr_in		= (m == OneCycleMember::cdr_in);
	template<OneCycleMember m> static constexpr bool V_is_end		= (m == OneCycleMember::end);
	template<OneCycleMember m> static constexpr bool V_is_aux		= (m == OneCycleMember::aux);
	template<OneCycleMember m> static constexpr bool V_is_msg		= (m == OneCycleMember::msg);

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

// signature:

private:

	template<typename...> class one_cycle_signature;

public:

	template<typename... Ts>
	using one_cycle = one_cycle_signature<_object<Ts>...>;

/***********************************************************************************************************************/

// accessors:

	// out:

		template<typename... Ts>
		static constexpr auto & out_ref(one_cycle_signature<_object<Ts>...> & s)
			{ return s.out; }

		template<typename... Ts>
		static constexpr auto & out_deref(one_cycle_signature<_object<Ts>...> & s)
			{ return *s.out; }

	// in:

		template<typename... Ts>
		static constexpr auto & in_ref(one_cycle_signature<_object<Ts>...> & s)
				{ return s.in; }

		template<typename... Ts>
		static constexpr auto & in_deref(one_cycle_signature<_object<Ts>...> & s)
			{ return *s.in; }

	// car in:

		template<typename... Ts>
		static constexpr auto & car_in_ref(one_cycle_signature<_object<Ts>...> & s)
			{ return s.car_in; }

		template<typename... Ts>
		static constexpr auto & car_in_deref(one_cycle_signature<_object<Ts>...> & s)
			{ return *s.car_in; }

	// cdr in:

		template<typename... Ts>
		static constexpr auto & cdr_in_ref(one_cycle_signature<_object<Ts>...> & s)
			{ return s.cdr_in; }

		template<typename... Ts>
		static constexpr auto & cdr_in_deref(one_cycle_signature<_object<Ts>...> & s)
			{ return *s.cdr_in; }

	// end:

		template<typename... Ts>
		static constexpr auto & end_ref(one_cycle_signature<_object<Ts>...> & s)
			{ return s.end; }

		template<typename... Ts>
		static constexpr auto & end_deref(one_cycle_signature<_object<Ts>...> & s)
			{ return *s.end; }

	// aux:

		template<typename... Ts>
		static constexpr auto & aux_ref(one_cycle_signature<_object<Ts>...> & s)
			{ return s.aux; }

		template<typename... Ts>
		static constexpr auto & aux_deref(one_cycle_signature<_object<Ts>...> & s)
			{ return *s.aux; }

	// msg:

		template<typename... Ts>
		static constexpr auto & msg_ref(one_cycle_signature<_object<Ts>...> & s)
			{ return s.msg; }

		template<typename... Ts>
		static constexpr auto & msg_deref(one_cycle_signature<_object<Ts>...> & s)
			{ return *s.msg; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specialization:

/***********************************************************************************************************************/

// out, in, end:

/*
private:

	template
	<
		typename OutType,
		typename InType,
		typename EndType
	>
	class one_cycle_signature
	<
		_object < OutType , Interval::closing >,
		_object < InType  , Interval::closing >,
		_object < EndType , Interval::closing >
	>
	{
		OutType out;
		InType  in;
		EndType end;

		public:

			constexpr one_cycle_signature
			(
				const OutType & _o,
				const InType  & _i,
				const EndType & _e

			) : out(_o), in(_i), end(_e) { }

		// friendship:

			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_ref);
			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_deref);
			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, in_ref);
			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, in_deref);
			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_ref);
			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_deref);
	};
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, end:

private:

	template
	<
		typename OutType,
		typename EndType
	>
	class one_cycle_signature
	<
		_out_object < OutType , Interval::closing >,
		_end_object < EndType , Interval::closing >
	>
	{
		OutType out;
		EndType end;

		public:

			constexpr one_cycle_signature
			(
				const OutType & o,
				const EndType & e

			) : out(o), end(e) { }

		// friendship:

		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_deref);
	};

/***********************************************************************************************************************/

// out, in, end:

private:

	template
	<
		typename OutType,
		typename InType,
		typename EndType
	>
	class one_cycle_signature
	<
		_out_object < OutType , Interval::closing >,
		_in_object  < InType  , Interval::closing >,
		_end_object < EndType , Interval::closing >
	>
	{
		OutType out;
		InType in;
		EndType end;

		public:

			constexpr one_cycle_signature
			(
				const OutType & o,
				const InType  & i,
				const EndType & e

			) : out(o), in(i), end(e) { }

		// friendship:

			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_ref);
			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_deref);
			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, in_ref);
			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, in_deref);
			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_ref);
			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_deref);
	};

/***********************************************************************************************************************/

// out, car in, cdr in, end:

private:

	template
	<
		typename OutType,
		typename CarInType,
		typename CdrInType,
		typename EndType
	>
	class one_cycle_signature
	<
		_out_object    < OutType   , Interval::closing >,
		_car_in_object < CarInType , Interval::closing >,
		_cdr_in_object < CdrInType , Interval::closing >,
		_end_object    < EndType   , Interval::closing >
	>
	{
		OutType out;
		CarInType car_in;
		CdrInType cdr_in;
		EndType end;

		public:

			constexpr one_cycle_signature
			(
				const OutType   & o,
				const CarInType & i1,
				const CdrInType & i2,
				const EndType   & e

			) : out(o), car_in(i1), cdr_in(i2), end(e) { }

		// friendship:

		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, car_in_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, car_in_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, cdr_in_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, cdr_in_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, end, msg:

private:

	template
	<
		typename OutType,
		typename EndType,
		typename MsgType
	>
	class one_cycle_signature
	<
		_out_object < OutType , Interval::closing >,
		_end_object < EndType , Interval::closing >,
		_msg_object < MsgType , Interval::closing >
	>
	{
		OutType out;
		EndType end;
		MsgType msg;

		public:

			constexpr one_cycle_signature
			(
				const OutType & o,
				const EndType & e

			) : out(o), end(e) { }

			constexpr one_cycle_signature
			(
				const OutType & o,
				const EndType & e,
				const MsgType & m

			) : out(o), end(e), msg(m) { }

		// friendship:

		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, msg_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, msg_deref);
	};

/***********************************************************************************************************************/

// out, in, end, msg:

private:

	template
	<
		typename OutType,
		typename InType,
		typename EndType,
		typename MsgType
	>
	class one_cycle_signature
	<
		_out_object < OutType , Interval::closing >,
		_in_object  < InType  , Interval::closing >,
		_end_object < EndType , Interval::closing >,
		_msg_object < MsgType , Interval::closing >
	>
	{
		OutType out;
		InType in;
		EndType end;
		MsgType msg;

		public:

			constexpr one_cycle_signature
			(
				const OutType & o,
				const InType  & i,
				const EndType & e

			) : out(o), in(i), end(e) { }

			constexpr one_cycle_signature
			(
				const OutType & o,
				const InType  & i,
				const EndType & e,
				const MsgType & m

			) : out(o), in(i), end(e), msg(m) { }

		// friendship:

		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, in_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, in_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, msg_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, msg_deref);
	};

/***********************************************************************************************************************/

// out, car in, cdr in, end, msg:

private:

	template
	<
		typename OutType,
		typename CarInType,
		typename CdrInType,
		typename EndType,
		typename MsgType
	>
	class one_cycle_signature
	<
		_out_object    < OutType   , Interval::closing >,
		_car_in_object < CarInType , Interval::closing >,
		_cdr_in_object < CdrInType , Interval::closing >,
		_end_object    < EndType   , Interval::closing >,
		_msg_object    < MsgType   , Interval::closing >
	>
	{
		OutType out;
		CarInType car_in;
		CdrInType cdr_in;
		EndType end;
		MsgType msg;

		public:

			constexpr one_cycle_signature
			(
				const OutType   & o,
				const CarInType & i1,
				const CdrInType & i2,
				const EndType   & e

			) : out(o), car_in(i1), cdr_in(i2), end(e) { }

			constexpr one_cycle_signature
			(
				const OutType   & o,
				const CarInType & i1,
				const CdrInType & i2,
				const EndType   & e,
				const MsgType   & m

			) : out(o), car_in(i1), cdr_in(i2), end(e), msg(m) { }

		// friendship:

		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, car_in_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, car_in_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, cdr_in_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, cdr_in_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, msg_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, msg_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, end, aux:

private:

	template
	<
		typename OutType,
		typename EndType,
		typename AuxType
	>
	class one_cycle_signature
	<
		_out_object < OutType , Interval::closing >,
		_end_object < EndType , Interval::closing >,
		_aux_object < AuxType , Interval::closing >
	>
	{
		OutType out;
		EndType end;
		AuxType aux;

		public:

			constexpr one_cycle_signature
			(
				const OutType & o,
				const EndType & e

			) : out(o), end(e) { }

			constexpr one_cycle_signature
			(
				const OutType & o,
				const EndType & e,
				const AuxType & a

			) : out(o), end(e), aux(a) { }

		// friendship:

		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, aux_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, aux_deref);
	};

/***********************************************************************************************************************/

// out, in, end, aux:

private:

	template
	<
		typename OutType,
		typename InType,
		typename EndType,
		typename AuxType
	>
	class one_cycle_signature
	<
		_out_object < OutType , Interval::closing >,
		_in_object  < InType  , Interval::closing >,
		_end_object < EndType , Interval::closing >,
		_aux_object < AuxType , Interval::closing >
	>
	{
		OutType out;
		InType in;
		EndType end;
		AuxType aux;

		public:

			constexpr one_cycle_signature
			(
				const OutType & o,
				const InType  & i,
				const EndType & e

			) : out(o), in(i), end(e) { }

			constexpr one_cycle_signature
			(
				const OutType & o,
				const InType  & i,
				const EndType & e,
				const AuxType & a

			) : out(o), in(i), end(e), aux(a) { }

		// friendship:

		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, in_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, in_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, aux_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, aux_deref);
	};

/***********************************************************************************************************************/

// out, car in, cdr in, end, aux:

private:

	template
	<
		typename OutType,
		typename CarInType,
		typename CdrInType,
		typename EndType,
		typename AuxType
	>
	class one_cycle_signature
	<
		_out_object    < OutType   , Interval::closing >,
		_car_in_object < CarInType , Interval::closing >,
		_cdr_in_object < CdrInType , Interval::closing >,
		_end_object    < EndType   , Interval::closing >,
		_aux_object    < AuxType   , Interval::closing >
	>
	{
		OutType out;
		CarInType car_in;
		CdrInType cdr_in;
		EndType end;
		AuxType aux;

		public:

			constexpr one_cycle_signature
			(
				const OutType   & o,
				const CarInType & i1,
				const CdrInType & i2,
				const EndType   & e

			) : out(o), car_in(i1), cdr_in(i2), end(e) { }

			constexpr one_cycle_signature
			(
				const OutType   & o,
				const CarInType & i1,
				const CdrInType & i2,
				const EndType   & e,
				const AuxType   & a

			) : out(o), car_in(i1), cdr_in(i2), end(e), aux(a) { }

		// friendship:

		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, car_in_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, car_in_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, cdr_in_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, cdr_in_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, aux_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, aux_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, end, aux, msg:

private:

	template
	<
		typename OutType,
		typename EndType,
		typename AuxType,
		typename MsgType
	>
	class one_cycle_signature
	<
		_out_object < OutType , Interval::closing >,
		_end_object < EndType , Interval::closing >,
		_aux_object < AuxType , Interval::closing >,
		_msg_object < MsgType , Interval::closing >
	>
	{
		OutType out;
		EndType end;
		AuxType aux;
		MsgType msg;

		public:

			constexpr one_cycle_signature
			(
				const OutType & o,
				const EndType & e

			) : out(o), end(e) { }

			constexpr one_cycle_signature
			(
				const OutType & o,
				const EndType & e,
				const MsgType & m

			) : out(o), end(e), msg(m) { }

			constexpr one_cycle_signature
			(
				const OutType & o,
				const EndType & e,
				const AuxType & a

			) : out(o), end(e), aux(a) { }

			constexpr one_cycle_signature
			(
				const OutType & o,
				const EndType & e,
				const AuxType & a,
				const MsgType & m

			) : out(o), end(e), aux(a), msg(m) { }

		// friendship:

		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, aux_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, aux_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, msg_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, msg_deref);
	};

/***********************************************************************************************************************/

// out, in, end, aux, msg:

private:

	template
	<
		typename OutType,
		typename InType,
		typename EndType,
		typename AuxType,
		typename MsgType
	>
	class one_cycle_signature
	<
		_out_object < OutType , Interval::closing >,
		_in_object  < InType  , Interval::closing >,
		_end_object < EndType , Interval::closing >,
		_aux_object < AuxType , Interval::closing >,
		_msg_object < MsgType , Interval::closing >
	>
	{
		OutType out;
		InType in;
		EndType end;
		AuxType aux;
		MsgType msg;

		public:

			constexpr one_cycle_signature
			(
				const OutType & o,
				const InType  & i,
				const EndType & e

			) : out(o), in(i), end(e) { }

			constexpr one_cycle_signature
			(
				const OutType & o,
				const InType  & i,
				const EndType & e,
				const MsgType & m

			) : out(o), in(i), end(e), msg(m) { }

			constexpr one_cycle_signature
			(
				const OutType & o,
				const InType  & i,
				const EndType & e,
				const AuxType & a

			) : out(o), in(i), end(e), aux(a) { }

			constexpr one_cycle_signature
			(
				const OutType & o,
				const InType  & i,
				const EndType & e,
				const AuxType & a,
				const MsgType & m

			) : out(o), in(i), end(e), aux(a), msg(m) { }

		// friendship:

		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, in_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, in_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, aux_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, aux_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, msg_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, msg_deref);
	};

/***********************************************************************************************************************/

// out, car in, cdr in, end, aux, msg:

private:

	template
	<
		typename OutType,
		typename CarInType,
		typename CdrInType,
		typename EndType,
		typename AuxType,
		typename MsgType
	>
	class one_cycle_signature
	<
		_out_object    < OutType   , Interval::closing >,
		_car_in_object < CarInType , Interval::closing >,
		_cdr_in_object < CdrInType , Interval::closing >,
		_end_object    < EndType   , Interval::closing >,
		_aux_object    < AuxType   , Interval::closing >,
		_msg_object    < MsgType   , Interval::closing >
	>
	{
		OutType out;
		CarInType car_in;
		CdrInType cdr_in;
		EndType end;
		AuxType aux;
		MsgType msg;

		public:

			constexpr one_cycle_signature
			(
				const OutType   & o,
				const CarInType & i1,
				const CdrInType & i2,
				const EndType   & e

			) : out(o), car_in(i1), cdr_in(i2), end(e) { }

			constexpr one_cycle_signature
			(
				const OutType   & o,
				const CarInType & i1,
				const CdrInType & i2,
				const EndType   & e,
				const MsgType   & m

			) : out(o), car_in(i1), cdr_in(i2), end(e), msg(m) { }

			constexpr one_cycle_signature
			(
				const OutType   & o,
				const CarInType & i1,
				const CdrInType & i2,
				const EndType   & e,
				const AuxType   & a

			) : out(o), car_in(i1), cdr_in(i2), end(e), aux(a) { }

			constexpr one_cycle_signature
			(
				const OutType   & o,
				const CarInType & i1,
				const CdrInType & i2,
				const EndType   & e,
				const AuxType   & a,
				const MsgType   & m

			) : out(o), car_in(i1), cdr_in(i2), end(e), aux(a), msg(m) { }

		// friendship:

		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, out_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, car_in_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, car_in_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, cdr_in_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, cdr_in_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, end_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, aux_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, aux_deref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, msg_ref);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, msg_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

