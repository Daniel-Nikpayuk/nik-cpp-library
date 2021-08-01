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

// machines source:

	// Heap policy:

		// Heap zero:

			// Stores and moves single objects.
			// Privileges front mutations.

		// Heap one:

			// Stores and moves entire packs.
			// Privileges back mutations.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// constexpr monad (design):

//		template<key_type... filler>
//		struct machine<MN::(((name))), (((note))), filler...>
//		{
//			template
//			<
//				// stack:

//					typename n, auto c, auto d, auto i, auto j, auto... Vs,

//				// heaps:

//					typename... Heaps
//			>
//			static constexpr auto result(Heaps... Hs)
//			{
//				return machine
//				<
//					n::next_name(c, d, i, j),
//					n::next_note(c, d, i, j)

//				>::template result
//				<
//					n, c,

//					n::next_depth(d),
//					n::next_index1(c, d, i, j),
//					n::next_index2(c, d, i, j),

//					Vs...	// The behaviour of each
//						// machine is such that it
//				>(Hs...);	// mutates these packs.
//			}
//		};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keys:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// names:

/***********************************************************************************************************************/

	// I would prefer to implement these as enums, but I don't know how
	// to get gcc/clang to pattern match the register machine when I do.

	struct MachineName
	{
		// halters:

			static constexpr key_type pause						=  0;

			static constexpr key_type first						=  1;
			static constexpr key_type rest						=  2;
			static constexpr key_type pack						=  3;

		// debuggers:

			static constexpr key_type depth						=  4;
			static constexpr key_type dump						=  5;

		// passers:

			// stack -> stack:

			static constexpr key_type sizeof_s_all__insert_at_s_front		=  6; // builtin
			static constexpr key_type align_s_all__insert_at_s_front		=  7; // builtin
			static constexpr key_type shift_i_block__insert_at_s_back		=  8; // <machine>

			static constexpr key_type map_s_all__op_at_h0_first			=  9; // builtin
			static constexpr key_type map_s_all__act_at_h0_first			= 10; // builtin
			static constexpr key_type map_s_all__arr_at_h0_first			= 11; // <near linear>

			static constexpr key_type drop_s_block					= 12; // <halters>
			static constexpr key_type drop_s_pos					= 13; // opt, <mutators>
			static constexpr key_type drop_s_all					= 14; // builtin

			static constexpr key_type move_s_block__insert_at_s_back		= 15; // <near linear>
			static constexpr key_type move_s_pos__insert_at_s_back			= 16; // opt, <near linear>

			static constexpr key_type fold_s_block__op_at_h0_first			= 17; // <near linear>
			static constexpr key_type roll_s_block__act_at_h0_first			= 18; // <near linear>

			// stack -> heap:

			static constexpr key_type move_s_block__insert_at_h0_front		= 19; // <mutators>
			static constexpr key_type move_s_block__insert_at_h1_back		= 20; // <mutators>
			static constexpr key_type move_s_first__replace_at_h1_value		= 21; // <near linear>

			static constexpr key_type copy_s_block__insert_at_h0_front		= 22; // <mutators>
			static constexpr key_type copy_s_block__insert_at_h1_back		= 23; // <mutators>
			static constexpr key_type copy_s_pos__insert_at_h0_front		= 24; // opt, <mutators>
			static constexpr key_type copy_s_pos__insert_at_h1_back			= 25; // opt, <mutators>

			// heap -> stack:

			static constexpr key_type move_h0_first__insert_at_s_front		= 26; // <mutators>
			static constexpr key_type move_h0_first__insert_at_s_pos		= 27; // opt, <mutators>
			static constexpr key_type move_h0_first__replace_at_s_pos		= 28; // opt, <mutators>

			static constexpr key_type move_h1_all__insert_at_s_front		= 29; // <mutators>
			static constexpr key_type move_h1_all__value_at_s_front			= 30; // <near linear>

			static constexpr key_type apply_h1_all__move__replace_at_s_pos		= 31; // opt, <machine>

			static constexpr key_type compel_h1_all__move__replace_at_s_pos		= 32; // opt, <machine>

			// heap -> heap:

			static constexpr key_type apply_h1_all__move__insert_at_h0_front	= 33; // <machine>

			static constexpr key_type compel_h1_all__move__insert_at_h0_front	= 34; // <machine>

		// interposers:

			static constexpr key_type branch					= 35; // <machine>
			static constexpr key_type go_to						= 36; // <machine>

			static constexpr key_type pass						= 37; // <machine>
			static constexpr key_type block						= 38;
			static constexpr key_type linear					= 39;
			static constexpr key_type control					= 40; // <machine>
			static constexpr key_type subcall					= 41; // <machine>
			static constexpr key_type call						= 42; // <machine>

		// recursors:

			static constexpr key_type recurse__insert_at_h0_front			= 43; // <machine>
			static constexpr key_type trampoline__insert_at_h0_front		= 44; // <machine>

		// reflection:

			static constexpr key_type reg_size					= 45;
	};

	using MN = MachineName;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// notes:

