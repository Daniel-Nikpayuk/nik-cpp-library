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

//	template<key_type...>
//	static constexpr instr_type apply_h0_all__insert_at_r_front = instruction
//	<
//		MN::call_h0_all, MT::insert_at_r_front, CP::op_at_h0_front
//	>;

//	template<key_type...>
//	static constexpr instr_type compel_h0_all__insert_at_r_front = instruction
//	<
//		MN::call_h0_all, MT::insert_at_r_front, CP::al_at_h0_front
//	>;

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

// dispatch:

	template
	<
		key_type RtnPolicy,
		key_type CallerLoc, index_type CallerPos,
		key_type NameLoc, index_type NamePos,
		key_type PackLoc, index_type PackPos,
		key_type ParamTrait, index_type... Params
	>
	static constexpr instr_type dispatch_call_program()
	{
		constexpr index_type Name		= MN::call;

		constexpr index_type ParamSize		= sizeof...(Params);
		constexpr index_type PackSize		= CD::pack_size(ParamTrait, ParamSize);
		constexpr index_type param_array[]	= { Params... };

		// assertions:

		constexpr bool caller_assert		= (CallerLoc  != CL::id);
		constexpr bool pack_assert		= (PackLoc    != CL::id);
		constexpr bool trait_assert		= (ParamTrait == CT::id || ParamTrait == CT::all);
		constexpr bool params_assert		= CD::assert_no_param_locs_equal_id(PackSize, param_array);

		static_assert( caller_assert , "[call instruction] caller location cannot be id."  );
		static_assert( pack_assert   , "[call instruction] pack location cannot be instr." );
		static_assert( trait_assert  , "[call instruction] param trait must be id or all." );
		static_assert( params_assert , "[call instruction] param locations cannot be id."  );

		// is id note:

		constexpr bool all_nonparams_equal_h0	= CD::all_nonparam_locs_equal_h0(CallerLoc, NameLoc, PackLoc);
		constexpr bool all_params_equal_h0	= CD::all_param_locs_equal_h0<ParamTrait>(PackSize, param_array);

		constexpr bool is_identity_note		= all_nonparams_equal_h0 && all_params_equal_h0;

		// is optimal note:

		constexpr bool is_caller_optimal	= CD::is_generic_optimal ( CallerLoc , CallerPos            );
		constexpr bool is_name_optimal		= CD::is_generic_optimal ( NameLoc   , NamePos              );
		constexpr bool is_pack_optimal		= CD::is_pack_optimal    ( PackLoc   , PackPos   , PackSize );
		constexpr bool is_params_optimal	= CD::is_params_optimal<ParamTrait>(PackSize, param_array);

		constexpr bool is_optimal_note		= is_caller_optimal && is_name_optimal &&
							  is_pack_optimal && is_params_optimal ;

		//

		constexpr index_type Note		= is_identity_note ? MT::id      :
							  is_optimal_note  ? MT::optimal : MT::fetch;

		return instruction
		<
			Name, Note,
			RtnPolicy,
			CallerLoc, CallerPos,
			NameLoc, NamePos,
			PackLoc, PackPos, PackSize,
			ParamTrait, Params...
		>;
	}

// program:

	template
	<
		key_type RtnPolicy,
		key_type CallerLoc, index_type CallerPos,
		key_type NameLoc, index_type NamePos,
		key_type PackLoc, index_type PackPos,
		key_type ParamTrait, index_type... Params
	>
	static constexpr instr_type call_program = dispatch_call_program
	<
		RtnPolicy,
		CallerLoc, CallerPos,
		NameLoc, NamePos,
		PackLoc, PackPos,
		ParamTrait, Params...
	>();

// interface:

	template<key_type RtnPolicy, index_type Caller, index_type Name, index_type... Params>
	static constexpr instr_type call_local_program = call_program
	<
		RtnPolicy,
		CL::h0, Caller,
		CL::h0, Name,
		CT::all, CL::h0, Params...
	>;

	template<key_type RtnPolicy, index_type Caller, index_type Name, index_type... Params>
	static constexpr instr_type call_builtin_program = call_program
	<
		RtnPolicy,
		CL::instr, Caller,
		CL::instr, Name,
		CT::all, CL::instr, Params...
	>;

