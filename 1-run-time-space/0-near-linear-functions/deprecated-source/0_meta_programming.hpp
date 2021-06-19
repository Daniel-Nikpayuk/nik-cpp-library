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

// template metaprogramming:

/*
	R   - trampoline_list				(typename)
	S   - value_list				(typename)
	T   - type					(typename)
	U   - type_map					(constexpr auto)
	V   - value					(constexpr auto)

	G   - template<typename> class
	F   - template<auto> class

	E   - template<typename, typename> class
	D   - template<typename, auto> class
	C   - template<auto, typename> class
	B   - template<auto, auto> class
*/

/***********************************************************************************************************************/

namespace nlfs_0
{

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

	constexpr void _na_()						{ }	// (not applicable auto)
	struct _NA_							{ };	// (not applicable typename)
	template<auto...> using _NAT_					= _NA_;	// (not applicable template)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// typename category:

/***********************************************************************************************************************/

	struct S__Vs
	{
		template<auto...> struct result				{ };
		template<auto V> struct result<V>			{ static constexpr auto value = V; };
		template<auto V1, auto V2> struct result<V1, V2>	{ static constexpr bool match = false; };
		template<auto V> struct result<V, V>			{ static constexpr bool match = true; };
	};

	struct R__Vs
	{
		template<auto...> struct result				{ };
	};

	//

	template<auto V>
	using S_value_V = S__Vs::template result<V>;

	template<typename V>
	constexpr auto V_value_S = V::value;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// debugging:

/***********************************************************************************************************************/

	template<typename T> using force_static_assert	= S_value_V<T::template result<false>()>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// boolean type:

/***********************************************************************************************************************/

	using S_false							= S_value_V<false>;
	using S_true							= S_value_V<true>;

	template<bool Predicate, auto = _na_> using S_boolean		= S_value_V<Predicate>;

	template<bool V, auto = _na_> using S_boolean_not		= S_value_V<!V>;
	template<bool V1, bool V2> using S_boolean_and			= S_value_V<V1 && V2>;
	template<bool V1, bool V2> using S_boolean_or			= S_value_V<V1 || V2>;

	template<bool V, auto = _na_> constexpr bool V_boolean_not	= ! V;
	template<bool V1, bool V2> constexpr bool V_boolean_and		= V1 && V2;
	template<bool V1, bool V2> constexpr bool V_boolean_or		= V1 || V2;

/***********************************************************************************************************************/

// true:

	template<bool True, auto = _na_>
	struct pattern_match_bool
	{
		// value:

			template<auto Antecedent, auto Consequent>
			static constexpr auto V_then_else_VxV = Antecedent;

		// type:

			template<typename Antecedent, typename Consequent>
			using T_then_else_TxT = Antecedent;
	};

/***********************************************************************************************************************/

// false:

	template<auto NA>
	struct pattern_match_bool<false, NA>
	{
		// value:

			template<auto Antecedent, auto Consequent>
			static constexpr auto V_then_else_VxV = Consequent;

		// type:

			template<typename Antecedent, typename Consequent>
			using T_then_else_TxT = Consequent;
	};

/***********************************************************************************************************************/

// if then else:

	// value:

		template<bool Predicate, auto Antecedent, auto Consequent>
		constexpr auto V_if_then_else = pattern_match_bool<Predicate>::template
			V_then_else_VxV<Antecedent, Consequent>;

	// type:

		template<bool Predicate, typename Antecedent, typename Consequent>
		using T_if_then_else = typename pattern_match_bool<Predicate>::template
			T_then_else_TxT<Antecedent, Consequent>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pointer type:

/***********************************************************************************************************************/

	template<typename>
	struct pattern_match_pointer
	{
		static constexpr bool match		= false;
	};

	template<typename T>
	struct pattern_match_pointer<T*>
	{
		static constexpr bool match		= true;

		using type				= T;
	};

/***********************************************************************************************************************/