/***********************************************************************************************************************/

	struct PassNote
	{
		static constexpr key_type recall		= 0;
		static constexpr key_type reindex		= 1;
		static constexpr key_type recurse		= 2;
	};

	using PT = PassNote;

	struct CallNote
	{
		static constexpr key_type fast			= 0;
		static constexpr key_type scalable		= 1;
	};

	using CT = CallNote;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machines:

private:

	template<key_type, key_type, key_type...> struct machine;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// halters:

/***********************************************************************************************************************/

// pause:

	template<key_type... filler>
	struct machine<MN::pause, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto sc = U_opt_pack_Vs<U_type_T<n>, c, i, j, Vs...>;
			constexpr auto hc = U_opt_pack_Vs<U_type_T<T_pretype_T<Heaps>>...>;

			return trampoline_pair(sc, hc);
		}
	};

/***********************************************************************************************************************/

// first:

	template<key_type... filler>
	struct machine<MN::first, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto V0, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return V0;
		}
	};

/***********************************************************************************************************************/

// rest:

	template<key_type... filler>
	struct machine<MN::rest, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto V0, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return U_opt_pack_Vs<Vs...>;
		}
	};

/***********************************************************************************************************************/

// pack:

	template<key_type... filler>
	struct machine<MN::pack, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return U_opt_pack_Vs<Vs...>;
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// debuggers:

/***********************************************************************************************************************/

// depth:

	template<key_type... filler>
	struct machine<MN::depth, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return d;
		}
	};

/***********************************************************************************************************************/

// dump:

	template<key_type... filler>
	struct machine<MN::dump, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto un = U_type_T<n>;
			constexpr auto rp = U_opt_pack_Vs<un, c, i, j, Vs...>;

			return U_opt_pack_Vs<rp, U_type_T<T_pretype_T<Heaps>>...>;
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (stack -> stack):

/***********************************************************************************************************************/

// sizeof stack all, insert at stack front:

	template<key_type... filler>
	struct machine<MN::sizeof_s_all__insert_at_s_front, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(n, c, d, i, j)

				sizeof...(Vs), Vs...

			NIK_END_MACHINE(Hs...);
		}
	};

/***********************************************************************************************************************/

// align stack all, insert at stack front:

	template<key_type... filler>
	struct machine<MN::align_s_all__insert_at_s_front, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto utype, auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<utype, Ws...>*), Heaps... Hs)
		{
			constexpr T_type_U<utype> array[] = { Vs... };

			return NIK_BEGIN_MACHINE(n, c, d, i, j)

				array

			NIK_END_MACHINE(U_opt_pack_Vs<Ws...>, Hs...);
		}
	};

/***********************************************************************************************************************/

