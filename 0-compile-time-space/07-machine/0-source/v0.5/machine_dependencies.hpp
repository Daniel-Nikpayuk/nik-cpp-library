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

// machine dependencies source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

	privileged instructions:

		0. erase
		1. insert
		2. replace
		3. branch
		4. goto using
		5. goto label
		6. assign using
		7. assign label
		8. test
		9. apply

/***********************************************************************************************************************/

	primary dependency instructions:

		0. reindex
		1. drop s pos
		2. (call) at
		3. move h0 first insert at s pos
		4. move h0 first replace at s pos
		5. copy i pos insert at h0 front
		6. copy s pos insert at h0 back
		7. apply h0 all move replace h0 front
		8. apply h0 all move replace s pos

/***********************************************************************************************************************/

	secondary dependency instructions:

		0. first
		1. drop s block
		2. move s segment insert at h1 back
		3. move h0 first insert at s front
		4. move h1 all insert at s front
		5. copy s block insert at h0 back
		6. apply h0 all move insert at s front

/***********************************************************************************************************************/

	tertiary dependency instructions:

		0. move s block insert at h1 back

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// hierarchy:

/***********************************************************************************************************************/

// level 0:

		0. first
		1. branch
		2. reindex
		3. copy i pos insert at h0 front

		0. move h0 first insert at s front
		0. move h1 all insert at s front
		0. apply h0 all move insert at s front
		0. apply h0 all move replace h0 front

/***********************************************************************************************************************/

// level 1:

		1. drop s block
		0. move s block insert at h1 back
		0. copy s block insert at h0 back

/***********************************************************************************************************************/

// level 2:

		0. at
		0. drop s pos
		0. move s segment insert at h1 back

/***********************************************************************************************************************/

// level 3:

		0. move h0 first insert at s pos
		0. move h0 first replace at s pos
		0. copy s pos insert at h0 back

		0. apply h0 all move replace s pos

/***********************************************************************************************************************/

// level 4:

		0. erase
		0. insert
		0. replace
		0. branch
		0. goto using
		0. goto label
		0. assign using
		0. assign label
		0. test
		0. apply

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// new hierarchy:

/***********************************************************************************************************************/

// level 0:

		0. first
		1. branch
		2. reindex
		3. copy i pos insert at h0 front

		0. move h0 first insert at s front
		0. move h1 all insert at s front
		0. apply h0 all move insert at s front
		0. apply h0 all move replace h0 front

/***********************************************************************************************************************/

// level 1:

		1. drop s block
		0. move s block insert at h1 back
		0. copy s block insert at h0 back

/***********************************************************************************************************************/

// level 2:

		0. at
		0. drop s pos
		0. move s segment insert at h1 back

/***********************************************************************************************************************/

// level 3:

		0. move h0 first insert at s pos
		0. move h0 first replace at s pos
		0. copy s pos insert at h0 back

		0. apply h0 all move replace s pos

/***********************************************************************************************************************/

// level 4:

		0. erase
		0. insert
		0. replace
		0. branch
		0. goto using
		0. goto label
		0. assign using
		0. assign label
		0. test
		0. apply

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

