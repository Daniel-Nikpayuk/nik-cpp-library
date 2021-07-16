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

// permutatic machines source:

private:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomics:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers:

/***********************************************************************************************************************/

// drop stack position:

	template<index_type... filler>
	struct machine<MN::drop_s_pos, _zero, filler...>
	{
		using nn			= VD;
		static constexpr auto nc	= controller_module::template
							drop_s_pos__contr<>;
		static constexpr auto ni	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = controller_module::template // single call
						drop_s_pos__locus<n::pos(c, i, j)>;
			constexpr auto un = U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		NIK_DEFINE__DROP_S_POS(1, 0, 0);
		NIK_DEFINE__DROP_S_POS(2, 1, 1);
		NIK_DEFINE__DROP_S_POS(3, 2, 1);
		NIK_DEFINE__DROP_S_POS(4, 3, 1);
		NIK_DEFINE__DROP_S_POS(5, 4, 1);
		NIK_DEFINE__DROP_S_POS(6, 5, 1);
		NIK_DEFINE__DROP_S_POS(7, 6, 1);
		NIK_DEFINE__DROP_S_POS(8, 7, 1);

/***********************************************************************************************************************/

// move stack position, insert at stack back:

	template<index_type... filler>
	struct machine<MN::move_s_pos__insert_at_s_back, _zero, filler...>
	{
		using nn			= VD;
		static constexpr auto nc	= controller_module::template
							move_s_pos__insert_at_s_back__contr<>;
		static constexpr auto ni	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = controller_module::template // single call
						move_s_pos__insert_at_s_back__locus<n::pos(c, i, j)>;
			constexpr auto un = U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(1, 0, 0);
		NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(2, 1, 1);
		NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(3, 2, 1);
		NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(4, 3, 1);
		NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(5, 4, 1);
		NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(6, 5, 1);
		NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(7, 6, 1);
		NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(8, 7, 1);

/***********************************************************************************************************************/

// move stack position, insert at heap zero front:

	template<index_type... filler>
	struct machine<MN::move_s_pos__insert_at_h0_front, _zero, filler...>
	{
		using nn			= VD;
		static constexpr auto nc	= controller_module::template
							move_s_pos__insert_at_h0_front__contr<>;
		static constexpr auto ni	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = controller_module::template // single call
						move_s_pos__insert_at_h0_front__locus<n::pos(c, i, j)>;
			constexpr auto un = U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		NIK_DEFINE__MOVE_S_POS__INSERT_AT_H0_FRONT(1, 0, 0);
		NIK_DEFINE__MOVE_S_POS__INSERT_AT_H0_FRONT(2, 1, 1);
		NIK_DEFINE__MOVE_S_POS__INSERT_AT_H0_FRONT(3, 2, 1);
		NIK_DEFINE__MOVE_S_POS__INSERT_AT_H0_FRONT(4, 3, 1);
		NIK_DEFINE__MOVE_S_POS__INSERT_AT_H0_FRONT(5, 4, 1);
		NIK_DEFINE__MOVE_S_POS__INSERT_AT_H0_FRONT(6, 5, 1);
		NIK_DEFINE__MOVE_S_POS__INSERT_AT_H0_FRONT(7, 6, 1);
		NIK_DEFINE__MOVE_S_POS__INSERT_AT_H0_FRONT(8, 7, 1);

/***********************************************************************************************************************/

// copy stack position, insert at heap zero front:

	template<index_type... filler>
	struct machine<MN::copy_s_pos__insert_at_h0_front, _zero, filler...>
	{
		using nn			= VD;
		static constexpr auto nc	= controller_module::template
							copy_s_pos__insert_at_h0_front__contr<>;
		static constexpr auto ni	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = controller_module::template // single call
						copy_s_pos__insert_at_h0_front__locus<n::pos(c, i, j)>;
			constexpr auto un = U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(1, 0);
		NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(2, 1);
		NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(3, 2);
		NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(4, 3);
		NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(5, 4);
		NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(6, 5);
		NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(7, 6);
		NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(8, 7);

/***********************************************************************************************************************/

// move heap zero all, insert at stack position:

	template<index_type... filler>
	struct machine<MN::move_h0_all__insert_at_s_pos, _zero, filler...>
	{
		using nn			= VD;
		static constexpr auto nc	= controller_module::template
							move_h0_all__insert_at_s_pos__contr<>;
		static constexpr auto ni	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = controller_module::template // single call(s)
						move_h0_all__insert_at_s_pos__locus<n::pos(c, i, j)>;
			constexpr auto un = U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		NIK_DEFINE__MOVE_H0_ALL__INSERT_AT_S_POS(1, 0, 0);
		NIK_DEFINE__MOVE_H0_ALL__INSERT_AT_S_POS(2, 1, 1);
		NIK_DEFINE__MOVE_H0_ALL__INSERT_AT_S_POS(3, 2, 1);
		NIK_DEFINE__MOVE_H0_ALL__INSERT_AT_S_POS(4, 3, 1);
		NIK_DEFINE__MOVE_H0_ALL__INSERT_AT_S_POS(5, 4, 1);
		NIK_DEFINE__MOVE_H0_ALL__INSERT_AT_S_POS(6, 5, 1);
		NIK_DEFINE__MOVE_H0_ALL__INSERT_AT_S_POS(7, 6, 1);
		NIK_DEFINE__MOVE_H0_ALL__INSERT_AT_S_POS(8, 7, 1);

/***********************************************************************************************************************/

// move heap zero all, replace at stack position:

	template<index_type... filler>
	struct machine<MN::move_h0_all__replace_at_s_pos, _zero, filler...>
	{
		using nn			= VD;
		static constexpr auto nc	= controller_module::template
							move_h0_all__replace_at_s_pos__contr<>;
		static constexpr auto ni	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = controller_module::template // single call(s)
						move_h0_all__replace_at_s_pos__locus<n::pos(c, i, j)>;
			constexpr auto un = U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		NIK_DEFINE__MOVE_H0_ALL__REPLACE_AT_S_POS(1, 0, 0);
		NIK_DEFINE__MOVE_H0_ALL__REPLACE_AT_S_POS(2, 1, 1);
		NIK_DEFINE__MOVE_H0_ALL__REPLACE_AT_S_POS(3, 2, 1);
		NIK_DEFINE__MOVE_H0_ALL__REPLACE_AT_S_POS(4, 3, 1);
		NIK_DEFINE__MOVE_H0_ALL__REPLACE_AT_S_POS(5, 4, 1);
		NIK_DEFINE__MOVE_H0_ALL__REPLACE_AT_S_POS(6, 5, 1);
		NIK_DEFINE__MOVE_H0_ALL__REPLACE_AT_S_POS(7, 6, 1);
		NIK_DEFINE__MOVE_H0_ALL__REPLACE_AT_S_POS(8, 7, 1);

/***********************************************************************************************************************/

// apply heap zero all, move, replace at stack position:

	template<index_type... filler>
	struct machine<MN::apply_h0_all__move__replace_at_s_pos, _zero, filler...>
	{
		using nn			= VD;
		static constexpr auto nc	= controller_module::template
							apply_h0_all__move__replace_at_s_pos__contr<>;
		static constexpr auto ni	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = controller_module::template // single call(s)
						apply_h0_all__move__replace_at_s_pos__locus<n::pos(c, i, j)>;
			constexpr auto un = U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		NIK_DEFINE__APPLY_H0_ALL__MOVE__REPLACE_AT_S_POS(1, 0, 0);
		NIK_DEFINE__APPLY_H0_ALL__MOVE__REPLACE_AT_S_POS(2, 1, 1);
		NIK_DEFINE__APPLY_H0_ALL__MOVE__REPLACE_AT_S_POS(3, 2, 1);
		NIK_DEFINE__APPLY_H0_ALL__MOVE__REPLACE_AT_S_POS(4, 3, 1);
		NIK_DEFINE__APPLY_H0_ALL__MOVE__REPLACE_AT_S_POS(5, 4, 1);
		NIK_DEFINE__APPLY_H0_ALL__MOVE__REPLACE_AT_S_POS(6, 5, 1);
		NIK_DEFINE__APPLY_H0_ALL__MOVE__REPLACE_AT_S_POS(7, 6, 1);
		NIK_DEFINE__APPLY_H0_ALL__MOVE__REPLACE_AT_S_POS(8, 7, 1);

/***********************************************************************************************************************/

// compel heap zero all, move, replace at stack position:

	template<index_type... filler>
	struct machine<MN::compel_h0_all__move__replace_at_s_pos, _zero, filler...>
	{
		using nn			= VD;
		static constexpr auto nc	= controller_module::template
							compel_h0_all__move__replace_at_s_pos__contr<>;
		static constexpr auto ni	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nj = controller_module::template // single call(s)
						compel_h0_all__move__replace_at_s_pos__locus<n::pos(c, i, j)>;
			constexpr auto un = U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

	// optimizations:

		NIK_DEFINE__COMPEL_H0_ALL__MOVE__REPLACE_AT_S_POS(1, 0, 0);
		NIK_DEFINE__COMPEL_H0_ALL__MOVE__REPLACE_AT_S_POS(2, 1, 1);
		NIK_DEFINE__COMPEL_H0_ALL__MOVE__REPLACE_AT_S_POS(3, 2, 1);
		NIK_DEFINE__COMPEL_H0_ALL__MOVE__REPLACE_AT_S_POS(4, 3, 1);
		NIK_DEFINE__COMPEL_H0_ALL__MOVE__REPLACE_AT_S_POS(5, 4, 1);
		NIK_DEFINE__COMPEL_H0_ALL__MOVE__REPLACE_AT_S_POS(6, 5, 1);
		NIK_DEFINE__COMPEL_H0_ALL__MOVE__REPLACE_AT_S_POS(7, 6, 1);
		NIK_DEFINE__COMPEL_H0_ALL__MOVE__REPLACE_AT_S_POS(8, 7, 1);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatch:

/***********************************************************************************************************************/

public:

	struct PD
	{
	// applications:

		static constexpr index_type size (pc_type c, index_type i, index_type) { return c[i][PA::size]; }
		static constexpr index_type name (pc_type c, index_type i, index_type) { return c[i][PA::name]; }
		static constexpr index_type note (pc_type c, index_type i, index_type) { return c[i][PA::note]; }
		static constexpr index_type pos  (pc_type c, index_type i, index_type) { return c[i][PA::pos ]; }

	// iterators:

		// name:

			static constexpr index_type next_name(pc_type c, depth_type d, index_type i, index_type)
			{
				if (d == 0)	return MN::pause;
				else 		return c[i+1][PA::name];
			}

		// note:

			static constexpr index_type next_note(pc_type c, depth_type d, index_type i, index_type)
			{
				if (d == 0) return _zero;
				else return c[i+1][PA::note];
			}

		// depth:

			static constexpr depth_type (*next_depth)(depth_type) =
				MD::template default_next_depth<depth_type>;

		// index1:

			static constexpr index_type next_index1(pc_type c, depth_type d, index_type i, index_type)
			{
				if (d == 0)	return i;
				else 		return i+1;
			}

		// index2:

			static constexpr index_type (*next_index2)(pc_type, depth_type, index_type, index_type) =
				MD::template default_next_index2<pc_type, depth_type, index_type, index_type>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

