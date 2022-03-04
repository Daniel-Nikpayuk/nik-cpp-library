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

/*
		// closed:

			template<auto ins, auto... Vs, auto prog, auto... Ws>
			static constexpr auto h2(nik_avpcr(auto_pack<prog, Ws...>*))
			{
				constexpr auto params	= U_opt_pack_Vs<Ws...>;
				constexpr auto base	= T_type_U<prog>::base;

				return Resolve<base>::template h2<ins, Vs...>(prog, params);
			}

		// open:

			template<auto caller, auto name>
			static constexpr auto build(key_type) { return U_type_T<program<caller, name>>; }

			template<auto caller, auto name, template<auto...> class B>
			static constexpr auto build(nik_avpcr(auto_template_pack<B>*)) { return U_type_T<B<name>>; }

			template<auto ins, auto... Vs, auto caller, auto name, auto... ps>
			static constexpr auto h2(nik_avpcr(auto_pack<caller, name, ps...>*))
			{
				constexpr auto prog	= build<caller, name>(caller);
				constexpr auto params	= U_opt_pack_Vs<ps...>;
				constexpr auto base	= T_type_U<prog>::base;

				return Resolve<base>::template h2<ins, Vs...>(prog, params);
			}
*/

/***********************************************************************************************************************/
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
/***********************************************************************************************************************/

// call dispatch:

	template<key_type, key_type...> struct CallDispatch;

	template<key_type... Keys> using CallGet	= CallDispatch < CR::get   , Keys... >;
	template<key_type... Keys> using CallBuild	= CallDispatch < CR::build , Keys... >;
	template<key_type... Keys> using CallMake	= CallDispatch < CR::make  , Keys... >;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// cache level 0:

/***********************************************************************************************************************/

// get:

	template<key_type... filler>
	struct CallDispatch<CR::get, MT::cache_level_0, filler...>
	{
		// handle, name, size:

			template<auto ins> static constexpr auto handle	= ins[CI::handle_pos];
			template<auto ins> static constexpr auto name	= ins[CI::name_pos];
			template<auto ins> static constexpr auto size	= ins[CI::param_size];

		// index segment:

			template<auto size> static constexpr auto index_segment = Fast<size>::U_index_segment;
	};

	using CG0 = CallGet<MT::cache_level_0>;

/***********************************************************************************************************************/

// build:

	template<key_type... Keys> using CallBuild0 = CallBuild<MT::cache_level_0, Keys...>;

	//

	template<key_type... filler>
	struct CallDispatch<CR::build, MT::cache_level_0, filler...>
	{
		// routine:

			template<auto handle, auto name>
			static constexpr auto routine = U_type_T<program<handle, name>>;

		// params:

			template<auto ins, auto ind_seg>
			static constexpr auto params = PE::template from_array<ins, _zero>(ind_seg);

		// h2:

			template<auto... Vs, typename T_routine, typename Params>
			static constexpr auto h2(nik_avpcr(T_routine*), Params params)
				{ return CallBuild0<T_routine::base>::template h2<T_routine, Vs...>(params); }
	};

	using CB0 = CallBuild0<>;

// block:

	template<key_type... filler>
	struct CallDispatch<CR::build, MT::cache_level_0, MP::block, filler...>
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

		template<typename T_routine, auto... Vs, auto pos, auto... Is>
		static constexpr auto h2(nik_avpcr(auto_pack<pos, Is...>*))
		{
			constexpr auto c = T_routine::template lines<Is...>;

			return U_resolve_prog_h2<c, pos, Vs...>();
		}
	};

	using CBB0 = CallBuild0<MP::block>;

// linear:

	template<key_type... filler>
	struct CallDispatch<CR::build, MT::cache_level_0, MP::linear, filler...>
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

		template<typename T_routine, auto... Vs, auto... Is>
		static constexpr auto h2(nik_avpcr(auto_pack<Is...>*))
		{
			constexpr auto c = T_routine::template lines<Is...>;

			return U_prog_h2<c, Vs...>;
		}
	};

	using CBL0 = CallBuild0<MP::linear>;

