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

// call specifications:

	template<key_type...>
	struct CallSpecification
	{
		static constexpr key_type id		=  0;
		static constexpr key_type identity	= id;	// convenience for
								// default params.
		static constexpr key_type handle	=  1;
		static constexpr key_type name		=  2;
		static constexpr key_type pack		=  3;
		static constexpr key_type param		=  4;

		// matchers:

			template<key_type V> static constexpr bool is_value  (ckey_type v) { return (v == V); }
			template<key_type V> static constexpr bool not_value (ckey_type v) { return (v != V); }

			// needed any more?

		//	template<typename... Ts>
		//	static constexpr bool all(Ts... vs) { return (... && vs); }

		//	template<typename T, typename... Ts>
		//	static constexpr bool all_equal(T v, Ts... vs) { return all((v == vs)...); }

		// cache level:

			static constexpr key_type cache_level(ckey_type location, cindex_type position)
			{
				if      (location == CL::instr)    return _zero;
				else if (MI::is_optimal(position)) return _one;
				else                               return _two;
			}
	};

	using CS = CallSpecification<>;

/***********************************************************************************************************************/

// handle:

	template<key_type... filler>
	struct CallSpecification<CS::handle, filler...>
	{
		ckey_type location;
		cindex_type position;

		constexpr CallSpecification(ckey_type l, cindex_type p) : location(l), position(p) { }

		// cache level:

			constexpr auto cache_level() const
				{ return CS::cache_level(location, position); }
	};

	using HandleSpec = CallSpecification<CS::handle>;

/***********************************************************************************************************************/

// name:

	template<key_type... filler>
	struct CallSpecification<CS::name, filler...>
	{
		static constexpr key_type closed	=  0;
		static constexpr key_type open		=  1;

		ckey_type location;
		cindex_type position;

		constexpr CallSpecification(ckey_type l, cindex_type p) : location(l), position(p) { }

		// assertions:

			constexpr bool assert_id_location() const
				{ return (location != CL::id) || (position == 0); }

		// shape:

			constexpr auto shape() const
				{ return (location == CL::id) ? closed : open; }

		// cache level:

			constexpr auto cache_level() const
				{ return CS::cache_level(location, position); }
	};

	using NameSpec = CallSpecification<CS::name>;

/***********************************************************************************************************************/

// pack:

	template<key_type... filler>
	struct CallSpecification<CS::pack, filler...>
	{
		ckey_type location;
		cindex_type position;
		ckey_type key;

		constexpr CallSpecification(ckey_type l, cindex_type p, ckey_type k) :
			location(l), position(p), key(k) { }

		// cache level:

			constexpr auto cache_level(cindex_type size) const
			{
				if (location == CL::id)
				{
					if (MI::is_optimal(size)) return _zero;
					else                      return _three;
				}
				else
				{
					if (MI::is_optimal(position)) return _one;
					else                          return _two;
				}
			}
	};

	using PackSpec = CallSpecification<CS::pack>;

/***********************************************************************************************************************/

// param (all):

	template<key_type... filler>
	struct CallSpecification<CS::param, CT::all, filler...>
	{
		cindex_type size;
		ckey_type *locs;

		constexpr CallSpecification(cindex_type s, ckey_type *l) : size(s), locs(l) { }

		// locations:

			template<key_type Loc0, index_type... Poses, typename T>
			static constexpr auto locations(T) { return U_opt_pack_Vs<Loc0>; }

		// positions:

			template<key_type Loc0, index_type... Poses, typename T>
			static constexpr auto positions(T) { return U_opt_pack_Vs<Poses...>; }

		// predicates:

			constexpr bool no_locs_equal_id() const
				{ return CS::template not_value<CL::id>(*locs); }

		// cache levels:

			template<auto Loc0, auto... Poses>
			constexpr auto cache_levels(nik_avpcr(auto_pack<Loc0>*), nik_avpcr(auto_pack<Poses...>*)) const
			{
				if constexpr (Loc0 == CL::instr)

					return U_opt_pack_Vs<PE::template first<_zero, Poses>...>;
				else
					return U_opt_pack_Vs<(MI::is_optimal(Poses) ? _one : _two)...>;
			}
	};

/***********************************************************************************************************************/

