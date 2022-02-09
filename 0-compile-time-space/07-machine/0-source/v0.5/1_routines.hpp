/************************************************************************************************************************
**
** Copyright 2021-2022 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

// routines source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// instructions:

public:

/***********************************************************************************************************************/

// halters:

	// value:

	template<key_type Note>
	static constexpr instr_type _value = instruction // *value* keyword is reserved for recursive use.
	<
		MN::value, Note
	>;

		template<key_type...> static constexpr instr_type first			= _value < MT::first     >;
		template<key_type...> static constexpr instr_type heap_zero		= _value < MT::h0        >;
		template<key_type...> static constexpr instr_type heap_one		= _value < MT::h1        >;
		template<key_type...> static constexpr instr_type arg_zero		= _value < MT::a0        >;
		template<key_type...> static constexpr instr_type registers		= _value < MT::registers >;
		template<key_type...> static constexpr instr_type arguments		= _value < MT::arguments >;
		template<key_type...> static constexpr instr_type depth			= _value < MT::depth     >;
		template<key_type...> static constexpr instr_type dump			= _value < MT::dump      >;

// passers:

	// block:

	template<key_type...>
	static constexpr instr_type drop_r_first = instruction	// optimization: We call the single block machine
	<							// directly, but still provide computational context.
		MN::move_r_block, _zero, MT::id, CP::drop
	>;

	// linear:

	template<key_type...>
	static constexpr instr_type move_h1_all__insert_at_r_front = instruction
	<
		MN::move_h1_all, MT::insert_at_r_front
	>;

	// near linear:

//	template<index_type Action>
//	static constexpr instr_type map_a0__replace_at_a0 = instruction
//	<
//		MN::select_a0, MT::id, Action, FP::replace_at_a0
//	>;

//	template<index_type...>
//	static constexpr instr_type cat_a0_a1__replace_at_a0 = instruction
//	<
//		MN::catenate_a0_a1, MT::replace_at_a0
//	>;

//	template<index_type Action>
//	static constexpr instr_type zip_a0_a1__replace_at_a0 = instruction
//	<
//		MN::zip_a0_a1, MT::replace_at_a0, Action
//	>;

	// recursive:

	template<key_type...>
	static constexpr instr_type cycle = instruction
	<
		MN::go_to, MT::first
	>;

	template<key_type Index>
	static constexpr instr_type branch = instruction
	<
		MN::go_to, MT::conditional, Index
	>;

	template<key_type...>
	static constexpr instr_type apply_h0_all__insert_at_r_front = instruction
	<
		MN::call_h0_all, MT::insert_at_r_front, CP::op_at_h0_front
	>;

	template<key_type...>
	static constexpr instr_type compel_h0_all__insert_at_r_front = instruction
	<
		MN::call_h0_all, MT::insert_at_r_front, CP::al_at_h0_front
	>;

	// optimizations:

	template<key_type Note, key_type Pos>
	static constexpr instr_type copy_r_pos = instruction
	<
		MN::copy_r_pos, Note, Pos
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// call:

/***********************************************************************************************************************/

// closed:

		// The instruction length is the same as with open.
		//         This is to allow for the refactoring of algorithms.

	template
	<
		key_type RtnPolicy,
		key_type CallerLoc, index_type Caller,
		key_type ParamLoc, index_type... Params
	>
	static constexpr instr_type call_closed_program = instruction
	<
		MN::call, MT::id, RtnPolicy, CallerLoc, Caller, CL::h0, _zero, ParamLoc, Params...
	>;

/***********************************************************************************************************************/

// open:

	template
	<
		key_type RtnPolicy,
		key_type CallerLoc, index_type Caller,
		key_type NameLoc, index_type Name,
		key_type ParamLoc, index_type... Params
	>
	static constexpr instr_type call_open_program = instruction
	<
		MN::call, CL::note(CallerLoc, NameLoc, ParamLoc, sizeof...(Params)),
		RtnPolicy, CallerLoc, Caller, NameLoc, Name, ParamLoc, Params...
	>;

	// interface:

		template<key_type RtnPolicy, index_type Caller, index_type Name, index_type... Params>
		static constexpr instr_type call_builtin_open_program = call_open_program
		<
			RtnPolicy,
			CL::instr, Caller,
			CL::instr, Name,
			CL::all_instr, Params...
		>;

	// syntactic sugar:

		template<key_type RtnPolicy, key_type Name, index_type Pos, key_type BPolicy, key_type Coname, key_type Conote>
		static constexpr instr_type call_builtin_block_program = call_builtin_open_program
		<
			RtnPolicy, MP::block, Name, Pos, BPolicy, Coname, Conote
		>;