// syntactic sugar:

	template<key_type RtnPolicy, key_type Name, index_type Pos, key_type BPolicy, key_type Coname, key_type Conote>
	static constexpr instr_type call_builtin_block_program = call_builtin_program
	<
		RtnPolicy, MP::block, Name, Pos, BPolicy, Coname, Conote
	>;

/***********************************************************************************************************************/

// retrieve:

	template<key_type...>
	static constexpr instr_type retrieve = instruction<MN::call, MT::retrieve, CP::replace_at_h1>;

//	template<key_type Policy>
//	static constexpr instr_type retrieve = instruction<MN::call, MT::retrieve, Policy>;

//		template<key_type...> static constexpr instr_type retrieve__return_value  = retrieve<CP::id>;
//		template<key_type...> static constexpr instr_type retrieve__replace_at_h0 = retrieve<CP::replace_at_h0>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// detour:

/***********************************************************************************************************************/

	template<key_type Policy>
	static constexpr instr_type detour_call = instruction
	<
		MN::detour, MT::internal, MN::id, Policy
	>;

	// syntactic sugar:

		template<key_type...>
		static constexpr instr_type apply_recursive__insert_at_r_front = detour_call<CP::insert_at_r_front>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machinate:

/***********************************************************************************************************************/

	template<key_type Note, key_type... Params>
	static constexpr instr_type machinate = instruction
	<
		MN::machinate, Note, Params...
	>;

	// syntactic sugar:

		template<key_type...>  static constexpr instr_type pause		= machinate < MT::pause      >;
		template<key_type...>  static constexpr instr_type unwind		= machinate < MT::unwind     >;
		template<key_type...>  static constexpr instr_type rewind		= machinate < MT::rewind     >;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

/***********************************************************************************************************************/

// index sequence segment (, insert at heap one back):

	template<key_type... filler>
	struct program<MP::block, BN::index_segment, filler...> : public block_program<filler...>
	{
		template<key_type BPolicy, key_type Coname, key_type Conote>
		static constexpr instr_type lines = instruction
		<
			MN::index_block, BPolicy, Coname, Conote
		>;
	};

	// interface:

		template<index_type Size>
		static constexpr auto index_segment__replace_at_h0 = call_builtin_block_program
		<
			CP::replace_at_h0,
			BN::index_segment,
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
	//			if constexpr (MI::is_optimal(Pos)) return copy_r_pos<Note, Pos>;
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

	// h0:

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

	// h1:

		template<index_type Pos>
		static constexpr instr_type copy_i_pos__insert_at_h1_back = instruction
		<
		>;

		template<index_type Pos>
		static constexpr instr_type copy_r_pos__insert_at_h1_back = instruction
		<
		>;

		template<index_type Pos>
		static constexpr instr_type copy_a_pos__insert_at_h1_back = instruction
		<
		>;

		template<index_type Pos>
		static constexpr instr_type copy_h0_pos__insert_at_h1_back = instruction
		<
		>;

		template<index_type Pos>
		static constexpr instr_type copy_h4_pos__insert_at_h1_back = instruction
		<
		>;

	// h2:

		template<index_type Pos>
		static constexpr instr_type copy_i_pos__insert_at_h2_back = instruction
		<
		>;

		template<index_type Pos>
		static constexpr instr_type copy_r_pos__insert_at_h2_back = instruction
		<
		>;

		template<index_type Pos>
		static constexpr instr_type copy_a_pos__insert_at_h2_back = instruction
		<
		>;

		template<index_type Pos>
		static constexpr instr_type copy_h4_pos__insert_at_h2_back = instruction
		<
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

/***********************************************************************************************************************/

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

// machination:

/***********************************************************************************************************************/

private:

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

// parameter:

	template<key_type...> struct Parameter;

/***********************************************************************************************************************/

