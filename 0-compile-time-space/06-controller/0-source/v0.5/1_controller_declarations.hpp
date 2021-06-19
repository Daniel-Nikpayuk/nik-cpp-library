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

// controller declarations:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block controller:

/***********************************************************************************************************************/

// controller:

	using bc_type = index_type const*;

	struct BC
	{
		// members:

			static constexpr index_type size = 0;
			static constexpr index_type name = 1;
			static constexpr index_type cont = 2;

		// procedures:

			static constexpr index_type length (bc_type c) { return c[size]; }
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	static constexpr bc_type b_controller = array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specializations:

/***********************************************************************************************************************/

// drop stack block:

	template<index_type Cont = MN::pass>
	static constexpr auto drop_s_block__contr = b_controller
	<
		MN::drop_s_block, Cont
	>;

/***********************************************************************************************************************/

// move stack block, insert at stack back:

	template<index_type Cont = MN::pass>
	static constexpr auto move_s_block__insert_at_s_back__contr = b_controller
	<
		MN::move_s_block__insert_at_s_back, Cont
	>;

/***********************************************************************************************************************/

// fold stack block, op at heap zero first:

	template<index_type Cont = MN::pass>
	static constexpr auto fold_s_block__op_at_h0_first__contr = b_controller
	<
		MN::fold_s_block__op_at_h0_first, Cont
	>;

/***********************************************************************************************************************/

// roll stack block, act at heap zero first:

	template<index_type Cont = MN::pass>
	static constexpr auto roll_s_block__act_at_h0_first__contr = b_controller
	<
		MN::roll_s_block__act_at_h0_first, Cont
	>;

/***********************************************************************************************************************/

// move stack block, insert at heap zero back:

	template<index_type Cont = MN::pass>
	static constexpr auto move_s_block__insert_at_h0_back__contr = b_controller
	<
		MN::move_s_block__insert_at_h0_back, Cont
	>;

/***********************************************************************************************************************/

// move stack block, insert at heap one back:

	template<index_type Cont = MN::pass>
	static constexpr auto move_s_block__insert_at_h1_back__contr = b_controller
	<
		MN::move_s_block__insert_at_h1_back, Cont
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic controller:

/***********************************************************************************************************************/

// locus:

	using vl_type = depth_type const*;

		// pack length is stored as the initial value.

	template<depth_type... Vs>
	static constexpr vl_type v_locus = array<depth_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/

// controller:

	using vc_type = index_type const*;

	struct VC
	{
		// members:

			static constexpr index_type size = 0;

		// procedures:

			static constexpr index_type length (vc_type c) { return c[size]; }
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	static constexpr vc_type v_controller = array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specializations:

/***********************************************************************************************************************/

// drop stack position:

	template<index_type Cont = MN::pass>
	static constexpr auto drop_s_pos__contr = v_controller
	<
		MN::move_s_segment__insert_at_h0_back,
		MN::drop_s_block,
		MN::move_h0_all__insert_at_s_front,

		Cont
	>;

	template<depth_type Pos>
	static constexpr auto drop_s_pos__locus = v_locus
	<
		Pos, _zero, _zero, _zero
	>;

/***********************************************************************************************************************/

// move stack position, insert at stack back:

	template<index_type Cont = MN::pass>
	static constexpr auto move_s_pos__insert_at_s_back__contr = v_controller
	<
		MN::move_s_segment__insert_at_h0_back,
		MN::move_s_block__insert_at_s_back,
		MN::move_h0_all__insert_at_s_front,

		Cont
	>;

	template<depth_type Pos>
	static constexpr auto move_s_pos__insert_at_s_back__locus = v_locus
	<
		Pos, _zero, _zero, _zero
	>;

/***********************************************************************************************************************/

// move stack position, insert at heap zero front:

	template<index_type Cont = MN::pass>
	static constexpr auto move_s_pos__insert_at_h0_front__contr = v_controller
	<
		MN::move_s_segment__insert_at_h1_back,
		MN::move_s_block__insert_at_h0_front,
		MN::move_h1_all__insert_at_s_front,

		Cont
	>;

	template<depth_type Obj>
	static constexpr auto move_s_pos__insert_at_h0_front__locus = v_locus
	<
		Obj, _zero, _zero, _zero
	>;

/***********************************************************************************************************************/

// copy stack position, insert at heap zero front:

	template<index_type Cont = MN::pass>
	static constexpr auto copy_s_pos__insert_at_h0_front__contr = v_controller
	<
		MN::move_s_segment__insert_at_h1_back,
		MN::copy_s_block__insert_at_h0_front,
		MN::move_h1_all__insert_at_s_front,

		Cont
	>;

	template<depth_type Obj>
	static constexpr auto copy_s_pos__insert_at_h0_front__locus = v_locus
	<
		Obj, _zero, _zero, _zero
	>;

/***********************************************************************************************************************/

// move heap zero all, insert at stack position:

	template<index_type Cont = MN::pass>
	static constexpr auto move_h0_all__insert_at_s_pos__contr = v_controller
	<
		MN::move_s_segment__insert_at_h1_back,
		MN::move_h0_all__insert_at_s_front,
		MN::move_h1_all__insert_at_s_front,

		Cont
	>;

	template<depth_type Pos>
	static constexpr auto move_h0_all__insert_at_s_pos__locus = v_locus
	<
		Pos, _zero, _zero, _zero
	>;

/***********************************************************************************************************************/

// move heap zero all, replace at stack position:

	template<index_type Cont = MN::pass>
	static constexpr auto move_h0_all__replace_at_s_pos__contr = v_controller
	<
		MN::move_s_segment__insert_at_h1_back,
		MN::drop_s_block,
		MN::move_h0_all__insert_at_s_front,
		MN::move_h1_all__insert_at_s_front,

		Cont
	>;

	template<depth_type Pos>
	static constexpr auto move_h0_all__replace_at_s_pos__locus = v_locus
	<
		Pos, _zero, _zero, _zero, _zero
	>;

/***********************************************************************************************************************/

// apply heap zero all, move, replace at stack position:

	template<index_type Cont = MN::pass>
	static constexpr auto apply_h0_all__move__replace_at_s_pos__contr = v_controller
	<
		MN::move_s_segment__insert_at_h1_back,
		MN::drop_s_block,
		MN::apply_h0_all__move__insert_at_s_front,
		MN::move_h1_all__insert_at_s_front,

		Cont
	>;

	template<depth_type Pos>
	static constexpr auto apply_h0_all__move__replace_at_s_pos__locus = v_locus
	<
		Pos, _zero, _zero, _zero, _zero
	>;

/***********************************************************************************************************************/

// compel heap zero all, move, replace at stack position:

	template<index_type Cont = MN::pass>
	static constexpr auto compel_h0_all__move__replace_at_s_pos__contr = v_controller
	<
		MN::move_s_segment__insert_at_h1_back,
		MN::drop_s_block,
		MN::compel_h0_all__move__insert_at_s_front,
		MN::move_h1_all__insert_at_s_front,

		Cont
	>;

	template<depth_type Pos>
	static constexpr auto compel_h0_all__move__replace_at_s_pos__locus = v_locus
	<
		Pos, _zero, _zero, _zero, _zero
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// permutatic controller:

/***********************************************************************************************************************/

// application:

	// inherits from machine applications:

		using pa_type	= ma_type;
		using PA	= MA;

/***********************************************************************************************************************/

// controller:

	using pc_type = pa_type const*;

	struct PC
	{
		// members:

			static constexpr index_type size = 0;

		// procedures:

			static constexpr index_type length (pc_type c) { return c[size][PA::size]; }
	};

		// pack length is stored as the initial value.

	template<pa_type... Vs>
	static constexpr pc_type p_controller = array<pa_type, array<index_type, sizeof...(Vs)>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specializations:

/***********************************************************************************************************************/

// erase:

	template<depth_type Pos, pa_type Cont = pass<>>
	static constexpr auto erase_contr = p_controller
	<
		drop_s_pos<Pos>,

		Cont
	>;

/***********************************************************************************************************************/

// insert:

	template<depth_type Pos, depth_type Obj, pa_type Cont = pass<>>
	static constexpr auto insert_contr = p_controller
	<
		copy_s_pos__insert_at_h0_front<Obj>,
		move_h0_all__insert_at_s_pos<Pos>,	// includes undefined behaviour.

		Cont
	>;

/***********************************************************************************************************************/

// replace:

	template<depth_type Pos, depth_type Obj, pa_type Cont = pass<>>
	static constexpr auto replace_contr = p_controller
	<
		copy_s_pos__insert_at_h0_front<Obj>,
		move_h0_all__replace_at_s_pos<Pos>,	// includes undefined behaviour.

		Cont
	>;

/***********************************************************************************************************************/

// unary apply replace:

	template<depth_type Pos, depth_type Op, depth_type Arg, pa_type Cont = pass<>>
	static constexpr auto apply1_replace_contr = p_controller
	<
		copy_s_pos__insert_at_h0_front<Arg>,
		copy_s_pos__insert_at_h0_front<Op>,
		apply_h0_all__move__replace_at_s_pos<Pos>,	// includes undefined behaviour.

		Cont
	>;

/***********************************************************************************************************************/

// binary apply replace:

	template<depth_type Pos, depth_type Op, depth_type Arg1, depth_type Arg2, pa_type Cont = pass<>>
	static constexpr auto apply2_replace_contr = p_controller
	<
		copy_s_pos__insert_at_h0_front<Arg2>,
		copy_s_pos__insert_at_h0_front<Arg1>,
		copy_s_pos__insert_at_h0_front<Op>,
		apply_h0_all__move__replace_at_s_pos<Pos>,	// includes undefined behaviour.

		Cont
	>;

/***********************************************************************************************************************/

// unary compel replace:

	template<depth_type Pos, depth_type Op, depth_type Arg, pa_type Cont = pass<>>
	static constexpr auto compel1_replace_contr = p_controller
	<
		copy_s_pos__insert_at_h0_front<Arg>,
		copy_s_pos__insert_at_h0_front<Op>,
		compel_h0_all__move__replace_at_s_pos<Pos>,	// includes undefined behaviour.

		Cont
	>;

/***********************************************************************************************************************/

// binary compel replace:

	template<depth_type Pos, depth_type Op, depth_type Arg1, depth_type Arg2, pa_type Cont = pass<>>
	static constexpr auto compel2_replace_contr = p_controller
	<
		copy_s_pos__insert_at_h0_front<Arg2>,
		copy_s_pos__insert_at_h0_front<Arg1>,
		copy_s_pos__insert_at_h0_front<Op>,
		compel_h0_all__move__replace_at_s_pos<Pos>,	// includes undefined behaviour.

		Cont
	>;

/***********************************************************************************************************************/

// unary test replace:

	template<depth_type Op, depth_type Arg, pa_type Cont = pass<>>
	static constexpr auto test1_replace_contr = p_controller
	<
		copy_s_pos__insert_at_h0_front<Arg>,
		copy_s_pos__insert_at_h0_front<Op>,
		apply_h0_all__replace_h0_all<>,			// includes undefined behaviour.

		Cont
	>;

/***********************************************************************************************************************/

// binary test replace:

	template<depth_type Op, depth_type Arg1, depth_type Arg2, pa_type Cont = pass<>>
	static constexpr auto test2_replace_contr = p_controller
	<
		copy_s_pos__insert_at_h0_front<Arg2>,
		copy_s_pos__insert_at_h0_front<Arg1>,
		copy_s_pos__insert_at_h0_front<Op>,
		apply_h0_all__replace_h0_all<>,			// includes undefined behaviour.

		Cont
	>;

/***********************************************************************************************************************/

// unary check replace:

	template<depth_type Op, depth_type Arg, pa_type Cont = pass<>>
	static constexpr auto check1_replace_contr = p_controller
	<
		copy_s_pos__insert_at_h0_front<Arg>,
		copy_s_pos__insert_at_h0_front<Op>,
		compel_h0_all__replace_h0_all<>,		// includes undefined behaviour.

		Cont
	>;

/***********************************************************************************************************************/

// binary check replace:

	template<depth_type Op, depth_type Arg1, depth_type Arg2, pa_type Cont = pass<>>
	static constexpr auto check2_replace_contr = p_controller
	<
		copy_s_pos__insert_at_h0_front<Arg2>,
		copy_s_pos__insert_at_h0_front<Arg1>,
		copy_s_pos__insert_at_h0_front<Op>,
		compel_h0_all__replace_h0_all<>,		// includes undefined behaviour.

		Cont
	>;

/***********************************************************************************************************************/

// left:

	template<depth_type Pos, pa_type Cont = pass<>>
	static constexpr auto left_contr = p_controller
	<
		move_s_segment__insert_at_h1_back<Pos>,
		clear<>,
		move_h1_all__insert_at_s_front<>,

		Cont
	>;

/***********************************************************************************************************************/

// roll:

	template<pa_type Cont = pass<>>
	static constexpr auto roll__contr = p_controller
	<
		call<MN::roll_s_segment__pos_at_h0_first, _zero>,

		Cont
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// distributic controller:

/***********************************************************************************************************************/

// application:

	// inherits from machine applications:

		using da_type	= ma_type;
		using DA	= MA;

/***********************************************************************************************************************/

// controller:

	using dc_type = da_type const*;

	struct DC
	{
		// members:

			static constexpr index_type size = 0;

		// procedures:

			static constexpr index_type length (dc_type c) { return c[size][DA::size]; }
	};

		// pack length is stored as the initial value.

	template<da_type... Vs>
	static constexpr dc_type d_controller = array<da_type, array<index_type, sizeof...(Vs)>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specializations:

/***********************************************************************************************************************/

// call:

	template<da_type Appl, da_type Cont = pass<>>
	static constexpr auto call_contr = d_controller<Appl, Cont>;

/***********************************************************************************************************************/

// skip:

	template<da_type Test, da_type Ante, da_type Conse, da_type Cont = pass<>>
	static constexpr auto skip_contr = d_controller<Test, skip<MA::binary>, Ante, Cont, Conse, Cont>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// near linear controller:

/***********************************************************************************************************************/

// applications:

	// inherits from machine applications:

		using na_type	= ma_type;
		using NA	= MA;

/***********************************************************************************************************************/

// continuation passing functors:

	using np_type = na_type const*;

	struct NP
	{
		// members:

			static constexpr index_type size		= 0;
			static constexpr index_type name		= 1;

			static constexpr index_type appl		= 2;

			static constexpr index_type cond		= 2;
			static constexpr index_type appl1		= 3;
			static constexpr index_type appl2		= 4;

		// constants:

			static constexpr na_type lift			= m_application<MN::lift, _zero>;
			static constexpr na_type stem			= m_application<MN::stem, _zero>;
			static constexpr na_type halt			= m_application<MN::halt, _zero>;
			static constexpr na_type cycle			= m_application<MN::cycle, _zero>;

		// procedures:

			static constexpr index_type length(np_type n)	{ return n[size][NA::size]; }
	};

		// pack length is stored as the initial value.

	template<na_type... Vs>
	static constexpr np_type n_continuation = array<na_type, array<index_type, sizeof...(Vs)>, Vs...>;

	// syntactic sugar:

		template<na_type N>
		static constexpr np_type n_lift = n_continuation<NP::lift, N>;

		template<na_type P, na_type B, na_type N>
		static constexpr np_type n_stem = n_continuation<NP::stem, P, B, N>;

		template<na_type B>
		static constexpr np_type n_halt = n_continuation<NP::halt, B>;

		static constexpr np_type n_cycle = n_continuation<NP::cycle>;

/***********************************************************************************************************************/

// controller:

	using nc_type = np_type const*;

	struct NC
	{
		// members:

			static constexpr index_type size	= 0;

		// procedures:

			static constexpr index_type length(nc_type c) { return c[size][NP::size][NA::size]; }
	};

		// pack length is stored as the initial value.

	template<np_type... Vs>
	static constexpr nc_type n_controller = array
		<np_type, array<na_type, array<index_type, sizeof...(Vs)>>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register controller:

/***********************************************************************************************************************/

// applications:

	// inherits from machine applications:

		using ra_type	= ma_type;
		using RA	= MA;

/***********************************************************************************************************************/

// labels:

	using rl_type = ra_type const*;

	struct RL
	{
		// members:

			static constexpr index_type size 	= 0;
			static constexpr index_type first	= 1;

		// procedures:

			static constexpr index_type	length(rl_type l)	{ return l[size][RA::size]; }
			static constexpr ra_type	last(rl_type l)		{ return l[length(l)]; }
	};

		// pack length is stored as the initial value.

	template<ra_type... Vs>
	static constexpr rl_type r_label = array<ra_type, array<index_type, sizeof...(Vs)>, Vs...>;

/***********************************************************************************************************************/

// controller:

	using rc_type = rl_type const*;

	struct RC
	{
		// members:

			static constexpr index_type size = 0;

		// procedures:

			static constexpr index_type	length   (rc_type c) { return c[size][RL::size][RA::size]; }
			static constexpr rl_type	last     (rc_type c) { return c[length(c)]; }
			static constexpr index_type	reg_size (rc_type c) { return RL::last(last(c))[RA::pos]; }
	};

		// pack length is stored as the initial value.

	template<rl_type... Vs>
	static constexpr rc_type r_controller = array
		<rl_type, array<ra_type, array<index_type, sizeof...(Vs)>>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

