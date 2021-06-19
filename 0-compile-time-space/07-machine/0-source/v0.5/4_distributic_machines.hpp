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

// distributic machines:

private:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomics:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers:

/***********************************************************************************************************************/

// erase:

	template<index_type... filler>
	struct machine<MN::erase, _zero, filler...>
	{
		using nn			= PD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= controller_module::template erase_contr // single call
						<
							n::pos(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// insert:

	template<index_type... filler>
	struct machine<MN::insert, _zero, filler...>
	{
		using nn			= PD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= controller_module::template insert_contr // single call(s)
						<
							n::pos(c, i, j), n::obj(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// replace:

	template<index_type... filler>
	struct machine<MN::replace, _zero, filler...>
	{
		using nn			= PD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= controller_module::template replace_contr // single call(s)
						<
							n::pos(c, i, j), n::obj(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// unary apply:

	template<index_type... filler>
	struct machine<MN::apply, MA::unary, filler...>
	{
		using nn			= PD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= controller_module::template apply1_replace_contr // single call(s)
						<
							n::pos(c, i, j), n::op(c, i, j), n::arg(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// binary apply:

	template<index_type... filler>
	struct machine<MN::apply, MA::binary, filler...>
	{
		using nn			= PD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= controller_module::template apply2_replace_contr // single call(s)
						<
							n::pos(c, i, j), n::op(c, i, j),
							n::arg1(c, i, j), n::arg2(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// unary compel:

	template<index_type... filler>
	struct machine<MN::compel, MA::unary, filler...>
	{
		using nn			= PD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= controller_module::template compel1_replace_contr // single call(s)
						<
							n::pos(c, i, j), n::op(c, i, j), n::arg(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// binary compel:

	template<index_type... filler>
	struct machine<MN::compel, MA::binary, filler...>
	{
		using nn			= PD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= controller_module::template compel2_replace_contr // single call(s)
						<
							n::pos(c, i, j), n::op(c, i, j),
							n::arg1(c, i, j), n::arg2(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// unary test:

	template<index_type... filler>
	struct machine<MN::test, MA::unary, filler...>
	{
		using nn			= PD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= controller_module::template test1_replace_contr // single call(s)
						<
							n::pred(c, i, j), n::input(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// binary test:

	template<index_type... filler>
	struct machine<MN::test, MA::binary, filler...>
	{
		using nn			= PD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= controller_module::template test2_replace_contr // single call(s)
						<
							n::pred(c, i, j),
							n::input1(c, i, j), n::input2(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// unary check:

	template<index_type... filler>
	struct machine<MN::check, MA::unary, filler...>
	{
		using nn			= PD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= controller_module::template check1_replace_contr // single call(s)
						<
							n::pred(c, i, j), n::input(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// binary check:

	template<index_type... filler>
	struct machine<MN::check, MA::binary, filler...>
	{
		using nn			= PD;
		static constexpr auto ni	= _zero;
		static constexpr auto nj	= _zero;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(NIK_FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= controller_module::template check2_replace_contr // single call(s)
						<
							n::pred(c, i, j),
							n::input1(c, i, j), n::input2(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_MACHINE(nn, nc, d, ni, nj)(NIK_FIXED_HEAP_ARGS, U_opt_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// unary skip:

	template<index_type... filler>
	struct machine<MN::skip, MA::unary, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			bool is_skip, auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<is_skip, Ws...>*), Heaps... Hs)
		{
			// To accurately get the next indices, the depth cannot be zero.

			constexpr auto i1	= is_skip ? n::next_index1(c, _one, i, j) : i;
			constexpr auto j1	= is_skip ? n::next_index2(c, _one, i, j) : j;

			return NIK_MACHINE(n, c, d, i1, j1)(U_opt_pack_Vs<Ws...>, Hs...);
		}
	};

/***********************************************************************************************************************/

// binary skip:

	template<index_type... filler>
	struct machine<MN::skip, MA::binary, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			bool is_skip, auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<is_skip, Ws...>*), Heaps... Hs)
		{
			// To accurately get the next indices, the depth cannot be zero.

			constexpr auto i1	= is_skip ? n::next_index1(c, _one, i, j) : i;
			constexpr auto j1	= is_skip ? n::next_index2(c, _one, i, j) : j;

			constexpr auto i2	= is_skip ? n::next_index1(c, _one, i1, j1) : i1;
			constexpr auto j2	= is_skip ? n::next_index2(c, _one, i1, j1) : j1;

			return NIK_MACHINE(n, c, d, i2, j2)(U_opt_pack_Vs<Ws...>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatch:

/***********************************************************************************************************************/

public:

	struct DD
	{
	// applications:

		static constexpr index_type size   (dc_type c, index_type i, index_type) { return c[i][DA::size  ]; }
		static constexpr index_type name   (dc_type c, index_type i, index_type) { return c[i][DA::name  ]; }
		static constexpr index_type note   (dc_type c, index_type i, index_type) { return c[i][DA::note  ]; }
		static constexpr index_type pos    (dc_type c, index_type i, index_type) { return c[i][DA::pos   ]; }

		static constexpr index_type obj    (dc_type c, index_type i, index_type) { return c[i][DA::obj   ]; }

		static constexpr index_type op     (dc_type c, index_type i, index_type) { return c[i][DA::op    ]; }
		static constexpr index_type arg    (dc_type c, index_type i, index_type) { return c[i][DA::arg   ]; }
		static constexpr index_type arg1   (dc_type c, index_type i, index_type) { return c[i][DA::arg1  ]; }
		static constexpr index_type arg2   (dc_type c, index_type i, index_type) { return c[i][DA::arg2  ]; }

		static constexpr index_type pred   (dc_type c, index_type i, index_type) { return c[i][DA::pred  ]; }
		static constexpr index_type input  (dc_type c, index_type i, index_type) { return c[i][DA::input ]; }
		static constexpr index_type input1 (dc_type c, index_type i, index_type) { return c[i][DA::input1]; }
		static constexpr index_type input2 (dc_type c, index_type i, index_type) { return c[i][DA::input2]; }

	// iterators:

		// name:

			static constexpr index_type next_name(dc_type c, depth_type d, index_type i, index_type)
			{
				if (d == 0)	return MN::pause;
				else 		return c[i+1][DA::name];
			}

		// note:

			static constexpr index_type next_note(dc_type c, depth_type d, index_type i, index_type)
			{
				if (d == 0)	return _zero;
				else		return c[i+1][DA::note];
			}

		// depth:

			static constexpr depth_type (*next_depth)(depth_type) =
				MD::template default_next_depth<depth_type>;

		// index1:

			static constexpr index_type next_index1(dc_type c, depth_type d, index_type i, index_type)
			{
				if (d == 0)	return i;
				else 		return i+1;
			}

		// index2:

			static constexpr index_type (*next_index2)(dc_type, depth_type, index_type, index_type) =
				MD::template default_next_index2<dc_type, depth_type, index_type, index_type>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