// recursive:

	template<key_type... filler>
	struct CallDispatch<CR::build, MT::cache_level_0, MP::recursive, filler...>
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

		template<typename T_routine, auto... Vs, auto... Is>
		static constexpr auto h2(nik_avpcr(auto_pack<Is...>*))
		{
			constexpr auto c = T_routine::template lines<Is...>;

			return U_prog_h2<c, Vs...>;
		}
	};

	using CBR0 = CallBuild0<MP::recursive>;

/***********************************************************************************************************************/

// make:

	template<key_type... filler>
	struct CallDispatch<CR::make, MT::cache_level_0, filler...>
	{
		// routine:

			template<auto ins>
			static constexpr auto routine()
			{
				constexpr auto handle	= CG0::template handle<ins>;
				constexpr auto name	= CG0::template name<ins>;

				return CB0::template routine<handle, name>;
			}

		// params:

			template<instr_type ins>
			static constexpr auto params()
			{
				constexpr auto size	= CG0::template size<ins>;
				constexpr auto ind_seg	= CG0::template index_segment<size>;

				return CB0::template params<ins, ind_seg>;
			}

		// program:

			template<auto ins, auto h3, auto... Vs>
			static constexpr auto program()
			{
				constexpr auto r  = routine<ins>();
				constexpr auto p  = params<ins>();

				constexpr auto h2 = CB0::template h2<Vs...>(r, p);

				return machination(MT::id, h2, h3);
			}
	};

	using CM0 = CallMake<MT::cache_level_0>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// cache level 1:

/***********************************************************************************************************************/

// get:

	template<key_type... filler>
	struct CallDispatch<CR::get, MT::cache_level_1, filler...>
	{
		// generic:

			template<auto cl, auto loc, auto pos, auto cVs, auto cH0, auto cH4, auto cAs>
			static constexpr auto generic()
			{
				if constexpr (cl == _zero) return pos;
				else
				{
					constexpr auto pos0	= (loc == CL::regs) ? _zero :
								  (loc == CL::h0  ) ? _one  :
								  (loc == CL::h4  ) ? _two  : _three ;
					constexpr auto mem	= Fast<pos0>::template at<cVs, cH0, cH4, cAs>();

					return PE::template fast_at<pos>(mem);
				}
			}

		// handle:

			template<auto ins, auto cVs, auto cH0, auto cH4, auto cAs>
			static constexpr auto handle = generic
			<
				ins[CI::handle_cl], ins[CI::handle_loc], ins[CI::handle_pos], cVs, cH0, cH4, cAs
			>();

		// name:

			template<auto ins, auto cVs, auto cH0, auto cH4, auto cAs>
			static constexpr auto name = generic
			<
				ins[CI::name_cl], ins[CI::name_loc], ins[CI::name_pos], cVs, cH0, cH4, cAs
			>();

		// pack:

		//	template<auto ins, auto cVs, auto cH0, auto cH4, auto cAs>
		//	static constexpr auto pack()
		//	{
		//		constexpr auto cl	= ins[CI::pack_cl];
		//		constexpr auto loc	= ins[CI::pack_loc];
		//		constexpr auto pos	= ins[CI::pack_pos];
		//		constexpr auto value	= generic<cl, loc, pos, cVs, cH0, cH4, cAs>();

		//		if constexpr (cl == _zero) return Fast<value>::U_index_segment;
		//		else
		//		{
		//			constexpr auto key = ins[CI::pack_key];

		//			return CB1::template pack<key>(value);
		//		}
		//	}

		// param:

			template<auto ins, auto cVs, auto cH0, auto cH4, auto cAs, typename Pack>
			static constexpr auto param(Pack pack)
			{
				constexpr auto cl	= ins[CI::param_cl];
				constexpr auto offset	= CI::offset;

				if constexpr (cl == _zero) return PE::template from_array<ins, offset>(pack);
				else
				{
					constexpr auto size	= ins[CI::param_size];
					constexpr auto l_offset	= offset + size;
					constexpr auto p_offset	= l_offset + size;

					constexpr auto Cls	= PE::template from_array<ins,   offset>(pack);
					constexpr auto Locs	= PE::template from_array<ins, l_offset>(pack);
					constexpr auto Poses	= PE::template from_array<ins, p_offset>(pack);

					return 0;//CB1::template param<cVs, cH0, cH4, cAs>(Cls, Locs, Poses);
				}
			}
	};

	using CG1 = CallGet<MT::cache_level_1>;