// param (id):

	template<key_type... filler>
	struct CallSpecification<CS::param, CT::id, filler...>
	{
		cindex_type size;
		ckey_type *locs;

		constexpr CallSpecification(cindex_type s, ckey_type *l) : size(s), locs(l) { }

		// subparams:

			template<key_type offset, index_type... Params, auto... Is>
			static constexpr auto subparams(nik_avpcr(auto_pack<Is...>*))
			{
				if constexpr (sizeof...(Params) == 0) return U_null_Vs;
				else
				{
					constexpr index_type arr[] = { Params... };

					return U_opt_pack_Vs<arr[(Is << 1) + offset]...>;
				}
			}

		// locations:

			template<index_type... Params, typename T>
			static constexpr auto locations(T v) { return subparams<_zero, Params...>(v); }

		// positions:

			template<index_type... Params, typename T>
			static constexpr auto positions(T v) { return subparams<_one, Params...>(v); }

		// all locs match:

			template<auto match>
			constexpr bool all_locs_match() const
			{
				if (size == 0) return true;
				else
				{
					bool result = true;

					for (ckey_type *k = locs; result && k < locs + size; ++k)
						result = match(*k);

					return result;
				}
			}

		// predicates:

			constexpr bool no_locs_equal_id() const
				{ return all_locs_match<CS::template not_value<CL::id>>(); }

		// cache levels:

			template<auto... Locs, auto... Poses>
			constexpr auto cache_levels(nik_avpcr(auto_pack<Locs...>*), nik_avpcr(auto_pack<Poses...>*)) const
				{ return U_opt_pack_Vs<CS::cache_level(Locs, Poses)...>; }
	};

	template<key_type Trait>
	using ParamSpec = CallSpecification<CS::param, Trait>;

/***********************************************************************************************************************/

// id:

	template<key_type Trait, key_type... filler>
	struct CallSpecification<CS::id, Trait, filler...>
	{
		ckey_type rtn_policy;

		const HandleSpec handle_spec;
		const NameSpec name_spec;
		const PackSpec pack_spec;
		const ParamSpec<Trait> param_spec;

		constexpr CallSpecification
		(
			ckey_type rp,
			const HandleSpec & h, const NameSpec & n, const PackSpec & p, const ParamSpec<Trait> & ps

		) : rtn_policy(rp), handle_spec(h), name_spec(n), pack_spec(p), param_spec(ps) { }

		// assertions:

			constexpr bool assert_handle () const { return handle_spec.location != CL::id; }
			constexpr bool assert_name   () const { return true; }
			constexpr bool assert_pack   () const { return pack_spec.location != CL::instr; }
			constexpr bool assert_trait  () const { return Trait == CL::id || Trait == CT::all; }
			constexpr bool assert_param  () const { return param_spec.no_locs_equal_id(); }

		// array max:

			constexpr auto array_max(ckey_type *cache_levels) const
			{
				index_type size		= param_spec.size + _three;
				key_type current_max	= _zero;

				for (ckey_type *k = cache_levels; k < cache_levels + size; ++k)
					if (*k > current_max) current_max = *k;

				return current_max;
			}

		// machine note:

			template<auto IndSpec>
			constexpr auto machine_note(ckey_type total_cache_level) const
			{
				if      (total_cache_level == 0) return MT::cache_level_0;
				else if (total_cache_level == 1) return MT::cache_level_1;
				else if (total_cache_level == 2) return MT::cache_level_2;
				else                             return MT::cache_level_3;
			}

		// cache level instruction:

			template<auto... ParamCLs, auto... Locs, auto... Poses>
			constexpr auto cache_level_instruction
			(
				nik_avpcr(auto_pack<ParamCLs...>*),
				nik_avpcr(auto_pack<Locs...>*),
				nik_avpcr(auto_pack<Poses...>*)

			) const
			{
				constexpr auto handle_cl	= handle_spec.cache_level();
				constexpr auto name_cl		= name_spec.cache_level();
				constexpr auto pack_cl		= pack_spec.cache_level(param_spec.size);

				constexpr key_type cl_array[]	= { handle_cl, name_cl, pack_cl, ParamCLs... };
				constexpr auto total_cl		= array_max(cl_array);
				constexpr auto note		= machine_note(total_cl);

				return instruction
				<
					MN::call, note, rtn_policy,
					handle_spec.location, handle_spec.position,
					name_spec.location, name_spec.position,
					pack_spec.location, pack_spec.position, pack_spec.key,
					Trait, param_spec.size,
					handle_cl, name_cl, pack_cl, ParamCLs...,
					Locs..., Poses...
				>;
			}

		// construct instruction:

			template<typename LocsType, typename PosesType>
			constexpr auto construct_instruction(LocsType, PosesType) const
			{
				constexpr auto LocsPack		= U_pretype_T<LocsType>;
				constexpr auto PosesPack	= U_pretype_T<PosesType>;
				constexpr auto ParamCLsPack	= param_spec.cache_levels(LocsPack, PosesPack);

				return cache_level_instruction(ParamCLsPack, LocsPack, PosesPack);
			}
	};

	template<key_type Trait>
	using IdSpec = CallSpecification<CS::id, Trait>;

