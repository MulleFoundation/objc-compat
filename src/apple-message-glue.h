#ifndef apple_message_glue_h__
#define apple_message_glue_h__


static inline id   objc_msgSend0( id self, SEL _cmd)
{
   return( objc_msgSend( self, _cmd));
}


static inline id   objc_msgSend2( id self, SEL _cmd, id a, id b)
{
   return( objc_msgSend( self, _cmd,a , b));
}



# pragma mark - imp calls

static inline id   objc_callIMP0( IMP imp, id self, SEL _cmd)
{
   return( (*IMP)( self, _cmd));
}


static inline id   objc_callIMP( IMP imp, id self, SEL _cmd, id a)
{
   return( (*IMP)( self, _cmd, a));
}


static inline id   objc_callIMP2( IMP imp, id self, SEL _cmd, id a, id b)
{
   return( (*IMP)( self, _cmd, a , b));
}

#endif
