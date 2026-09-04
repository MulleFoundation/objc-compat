//
//  objc-compat.h
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
#ifndef objc_compat_h__
#define objc_compat_h__
/*
 *  (c) 2018 nat
 *
 *  version:  major, minor, patch
 */
#define OBJC__COMPAT_VERSION  ((0UL << 20) | (21 << 8) | 3)


static inline unsigned int   objc_compat_get_version_major( void)
{
   return( OBJC__COMPAT_VERSION >> 20);
}


static inline unsigned int   objc_compat_get_version_minor( void)
{
   return( (OBJC__COMPAT_VERSION >> 8) & 0xFFF);
}


static inline unsigned int   objc_compat_get_version_patch( void)
{
   return( OBJC__COMPAT_VERSION & 0xFF);
}


/*
 * Determine runtime to include.
 * Include it.
 * Include our glue code.
 */

#ifdef __MULLE_OBJC__
# include <MulleObjC/mulle-objc.h>
# include <mulle-objc-compat/mulle-objc-compat.h>
# include "mulle-alloca-glue.h"
# include "mulle-isa-glue.h"
# include "mulle-compiler-glue.h"
# include "mulle-object-glue.h"
# include "mulle-message-glue.h"
# include "mulle-vararg-glue.h"
#else
# if defined( __APPLE__) && ! defined( GNUSTEP)
#  include "apple-isa-glue.h"  // need defines ahead
#  include <objc/objc.h>
#  include <objc/objc-runtime.h>
#  include <objc/objc-api.h>
#  include <objc/message.h>
#  include "apple-alloca-glue.h"
#  include "apple-object-glue.h"
#  include "apple-message-glue.h"
#  include "apple-vararg-glue.h"
# else
#  error "unsupported Objective-C runtime"
# endif
#endif


#ifdef __has_include
# if __has_include( "_objc-compat-versioncheck.h")
#  include "_objc-compat-versioncheck.h"
# endif
#endif

#endif

