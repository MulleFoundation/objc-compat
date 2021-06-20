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
