//
//  apple-object-glue.h
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
#ifndef apple_object_glue_h__
#define apple_object_glue_h__

#include <stdint.h>
#include <assert.h>

#ifndef PROTOCOL
typedef Protocol  *PROTOCOL;
#endif

//
// if you allocate instancesize amount of memory, use this to get the pointer
// to the instance
//
static inline id  objc_getInstance( void *memory)
{
   return( (id) memory);
}


static inline void  *object_getAlloc( id obj)
{
   return( (void *) obj);
}


static inline void  *object_getExtraBytes( id obj)
{
   void      *allocation;
   size_t    size;

   if( ! obj)
      return( obj);

   allocation = object_getAlloc( obj);
   size       = class_getInstanceSize( object_getClass( obj));
   return( &((char *) allocation)[ size]);
}


// we can't support all this, but maybe it just works
#define MULLE_OBJC_MAKE_CLASSID( classname)       	0
#define MULLE_OBJC_MAKE_CATEGORYID( categoryname) 	0

#define MULLE_OBJC_CLASS_DEPENDENCY( classname) 
#define MULLE_OBJC_CATEGORY_DEPENDENCY( classname, categoryname) 
#define MULLE_OBJC_LIBRARY_DEPENDENCY( libname) 
#define MULLE_OBJC_NO_DEPENDENCY  

#define MULLE_OBJC_DEPENDS_ON_CLASS( classname)             
#define MULLE_OBJC_DEPENDS_ON_CATEGORY( classname, categoryname) 
#define MULLE_OBJC_DEPENDS_ON_LIBRARY( libname)             

//
// NOT using NSUInteger here, since we potentially don't have
// it yet (see mulle-bunchobjects...)
//
// old fashioned, wrongly named and pretty much unused
static inline uintptr_t   MulleObjCCopyObjects( id *objects,
                                                uintptr_t length,
                                                uintptr_t count, ...)
{
   va_list      args;
   id           *sentinel;
   id           obj;
   uintptr_t    n;

   assert( objects || ! length);

   sentinel = &objects[ length];
   n        = 0;

   va_start( args, count);
   while( count)
   {
      obj = va_arg( args, id);
      if( obj)
      {
         ++n;
         if( objects < sentinel)
            *objects++ = obj;
      }
      --count;
   }
   va_end( args);

   return( n);
}

// old fashioned, wrongly named and pretty much unused
static inline uintptr_t   MulleObjCCopyObjectArray( id *objects,
                                                     uintptr_t length,
                                                     id *array,
                                                     uintptr_t count)
{
   va_list      args;
   id           *sentinel;
   id           obj;
   uintptr_t    n;

   assert( objects || ! length);

   sentinel = &objects[ length];
   n        = 0;

   while( count)
   {
      obj = *array++;
      if( obj)
      {
         ++n;
         if( objects < sentinel)
            *objects++ = obj;
      }
      --count;
   }

   return( n);
}
#endif
