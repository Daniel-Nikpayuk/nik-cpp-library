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

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// objects:

/***********************************************************************************************************************/

// members:

public:

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

// kinds:

	template<typename T> using _out_object			= _object < OneCycleMember::out    , T >;
	template<typename T> using _in_object			= _object < OneCycleMember::in     , T >;
	template<typename T> using _car_in_object		= _object < OneCycleMember::car_in , T >;
	template<typename T> using _cdr_in_object		= _object < OneCycleMember::cdr_in , T >;
	template<typename T> using _end_object			= _object < OneCycleMember::end    , T >;
	template<typename T> using _aux_object			= _object < OneCycleMember::aux    , T >;
	template<typename T> using _msg_object			= _object < OneCycleMember::msg    , T >;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// signature:

private:

	template<typename...> class one_cycle_signature;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, end:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DECLARE_OUT_END_ONE_CYCLE_ACCESSOR(out_ref, s)		{ return s.out; }
		NIK_DECLARE_OUT_END_ONE_CYCLE_ACCESSOR(out_deref, s)		{ return *s.out; }

	// end:

		NIK_DECLARE_OUT_END_ONE_CYCLE_ACCESSOR(end_ref, s)		{ return s.end; }
		NIK_DECLARE_OUT_END_ONE_CYCLE_ACCESSOR(end_deref, s)		{ return *s.end; }

/***********************************************************************************************************************/

// specialization:

