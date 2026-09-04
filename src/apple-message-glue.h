//
//  apple-message-glue.h
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
#ifndef apple_message_glue_h__
#define apple_message_glue_h__


//
// for mulle-objc this needs an intermediate cast due to C++ influence 
//
static inline void  *SEL_asPointer( SEL sel)
{
   return( (void *) sel);
}


static inline SEL   pointer_asSEL( void *p)
{
   return( (SEL) p);
}


static inline id   objc_msgSend0( id self, SEL _cmd)
{
   return( ((id (*)( id, SEL)) objc_msgSend)( self, _cmd));
}

static inline id   objc_msgSend1( id self, SEL _cmd, id a)
{
   return( ((id (*)( id, SEL, id)) objc_msgSend)( self, _cmd, a));
}

static inline id   objc_msgSend2( id self, SEL _cmd, id a, id b)
{
   return( ((id (*)( id, SEL, id, id)) objc_msgSend)( self, _cmd, a, b));
}

static inline id   objc_msgSend3( id self, SEL _cmd, id a, id b, id c)
{
   return( ((id (*)( id, SEL, id, id, id)) objc_msgSend)( self, _cmd, a , b, c));
}

static inline id   objc_msgSend4( id self, SEL _cmd, id a, id b, id c, id d)
{
   return( ((id (*)( id, SEL, id, id, id, id)) objc_msgSend)( self, _cmd, a, b, c, d));
}

static inline id   objc_msgSend5( id self, SEL _cmd, id a, id b, id c, id d, id e)
{
   return( ((id (*)( id, SEL, id, id, id, id, id)) objc_msgSend)( self, _cmd, a, b, c, d, e));
}


static inline BOOL   objc_msgSendBOOLReturn( id self, SEL _cmd, id a)
{
   //
   // cast objc_msgSend into a function returning a BOOL
   // cut off leading junk for compatiblity
   return( ((BOOL (*)( id, SEL, id)) objc_msgSend) ( self, _cmd, a));
}

static inline BOOL   objc_msgSendIntReturn( id self, SEL _cmd, id a)
{
   //
   // cast objc_msgSend into a function returning an int
   //
   return( ((int (*)( id, SEL, id)) objc_msgSend) ( self, _cmd, a));
}




# pragma mark - imp calls

static inline id   objc_callIMP0( IMP imp, id self, SEL _cmd)
{
   return( (* (id (*)( id, SEL)) imp)( self, _cmd));
}


static inline id   objc_callIMP1( IMP imp, id self, SEL _cmd, id a)
{
   return( (* (id (*)( id, SEL, id)) imp)( self, _cmd, a));
}


static inline id   objc_callIMP2( IMP imp, id self, SEL _cmd, id a, id b)
{
   return( (* (id (*)( id, SEL, id, id)) imp)( self, _cmd, a , b));
}


static inline id   objc_callIMP3( IMP imp, id self, SEL _cmd, id a, id b, id c)
{
   return( (* (id (*)( id, SEL, id, id, id)) imp)( self, _cmd, a , b, c));
}


static inline id   objc_callIMP4( IMP imp, id self, SEL _cmd, id a, id b, id c, id d)
{
   return( (* (id (*)( id, SEL, id, id, id, id)) imp)( self, _cmd, a, b, c, d));
}


static inline id   objc_callIMP5( IMP imp, id self, SEL _cmd, id a, id b, id c, id d, id e)
{
   return( (* (id (*)( id, SEL, id, id, id, id, id)) imp)( self, _cmd, a, b, c, d, e));
}


static inline BOOL   objc_callIMPBOOLReturn( IMP imp, id self, SEL _cmd, id a)
{
   //
   // cast into a function returning a BOOL
   //
   return( ((BOOL (*)( id, SEL, id)) imp)( self, _cmd, a));
}


static inline int   objc_callIMPIntReturn( IMP imp, id self, SEL _cmd, id a)
{
   //
   // cast into a function returning a BOOL
   //
   return( ((int (*)( id, SEL, id)) imp)( self, _cmd, a));
}


static inline void   objc_msgBroadcast( id *objects, uintptr_t n, SEL _cmd, id a)
{
   id   *p;
   id   *sentinel;

   p        = objects;
   sentinel = &p[ n];
   while( p < sentinel)
      objc_msgSend1( *p++, _cmd, a);
}

#endif