/***********************************************************************************************************************/

// build:

	template<key_type... filler>
	struct CallDispatch<CR::build, MT::cache_level_1, filler...>
	{
		// pack:

		//	template<auto key, typename T>
		//	static constexpr auto pack(const T & p) { return p; }

		//	template<auto key, template<auto...> class B>
		//	static constexpr auto pack(nik_avpcr(auto_template_pack<B>*)) { return B<key>::result; }

		// routine:

			template<auto key, template<auto...> class B>
			static constexpr auto routine(nik_avpcr(auto_template_pack<B>*))
				{ return U_type_T<B<key>>; }

		// params:

			template<auto cVs, auto cH0, auto cH4, auto cAs, auto... cls, auto... locs, auto... poses>
			static constexpr auto params
			(
				nik_avpcr(auto_pack<cls...>*),
				nik_avpcr(auto_pack<locs...>*),
				nik_avpcr(auto_pack<poses...>*)
			)
			{
				return U_opt_pack_Vs
				<
					CG1::template generic<cls, locs, poses, cVs, cH0, cH4, cAs>()...
				>;
			}

		// h2:

			template<typename T_routine, auto... Is, auto... Vs>
			static constexpr auto h2
			(
				nik_avpcr(T_routine*),
				nik_avpcr(auto_pack<Is...>*),
				nik_avpcr(auto_pack<Vs...>*)
			)
			{
				return 0;
			}

		// h3:

		//	constexpr auto h3	= CallBuild1::template h3(cHs, cAs);

			template<NIK_HEAP_AUTO_CARGS, auto... As>
			static constexpr auto h3
			(
				nik_avpcr(auto_pack<NIK_HEAP_CARGS>*),
				nik_avpcr(auto_pack<As...>*)
			)
			{
				return 0;
			}
	};

	using CB1 = CallBuild<MT::cache_level_1>;

/***********************************************************************************************************************/

// make:

	template<key_type... filler>
	struct CallDispatch<CR::make, MT::cache_level_1, filler...>
	{
		// routine:

			template<auto ins, auto cVs, auto cH0, auto cH4, auto cAs>
			static constexpr auto routine()
			{
				constexpr auto handle	= CG1::template handle<ins, cVs, cH0, cH4, cAs>;
				constexpr auto name_loc	= ins[CI::name_loc];

				if constexpr (name_loc == CL::id) return handle;
				else
				{
					constexpr auto name = CG1::template name<ins, cVs, cH0, cH4, cAs>;

					return CB1::template routine<name>(handle);
				}
			}

		// params:

			template<auto ins, auto cVs, auto cH0, auto cH4, auto cAs>
			static constexpr auto params()
			{
				constexpr auto param_cl = ins[CI::param_cl];

				if constexpr (param_cl == _zero) return CM0::template params<ins>();
				else
				{
				//	constexpr auto pack	= CG1::template pack<ins, cVs, cH0, cH4, cAs>();
				//	constexpr auto cls	= CG1::template cache_levels<ins>(pack);
				//	constexpr auto locs	= CG1::template locations<ins>(pack);
				//	constexpr auto poses	= CG1::template positions<ins>(pack);

				//	return CB1::template params<ins, cVs, cH0, cH4, cAs>(cls, locs, poses);
					return 0;
				}
			}

		// program:

			template<auto ins, auto cVs, auto cAs, NIK_HEAP_AUTO_CARGS>
			static constexpr auto program(nik_vpcr(cHs)(auto_pack<NIK_HEAP_CARGS>*))
			{
				constexpr auto r	= routine<ins, cVs, cH0, cH4, cAs>();
				constexpr auto p	= params<ins, cVs, cH0, cH4, cAs>();

				constexpr auto h2	= CB1::template h2(r, p, cVs);
				constexpr auto h3	= CB1::template h3(cHs, cAs);

				return machination(MT::id, h2, h3);
			}
	};

	using CM1 = CallMake<MT::cache_level_1>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// cache level 2:

