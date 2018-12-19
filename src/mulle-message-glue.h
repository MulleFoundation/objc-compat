#ifndef mulle_message_glue_h__
#define mulle_message_glue_h__


// define oneway away mulle-objc doesn't have it
#define oneway


static inline id   objc_msgSend0( id self, SEL _cmd)
{
   return( MulleObjCPerformSelector0( self, _cmd));
}


static inline id   objc_msgSend( id self, SEL _cmd, id a)
{
   return( MulleObjCPerformSelector( self, _cmd, a));
}


static inline id   objc_msgSend2( id self, SEL _cmd, id a, id b)
{
   return( MulleObjCPerformSelector2( self, _cmd, a , b));
}


# pragma mark - imp calls

static inline id   objc_callIMP0( IMP imp, id self, SEL _cmd)
{
   return( MulleObjCCallIMP0( imp, self, _cmd));
}


static inline id   objc_callIMP( IMP imp, id self, SEL _cmd, id a)
{
   return( MulleObjCCallIMP( imp, self, _cmd, a));
}


static inline id   objc_callIMP2( IMP imp, id self, SEL _cmd, id a, id b)
{
   return( MulleObjCCallIMP2( imp, self, _cmd, a , b));
}


#endif
