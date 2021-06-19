/************************************************************************************************************************
**
** Copyright 2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of near_linear_function_space.
**
** near_linear_function_space is free software: you can redistribute it and/or modify it under the terms
** of the GNU General Public License as published by the Free Software Foundation, either version 3
** of the License, or (at your option) any later version.
**
** near_linear_function_space is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
** without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with near_linear_function_space.
** If not, see <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

// near linear induction:

/*
	ch - continuation halting
	cp - continuation passing
*/

// run time (compatible) stem lattice:

/*
	pf - policy_f		p1f  - policy1_f	p2f  - policy2_f
	bf - break_f		b1f  - break1_f		b2f  - break2_f
	nf - next_f		n1f  - next1_f		n2f  - next2_f
				n11f - next11_f		n2f - next2_f
				n12f - next12_f
	cf - cont_f
*/

/***********************************************************************************************************************/

namespace nlfs_2
{
	using namespace nlfs_1;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// continuation passing constructors:

/***********************************************************************************************************************/

// lift:

		// returns a proper identity function rather than the _id_ keyword.

	template<auto f>
	struct cp_lift
	{
		template<auto composed_f, auto Type>
		using let_result = T_colist_Bs
		<
			composed_f, _na_,		Type, composed_f,

			S_is_id_keyword,		return_id,
			otherwise,			return_right_function
		>;

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_value_S
		<
			let_result
			<
				V_compose_opt<cont_f, f>,
				U_type_T<Type>
			>
		>;
	};

	//

	template<bool predicate, auto function1, auto function2 = _id_>
	using cp_if_then_else = cp_lift<V_if_then_else<predicate, function1, function2>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// stem:

/***********************************************************************************************************************/

	template<auto policy_f, auto break_f, auto next_f>
	struct cp_stem
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return break_f(arg);
			else			return next_f(arg);
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return break_f(arg);
			else			return cont_f(next_f(arg));
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

	template<auto policy_f, auto break_f>
	struct cp_stem<policy_f, break_f, _id_>
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return break_f(arg);
			else			return arg;
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return break_f(arg);
			else			return cont_f(arg);
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

	template<auto policy_f, auto next_f>
	struct cp_stem<policy_f, _id_, next_f>
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return arg;
			else			return next_f(arg);
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return arg;
			else			return cont_f(next_f(arg));
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

//*** Assumes policy_f has no side effects:

	template<auto policy_f>
	struct cp_stem<policy_f, _id_, _id_>
	{
	// halting:

		template<auto, auto U>
		using return_halting = S_value_V<id<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return arg;
			else			return cont_f(arg);
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// costem:

/***********************************************************************************************************************/

	template<auto policy_f, auto next_f, auto break_f>
	struct cp_costem
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return next_f(arg);
			else			return break_f(arg);
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return cont_f(next_f(arg));
			else			return break_f(arg);
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

	template<auto policy_f, auto next_f>
	struct cp_costem<policy_f, next_f, _id_>
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return next_f(arg);
			else			return arg;
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return cont_f(next_f(arg));
			else			return arg;
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

	template<auto policy_f, auto break_f>
	struct cp_costem<policy_f, _id_, break_f>
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return arg;
			else			return break_f(arg);
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return cont_f(arg);
			else			return break_f(arg);
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

//*** Assumes policy_f has no side effects:

	template<auto policy_f>
	struct cp_costem<policy_f, _id_, _id_>
	{
	// halting:

		template<auto, auto U>
		using return_halting = S_value_V<id<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return cont_f(arg);
			else			return arg;
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// distem:

/***********************************************************************************************************************/

	template<auto policy_f, auto next1_f, auto next2_f>
	struct cp_distem
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return next1_f(arg);
			else			return next2_f(arg);
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return cont_f(next1_f(arg));
			else			return cont_f(next2_f(arg));
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

	template<auto policy_f, auto next1_f>
	struct cp_distem<policy_f, next1_f, _id_>
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return next1_f(arg);
			else			return arg;
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return cont_f(next1_f(arg));
			else			return cont_f(arg);
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

	template<auto policy_f, auto next2_f>
	struct cp_distem<policy_f, _id_, next2_f>
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return arg;
			else			return next2_f(arg);
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return cont_f(arg);
			else			return cont_f(next2_f(arg));
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

//*** Assumes policy_f has no side effects:

