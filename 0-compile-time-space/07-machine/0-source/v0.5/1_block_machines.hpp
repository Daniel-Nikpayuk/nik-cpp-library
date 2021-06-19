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

// block machines:

private:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomics:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// halters:

/***********************************************************************************************************************/

// first:

	template<index_type... filler>
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

	template<index_type... filler>
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

	template<index_type... filler>
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

	template<index_type... filler>
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

	template<index_type... filler>
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

// passers:

/***********************************************************************************************************************/

// pause:

	template<index_type... filler>
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

// pass:

	template<index_type... filler>
	struct machine<MN::pass, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, auto un, auto nc, auto ni, auto nj, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, void(*H2)(auto_pack<un, nc, ni, nj>*), Heaps... Hs)
		{
			using nn = T_type_U<un>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (stack):

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

// move stack block, insert at stack back (2^N):

	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_S_BACK(0);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_S_BACK(1);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_S_BACK(2);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_S_BACK(3);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_S_BACK(4);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_S_BACK(5);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_S_BACK(6);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_S_BACK(7);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_S_BACK(8);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_S_BACK(9);

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

//	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(9); // clang: bracket nesting level defaults to a maximum of 256

#endif // GCC_IMPLEMENTATION

	template<index_type... filler>
	struct machine<MN::fold_s_block__op_at_h0_first, _nine, filler...>
	{
		template<NIK_CONTR_PARAMS, auto V, NIK_2_9_AUTO_VS, auto... Vs, auto op, auto... Ws, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<op, Ws...>*), Heaps... Hs)
		{
			constexpr auto val = NIK_2_8_OPS  V,  NIK_2_8_OP_VS;

			return BEGIN_NIK_MACHINE(n, c, d, i, j)

				NIK_2_8_OPS  val,  NIK_UPPER_512_OP_VS, Vs...

			END_NIK_MACHINE(H0, Hs...);
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

// passers (stack to heap):

/***********************************************************************************************************************/

// move stack block, insert at heap zero front (2^N):

	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(0);

/***********************************************************************************************************************/

// move stack block, insert at heap zero back (2^N):

	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_BACK(0);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_BACK(1);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_BACK(2);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_BACK(3);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_BACK(4);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_BACK(5);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_BACK(6);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_BACK(7);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_BACK(8);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_BACK(9);

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

// copy stack block, insert at heap zero front (2^N):

	NIK_DEFINE__COPY_S_BLOCK__INSERT_AT_H0_FRONT(0);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatch:

public:

/***********************************************************************************************************************/

	static constexpr index_type block_max_note(depth_type n)
	{
		return	(n >= _2_9) ? 9 :
			(n >= _2_8) ? 8 :
			(n >= _2_7) ? 7 :
			(n >= _2_6) ? 6 :
			(n >= _2_5) ? 5 :
			(n >= _2_4) ? 4 :
			(n >= _2_3) ? 3 :
			(n >= _2_2) ? 2 :
			(n >= _2_1) ? 1 : 0 ;
	}

	static constexpr depth_type block_max_index2(depth_type n)
	{
		return	(n >= _2_9) ? _2_9 :
			(n >= _2_8) ? _2_8 :
			(n >= _2_7) ? _2_7 :
			(n >= _2_6) ? _2_6 :
			(n >= _2_5) ? _2_5 :
			(n >= _2_4) ? _2_4 :
			(n >= _2_3) ? _2_3 :
			(n >= _2_2) ? _2_2 :
			(n >= _2_1) ? _2_1 :
			(n >= _2_0) ? _2_0 : 0 ;
	}

	struct BD
	{
	// iterators:

		// name:

			static constexpr index_type next_name(bc_type c, depth_type d, depth_type i, depth_type j)
			{
				if (d == 0)	return MN::pause;	// assumes i >= j, next i := i - j
				else if (i > j)	return c[BC::name];	// implies next i > 0
				else 		return c[BC::cont];	// otherwise next i == 0
			}

		// note:

			static constexpr index_type next_note(bc_type c, depth_type d, depth_type i, depth_type j)
			{
				if (d == 0)	return _zero;
				else		return block_max_note(i - j);
			}

		// depth:

			static constexpr depth_type (*next_depth)(depth_type) =
				MD::template default_next_depth<depth_type>;

		// index1:

			static constexpr depth_type next_index1(bc_type c, depth_type d, depth_type i, depth_type j)
			{
				if (d == 0)	return i;
				else 		return i - j;
			}

		// index2:

			static constexpr depth_type next_index2(bc_type c, depth_type d, depth_type i, depth_type j)
			{
				if (d == 0)	return j;
				else		return block_max_index2(i - j);
			}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