	template<typename T>
	constexpr bool V_is_pointer_T			= pattern_match_pointer<T>::match;

	//

	template<typename T>
	using T_pointer_T				= T*;

	template<typename Pointer>
	using T_pointer_type_T				= typename pattern_match_pointer<Pointer>::type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// reference type:

/***********************************************************************************************************************/

	template<typename>
	struct pattern_match_reference
	{
		static constexpr bool match		= false;
	};

	template<typename T>
	struct pattern_match_reference<T&>
	{
		static constexpr bool match		= true;

		using type				= T;
	};

/***********************************************************************************************************************/

	template<typename T>
	constexpr bool V_is_reference_T			= pattern_match_reference<T>::match;

	//

	template<typename T>
	using T_reference_T				= T&;

	template<typename Reference>
	using T_reference_type_T			= typename pattern_match_reference<Reference>::type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// auto category:

/***********************************************************************************************************************/

// hold:

	struct hold_ante
	{
		template<typename Antecedent, template<typename> class Function, typename Consequent>
		using T_hold_TxGxT = Antecedent;
	};

	struct hold_conse
	{
		template<typename Antecedent, template<typename> class Function, typename Consequent>
		using T_hold_TxGxT = Function<Consequent>;
	};

	//

	template<bool Predicate, typename Antecedent, template<typename> class Function, typename Consequent>
	using T_hold = typename T_if_then_else
	<
		Predicate,

			hold_ante, hold_conse

	>::template T_hold_TxGxT
	<
		Antecedent, Function, Consequent
	>;

/***********************************************************************************************************************/

// typename to auto (functor):

	template<typename T>
	constexpr void type_map(T)			{ }			// Unsafe to use directly,
										// as T cannot equal void.
										// use the following instead:

	template<typename T>
	constexpr auto U_type_T		 		= type_map		// This implementation was chosen
							<			// as it simplifies the special
								T_hold		// case when T == void.
								<
									V_is_reference_T<T>,

									T,
									T_pointer_T, T
								>
							>;

	template<typename T>				// T_decltype(_type)_T:
	using T_decltype_T				= decltype(U_type_T<T>);

	template<auto V>				// U_(type_)decltype_V:
	constexpr auto U_decltype_V	 		= U_type_T<decltype(V)>;

	//

	template<auto, auto = _na_>
	struct pattern_match_type_map
	{
		static constexpr bool match		= false;
	};

	template<typename T, void(*f)(T*), auto NA>
	struct pattern_match_type_map<f, NA>
	{
		static constexpr bool match		= true;

		using type				= T;
	};

	template<typename T, void(*f)(T&), auto NA>
	struct pattern_match_type_map<f, NA>
	{
		static constexpr bool match		= true;

		using type				= T&;
	};

	template<auto TMap>
	using T_type_U			 		= typename pattern_match_type_map<TMap>::type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic:

/***********************************************************************************************************************/

// empty:

	template<typename... Ts> constexpr bool V_empty_Ts				= ! bool(sizeof...(Ts));
	template<template<auto, auto> class... Bs> constexpr bool V_empty_Bs		= ! bool(sizeof...(Bs));

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// colist type:

/***********************************************************************************************************************/

	struct template_list_colist
	{
		struct halt
		{
			template
			<
				typename Colist,
			// halt:
				typename Default1,
			// cont:
				auto V11, auto V12,		auto V21, auto V22,	typename Default2,

				template<auto, auto> class... Aliases
			>
			using result = Default1;
		};

		struct cont
		{
			struct sub_halt
			{
				template
				<
					typename Colist,
				// halt:
					template<auto, auto> class Break, auto V11, auto V12,
				// cont:
					auto V21, auto V22,		auto V31, auto V32,	typename Default,

					template<auto, auto> class... Aliases
				>
				using result = Break<V11, V12>;
			};

