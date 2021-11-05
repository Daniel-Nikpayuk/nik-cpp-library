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

// names:

public:

/***********************************************************************************************************************/

// machine names:

	struct MN
	{
		static constexpr key_type pause		= 0;
		static constexpr key_type cons		= 1;
		static constexpr key_type at		= 2;
		static constexpr key_type left		= 3;
		static constexpr key_type right		= 4;
		static constexpr key_type name		= 5;
		static constexpr key_type unpack	= 6;
	};

/***********************************************************************************************************************/

// inductor names:

	struct IN
	{
		static constexpr key_type push_front	= 0;
		static constexpr key_type push_back	= 1;
		static constexpr key_type zip		= 2;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machines:

private:

	template<key_type, key_type, key_type...> struct machine;

/***********************************************************************************************************************/

// pause:

	template<key_type... filler>
	struct machine<MN::pause, _zero, filler...>
	{
		template
		<
			typename n, auto c, auto d, auto i, auto j,
			template<auto...> class ListName, template<auto...> class... LNs,
			auto... Vs, typename... Ts
		>
		static constexpr auto result(void(*)(auto_template_pack<ListName, LNs...>*), Ts... As)
		{
			constexpr auto sc = U_pack_Vs<U_type_T<n>, c, i, j, U_pack_Bs<ListName, LNs...>, Vs...>;
			constexpr auto hc = U_pack_Vs<U_type_T<T_pretype_T<Ts>>...>;

			return machine_module::trampoline_pair(sc, hc);
		}
	};

/***********************************************************************************************************************/

// cons:

private:

	template<key_type... filler>
	struct machine<MN::cons, _zero, filler...>
	{
		template
		<
			typename n, auto c, auto d, auto i, auto j,
			template<auto...> class ListName, template<auto...> class... LNs,
			auto... Vs, typename... Ts
		>
		static constexpr auto result(void(*)(auto_template_pack<ListName, LNs...>*), Ts... As)
		{
			return U_type_T<ListName<Vs...>>;
		}
	};

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// at:

private:

	template<key_type... filler>
	struct machine<MN::at, _zero, filler...>
	{
		template<typename n, auto c, auto d, auto i, auto j, auto pos, auto... Vs, typename... Ts>
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
	struct machine<MN::left, _zero, filler...>
	{
		template<typename n, auto c, auto d, auto i, auto j, auto pos, auto... Vs, typename... Ts>
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
	struct machine<MN::right, _zero, filler...>
	{
		template<typename n, auto c, auto d, auto i, auto j, auto pos, auto... Vs, typename... Ts>
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
	struct machine<MN::name, _zero, filler...>
	{
		template
		<
			typename n, auto c, auto d, auto i, auto j,
			template<auto...> class ListName, template<auto...> class... LNs,
			auto... Vs, typename... Ts
		>
		static constexpr auto result(void(*A0)(auto_template_pack<ListName, LNs...>*), Ts... As)
		{
			return A0;
		}
	};

public:

//	template<typename List>
//	static constexpr auto name = pattern_match_list<List>::template push_back<name_cont>();

/***********************************************************************************************************************/

// unpack:

private:

	template<key_type... filler>
	struct machine<MN::unpack, IN::push_front, filler...>
	{
		template<typename n, auto c, auto d, auto i, auto j, auto... Vs, typename T0, typename T1, typename... Ts>
		static constexpr auto result(T0 A0, T1, Ts... As)
		{
			return pattern_match_list<T_pretype_T<T1>>::template push_front<n, c, d, i, j, Vs...>(A0, As...);
		}
	};

	template<key_type... filler>
	struct machine<MN::unpack, IN::push_back, filler...>
	{
		template<typename n, auto c, auto d, auto i, auto j, auto... Vs, typename T0, typename T1, typename... Ts>
		static constexpr auto result(T0 A0, T1, Ts... As)
		{
			return pattern_match_list<T_pretype_T<T1>>::template push_back<n, c, d, i, j, Vs...>(A0, As...);
		}
	};

	template<key_type... filler>
	struct machine<MN::unpack, IN::zip, filler...>
	{
		template<typename n, auto c, auto d, auto i, auto j, auto... Vs, typename T0, typename T1, typename... Ts>
		static constexpr auto result(T0 A0, T1, Ts... As)
		{
			return pattern_match_list<T_pretype_T<T1>>::template zip<n, c, d, i, j, Vs...>(A0, As...);
		}
	};

/*
	template<key_type Note, key_type... filler>
	struct machine<MN::unpack, Note, filler...>
	{
		template<typename n, auto c, auto d, auto i, auto j, auto... Vs, typename T0, typename T1, typename... Ts>
		static constexpr auto result(T0 A0, T1, Ts... As)
		{
			return pattern_match_list<T_pretype_T<T1>>::template induct<Note>::template machine
			<
				n::next_name(c, d, i, j),
				n::next_note(c, d, i, j)

			>::template result
			<
				n, c,

				n::next_unpack_depth(d),
				n::next_index1(c, d, i, j),
				n::next_index2(c, d, i, j),

				Vs...

			>(A0, As...);
		}
	};
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pattern match list:

private:

	template<typename> struct pattern_match_list;

/***********************************************************************************************************************/

	template<template<auto...> class ListName, auto... Ws>
	struct pattern_match_list<ListName<Ws...>>
	{
		template
		<
			typename n, auto c, auto d, auto i, auto j, auto... Vs,
			template<auto...> class... LNs, typename... Ts
		>
		static constexpr auto push_front(void(*)(auto_template_pack<LNs...>*), Ts... As)
		{
			return machine
			<
				n::next_name(c, d, i, j),
				n::next_note(c, d, i, j)

			>::template result
			<
				n, c,

				n::next_unpack_depth(d),
				n::next_index1(c, d, i, j),
				n::next_index2(c, d, i, j),

				Ws..., Vs...

			>(U_pack_Bs<ListName, LNs...>, As...);
		}

		template
		<
			typename n, auto c, auto d, auto i, auto j, auto... Vs,
			template<auto...> class... LNs, typename... Ts
		>
		static constexpr auto push_back(void(*)(auto_template_pack<LNs...>*), Ts... As)
		{
			return machine
			<
				n::next_name(c, d, i, j),
				n::next_note(c, d, i, j)

			>::template result
			<
				n, c,

				n::next_unpack_depth(d),
				n::next_index1(c, d, i, j),
				n::next_index2(c, d, i, j),

				Vs..., Ws...

			>(U_pack_Bs<ListName, LNs...>, As...);
		}

		template
		<
			typename n, auto c, auto d, auto i, auto j, auto Op, auto... Vs,
			template<auto...> class... LNs, typename... Ts
		>
		static constexpr auto zip(void(*)(auto_template_pack<LNs...>*), Ts... As)
		{
			return machine
			<
				n::next_name(c, d, i, j),
				n::next_note(c, d, i, j)

			>::template result
			<
				n, c,

				n::next_unpack_depth(d),
				n::next_index1(c, d, i, j),
				n::next_index2(c, d, i, j),

				Op, T_type_U<Op>::template result<Vs, Ws>...

			>(U_pack_Bs<ListName, LNs...>, As...);
		}
	};

/*
	template<template<auto...> class ListName, auto... Ws>
	struct pattern_match_list<ListName<Ws...>>
	{
		template<key_type, key_type...> struct induct;

		template<key_type... filler>
		struct induct<IN::push_front, filler...>
		{
			template
			<
				typename n, auto c, auto d, auto i, auto j, auto... Vs,
				template<auto...> class... LNs, typename... Ts
			>
			static constexpr auto result(void(*)(auto_template_pack<LNs...>*), Ts... As)
			{
				return machine
				<
					n::next_name(c, d, i, j),
					n::next_note(c, d, i, j)

				>::template result
				<
					n, c,

					n::next_depth(d),
					n::next_index1(c, d, i, j),
					n::next_index2(c, d, i, j),

					Ws..., Vs...

				>(U_pack_Bs<ListName, LNs...>, As...);
			}
		};

		template<key_type... filler>
		struct induct<IN::push_back, filler...>
		{
			template
			<
				typename n, auto c, auto d, auto i, auto j, auto... Vs,
				template<auto...> class... LNs, typename... Ts
			>
			static constexpr auto result(void(*)(auto_template_pack<LNs...>*), Ts... As)
			{
				return machine
				<
					n::next_name(c, d, i, j),
					n::next_note(c, d, i, j)

				>::template result
				<
					n, c,

					n::next_depth(d),
					n::next_index1(c, d, i, j),
					n::next_index2(c, d, i, j),

					Vs..., Ws...

				>(U_pack_Bs<ListName, LNs...>, As...);
			}
		};

		template<key_type... filler>
		struct induct<IN::zip, filler...>
		{
			template
			<
				typename n, auto c, auto d, auto i, auto j, auto Op, auto... Vs,
				template<auto...> class... LNs, typename... Ts
			>
			static constexpr auto result(void(*)(auto_template_pack<LNs...>*), Ts... As)
			{
				return machine
				<
					n::next_name(c, d, i, j),
					n::next_note(c, d, i, j)

				>::template result
				<
					n, c,

					n::next_depth(d),
					n::next_index1(c, d, i, j),
					n::next_index2(c, d, i, j),

					Op, T_type_U<Op>::template result<Vs, Ws>...

				>(U_pack_Bs<ListName, LNs...>, As...);
			}
		};
	};
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controller:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatchers:

/***********************************************************************************************************************/

// list:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// trampolining:

/***********************************************************************************************************************/

// triple:

private:

/*
	template<typename StackCache, typename HeapCache, typename MachCache>
	struct trampoline_triple
	{
		StackCache sc;
		HeapCache hc;
		MachCache mc;

		constexpr trampoline_triple(const StackCache & _sc, const HeapCache & _hc, const MachCache & _mc) :
				sc(_sc), hc(_hc), mc(_mc) { }
	};

	template<typename T>
	static constexpr bool is_trampoline_triple(T) { return false; }

	template<typename StackCache, typename HeapCache, typename MachCache>
	static constexpr bool is_trampoline_triple(trampoline_triple<StackCache, HeapCache, MachCache>) { return true; }
*/

/***********************************************************************************************************************/

// trampoline:

public:

/*
	template<auto d, auto un, auto c, auto i, auto... Vs, template<auto...> class ListName, auto... Ws, auto... As>
	static constexpr auto trampoline
	(
		void(*)(auto_pack<un, c, i, Vs...>*),
		void(*)(ListName<Ws...>*),
		void(*)(auto_pack<As...>*)
	)
	{
		static_assert(bool(d), "list trampolining nesting depth exceeded.");

		using n			= T_type_U<un>;
		constexpr auto result	= pattern_match_list<ListName<Ws...>>::template induction
		<
			n::next_induct_name(c, d, i)

		>::template result
		<
			n, c,

			n::next_depth(d),
			n::next_index(c, d, i),

			Vs...

		>(As...);

		if constexpr (is_trampoline_triple(result)) return trampoline<d-1>(result.sc, result.hc, result.mc);
		else                                        return result;
	}
*/

/***********************************************************************************************************************/

// start:

/*
	template<typename n, auto c, auto d, template<auto...> class ListName, auto... Vs, typename... Ts>
	static constexpr auto start(Ts... As)
	{
		constexpr auto result = machine
		<
			n::next_cont_name(c, d, n::i, false)

		>::template result
		<
			n, c,

			n::next_depth(d),
			n::next_index(c, d, i, n::i),

			ListName, Vs...

		>(U_type_T<T_pretype_T<Ts>>...);

		if constexpr (is_trampoline_triple(result)) return trampoline<d>(result.sc, result.hc, result.mc);
		else                                        return result;
	}
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