/***********************************************************************************************************************/

// get:

	template<key_type... filler>
	struct CallDispatch<CR::get, MT::cache_level_2, filler...>
	{
	};

	using CG2 = CallGet<MT::cache_level_2>;

/***********************************************************************************************************************/

// build:

	template<key_type... filler>
	struct CallDispatch<CR::build, MT::cache_level_2, filler...>
	{
		// routine:

		// params:

		// base:
	};

	using CB2 = CallBuild<MT::cache_level_2>;

/***********************************************************************************************************************/

// make:

	template<key_type... filler>
	struct CallDispatch<CR::make, MT::cache_level_2, filler...>
	{
	};

	using CM2 = CallMake<MT::cache_level_2>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// cache level 3:

/***********************************************************************************************************************/

// get:

	template<key_type... filler>
	struct CallDispatch<CR::get, MT::cache_level_3, filler...>
	{
	};

	using CG3 = CallGet<MT::cache_level_3>;

/***********************************************************************************************************************/

// build:

/***********************************************************************************************************************/

// make:

	template<key_type... filler>
	struct CallDispatch<CR::make, MT::cache_level_3, filler...>
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
	//		//	constexpr auto handle_ins	= GC::template instrs<ins>();
	//		//	constexpr auto name_ins		= GN::template instrs<ins>();
	//		//	constexpr auto param_ins	= GP::template instrs<ins>();
	//		//	constexpr auto tail_ins		= GE::function_tail_instrs;

	//		//	return Build::lines(handle_ins, name_ins, param_ins, tail_ins);
	//			return 0;
	//		}
	};

	using CM3 = CallMake<MT::cache_level_3>;

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
		static constexpr key_type handle	=  0;
		static constexpr key_type name		=  1;
		static constexpr key_type routine	=  2;

		static constexpr key_type pack		=  3;
		static constexpr key_type key		=  4;
		static constexpr key_type param		=  5;
		static constexpr key_type params	=  6;

		static constexpr key_type program	=  7;

		static constexpr key_type closed	=  8;
		static constexpr key_type open		=  9;

		// name shape:

			static constexpr auto shape(ckey_type name_location)
				{ return (name_location == CL::id) ? closed : open; }

		// matchers:

			template<key_type V> static constexpr bool is_value  (ckey_type v) { return (v == V); }
			template<key_type V> static constexpr bool not_value (ckey_type v) { return (v != V); }

		// cache level:

			static constexpr key_type cache_level(ckey_type location, cindex_type position)
			{
				if      (location == CL::instr)    return _zero;
				else if (MI::is_optimal(position)) return _one;
				else                               return _two;
			}

		// key max:

			static constexpr auto key_max(ckey_type x, ckey_type y) { return (x > y) ? x : y; }

		// array max:

			static constexpr auto array_max(ckey_type *begin, ckey_type *end)
			{
				key_type current_max = _zero;

				for (ckey_type *k = begin; k < end; ++k)
					if (*k > current_max) current_max = *k;

				return current_max;
			}

		// total cache level:

			template<auto... CLs>
			static constexpr auto total_cache_level(nik_avpcr(auto_pack<CLs...>*))
			{
				ckey_type cl_array[]	= { CLs... };
				cindex_type cl_size	= sizeof...(CLs);

				return array_max(cl_array, cl_array + cl_size);
			}

		// resolve params:

			template<auto ParamCL, typename ParamPack>
			static constexpr auto resolve_params(ParamPack params)
			{
				if constexpr (ParamCL == _zero) return U_null_Vs;
				else                            return params;
			}
	};

	using CS = CallSpecification<>;