			struct sub_cont
			{
				template
				<
					typename Colist,
				// halt:
					template<auto, auto> class Break, auto V11, auto V12,
				// cont:
					auto V21, auto V22,		auto V31, auto V32,	typename Default,

					template<auto, auto> class... Aliases
				>
				using result = typename Colist::template result
				<
					V21, V22,	V31, V32,	Default,

					Aliases...
				>;
			};

			template
			<
				typename Colist,
			// halt:
				typename Default1,
			// cont:
				auto V11, auto V12,		auto V21, auto V22,	typename Default2,

				template<auto, auto> class Policy,	template<auto, auto> class Break,

				template<auto, auto> class... Aliases
			>
			using result = typename T_if_then_else
			<
				V_value_S<Policy<V11, V12>>,

					sub_halt, sub_cont

			>::template result
			<
				Colist,
			// halt:
				Break, V21, V22,
			// cont:
				V11, V12,	V21, V22,	Default2,

				Aliases...
			>;
		};

		template
		<
			auto V11, auto V12,		auto V21, auto V22,	typename Default,

			template<auto, auto> class... Aliases
		>
		using result = typename T_if_then_else
		<
			V_empty_Bs<Aliases...>, halt, cont

		>::template result
		<
			template_list_colist,
		// halt:
			Default,
		// cont:
			V11, V12,	V21, V22,	Default,

			Aliases...
		>;
	};

/***********************************************************************************************************************/

// type:

	template
	<
		auto V11, auto V12,
		auto V21, auto V22,
		template<auto, auto> class... Aliases
	>
	using T_colist_Bs = typename template_list_colist::template result
	<
		V11, V12, V21, V22, _NA_, Aliases...
	>;

/***********************************************************************************************************************/

// value:

	template
	<
		auto V11, auto V12,
		auto V21, auto V22,
		template<auto, auto> class... Aliases
	>
	constexpr auto V_colist_Bs = V_value_S
	<
		typename template_list_colist::template result
		<
			V11, V12, V21, V22, _NA_, Aliases...
		>
	>;

/***********************************************************************************************************************/

	template<auto, auto> using otherwise		= S_true;
	template<auto, auto> using return_false		= S_false;
	template<auto, auto> using return_true		= S_true;

	template<auto, auto> using return_void		= void;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identity type:

/***********************************************************************************************************************/

	template<auto V1, auto V2>
	constexpr bool V_equal_VxV			= S__Vs::template result<V1, V2>::match;

	template<auto V1, auto V2>
	using S_equal_VxV				= S_boolean<V_equal_VxV<V1, V2>>;

/***********************************************************************************************************************/

	template<typename T1, typename T2>
	constexpr bool V_is_equal_UxU(void(*)(T1), void(*)(T2))	// Unsafe to use directly,
		{ return false; }

	template<typename T>
	constexpr bool V_is_equal_UxU(void(*)(T), void(*)(T))	// Use the following instead:
		{ return true; }

	//

	template<typename T1, typename T2>
	constexpr bool V_equal_TxT			= V_is_equal_UxU(U_type_T<T1>, U_type_T<T2>);

	template<typename T1, typename T2>
	using S_equal_TxT				= S_boolean<V_is_equal_UxU(U_type_T<T1>, U_type_T<T2>)>;

/***********************************************************************************************************************/

	template<auto TMap1, auto TMap2>
	constexpr bool V_equal_UxU			= V_is_equal_UxU(TMap1, TMap2);

	template<auto TMap1, auto TMap2>
	using S_equal_UxU				= S_boolean<V_is_equal_UxU(TMap1, TMap2)>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identifiers (convenience aliases):

/***********************************************************************************************************************/

	constexpr auto U_void						= U_type_T<void>;
	constexpr auto U_char_ptr					= U_type_T<char*>;

/***********************************************************************************************************************/

	template<auto T, auto = _na_> using S_equals_void		= S_equal_UxU<T, U_void>;

