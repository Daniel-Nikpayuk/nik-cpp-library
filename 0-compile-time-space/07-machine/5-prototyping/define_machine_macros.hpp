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

// define machine macros:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
				initial pattern:

		2^0 - ll(V0, cur_ll)
		2^1 - ll(V0, ll(V1, cur_ll))
		  3 - ll(V0, ll(V1, ll(V2, cur_ll)))
		2^2 - ll(V0, ll(V1, ll(V2, ll(V3, cur_ll))))

				normalized pattern:

		2^0 - ll(V0,                         cur_ll    )
		2^1 - ll(V0, ll(V1,                  cur_ll    ))
		  3 - ll(V0, ll(V1, ll(V2,           cur_ll    )))
		2^2 - ll(V0, ll(V1, ll(V2, ll(V3,    cur_ll    ))))

				abstract pattern:

		2^N - _2_ ## N ## _ll_Vs             cur_ll    _2_ ## N ## _lls
*/

/***********************************************************************************************************************/

// cons (2^N):

	#define define_block_machine_cons(N)										\
															\
		template<>												\
		struct machine<MN::cons_2_n, N>										\
		{													\
			template											\
			<												\
				typename n, auto c, auto i, auto j,							\
				auto V, _2_ ## N ## _auto_Vs, auto... Vs,						\
				auto op, typename... Heaps								\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<op>*), Heaps... Hs)				\
			{												\
				return machine										\
				<											\
					n::next_name(c, d, i, j),							\
					n::next_note(c, d, i, j)							\
															\
				>::template result									\
				<											\
					n, c,										\
															\
					n::next_depth(d),								\
					n::next_index1(c, d, i, j),							\
					n::next_index2(c, d, i, j),							\
															\
					_2_ ## N ## _ops  V,  _2_ ## N ## _op_Vs, Vs...					\
															\
				>(H0, Hs...);										\
			}												\
		}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