	template<auto policy_f>
	struct cp_distem<policy_f, _id_, _id_>
	{
	// halting:

		template<auto, auto U>
		using return_halting = S_value_V<id<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			return cont_f(arg);
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// endopose:

		// Restricted to functions with the same input and output types.
		// This is limiting in general, but works in this context.

	// continuation passing monadic composition:

	//	f(x, c1(y))  endopose  g(y, c2(z))    :=    f(x, \y -> g(y, c2(z)))

	template<typename StemType1, typename StemType2>
	struct cp_endopose
	{
		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = StemType1::template result
		<
			StemType2::template result<cont_f, Type>,
			Type
		>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// chain endopose:

/***********************************************************************************************************************/

// empty:

	template<typename... Types> constexpr bool V_empty_Ts = ! bool(sizeof...(Types));

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// cp_stem:

/***********************************************************************************************************************/

// true:

	struct cp_chain_endopose_true
	{
		// hold:

			template
			<
			// true:

				typename Default,

			// false:

				template
				<
					typename, typename,
					typename, typename...

				> class Suboperator, typename Operator, typename Current,

				typename... CP_Stems
			>
			using T_hold_Ts = Default;
	};

/***********************************************************************************************************************/

// false:

	struct cp_chain_endopose_false
	{
		// hold:

			template
			<
			// true:

				typename Default,

			// false:

				template
				<
					typename, typename,
					typename, typename...

				> class Suboperator, typename Operator, typename Current,

				typename CP_Stem, typename... CP_Stems
			>
			using T_hold_Ts = Suboperator<Operator, Current, CP_Stem, CP_Stems...>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	struct cp_chain_endopose
	{
		template
		<
			typename ChainEndopose, typename Chain,
			typename CP_Stem, typename... CP_Stems
		>
		using loop = typename ChainEndopose::template result
		<
			cp_endopose<Chain, CP_Stem>, CP_Stems...
		>;

		template
		<
			typename Chain, typename... CP_Stems
		>
		using result = typename T_if_then_else
		<
			V_empty_Ts<CP_Stems...>,

				cp_chain_endopose_true, cp_chain_endopose_false

		>::template T_hold_Ts
		<
			Chain,
			loop, cp_chain_endopose, Chain, CP_Stems...
		>;
	};

/***********************************************************************************************************************/

// inductor:

	template
	<
		typename Type, auto cont_f, typename... CP_Stems
	>
	constexpr Type (*cp_inductor)(Type) = cp_chain_endopose::template result
	<
		cp_lift<_id_>, CP_Stems...

	>::template result<cont_f, Type>;

/***********************************************************************************************************************/

// recursive inductor:

	template
	<
		typename Type, typename... CP_Stems
	>
	constexpr Type cp_recursive_inductor(Type arg)
	{
		return cp_chain_endopose::template result
		<
			cp_lift<_id_>, CP_Stems...

		>::template result<cp_recursive_inductor<Type, CP_Stems...>, Type>(arg);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// cycle inductor:

/***********************************************************************************************************************/

	template
	<
		typename Signature, typename... CP_Stems
	>
	constexpr Signature & precycle(Signature & arg)
	{
		return cp_chain_endopose::template result
		<
			cp_lift<_id_>, CP_Stems...

		>::template result<_id_, Signature &>(arg);
	}

/***********************************************************************************************************************/

	template
	<
		typename Signature, typename... CP_Stems
	>
	constexpr Signature & cycle(Signature & arg)
	{
		return cp_chain_endopose::template result
		<
			cp_lift<_id_>, CP_Stems...

		>::template result<cycle<Signature, CP_Stems...>, Signature &>(arg);
	}

/***********************************************************************************************************************/

	template
	<
		typename Signature, typename... CP_Stems
	>
	constexpr Signature & postcycle(Signature & arg)
	{
		return cp_chain_endopose::template result
		<
			cp_lift<_id_>, CP_Stems...

		>::template result<_id_, Signature &>(arg);
	}

/***********************************************************************************************************************/

	template<auto f, auto g, auto h>
	constexpr auto cycle_inductor = V_do_compose_opt
	<
		V_do_compose_opt<f, g>, h
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