	template<auto T1, auto T2> using S_left_equals_void		= S_equal_UxU<T1, U_void>;
	template<auto T1, auto T2> using S_right_equals_void		= S_equal_UxU<T2, U_void>;

	//

	template<auto T> constexpr bool V_equals_char_ptr		= V_equal_UxU<T, U_char_ptr>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// higher continuations:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// lift:

	template<template<typename, auto...> class F, auto> struct mp_lift;

	template<template<typename, auto...> class F>
	struct mp_lift<F, 0>
	{
		template<typename C, auto... Vs>
		using result = F<C, Vs...>;
	};

	template<template<typename, auto...> class F>
	struct mp_lift<F, 1>
	{
		template<typename C, auto V1, auto... Vs>
		using result = F<C, V1, Vs...>;
	};

	template<template<typename, auto...> class F>
	struct mp_lift<F, 2>
	{
		template<typename C, auto V1, auto V2, auto... Vs>
		using result = F<C, V1, V2, Vs...>;
	};

	template<template<typename, auto...> class F>
	struct mp_lift<F, 3>
	{
		template<typename C, auto V1, auto V2, auto V3, auto... Vs>
		using result = F<C, V1, V2, V3, Vs...>;
	};

	template<template<typename, auto...> class F, auto skip>
	struct mp_lift
	{
		template<typename C, auto V1, auto V2, auto V3, auto V4, auto... Vs>
		using result = F<C, V1, V2, V3, V4, Vs...>;
	};

/***********************************************************************************************************************/

// stem:

	template
	<
		template<typename, auto...> class Policy, auto p_skip,
		template<typename, auto...> class Break, auto b_skip,
		template<typename, auto...> class Next, auto n_skip,

		typename Halt = S__Vs
	>
	struct mp_stem
	{
		using test = mp_lift<Policy, p_skip>;
		using halt = mp_lift<Break, b_skip>;
		using cont = mp_lift<Next, n_skip>;

		template<bool pred, typename Cont, auto... Vs>
		using let_result = typename T_if_then_else<pred, halt, cont>::template result
		<
			T_if_then_else<pred, Halt, Cont>, Vs...
		>;

		template<auto... Vs>
		static constexpr bool policy = V_value_S // required to match parameter pack:
		<
			typename test::template result<S__Vs, Vs...>
		>;

		template<typename Cont, auto... Vs>
		using result = let_result
		<
			policy<Vs...>, Cont, Vs...
		>;
	};

/***********************************************************************************************************************/

// costem:

	template
	<
		template<typename, auto...> class Policy, auto p_skip,
		template<typename, auto...> class Next, auto n_skip,
		template<typename, auto...> class Break, auto b_skip,

		typename Halt = S__Vs
	>
	struct mp_costem
	{
		using test = mp_lift<Policy, p_skip>;
		using cont = mp_lift<Next, n_skip>;
		using halt = mp_lift<Break, b_skip>;

		template<bool pred, typename Cont, auto... Vs>
		using let_result = typename T_if_then_else<pred, cont, halt>::template result
		<
			T_if_then_else<pred, Cont, Halt>, Vs...
		>;

		template<auto... Vs>
		static constexpr bool policy = V_value_S // required to match parameter pack:
		<
			typename test::template result<S__Vs, Vs...>
		>;

		template<typename Cont, auto... Vs>
		using result = let_result
		<
			policy<Vs...>, Cont, Vs...
		>;
	};

/***********************************************************************************************************************/

// distem:

	template
	<
		template<typename, auto...> class Policy, auto p_skip,
		template<typename, auto...> class Next1, auto n1_skip,
		template<typename, auto...> class Next2, auto n2_skip,

		typename Halt = S__Vs
	>
	struct mp_distem
	{
		using test = mp_lift<Policy, p_skip>;
		using cont1 = mp_lift<Next1, n1_skip>;
		using cont2 = mp_lift<Next2, n2_skip>;