/***********************************************************************************************************************/

// interoperators:

	// detour:

	template<key_type Policy>
	static constexpr instr_type detour_call = instruction
	<
		MN::detour, MT::internal, MN::id, Policy
	>;

		template<key_type...>
		static constexpr instr_type apply_recursive__insert_at_r_front = detour_call<CP::insert_at_r_front>;

	// machinate:

	template<key_type Note>
	static constexpr instr_type machinate = instruction
	<
		MN::machinate, Note
	>;

		template<key_type...> static constexpr instr_type pause			= machinate < MT::pause  >;
		template<key_type...> static constexpr instr_type unwind		= machinate < MT::unwind >;
		template<key_type...> static constexpr instr_type rewind		= machinate < MT::rewind >;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

	// Block programs consist of two block instructions and some machine
	// modifiers: As such they can be optimized into a single instruction.

/***********************************************************************************************************************/

// unpack instruction right (, insert at heap one back):

	template<key_type... filler>
	struct program<MP::block, BN::unpack_i_right, filler...> : public block_program<filler...>
	{
		template<key_type BPolicy, key_type Coname, key_type Conote>
		static constexpr instr_type lines = instruction
		<
			MN::unpack_i_block, BPolicy, Coname, Conote
		>;
	};

	// interface:

		template<index_type Size>
		static constexpr auto unpack_i_right__replace_at_h1 = call_builtin_block_program
		<
			CP::replace_at_h1,
			BN::unpack_i_right,
			Size,
			CP::insert_at_h1_back,
			MN::value, MT::h1
		>;

/***********************************************************************************************************************/

// move register segment:

	template<key_type... filler>
	struct program<MP::block, BN::move_r_segment, filler...> : public block_program<filler...>
	{
		template<key_type BPolicy, key_type Coname, key_type Conote>
		static constexpr instr_type lines = instruction
		<
			MN::move_r_block, BPolicy, Coname, Conote
		>;
	};

	// interface:

		template<key_type Policy, index_type Pos, key_type Conote>
		static constexpr instr_type drop_r_segment = call_builtin_block_program
		<
			Policy,
			BN::move_r_segment,
			Pos,
			CP::drop,
			MN::value, Conote
		>;

		template<index_type Pos>
		static constexpr instr_type move_r_segment__insert_at_h1_back = call_builtin_block_program
		<
			CP::load,
			BN::move_r_segment,
			Pos,
			CP::insert_at_h1_back,
			MN::machinate, MT::unwind
		>;

	// syntactic sugar:

	//	template<index_type Pos>
	//	static constexpr instr_type value = drop_r_segment<CP::id, Pos, MT::first>;

	//		template<key_type Note, index_type Pos>
	//		static constexpr auto dispatch_copy_r_pos()
	//		{
	//			if constexpr (MI::is_opt(Pos)) return copy_r_pos<Note, Pos>;
	//			else
	//			{
	//				constexpr auto policy = (Note == MT::insert_at_h0_front) ?
	//							 CP::insert_at_h0_front          :
	//							 CP::insert_at_h0_back           ;

	//				return drop_r_segment<policy, Pos, MT::first>;
	//			}
	//		}

	//	template<index_type Pos>
	//	static constexpr instr_type copy_r_pos__insert_at_h0_front = dispatch_copy_r_pos
	//	<
	//		MT::insert_at_h0_front, Pos
	//	>();

	//	template<index_type Pos>
	//	static constexpr instr_type copy_r_pos__insert_at_h0_back = dispatch_copy_r_pos
	//	<
	//		MT::insert_at_h0_back, Pos
	//	>();

		template<index_type Pos>
		static constexpr instr_type copy_i_pos__insert_at_h0_back = instruction
		<
		>;

		template<index_type Pos>
		static constexpr instr_type copy_r_pos__insert_at_h0_back = instruction
		<
		>;

		template<index_type Pos>
		static constexpr instr_type copy_a_pos__insert_at_h0_back = instruction
		<
		>;

		template<index_type Pos>
		static constexpr instr_type copy_h4_pos__insert_at_h0_back = instruction
		<
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