// shift index block, insert at stack back (2^N):

	NIK_DEFINE__SHIFT_I_BLOCK__INSERT_AT_S_BACK(0);
	NIK_DEFINE__SHIFT_I_BLOCK__INSERT_AT_S_BACK(1);
	NIK_DEFINE__SHIFT_I_BLOCK__INSERT_AT_S_BACK(2);
	NIK_DEFINE__SHIFT_I_BLOCK__INSERT_AT_S_BACK(3);
	NIK_DEFINE__SHIFT_I_BLOCK__INSERT_AT_S_BACK(4);
	NIK_DEFINE__SHIFT_I_BLOCK__INSERT_AT_S_BACK(5);
	NIK_DEFINE__SHIFT_I_BLOCK__INSERT_AT_S_BACK(6);
	NIK_DEFINE__SHIFT_I_BLOCK__INSERT_AT_S_BACK(7);
	NIK_DEFINE__SHIFT_I_BLOCK__INSERT_AT_S_BACK(8);
	NIK_DEFINE__SHIFT_I_BLOCK__INSERT_AT_S_BACK(9);

/***********************************************************************************************************************/

// map stack all, operation at heap zero first:

	template<key_type... filler>
	struct machine<MN::map_s_all__op_at_h0_first, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto op, auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<op, Ws...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(n, c, d, i, j)

				op(Vs)...

			NIK_END_MACHINE(H0, Hs...);
		}
	};

/***********************************************************************************************************************/

// map stack all, action at heap zero first:

	template<key_type... filler>
	struct machine<MN::map_s_all__act_at_h0_first, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto uact, auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<uact, Ws...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(n, c, d, i, j)

				T_type_U<uact>::template result<Vs>...

			NIK_END_MACHINE(H0, Hs...);
		}
	};

/***********************************************************************************************************************/

// map stack all, array at heap zero first:

	template<key_type... filler>
	struct machine<MN::map_s_all__arr_at_h0_first, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto arr, auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<arr, Ws...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(n, c, d, i, j)

				arr[Vs]...

			NIK_END_MACHINE(H0, Hs...);
		}
	};

/***********************************************************************************************************************/

// drop stack block (2^N):

	NIK_DEFINE__DROP_S_BLOCK(0);
	NIK_DEFINE__DROP_S_BLOCK(1);
	NIK_DEFINE__DROP_S_BLOCK(2);
	NIK_DEFINE__DROP_S_BLOCK(3);
	NIK_DEFINE__DROP_S_BLOCK(4);
	NIK_DEFINE__DROP_S_BLOCK(5);
	NIK_DEFINE__DROP_S_BLOCK(6);
	NIK_DEFINE__DROP_S_BLOCK(7);
	NIK_DEFINE__DROP_S_BLOCK(8);
	NIK_DEFINE__DROP_S_BLOCK(9);

/***********************************************************************************************************************/

// drop stack position (optimization):

	NIK_DEFINE__DROP_S_POS(1, 0, 0);
	NIK_DEFINE__DROP_S_POS(2, 1, 1);
	NIK_DEFINE__DROP_S_POS(3, 2, 1);
	NIK_DEFINE__DROP_S_POS(4, 3, 1);
	NIK_DEFINE__DROP_S_POS(5, 4, 1);
	NIK_DEFINE__DROP_S_POS(6, 5, 1);
	NIK_DEFINE__DROP_S_POS(7, 6, 1);
	NIK_DEFINE__DROP_S_POS(8, 7, 1);

/***********************************************************************************************************************/

// drop stack all:

	template<key_type... filler>
	struct machine<MN::drop_s_all, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
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
				n::next_index2(c, d, i, j)

			>(Hs...);
		}
	};

/***********************************************************************************************************************/

// move stack block, insert at stack back (2^N):

	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_S_BACK(0);

/***********************************************************************************************************************/

// move stack position, insert at stack back (optimization):

	NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(1, 0, 0);
	NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(2, 1, 1);
	NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(3, 2, 1);
	NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(4, 3, 1);
	NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(5, 4, 1);
	NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(6, 5, 1);
	NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(7, 6, 1);
	NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(8, 7, 1);

/***********************************************************************************************************************/

// fold stack block, op at heap zero first (2^N):

	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(0);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(1);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(2);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(3);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(4);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(5);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(6);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(7);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(8);

#ifdef GCC_IMPLEMENTATION

//	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(9);

