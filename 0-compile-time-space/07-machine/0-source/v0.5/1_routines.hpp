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

// call:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specifications:

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
			{
				return (location == CL::instr);
			}

			constexpr bool is_cache_level_1(const bool is_cl0) const
			{
				return is_cl0 || MI::is_optimal(position);
			}
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
			{
				return (location == CL::instr);
			}

			constexpr bool is_cache_level_1(const bool is_cl0) const
			{
				return is_cl0 || MI::is_optimal(position); // assumes if loc == id then pos = 0.
			}
	};

	using NameSpec = CallSpecification<CS::name>;

/***********************************************************************************************************************/

// pack:

	template<key_type... filler>
	struct CallSpecification<CS::pack, filler...>
	{
		const key_type location;
		const index_type position;
		const index_type size;

		constexpr CallSpecification(ckey_type l, cindex_type p, cindex_type pt, cindex_type ps) :
			location(l), position(p), size(length(pt, ps)) { }

		// size:

			constexpr index_type length(cindex_type param_trait, cindex_type param_size)
			{
				if      (param_size == 0)        return 0;
				else if (param_trait == CT::all) return param_size - 1;
				else                             return param_size >> 1;
			}

		// predicates:

			constexpr bool is_cache_level_0() const
			{
				return (location == CL::id) && MI::is_optimal(size);
			}

			constexpr bool is_cache_level_1(const bool is_opt) const
			{
				return is_opt || MI::is_optimal(position);
			}
	};

	using PackSpec = CallSpecification<CS::pack>;

/***********************************************************************************************************************/

// param:

	template<key_type Trait, key_type... filler>
	struct CallSpecification<CS::param, Trait, filler...>
	{
		const key_type trait; // temporary (may be unneeded)
		const index_type *parameters;

		constexpr CallSpecification(cindex_type *ps) : trait(Trait), parameters(ps) { }

		// matchers:

			template<ckey_type V> static constexpr bool is_value  (ckey_type v) { return (v == V); }
			template<ckey_type V> static constexpr bool not_value (ckey_type v) { return (v != V); }

		// all locs match:

			template<auto match>
			constexpr bool all_locs_match(cindex_type pack_size) const
			{
				if (pack_size == 0) return true;
				else
				{
					if constexpr (Trait == CT::all) return match(*parameters);
					else
					{
						const index_type *end	= parameters + (pack_size << 1);
						bool result		= true;

						for (cindex_type *k = parameters; result && k < end; k += 2)
							result = match(*k);

						return result;
					}
				}
			}

		// predicates:

			constexpr bool no_locs_equal_id(cindex_type pack_size) const
			{
				return all_locs_match<not_value<CL::id>>(pack_size);
			}

			constexpr bool all_locs_equal_h0(cindex_type pack_size) const
			{
				return all_locs_match<is_value<CL::h0>>(pack_size);
			}

			// is cache 0:

				constexpr bool is_cache_level_0(cindex_type pack_size) const
				{
					if (!MI::is_optimal(pack_size)) return false;
					else
					{
						if constexpr (Trait != CT::all) return false;
						else                            return (*parameters == CL::instr);
					}
				}

			// is cache 1:

				constexpr bool is_all_cache_level_1(cindex_type pack_size) const
				{
					bool result = true;

					for (cindex_type *k = parameters + 1; result && k < parameters + pack_size; ++k)
						result = MI::is_optimal(*k);

					return result;
				}

				constexpr bool is_id_cache_level_1(cindex_type pack_size) const
				{
					cindex_type *k	= parameters;
					bool result	= true;

					for (index_type j = 0; result && j < pack_size; ++j, ++k)
						result = (*k == CL::instr) || MI::is_optimal(*++k);

					return result;
				}

				constexpr bool is_cache_level_1(const bool is_opt, cindex_type pack_size) const
				{
					if (is_opt) return true;

					// at least one of the following is false:

						//   pack_size <  eight
						//       Trait == all
						// *parameters == instr

					else if (!MI::is_optimal(pack_size)) return false;

					if constexpr (Trait == CT::all) // implies *parameters != instr
					{
						return is_all_cache_level_1(pack_size);
					}
					else
					{
						if (pack_size == 0) return true;
						else return is_id_cache_level_1(pack_size);
					}
				}
	};

	template<key_type Trait>
	using ParamSpec = CallSpecification<CS::param, Trait>;

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

		) :	handle_spec(h), name_spec(n), pack_spec(p), param_spec(ps) { }

		// matchers:

			template<typename... Ts>
			static constexpr bool all(Ts... vs) { return (... && vs); }

			template<typename T, typename... Ts>
			static constexpr bool all_equal(T v, Ts... vs) { return all((v == vs)...); }

		// assertions:

			constexpr bool assert_handle () const { return handle_spec.location != CL::id; }
			constexpr bool assert_name   () const { return true; }
			constexpr bool assert_pack   () const { return pack_spec.location != CL::instr; }
			constexpr bool assert_trait  () const { return param_spec.trait == CL::id || param_spec.trait == CT::all; }
			constexpr bool assert_param  () const { return param_spec.no_locs_equal_id(pack_spec.size); }

					// should assert that if trait == all, then a single loc must follow.

		// pack size:

			constexpr auto pack_size() const { return pack_spec.size; }

		// predicates:

			constexpr bool all_nonparam_locs_equal_h0() const
			{
				return all_equal(CL::h0, handle_spec.location, name_spec.location, pack_spec.location);
			}

		// note:

			constexpr auto cache_level_1_note(const bool h_is_cl0,
					const bool n_is_cl0, const bool p_is_cl0, const bool ps_is_cl0) const
			{
				const bool  h_is_cl1		= handle_spec.is_cache_level_1(h_is_cl0);
				const bool  n_is_cl1		=   name_spec.is_cache_level_1(n_is_cl0);
				const bool  p_is_cl1		=   pack_spec.is_cache_level_1(p_is_cl0);
				const bool ps_is_cl1		=  param_spec.is_cache_level_1(ps_is_cl0, pack_spec.size);

				const bool is_cache_level_1	= all(h_is_cl1, n_is_cl1, p_is_cl1, ps_is_cl1);

				return is_cache_level_1 ? MT::cache_level_1 : MT::cache_level_2;
			}

			constexpr auto cache_level_0_note() const
			{
				const bool  h_is_cl0		= handle_spec.is_cache_level_0();
				const bool  n_is_cl0		=   name_spec.is_cache_level_0();
				const bool  p_is_cl0		=   pack_spec.is_cache_level_0();
				const bool ps_is_cl0		=  param_spec.is_cache_level_0(pack_spec.size);

				const bool is_cache_level_0	= all(h_is_cl0, n_is_cl0, p_is_cl0, ps_is_cl0);

				if (is_cache_level_0) return MT::cache_level_0;
				else                  return cache_level_1_note(h_is_cl0, n_is_cl0, p_is_cl0, ps_is_cl0);
			}

			constexpr auto is_identity_note() const
			{
				return all_nonparam_locs_equal_h0() && param_spec.all_locs_equal_h0(pack_spec.size);
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
		constexpr auto Pack		= PackSpec(PackLoc, PackPos, ParamTrait, sizeof...(Params));

		constexpr auto ParamArray	= array<index_type, Params...>;
		constexpr auto Param		= ParamSpec<ParamTrait>(ParamArray);

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
			PackLoc, PackPos, Spec.pack_size(),
			ParamTrait, Params...
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
/***********************************************************************************************************************/

