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

// signature alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// objects:

/***********************************************************************************************************************/

// members:

	using nik_name(NIK_PREFIX, OneCycleMember)			= typename NIK_MODULE::OneCycleMember;

	template<auto m>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_out)			= NIK_MODULE::template V_is_out<m>;

	template<auto m>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_in)			= NIK_MODULE::template V_is_in<m>;

	template<auto m>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_car_in)		= NIK_MODULE::template V_is_car_in<m>;

	template<auto m>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_cdr_in)		= NIK_MODULE::template V_is_cdr_in<m>;

	template<auto m>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_end)			= NIK_MODULE::template V_is_end<m>;

	template<auto m>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_aux)			= NIK_MODULE::template V_is_aux<m>;

	template<auto m>
	NIK_POLICY auto nik_name(NIK_PREFIX, V_is_msg)			= NIK_MODULE::template V_is_msg<m>;

// kinds:

	template<typename T>
	using nik_name(NIK_PREFIX, _out_object)			= typename NIK_MODULE::template _out_object<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, _in_object)			= typename NIK_MODULE::template _in_object<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, _car_in_object)		= typename NIK_MODULE::template _car_in_object<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, _cdr_in_object)		= typename NIK_MODULE::template _cdr_in_object<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, _end_object)			= typename NIK_MODULE::template _end_object<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, _aux_object)			= typename NIK_MODULE::template _aux_object<T>;

	template<typename T>
	using nik_name(NIK_PREFIX, _msg_object)			= typename NIK_MODULE::template _msg_object<T>;

/***********************************************************************************************************************/

// signature:

	template<typename... Ts>
	using nik_name(NIK_PREFIX, one_cycle)			= typename NIK_MODULE::template one_cycle<Ts...>;

// accessors:

	// out:

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, out_ref)(Signature & s)
		{ return NIK_MODULE::out_ref(s); }

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, out_deref)(Signature & s)
		{ return NIK_MODULE::out_deref(s); }

	// in:

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, in_ref)(Signature & s)
		{ return NIK_MODULE::in_ref(s); }

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, in_deref)(Signature & s)
		{ return NIK_MODULE::in_deref(s); }

	// car in:

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, car_in_ref)(Signature & s)
		{ return NIK_MODULE::car_in_ref(s); }

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, car_in_deref)(Signature & s)
		{ return NIK_MODULE::car_in_deref(s); }

	// cdr in:

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, cdr_in_ref)(Signature & s)
		{ return NIK_MODULE::cdr_in_ref(s); }

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, cdr_in_deref)(Signature & s)
		{ return NIK_MODULE::cdr_in_deref(s); }

	// end:

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, end_ref)(Signature & s)
		{ return NIK_MODULE::end_ref(s); }

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, end_deref)(Signature & s)
		{ return NIK_MODULE::end_deref(s); }

	// aux:

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, aux_ref)(Signature & s)
		{ return NIK_MODULE::aux_ref(s); }

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, aux_deref)(Signature & s)
		{ return NIK_MODULE::aux_deref(s); }

	// msg:

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, msg_ref)(Signature & s)
		{ return NIK_MODULE::msg_ref(s); }

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, msg_deref)(Signature & s)
		{ return NIK_MODULE::msg_deref(s); }

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

