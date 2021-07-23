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

// dispatchers source:

	// nesting depth policy:

		// It is assumed each function nesting depth is chosen to be less than the compiler's nesting depth.
		// This is to say that in practice there should be small buffer of nesting depths/calls available.

		// Consequences: If d == 0 during a given machine call,

		// A) It is able to call the next machine. In turn the iterators will
		//    dispatch it to MN::pause which does not require any further depths.

		// B) It is able to call single depth functions within its scope.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interface:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// instructions:

/***********************************************************************************************************************/

	struct MachineInstr
	{
		using type						= index_type const*;

		static constexpr index_type size			= 0;
		static constexpr index_type name			= 1;
		static constexpr index_type note			= 2;
		static constexpr index_type pos				= 3;

		static constexpr index_type length (type i)		{ return i[size]; }
		static constexpr index_type last   (type i)		{ return i[length(i)]; }
		static constexpr index_type patch  (index_type pos)	{ return (pos < _eight) ? pos+1 : _zero; }
		static constexpr index_type linear (index_type n)	{ return (n < _eight) ? _zero : _two; }
	};

	using MI							= MachineInstr;
	using instr_type						= typename MI::type;

	struct CallInstr : public MI
	{
		static constexpr index_type name			= 3;

		// block:

		static constexpr index_type pos				= 4;

		// linear:

		static constexpr index_type note			= 4;
	};

	struct AsgnInstr : public MI
	{
		static constexpr index_type obj				= 4;
	};

	struct ApplInstr : public MI
	{
		static constexpr index_type op				= 4;
		static constexpr index_type arg				= 5;
		static constexpr index_type arg1			= 5;
		static constexpr index_type arg2			= 6;
	};

	struct PredInstr : public MI
	{
		static constexpr index_type pred			= 3;
		static constexpr index_type input			= 4;
		static constexpr index_type input1			= 4;
		static constexpr index_type input2			= 5;
	};

	struct NLInstr : public MI
	{
		static constexpr key_type appl				= 2;

		static constexpr key_type cond				= 2;
		static constexpr key_type appl1				= 3;
		static constexpr key_type appl2				= 4;
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	static constexpr instr_type instruction = array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// labels:

/***********************************************************************************************************************/

	struct MachineLabel
	{
		using type						= instr_type const*;

		static constexpr index_type size			= 0;
		static constexpr index_type first			= 1;
		static constexpr index_type second			= 2;

		static constexpr index_type length (type l)		{ return l[size][MI::size]; }
		static constexpr instr_type last   (type l)		{ return l[length(l)]; }
	};

	using ML							= MachineLabel;
	using label_type						= typename ML::type;

		// pack length is stored as the initial value.

	template<instr_type... Vs>
	static constexpr label_type label = array<instr_type, array<index_type, sizeof...(Vs)>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controllers:

/***********************************************************************************************************************/

	struct MachineContr
	{
		using type						= label_type const*;

		static constexpr index_type size			= 0;
		static constexpr index_type first			= 1;

		static constexpr index_type length   (type c)		{ return c[size][ML::size][MI::size]; }
		static constexpr label_type last     (type c)		{ return c[length(c)]; }
		static constexpr index_type reg_size (type c)		{ return ML::last(last(c))[MI::pos]; }
	};

	using MC							= MachineContr;
	using contr_type						= typename MC::type;

		// pack length is stored as the initial value.

	template<label_type... Vs>
	static constexpr contr_type controller = array
		<label_type, array<instr_type, array<index_type, sizeof...(Vs)>>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatchers:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

	template<key_type, key_type...> struct block_controller;

/***********************************************************************************************************************/

	struct BD
	{
		static constexpr index_type max_note(index_type n)
		{
			return	(n >= _2_9) ? 9 :
				(n >= _2_8) ? 8 :
				(n >= _2_7) ? 7 :
				(n >= _2_6) ? 6 :
				(n >= _2_5) ? 5 :
				(n >= _2_4) ? 4 :
				(n >= _2_3) ? 3 :
				(n >= _2_2) ? 2 :
				(n >= _2_1) ? 1 : 0 ;
		}

		static constexpr index_type max_index2(index_type n)
		{
			return	(n >= _2_9) ? _2_9 :
				(n >= _2_8) ? _2_8 :
				(n >= _2_7) ? _2_7 :
				(n >= _2_6) ? _2_6 :
				(n >= _2_5) ? _2_5 :
				(n >= _2_4) ? _2_4 :
				(n >= _2_3) ? _2_3 :
				(n >= _2_2) ? _2_2 :
				(n >= _2_1) ? _2_1 :
				(n >= _2_0) ? _2_0 : 0 ;
		}

	// iterators:

		// optimized to use a single instruction as the controller.

		static constexpr key_type next_name(instr_type c, depth_type d, index_type i, index_type j)
		{
			if (d == 0)	return MN::pause;	// assumes i >= j, next i := i - j
			else if (i > j)	return c[MI::name];	// implies next i > 0
			else 		return MI::last(c);	// otherwise next i == 0
		}

		static constexpr key_type next_note(instr_type c, depth_type d, index_type i, index_type j)
		{
			if (d == 0)	return _zero;
			else		return max_note(i - j);
		}

		static constexpr depth_type next_depth(depth_type d)
		{
			if (d > 0)	return d-1;
			else 		return d;
		}

		static constexpr index_type next_index1(instr_type c, depth_type d, index_type i, index_type j)
		{
			if (d == 0)	return i;
			else 		return i - j;
		}

		static constexpr index_type next_index2(instr_type c, depth_type d, index_type i, index_type j)
		{
			if (d == 0)	return j;
			else		return max_index2(i - j);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

	template<key_type, key_type...> struct linear_controller;

/***********************************************************************************************************************/

	struct LD
	{
	// block:

		static constexpr auto call_name(label_type l, index_type, index_type j)
			{ return l[j][CallInstr::name]; }

		static constexpr index_type call_pos(label_type l, index_type, index_type j)
			{ return l[j][CallInstr::pos]; }

	// linear:

		static constexpr index_type call_note(label_type l, index_type, index_type j)
			{ return l[j][CallInstr::note]; }

		static constexpr instr_type call_instr(label_type l, index_type, index_type j)
			{ return l[j]; }

	// iterators:

		// optimized to use a single label as the controller.

		static constexpr key_type next_name(label_type l, depth_type d, index_type, index_type j)
		{
			if (d == 0)	return MN::pause;
			else 		return l[j+1][MI::name];
		}

		static constexpr key_type next_note(label_type l, depth_type d, index_type, index_type j)
		{
			if (d == 0)	 return _zero;
			else		 return l[j+1][MI::note];
		}

		static constexpr depth_type next_depth(depth_type d)
		{
			if (d > 0)	return d-1;
			else 		return d;
		}

		static constexpr index_type next_index1(label_type, depth_type, index_type i, index_type)
		{
			return i;
		}

		static constexpr index_type next_index2(label_type, depth_type d, index_type, index_type j)
		{
			if (d == 0)	return j;
			else 		return j+1;
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register:

/***********************************************************************************************************************/

	// Initializers require (l = 0, m = k) -> first instruction.

	// modularizing assign, save, restore, is better design, but given
	// compile time performance constraints optimization is privileged.

/*
	struct RD
	{
	// reg size:

		static constexpr index_type reg_size (rc_type c, index_type, index_type)
			{ return RC::reg_size(c); }

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
			key_type name	= c[ni][nj][RA::name];
			key_type note	= c[ni][nj][RA::note];

			if (name == MN::go_to && note == MD::contr)	return c[ni][nj][RA::pos];
			else 						return ni;
		}

	// index2:

		static constexpr index_type next_index2(rc_type c, depth_type d, index_type i, index_type j)
		{
			if (d == 0) return j;

			index_type ni	= basic_next_index1(c, i, j);
			index_type nj	= basic_next_index2(c, i, j);
			key_type name	= c[ni][nj][RA::name];
			key_type note	= c[ni][nj][RA::note];

			if (name == MN::go_to && note == MD::contr)	return _one;
			else						return nj;
		}

	// name:

		static constexpr key_type next_name(rc_type c, depth_type d, index_type i, index_type j)
		{
			if (d == 0) return MN::pause;

			index_type ni = next_index1(c, d, i, j);
			index_type nj = next_index2(c, d, i, j);

			return c[ni][nj][RA::name];
		}

	// note:

		static constexpr key_type next_note(rc_type c, depth_type d, index_type i, index_type j)
		{
			if (d == 0) return _zero;

			index_type ni = next_index1(c, d, i, j);
			index_type nj = next_index2(c, d, i, j);

			return c[ni][nj][RA::note];
		}

	// depth:

		static constexpr depth_type next_depth(depth_type d)
		{
			if (d > 0)	return d-1;
			else 		return d;
		}
	};
*/

/***********************************************************************************************************************/

// predefined:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interposers:

private:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pass (zero):

	template<key_type... filler>
	struct machine<MN::pass, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, auto un, auto nc, auto ni, auto nj, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, void(*H2)(auto_pack<un, nc, ni, nj>*), Heaps... Hs)
		{
			using nn = T_type_U<un>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, Hs...);
		}
	};

/***********************************************************************************************************************/

// block:

	template<key_type... filler>
	struct machine<MN::block, _zero, filler...>
	{
		using nn = BD;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= block_controller<n::call_name(c, i, j)>::template result<>;
			constexpr auto pos	= n::call_pos(c, i, j);
			constexpr auto nj	= nn::max_index2(pos);
			constexpr auto ni	= pos + nj;

			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// linear (zero):

	template<key_type... filler>
	struct machine<MN::linear, _zero, filler...>
	{
		using nn			= LD;
		static constexpr auto ni	= _one;
		static constexpr auto nj	= _zero;

		template<key_type Name, key_type Note, instr_type I>
		static constexpr auto make_linear()
		{
			using c = linear_controller<Name>;

			if constexpr      (Note == 0) return c::template result<>;
			else if constexpr (Note == 1) return c::template result<I[5]>;
			else if constexpr (Note == 2) return c::template result<I[5], I[6]>;
			else if constexpr (Note == 3) return c::template result<I[5], I[6], I[7]>;
			else if constexpr (Note == 4) return c::template result<I[5], I[6], I[7], I[8]>;
			else if constexpr (Note == 5) return c::template result<I[5], I[6], I[7], I[8], I[9]>;
			else if constexpr (Note == 6) return c::template result<I[5], I[6], I[7], I[8], I[9], I[10]>;
			else                          return c::template result<I[5], I[6], I[7], I[8], I[9], I[10], I[11]>;
		}

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= make_linear
						<
							n::call_name(c, i, j),
							n::call_note(c, i, j),
							n::call_instr(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)
				(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// linear (one):

	template<key_type... filler>
	struct machine<MN::linear, _one, filler...>
	{
		using nn			= LD;
		static constexpr auto ni	= _one;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Is,
			auto instr, auto... Ws, auto... Vs, typename Heap1, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<instr, Ws...>*), Heap1 H1,
			void(*H2)(auto_pack<Vs...>*), Heaps... Hs
		)
		{
			constexpr auto nc = linear_controller<instr[CallInstr::name]>::template result<instr[Is]...>;

			return NIK_BEGIN_MACHINE(nn, nc, d, ni, nj)

				Vs...

			NIK_END_MACHINE(U_opt_pack_Vs<Ws...>, H1, Hs...);
		}
	};

/***********************************************************************************************************************/

// linear (two):

	template<key_type... filler>
	struct machine<MN::linear, _two, filler...>
	{
		using nn			= LD;
		static constexpr auto ni	= _one;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, typename Heap1, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heap1 H1, Heaps... Hs)
		{
			constexpr auto instr	= n::call_instr(c, i, j);
			constexpr auto note	= n::call_note(c, i, j);
			constexpr auto nc	= label
						<
							make_i_segment__insert_at_s_back<note>,
							instruction<MN::linear, _one> // optimization
						>;
			constexpr auto un	= U_type_T<n>;

			return machine
			<
				nn::next_name(nc, d, ni, nj),
				nn::next_note(nc, d, ni, nj)

			>::template result
			<
				nn, nc,

				nn::next_depth(d),
				nn::next_index1(nc, d, ni, nj),
				nn::next_index2(nc, d, ni, nj)

			>(U_opt_pack_Vs<instr, Ws...>, H1, U_opt_pack_Vs<Vs...>, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// call:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// trampolining:

/***********************************************************************************************************************/

// pair:

	template<typename StackCache, typename HeapCache>
	struct trampoline_pair
	{
		StackCache sc;
		HeapCache hc;

		constexpr trampoline_pair(const StackCache & _sc, const HeapCache & _hc) : sc(_sc), hc(_hc) { }
	};

	template<typename T>
	static constexpr bool is_trampoline_pair(T) { return false; }

	template<typename StackCache, typename HeapCache>
	static constexpr bool is_trampoline_pair(trampoline_pair<StackCache, HeapCache>) { return true; }

/***********************************************************************************************************************/

// trampoline:

	template<auto d, auto un, auto c, auto i, auto j, auto... Vs, auto... Hs>
	static constexpr auto machine_trampoline(void(*)(auto_pack<un, c, i, j, Vs...>*), void(*)(auto_pack<Hs...>*))
	{
		static_assert(bool(d), "machine trampolining nesting depth exceeded.");

		using n = T_type_U<un>;

		constexpr auto result = NIK_MACHINE(n, c, d, i, j)(Hs...);

		if constexpr (is_trampoline_pair(result))	return machine_trampoline<d-1>(result.sc, result.hc);
		else						return result;
	}

/***********************************************************************************************************************/

// start:

public:

	template<NIK_CONTR_PARAMS, auto... Vs, auto... Ws, auto... Xs>
	static constexpr auto start
	(
		void(*H0)(auto_pack<Ws...>*) = U_opt_pack_Vs<>,
		void(*H1)(auto_pack<Xs...>*) = U_opt_pack_Vs<>
	)
	{
		constexpr auto result = NIK_MACHINE(n, c, d, i, j)(U_opt_pack_Vs<Ws...>, U_opt_pack_Vs<Xs...>);

		if constexpr (is_trampoline_pair(result))	return machine_trampoline<d>(result.sc, result.hc);
		else						return result;
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

