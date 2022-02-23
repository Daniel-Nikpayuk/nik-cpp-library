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
	};

	using CS = CallSpecification<>;

/***********************************************************************************************************************/

// handle:

	template<key_type... filler>
	struct CallSpecification<CS::handle, filler...>
	{
		const key_type location;
		const index_type position;

		constexpr CallSpecification(ckey_type l, cindex_type p) : location(l), position(p) { }

		// predicates:

			constexpr bool is_cache_level_0() const
				{ return (location == CL::instr); }

			constexpr bool is_cache_level_1(const bool is_cl0) const
				{ return is_cl0 || MI::is_optimal(position); }
	};

	using HandleSpec = CallSpecification<CS::handle>;

/***********************************************************************************************************************/

// name:

	template<key_type... filler>
	struct CallSpecification<CS::name, filler...>
	{
		static constexpr key_type closed	=  0;
		static constexpr key_type open		=  1;

		const key_type location;
		const index_type position;

		constexpr CallSpecification(ckey_type l, cindex_type p) : location(l), position(p) { }

		// predicates:

			constexpr bool is_cache_level_0() const
				{ return (location == CL::instr); }

			constexpr bool is_cache_level_1(const bool is_cl0) const // assumes if loc == id then pos = 0.
				{ return is_cl0 || MI::is_optimal(position); }
	};

	using NameSpec = CallSpecification<CS::name>;

/***********************************************************************************************************************/

// pack:

	template<key_type... filler>
	struct CallSpecification<CS::pack, filler...>
	{
		const key_type location;
		const index_type position;

		constexpr CallSpecification(ckey_type l, cindex_type p) : location(l), position(p) { }

		// predicates:

			constexpr bool is_cache_level_0() const
				{ return (location == CL::id); }

			constexpr bool is_cache_level_1(const bool is_opt) const
				{ return is_opt || MI::is_optimal(position); }

			constexpr bool is_cache_level_2(cindex_type size) const
			{
				if (location == CL::id) return MI::is_optimal(size);
				else                    return MI::is_optimal(position);
			}
	};

	using PackSpec = CallSpecification<CS::pack>;

/***********************************************************************************************************************/

// param:

	template<key_type Trait, key_type... filler>
	struct CallSpecification<CS::param, Trait, filler...>
	{
		const index_type size;
		const index_type *params;

		constexpr CallSpecification(cindex_type s, cindex_type *p) : size(length(s)), params(p) { }

		// matchers:

			template<ckey_type V> static constexpr bool is_value  (ckey_type v) { return (v == V); }
			template<ckey_type V> static constexpr bool not_value (ckey_type v) { return (v != V); }

		// all locs match:

			template<auto match>
			constexpr bool all_locs_match() const
			{
				if (size == 0) return true;
				else
				{
					if constexpr (Trait == CT::all) return match(*params);
					else
					{
						const index_type *end	= params + (size << 1);
						bool result		= true;

						for (cindex_type *k = params; result && k < end; k += 2)
							result = match(*k);

						return result;
					}
				}
			}

		// size:

			constexpr index_type length(cindex_type param_size)
			{
				if (param_size == 0)  return 0;
				else
				{
					if constexpr (Trait == CT::all) return param_size - 1;
					else                            return param_size >> 1;
				}
			}

		// predicates:

			constexpr bool no_locs_equal_id() const
				{ return all_locs_match<not_value<CL::id>>(); }

			constexpr bool all_locs_equal_h0() const
				{ return all_locs_match<is_value<CL::h0>>(); }

			// is cache level 0:

				constexpr bool is_cache_level_0() const
				{
					if (!MI::is_optimal(size)) return false;
					else
					{
						if constexpr (Trait != CT::all) return false;
						else                            return (*params == CL::instr);
					}
				}

			// is cache level 1:

				constexpr bool is_all_cache_level_1() const
				{
					bool result = true;

					for (cindex_type *k = params + 1; result && k < params + size; ++k)
						result = MI::is_optimal(*k);

					return result;
				}

				constexpr bool is_id_cache_level_1() const
				{
					cindex_type *k	= params;
					bool result	= true;

					for (index_type j = 0; result && j < size; ++j, ++k)
						result = (*k == CL::instr) || MI::is_optimal(*++k);

					return result;
				}

				constexpr bool is_cache_level_1(const bool is_opt) const
				{
					if (is_opt) return true;
					else if (!MI::is_optimal(size)) return false;

					if constexpr (Trait == CT::all) return is_all_cache_level_1();
					else
					{
						if (size == 0) return true;
						else return is_id_cache_level_1();
					}
				}
	};

	template<key_type Trait> using ParamSpec = CallSpecification<CS::param, Trait>;