/***********************************************************************************************************************/

// handle:

	template<key_type... filler>
	struct CallSpecification<CS::handle, filler...>
	{
		ckey_type cache_level;
		ckey_type location;
		cindex_type position;

		constexpr CallSpecification(ckey_type l, cindex_type p) :

			cache_level{CS::cache_level(l, p)},
			location{l}, position{p} { }
	};

	using HandleSpec = CallSpecification<CS::handle>;

/***********************************************************************************************************************/

// name:

	template<key_type... filler>
	struct CallSpecification<CS::name, filler...>
	{
		ckey_type cache_level;
		ckey_type location;
		cindex_type position;

		constexpr CallSpecification(ckey_type l, cindex_type p) :

			cache_level{CS::cache_level(l, p)},
			location{l}, position{p} { }
	};

	using NameSpec = CallSpecification<CS::name>;

/***********************************************************************************************************************/

// routine:

	template<key_type... filler>
	struct CallSpecification<CS::routine, filler...>
	{
		ckey_type cache_level;
		const HandleSpec handle;
		const NameSpec name;

		constexpr CallSpecification(const HandleSpec & h, const NameSpec & n) :

			cache_level{CS::key_max(h.cache_level, n.cache_level)},
			handle{h}, name{n} { }
	};

	using RoutineSpec = CallSpecification<CS::routine>;

/***********************************************************************************************************************/

// pack:

	template<key_type... filler>
	struct CallSpecification<CS::pack, filler...>
	{
		ckey_type cache_level;
		ckey_type location;
		cindex_type position;

		constexpr CallSpecification(ckey_type l, cindex_type p, cindex_type s) :

			cache_level{cl(l, p, s)},
			location{l}, position{p} { }

		// cache level:

			static constexpr auto cl(ckey_type l, cindex_type p, cindex_type s)
			{
				if (l == CL::id) return MI::is_optimal(s) ? _zero : _three;
				else             return MI::is_optimal(p) ? _one  : _two;
			}
	};

	using PackSpec = CallSpecification<CS::pack>;

/***********************************************************************************************************************/

// key:

	template<key_type... filler>
	struct CallSpecification<CS::key, filler...>
	{
		ckey_type cache_level;
		ckey_type location;
		cindex_type position;

		constexpr CallSpecification(ckey_type l, cindex_type p) :

			cache_level{cl(l, p)},
			location{l}, position{p} { }

		// cache level:

			static constexpr key_type cl(ckey_type l, cindex_type p)
			{
				if   (l == CL::id) return _zero;
				else               return CS::cache_level(l, p);
			}
	};

	using KeySpec = CallSpecification<CS::key>;

/***********************************************************************************************************************/

// param (all):

	template<key_type... filler>
	struct CallSpecification<CS::param, CT::all, filler...>
	{
		ckey_type total_cache_level;
		ckey_type cache_level;

		ckey_type trait;
		ckey_type *location;
		cindex_type *position;
		cindex_type size;

		constexpr CallSpecification(ckey_type *l, cindex_type *p, cindex_type s) :
			cache_level{}, total_cache_level{},
			location{l}, position{p}, size{s}
		{
		}

		// predicates:

		//	constexpr bool no_locs_equal_id() const
		//		{ return CS::template not_value<CL::id>(*opt_locs); }

		// cache levels:

			template<auto Loc0, auto... Locs, auto... Poses>
			static constexpr auto cache_levels
			(
				nik_avpcr(auto_pack<Loc0, Locs...>*),
				nik_avpcr(auto_pack<Poses...>*)
			)
			{
				if constexpr (Loc0 == CL::instr) return U_opt_pack_Vs<_zero>;
				else return U_opt_pack_Vs<(MI::is_optimal(Poses) ? _one : _two)...>;
			}
	};

/***********************************************************************************************************************/