// all:

	template<key_type... filler>
	struct Parameter<CT::all, filler...>
	{
		template<instr_type ins>
		static constexpr index_type param_size	= MI::length(ins) - CI::loc_offset;

		template<auto size>
		static constexpr auto index_segment	= Fast<size>::U_index_segment;

		// parse:

			template<instr_type ins, auto index_segment>
			static constexpr auto parse()
			{
				constexpr auto l	= ins[CI::loc_offset]; // tmp
				constexpr auto p	= ins[CI::pos_offset]; // tmp

				constexpr auto locs	= PE::template to_constant<p>(index_segment);
				constexpr auto poses	= PE::template map_array<ins, CI::pos_offset>(index_segment);

				return machination(MN::id, locs, poses);
			}

		// params:

			template<instr_type ins>
			static constexpr auto U_params()
			{
				constexpr auto s = param_size<ins>;
				constexpr auto r = Fast<s>::U_index_segment;

				return PE::template map_array<ins, CI::pos_offset>(r);
			}
	};

	using QF = Parameter<CT::all>;

/***********************************************************************************************************************/

// identity:

	template<key_type... filler>
	struct Parameter<CT::id, filler...>
	{
		template<instr_type ins>
		static constexpr index_type param_size	= (QF::template param_size<ins> + 1) >> 1;

		template<auto size>
		static constexpr auto index_segment	= Fast<size>::U_even_index_segment;

		// parse:

			template<instr_type ins, auto index_segment>
			static constexpr auto parse()
			{
				constexpr auto locs	= PE::template map_array<ins, CI::loc_offset>(index_segment);
				constexpr auto poses	= PE::template map_array<ins, CI::pos_offset>(index_segment);

				return machination(MN::id, locs, poses);
			}
	};

	using QO = Parameter<CT::id>;

/***********************************************************************************************************************/

// dispatch:

	template<key_type... filler>
	struct Parameter<CT::dispatch, filler...>
	{
		// find from h4:

			template<auto n, NIK_HEAP_AUTO_CARGS, auto... cAs>
			static constexpr auto find_from_h4(nik_avpcr(auto_pack<NIK_HEAP_CARGS, cAs...>*))
			{
				auto record		= PE::template at<0>(cH4);
				cindex_type size	= MI::length(record);
				bool not_found		= true;
				index_type pos		= _zero;

				while (not_found && pos < size) not_found = (record[++pos] != n);

				return array<index_type, false, 0>;
			//	return array<index_type, !not_found, pos>;
			}

		// opt program:

			template<typename Q, auto ins, auto index_segment, auto... Vs, NIK_HEAP_AUTO_CARGS, auto... cAs>
			static constexpr auto opt_program
			(
		 		nik_avpcr(auto_pack<Vs...>*),
		 		nik_avpcr(auto_pack<NIK_HEAP_CARGS, cAs...>*)
			)
			{
				constexpr label_type c		= label
								<
									retrieve<>,
									rewind<>
								>;

				constexpr auto parsed		= Q::template parse<ins, index_segment>();
				constexpr auto locs		= parsed.h2;
				constexpr auto poses		= parsed.h3;

				constexpr auto nH0		= U_opt_pack_Vs<locs, poses, cH0>;

				constexpr auto h2		= RL::template U_prog_h2<c, Vs...>;
    				constexpr auto h3		= U_opt_pack_Vs<nH0, cH1, cH2, cH3, cH4, cH5, cAs...>;

				return machination(MT::id, h2, h3);
			}

		// h4 program:

			template<typename Q, auto ins, auto pos, auto... Vs, NIK_HEAP_AUTO_CARGS, auto... cAs>
			static constexpr auto h4_program
			(
		 		nik_avpcr(auto_pack<Vs...>*),
		 		nik_avpcr(auto_pack<NIK_HEAP_CARGS, cAs...>*)
			)
			{
				return 0;
			}

		// program:

			template<typename Q, auto ins, auto size, auto... Vs, NIK_HEAP_AUTO_CARGS, auto... cAs>
			static constexpr auto program
			(
		 		nik_avpcr(auto_pack<Vs...>*),
		 		nik_avpcr(auto_pack<NIK_HEAP_CARGS, cAs...>*)
			)
			{
				return 0;
			}
	};

	using QD = Parameter<CT::dispatch>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// make:

	template<key_type...> struct Make;

/***********************************************************************************************************************/

// closed:

	template<key_type... filler>
	struct Make<CT::closed, filler...>
	{
		template<auto ins, auto... Vs, auto prog, auto... Ws>
		static constexpr auto h2(nik_avpcr(auto_pack<prog, Ws...>*))
		{
			constexpr auto params	= U_opt_pack_Vs<Ws...>;
			constexpr auto base	= T_type_U<prog>::base;

			return Resolve<base>::template h2<ins, Vs...>(prog, params);
		}
	};