/***********************************************************************************************************************/

		template<key_type...>
		static constexpr auto fetch_rs__replace_at_h1 = instruction
		<
		>;

		template<key_type...>
		static constexpr auto fetch_as__replace_at_h1 = instruction
		<
		>;

		template<key_type...>
		static constexpr auto fetch_h4s__replace_at_h1 = instruction
		<
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// recursive:

/***********************************************************************************************************************/

// make:

//	template<key_type... filler>
//	struct program<MP::linear, LN::get_generic_program, filler...> : public linear_program<filler...>
//	{
//		template<index_type Pos>
//		static constexpr label_type lines = label
//		<
//			copy_c_pos__insert_at_h0_back<Pos>,
//			get_generic_params<>
//		>;
//	};

	// interface:

/***********************************************************************************************************************/

// run generic program:

//	template<key_type... filler>
//	struct program<MP::linear, LN::run_generic_program, filler...> : public linear_program<filler...>
//	{
//		template<index_type Pos>
//		static constexpr label_type lines = label
//		<
//			move_r_segment__insert_at_h1_back<Pos>,
//			drop_r_first<>,
//			apply_recursive__insert_at_r_front<>,	// ?
//			move_h1_all__insert_at_r_front<>,
//			unwind<>
//		>;
//	};

	// interface:

/***********************************************************************************************************************/

// test:

//	template<key_type... filler>
//	struct program<MP::linear, LN::test, filler...> : public linear_program<filler...>
//	{
//		template<index_type Op, index_type... Args>
//		static constexpr label_type lines = label
//		<
//			copy_r_pos__insert_at_h0_back<Op>,
//			copy_r_pos__insert_at_h0_back<Args>...,
//			apply_h0_all__replace_at_h0_front<>,
//			unwind<>
//		>;
//	};

	// interface:

	//	template<index_type Op, index_type... Args>
	//	static constexpr instr_type test = call_linear_program
	//	<
	//		LN::test,
	//		CP::load,
	//		Op, Args...
	//	>;

/***********************************************************************************************************************/

// check:

//	template<key_type... filler>
//	struct program<MP::linear, LN::check, filler...> : public linear_program<filler...>
//	{
//		template<index_type Op, index_type... Args>
//		static constexpr label_type lines = label
//		<
//			copy_r_pos__insert_at_h0_back<Op>,
//			copy_r_pos__insert_at_h0_back<Args>...,
//			compel_h0_all__replace_at_h0_front<>,
//			unwind<>
//		>;
//	};

	// interface:

	//	template<index_type Op, index_type... Args>
	//	static constexpr instr_type check = call_linear_program
	//	<
	//		LN::check,
	//		CP::load,
	//		Op, Args...
	//	>;

/***********************************************************************************************************************/

// apply:

//	template<key_type... filler>
//	struct program<MP::linear, LN::apply, filler...> : public linear_program<filler...>
//	{
//		template<index_type Pos, index_type Op, index_type... Args>
//		static constexpr label_type lines = label
//		<
//			copy_r_pos__insert_at_h0_back<Op>,
//			copy_r_pos__insert_at_h0_back<Args>...,
//			move_r_segment__insert_at_h1_back<Pos>,
//			drop_r_first<>,
//			apply_h0_all__insert_at_r_front<>,
//			move_h1_all__insert_at_r_front<>,
//			unwind<>
//		>;
//	};

	// interface:

	//	template<index_type Pos, index_type Op, index_type... Args>
	//	static constexpr instr_type apply = call_linear_program
	//	<
	//		LN::apply,
	//		CP::load,
	//		Pos, Op, Args...
	//	>;