#endif // GCC_IMPLEMENTATION

		// clang: bracket nesting level defaults to a maximum of 256

	template<key_type... filler>
	struct machine<MN::fold_s_block__op_at_h0_first, _nine, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto V, NIK_2_9_AUTO_VS, auto... Vs,
			auto op, auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<op, Ws...>*), Heaps... Hs)
		{
			constexpr auto val = NIK_2_8_OPS  V,  NIK_2_8_OP_VS;

			return NIK_BEGIN_MACHINE(n, c, d, i, j)

				NIK_2_8_OPS  val,  NIK_UPPER_512_OP_VS, Vs...

			NIK_END_MACHINE(H0, Hs...);
		}
	};

/***********************************************************************************************************************/

// roll stack block, act at heap zero first (2^N):

	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(0);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(1);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(2);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(3);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(4);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(5);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(6);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(7);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(8);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(9);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (stack -> heap):

/***********************************************************************************************************************/

// move stack block, insert at heap zero front (2^N):

	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(0);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(1);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(2);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(3);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(4);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(5);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(6);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(7);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(8);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(9);

/***********************************************************************************************************************/

// move stack block, insert at heap one back (2^N):

	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(0);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(1);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(2);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(3);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(4);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(5);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(6);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(7);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(8);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(9);

/***********************************************************************************************************************/

// move stack first, replace heap one value:

	template<key_type... filler>
	struct machine<MN::move_s_first__replace_at_h1_value, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto V0, auto... Vs, NIK_FIXED_HEAP_PARAMS, typename... Heaps>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(n, c, d, i, j)

				Vs...

			NIK_END_MACHINE(H0, V0, Hs...);
		}
	};

/***********************************************************************************************************************/

// copy stack block, insert at heap zero front (2^N):

	NIK_DEFINE__COPY_S_BLOCK__INSERT_AT_H0_FRONT(0);

/***********************************************************************************************************************/

// copy stack position, insert at heap zero front (optimization):

	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(1, 0);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(2, 1);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(3, 2);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(4, 3);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(5, 4);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(6, 5);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(7, 6);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(8, 7);

/***********************************************************************************************************************/

// copy stack block, insert at heap one back (2^N):

	NIK_DEFINE__COPY_S_BLOCK__INSERT_AT_H1_BACK(0);

/***********************************************************************************************************************/

// copy stack position, insert at heap one back (optimization):

	NIK_DEFINE__COPY_S_POS__INSERT_AT_H1_BACK(1, 0);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H1_BACK(2, 1);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H1_BACK(3, 2);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H1_BACK(4, 3);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H1_BACK(5, 4);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H1_BACK(6, 5);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H1_BACK(7, 6);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H1_BACK(8, 7);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (heap -> stack):

/***********************************************************************************************************************/

// move heap zero first, insert at stack front:

	template<key_type... filler>
	struct machine<MN::move_h0_first__insert_at_s_front, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto W0, auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<W0, Ws...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(n, c, d, i, j)

				W0, Vs...

			NIK_END_MACHINE(U_opt_pack_Vs<Ws...>, Hs...);
		}
	};

/***********************************************************************************************************************/

// move heap zero first, insert at stack position (optimization):

	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(0, 0);
	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(1, 1);
	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(2, 1);
	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(3, 1);
	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(4, 1);
	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(5, 1);
	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(6, 1);
	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(7, 1);

/***********************************************************************************************************************/

// move heap zero first, replace at stack position (optimization):

	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(1, 0, 0);
	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(2, 1, 1);
	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(3, 2, 1);
	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(4, 3, 1);
	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(5, 4, 1);
	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(6, 5, 1);
	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(7, 6, 1);
	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(8, 7, 1);

/***********************************************************************************************************************/

// move heap one all, insert at stack front:

	template<key_type... filler>
	struct machine<MN::move_h1_all__insert_at_s_front, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, auto... Ws, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, void(*H1)(auto_pack<Ws...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(n, c, d, i, j)

				Ws..., Vs...

			NIK_END_MACHINE(H0, U_opt_pack_Vs<>, Hs...);
		}
	};

/***********************************************************************************************************************/

