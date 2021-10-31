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

// list source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

private:

	template<typename T>				// This works because as a variable template it has
	static constexpr bool is_list = false;		// a partial specialize defined outside of this module.

public:

	template<typename T>
	static constexpr bool V_is_list_T = is_list<T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controller:

public:

	template<index_type... Vs>
	static constexpr auto induct		= machine_module::template instruction<Vs...>;

	template<index_type... Vs>
	static constexpr auto cont_if_last	= machine_module::template instruction<Vs...>;

	template<instr_type... Vs>
	static constexpr auto controller	= machine_module::template label<Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatchers:

/***********************************************************************************************************************/

// list:

	struct LD
	{
		static constexpr auto i = _zero;

	// iterators:

		static constexpr key_type next_induct_name(contr_type c, depth_type d, index_type i)
		{
			if (d == 0)	return IN::pause;
			else 		return c[i+1][_one];
		}

		static constexpr key_type next_cont_name(contr_type c, depth_type d, index_type i)
		{
			if (d == 0)	return CN::pause;
			else 		return c[i+1][_one];
		}

		static constexpr depth_type next_depth(depth_type d)
		{
			if (d > 0)	return d-1;
			else 		return d;
		}

		static constexpr index_type next_index(contr_type, depth_type d, index_type i)
		{
			if (d == 0)	return i;
			else 		return i+1;
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// :

private:

	template<key_type, key_type...> struct continuation;
	template<typename>		struct pattern_match_list;

/***********************************************************************************************************************/

// trampoline:

public:

/*
	template<auto d, auto un, auto c, auto i, auto... Vs, auto... As>
	static constexpr auto trampoline(void(*)(auto_pack<un, c, i, Vs...>*), void(*)(auto_pack<As...>*))
	{
		static_assert(bool(d), "list trampolining nesting depth exceeded.");

		using n			= T_type_U<un>;
		constexpr auto result	= NIK_MACHINE(n, c, d, i, j)(Hs...);

		if constexpr (is_trampoline_pair(result)) return trampoline<d-1>(result.sc, result.hc);
		else                                      return result;
	}
*/

/***********************************************************************************************************************/

// start:

/*
	static constexpr auto catenate_contr = list_controller
	<
		induct       < IN::push_back          >,
		cont_if_last < CN::cons, CN::catenate >
	>;

	template<typename n, auto c, auto d, auto... Vs, typename L, typename... Ts>
	static constexpr auto start(void(*)(L*), Ts... As)
	{
		constexpr auto result = pattern_match_list<L>::template induct
		<
			n::next_induct_name(c, d, n::i)

		>::template result
		<
			n, c,

			n::next_depth(d),
			n::next_index(c, d, n::i),

			Vs...

		>(As...);

		if constexpr (is_trampoline_pair(result)) return list_trampoline<d>(result.sc, result.hc);
		else                                      return result;
	}
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pattern match:

	// redesign (extend) to be more robust against nesting depth,
	// possibly extending to include greater expressivity similar
	// to the compile time register machine design.

/***********************************************************************************************************************/

// inductor names:

	struct IN
	{
		static constexpr key_type pause		= 0;
		static constexpr key_type push_front	= 1;
		static constexpr key_type push_back	= 2;
		static constexpr key_type zip		= 3;
	};

/***********************************************************************************************************************/

private:

	template<template<auto...> class ListName, auto... Ws>
	struct pattern_match_list<ListName<Ws...>>
	{
		template<key_type, key_type...> struct induct;

		// 2^0:

		template<key_type... filler>
		struct induct<IN::push_front, filler...>
		{
			template<typename n, auto c, auto d, auto i, auto... Vs, typename... Ts>
			static constexpr auto result(Ts... As)
			{
				return continuation
				<
					n::next_cont_name(c, d, i)

				>::template result
				<
					n, c,

					n::next_depth(d),
					n::next_index(c, d, i),

					ListName, Ws..., Vs...

				>(As...);
			}
		};

		template<key_type... filler>
		struct induct<IN::push_back, filler...>
		{
			template<typename n, auto c, auto d, auto i, auto... Vs, typename... Ts>
			static constexpr auto result(Ts... As)
			{
				return continuation
				<
					n::next_cont_name(c, d, i)

				>::template result
				<
					n, c,

					n::next_depth(d),
					n::next_index(c, d, i),

					ListName, Vs..., Ws...

				>(As...);
			}
		};

		template<key_type... filler>
		struct induct<IN::zip, filler...>
		{
			template<typename n, auto c, auto d, auto i, auto... Vs, typename Op, typename... Ts>
			static constexpr auto result(void(*op)(Op*), Ts... As)
			{
				return continuation
				<
					n::next_cont_name(c, d, i)

				>::template result
				<
					n, c,

					n::next_depth(d),
					n::next_index(c, d, i),

					ListName, Op::template result<Vs, Ws>...

				>(op, As...);
			}
		};
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// continuation names:

public:

	struct CN
	{
		static constexpr key_type pause		= 0;
		static constexpr key_type cons		= 1;
		static constexpr key_type at		= 2;
		static constexpr key_type left		= 3;
		static constexpr key_type right		= 4;
		static constexpr key_type name		= 5;
		static constexpr key_type catenate	= 6;
		static constexpr key_type zip		= 7;
	};

/***********************************************************************************************************************/

// cons:

private:

	template<key_type... filler>
	struct continuation<CN::cons, filler...>
	{
		template
		<
			typename n, auto c, auto d, auto i,
			template<auto...> class ListName, auto... Vs, typename... Ts
		>
		static constexpr auto result(Ts... As)
		{
			return cache_module::template U_type_T<ListName<Vs...>>;
		}
	};

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// at:

private:

	template<key_type... filler>
	struct continuation<CN::at, filler...>
	{
		template
		<
			typename n, auto c, auto d, auto i,
			template<auto...> class ListName, auto pos, auto... Vs, typename... Ts
		>
		static constexpr auto result(Ts... As)
		{
			return pack_module::template at<d, pos, Vs...>;
		}
	};

public:

//	template<typename List, index_type pos, depth_type depth = 500>
//	static constexpr auto at = pattern_match_list<List>::template push_back<at_cont, depth, pos>();

/***********************************************************************************************************************/

// left:

private:

	template<key_type... filler>
	struct continuation<CN::left, filler...>
	{
		template
		<
			typename n, auto c, auto d, auto i,
			template<auto...> class ListName, auto pos, auto... Vs, typename... Ts
		>
		static constexpr auto result(Ts... As)
		{
			return pack_module::template left<d, pos, Vs...>;
		}
	};

public:

//	template<typename List, index_type pos, depth_type depth = 500>
//	static constexpr auto left = pattern_match_list<List>::template push_back<left_cont, depth, pos>();

/***********************************************************************************************************************/

// right:

private:

	template<key_type... filler>
	struct continuation<CN::right, filler...>
	{
		template
		<
			typename n, auto c, auto d, auto i,
			template<auto...> class ListName, auto pos, auto... Vs, typename... Ts
		>
		static constexpr auto result(Ts... As)
		{
			return pack_module::template right<d, pos, Vs...>;
		}
	};

public:

//	template<typename List, index_type pos, depth_type depth = 500>
//	static constexpr auto right = pattern_match_list<List>::template push_back<right_cont, depth, pos>();

/***********************************************************************************************************************/

// name:

private:

	template<key_type... filler>
	struct continuation<CN::name, filler...>
	{
		template
		<
			typename n, auto c, auto d, auto i,
			template<auto...> class ListName, auto... Vs, typename... Ts
		>
		static constexpr auto result(Ts... As)
		{
			return cache_module::template U_pack_Bs<ListName>;
		}
	};

public:

//	template<typename List>
//	static constexpr auto name = pattern_match_list<List>::template push_back<name_cont>();

/***********************************************************************************************************************/

// catenate:

private:

	template<key_type... filler>
	struct continuation<CN::catenate, filler...>
	{
		template
		<
			typename n, auto c, auto d, auto i,
			template<auto...> class ListName, auto... Vs, typename L, typename... Ts
		>
		static constexpr auto result(void(*)(L*), Ts... As)
		{
			return pattern_match_list<L>::template induct
			<
				n::next_induct_name(c, d, i)

			>::template result
			<
				n, c,

				n::next_depth(d),
				n::next_index(c, d, i),

				Vs...

			>(As...);
		}
	};

	static constexpr auto catenate_contr = controller
	<
		induct       < IN::push_back                >,
		cont_if_last < CN::cons      , CN::catenate >
	>;

/*
	struct catenate_cont
	{
		template<template<auto...> class ListName, auto... Vs, typename L, typename... Ts>
		static constexpr auto result(void(*)(L*), Ts... As)
		{
			if constexpr (sizeof...(Ts) == 0)

				return pattern_match_list<L>::template push_back<cons_cont, Vs...>();
			else
				return pattern_match_list<L>::template push_back<catenate_cont, Vs...>(As...);
		}
	};
*/

public:

/*
	template<typename L1, typename L2, typename... Ls>
	static constexpr auto U_catenate_TxTxTs = pattern_match_list<L1>::template push_back<catenate_cont>
	(
		cache_module::template U_type_T<L2>,
		cache_module::template U_type_T<Ls>...
	);
*/

/***********************************************************************************************************************/

// map:

/***********************************************************************************************************************/

// zip:

private:

	template<key_type... filler>
	struct continuation<CN::zip, filler...>
	{
		template
		<
			typename n, auto c, auto d, auto i,
			template<auto...> class ListName, auto... Vs, typename Op, typename L, typename... Ts
		>
		static constexpr auto result(Op op, void(*)(L*), Ts... As)
		{
			return pattern_match_list<L>::template induct
			<
				n::next_induct_name(c, d, i)

			>::template result
			<
				n, c,

				n::next_depth(d),
				n::next_index(c, d, i),

				Vs...

			>(op, As...);
		}
	};

/*
	struct zip_cont
	{
		template<template<auto...> class ListName, auto... Vs, typename Op, typename L, typename... Ts>
		static constexpr auto result(Op op, void(*)(L*), Ts... As)
		{
			if constexpr (sizeof...(Ts) == 0)

				return pattern_match_list<L>::template zip<cons_cont, Vs...>(op);
			else
				return pattern_match_list<L>::template zip<zip_cont, Vs...>(op, As...);
		}
	};
*/

public:

/*
	template<typename Op, typename L1, typename L2, typename... Ls>
	static constexpr auto U_zip_TxTxTxTs = pattern_match_list<L1>::template push_back<zip_cont>
	(
		cache_module::template U_type_T<Op>,
		cache_module::template U_type_T<L2>,
		cache_module::template U_type_T<Ls>...
	);
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

