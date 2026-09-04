//
//  apple-vararg-glue.h
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
#ifndef apple_vararg_glue_h__
#define apple_vararg_glue_h__

#include <stdarg.h>

typedef va_list   objc_va_list;

#define objc_va_copy( dst, src)                 va_copy( dst, src)
#define objc_va_end( args)                      va_end( args)
#define objc_va_start( args, last)              va_start( args, last)

#define objc_va_next_fp( args, type)            va_arg( args, type)
#define objc_va_next_integer( args, type)       va_arg( args, type)
#define objc_va_next_long_double( args, type)   va_arg( args, type)
#define objc_va_next_object( args, type)        va_arg( args, type)
#define objc_va_next_pointer( args, type)       va_arg( args, type)
#define objc_va_next_struct( args, type)        va_arg( args, type)
#define objc_va_next_union( args, type)         va_arg( args, type)

#define objc_va_next_char_pointer( args)        va_arg( args, char *)
#define objc_va_next_double( args)              va_arg( args, double)
#define objc_va_next_id( args)                  va_arg( args, id)
#define objc_va_next_int( args)                 va_arg( args, int)

//
// hacks the selector of initWithFormat:objcVarargList: and such methods
// to use the proper method. initWithFormat:arguments:
// Fails for @selector( initWithFormat:objcVarargList:)
//
#define objcVarargList             arguments

#endif