/***********************************************************************************************************************/

// compel:

//	template<key_type... filler>
//	struct program<MP::linear, LN::compel, filler...> : public linear_program<filler...>
//	{
//		template<index_type Pos, index_type Op, index_type... Args>
//		static constexpr label_type lines = label
//		<
//			copy_r_pos__insert_at_h0_back<Op>,
//			copy_r_pos__insert_at_h0_back<Args>...,
//			move_r_segment__insert_at_h1_back<Pos>,
//			drop_r_first<>,
//			compel_h0_all__insert_at_r_front<>,
//			move_h1_all__insert_at_r_front<>,
//			unwind<>
//		>;
//	};

	// interface:

	//	template<index_type Pos, index_type Op, index_type... Args>
	//	static constexpr instr_type compel = call_linear_program
	//	<
	//		LN::compel,
	//		CP::load,
	//		Pos, Op, Args...
	//	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// get:

private:

/***********************************************************************************************************************/

	template<key_type...>
	struct Get
	{
			template<index_type... Is>
			static constexpr auto copy_is__insert_at_h0_back = U_opt_pack_Vs
			<
				copy_i_pos__insert_at_h0_back<Is>...
			>;

			template<index_type... Is>
			static constexpr label_type copy_rs__insert_at_h0_back = U_opt_pack_Vs
			<
				copy_r_pos__insert_at_h0_back<Is>...
			>;

			template<index_type... Is>
			static constexpr label_type copy_as__insert_at_h0_back = U_opt_pack_Vs
			<
				copy_a_pos__insert_at_h0_back<Is>...
			>;

			template<index_type... Is>
			static constexpr label_type copy_h4s__insert_at_h0_back = U_opt_pack_Vs
			<
				copy_h4_pos__insert_at_h0_back<Is>...
			>;

		// function:

			static constexpr auto func_tail = U_opt_pack_Vs
			<
				unwind<>
			>;

		// program:

			static constexpr auto prog_tail = U_opt_pack_Vs
			<
				rewind<>
			>;
	};

	using GE = Get<>;

/***********************************************************************************************************************/

// caller:

	template<key_type... filler>
	struct Get<CI::caller, filler...> : public GE
	{
		template<auto ins>
		static constexpr auto instrs()
		{
			constexpr auto caller_loc = ins[CI::caller_loc];

			if constexpr (caller_loc == CL::instr) return copy_is__insert_at_h0_back<CI::caller>;
			else
			{
				constexpr auto pos = ins[CI::caller];

				if constexpr      (caller_loc == CL::regs) return copy_rs__insert_at_h0_back<pos>;
				else if constexpr (caller_loc == CL::args) return copy_as__insert_at_h0_back<pos>;
				else                                       return copy_h4s__insert_at_h0_back<pos>;
			}
		}
	};

	using GC = Get<CI::caller>;

/***********************************************************************************************************************/

// name:

	template<key_type... filler>
	struct Get<CI::name, filler...> : public GE
	{
		template<auto ins>
		static constexpr auto instrs()
		{
			constexpr auto name_loc = ins[CI::name_loc];

			if constexpr      (name_loc == CL::h0   ) return U_null_Vs; // closed.
			else if constexpr (name_loc == CL::instr) return copy_is__insert_at_h0_back<CI::name>;
			else
			{
				constexpr auto pos = ins[CI::name];

				if constexpr      (name_loc == CL::regs) return copy_rs__insert_at_h0_back<pos>;
				else if constexpr (name_loc == CL::args) return copy_as__insert_at_h0_back<pos>;
				else                                     return copy_h4s__insert_at_h0_back<pos>;
			}
		}
	};

	using GN = Get<CI::name>;

/***********************************************************************************************************************/