		template<auto... Vs>
		static constexpr bool policy = V_value_S // required to match parameter pack:
		<
			typename test::template result<S__Vs, Vs...>
		>;

		template<typename Cont, auto... Vs>
		using result = typename T_if_then_else
		<
			policy<Vs...>, cont1, cont2

		>::template result<Cont, Vs...>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// endopose:

	// continuation passing monadic composition:

	//	f(x, c1(y))  endopose  g(y, c2(z))    :=    f(x, \y -> g(y, c2(z)))

	template<typename CP__F, typename CP__G>
	struct endopose
	{
		template<typename Cont>
		struct Lambda_G
		{
			template<auto... Vs>
			using result = typename CP__G::template result
			<
				Cont, Vs...
			>;
		};

		template<typename Cont, auto... Vs>
		using result = typename CP__F::template result
		<
			Lambda_G<Cont>, Vs...
		>;
	};

/***********************************************************************************************************************/

// chain endopose:

	struct type_list_chain_endopose
	{
		struct halt
		{
			template
			<
				typename ChainEndopose, typename Chain,

				typename... CP__Fs
			>
			using result = Chain;
		};

		struct cont
		{
			template
			<
				typename ChainEndopose, typename Chain,

				typename CP__F, typename... CP__Fs
			>
			using result = typename ChainEndopose::template result
			<
				endopose<Chain, CP__F>, CP__Fs...
			>;
		};

		template
		<
			typename Chain, typename... CP__Fs
		>
		using result = typename T_if_then_else
		<
			V_empty_Ts<CP__Fs...>, halt, cont

		>::template result
		<
			type_list_chain_endopose, Chain,

			CP__Fs...
		>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// continuation aliases:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

// is zero:

	template<typename C, auto n, auto...> using m1_is_zero		= typename C::template result<(n == 0)>;

/***********************************************************************************************************************/

// is empty:

	template<typename C, auto... Vs> using m0_is_empty		= typename C::template result<!bool(sizeof...(Vs))>;

/***********************************************************************************************************************/

// is length:

	template<typename C, auto... Vs> using m0_is_length_1		= typename C::template result<sizeof...(Vs) == 1>;
	template<typename C, auto... Vs> using m0_is_length_2		= typename C::template result<sizeof...(Vs) == 2>;
	template<typename C, auto... Vs> using m0_is_length_3		= typename C::template result<sizeof...(Vs) == 3>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// functions:

/***********************************************************************************************************************/

// id:

	template<typename C, auto... Vs> using m0_id			= typename C::template result<Vs...>;

/***********************************************************************************************************************/

// functor:

	template<typename C, auto U, auto...> using m1_to_type		= T_type_U<U>;

/***********************************************************************************************************************/

// length:

	template<typename C, auto... Vs> using m0_length		= typename C::template result<sizeof...(Vs)>;

/***********************************************************************************************************************/

// cons:

	template<typename C, auto... Vs> using m0_cons			= typename C::template result<Vs...>;
	template<typename C, auto, auto... Vs> using m1_cons		= typename C::template result<Vs...>;

/***********************************************************************************************************************/

// car:

	template<typename C, auto V, auto... Vs> using m1_car			= typename C::template result<V>;
	template<typename C, auto, auto V, auto... Vs> using m2_car		= typename C::template result<V>;
	template<typename C, auto, auto, auto V, auto... Vs> using m3_car	= typename C::template result<V>;

/***********************************************************************************************************************/

// cdr:

	template<typename C, auto V, auto... Vs> using m1_cdr			= typename C::template result<Vs...>;
	template<typename C, auto, auto V, auto... Vs> using m2_cdr		= typename C::template result<Vs...>;

/***********************************************************************************************************************/

// increment:

	template<typename C, auto n, auto... Vs> using m1_increment		= typename C::template result<n+1, Vs...>;

/***********************************************************************************************************************/

// decrement:

	template<typename C, auto n, auto... Vs> using m1_decrement		= typename C::template result<n-1, Vs...>;

/***********************************************************************************************************************/

// monoids:

