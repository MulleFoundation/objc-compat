#ifndef apple_message_glue_h__
#define apple_message_glue_h__


static inline id   objc_msgSend0( id self, SEL _cmd)
{
   return( objc_msgSend( self, _cmd));
}

static inline id   objc_msgSend2( id self, SEL _cmd, id a, id b)
{
   return( objc_msgSend( self, _cmd, a , b));
}

static inline id   objc_msgSend3( id self, SEL _cmd, id a, id b, id c)
{
   return( objc_msgSend( self, _cmd, a , b, c));
}

static inline id   objc_msgSend4( id self, SEL _cmd, id a, id b, id c, id d)
{
   return( objc_msgSend( self, _cmd, a , b, c, d));
}

static inline id   objc_msgSend5( id self, SEL _cmd, id a, id b, id c, id d, id e)
{
   return( objc_msgSend( self, _cmd, a , b, c, d, e));
}


static inline BOOL   objc_msgSendBOOLReturn( id self, SEL _cmd, id a)
{
   //
   // cast objc_msgSend into a function returning a BOOL
   //
   return( ((BOOL (*)( id, SEL, ...)) objc_msgSend) ( self, _cmd, a));
}

static inline BOOL   objc_msgSendIntReturn( id self, SEL _cmd, id a)
{
   //
   // cast objc_msgSend into a function returning an int
   //
   return( ((int (*)( id, SEL, ...)) objc_msgSend) ( self, _cmd, a));
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


static inline id   objc_callIMP3( IMP imp, id self, SEL _cmd, id a, id b, id c)
{
   return( (*IMP)( imp, self, _cmd, a , b, c));
}


static inline id   objc_callIMP4( IMP imp, id self, SEL _cmd, id a, id b, id c, id d)
{
   return( (*IMP)( imp, self, _cmd, a , b, c, d));
}


static inline id   objc_callIMP5( IMP imp, id self, SEL _cmd, id a, id b, id c, id d, id e)
{
   return( (*IMP)( imp, self, _cmd, a , b, c, d, e));
}


static inline BOOL   objc_callIMPBOOLReturn( IMP imp, id self, SEL _cmd, id a)
{
   //
   // cast into a function returning a BOOL
   //
   return( ((BOOL (*)( id, SEL, ...)) imp)( self, _cmd, a));
}


static inline int   objc_callIMPIntReturn( IMP imp, id self, SEL _cmd, id a)
{
   //
   // cast into a function returning a BOOL
   //
   return( ((int (*)( id, SEL, ...)) imp)( self, _cmd, a));
}


static inline void   objc_msgBroadcast( id *objects, NSUInteger n, SEL _cmd, id a)
{
   id   *p;
   id   *sentinel;

   p        = objects;
   sentinel = &p[ n];
   while( p < sentinel)
      objc_msgSend( *p++, _cmd, a);
}

#endif
