#ifndef apple_object_glue_h__
#define apple_object_glue_h__


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

#endif