	template<typename C, auto op, auto V1, auto V2, auto... Vs>
		using m3_binary = typename C::template result<op, op(V1, V2), Vs...>;

	template<typename C, auto V0, auto op, auto V1, auto V2, auto... Vs>
		using m4_binary = typename C::template result<V0, op, op(V1, V2), Vs...>;

/***********************************************************************************************************************/

// compositions (optimizations):

	template<typename C, auto n, auto V, auto... Vs> using m2_dec_cdr	= typename C::template result<n-1, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// applications:

/***********************************************************************************************************************/

// inductor:

	template<typename... CP__Fs>
	using mp_inductor = typename type_list_chain_endopose::template result
	<
		mp_lift<m0_id, 0>, CP__Fs...
	>;

/***********************************************************************************************************************/

// recursive inductor:

	template<typename Inductor>
	struct mp_recursive_inductor
	{
		template<auto... Vs>
		using result = typename Inductor::template result<mp_recursive_inductor, Vs...>;
	};

/***********************************************************************************************************************/

// apply:

	template<typename Inductor, auto... Vs>
	using S_apply = typename Inductor::template result<S__Vs, Vs...>;

	template<typename Inductor, auto... Vs>
	constexpr auto V_apply = V_value_S
	<
		typename Inductor::template result<S__Vs, Vs...>
	>;

/***********************************************************************************************************************/

// recursive apply:

	template<typename Inductor, auto... Vs>
	using S_recursive_apply = typename mp_recursive_inductor<Inductor>::template result<Vs...>;

	template<typename Inductor, auto... Vs>
	constexpr auto V_recursive_apply = V_value_S
	<
		typename mp_recursive_inductor<Inductor>::template result<Vs...>
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// auto list:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<auto... Vs> using value_list			= typename S__Vs::template result<Vs...>;
	template<typename... Ts> using type_list		= typename S__Vs::template result<U_type_T<Ts>...>;

	template<auto... Vs> using trampoline_list		= typename R__Vs::template result<Vs...>;

/***********************************************************************************************************************/

	template<typename>
	struct pattern_match_auto_list
	{
		template
		<
			template
			<
				bool, template<auto...> class, auto...

			> class Continuation
		>
		using induct = Continuation<false, _NAT_>;
	};

	template<template<auto...> class ListName, auto... Vs>
	struct pattern_match_auto_list<ListName<Vs...>>
	{
		template
		<
			template
			<
				bool, template<auto...> class, auto...

			> class Continuation, auto... Args
		>
		using rinduct = Continuation<true, ListName, Vs..., Args...>;

		template
		<
			template
			<
				bool, template<auto...> class, auto...

			> class Continuation, auto... Args
		>
		using induct = Continuation<true, ListName, Args..., Vs...>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// inductor cache:

/***********************************************************************************************************************/

	template<template<bool, template<auto...> class, auto...> class, auto> struct list_inductor_cache;

	template<template<bool, template<auto...> class, auto...> class op_cont>
	struct list_inductor_cache<op_cont, 0>
	{
		template<bool m, template<auto...> class name, auto... Vs>
		using result = op_cont<m, name, Vs...>;
	};

	template<template<bool, template<auto...> class, auto...> class op_cont>
	struct list_inductor_cache<op_cont, 1>
	{
		template<bool m, template<auto...> class name, auto V1, auto... Vs>
		using result = op_cont<m, name, V1, Vs...>;
	};

	template<template<bool, template<auto...> class, auto...> class op_cont>
	struct list_inductor_cache<op_cont, 2>
	{
		template<bool m, template<auto...> class name, auto V1, auto V2, auto... Vs>
		using result = op_cont<m, name, V1, V2, Vs...>;
	};

