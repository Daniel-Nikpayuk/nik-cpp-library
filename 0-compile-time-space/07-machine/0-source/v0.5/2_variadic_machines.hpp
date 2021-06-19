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

// variadic machines:

private:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomics:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// halters:

/***********************************************************************************************************************/

// stop (optimized):

		// doesn't update the heaps.

	template<index_type... filler>
	struct machine<MN::stop, _zero, filler...>
	{
		using nn			= BD;
		static constexpr auto nc	= controller_module::template drop_s_block__contr<MN::first>;

		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto pos	= n::pos(c, i, j);		// single call
			constexpr depth_type nj	= block_max_index2(pos);	// single call
			constexpr depth_type ni	= pos + nj;			// single call

			return NIK_MACHINE(nn, nc, d, ni, nj)(Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (stack):

/***********************************************************************************************************************/

// drop stack segment:

	template<index_type... filler>
	struct machine<MN::drop_s_segment, _zero, filler...>
	{
		using nn			= BD;
		static constexpr auto nc	= controller_module::template drop_s_block__contr<>;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr depth_type pos	= n::pos(c, i, j);
			constexpr depth_type nj		= block_max_index2(pos);
			constexpr depth_type ni		= pos + nj;

			constexpr auto un		= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// move stack segment, insert at stack back:

	template<index_type... filler>
	struct machine<MN::move_s_segment__insert_at_s_back, _zero, filler...>
	{
		using nn			= BD;
		static constexpr auto nc	= controller_module::template move_s_block__insert_at_s_back__contr<>;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr depth_type pos	= n::pos(c, i, j);
			constexpr depth_type nj		= block_max_index2(pos);
			constexpr depth_type ni		= pos + nj;

			constexpr auto un		= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// fold stack segment, pos at heap zero first:

	template<index_type... filler>
	struct machine<MN::fold_s_segment__pos_at_h0_first, _zero, filler...>
	{
		using nn			= BD;
		static constexpr auto nc	= controller_module::template fold_s_block__op_at_h0_first__contr<>;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto pos, auto... Ws, typename Heap1, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<pos, Ws...>*), Heap1 H1, Heaps... Hs)
		{
			constexpr depth_type nj		= block_max_index2(pos);
			constexpr depth_type ni		= pos + nj;

			constexpr auto un		= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(U_opt_pack_Vs<Ws...>, H1, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// roll stack segment, pos at heap zero first:

	template<index_type... filler>
	struct machine<MN::roll_s_segment__pos_at_h0_first, _zero, filler...>
	{
		using nn			= BD;
		static constexpr auto nc	= controller_module::template roll_s_block__act_at_h0_first__contr<>;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto pos, auto... Ws, typename Heap1, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<pos, Ws...>*), Heap1 H1, Heaps... Hs)
		{
			constexpr depth_type nj		= block_max_index2(pos);
			constexpr depth_type ni		= pos + nj;

			constexpr auto un		= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(U_opt_pack_Vs<Ws...>, H1, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (stack to heap):

/***********************************************************************************************************************/

// move stack segment, insert at heap zero back:

	template<index_type... filler>
	struct machine<MN::move_s_segment__insert_at_h0_back, _zero, filler...>
	{
		using nn			= BD;
		static constexpr auto nc	= controller_module::template move_s_block__insert_at_h0_back__contr<>;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr depth_type pos	= n::pos(c, i, j);
			constexpr depth_type nj		= block_max_index2(pos);
			constexpr depth_type ni		= pos + nj;

			constexpr auto un		= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// move stack segment, insert at heap one back:

	template<index_type... filler>
	struct machine<MN::move_s_segment__insert_at_h1_back, _zero, filler...>
	{
		using nn			= BD;
		static constexpr auto nc	= controller_module::template move_s_block__insert_at_h1_back__contr<>;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr depth_type pos	= n::pos(c, i, j);
			constexpr depth_type nj		= block_max_index2(pos);
			constexpr depth_type ni		= pos + nj;

			constexpr auto un		= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (heap to stack):

/***********************************************************************************************************************/

// move heap zero all, insert at stack front:

	template<index_type... filler>
	struct machine<MN::move_h0_all__insert_at_s_front, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)
		{
			return BEGIN_NIK_MACHINE(n, c, d, i, j)

				Ws..., Vs...

			END_NIK_MACHINE(U_opt_pack_Vs<>, Hs...);
		}
	};

/***********************************************************************************************************************/

// move heap one all, insert at stack front:

	template<index_type... filler>
	struct machine<MN::move_h1_all__insert_at_s_front, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, auto... Ws, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, void(*H1)(auto_pack<Ws...>*), Heaps... Hs)
		{
			return BEGIN_NIK_MACHINE(n, c, d, i, j)

				Ws..., Vs...

			END_NIK_MACHINE(H0, U_opt_pack_Vs<>, Hs...);
		}
	};

/***********************************************************************************************************************/

// copy heap zero all, insert at stack front:

	template<index_type... filler>
	struct machine<MN::copy_h0_all__insert_at_s_front, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)
		{
			return BEGIN_NIK_MACHINE(n, c, d, i, j)

				Ws..., Vs...

			END_NIK_MACHINE(H0, Hs...);
		}
	};

/***********************************************************************************************************************/

// copy heap one all, insert at stack front:

	template<index_type... filler>
	struct machine<MN::copy_h1_all__insert_at_s_front, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, auto... Ws, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, void(*H1)(auto_pack<Ws...>*), Heaps... Hs)
		{
			return BEGIN_NIK_MACHINE(n, c, d, i, j)

				Ws..., Vs...

			END_NIK_MACHINE(H0, H1, Hs...);
		}
	};

