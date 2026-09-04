//
//  mulle-vararg-glue.h
//  objc-compat
//
//  Copyright (c) 2018 Nat! - Mulle kybernetiK.
//  All rights reserved.
//
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//  Redistributions of source code must retain the above copyright notice, this
//  list of conditions and the following disclaimer.
//
//  Redistributions in binary form must reproduce the above copyright notice,
//  this list of conditions and the following disclaimer in the documentation
//  and/or other materials provided with the distribution.
//
//  Neither the name of Mulle kybernetiK nor the names of its contributors
//  may be used to endorse or promote products derived from this software
//  without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//
#ifndef mulle_vararg_glue_h__
#define mulle_vararg_glue_h__

#include <mulle-vararg/mulle-vararg.h>

typedef mulle_vararg_list          objc_va_list;

#define objc_va_copy( dst, src)    mulle_vararg_copy( dst, src)
#define objc_va_end( args)         mulle_vararg_end( args)
#define objc_va_start( args, last) mulle_vararg_start( args, last)

// use this for all pointer types
#define objc_va_next_fp( args, type)          mulle_vararg_next_fp( args, type)
#define objc_va_next_integer( args, type)     mulle_vararg_next_integer( args, type)
#define objc_va_next_long_double( args, type) mulle_vararg_next_long_double( args, type)
#define objc_va_next_object( args, type)      mulle_vararg_next_object( args, type)
#define objc_va_next_pointer( args, type)     mulle_vararg_next_pointer( args, type)
#define objc_va_next_struct( args, type)      mulle_vararg_next_struct( args, type)
#define objc_va_next_union( args, type)       mulle_vararg_next_union( args, type)

#define objc_va_next_char_pointer( args)      mulle_vararg_next_pointer( args, char *)
#define objc_va_next_double( args)            mulle_vararg_next_fp( args, double)
#define objc_va_next_id( args)                mulle_vararg_next_object( args, id)
#define objc_va_next_int( args)               mulle_vararg_next_integer( args, int)


//
// hacks the selector of initWithFormat:objcVarargList: and such methods
// to use the proper method. initWithFormat:mulleVarargList:
// Fails for @selector( initWithFormat:objcVarargList:)
//
#define objcVarargList             mulleVarargList

#endif