// param (id):

	template<key_type... filler>
	struct CallSpecification<CS::param, CT::id, filler...>
	{
		ckey_type total_cache_level;
		ckey_type cache_level;

		ckey_type trait;
		ckey_type *location;
		cindex_type *position;
		cindex_type size;

		constexpr CallSpecification(ckey_type *l, cindex_type *p, cindex_type s) :
			cache_level{}, total_cache_level{},
			location{l}, position{p}, size{s} { }

		// subparams:

		//	template<key_type offset, index_type... Params, auto... Is>
		//	static constexpr auto subparams(nik_avpcr(auto_pack<Is...>*))
		//	{
		//		if constexpr (sizeof...(Params) == 0) return U_null_Vs;
		//		else
		//		{
		//			constexpr index_type arr[] = { Params... };

		//			return U_opt_pack_Vs<arr[(Is << 1) + offset]...>;
		//		}
		//	}

		// locations:

		//	template<index_type... Params, typename T>
		//	static constexpr auto locations(T v) { return subparams<_zero, Params...>(v); }

		// positions:

		//	template<index_type... Params, typename T>
		//	static constexpr auto positions(T v) { return subparams<_one, Params...>(v); }

		// all locs match:

		//	template<auto match>
		//	constexpr bool all_locs_match() const
		//	{
		//		if (size == 0) return true;
		//		else
		//		{
		//			bool result = true;

		//			for (ckey_type *k = locs; result && k < locs + size; ++k)
		//				result = match(*k);

		//			return result;
		//		}
		//	}

		// predicates:

		//	constexpr bool no_locs_equal_id() const
		//		{ return all_locs_match<CS::template not_value<CL::id>>(); }

		// cache levels:

			template<auto... Locs, auto... Poses>
			static constexpr auto cache_levels
			(
				nik_avpcr(auto_pack<Locs...>*),
				nik_avpcr(auto_pack<Poses...>*)

			) { return U_opt_pack_Vs<CS::cache_level(Locs, Poses)...>; }
	};

	template<key_type Trait>
	using ParamSpec = CallSpecification<CS::param, Trait>;

/***********************************************************************************************************************/

// params:

	template<key_type Trait, key_type... filler>
	struct CallSpecification<CS::params, Trait, filler...>
	{
	};

	template<key_type Trait>
	using ParamsSpec = CallSpecification<CS::params, Trait>;

/***********************************************************************************************************************/

// program:

	template<key_type Trait, key_type... filler>
	struct CallSpecification<CS::program, Trait, filler...>
	{
		ckey_type rtn_policy;

		const RoutineSpec routine_spec;
		const ParamsSpec<Trait> params_spec;

		constexpr CallSpecification
		(
			ckey_type rp,
			const RoutineSpec & r, const ParamsSpec<Trait> & p

		) : rtn_policy{rp}, routine_spec{r}, params_spec{p} { }

		// assertions:

		//	constexpr bool assert_handle () const { return handle_spec.location != CL::id; }
		//	constexpr bool assert_name   () const { return true; }
		//	constexpr bool assert_pack   () const { return pack_spec.location != CL::instr; }
		//	constexpr bool assert_trait  () const { return Trait == CL::id || Trait == CT::all; }
		//	constexpr bool assert_param  () const { return param_spec.no_locs_equal_id(); }

		// note:

			constexpr auto note(ckey_type param_cl) const
			{
			//	const auto handle_cl	= handle_spec.cache_level();
			//	const auto name_cl	= name_spec.cache_level();
			//	const auto pack_cl	= pack_spec.cache_level(param_spec.length());

			//	ckey_type cl_array[]	= { handle_cl, name_cl, pack_cl, param_cl };
			//	const auto total_cl	= CS::array_max(cl_array, cl_array + _four);

			//	if      (total_cl == 0) return MT::cache_level_0;
			//	else if (total_cl == 1) return MT::cache_level_1;
			//	else if (total_cl == 2) return MT::cache_level_2;
			//	else                    return MT::cache_level_3;

				return 0;
			}
	};

	template<key_type Trait>
	using ProgramSpec = CallSpecification<CS::id, Trait>;

/***********************************************************************************************************************/

