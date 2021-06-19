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

// register machines:

private:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomics:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// halters:

/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers:

/***********************************************************************************************************************/

// assign:

	template<index_type... filler>
	struct machine<MN::assign, _zero, filler...>
	{
		using nn			= VD;
		static constexpr auto nc	= controller_module::template
							move_h0_all__replace_at_s_pos__contr<>;
		static constexpr auto ni	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, typename Heap1, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heap1 H1, Heaps... Hs)
		{
			constexpr auto nj = controller_module::template // single call(s)
						move_h0_all__replace_at_s_pos__locus<n::pos(c, i, j)>;
			constexpr auto un = U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)
				(U_opt_pack_Vs<Ws..., n::obj(c, i, j)>, H1, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (dispatch):

/***********************************************************************************************************************/

// branch:

	template<index_type... filler>
	struct machine<MN::branch, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			bool is_br, auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<is_br, Ws...>*), Heaps... Hs)
		{
			constexpr auto i1 = is_br ? n::pos(c, i, j) : i;
			constexpr auto j1 = is_br ? _zero : j;

			return NIK_MACHINE(n, c, d, i1, j1)(U_opt_pack_Vs<Ws...>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// operators:

/***********************************************************************************************************************/

// go to, pos at heap zero first (optimized):

	template<index_type... filler>
	struct machine<MN::go_to__next_at_h0_front, _zero, filler...>
	{
		static constexpr auto nj = _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto ni, auto un, auto nc, auto... Ws, typename Heap1, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<ni, un, nc, Ws...>*), Heap1 H1, Heaps... Hs)
		{
			using nn = T_type_U<un>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(U_opt_pack_Vs<Ws...>, H1, Hs...);
		}
	};

/***********************************************************************************************************************/

// go to (optimized):

	template<index_type... filler>
	struct machine<MN::go_to, MD::regtr, filler...>
	{
		using nn			= PD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template<depth_type pos>
		static constexpr auto go_to_contr = controller_module::template p_controller
		<
			controller_module::template copy_s_pos__insert_at_h0_front<pos>,

			controller_module::template call<MN::go_to__next_at_h0_front, _zero>
		>;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, typename Heap1, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heap1 H1, Heaps... Hs)
		{
			constexpr auto nc = go_to_contr<n::pos(c, i, j)>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(U_opt_pack_Vs<un, c, Ws...>, H1, Hs...);
		}
	};

/***********************************************************************************************************************/

// save:

	template<index_type... filler>
	struct machine<MN::save, _zero, filler...>
	{
		using nn			= PD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc = controller_module::template // single call(s)
						insert_contr<n::reg_size(c, i, j), n::pos(c, i, j)>;
			constexpr auto un = U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// restore:

	template<index_type... filler>
	struct machine<MN::restore, _zero, filler...>
	{
		using nn			= PD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template<depth_type pos, depth_type obj, pa_type cont = controller_module::template pass<>>
		static constexpr auto restore_contr = controller_module::template p_controller
		<
			controller_module::template move_s_pos__insert_at_h0_front<obj>,
			controller_module::template move_h0_all__replace_at_s_pos<pos>,

			cont
		>;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto un = U_type_T<n>;
			constexpr auto nc = restore_contr<n::pos(c, i, j), n::reg_size(c, i, j)>; // single call(s)

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatch:

/***********************************************************************************************************************/

public:

	// Initializers require (l = 0, m = k) -> first instruction.

	// modularizing assign, save, restore, is better design, but given
	// compile time performance constraints optimization is privileged.

	struct RD
	{
	// applications:

	static constexpr index_type size   (rc_type c, index_type i, index_type j) { return c[i][j][RA::size  ]; }
	static constexpr index_type name   (rc_type c, index_type i, index_type j) { return c[i][j][RA::name  ]; }
	static constexpr index_type note   (rc_type c, index_type i, index_type j) { return c[i][j][RA::note  ]; }
	static constexpr index_type pos    (rc_type c, index_type i, index_type j) { return c[i][j][RA::pos   ]; }

	static constexpr index_type obj    (rc_type c, index_type i, index_type j) { return c[i][j][RA::obj   ]; }

	static constexpr index_type op     (rc_type c, index_type i, index_type j) { return c[i][j][RA::op    ]; }
	static constexpr index_type arg    (rc_type c, index_type i, index_type j) { return c[i][j][RA::arg   ]; }
	static constexpr index_type arg1   (rc_type c, index_type i, index_type j) { return c[i][j][RA::arg1  ]; }
	static constexpr index_type arg2   (rc_type c, index_type i, index_type j) { return c[i][j][RA::arg2  ]; }

	static constexpr index_type pred   (rc_type c, index_type i, index_type j) { return c[i][j][RA::pred  ]; }
	static constexpr index_type input  (rc_type c, index_type i, index_type j) { return c[i][j][RA::input ]; }
	static constexpr index_type input1 (rc_type c, index_type i, index_type j) { return c[i][j][RA::input1]; }
	static constexpr index_type input2 (rc_type c, index_type i, index_type j) { return c[i][j][RA::input2]; }

	static constexpr index_type reg_size (rc_type c, index_type, index_type)   { return RC::reg_size(c); }

	// iterators:

		// basics:

			static constexpr index_type basic_next_index1(rc_type c, index_type i, index_type j)
			{
				return i + bool{j == RL::length(c[i])};	// j == last : return i+1.
									// j != last : return i.
			}

			static constexpr index_type basic_next_index2(rc_type c, index_type i, index_type j)
			{
				return (j == RL::length(c[i])) ? _one : j+1;	// j == last : return one.
										// j != last : return j+1.
			}

		// index1:

			static constexpr index_type next_index1(rc_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0) return i;

				index_type ni	= basic_next_index1(c, i, j);
				index_type nj	= basic_next_index2(c, i, j);
				index_type name	= c[ni][nj][RA::name];
				index_type note	= c[ni][nj][RA::note];

				if (name == MN::go_to && note == MD::contr)	return c[ni][nj][RA::pos];
				else 						return ni;
			}

		// index2:

			static constexpr index_type next_index2(rc_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0) return j;

				index_type ni	= basic_next_index1(c, i, j);
				index_type nj	= basic_next_index2(c, i, j);
				index_type name	= c[ni][nj][RA::name];
				index_type note	= c[ni][nj][RA::note];

				if (name == MN::go_to && note == MD::contr)	return _one;
				else						return nj;
			}

		// name:

			static constexpr index_type next_name(rc_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0) return MN::pause;

				index_type ni = next_index1(c, d, i, j);
				index_type nj = next_index2(c, d, i, j);

				return c[ni][nj][RA::name];
			}

		// note:

			static constexpr index_type next_note(rc_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0) return _zero;

				index_type ni = next_index1(c, d, i, j);
				index_type nj = next_index2(c, d, i, j);

				return c[ni][nj][RA::note];
			}

		// depth:

			static constexpr depth_type (*next_depth)(depth_type) =
				MD::template default_next_depth<depth_type>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

