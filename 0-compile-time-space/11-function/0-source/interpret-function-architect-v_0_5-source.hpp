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

// function source:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// reflection:

/***********************************************************************************************************************/

// match:

	struct S_is_function
	{
		template<typename T>
		static constexpr bool f_result(T) { return false; }

		template<typename OutType, typename... InTypes>
		static constexpr bool f_result(OutType(*f)(InTypes...)) { return true; }

		template<auto f>
		static constexpr bool result = f_result(f);
	};

	static constexpr auto U_is_function = functor_module::template U_type_T<S_is_function>;

	template<auto f>
	static constexpr bool is_function = S_is_function::f_result(f);

/***********************************************************************************************************************/

// arity:

	struct S_arity
	{
		template<typename OutType, typename... InTypes>
		static constexpr auto f_result(OutType(*f)(InTypes...))
		{
			return sizeof...(InTypes);
		}

		template<auto f>
		static constexpr auto result = f_result(f);
	};

	static constexpr auto U_arity = functor_module::template U_type_T<S_arity>;

	template<auto f>
	static constexpr auto arity = S_arity::f_result(f);

/***********************************************************************************************************************/

// is n-ary:

	struct S_is_n_ary
	{
		template<auto f, auto n>
		static constexpr bool result = (S_arity::f_result(f) == n);
	};

	static constexpr auto U_is_n_ary = functor_module::template U_type_T<S_is_n_ary>;

	template<auto f, auto n>
	static constexpr bool is_n_ary = (S_arity::f_result(f) == n);

/***********************************************************************************************************************/

// out type:

	struct S_out_type
	{
		template<typename OutType, typename... InTypes>
		static constexpr auto f_result(OutType(*f)(InTypes...))
		{
			return functor_module::template U_type_T<OutType>;
		}

		template<auto f>
		static constexpr auto result = f_result(f);
	};

	static constexpr auto U_out_type = functor_module::template U_type_T<S_out_type>;

	template<auto f>
	using out_type = typename functor_module::template T_type_U
	<
		S_out_type::f_result(f)
	>;

/***********************************************************************************************************************/

// in type:

	struct S_in_type
	{
		template<auto depth, auto pos, typename OutType, typename... InTypes>
		static constexpr auto f_result(OutType(*f)(InTypes...))
		{
			return pack_module::at<depth, pos, functor_module::template U_type_T<InTypes>...>;
		}

		template<auto depth, auto pos, auto f>
		static constexpr auto result = f_result<depth, pos>(f);
	};

	static constexpr auto U_in_type = functor_module::template U_type_T<S_in_type>;

	template<auto f, depth_type pos = 0, depth_type depth = 500>
	using in_type = typename functor_module::template T_type_U
	<
		S_in_type::template f_result<depth, pos>(f)
	>;

/***********************************************************************************************************************/

// in types:

	struct S_in_types
	{
		template<typename OutType, typename... InTypes>
		static constexpr auto f_result(OutType(*f)(InTypes...))
		{
			return functor_module::template U_pack_Vs
			<
				functor_module::template U_type_T<InTypes>...
			>;
		}

		template<auto f>
		static constexpr auto result = f_result(f);
	};

	static constexpr auto U_in_types = functor_module::template U_type_T<S_in_types>;

	template<auto f>
	using in_types = typename functor_module::template T_type_U
	<
		S_in_types::f_result(f)
	>;

/***********************************************************************************************************************/

// in types left:

	struct S_in_types_left
	{
		template<auto depth, auto pos, typename OutType, typename... InTypes>
		static constexpr auto f_result(OutType(*f)(InTypes...))
		{
			return pack_module::left<depth, pos, functor_module::template U_type_T<InTypes>...>;
		}

		template<auto depth, auto pos, auto f>
		static constexpr auto result = f_result<depth, pos>(f);
	};

	static constexpr auto U_in_types_left = functor_module::template U_type_T<S_in_types_left>;

	template<auto f, depth_type pos, depth_type depth = 500>
	using in_types_left = typename functor_module::template T_type_U
	<
		S_in_types_left::template f_result<depth, pos>(f)
	>;

/***********************************************************************************************************************/

// in types right:

	struct S_in_types_right
	{
		template<auto depth, auto pos, typename OutType, typename... InTypes>
		static constexpr auto f_result(OutType(*f)(InTypes...))
		{
			return pack_module::right<depth, pos, functor_module::template U_type_T<InTypes>...>;
		}

		template<auto depth, auto pos, auto f>
		static constexpr auto result = f_result<depth, pos>(f);
	};

	static constexpr auto U_in_types_right = functor_module::template U_type_T<S_in_types_right>;

	template<auto f, depth_type pos, depth_type depth = 500>
	using in_types_right = typename functor_module::template T_type_U
	<
		S_in_types_right::template f_result<depth, pos>(f)
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

