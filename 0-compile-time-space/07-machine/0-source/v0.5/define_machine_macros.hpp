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

// define machine macros source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// preamble:

/***********************************************************************************************************************/

	#define NIK_CONTR_PARAMS											\
															\
		auto n, auto c, auto d, auto i, auto j									\

/***********************************************************************************************************************/

	#define NIK_BEGIN_MACHINE(_n_, _c_, _d_, _i_, _j_)								\
															\
		machine													\
		<													\
			T_type_U<_n_>::next_name(_c_, _d_, _i_, _j_),							\
			T_type_U<_n_>::next_note(_c_, _d_, _i_, _j_)							\
															\
		>::template result											\
		<													\
			_n_, _c_,											\
															\
			T_type_U<_n_>::next_depth(_d_),									\
			T_type_U<_n_>::next_index1(_c_, _d_, _i_, _j_),							\
			T_type_U<_n_>::next_index2(_c_, _d_, _i_, _j_)

	#define NIK_END_MACHINE 											\
															\
		>

	#define NIK_MACHINE(_n_, _c_, _d_, _i_, _j_, _v_)								\
															\
		NIK_BEGIN_MACHINE(_n_, _c_, _d_, _i_, _j_),  _v_...  NIK_END_MACHINE

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// unpack instruction block (2^N):

	#define NIK_DEFINE__UNPACK_I_BLOCK(_n_)										\
															\
		template<key_type... filler>										\
		struct machine<MN::unpack_i_block, _n_, filler...>							\
		{													\
			static constexpr index_type offset = 5;								\
															\
			template<NIK_CONTR_PARAMS, auto... Vs, auto... Ws, typename... Heaps>				\
			static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)				\
			{												\
				using tn			= T_type_U<n>;						\
				constexpr index_type offset	= sizeof...(Vs);					\
															\
				return NIK_MACHINE(n, c, d, i, j, Vs)							\
				(											\
					U_opt_pack_Vs<NIK_2_ ## _n_ ## _INDICES(offset), Ws...>,			\
					H1, Hs...									\
				);											\
			}												\
		}

/***********************************************************************************************************************/

// drop stack block (2^N):

	#define NIK_DEFINE__DROP_S_BLOCK(_n_)										\
															\
		template<key_type... filler>										\
		struct machine<MN::drop_s_block, _n_, filler...>							\
		{													\
			template<NIK_CONTR_PARAMS, NIK_2_ ## _n_ ## _AUTO_VS, auto... Vs, typename... Heaps>		\
			static constexpr auto result(Heaps... Hs)							\
			{												\
				return NIK_MACHINE(n, c, d, i, j, Vs)(Hs...);						\
			}												\
		}

/***********************************************************************************************************************/

// move stack block (2^N):

	#define NIK_DEFINE__MOVE_S_BLOCK(_n_)										\
															\
		template<key_type... filler>										\
		struct machine<MN::move_s_block, _n_, filler...>							\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_2_ ## _n_ ## _AUTO_VS, auto... Vs,				\
				auto... Ws, auto... Xs, typename... Heaps						\
			>												\
			static constexpr auto result									\
			(												\
				void(*H0)(auto_pack<Ws...>*),								\
				void(*H1)(auto_pack<Xs...>*),								\
				Heaps... Hs										\
			)												\
			{												\
				using tn			= T_type_U<n>;						\
				constexpr key_type memonic	= tn::mem(c, i, j);					\
				constexpr key_type locator	= tn::loc(c, i, j);					\
															\
				if constexpr (memonic == MM::heap_one)							\
				{											\
					if constexpr (locator == MM::back)						\
															\
						return NIK_MACHINE(n, c, d, i, j, Vs)					\
							(H0, U_opt_pack_Vs<Xs..., NIK_2_ ## _n_ ## _VS>, Hs...);	\
					else										\
						return NIK_MACHINE(n, c, d, i, j, Vs)					\
							(H0, U_opt_pack_Vs<NIK_2_ ## _n_ ## _VS, Xs...>, Hs...);	\
				}											\
				else if constexpr (memonic == MM::heap_zero)						\
				{											\
					if constexpr (locator == MM::front)						\
															\
						return NIK_MACHINE(n, c, d, i, j, Vs)					\
							(U_opt_pack_Vs<NIK_2_ ## _n_ ## _VS, Ws...>, H1, Hs...);	\
					else										\
						return NIK_MACHINE(n, c, d, i, j, Vs)					\
							(U_opt_pack_Vs<Ws..., NIK_2_ ## _n_ ## _VS>, H1, Hs...);	\
				}											\
				else /* if constexpr (memonic == MM::stack) */						\
					return NIK_BEGIN_MACHINE(n, c, d, i, j),					\
															\
						Vs..., NIK_2_ ## _n_ ## _VS						\
															\
					NIK_END_MACHINE(H0, H1, Hs...);							\
			}												\
		}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

