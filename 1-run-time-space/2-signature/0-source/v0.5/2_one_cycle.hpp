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

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// signature:

	template<typename...> class one_cycle;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, in, end:

/***********************************************************************************************************************/

	template<typename> struct _object	{ };

/***********************************************************************************************************************/

// accessors:

/*
	template<typename OutT, typename InT, typename EndT>
	OutT & dout(one_cycle<OutT, InT, EndT> & s)			{ return s.out; }

	template<typename OutT, typename InT, typename EndT>
	auto & iout(one_cycle<OutT, InT, EndT> & s)			{ return *s.out; }

	template<typename OutT, typename InT, typename EndT>
	InT & din(one_cycle<OutT, InT, EndT> & s)			{ return s.in; }

	template<typename OutT, typename InT, typename EndT>
	auto & iin(one_cycle<OutT, InT, EndT> & s)			{ return *s.in; }

	template<typename OutT, typename InT, typename EndT>
	EndT & dend(one_cycle<OutT, InT, EndT> & s)			{ return s.end; }

	template<typename OutT, typename InT, typename EndT>
	auto & iend(one_cycle<OutT, InT, EndT> & s)			{ return *s.end; }
*/

	template<typename OutType, typename InType, typename EndType>
	OutType & dout(one_cycle<_object<OutType>, _object<InType>, _object<EndType>> & s)
		{ return s.out; }

/***********************************************************************************************************************/

// specialization:

	template
	<
		typename OutType,
		typename InType,
		typename EndType
	>
	class one_cycle
	<
		_object < OutType >,
		_object < InType  >,
		_object < EndType >
	>
	{
		OutType out;
		InType  in;
		EndType end;

		public:

			constexpr one_cycle(const OutType & _o, const InType & _i, const EndType & _e) :

				out(_o), in(_i), end(_e) { }

		// friendship:

			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(OutType, dout);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, iout);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(InType, din);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, iin);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(EndType, dend);
		//	friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, iend);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

