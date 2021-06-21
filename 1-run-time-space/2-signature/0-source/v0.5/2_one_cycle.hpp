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

	template<typename> struct _object	{ };

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
		static constexpr auto & dout(one_cycle_signature<_object<Ts>...> & s)		{ return s.out; }

		template<typename... Ts>
		static constexpr auto & iout(one_cycle_signature<_object<Ts>...> & s)		{ return *s.out; }

	// in:

		template<typename... Ts>
		static constexpr auto & din(one_cycle_signature<_object<Ts>...> & s)		{ return s.in; }

		template<typename... Ts>
		static constexpr auto & iin(one_cycle_signature<_object<Ts>...> & s)		{ return *s.in; }

	// car in:

		template<typename... Ts>
		static constexpr auto & dcar_in(one_cycle_signature<_object<Ts>...> & s)	{ return s.car_in; }

		template<typename... Ts>
		static constexpr auto & icar_in(one_cycle_signature<_object<Ts>...> & s)	{ return *s.car_in; }

	// cdr in:

		template<typename... Ts>
		static constexpr auto & dcdr_in(one_cycle_signature<_object<Ts>...> & s)	{ return s.cdr_in; }

		template<typename... Ts>
		static constexpr auto & icdr_in(one_cycle_signature<_object<Ts>...> & s)	{ return *s.cdr_in; }

	// end:

		template<typename... Ts>
		static constexpr auto & dend(one_cycle_signature<_object<Ts>...> & s)		{ return s.end; }

		template<typename... Ts>
		static constexpr auto & iend(one_cycle_signature<_object<Ts>...> & s)		{ return *s.end; }

	// aux:

		template<typename... Ts>
		static constexpr auto & daux(one_cycle_signature<_object<Ts>...> & s)		{ return s.aux; }

		template<typename... Ts>
		static constexpr auto & iaux(one_cycle_signature<_object<Ts>...> & s)		{ return *s.aux; }

	// msg:

		template<typename... Ts>
		static constexpr auto & dmsg(one_cycle_signature<_object<Ts>...> & s)		{ return s.msg; }

		template<typename... Ts>
		static constexpr auto & imsg(one_cycle_signature<_object<Ts>...> & s)		{ return *s.msg; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// out, in, end:

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
		_object < OutType >,
		_object < InType  >,
		_object < EndType >
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

			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, dout);
			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, iout);
			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, din);
			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, iin);
			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, dend);
			friend NIK_DECLARE_OUT_IN_END_ONE_CYCLE_ACCESSOR(auto, iend);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

