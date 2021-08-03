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
		static constexpr bool is_opt (index_type n)		{ return (n < _eight); }
	};

	using MI							= MachineInstr;
	using instr_type						= typename MI::type;

	struct CallInstr : public MI
	{
		// The subnote value tells us how many of the leftside parameters
		// are direct values rather than register locations.

		static constexpr index_type subname			= 3;
		static constexpr index_type subnote			= 4;
		static constexpr index_type offset			= 5;

		static constexpr index_type subsize  (type i)		{ return i[size] - subnote; }
		static constexpr index_type subright (type i)		{ return offset; }

		static constexpr key_type patchname(key_type m, index_type n)	{ return is_opt(n) ? m : MN::call; }
		static constexpr key_type patchnote(key_type m, index_type n)	{ return is_opt(n) ? CT::fast : m; }

		template<template<key_type, key_type...> class Space, instr_type I>
		static constexpr auto opt_make_controller()
		{
			using s			= Space<I[subname]>;
			constexpr auto i	= subright(I);
			constexpr auto n	= subsize(I);

			if constexpr      (n == 0) return s::template result<>;
			else if constexpr (n == 1) return s::template result<I[i]>;
			else if constexpr (n == 2) return s::template result<I[i], I[i+1]>;
			else if constexpr (n == 3) return s::template result<I[i], I[i+1], I[i+2]>;
			else if constexpr (n == 4) return s::template result<I[i], I[i+1], I[i+2], I[i+3]>;
			else if constexpr (n == 5) return s::template result<I[i], I[i+1], I[i+2], I[i+3], I[i+4]>;
			else if constexpr (n == 6) return s::template result<I[i], I[i+1], I[i+2], I[i+3], I[i+4], I[i+5]>;
			else return s::template result<I[i], I[i+1], I[i+2], I[i+3], I[i+4], I[i+5], I[i+6]>;
		}
	};

	using CI = CallInstr;

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

	struct LD
	{
		static constexpr auto i = _one;
		static constexpr auto j = _zero;

	// block:

		static constexpr auto subname(label_type l, index_type, index_type j)
			{ return l[j][CI::subname]; }

		static constexpr index_type subpos(label_type l, index_type, index_type j)
			{ return l[j][CI::offset]; }

	// linear:

		static constexpr index_type subnote(label_type l, index_type, index_type j)
			{ return l[j][CI::subnote]; }

		static constexpr instr_type subinstr(label_type l, index_type, index_type j)
			{ return l[j]; }

	// interposers:

		static constexpr index_type val(label_type l, index_type, index_type j)
			{ return l[j][MI::pos]; }

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

// control:

	struct CD
	{
		static constexpr auto i = _one;
		static constexpr auto j = _zero;

	// block:

		static constexpr auto subname(contr_type c, index_type i, index_type j)
			{ return c[i][j][CI::subname]; }

		static constexpr index_type subpos(contr_type c, index_type i, index_type j)
			{ return c[i][j][CI::offset]; }

	// linear:

		static constexpr index_type subnote(contr_type c, index_type i, index_type j)
			{ return c[i][j][CI::subnote]; }

		static constexpr instr_type subinstr(contr_type c, index_type i, index_type j)
			{ return c[i][j]; }

	// interposers:

		static constexpr index_type val(contr_type c, index_type i, index_type j)
			{ return c[i][j][MI::pos]; }

	// iterators:

	// depth:

		static constexpr depth_type next_depth(depth_type d)
		{
			if (d > 0)	return d-1;
			else 		return d;
		}

	// basic indices:

		static constexpr index_type basic_next_index1(contr_type c, index_type i, index_type j)
		{
			return i + bool{j == ML::length(c[i])};	// j == last : return i+1.
								// j != last : return i.
		}

		static constexpr index_type basic_next_index2(contr_type c, index_type i, index_type j)
		{
			return (j == ML::length(c[i])) ? _one : j+1;	// j == last : return one.
									// j != last : return j+1.
		}

	// index1:

		static constexpr index_type next_index1(contr_type c, depth_type d, index_type i, index_type j)
		{
			if (d == 0) return i;

			index_type ni = basic_next_index1(c, i, j);
			index_type nj = basic_next_index2(c, i, j);
			key_type name = c[ni][nj][MI::name];

			if (name == MN::linear)
			{
				key_type subname = c[ni][nj][CI::subname];

				if (subname == LN::go_to_label) return c[ni][nj][CI::offset];
			}

			return ni;
		}

	// index2:

		static constexpr index_type next_index2(contr_type c, depth_type d, index_type i, index_type j)
		{
			if (d == 0) return j;

			index_type ni = basic_next_index1(c, i, j);
			index_type nj = basic_next_index2(c, i, j);
			key_type name = c[ni][nj][CI::name];

			if (name == MN::linear)
			{
				key_type subname = c[ni][nj][CI::subname];

				if (subname == LN::go_to_label) return _one;
			}

			return nj;
		}

	// name:

		static constexpr key_type next_name(contr_type c, depth_type d, index_type i, index_type j)
		{
			if (d == 0) return MN::pause;

			index_type ni = next_index1(c, d, i, j);
			index_type nj = next_index2(c, d, i, j);

			return c[ni][nj][MI::name];
		}

	// note:

		static constexpr key_type next_note(contr_type c, depth_type d, index_type i, index_type j)
		{
			if (d == 0) return _zero;

			index_type ni = next_index1(c, d, i, j);
			index_type nj = next_index2(c, d, i, j);

			return c[ni][nj][MI::note];
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interposers:

private:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pass:

/***********************************************************************************************************************/

// recall:

	template<key_type... filler>
	struct machine<MN::pass, PT::recall, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2,
			auto un, auto nc, auto ni, auto nj, typename... Heaps
		>
		static constexpr auto result
		(
			Heap0 H0, Heap1 H1, Heap2 H2,
			void(*H3)(auto_pack<un, nc, ni, nj>*), Heaps... Hs
		)
		{
			using nn = T_type_U<un>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(H0, H1, H2, Hs...);
		}
	};

/***********************************************************************************************************************/

// reindex:

	template<key_type... filler>
	struct machine<MN::pass, PT::reindex, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto pos, auto... Ws, typename Heap1, typename Heap2,
			auto un, auto nc, auto ni, auto nj, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<pos, Ws...>*), Heap1 H1, Heap2 H2,
			void(*H3)(auto_pack<un, nc, ni, nj>*), Heaps... Hs
		)
		{
			using nn = T_type_U<un>;

			return NIK_MACHINE(nn, nc, d, pos, nn::j)(U_opt_pack_Vs<Ws...>, H1, H2, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

/***********************************************************************************************************************/

	template<key_type... filler>
	struct machine<MN::block, _zero, filler...>
	{
		using nn = BD;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heap2 H2, Heaps... Hs)
		{
			constexpr auto nc	= block_space<n::subname(c, i, j)>::template result<>;
			constexpr auto pos	= n::subpos(c, i, j);
			constexpr auto nj	= nn::max_index2(pos);
			constexpr auto ni	= pos + nj;
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(H0, H1, H2, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

/***********************************************************************************************************************/

// fast:

	template<key_type... filler>
	struct machine<MN::linear, CT::fast, filler...>
	{
		using nn = LD;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heap2 H2, Heaps... Hs)
		{
			constexpr auto instr	= n::subinstr(c, i, j);
			constexpr auto nc	= CI::template opt_make_controller<linear_space, instr>();
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, nn::i, nn::j)(H0, H1, H2, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// scalable (call helper):

	template<key_type... filler>
	struct machine<MN::linear, CT::scalable, filler...>
	{
		using nn = LD;

		template
		<
			NIK_CONTR_PARAMS, auto... Is,
			auto instr, auto... Ws, typename Heap1, typename Heap2, auto... Vs, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<instr, Ws...>*), Heap1 H1, Heap2 H2, void(*H3)(auto_pack<Vs...>*), Heaps... Hs
		)
		{
			using ls		= linear_space<instr[CI::subname]>;
			constexpr auto shift	= CI::subright(instr);
			constexpr auto nc	= ls::template result<instr[Is+shift]...>;

			return NIK_BEGIN_MACHINE(nn, nc, d, nn::i, nn::j),

				Vs...

			NIK_END_MACHINE(U_opt_pack_Vs<Ws...>, H1, H2, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// control:

/***********************************************************************************************************************/

// fast:

	template<key_type... filler>
	struct machine<MN::control, CT::fast, filler...>
	{
		using nn = CD;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heap2 H2, Heaps... Hs)
		{
			constexpr auto instr	= n::subinstr(c, i, j);
			constexpr auto nc	= CI::template opt_make_controller<control_space, instr>();
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, nn::i, nn::j)(H0, H1, H2, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// scalable (call helper):

	template<key_type... filler>
	struct machine<MN::control, CT::scalable, filler...>
	{
		using nn = CD;

		template
		<
			NIK_CONTR_PARAMS, auto... Is,
			auto instr, auto... Ws, typename Heap1, typename Heap2, auto... Vs, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<instr, Ws...>*), Heap1 H1, Heap2 H2, void(*H3)(auto_pack<Vs...>*), Heaps... Hs
		)
		{
			using cs		= control_space<instr[CI::subname]>;
			constexpr auto shift	= CI::subright(instr);
			constexpr auto nc	= cs::template result<instr[Is+shift]...>;

			return NIK_BEGIN_MACHINE(nn, nc, d, nn::i, nn::j),

				Vs...

			NIK_END_MACHINE(U_opt_pack_Vs<Ws...>, H1, H2, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// user:

/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// call:

/***********************************************************************************************************************/

	template<key_type Note, key_type... filler>
	struct machine<MN::call, Note, filler...>
	{
		using nn = LD;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, typename Heap1, typename Heap2, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heap1 H1, Heap2 H2, Heaps... Hs)
		{
			constexpr auto instr	= n::subinstr(c, i, j);
			constexpr auto subsize	= CI::subsize(instr);
			constexpr auto nc	= label
						<
							make_r_segment__insert_at_s_back<subsize>,
							instruction<Note, CT::scalable> // optimization
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_BEGIN_MACHINE(nn, nc, d, nn::i, nn::j)

			NIK_END_MACHINE
			(
				U_opt_pack_Vs<instr, Ws...>, H1, H2,
				U_opt_pack_Vs<Vs...>, U_opt_pack_Vs<un, c, i, j>, Hs...
			);
		}
	};

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

// recurse:

	template<key_type... filler>
	struct machine<MN::recurse__insert_at_h0_front, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, typename Heap1, typename Heap2,
			auto un, auto nc, auto ni, auto nj, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<Ws...>*), Heap1 H1, Heap2 H2,
			void(*H3)(auto_pack<un, nc, ni, nj>*), Heaps... Hs
		)
		{
			using nn		= T_type_U<un>;
			constexpr auto val	= NIK_MACHINE(nn, nc, d, nn::i, nn::j)
							(U_opt_pack_Vs<>, U_opt_pack_Vs<>, U_opt_pack_Vs<>);
			constexpr auto is_br	= is_trampoline_pair(val);

			if constexpr (is_br)

				return NIK_MACHINE(n, c, d, i, j)
					(U_opt_pack_Vs<is_br, Ws...>, H1, H2, val.sc, val.hc, H3, Hs...);
			else
				return NIK_MACHINE(n, c, d, i, j)
					(U_opt_pack_Vs<is_br, val, Ws...>, H1, H2, H3, Hs...);
		}
	};

/***********************************************************************************************************************/

// trampoline:

	template<key_type... filler>
	struct machine<MN::trampoline__insert_at_h0_front, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, typename Heap1, typename Heap2,
			auto un, auto nc, auto ni, auto nj, auto... Xs, auto... Is, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<Ws...>*), Heap1 H1, Heap2 H2,
			void(*H3)(auto_pack<un, nc, ni, nj, Xs...>*),	// H3: stack cache
			void(*H4)(auto_pack<Is...>*), Heaps... Hs	// H4: heap cache
		)
		{
			using nn		= T_type_U<un>;
			constexpr auto val	= NIK_BEGIN_MACHINE(nn, nc, d, ni, nj), Xs... NIK_END_MACHINE(Is...);
			constexpr auto is_br	= is_trampoline_pair(val);

			if constexpr (is_br)

				return NIK_MACHINE(n, c, d, i, j)
					(U_opt_pack_Vs<is_br, Ws...>, H1, H2, val.sc, val.hc, Hs...);
			else
				return NIK_MACHINE(n, c, d, i, j)
					(U_opt_pack_Vs<is_br, val, Ws...>, H1, H2, Hs...);
		}
	};

/***********************************************************************************************************************/

// trampoline:

	template<auto d, auto un, auto c, auto i, auto j, auto... Vs, auto... Hs>
	static constexpr auto machine_trampoline(void(*)(auto_pack<un, c, i, j, Vs...>*), void(*)(auto_pack<Hs...>*))
	{
		static_assert(bool(d), "machine trampolining nesting depth exceeded.");

		using n			= T_type_U<un>;
		constexpr auto result	= NIK_MACHINE(n, c, d, i, j)(Hs...);

		if constexpr (is_trampoline_pair(result)) return machine_trampoline<d-1>(result.sc, result.hc);
		else                                      return result;
	}

/***********************************************************************************************************************/

// start:

public:

	template<typename n, auto c, auto d, auto... Vs, auto... Ws, auto... Xs, auto... Ys>
	static constexpr auto start
	(
		void(*H0)(auto_pack<Ws...>*) = U_opt_pack_Vs<>,
		void(*H1)(auto_pack<Xs...>*) = U_opt_pack_Vs<>,
		void(*H2)(auto_pack<Ys...>*) = U_opt_pack_Vs<>
	)
	{
		constexpr auto result = NIK_MACHINE(n, c, d, n::i, n::j)
					(U_opt_pack_Vs<Ws...>, U_opt_pack_Vs<Xs...>, U_opt_pack_Vs<Ys...>);

		if constexpr (is_trampoline_pair(result)) return machine_trampoline<d>(result.sc, result.hc);
		else                                      return result;
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

