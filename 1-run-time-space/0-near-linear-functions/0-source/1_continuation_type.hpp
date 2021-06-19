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

#ifndef _2_CONTINUATION_TYPE_HPP
#define _2_CONTINUATION_TYPE_HPP

// continuation type:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace continuation_space
{
	#include"../../0-register-machine/using_namespace_meta_programming.hpp"
	#include"../../0-register-machine/using_namespace_machine_space.hpp"

	using function_space::_id_;

	using function_space::is_id_keyword;
	using function_space::compose;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// lift:

	template<auto> struct S_lift;

	template<typename OutType, typename... InTypes, OutType(*f)(InTypes...)>
	struct S_lift<f>
	{
		using out_type = OutType;
		using in_types = typename_pack<InTypes...>;

		template<auto cont>
		static constexpr auto f_result()
		{
			if constexpr (is_id_keyword<cont>)	return f;
			else					return compose<cont, f>;
		}

		template<auto cont>
		static constexpr OutType (*result)(InTypes...) = f_result<cont>();
	};

	template<auto f>
	constexpr auto lift = U_type_T<S_lift<f>>;

/***********************************************************************************************************************/

// keywords:

	struct S_is_lifted_id_keyword
	{
		static constexpr auto U_lift_id_ = U_type_T<S_lift<_id_>>;

		template<auto uf>
		static constexpr bool result = V_is_equal_UxU(U_pack_Vs<uf>, U_lift_id_);
	};

	constexpr auto U_is_lifted_id_keyword = U_type_T<S_is_lifted_id_keyword>;

	template<auto uf>
	constexpr bool is_lifted_id_keyword = S_is_lifted_id_keyword::template result<uf>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// stem:

/***********************************************************************************************************************/

// f specializations:

	// * *:

		template<auto pred, auto ante, auto conse, auto cont, typename OutType, typename... InTypes>
		constexpr OutType f_stem_pred_ante_conse_cont(InTypes... args)
		{
			if (pred(args...))	return ante(args...);
			else			return cont(conse(args...));
		}

		template<auto pred, auto ante, auto conse, typename OutType, typename... InTypes>
		constexpr OutType f_stem_pred_ante_conse_id(InTypes... args)
		{
			if (pred(args...))	return ante(args...);
			else			return conse(args...);
		}

	// * id:

		template<auto pred, auto ante, auto cont, typename OutType, typename... InTypes>
		constexpr OutType f_stem_pred_ante_id_cont(InTypes... args)
		{
			if (pred(args...))	return ante(args...);
			else			return cont(args...);
		}

		template<auto pred, auto ante, typename OutType, typename InType, typename... InTypes>
		constexpr OutType f_stem_pred_ante_id_id(InType arg, InTypes... args)
		{
			if (pred(arg, args...))	return ante(arg, args...);
			else			return arg;
		}

	// id *:

		template<auto pred, auto conse, auto cont, typename OutType, typename InType, typename... InTypes>
		constexpr OutType f_stem_pred_id_conse_cont(InType arg, InTypes... args)
		{
			if (pred(arg, args...))	return arg;
			else			return cont(conse(arg, args...));
		}

		template<auto pred, auto conse, typename OutType, typename InType, typename... InTypes>
		constexpr OutType f_stem_pred_id_conse_id(InType arg, InTypes... args)
		{
			if (pred(arg, args...))	return arg;
			else			return conse(arg, args...);
		}

	// id id:

		template<auto pred, auto cont, typename OutType, typename InType, typename... InTypes>
		constexpr OutType f_stem_pred_id_id_cont(InType arg, InTypes... args)
		{
			if (pred(arg, args...))	return arg;
			else			return cont(arg, args...);
		}

		template<auto pred, typename OutType, typename InType, typename... InTypes>
		constexpr OutType f_stem_pred_id_id_id(InType arg, InTypes... args)
		{
			if (pred(arg, args...))	return arg; // pred might have side effects,
			else			return arg; // so the policy is to leave as is.
		}

/***********************************************************************************************************************/

// specializations:

	// * *:

		template<auto, auto, auto> struct S_stem;

		template
		<
			typename OutType,
			typename... InTypes,

			bool(*pred)(InTypes...),
			OutType(*ante)(InTypes...),
			OutType(*conse)(InTypes...)
		>
		struct S_stem<pred, ante, conse>
		{
			using out_type	= OutType;
			using in_types	= typename_pack<InTypes...>;
			using f_type	= OutType(*)(InTypes...);

			template<auto cont>
			static constexpr auto f_result()
			{
				if constexpr (is_id_keyword<cont>)

					return f_stem_pred_ante_conse_id
					<
						pred, ante, conse, OutType, InTypes...
					>;
				else
					return f_stem_pred_ante_conse_cont
					<
						pred, ante, conse, cont, OutType, InTypes...
					>;
			}

			template<auto cont>
			static constexpr OutType (*result)(InTypes...) = f_result<cont>();
		};

	// * id:

		template
		<
			typename OutType,
			typename... InTypes,

			bool(*pred)(InTypes...),
			OutType(*ante)(InTypes...)
		>
		struct S_stem<pred, ante, _id_>
		{
			using out_type	= OutType;
			using in_types	= typename_pack<InTypes...>;
			using f_type	= OutType(*)(InTypes...);

			template<auto cont>
			static constexpr auto f_result()
			{
				if constexpr (is_id_keyword<cont>)

					return f_stem_pred_ante_id_id
					<
						pred, ante, OutType, InTypes...
					>;
				else
					return f_stem_pred_ante_id_cont
					<
						pred, ante, cont, OutType, InTypes...
					>;
			}

			template<auto cont>
			static constexpr OutType (*result)(InTypes...) = f_result<cont>();
		};

	// id *:

		template
		<
			typename OutType,
			typename... InTypes,

			bool(*pred)(InTypes...),
			OutType(*conse)(InTypes...)
		>
		struct S_stem<pred, _id_, conse>
		{
			using out_type	= OutType;
			using in_types	= typename_pack<InTypes...>;
			using f_type	= OutType(*)(InTypes...);

			template<auto cont>
			static constexpr auto f_result()
			{
				if constexpr (is_id_keyword<cont>)

					return f_stem_pred_id_conse_id
					<
						pred, conse, OutType, InTypes...
					>;
				else
					return f_stem_pred_id_conse_cont
					<
						pred, conse, cont, OutType, InTypes...
					>;
			}

			template<auto cont>
			static constexpr OutType (*result)(InTypes...) = f_result<cont>();
		};

	// id id:

		template
		<
			typename InType,
			typename... InTypes,

			bool(*pred)(InType, InTypes...)
		>
		struct S_stem<pred, _id_, _id_>
		{
			using OutType	= InType;

			using out_type	= OutType;
			using in_types	= typename_pack<InType, InTypes...>;
			using f_type	= OutType(*)(InType, InTypes...);

			template<auto cont>
			static constexpr auto f_result()
			{
				if constexpr (is_id_keyword<cont>)

					return f_stem_pred_id_id_id
					<
						pred, OutType, InType, InTypes...
					>;
				else
					return f_stem_pred_id_id_cont
					<
						pred, cont, OutType, InType, InTypes...
					>;
			}

			template<auto cont>
			static constexpr OutType (*result)(InType, InTypes...) = f_result<cont>();
		};

/***********************************************************************************************************************/

// dispatch:

	template<auto pred, auto ante, auto conse>
	constexpr auto stem = U_type_T<S_stem<pred, ante, conse>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// costem:

/***********************************************************************************************************************/

// f specializations:

	// * *:

		template<auto pred, auto ante, auto conse, auto cont, typename OutType, typename... InTypes>
		constexpr OutType f_costem_pred_ante_conse_cont(InTypes... args)
		{
			if (pred(args...))	return cont(ante(args...));
			else			return conse(args...);
		}

		template<auto pred, auto ante, auto conse, typename OutType, typename... InTypes>
		constexpr OutType f_costem_pred_ante_conse_id(InTypes... args)
		{
			if (pred(args...))	return ante(args...);
			else			return conse(args...);
		}

	// * id:

		template<auto pred, auto ante, auto cont, typename OutType, typename InType, typename... InTypes>
		constexpr OutType f_costem_pred_ante_id_cont(InType arg, InTypes... args)
		{
			if (pred(arg, args...))	return cont(ante(arg, args...));
			else			return arg;
		}

		template<auto pred, auto ante, typename OutType, typename InType, typename... InTypes>
		constexpr OutType f_costem_pred_ante_id_id(InType arg, InTypes... args)
		{
			if (pred(arg, args...))	return ante(arg, args...);
			else			return arg;
		}

	// id *:

		template<auto pred, auto conse, auto cont, typename OutType, typename... InTypes>
		constexpr OutType f_costem_pred_id_conse_cont(InTypes... args)
		{
			if (pred(args...))	return cont(args...);
			else			return conse(args...);
		}

		template<auto pred, auto conse, typename OutType, typename InType, typename... InTypes>
		constexpr OutType f_costem_pred_id_conse_id(InType arg, InTypes... args)
		{
			if (pred(arg, args...))	return arg;
			else			return conse(arg, args...);
		}

	// id id:

		template<auto pred, auto cont, typename OutType, typename InType, typename... InTypes>
		constexpr OutType f_costem_pred_id_id_cont(InType arg, InTypes... args)
		{
			if (pred(arg, args...))	return cont(arg, args...);
			else			return arg;
		}

		template<auto pred, typename OutType, typename InType, typename... InTypes>
		constexpr OutType f_costem_pred_id_id_id(InType arg, InTypes... args)
		{
			if (pred(arg, args...))	return arg; // pred might have side effects,
			else			return arg; // so the policy is to leave as is.
		}

/***********************************************************************************************************************/

// specializations:

	// * *:

		template<auto, auto, auto> struct S_costem;

		template
		<
			typename OutType,
			typename... InTypes,

			bool(*pred)(InTypes...),
			OutType(*ante)(InTypes...),
			OutType(*conse)(InTypes...)
		>
		struct S_costem<pred, ante, conse>
		{
			using out_type	= OutType;
			using in_types	= typename_pack<InTypes...>;
			using f_type	= OutType(*)(InTypes...);

			template<auto cont>
			static constexpr auto f_result()
			{
				if constexpr (is_id_keyword<cont>)

					return f_costem_pred_ante_conse_id
					<
						pred, ante, conse, OutType, InTypes...
					>;
				else
					return f_costem_pred_ante_conse_cont
					<
						pred, ante, conse, cont, OutType, InTypes...
					>;
			}

			template<auto cont>
			static constexpr OutType (*result)(InTypes...) = f_result<cont>();
		};

	// * id:

		template
		<
			typename OutType,
			typename... InTypes,

			bool(*pred)(InTypes...),
			OutType(*ante)(InTypes...)
		>
		struct S_costem<pred, ante, _id_>
		{
			using out_type	= OutType;
			using in_types	= typename_pack<InTypes...>;
			using f_type	= OutType(*)(InTypes...);

			template<auto cont>
			static constexpr auto f_result()
			{
				if constexpr (is_id_keyword<cont>)

					return f_costem_pred_ante_id_id
					<
						pred, ante, OutType, InTypes...
					>;
				else
					return f_costem_pred_ante_id_cont
					<
						pred, ante, cont, OutType, InTypes...
					>;
			}

			template<auto cont>
			static constexpr OutType (*result)(InTypes...) = f_result<cont>();
		};

	// id *:

		template
		<
			typename OutType,
			typename... InTypes,

			bool(*pred)(InTypes...),
			OutType(*conse)(InTypes...)
		>
		struct S_costem<pred, _id_, conse>
		{
			using out_type	= OutType;
			using in_types	= typename_pack<InTypes...>;
			using f_type	= OutType(*)(InTypes...);

			template<auto cont>
			static constexpr auto f_result()
			{
				if constexpr (is_id_keyword<cont>)

					return f_costem_pred_id_conse_id
					<
						pred, conse, OutType, InTypes...
					>;
				else
					return f_costem_pred_id_conse_cont
					<
						pred, conse, cont, OutType, InTypes...
					>;
			}

			template<auto cont>
			static constexpr OutType (*result)(InTypes...) = f_result<cont>();
		};

	// id id:

		template
		<
			typename InType,
			typename... InTypes,

			bool(*pred)(InType, InTypes...)
		>
		struct S_costem<pred, _id_, _id_>
		{
			using OutType	= InType;

			using out_type	= OutType;
			using in_types	= typename_pack<InType, InTypes...>;
			using f_type	= OutType(*)(InType, InTypes...);

			template<auto cont>
			static constexpr auto f_result()
			{
				if constexpr (is_id_keyword<cont>)

					return f_costem_pred_id_id_id
					<
						pred, OutType, InType, InTypes...
					>;
				else
					return f_costem_pred_id_id_cont
					<
						pred, cont, OutType, InType, InTypes...
					>;
			}

			template<auto cont>
			static constexpr OutType (*result)(InType, InTypes...) = f_result<cont>();
		};

/***********************************************************************************************************************/

// dispatch:

	template<auto pred, auto ante, auto conse>
	constexpr auto costem = U_type_T<S_costem<pred, ante, conse>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// distem:

/***********************************************************************************************************************/

// f specializations:

	// * *:

		template<auto pred, auto ante, auto conse, auto cont, typename OutType, typename... InTypes>
		constexpr OutType f_distem_pred_ante_conse_cont(InTypes... args)
		{
			if (pred(args...))	return cont(ante(args...));
			else			return cont(conse(args...));
		}

		template<auto pred, auto ante, auto conse, typename OutType, typename... InTypes>
		constexpr OutType f_distem_pred_ante_conse_id(InTypes... args)
		{
			if (pred(args...))	return ante(args...);
			else			return conse(args...);
		}

	// * id:

		template<auto pred, auto ante, auto cont, typename OutType, typename... InTypes>
		constexpr OutType f_distem_pred_ante_id_cont(InTypes... args)
		{
			if (pred(args...))	return cont(ante(args...));
			else			return cont(args...);
		}

		template<auto pred, auto ante, typename OutType, typename InType, typename... InTypes>
		constexpr OutType f_distem_pred_ante_id_id(InType arg, InTypes... args)
		{
			if (pred(arg, args...))	return ante(arg, args...);
			else			return arg;
		}

	// id *:

		template<auto pred, auto conse, auto cont, typename OutType, typename... InTypes>
		constexpr OutType f_distem_pred_id_conse_cont(InTypes... args)
		{
			if (pred(args...))	return cont(args...);
			else			return cont(conse(args...));
		}

		template<auto pred, auto conse, typename OutType, typename InType, typename... InTypes>
		constexpr OutType f_distem_pred_id_conse_id(InType arg, InTypes... args)
		{
			if (pred(arg, args...))	return arg;
			else			return conse(arg, args...);
		}

	// id id:

		template<auto pred, auto cont, typename OutType, typename... InTypes>
		constexpr OutType f_distem_pred_id_id_cont(InTypes... args)
		{
			if (pred(args...))	return cont(args...); // pred might have side effects,
			else			return cont(args...); // so the policy is to leave as is.
		}

		template<auto pred, typename OutType, typename InType, typename... InTypes>
		constexpr OutType f_distem_pred_id_id_id(InType arg, InTypes... args)
		{
			if (pred(arg, args...))	return arg; // pred might have side effects,
			else			return arg; // so the policy is to leave as is.
		}

/***********************************************************************************************************************/

// specializations:

	// * *:

		template<auto, auto, auto> struct S_distem;

		template
		<
			typename OutType,
			typename... InTypes,

			bool(*pred)(InTypes...),
			OutType(*ante)(InTypes...),
			OutType(*conse)(InTypes...)
		>
		struct S_distem<pred, ante, conse>
		{
			using out_type	= OutType;
			using in_types	= typename_pack<InTypes...>;
			using f_type	= OutType(*)(InTypes...);

			template<auto cont>
			static constexpr auto f_result()
			{
				if constexpr (is_id_keyword<cont>)

					return f_distem_pred_ante_conse_id
					<
						pred, ante, conse, OutType, InTypes...
					>;
				else
					return f_distem_pred_ante_conse_cont
					<
						pred, ante, conse, cont, OutType, InTypes...
					>;
			}

			template<auto cont>
			static constexpr OutType (*result)(InTypes...) = f_result<cont>();
		};

	// * id:

		template
		<
			typename OutType,
			typename... InTypes,

			bool(*pred)(InTypes...),
			OutType(*ante)(InTypes...)
		>
		struct S_distem<pred, ante, _id_>
		{
			using out_type	= OutType;
			using in_types	= typename_pack<InTypes...>;
			using f_type	= OutType(*)(InTypes...);

			template<auto cont>
			static constexpr auto f_result()
			{
				if constexpr (is_id_keyword<cont>)

					return f_distem_pred_ante_id_id
					<
						pred, ante, OutType, InTypes...
					>;
				else
					return f_distem_pred_ante_id_cont
					<
						pred, ante, cont, OutType, InTypes...
					>;
			}

			template<auto cont>
			static constexpr OutType (*result)(InTypes...) = f_result<cont>();
		};

	// id *:

		template
		<
			typename OutType,
			typename... InTypes,

			bool(*pred)(InTypes...),
			OutType(*conse)(InTypes...)
		>
		struct S_distem<pred, _id_, conse>
		{
			using out_type	= OutType;
			using in_types	= typename_pack<InTypes...>;
			using f_type	= OutType(*)(InTypes...);

			template<auto cont>
			static constexpr auto f_result()
			{
				if constexpr (is_id_keyword<cont>)

					return f_distem_pred_id_conse_id
					<
						pred, conse, OutType, InTypes...
					>;
				else
					return f_distem_pred_id_conse_cont
					<
						pred, conse, cont, OutType, InTypes...
					>;
			}

			template<auto cont>
			static constexpr OutType (*result)(InTypes...) = f_result<cont>();
		};

	// id id:

		template
		<
			typename InType,
			typename... InTypes,

			bool(*pred)(InType, InTypes...)
		>
		struct S_distem<pred, _id_, _id_>
		{
			using OutType	= InType;

			using out_type	= OutType;
			using in_types	= typename_pack<InType, InTypes...>;
			using f_type	= OutType(*)(InType, InTypes...);

			template<auto cont>
			static constexpr auto f_result()
			{
				if constexpr (is_id_keyword<cont>)

					return f_distem_pred_id_id_id
					<
						pred, OutType, InType, InTypes...
					>;
				else
					return f_distem_pred_id_id_cont
					<
						pred, cont, OutType, InType, InTypes...
					>;
			}

			template<auto cont>
			static constexpr OutType (*result)(InType, InTypes...) = f_result<cont>();
		};

/***********************************************************************************************************************/

// dispatch:

	template<auto pred, auto ante, auto conse>
	constexpr auto distem = U_type_T<S_distem<pred, ante, conse>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// endobind:

	template<typename, typename, typename, typename, typename, typename> struct S_endobind;

	template
	<
		typename S1, typename OutType, typename CType,
		typename S2, typename... InTypes
	>
	struct S_endobind
	<
		S1, OutType, typename_pack<CType>,
		S2, CType, typename_pack<InTypes...>
	>
	{
		using out_type = OutType;
		using in_types = typename_pack<InTypes...>;

		template<auto cont>
		static constexpr OutType result(InTypes... args)
		{
			return S1::template result
			<
				S2::template result<cont>

			>(args...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// endoposition:

/***********************************************************************************************************************/

// endopose:

	struct S_endopose
	{
		template<typename S1, typename S2>
		static constexpr auto let_result = U_type_T
		<
			S_endobind
			<
				S1, typename S1::out_type, typename S1::in_types,
				S2, typename S2::out_type, typename S2::in_types
			>
		>;

		template<auto uf, auto ug>
		static constexpr auto result = let_result<T_type_U<uf>, T_type_U<ug>>;
	};

	constexpr auto U_endopose = U_type_T<S_endopose>;

	template<auto uf, auto ug>
	constexpr auto endopose = S_endopose::template result<uf, ug>;

/***********************************************************************************************************************/

// chain lift:

	template<auto f0, auto... fs>
	constexpr auto chain_lift = machine_space::f_pack_roll<500, U_endopose, lift<f0>, lift<fs>...>();

/***********************************************************************************************************************/

// chain endopose:

	template<auto c0, auto... cs>
	constexpr auto chain_endopose = machine_space::f_pack_roll<500, U_endopose, c0, cs...>();

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// optimized endoposition:

/***********************************************************************************************************************/

// opt endopose:

	struct S_opt_endopose
	{
		template<auto uf, auto ug>
		static constexpr auto f_result()
		{
			if constexpr      (is_lifted_id_keyword<uf>)	return ug;
			else if constexpr (is_lifted_id_keyword<ug>)	return uf;
			else						return endopose<uf, ug>;
		};

		template<auto uf, auto ug>
		static constexpr auto result = f_result<uf, ug>();
	};

	constexpr auto U_opt_endopose = U_type_T<S_opt_endopose>;

	template<auto uf, auto ug>
	constexpr auto opt_endopose = S_opt_endopose::template f_result<uf, ug>();

/***********************************************************************************************************************/

// opt chain lift:

	template<auto f0, auto... fs>
	constexpr auto opt_chain_lift = machine_space::f_pack_roll<500, U_opt_endopose, lift<f0>, lift<fs>...>();

/***********************************************************************************************************************/

// opt chain endopose:

	template<auto c0, auto... cs>
	constexpr auto opt_chain_endopose = machine_space::f_pack_roll<500, U_opt_endopose, c0, cs...>();

/***********************************************************************************************************************/

// close cycle:

	template<auto expr, typename T>
	constexpr T & close_cycle(T & s)
	{
		return T_type_U<expr>::template result
		<
			close_cycle<expr, T>
		>(s);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

#endif