private:

	template
	<
		typename OutType,
		typename EndType
	>
	class one_cycle_signature
	<
		_out_object < OutType >,
		_end_object < EndType >
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

			NIK_DECLARE_OUT_END_ONE_CYCLE_FRIEND(out_ref);
			NIK_DECLARE_OUT_END_ONE_CYCLE_FRIEND(out_deref);
			NIK_DECLARE_OUT_END_ONE_CYCLE_FRIEND(end_ref);
			NIK_DECLARE_OUT_END_ONE_CYCLE_FRIEND(end_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, in, end:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(out_ref, s)		{ return s.out; }
		NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(out_deref, s)		{ return *s.out; }

	// in:

		NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(in_ref, s)		{ return s.in; }
		NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(in_deref, s)		{ return *s.in; }

	// end:

		NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(end_ref, s)		{ return s.end; }
		NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(end_deref, s)		{ return *s.end; }

/***********************************************************************************************************************/

// specialization:

private:

	template
	<
		typename OutType,
		typename InType,
		typename EndType
	>
	class one_cycle_signature
	<
		_object < OneCycleMember::out , OutType >,
		_object < OneCycleMember::in  , InType  >,
		_object < OneCycleMember::end , EndType >
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

			NIK_DECLARE_OUT_IN_END_ONE_CYCLE_FRIEND(out_ref);
			NIK_DECLARE_OUT_IN_END_ONE_CYCLE_FRIEND(out_deref);
			NIK_DECLARE_OUT_IN_END_ONE_CYCLE_FRIEND(in_ref);
			NIK_DECLARE_OUT_IN_END_ONE_CYCLE_FRIEND(in_deref);
			NIK_DECLARE_OUT_IN_END_ONE_CYCLE_FRIEND(end_ref);
			NIK_DECLARE_OUT_IN_END_ONE_CYCLE_FRIEND(end_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

//here:

// out, car in, cdr in, end:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR(out_ref, s)		{ return s.out; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR(out_deref, s)		{ return *s.out; }

	// car in:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR(car_in_ref, s)		{ return s.car_in; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR(car_in_deref, s)		{ return *s.car_in; }

	// cdr in:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR(cdr_in_ref, s)		{ return s.cdr_in; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR(cdr_in_deref, s)		{ return *s.cdr_in; }

	// end:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR(end_ref, s)		{ return s.end; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR(end_deref, s)		{ return *s.end; }

/***********************************************************************************************************************/

// specialization:

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
		_out_object    < OutType   >,
		_car_in_object < CarInType >,
		_cdr_in_object < CdrInType >,
		_end_object    < EndType   >
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

			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND(out_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND(out_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND(car_in_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND(car_in_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND(cdr_in_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND(cdr_in_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND(end_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND(end_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, end, msg:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DECLARE_OUT_END_MSG_ONE_CYCLE_ACCESSOR(out_ref, s)			{ return s.out; }
		NIK_DECLARE_OUT_END_MSG_ONE_CYCLE_ACCESSOR(out_deref, s)		{ return *s.out; }

	// end:

		NIK_DECLARE_OUT_END_MSG_ONE_CYCLE_ACCESSOR(end_ref, s)			{ return s.end; }
		NIK_DECLARE_OUT_END_MSG_ONE_CYCLE_ACCESSOR(end_deref, s)		{ return *s.end; }

	// msg:

		NIK_DECLARE_OUT_END_MSG_ONE_CYCLE_ACCESSOR(msg_ref, s)			{ return s.msg; }
		NIK_DECLARE_OUT_END_MSG_ONE_CYCLE_ACCESSOR(msg_deref, s)		{ return *s.msg; }

/***********************************************************************************************************************/

// specialization:

private:

	template
	<
		typename OutType,
		typename EndType,
		typename MsgType
	>
	class one_cycle_signature
	<
		_out_object < OutType >,
		_end_object < EndType >,
		_msg_object < MsgType >
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

			NIK_DECLARE_OUT_END_MSG_ONE_CYCLE_FRIEND(out_ref);
			NIK_DECLARE_OUT_END_MSG_ONE_CYCLE_FRIEND(out_deref);
			NIK_DECLARE_OUT_END_MSG_ONE_CYCLE_FRIEND(end_ref);
			NIK_DECLARE_OUT_END_MSG_ONE_CYCLE_FRIEND(end_deref);
			NIK_DECLARE_OUT_END_MSG_ONE_CYCLE_FRIEND(msg_ref);
			NIK_DECLARE_OUT_END_MSG_ONE_CYCLE_FRIEND(msg_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, in, end, msg:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR(out_ref, s)		{ return s.out; }
		NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR(out_deref, s)		{ return *s.out; }

	// in:

		NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR(in_ref, s)		{ return s.in; }
		NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR(in_deref, s)		{ return *s.in; }

	// end:

		NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR(end_ref, s)		{ return s.end; }
		NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR(end_deref, s)		{ return *s.end; }

	// msg:

		NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR(msg_ref, s)		{ return s.msg; }
		NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR(msg_deref, s)		{ return *s.msg; }

/***********************************************************************************************************************/

// specialization:

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
		_out_object < OutType >,
		_in_object  < InType  >,
		_end_object < EndType >,
		_msg_object < MsgType >
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

			NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND(out_ref);
			NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND(out_deref);
			NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND(in_ref);
			NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND(in_deref);
			NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND(end_ref);
			NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND(end_deref);
			NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND(msg_ref);
			NIK_DECLARE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND(msg_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, car in, cdr in, end, msg:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR(out_ref, s)		{ return s.out; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR(out_deref, s)		{ return *s.out; }

	// car in:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR(car_in_ref, s)		{ return s.car_in; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR(car_in_deref, s)	{ return *s.car_in; }

	// cdr in:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR(cdr_in_ref, s)		{ return s.cdr_in; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR(cdr_in_deref, s)	{ return *s.cdr_in; }

	// end:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR(end_ref, s)		{ return s.end; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR(end_deref, s)		{ return *s.end; }

	// msg:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR(msg_ref, s)		{ return s.msg; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR(msg_deref, s)		{ return *s.msg; }

/***********************************************************************************************************************/

// specialization:

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
		_out_object    < OutType   >,
		_car_in_object < CarInType >,
		_cdr_in_object < CdrInType >,
		_end_object    < EndType   >,
		_msg_object    < MsgType   >
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

			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND(out_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND(out_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND(car_in_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND(car_in_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND(cdr_in_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND(cdr_in_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND(end_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND(end_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND(msg_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND(msg_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, end, aux:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DECLARE_OUT_END_AUX_ONE_CYCLE_ACCESSOR(out_ref, s)			{ return s.out; }
		NIK_DECLARE_OUT_END_AUX_ONE_CYCLE_ACCESSOR(out_deref, s)		{ return *s.out; }

	// end:

		NIK_DECLARE_OUT_END_AUX_ONE_CYCLE_ACCESSOR(end_ref, s)			{ return s.end; }
		NIK_DECLARE_OUT_END_AUX_ONE_CYCLE_ACCESSOR(end_deref, s)		{ return *s.end; }

	// aux:

		NIK_DECLARE_OUT_END_AUX_ONE_CYCLE_ACCESSOR(aux_ref, s)			{ return s.aux; }
		NIK_DECLARE_OUT_END_AUX_ONE_CYCLE_ACCESSOR(aux_deref, s)		{ return *s.aux; }

/***********************************************************************************************************************/

// specialization:

private:

	template
	<
		typename OutType,
		typename EndType,
		typename AuxType
	>
	class one_cycle_signature
	<
		_out_object < OutType >,
		_end_object < EndType >,
		_aux_object < AuxType >
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

			NIK_DECLARE_OUT_END_AUX_ONE_CYCLE_FRIEND(out_ref);
			NIK_DECLARE_OUT_END_AUX_ONE_CYCLE_FRIEND(out_deref);
			NIK_DECLARE_OUT_END_AUX_ONE_CYCLE_FRIEND(end_ref);
			NIK_DECLARE_OUT_END_AUX_ONE_CYCLE_FRIEND(end_deref);
			NIK_DECLARE_OUT_END_AUX_ONE_CYCLE_FRIEND(aux_ref);
			NIK_DECLARE_OUT_END_AUX_ONE_CYCLE_FRIEND(aux_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, in, end, aux:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR(out_ref, s)		{ return s.out; }
		NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR(out_deref, s)		{ return *s.out; }

	// in:

		NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR(in_ref, s)		{ return s.in; }
		NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR(in_deref, s)		{ return *s.in; }

	// end:

		NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR(end_ref, s)		{ return s.end; }
		NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR(end_deref, s)		{ return *s.end; }

	// aux:

		NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR(aux_ref, s)		{ return s.aux; }
		NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR(aux_deref, s)		{ return *s.aux; }

/***********************************************************************************************************************/

// specialization:

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
		_out_object < OutType >,
		_in_object  < InType  >,
		_end_object < EndType >,
		_aux_object < AuxType >
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

			NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND(out_ref);
			NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND(out_deref);
			NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND(in_ref);
			NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND(in_deref);
			NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND(end_ref);
			NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND(end_deref);
			NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND(aux_ref);
			NIK_DECLARE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND(aux_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, car in, cdr in, end, aux:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR(out_ref, s)		{ return s.out; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR(out_deref, s)		{ return *s.out; }

	// car in:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR(car_in_ref, s)		{ return s.car_in; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR(car_in_deref, s)	{ return *s.car_in; }

	// cdr in:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR(cdr_in_ref, s)		{ return s.cdr_in; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR(cdr_in_deref, s)	{ return *s.cdr_in; }

	// end:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR(end_ref, s)		{ return s.end; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR(end_deref, s)		{ return *s.end; }

	// aux:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR(aux_ref, s)		{ return s.aux; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR(aux_deref, s)		{ return *s.aux; }

/***********************************************************************************************************************/

// specialization:

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
		_out_object    < OutType   >,
		_car_in_object < CarInType >,
		_cdr_in_object < CdrInType >,
		_end_object    < EndType   >,
		_aux_object    < AuxType   >
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

			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND(out_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND(out_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND(car_in_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND(car_in_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND(cdr_in_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND(cdr_in_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND(end_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND(end_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND(aux_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND(aux_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, end, aux, msg:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR(out_ref, s)		{ return s.out; }
		NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR(out_deref, s)		{ return *s.out; }

	// end:

		NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR(end_ref, s)		{ return s.end; }
		NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR(end_deref, s)		{ return *s.end; }

	// aux:

		NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR(aux_ref, s)		{ return s.aux; }
		NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR(aux_deref, s)		{ return *s.aux; }

	// msg:

		NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR(msg_ref, s)		{ return s.msg; }
		NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR(msg_deref, s)		{ return *s.msg; }

/***********************************************************************************************************************/

// specialization:

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
		_out_object < OutType >,
		_end_object < EndType >,
		_aux_object < AuxType >,
		_msg_object < MsgType >
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

			NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND(out_ref);
			NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND(out_deref);
			NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND(end_ref);
			NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND(end_deref);
			NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND(aux_ref);
			NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND(aux_deref);
			NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND(msg_ref);
			NIK_DECLARE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND(msg_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, in, end, aux, msg:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(out_ref, s)		{ return s.out; }
		NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(out_deref, s)		{ return *s.out; }

	// in:

		NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(in_ref, s)		{ return s.in; }
		NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(in_deref, s)		{ return *s.in; }

	// end:

		NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(end_ref, s)		{ return s.end; }
		NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(end_deref, s)		{ return *s.end; }

	// aux:

		NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(aux_ref, s)		{ return s.aux; }
		NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(aux_deref, s)		{ return *s.aux; }

	// msg:

		NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(msg_ref, s)		{ return s.msg; }
		NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(msg_deref, s)		{ return *s.msg; }

/***********************************************************************************************************************/

// specialization:

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
		_out_object < OutType >,
		_in_object  < InType  >,
		_end_object < EndType >,
		_aux_object < AuxType >,
		_msg_object < MsgType >
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

			NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(out_ref);
			NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(out_deref);
			NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(in_ref);
			NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(in_deref);
			NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(end_ref);
			NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(end_deref);
			NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(aux_ref);
			NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(aux_deref);
			NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(msg_ref);
			NIK_DECLARE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(msg_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, car in, cdr in, end, aux, msg:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(out_ref, s)	{ return s.out; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(out_deref, s)	{ return *s.out; }

	// car in:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(car_in_ref, s)	{ return s.car_in; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(car_in_deref, s)	{ return *s.car_in; }

	// cdr in:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(cdr_in_ref, s)	{ return s.cdr_in; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(cdr_in_deref, s)	{ return *s.cdr_in; }

	// end:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(end_ref, s)	{ return s.end; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(end_deref, s)	{ return *s.end; }

	// aux:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(aux_ref, s)	{ return s.aux; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(aux_deref, s)	{ return *s.aux; }

	// msg:

		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(msg_ref, s)	{ return s.msg; }
		NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR(msg_deref, s)	{ return *s.msg; }

/***********************************************************************************************************************/

// specialization:

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
		_out_object    < OutType   >,
		_car_in_object < CarInType >,
		_cdr_in_object < CdrInType >,
		_end_object    < EndType   >,
		_aux_object    < AuxType   >,
		_msg_object    < MsgType   >
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

			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(out_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(out_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(car_in_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(car_in_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(cdr_in_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(cdr_in_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(end_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(end_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(aux_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(aux_deref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(msg_ref);
			NIK_DECLARE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND(msg_deref);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

public:

	template<typename... Ts>
	using one_cycle = one_cycle_signature<Ts...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