/***********************************************************************************************************************/

// call program:

	template
	<
		key_type RtnPolicy,
		key_type HandleLoc, index_type HandlePos,
		key_type NameLoc, index_type NamePos,
		key_type PackLoc, index_type PackPos, key_type PackKey,
		key_type ParamTrait, index_type... Params,
		typename T
	>
	static constexpr instr_type call_program(T)
	{
		constexpr auto Handle		= HandleSpec(HandleLoc, HandlePos);
		constexpr auto Name		= NameSpec(NameLoc, NamePos);
		constexpr auto Pack		= PackSpec(PackLoc, PackPos, PackKey);

		constexpr auto IndSeg		= U_pretype_T<T>;
		constexpr auto ParamLocs	= ParamSpec<ParamTrait>::template locations<Params...>(IndSeg);
		constexpr auto ParamPoses	= ParamSpec<ParamTrait>::template positions<Params...>(IndSeg);

		constexpr auto ParamLocsArray	= PE::template to_array<index_type>(ParamLocs);
		constexpr auto ParamLocsSize	= PE::template length(ParamLocs);
		constexpr auto Param		= ParamSpec<ParamTrait>(ParamLocsSize, ParamLocsArray);

		constexpr auto Spec		= IdSpec<ParamTrait>(RtnPolicy, Handle, Name, Pack, Param);

		static_assert(Spec.assert_handle (), "[call instruction] caller location cannot be id."  );
		static_assert(Spec.assert_pack   (), "[call instruction] pack location cannot be instr." );
		static_assert(Spec.assert_trait  (), "[call instruction] param trait must be id or all." );
		static_assert(Spec.assert_param  (), "[call instruction] param locations cannot be id."  );
		// assert sizeof...(Is) == Spec.param_size();
		// assert that if trait == all, then there is a single loc, and at least one pos.
		// assert that if trait == id, then there is an even number of parameters.

		return Spec.construct_instruction(ParamLocs, ParamPoses);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// call instructions:

/***********************************************************************************************************************/

public:

// program:

	// interface:

//		template<key_type RtnPolicy, index_type Handle, index_type Name, index_type... Params>
//		static constexpr instr_type call_local_program = call_program
//		<
//			RtnPolicy,
//			CL::h0, Handle,
//			CL::h0, Name,
//			CT::all, CL::h0, Params...
//		>;

//		template<key_type RtnPolicy, index_type Handle, index_type Name, index_type... Params>
//		static constexpr instr_type call_builtin_program = call_program
//		<
//			RtnPolicy,
//			CL::instr, Handle,
//			CL::instr, Name,
//			CT::all, CL::instr, Params...
//		>;

	// syntactic sugar:

//		template<key_type RtnPolicy, key_type Name, index_type Pos, key_type BPolicy, key_type Coname, key_type Conote>
//		static constexpr instr_type call_builtin_block_program = call_builtin_program
//		<
//			RtnPolicy, MP::block, Name, Pos, BPolicy, Coname, Conote
//		>;

/***********************************************************************************************************************/

// test spec:

	template<key_type RtnPolicy = CP::load>
	static constexpr instr_type test_spec = call_program
	<
		RtnPolicy,
		CL::h0, _zero,
		CL::instr, _five,
		CL::id, _zero, _zero,
		CT::all, CL::instr, 0, 1, 2, 5, 4, 3

	>(Fast<6>::U_index_segment);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machination:

private:

/***********************************************************************************************************************/

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

// call build:

	template<key_type, key_type...> struct CallBuild;

/***********************************************************************************************************************/

// cache level 0:

	template<key_type... Keys> using CallBuild0 = CallBuild<MT::cache_level_0, Keys...>;

	//

	template<key_type... filler>
	struct CallBuild<MT::cache_level_0, filler...>
	{
		// program:

			template<instr_type ins>
			static constexpr auto U_program = U_type_T<program<ins[CI::handle_pos], ins[CI::name_pos]>>;

		// params: assumes Trait == all; loc0 == instr; and is_optimal(size)

			template<instr_type ins>
			static constexpr auto params()
			{
				constexpr auto trait	= ins[CI::param_trait];
				constexpr auto size	= ins[CI::param_size];
				constexpr auto ind_seg	= Fast<size>::U_index_segment;
				constexpr auto offset	= CI::offset + (size << 1);

				return PE::template from_array<ins, offset>(ind_seg);
			}

			template<instr_type ins>
			static constexpr auto U_params = params<ins>();
	};

	using CB0 = CallBuild0<>;

// block:

	template<key_type... filler>
	struct CallBuild<MT::cache_level_0, MP::block, filler...>
	{
		template<auto c, auto pos, auto... Vs>
		static constexpr auto U_resolve_prog_h2()
		{
			constexpr auto m = MT::id;
			constexpr auto n = U_block_program;
			constexpr auto j = T_block_program::max_index2(pos);
			constexpr auto i = pos + j;

			return U_opt_pack_Vs<m, n, c, i, j, Vs...>;
		}

		template<auto c, auto pos, auto... Vs>
		static constexpr auto U_prog_h2 = U_resolve_prog_h2<c, pos, Vs...>();

		template<auto... Vs, typename T_specific, auto pos, auto... Is>
		static constexpr auto h2(nik_avpcr(T_specific*), nik_avpcr(auto_pack<pos, Is...>*))
		{
			constexpr auto c = T_specific::template lines<Is...>;

			return U_resolve_prog_h2<c, pos, Vs...>();
		}
	};

	using CBB0 = CallBuild0<MP::block>;

// linear:

	template<key_type... filler>
	struct CallBuild<MT::cache_level_0, MP::linear, filler...>
	{
		template<auto c, auto... Vs>
		static constexpr auto U_prog_h2 = U_opt_pack_Vs
		<
			MT::id,
			U_linear_program,
			c,
			T_linear_program::initial_i,
			T_linear_program::initial_j,
			Vs...
		>;

		template<auto... Vs, typename T_specific, auto... Is>
		static constexpr auto h2(nik_avpcr(T_specific*), nik_avpcr(auto_pack<Is...>*))
		{
			constexpr auto c = T_specific::template lines<Is...>;

			return U_prog_h2<c, Vs...>;
		}
	};

	using CBL0 = CallBuild0<MP::linear>;

// recursive:

	template<key_type... filler>
	struct CallBuild<MT::cache_level_0, MP::recursive, filler...>
	{
		template<auto c, auto... Vs>
		static constexpr auto U_prog_h2 = U_opt_pack_Vs
		<
			MT::id,
			U_recursive_program,
			c,
			T_recursive_program::initial_i,
			T_recursive_program::initial_j,
			Vs...
		>;

		template<auto... Vs, typename T_specific, auto... Is>
		static constexpr auto h2(nik_avpcr(T_specific*), nik_avpcr(auto_pack<Is...>*))
		{
			constexpr auto c = T_specific::template lines<Is...>;

			return U_prog_h2<c, Vs...>;
		}
	};

	using CBR0 = CallBuild0<MP::recursive>;

/***********************************************************************************************************************/

// cache level 1:

	template<key_type... Keys> using CallBuild1 = CallBuild<MT::cache_level_1, Keys...>;

	//

	template<key_type... filler>
	struct CallBuild<MT::cache_level_1, filler...>
	{
	};

	using CB1 = CallBuild1<>;

/***********************************************************************************************************************/

// cache level 2:

	template<key_type... Keys> using CallBuild2 = CallBuild<MT::cache_level_2, Keys...>;

	//

	template<key_type... filler>
	struct CallBuild<MT::cache_level_2, filler...>
	{
	};

	using CB2 = CallBuild2<>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// call get:

	template<key_type...> struct CallGet;

/***********************************************************************************************************************/

// cache level 0:

	template<key_type... filler>
	struct CallGet<MT::cache_level_0, filler...>
	{
	};

	using CallGet0 = CallGet<MT::cache_level_0>;

/***********************************************************************************************************************/

// cache level 1:

	template<key_type... filler>
	struct CallGet<MT::cache_level_1, filler...>
	{
	};

	using CallGet1 = CallGet<MT::cache_level_1>;

/***********************************************************************************************************************/

// cache level 2:

	template<key_type... filler>
	struct CallGet<MT::cache_level_2, filler...>
	{
	};

	using CallGet2 = CallGet<MT::cache_level_2>;

/***********************************************************************************************************************/

// cache level 3:

	template<key_type... filler>
	struct CallGet<MT::cache_level_3, filler...>
	{
	};

	using CallGet3 = CallGet<MT::cache_level_3>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// call make:

	template<key_type...> struct CallMake;

/***********************************************************************************************************************/

// cache level 0:

	template<key_type... filler>
	struct CallMake<MT::cache_level_0, filler...>
	{
		template<auto ins, auto h3, auto... Vs>
		static constexpr auto program()
		{
			constexpr auto handle	= ins[CI::handle_pos];
			constexpr auto prog	= CB0::template U_program<ins>;
			constexpr auto params	= CB0::template U_params<ins>;

			constexpr auto h2	= CallBuild0<handle>::template h2<ins, Vs...>(prog, params);

			return machination(MT::id, h2, h3);
		}
	};

	using CallMake0 = CallMake<MT::cache_level_0>;

/***********************************************************************************************************************/

// cache level 1:

	template<key_type... filler>
	struct CallMake<MT::cache_level_1, filler...>
	{
	//	template<auto ins, auto cVs, auto cAs, NIK_HEAP_AUTO_CARGS>
	//	static constexpr auto program(nik_vpcr(cHs)(auto_pack<NIK_HEAP_CARGS>*))
	//	{
	//		constexpr auto caller	= RetrieveHandle::template result<ins, cVs, cH0, cH4, cAs>();
	//		constexpr auto name	= RetrieveName::template result<ins, cVs, cH0, cH4, cAs>();
	//		constexpr auto pack	= RetrievePack::template result<ins, cVs, cH0, cH4, cAs>();
	//		constexpr auto params	= RetrieveParams::template result<ins, cVs, cH0, cH4, cAs>();

	//		constexpr auto h2	= Make::h2<ins>(caller, name, pack, params, cVs);
	//		constexpr auto h3	= Make::h3<ins>(cHs, cAs);

	//		return machination(MT::id, h2, h3);
	//	}
	};

	using CallMake1 = CallMake<MT::cache_level_1>;

/***********************************************************************************************************************/

// cache level 2:

	template<key_type... filler>
	struct CallMake<MT::cache_level_2, filler...>
	{
	};

	using CallMake2 = CallMake<MT::cache_level_2>;

/***********************************************************************************************************************/

// cache level 3:

	template<key_type... filler>
	struct CallMake<MT::cache_level_3, filler...>
	{
		// dispatch:

	//		template<auto ins, typename Heap0, typename Heap1>
	//		static constexpr auto program(Heap0 H0, Heap1 H1)
	//		{
	//			using Q			= Parameter<_zero>; // tmp
	//			constexpr auto size	= Q::template param_size<ins>;

	//			if constexpr (CI::is_optimal(size))
	//			{
	//				constexpr auto index_segment = Q::template index_segment<size>;

	//				return QD::template opt_program<Q, ins, index_segment>(H0, H1);
	//			}
	//			else
	//			{
	//				constexpr auto result = QD::find_from_h4<size>(H1);
	//				constexpr bool h4_has = result[_zero];

	//				if constexpr (h4_has)
	//				{
	//					constexpr auto pos = result[_one];

	//					return QD::template h4_program<Q, ins, pos>(H0, H1);
	//				}
	//				else return QD::template program<Q, ins, size>(H0, H1);
	//			}
	//		}

	//	// function:

	//		template<auto ins, auto H0, auto... Vs>
	//		static constexpr auto function()
	//		{
	//		//	constexpr auto caller_ins	= GC::template instrs<ins>();
	//		//	constexpr auto name_ins		= GN::template instrs<ins>();
	//		//	constexpr auto param_ins	= GP::template instrs<ins>();
	//		//	constexpr auto tail_ins		= GE::function_tail_instrs;

	//		//	return Build::lines(caller_ins, name_ins, param_ins, tail_ins);
	//			return 0;
	//		}
	};

	using CallMake3 = CallMake<MT::cache_level_3>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