// parameters:

	template<key_type... filler>
	struct Get<CI::param, filler...> : public Get<filler...>
	{
		template<auto Size>
		static constexpr auto all_instr = U_opt_pack_Vs
		<
			unpack_i_right__replace_at_h1<Size>
		>;

		template<auto Size>
		static constexpr auto all_regs = U_opt_pack_Vs
		<
			unpack_i_right__replace_at_h1<Size>,
			fetch_rs__replace_at_h1<>
		>;

		template<auto Size>
		static constexpr auto all_args = U_opt_pack_Vs
		<
			unpack_i_right__replace_at_h1<Size>,
			fetch_as__replace_at_h1<>
		>;

		template<auto Size>
		static constexpr auto all_h4 = U_opt_pack_Vs
		<
			unpack_i_right__replace_at_h1<Size>,
			fetch_h4s__replace_at_h1<>
		>;

		template<auto ins>
		static constexpr auto instrs()
		{
			constexpr auto param_loc	= ins[CI::param_loc];
			constexpr auto size		= RG::template size<ins>;

			if constexpr      (param_loc == CL::all_instr) return all_instr<size>;
			else if constexpr (param_loc == CL::all_regs ) return all_regs<size>;
			else if constexpr (param_loc == CL::all_args ) return all_args<size>;
			else                                           return all_h4<size>;
		}
	};

	using GP = Get<CI::param>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// build:

/***********************************************************************************************************************/

// label:

	template<auto... Hs, auto... Is, auto... Js, auto... Ks>
	static constexpr auto build_label
	(
		void(*)(auto_pack<Hs...>*),
		void(*)(auto_pack<Is...>*),
		void(*)(auto_pack<Js...>*),
		void(*)(auto_pack<Ks...>*)
	)
	{
		return label
		<
			Hs...,
			Is...,
			Js...,
			Ks...
		>;
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machination:

/***********************************************************************************************************************/

	// Do not refactor using other templated structs. Although these definitions are potentially redundant,
	// trampolining/detouring require a distinct keyword so there's no confusion with other returned values.

	template<typename Stack1Cache, typename Stack2Cache>
	struct machination
	{
		key_type m;

		Stack1Cache h2;
		Stack2Cache h3;

		constexpr machination(key_type _m, const Stack1Cache & _h2, const Stack2Cache & _h3) :
					m{_m}, h2{_h2}, h3{_h3} { }
	};

	//

	template<typename T>
	static constexpr bool is_machination(T) { return false; }

	template<typename Stack1Cache, typename Stack2Cache>
	static constexpr bool is_machination(const machination<Stack1Cache, Stack2Cache> &) { return true; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// fetch:

/***********************************************************************************************************************/

// function:

	template<auto ins, auto H0, auto... Vs>
	static constexpr auto fetch_func()
	{
		constexpr auto caller_ins	= GC::template instrs<ins>();
		constexpr auto name_ins		= GN::template instrs<ins>();
		constexpr auto param_ins	= GP::template instrs<ins>();
		constexpr auto tail_ins		= GE::func_tail;

		return build_label(caller_ins, name_ins, param_ins, tail_ins);
	}

/***********************************************************************************************************************/

// program:

	template<auto ins, auto... Vs, typename Heap0, typename Heap1, typename... Heaps>
	static constexpr auto fetch_program(Heap0 H0, Heap1 H1, Heaps... Hs)
	{
		if constexpr (CL::is_h0_all(ins))
		{
			constexpr auto shape	= CL::shape(ins);
			constexpr auto nH2	= Make<shape>::template h2<ins, Vs...>(H0);
			constexpr auto nH3	= U_opt_pack_Vs<U_null_Vs, U_pretype_T<Heap1>, U_pretype_T<Heaps>...>;

			return machination(nH2, nH3);
		}
		else
		{
			constexpr auto caller_ins	= GC::template instrs<ins>();
			constexpr auto name_ins		= GN::template instrs<ins>();
			constexpr auto param_ins	= GP::template instrs<ins>();
			constexpr auto tail_ins		= GE::prog_tail;
			constexpr auto c		= build_label(caller_ins, name_ins, param_ins, tail_ins);

			constexpr auto length		= RG::template length<ins>;
			constexpr auto nH0		= U_opt_pack_Vs<ins, length>;

			constexpr auto nH2		= RL::template U_prog_h2<c, Vs...>;
    			constexpr auto nH3		= U_opt_pack_Vs<nH0, U_null_Vs, Hs...>;

			return machination(nH2, nH3);
		}
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