// routine:

	template
	<
		key_type HandleLoc, index_type HandlePos,
		key_type NameLoc, index_type NamePos
	>
	static constexpr auto routine()
	{
		constexpr bool assert_handle_loc_not_id = (HandleLoc != CL::id);
		static_assert( assert_handle_loc_not_id , "[call instruction] handle location cannot be id.");

		constexpr auto Handle	= HandleSpec{HandleLoc, HandlePos};
		constexpr auto Name	= NameSpec{NameLoc, NamePos};

		return RoutineSpec(Handle, Name);
	};

/***********************************************************************************************************************/

// params:

	template
	<
		key_type PackLoc, index_type PackPos,
		key_type KeyLoc, index_type KeyPos,
		key_type ParamTrait
	>
	static constexpr auto params
	(
		cindex_type locs_size, ckey_type *param_locs,
		cindex_type poses_size, cindex_type *param_poses
	)
	{
		// assertions:

		constexpr bool assert_pack_loc_not_instr = (PackLoc != CL::instr);
		static_assert( assert_pack_loc_not_instr , "[call instruction] pack location cannot be instr.");

		constexpr bool assert_param_trait_is_id_or_all = (ParamTrait == CT::id || ParamTrait == CT::all);
		static_assert( assert_param_trait_is_id_or_all , "[call instruction] param trait must be id or all.");

		constexpr bool assert_param_trait_id = (ParamTrait != CT::id) || (locs_size == poses_size);
		static_assert( assert_param_trait_id , "[call instruction] param trait all must have exactly one location.");

		constexpr bool assert_param_trait_all_locs = (ParamTrait != CT::all) || (locs_size == 1);
		static_assert( assert_param_trait_all_locs , "[call instruction] param trait all must have exactly one location.");

		constexpr bool assert_param_trait_all_poses = (ParamTrait != CT::all) || (poses_size > 0);
		static_assert( assert_param_trait_all_poses , "[call instruction] param trait all must have at least one position");

	//	constexpr bool assert_param_locs_not_id = CS::template not_value<CL::id>(param_locs);
	//	static_assert( assert_param_locs_not_id , "[call instruction] param locations cannot be id.");

		//

		constexpr auto Pack	= PackSpec(PackLoc, PackPos, poses_size);
		constexpr auto Key	= KeySpec(KeyLoc, KeyPos);
		constexpr auto Param	= ParamSpec<ParamTrait>(param_locs, param_poses, poses_size);

		return 0;//ParamsSpec<ParamTrait>(Pack, Key, Param);
	};

/***********************************************************************************************************************/

// call program:

	template<key_type RtnPolicy, auto RoutineSpecCallable, auto ParamsSpecCallable, auto... Is>
	static constexpr instr_type call_program(nik_avpcr(auto_pack<Is...>*))
	{
		// assert RtnPolicy is one of the expected values.

		constexpr auto routine_spec	= RoutineSpecCallable();
		constexpr auto params_spec	= ParamsSpecCallable();
		constexpr auto program_spec	= ProgramSpec<params_spec.trait>{RtnPolicy, routine_spec, params_spec};

		// assert sizeof...(Is) == Spec.poses_size();

		return instruction
		<
			// base:

				MN::call,
				program_spec.note,
				RtnPolicy,

			// handle:

				routine_spec.handle_spec.cache_level,
				routine_spec.handle_spec.location,
				routine_spec.handle_spec.position,

			// name:

				routine_spec.name_spec.cache_level,
				routine_spec.name_spec.location,
				routine_spec.name_spec.position,

			// pack:

				params_spec.pack_spec.cache_level,
				params_spec.pack_spec.location,
				params_spec.pack_spec.position,

			// key:

				params_spec.key_spec.cache_level,
				params_spec.key_spec.location,
				params_spec.key_spec.position,

			// param:

				params_spec.param_spec.cache_level,
				params_spec.param_spec.size,
				params_spec.param_spec.cache_level[Is]...,
				params_spec.param_spec.location[Is]...,
				params_spec.param_spec.position[Is]...
		>;
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
/***********************************************************************************************************************/

