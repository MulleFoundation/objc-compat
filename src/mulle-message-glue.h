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

static inline id   objc_msgSend3( id self, SEL _cmd, id a, id b, id c)
{
   return( MulleObjCPerformSelector3( self, _cmd, a , b, c));
}

static inline id   objc_msgSend4( id self, SEL _cmd, id a, id b, id c, id d)
{
   return( MulleObjCPerformSelector4( self, _cmd, a , b, c, d));
}

static inline id   objc_msgSend5( id self, SEL _cmd, id a, id b, id c, id d, id e)
{
   return( MulleObjCPerformSelector5( self, _cmd, a , b, c, d, e));
}


static inline BOOL   objc_msgSendBOOLReturn( id self, SEL _cmd, id a)
{
   //
   // as BOOL is an int in MulleObjC (actually an enum)
   // the conversion back "should" be harmless
   return( (BOOL) (int) MulleObjCPerformSelector( self, _cmd, a));
}

static inline int   objc_msgSendIntReturn( id self, SEL _cmd, id a)
{
   //
   // cast objc_msgSend into a function returning an int
   //
   return( (int) MulleObjCPerformSelector( self, _cmd, a));
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


static inline id   objc_callIMP3( IMP imp, id self, SEL _cmd, id a, id b, id c)
{
   return( MulleObjCCallIMP3( imp, self, _cmd, a , b, c));
}


static inline id   objc_callIMP4( IMP imp, id self, SEL _cmd, id a, id b, id c, id d)
{
   return( MulleObjCCallIMP4( imp, self, _cmd, a, b, c, d));
}


static inline id   objc_callIMP5( IMP imp, id self, SEL _cmd, id a, id b, id c, id d, id e)
{
   return( MulleObjCCallIMP5( imp, self, _cmd, a, b, c, d, e));
}


static inline BOOL   objc_callIMPBOOLReturn( IMP imp, id self, SEL _cmd, id a)
{
   //
   // as BOOL is an int in MulleObjC (actually an enum)
   // the conversion back "should" be harmless
   //
   return( (BOOL) (int) MulleObjCCallIMP( imp, self, _cmd, a));
}

static inline BOOL   objc_callIMPIntReturn( IMP imp, id self, SEL _cmd, id a)
{
   //
   // as BOOL is an int in MulleObjC (actually an enum)
   // the conversion back "should" be harmless
   return( (int) MulleObjCCallIMP( imp, self, _cmd, a));
}


static inline void   objc_msgBroadcast( id *self, NSUInteger n, SEL _cmd, id a)
{
   return( MulleObjCMakeObjectsPerformSelector( self, n, _cmd, a));
}

#endif
