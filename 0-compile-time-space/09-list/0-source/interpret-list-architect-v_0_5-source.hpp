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

// pattern match:

	// redesign (extend) to be more robust against nesting depth,
	// possibly extending to include greater expressivity similar
	// to the compile time register machine design.

	struct IN
	{
		static constexpr key_type push_back	= 0;
		static constexpr key_type zip		= 1;
	};

private:

	template<key_type, key_type...> struct continuation;
	template<typename>		struct pattern_match_list;

	template<template<auto...> class ListName, auto... Vs>
	struct pattern_match_list<ListName<Vs...>>
	{
		template<key_type, key_type...> struct induct;

		// 2^0:

		template<key_type... filler>
		struct induct<IN::push_back, filler...>
		{
			template<typename n, auto c, auto d, auto i, auto... Ws, typename... Ts>
			static constexpr auto result(Ts... As)
			{
				return continuation
				<
					n::next_name(c, d, i)

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
		struct induct<IN::zip, filler...>
		{
			template<typename n, auto c, auto d, auto i, auto... Ws, typename Op, typename... Ts>
			static constexpr auto result(void(*op)(Op*), Ts... As)
			{
				return continuation
				<
					n::next_name(c, d, i)

				>::template result
				<
					n, c,

					n::next_depth(d),
					n::next_index(c, d, i),

					ListName, Op::template result<Ws, Vs>...

				>(op, As...);
			}
		};
	};


/*
	template<template<auto...> class ListName, auto... Vs>
	struct pattern_match_list<ListName<Vs...>>
	{
		template<typename Cont, auto... Ws, typename... Ts>
		static constexpr auto push_back(Ts... As)
		{
			return Cont::template result<ListName, Ws..., Vs...>(As...);
		}

		template<typename Cont, auto... Ws, typename Op, typename... Ts>
		static constexpr auto zip(void(*op)(Op*), Ts... As)
		{
			return Cont::template result<ListName, Op::template result<Ws, Vs>...>(op, As...);
		}
	};
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// continuation:

public:

	struct CN
	{
		static constexpr key_type cons		= 0;
		static constexpr key_type at		= 1;
		static constexpr key_type left		= 2;
		static constexpr key_type right		= 3;
		static constexpr key_type name		= 4;
		static constexpr key_type catenate	= 5;
		static constexpr key_type zip		= 6;
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

/*
	struct cons_cont
	{
		template<template<auto...> class ListName, auto... Vs, typename... Ts>
		static constexpr auto result(Ts... As)
		{
			return cache_module::template U_type_T<ListName<Vs...>>;
		}
	};
*/

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

/*
	struct at_cont
	{
		template<template<auto...> class ListName, auto d, auto pos, auto... Vs, typename... Ts>
		static constexpr auto result(Ts... As)
		{
			return pack_module::template at<d, pos, Vs...>;
		}
	};
*/

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

/*
	struct left_cont
	{
		template<template<auto...> class ListName, auto d, auto pos, auto... Vs, typename... Ts>
		static constexpr auto result(Ts... As)
		{
			return pack_module::template left<d, pos, Vs...>;
		}
	};
*/

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

/*
	struct right_cont
	{
		template<template<auto...> class ListName, auto d, auto pos, auto... Vs, typename... Ts>
		static constexpr auto result(Ts... As)
		{
			return pack_module::template right<d, pos, Vs...>;
		}
	};
*/

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

/*
	struct name_cont
	{
		template<template<auto...> class ListName, auto... Vs, typename... Ts>
		static constexpr auto result(Ts... As)
		{
			return cache_module::template U_pack_Bs<ListName>;
		}
	};
*/

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
			template<auto...> class ListName, auto... Ws, typename L, typename... Ts
		>
		static constexpr auto result(void(*)(L*), Ts... As)
		{
			return pattern_match_list<L>::template induct
			<
				n::next_name(c, d, i)

			>::template result
			<
				n, c,

				n::next_depth(d),
				n::next_index(c, d, i),

				Ws...

			>(As...);
		}
	};

/*
	struct catenate_cont
	{
		template<template<auto...> class ListName, auto... Ws, typename L, typename... Ts>
		static constexpr auto result(void(*)(L*), Ts... As)
		{
			if constexpr (sizeof...(Ts) == 0)

				return pattern_match_list<L>::template push_back<cons_cont, Ws...>();
			else
				return pattern_match_list<L>::template push_back<catenate_cont, Ws...>(As...);
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
			template<auto...> class ListName, auto... Ws, typename Op, typename L, typename... Ts
		>
		static constexpr auto result(Op op, void(*)(L*), Ts... As)
		{
			return pattern_match_list<L>::template induct
			<
				n::next_name(c, d, i)

			>::template result
			<
				n, c,

				n::next_depth(d),
				n::next_index(c, d, i),

				Ws...

			>(op, As...);
		}
	};

/*
	struct zip_cont
	{
		template<template<auto...> class ListName, auto... Ws, typename Op, typename L, typename... Ts>
		static constexpr auto result(Op op, void(*)(L*), Ts... As)
		{
			if constexpr (sizeof...(Ts) == 0)

				return pattern_match_list<L>::template zip<cons_cont, Ws...>(op);
			else
				return pattern_match_list<L>::template zip<zip_cont, Ws...>(op, As...);
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

