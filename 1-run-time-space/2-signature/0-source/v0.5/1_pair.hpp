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

// pair:

//	filters (accessors):

//		i(...) - identity
//		d(...) - dereference

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pair:

/***********************************************************************************************************************/

	template<typename CarType, typename CdrType>
	struct pair_signature
	{
		CarType car;
		CdrType cdr;

		pair_signature() { }
	};

	//

	template<typename Pair>
	constexpr auto & pair_car(Pair & arg)		{ return arg.car; }

	template<typename Pair>
	constexpr auto & pair_cdr(Pair & arg)		{ return arg.cdr; }

	//

	template<typename Pair, auto Car, auto Cdr>
	struct pair_specification
	{
		using sign_type				= Pair;

		static constexpr auto sign_return	= Car;
		static constexpr auto sign_facade	= set<Cdr, Pair, T_reference_type_T<f_out_type<Cdr>>>;

		static constexpr auto car		= Car;
		static constexpr auto cdr		= Cdr;
	};