/***********************************************************************************************************************/

// id:

	template<key_type Trait, key_type... filler>
	struct CallSpecification<CS::id, Trait, filler...>
	{
		const HandleSpec handle_spec;
		const NameSpec name_spec;
		const PackSpec pack_spec;
		const ParamSpec<Trait> param_spec;

		constexpr CallSpecification
		(
			const HandleSpec & h, const NameSpec & n, const PackSpec & p, const ParamSpec<Trait> & ps

		) : handle_spec(h), name_spec(n), pack_spec(p), param_spec(ps) { }

		// matchers:

			template<typename... Ts>
			static constexpr bool all(Ts... vs) { return (... && vs); }

			template<typename T, typename... Ts>
			static constexpr bool all_equal(T v, Ts... vs) { return all((v == vs)...); }

		// assertions:

			constexpr bool assert_handle () const { return handle_spec.location != CL::id; }
			constexpr bool assert_name   () const { return true; }
			constexpr bool assert_pack   () const { return pack_spec.location != CL::instr; }
			constexpr bool assert_trait  () const { return Trait == CL::id || Trait == CT::all; }
			constexpr bool assert_param  () const { return param_spec.no_locs_equal_id(); }

					// should assert that if trait == all, then a single loc must follow.

		// pack size:

			constexpr auto param_size() const { return param_spec.size; }

		// predicates:

			constexpr bool all_nonparam_locs_equal_h0() const
			{
				return all_equal(CL::h0, handle_spec.location, name_spec.location, pack_spec.location);
			}

		// note:

			constexpr auto cache_level_2_note() const
			{
				const bool is_cache_level_2 = pack_spec.is_cache_level_2(param_spec.size);

				return is_cache_level_2 ? MT::cache_level_2 : MT::cache_level_3;
			}

			constexpr auto cache_level_1_note(const bool h_is_cl0,
					const bool n_is_cl0, const bool p_is_cl0, const bool r_is_cl0) const
			{
				const bool h_is_cl1		= handle_spec.is_cache_level_1(h_is_cl0);
				const bool n_is_cl1		=   name_spec.is_cache_level_1(n_is_cl0);
				const bool p_is_cl1		=   pack_spec.is_cache_level_1(p_is_cl0);
				const bool r_is_cl1		=  param_spec.is_cache_level_1(r_is_cl0);

				const bool is_cache_level_1	= all(h_is_cl1, n_is_cl1, p_is_cl1, r_is_cl1);

				if (is_cache_level_1) return MT::cache_level_1;
				else                  return cache_level_2_note();
			}

			constexpr auto cache_level_0_note() const
			{
				const bool h_is_cl0		= handle_spec.is_cache_level_0();
				const bool n_is_cl0		=   name_spec.is_cache_level_0();
				const bool p_is_cl0		=   pack_spec.is_cache_level_0();
				const bool r_is_cl0		=  param_spec.is_cache_level_0();

				const bool is_cache_level_0	= all(h_is_cl0, n_is_cl0, p_is_cl0, r_is_cl0);

				if (is_cache_level_0) return MT::cache_level_0;
				else                  return cache_level_1_note(h_is_cl0, n_is_cl0, p_is_cl0, r_is_cl0);
			}

			constexpr auto is_identity_note() const
			{
				return all_nonparam_locs_equal_h0() && param_spec.all_locs_equal_h0();
			}

			constexpr auto note() const
			{
				if (is_identity_note()) return MT::id;
				else                    return cache_level_0_note();
			}
	};

	template<key_type Trait>
	using IdSpec = CallSpecification<CS::id, Trait>;

/***********************************************************************************************************************/

