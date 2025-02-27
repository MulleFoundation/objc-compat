/* DO:    #import this files in public headers

   DONT:  #import this file in private headers
          #import this files in directly in sources
          #include this file anywhere
*/

/* This is a central include file to keep dependencies out of the library
   Objective-C files. It is usally imported by Objective-C .h files only.
   .m and .aam use import-private.h.
*/

/* Include the header file automatically generated by mulle-sourcetree-to-c.
   Here the prefix is harmless and serves disambiguation. If you have no
   sourcetree, then you don't need it.
 */

#import "_objc-compat-import.h"
#ifdef OBJC_COMPAT_BUILD
# define OBJC_COMPAT_GLOBAL    MULLE_C_GLOBAL
#else
# if defined( OBJC_COMPAT_INCLUDE_DYNAMIC) || (defined( MULLE_INCLUDE_DYNAMIC) && ! defined( OBJC_COMPAT_INCLUDE_STATIC))
#  define OBJC_COMPAT_GLOBAL   MULLE_C_EXTERN_GLOBAL
# else
#  define OBJC_COMPAT_GLOBAL   extern
# endif
#endif


/* You can add some more import statements here */
