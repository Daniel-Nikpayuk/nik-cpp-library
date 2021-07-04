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

// near linear machines source:

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

// size of:

	template<index_type... filler>
	struct machine<MN::size_of, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return BEGIN_NIK_MACHINE(n, c, d, i, j)

				sizeof...(Vs), Vs...

			END_NIK_MACHINE(Hs...);
		}
	};

/***********************************************************************************************************************/

// clear:

	template<index_type... filler>
	struct machine<MN::clear, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return machine
			<
				n::next_name(c, d, i, j),
				n::next_note(c, d, i, j)

			>::template result
			<
				n, c,

				n::next_depth(d),
				n::next_index1(c, d, i, j),
				n::next_index2(c, d, i, j)

			>(Hs...);
		}
	};

/***********************************************************************************************************************/

// map:

	template<index_type... filler>
	struct machine<MN::map, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto op, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<op>*), Heaps... Hs)
		{
			return BEGIN_NIK_MACHINE(n, c, d, i, j)

				op(Vs)...

			END_NIK_MACHINE(H0, Hs...);
		}
	};

/***********************************************************************************************************************/

// plot:

	template<index_type... filler>
	struct machine<MN::plot, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto uact, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<uact>*), Heaps... Hs)
		{
			return BEGIN_NIK_MACHINE(n, c, d, i, j)

				T_type_U<uact>::template result<Vs>...

			END_NIK_MACHINE(H0, Hs...);
		}
	};

/***********************************************************************************************************************/

// align:

	template<index_type... filler>
	struct machine<MN::align, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto utype, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<utype>*), Heaps... Hs)
		{
			constexpr T_type_U<utype> array[] = { Vs... };

			return BEGIN_NIK_MACHINE(n, c, d, i, j)

				array

			END_NIK_MACHINE(H0, Hs...);
		}
	};

/***********************************************************************************************************************/

// lift:

	template<index_type... filler>
	struct machine<MN::lift, _zero, filler...>
	{
		using nn			= DD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc = controller_module::template call_contr<n::appl(c, i, j)>;
			constexpr auto un = U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// stem:

	template<index_type... filler>
	struct machine<MN::stem, _zero, filler...>
	{
		using nn			= DD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= controller_module::template skip_contr
						<
							n::cond(c, i, j), n::appl2(c, i, j), n::appl1(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// costem:

	template<index_type... filler>
	struct machine<MN::costem, _zero, filler...>
	{
		using nn			= DD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= controller_module::template skip_contr
						<
							n::cond(c, i, j), n::appl1(c, i, j), n::appl2(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// cycle (optimized):

	// refactored into the controller iterator.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatch:

/***********************************************************************************************************************/

public:

	struct ND
	{
	// applications:

		static constexpr auto appl(nc_type c, index_type i, index_type) { return c[i][NP::appl]; }

		static constexpr auto cond(nc_type c, index_type i, index_type) { return c[i][NP::cond]; }
		static constexpr auto appl1(nc_type c, index_type i, index_type) { return c[i][NP::appl1]; }
		static constexpr auto appl2(nc_type c, index_type i, index_type) { return c[i][NP::appl2]; }

	// iterators:

		// name:

			static constexpr index_type next_name(nc_type c, depth_type d, index_type i, index_type)
			{
				if (d == 0) return MN::pause;

				index_type name = c[i+1][NP::name][NA::name];

				if (name != MN::cycle)	return name;
				else			return c[_one][NP::name][NA::name];
			}

		// note:

			static constexpr index_type (*next_note)(nc_type, depth_type, index_type, index_type) =
				MD::template default_next_note<nc_type, depth_type, index_type, index_type>;

		// depth:

			static constexpr depth_type (*next_depth)(depth_type) =
				MD::template default_next_depth<depth_type>;
		// index1:

			static constexpr index_type next_index1(nc_type c, depth_type d, index_type i, index_type)
			{
				if (d == 0) return i;

				index_type name = c[i+1][NP::name][NA::name];

				if (name != MN::cycle)	return i+1;
				else			return _one;
			}

		// index2:

			static constexpr index_type (*next_index2)(nc_type, depth_type, index_type, index_type) =
				MD::template default_next_index2<nc_type, depth_type, index_type, index_type>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

