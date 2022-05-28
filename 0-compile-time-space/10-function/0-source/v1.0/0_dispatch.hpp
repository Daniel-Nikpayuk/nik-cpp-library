/************************************************************************************************************************
**
** Copyright 2021-2022 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

// dispatch source:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attributes:

/***********************************************************************************************************************/

	struct Argument
	{
		nik_ces auto to_val		= cons < Constant::from_const , Reference::from_reference >;
		nik_ces auto to_ref		= cons < Constant::from_const , Reference::to_reference   >;
		nik_ces auto to_cval		= cons < Constant::to_const   , Reference::from_reference >;
		nik_ces auto to_cref		= cons < Constant::to_const   , Reference::to_reference   >;
	};

/***********************************************************************************************************************/

	template<auto p> nik_ces bool arg_is_to_const		= constant_module::template is_to_const<car<p>>;
	template<auto p> nik_ces bool arg_is_from_const	= constant_module::template is_from_const<car<p>>;

	template<auto p> nik_ces bool arg_is_to_reference	= reference_module::template is_to_reference<cdr<p>>;
	template<auto p> nik_ces bool arg_is_from_reference	= reference_module::template is_from_reference<cdr<p>>;

	//

	template<auto p> nik_ces bool arg_is_to_val	= store_module::template V_equal_VxV<p, Argument::to_val>;
	template<auto p> nik_ces bool arg_is_to_ref	= store_module::template V_equal_VxV<p, Argument::to_ref>;
	template<auto p> nik_ces bool arg_is_to_cval	= store_module::template V_equal_VxV<p, Argument::to_cval>;
	template<auto p> nik_ces bool arg_is_to_cref	= store_module::template V_equal_VxV<p, Argument::to_cref>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// modify:

private:

	template<typename, auto> struct modify;

	// to val:

		template<typename T>
		struct modify<T, Argument::to_val>
		{
			using type	= T;
		};

		template<typename T>
		struct modify<T&, Argument::to_val>
		{
			using type	= T;
		};

		template<typename T>
		struct modify<T const, Argument::to_val>
		{
			using type	= T;
		};

		template<typename T>
		struct modify<T const &, Argument::to_val>
		{
			using type	= T;
		};

	// to ref:

		template<typename T>
		struct modify<T, Argument::to_ref>
		{
			using type	= T&;
		};

		template<typename T>
		struct modify<T&, Argument::to_ref>
		{
			using type	= T&;
		};

		template<typename T>
		struct modify<T const, Argument::to_ref>
		{
			using type	= T&;
		};

		template<typename T>
		struct modify<T const &, Argument::to_ref>
		{
			using type	= T&;
		};

	// to cval:

		template<typename T>
		struct modify<T, Argument::to_cval>
		{
			using type	= T const;
		};

		template<typename T>
		struct modify<T&, Argument::to_cval>
		{
			using type	= T const;
		};

		template<typename T>
		struct modify<T const, Argument::to_cval>
		{
			using type	= T const;
		};

		template<typename T>
		struct modify<T const &, Argument::to_cval>
		{
			using type	= T const;
		};

	// to cref:

		template<typename T>
		struct modify<T, Argument::to_cref>
		{
			using type	= T const &;
		};

		template<typename T>
		struct modify<T&, Argument::to_cref>
		{
			using type	= T const &;
		};

		template<typename T>
		struct modify<T const, Argument::to_cref>
		{
			using type	= T const &;
		};

		template<typename T>
		struct modify<T const &, Argument::to_cref>
		{
			using type	= T const &;
		};

public:

	template<typename T, auto a>
	using T_arg_modify_TxV = typename modify<T, a>::type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatchers:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specialize:

/***********************************************************************************************************************/

public:

	template<auto J, typename... Ts>
	nik_ces auto specialize = store_module::T_store_U<J>::template result<Ts...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// resolve:

/***********************************************************************************************************************/

private:

	template<auto J, template<typename...> class ListName, typename... Ts>
	nik_ces auto f_resolve(nik_avpcr(ListName<Ts...>*))
	{
		return store_module::T_store_U<J>::template result<Ts...>;
	}

public:

	template<auto J, typename List>
	nik_ces auto resolve = f_resolve<J>(store_module::template U_store_T<List>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

