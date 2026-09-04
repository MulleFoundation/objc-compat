//
//  mulle-message-glue.h
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
#ifndef mulle_message_glue_h__
#define mulle_message_glue_h__


#pragma clang diagnostic ignored "-Wdeprecated-objc-pointer-introspection"

#include <stdint.h>


// define oneway away mulle-objc doesn't have it
#define oneway

static inline void  *SEL_asPointer( SEL sel)
{
   return( (void *) (intptr_t) sel);
}


static inline SEL   pointer_asSEL( void *p)
{
   return( (SEL) (intptr_t) p);
}


static inline id   objc_msgSend0( id self, SEL _cmd)
{
   return( MulleObjCObjectPerformSelector0( self, _cmd));
}

static inline id   objc_msgSend1( id self, SEL _cmd, id a)
{
   return( MulleObjCObjectPerformSelector( self, _cmd, a));
}

static inline id   objc_msgSend2( id self, SEL _cmd, id a, id b)
{
   return( MulleObjCObjectPerformSelector2( self, _cmd, a , b));
}

static inline id   objc_msgSend3( id self, SEL _cmd, id a, id b, id c)
{
   return( MulleObjCObjectPerformSelector3( self, _cmd, a , b, c));
}

static inline id   objc_msgSend4( id self, SEL _cmd, id a, id b, id c, id d)
{
   return( MulleObjCObjectPerformSelector4( self, _cmd, a , b, c, d));
}

static inline id   objc_msgSend5( id self, SEL _cmd, id a, id b, id c, id d, id e)
{
   return( MulleObjCObjectPerformSelector5( self, _cmd, a , b, c, d, e));
}


static inline BOOL   objc_msgSendBOOLReturn( id self, SEL _cmd, id a)
{
   //
   // as BOOL is an int in MulleObjC (actually an enum)
   // the conversion back "should" be harmless
   return( (BOOL) (((intptr_t) MulleObjCObjectPerformSelector( self, _cmd, a)) & 0xFF));
}

static inline int   objc_msgSendIntReturn( id self, SEL _cmd, id a)
{
   //
   // cast objc_msgSend into a function returning an int
   //
   return( (int) (intptr_t) MulleObjCObjectPerformSelector( self, _cmd, a));
}


# pragma mark - imp calls

static inline id   objc_callIMP0( IMP imp, id self, SEL _cmd)
{
   return( MulleObjCIMPCall0( imp, self, _cmd));
}


static inline id   objc_callIMP1( IMP imp, id self, SEL _cmd, id a)
{
   return( MulleObjCIMPCall( imp, self, _cmd, a));
}


static inline id   objc_callIMP2( IMP imp, id self, SEL _cmd, id a, id b)
{
   return( MulleObjCIMPCall2( imp, self, _cmd, a , b));
}


static inline id   objc_callIMP3( IMP imp, id self, SEL _cmd, id a, id b, id c)
{
   return( MulleObjCIMPCall3( imp, self, _cmd, a , b, c));
}


static inline id   objc_callIMP4( IMP imp, id self, SEL _cmd, id a, id b, id c, id d)
{
   return( MulleObjCIMPCall4( imp, self, _cmd, a, b, c, d));
}


static inline id   objc_callIMP5( IMP imp, id self, SEL _cmd, id a, id b, id c, id d, id e)
{
   return( MulleObjCIMPCall5( imp, self, _cmd, a, b, c, d, e));
}


static inline BOOL   objc_callIMPBOOLReturn( IMP imp, id self, SEL _cmd, id a)
{
   //
   // as BOOL is an int in MulleObjC (actually an enum)
   // the conversion back "should" be harmless, but we cut off to 0xFF
   // for compatibility
   return( (BOOL) (((intptr_t) MulleObjCIMPCall( imp, self, _cmd, a)) & 0xFF));
}


static inline int   objc_callIMPIntReturn( IMP imp, id self, SEL _cmd, id a)
{
   return( (int) (intptr_t) MulleObjCIMPCall( imp, self, _cmd, a));
}


static inline void   objc_msgBroadcast( id *self, NSUInteger n, SEL _cmd, id a)
{
   MulleObjCMakeObjectsPerformSelector( self, n, _cmd, a);
}

#endif