// dispatch:

	template
	<
		key_type RtnPolicy,
		key_type HandleLoc, index_type HandlePos,
		key_type NameLoc, index_type NamePos,
		key_type PackLoc, index_type PackPos,
		key_type ParamTrait, index_type... Params
	>
	static constexpr instr_type dispatch_call_program()
	{
		constexpr auto Handle		= HandleSpec(HandleLoc, HandlePos);
		constexpr auto Name		= NameSpec(NameLoc, NamePos);
		constexpr auto Pack		= PackSpec(PackLoc, PackPos);

		constexpr auto ParamArray	= array<index_type, Params...>;
		constexpr auto Param		= ParamSpec<ParamTrait>(sizeof...(Params), ParamArray);

		constexpr auto Spec		= IdSpec<ParamTrait>(Handle, Name, Pack, Param);

		static_assert(Spec.assert_handle (), "[call instruction] caller location cannot be id."  );
		static_assert(Spec.assert_pack   (), "[call instruction] pack location cannot be instr." );
		static_assert(Spec.assert_trait  (), "[call instruction] param trait must be id or all." );
		static_assert(Spec.assert_param  (), "[call instruction] param locations cannot be id."  );

		return instruction
		<
			MN::call, Spec.note(),
			RtnPolicy,
			HandleLoc, HandlePos,
			NameLoc, NamePos,
			PackLoc, PackPos,
			ParamTrait, Spec.param_size(), Params...
		>;
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// call instructions:

/***********************************************************************************************************************/

public:

// program:

	template
	<
		key_type RtnPolicy,
		key_type HandleLoc, index_type HandlePos,
		key_type NameLoc, index_type NamePos,
		key_type PackLoc, index_type PackPos,
		key_type ParamTrait, index_type... Params
	>
	static constexpr instr_type call_program = dispatch_call_program
	<
		RtnPolicy,
		HandleLoc, HandlePos,
		NameLoc, NamePos,
		PackLoc, PackPos,
		ParamTrait, Params...
	>();

// interface:

	template<key_type RtnPolicy, index_type Handle, index_type Name, index_type... Params>
	static constexpr instr_type call_local_program = call_program
	<
		RtnPolicy,
		CL::h0, Handle,
		CL::h0, Name,
		CT::all, CL::h0, Params...
	>;

	template<key_type RtnPolicy, index_type Handle, index_type Name, index_type... Params>
	static constexpr instr_type call_builtin_program = call_program
	<
		RtnPolicy,
		CL::instr, Handle,
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

// test spec:

	template<key_type RtnPolicy = CP::load>
	static constexpr instr_type test_spec = call_program
	<
		RtnPolicy,
		CL::h0, _zero,
		CL::instr, _five,
		CL::id, _zero,
		CT::all, CL::instr, 0, 1, 2, 5, 4, 3
	>;

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

	template<key_type...>
	struct CallBuild
	{
		// program:

			template<instr_type ins>
			static constexpr auto U_program = U_type_T<program<ins[CI::handle_pos], ins[CI::name_pos]>>;

		// params:

			template<instr_type ins>
			static constexpr auto index_segment()
			{
				constexpr auto trait	= ins[CI::param_trait];
				constexpr auto size	= ins[CI::param_size];

				if constexpr (trait == CT::all) return Fast<size>::U_index_segment;
				else                            return Fast<size>::U_even_index_segment;
			}

			template<instr_type ins>
			static constexpr auto U_params = PE::template map_array<ins, CI::pos_offset>(index_segment<ins>());
	};

	using CB0 = CallBuild<>;

/***********************************************************************************************************************/

// block:

	template<key_type... filler>
	struct CallBuild<MP::block, filler...>
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

	using CBB = CallBuild<MP::block>;

/***********************************************************************************************************************/

// linear:

	template<key_type... filler>
	struct CallBuild<MP::linear, filler...>
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

	using CBL = CallBuild<MP::linear>;

/***********************************************************************************************************************/

// recursive:

	template<key_type... filler>
	struct CallBuild<MP::recursive, filler...>
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

	using CBR = CallBuild<MP::recursive>;

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

			constexpr auto h2	= CallBuild<handle>::template h2<ins, Vs...>(prog, params);

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