	template<template<bool, template<auto...> class, auto...> class op_cont>
	struct list_inductor_cache<op_cont, 3>
	{
		template<bool m, template<auto...> class name, auto V1, auto V2, auto V3, auto... Vs>
		using result = op_cont<m, name, V1, V2, V3, Vs...>;
	};

	template<template<bool, template<auto...> class, auto...> class op_cont, auto skip>
	struct list_inductor_cache
	{
		template<bool m, template<auto...> class name, auto V1, auto V2, auto V3, auto V4, auto... Vs>
		using result = op_cont<m, name, V1, V2, V3, V4, Vs...>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// list procedures:

/***********************************************************************************************************************/

// length:

	template<bool, template<auto...> class ListName, auto... Vs>
	using auto_list_length_cont = S_value_V<sizeof...(Vs)>;

	template<typename List>
	using auto_list_length = typename pattern_match_auto_list<List>::template induct
	<
		auto_list_length_cont
	>;

/***********************************************************************************************************************/

// cons:

	template<bool, template<auto...> class ListName, auto... Vs>
	using auto_list_cons_cont = ListName<Vs...>;

	//

	template<bool, template<auto...> class ListName, auto... Vs>
	using auto_list_to_null_cont = ListName<>;

	template<typename List>
	using auto_list_to_null = typename pattern_match_auto_list<List>::template induct
	<
		auto_list_to_null_cont
	>;

/***********************************************************************************************************************/

// car:

	template<bool, template<auto...> class ListName, auto pos, auto... Vs>
	using auto_list_car_cont = S_recursive_apply
	<
		mp_inductor
		<
			mp_stem    < m1_is_zero , 1 , m2_car , 2 , m2_dec_cdr , 2 >
		>,

		pos, Vs...
	>;

	template<typename List, auto pos = 0>
	using auto_list_car = typename pattern_match_auto_list<List>::template induct
	<
		auto_list_car_cont, pos
	>;

	template<typename List, auto pos = 0> constexpr auto V_auto_list_car = V_value_S<auto_list_car<List, pos>>;

/***********************************************************************************************************************/

// cdr:

	template<bool, template<auto...> class ListName, auto pos, auto... Vs>
	using auto_list_cdr_cont = S_recursive_apply
	<
		mp_inductor
		<
			mp_stem    < m1_is_zero , 1 , m2_cdr , 2 , m2_dec_cdr , 2 >
		>,

		pos, Vs...
	>;

	template<typename List, auto pos = 0>
	using auto_list_cdr = typename pattern_match_auto_list<List>::template induct
	<
		auto_list_cdr_cont, pos + 1
	>;

/***********************************************************************************************************************/

// catenate:

	template<template<auto...> class ListName, auto List, auto... Vs>
	using auto_list_catenate_cont = typename pattern_match_auto_list<T_type_U<List>>::template induct
	<
		auto_list_cons_cont, Vs...
	>;

	template<typename List1, typename List2>
	using auto_list_catenate = typename pattern_match_auto_list<List1>::template induct
	<
		auto_list_catenate_cont, U_type_T<List2>
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// trampoline:

/***********************************************************************************************************************/

	template<typename C, auto List, auto...>
	using m1_not_trampoline = typename C::template result
	<
		! V_equal_TxT<auto_list_to_null<T_type_U<List>>, trampoline_list<>>
	>;

	template<typename C, auto List, auto op_cont, auto depth, auto...>
	using m3_list_induct = typename C::template result
	<
		U_type_T<typename pattern_match_auto_list<T_type_U<List>>::template
			induct<T_type_U<op_cont>::template result, depth>>, op_cont, depth
	>;

	template<typename List, template<bool, template<auto...> class, auto...> class op_cont, auto skip, auto depth>
	using trampoline = S_recursive_apply
	<
		mp_inductor
		<
			mp_stem < m1_not_trampoline , 1 , m1_to_type , 1 , m3_list_induct , 3 >
		>,

		U_type_T<List>, U_type_T<list_inductor_cache<op_cont, skip>>, depth
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