/***********************************************************************************************************************/

// apply heap zero all, move, insert at stack front:

	template<index_type... filler>
	struct machine<MN::apply_h0_all__move__insert_at_s_front, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto op, auto... args, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<op, args...>*), Heaps... Hs)
		{
			return BEGIN_NIK_MACHINE(n, c, d, i, j)

				op(args...), Vs...

			END_NIK_MACHINE(U_opt_pack_Vs<>, Hs...);
		}
	};

/***********************************************************************************************************************/

// apply heap zero all, replace heap zero all:

	template<index_type... filler>
	struct machine<MN::apply_h0_all__replace_h0_all, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto op, auto... args, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<op, args...>*), Heaps... Hs)
		{
			return NIK_MACHINE(n, c, d, i, j)(U_opt_pack_Vs<op(args...)>, Hs...);
		}
	};

/***********************************************************************************************************************/

// compel heap zero all, move, insert at stack front:

	template<index_type... filler>
	struct machine<MN::compel_h0_all__move__insert_at_s_front, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto act, auto... args, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<act, args...>*), Heaps... Hs)
		{
			return BEGIN_NIK_MACHINE(n, c, d, i, j)

				T_type_U<act>::template result<args...>, Vs...

			END_NIK_MACHINE(U_opt_pack_Vs<>, Hs...);
		}
	};

/***********************************************************************************************************************/

// compel heap zero all, replace heap zero all:

	template<index_type... filler>
	struct machine<MN::compel_h0_all__replace_h0_all, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto act, auto... args, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<act, args...>*), Heaps... Hs)
		{
			return NIK_MACHINE(n, c, d, i, j)
				(U_opt_pack_Vs<T_type_U<act>::template result<args...>>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatch:

/***********************************************************************************************************************/

public:

	struct VD
	{
	// applications:

		static constexpr index_type pos(vc_type c, index_type i, vl_type j) { return j[i]; }

	// iterators:

		// name:

			static constexpr index_type next_name(vc_type c, depth_type d, index_type i, vl_type j)
			{
				if (d == 0)	return MN::pause;
				else 		return c[i+1];
			}

		// note:

			static constexpr index_type (*next_note)(vc_type, depth_type, index_type, vl_type) =
				MD::template default_next_note<vc_type, depth_type, index_type, vl_type>;

		// depth:

			static constexpr depth_type (*next_depth)(depth_type) =
				MD::template default_next_depth<depth_type>;

		// index1:

			static constexpr index_type next_index1(vc_type c, depth_type d, index_type i, vl_type j)
			{
				if (d == 0)	return i;
				else 		return i+1;
			}

		// index2:

			static constexpr vl_type (*next_index2)(vc_type, depth_type, index_type, vl_type) =
				MD::template default_next_index2<vc_type, depth_type, index_type, vl_type>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

