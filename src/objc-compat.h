#ifndef objc_compat_h__
#define objc_compat_h__
/*
 *  (c) 2018 nat
 *
 *  version:  major, minor, patch
 */
#define OBJC_COMPAT_VERSION  ((0 << 20) | (20 << 8) | 0)


static inline unsigned int   objc_compat_get_version_major( void)
{
   return( OBJC_COMPAT_VERSION >> 20);
}


static inline unsigned int   objc_compat_get_version_minor( void)
{
   return( (OBJC_COMPAT_VERSION >> 8) & 0xFFF);
}


static inline unsigned int   objc_compat_get_version_patch( void)
{
   return( OBJC_COMPAT_VERSION & 0xFF);
}


/*
 * Determine runtime to include.
 * Include it.
 * Include our glue code.
 */

#ifdef __MULLE_OBJC__
# include <MulleObjC/mulle-objc.h>
# include <mulle-objc-compat/mulle-objc-compat.h>
# include "mulle-alloca-glue.h"
# include "mulle-isa-glue.h"
# include "mulle-compiler-glue.h"
# include "mulle-object-glue.h"
# include "mulle-message-glue.h"
# include "mulle-vararg-glue.h"
#else
# if defined( __APPLE__) && ! defined( GNUSTEP)
#  include "apple-isa-glue.h"  // need defines ahead
#  include <objc/objc.h>
#  include <objc/objc-runtime.h>
#  include <objc/objc-api.h>
#  include <objc/message.h>
#  include "apple-alloca-glue.h"
#  include "apple-object-glue.h"
#  include "apple-message-glue.h"
#  include "apple-vararg-glue.h"
# else
#  error "unsupported Objective-C runtime"
# endif
#endif

#endif