/***********************************************************************************************************************/

// open:

	template<key_type... filler>
	struct Make<CT::open, filler...>
	{
		template<auto caller, auto name>
		static constexpr auto make(key_type) { return U_type_T<program<caller, name>>; }

		template<auto caller, auto name, template<auto...> class B>
		static constexpr auto make(nik_avpcr(auto_template_pack<B>*)) { return U_type_T<B<name>>; }

		template<auto ins, auto... Vs, auto caller, auto name, auto... ps>
		static constexpr auto h2(nik_avpcr(auto_pack<caller, name, ps...>*))
		{
			constexpr auto prog	= make<caller, name>(caller);
			constexpr auto params	= U_opt_pack_Vs<ps...>;
			constexpr auto base	= T_type_U<prog>::base;

			return Resolve<base>::template h2<ins, Vs...>(prog, params);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// build:

/***********************************************************************************************************************/

	struct Build
	{
		template<auto... Hs, auto... Is, auto... Js, auto... Ks>
		static constexpr label_type lines
		(
			nik_avpcr(auto_pack<Hs...>*),
			nik_avpcr(auto_pack<Is...>*),
			nik_avpcr(auto_pack<Js...>*),
			nik_avpcr(auto_pack<Ks...>*)
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
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// retrieve:

/***********************************************************************************************************************/

	struct Retrieve
	{
		template<auto pos>
		static constexpr auto copy_l_pos__insert_at_h1_back(key_type loc)
		{
			if      (loc == CL::regs) return copy_r_pos__insert_at_h1_back<pos>;
			else if (loc == CL::args) return copy_a_pos__insert_at_h1_back<pos>;
			else if (loc == CL::h4)   return copy_h4_pos__insert_at_h1_back<pos>;
			else                      return copy_h0_pos__insert_at_h1_back<pos>;
		}

		template
		<
			auto h0, auto... Vs,
			auto... locs, auto... poses,
			auto cH2, auto cH3, auto cH4, auto... cAs
		>
		static constexpr auto program
		(
		 	nik_avpcr(auto_pack<locs...>*),
		 	nik_avpcr(auto_pack<poses...>*),
			nik_avpcr(auto_pack<cH2, cH3, cH4, cAs...>*)
		)
		{
			constexpr auto c	= label
						<
							copy_l_pos__insert_at_h1_back<poses>(locs)...,
							heap_one<>
						>;

			constexpr auto cH0	= h0;
			constexpr auto cH1	= U_null_Vs;
			constexpr auto cH5	= U_null_Vs;

			constexpr auto h2	= RL::template U_prog_h2<c, Vs...>;
    			constexpr auto h3	= U_opt_pack_Vs<NIK_HEAP_CARGS, cAs...>;

			return machination(MT::id, h2, h3);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// fetch:

/***********************************************************************************************************************/

	struct Fetch
	{
		// dispatch:

			template<auto ins, typename Heap0, typename Heap1>
			static constexpr auto program(Heap0 H0, Heap1 H1)
			{
				using Q			= Parameter<_zero>; // tmp
				constexpr auto size	= Q::template param_size<ins>;

				if constexpr (CI::is_optimal(size))
				{
					constexpr auto index_segment = Q::template index_segment<size>;

					return QD::template opt_program<Q, ins, index_segment>(H0, H1);
				}
				else
				{
					constexpr auto result = QD::find_from_h4<size>(H1);
					constexpr bool h4_has = result[_zero];

					if constexpr (h4_has)
					{
						constexpr auto pos = result[_one];

						return QD::template h4_program<Q, ins, pos>(H0, H1);
					}
					else return QD::template program<Q, ins, size>(H0, H1);
				}
			}

		// function:

			template<auto ins, auto H0, auto... Vs>
			static constexpr auto function()
			{
			//	constexpr auto caller_ins	= GC::template instrs<ins>();
			//	constexpr auto name_ins		= GN::template instrs<ins>();
			//	constexpr auto param_ins	= GP::template instrs<ins>();
			//	constexpr auto tail_ins		= GE::function_tail_instrs;

			//	return Build::lines(caller_ins, name_ins, param_ins, tail_ins);
				return 0;
			}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

