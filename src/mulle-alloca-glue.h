#ifndef mulle_alloca_glue_h__
#define mulle_alloca_glue_h__

#include <stdlib.h>

//
// A problem with this approach is, that the lifetime is tied to the
// autoreleasepool and not the stack frame.
//
#if DEBUG  // coz the stupid debugger trips up on alloca stack frames
# define objc_alloca( size)  MulleObjCCallocAutoreleased( 1, (size))
#else
# define objc_alloca( size)            \
  ( (size) <= (sizeof( double) * 32)   \
      ? alloca( (size))                \
      : MulleObjCCallocAutoreleased( 1, (size)))
#endif

#endif
