#ifndef mulle_object_glue_h__
#define mulle_object_glue_h__


//
// if you allocate instancesize amount of memory, use this to get the pointer
// to the instance
//
static inline id  objc_getInstance( void *memory)
{
   return( memory ? (id) _mulle_objc_objectheader_get_object( memory) : (id) memory);
}


static inline void  *object_getAlloc( id obj)
{
   return( obj ? (void *) _mulle_objc_object_get_objectheader( (struct _mulle_objc_object *) obj)
               : (void *) obj);
}

#endif
