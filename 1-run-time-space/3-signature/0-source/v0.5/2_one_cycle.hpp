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

		NIK_DEFINE_OUT_END_ONE_CYCLE_ACCESSOR( out , VARIABLE  );
		NIK_DEFINE_OUT_END_ONE_CYCLE_ACCESSOR( out , IMMUTABLE );

	// end:

		NIK_DEFINE_OUT_END_ONE_CYCLE_ACCESSOR( end , VARIABLE  );
		NIK_DEFINE_OUT_END_ONE_CYCLE_ACCESSOR( end , IMMUTABLE );

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

			NIK_DEFINE_OUT_END_ONE_CYCLE_FRIEND( out , VARIABLE  );
			NIK_DEFINE_OUT_END_ONE_CYCLE_FRIEND( out , IMMUTABLE );
			NIK_DEFINE_OUT_END_ONE_CYCLE_FRIEND( end , VARIABLE  );
			NIK_DEFINE_OUT_END_ONE_CYCLE_FRIEND( end , IMMUTABLE );
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, in, end:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DEFINE_OUT_IN_END_ONE_CYCLE_ACCESSOR( out , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_ONE_CYCLE_ACCESSOR( out , IMMUTABLE );

	// in:

		NIK_DEFINE_OUT_IN_END_ONE_CYCLE_ACCESSOR( in , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_ONE_CYCLE_ACCESSOR( in , IMMUTABLE );

	// end:

		NIK_DEFINE_OUT_IN_END_ONE_CYCLE_ACCESSOR( end , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_ONE_CYCLE_ACCESSOR( end , IMMUTABLE );

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

			NIK_DEFINE_OUT_IN_END_ONE_CYCLE_FRIEND( out , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_ONE_CYCLE_FRIEND( out , IMMUTABLE );
			NIK_DEFINE_OUT_IN_END_ONE_CYCLE_FRIEND( in  , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_ONE_CYCLE_FRIEND( in  , IMMUTABLE );
			NIK_DEFINE_OUT_IN_END_ONE_CYCLE_FRIEND( end , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_ONE_CYCLE_FRIEND( end , IMMUTABLE );
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

//here:

// out, car in, cdr in, end:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR( out , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR( out , IMMUTABLE );

	// car in:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR( car_in , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR( car_in , IMMUTABLE );

	// cdr in:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR( cdr_in , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR( cdr_in , IMMUTABLE );

	// end:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR( end , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_ACCESSOR( end , IMMUTABLE );

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

			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND( out    , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND( out    , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND( car_in , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND( car_in , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND( cdr_in , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND( cdr_in , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND( end    , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_ONE_CYCLE_FRIEND( end    , IMMUTABLE );
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, end, msg:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DEFINE_OUT_END_MSG_ONE_CYCLE_ACCESSOR( out , VARIABLE  );
		NIK_DEFINE_OUT_END_MSG_ONE_CYCLE_ACCESSOR( out , IMMUTABLE );

	// end:

		NIK_DEFINE_OUT_END_MSG_ONE_CYCLE_ACCESSOR( end , VARIABLE  );
		NIK_DEFINE_OUT_END_MSG_ONE_CYCLE_ACCESSOR( end , IMMUTABLE );

	// msg:

		NIK_DEFINE_OUT_END_MSG_ONE_CYCLE_ACCESSOR( msg , VARIABLE  );
		NIK_DEFINE_OUT_END_MSG_ONE_CYCLE_ACCESSOR( msg , IMMUTABLE );

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

			NIK_DEFINE_OUT_END_MSG_ONE_CYCLE_FRIEND( out , VARIABLE  );
			NIK_DEFINE_OUT_END_MSG_ONE_CYCLE_FRIEND( out , IMMUTABLE );
			NIK_DEFINE_OUT_END_MSG_ONE_CYCLE_FRIEND( end , VARIABLE  );
			NIK_DEFINE_OUT_END_MSG_ONE_CYCLE_FRIEND( end , IMMUTABLE );
			NIK_DEFINE_OUT_END_MSG_ONE_CYCLE_FRIEND( msg , VARIABLE  );
			NIK_DEFINE_OUT_END_MSG_ONE_CYCLE_FRIEND( msg , IMMUTABLE );
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, in, end, msg:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR( out , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR( out , IMMUTABLE );

	// in:

		NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR( in , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR( in , IMMUTABLE );

	// end:

		NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR( end , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR( end , IMMUTABLE );

	// msg:

		NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR( msg , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_ACCESSOR( msg , IMMUTABLE );

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

			NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND( out , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND( out , IMMUTABLE );
			NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND( in  , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND( in  , IMMUTABLE );
			NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND( end , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND( end , IMMUTABLE );
			NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND( msg , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_MSG_ONE_CYCLE_FRIEND( msg , IMMUTABLE );
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, car in, cdr in, end, msg:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR( out , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR( out , IMMUTABLE );

	// car in:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR( car_in , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR( car_in , IMMUTABLE );

	// cdr in:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR( cdr_in , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR( cdr_in , IMMUTABLE );

	// end:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR( end , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR( end , IMMUTABLE );

	// msg:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR( msg , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_ACCESSOR( msg , IMMUTABLE );

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

			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND( out    , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND( out    , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND( car_in , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND( car_in , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND( cdr_in , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND( cdr_in , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND( end    , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND( end    , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND( msg    , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_MSG_ONE_CYCLE_FRIEND( msg    , IMMUTABLE );
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, end, aux:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DEFINE_OUT_END_AUX_ONE_CYCLE_ACCESSOR( out , VARIABLE  );
		NIK_DEFINE_OUT_END_AUX_ONE_CYCLE_ACCESSOR( out , IMMUTABLE );

	// end:

		NIK_DEFINE_OUT_END_AUX_ONE_CYCLE_ACCESSOR( end , VARIABLE  );
		NIK_DEFINE_OUT_END_AUX_ONE_CYCLE_ACCESSOR( end , IMMUTABLE );

	// aux:

		NIK_DEFINE_OUT_END_AUX_ONE_CYCLE_ACCESSOR( aux , VARIABLE  );
		NIK_DEFINE_OUT_END_AUX_ONE_CYCLE_ACCESSOR( aux , IMMUTABLE );

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

			NIK_DEFINE_OUT_END_AUX_ONE_CYCLE_FRIEND( out , VARIABLE  );
			NIK_DEFINE_OUT_END_AUX_ONE_CYCLE_FRIEND( out , IMMUTABLE );
			NIK_DEFINE_OUT_END_AUX_ONE_CYCLE_FRIEND( end , VARIABLE  );
			NIK_DEFINE_OUT_END_AUX_ONE_CYCLE_FRIEND( end , IMMUTABLE );
			NIK_DEFINE_OUT_END_AUX_ONE_CYCLE_FRIEND( aux , VARIABLE  );
			NIK_DEFINE_OUT_END_AUX_ONE_CYCLE_FRIEND( aux , IMMUTABLE );
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, in, end, aux:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR( out , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR( out , IMMUTABLE );

	// in:

		NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR( in , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR( in , IMMUTABLE );

	// end:

		NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR( end , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR( end , IMMUTABLE );

	// aux:

		NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR( aux , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_ACCESSOR( aux , IMMUTABLE );

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

			NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND( out , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND( out , IMMUTABLE );
			NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND( in  , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND( in  , IMMUTABLE );
			NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND( end , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND( end , IMMUTABLE );
			NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND( aux , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_AUX_ONE_CYCLE_FRIEND( aux , IMMUTABLE );
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, car in, cdr in, end, aux:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR( out , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR( out , IMMUTABLE );

	// car in:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR( car_in , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR( car_in , IMMUTABLE );

	// cdr in:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR( cdr_in , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR( cdr_in , IMMUTABLE );

	// end:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR( end , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR( end , IMMUTABLE );

	// aux:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR( aux , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_ACCESSOR( aux , IMMUTABLE );

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

			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND( out    , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND( out    , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND( car_in , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND( car_in , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND( cdr_in , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND( cdr_in , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND( end    , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND( end    , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND( aux    , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_ONE_CYCLE_FRIEND( aux    , IMMUTABLE );
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, end, aux, msg:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR( out , VARIABLE  );
		NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR( out , IMMUTABLE );

	// end:

		NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR( end , VARIABLE  );
		NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR( end , IMMUTABLE );

	// aux:

		NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR( aux , VARIABLE  );
		NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR( aux , IMMUTABLE );

	// msg:

		NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR( msg , VARIABLE  );
		NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_ACCESSOR( msg , IMMUTABLE );

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

			NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND( out , VARIABLE  );
			NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND( out , IMMUTABLE );
			NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND( end , VARIABLE  );
			NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND( end , IMMUTABLE );
			NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND( aux , VARIABLE  );
			NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND( aux , IMMUTABLE );
			NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND( msg , VARIABLE  );
			NIK_DEFINE_OUT_END_AUX_MSG_ONE_CYCLE_FRIEND( msg , IMMUTABLE );
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, in, end, aux, msg:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( out , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( out , IMMUTABLE );

	// in:

		NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( in , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( in , IMMUTABLE );

	// end:

		NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( end , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( end , IMMUTABLE );

	// aux:

		NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( aux , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( aux , IMMUTABLE );

	// msg:

		NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( msg , VARIABLE  );
		NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( msg , IMMUTABLE );

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

			NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( out , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( out , IMMUTABLE );
			NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( in  , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( in  , IMMUTABLE );
			NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( end , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( end , IMMUTABLE );
			NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( aux , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( aux , IMMUTABLE );
			NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( msg , VARIABLE  );
			NIK_DEFINE_OUT_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( msg , IMMUTABLE );
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, car in, cdr in, end, aux, msg:

/***********************************************************************************************************************/

// accessors:

public:

	// out:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( out , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( out , IMMUTABLE );

	// car in:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( car_in , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( car_in , IMMUTABLE );

	// cdr in:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( cdr_in , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( cdr_in , IMMUTABLE );

	// end:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( end , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( end , IMMUTABLE );

	// aux:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( aux , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( aux , IMMUTABLE );

	// msg:

		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( msg , VARIABLE  );
		NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_ACCESSOR( msg , IMMUTABLE );

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

			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( out    , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( out    , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( car_in , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( car_in , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( cdr_in , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( cdr_in , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( end    , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( end    , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( aux    , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( aux    , IMMUTABLE );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( msg    , VARIABLE  );
			NIK_DEFINE_OUT_CAR_IN_CDR_IN_END_AUX_MSG_ONE_CYCLE_FRIEND( msg    , IMMUTABLE );
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

public:

	template<typename... Ts>
	using one_cycle = one_cycle_signature<Ts...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

