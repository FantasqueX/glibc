/* Symbol rediretion for loader/static initialization code.
   Copyright (C) 2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _DL_SYMBOL_HACKS_H
#define _DL_SYMBOL_HACKS_H

#include <dl-ifunc-generic.h>

/* Some compiler optimizations may transform loops into memset/memmove
   calls and without proper redirection it might call PLT throught
   ifunc without relocations being processed.  */
#ifdef HAVE_MEMSET_IFUNC_GENERIC
asm ("memset = " HAVE_MEMSET_IFUNC_GENERIC);
#endif

#endif