// move heap one all, value at stack front:

	template<key_type... filler>
	struct machine<MN::move_h1_all__value_at_s_front, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename Heap0, auto... Ws, typename... Heaps>
		static constexpr auto result(Heap0 H0, void(*H1)(auto_pack<Ws...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(n, c, d, i, j)

				U_opt_pack_Vs<Ws...>, Vs...

			NIK_END_MACHINE(H0, U_opt_pack_Vs<>, Hs...);
		}
	};

/***********************************************************************************************************************/

// apply heap one all, move, replace at stack position (optimization):

	NIK_DEFINE__APPLY_H1_ALL__MOVE__REPLACE_AT_S_POS(1, 0, 0);
	NIK_DEFINE__APPLY_H1_ALL__MOVE__REPLACE_AT_S_POS(2, 1, 1);
	NIK_DEFINE__APPLY_H1_ALL__MOVE__REPLACE_AT_S_POS(3, 2, 1);
	NIK_DEFINE__APPLY_H1_ALL__MOVE__REPLACE_AT_S_POS(4, 3, 1);
	NIK_DEFINE__APPLY_H1_ALL__MOVE__REPLACE_AT_S_POS(5, 4, 1);
	NIK_DEFINE__APPLY_H1_ALL__MOVE__REPLACE_AT_S_POS(6, 5, 1);
	NIK_DEFINE__APPLY_H1_ALL__MOVE__REPLACE_AT_S_POS(7, 6, 1);
	NIK_DEFINE__APPLY_H1_ALL__MOVE__REPLACE_AT_S_POS(8, 7, 1);

/***********************************************************************************************************************/

// compel heap one all, move, replace at stack position (optimization):

	NIK_DEFINE__COMPEL_H1_ALL__MOVE__REPLACE_AT_S_POS(1, 0, 0);
	NIK_DEFINE__COMPEL_H1_ALL__MOVE__REPLACE_AT_S_POS(2, 1, 1);
	NIK_DEFINE__COMPEL_H1_ALL__MOVE__REPLACE_AT_S_POS(3, 2, 1);
	NIK_DEFINE__COMPEL_H1_ALL__MOVE__REPLACE_AT_S_POS(4, 3, 1);
	NIK_DEFINE__COMPEL_H1_ALL__MOVE__REPLACE_AT_S_POS(5, 4, 1);
	NIK_DEFINE__COMPEL_H1_ALL__MOVE__REPLACE_AT_S_POS(6, 5, 1);
	NIK_DEFINE__COMPEL_H1_ALL__MOVE__REPLACE_AT_S_POS(7, 6, 1);
	NIK_DEFINE__COMPEL_H1_ALL__MOVE__REPLACE_AT_S_POS(8, 7, 1);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (heap -> heap):

/***********************************************************************************************************************/

// apply heap one all, move, insert at heap zero front:

	template<key_type... filler>
	struct machine<MN::apply_h1_all__move__insert_at_h0_front, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, auto op, auto... args, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<Ws...>*), void(*H1)(auto_pack<op, args...>*), Heaps... Hs
		)
		{
			return NIK_MACHINE(n, c, d, i, j)(U_opt_pack_Vs<op(args...), Ws...>, U_opt_pack_Vs<>, Hs...);
		}
	};

/***********************************************************************************************************************/

// compel heap one all, move, insert at heap zero front:

	template<key_type... filler>
	struct machine<MN::compel_h1_all__move__insert_at_h0_front, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, auto act, auto... args, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<Ws...>*), void(*H1)(auto_pack<act, args...>*), Heaps... Hs
		)
		{
			constexpr auto nH0	= U_opt_pack_Vs
						<
							T_type_U<act>::template result<args...>,
							Ws...
						>;

			return NIK_MACHINE(n, c, d, i, j)(nH0, U_opt_pack_Vs<>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// control:

/***********************************************************************************************************************/

// branch:

	template<key_type... filler>
	struct machine<MN::branch, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			bool is_br, auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<is_br, Ws...>*), Heaps... Hs)
		{
			constexpr auto ni = is_br ? n::val(c, i, j) : i;
			constexpr auto nj = is_br ? _zero : j;

			return NIK_MACHINE(n, c, d, ni, nj)(U_opt_pack_Vs<Ws...>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

