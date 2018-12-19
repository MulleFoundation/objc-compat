#ifndef apple_vararg_glue_h__
#define apple_vararg_glue_h__

#include <stdarg/stdarg.h>

typedef va_list   objc_va_list;

#define objc_va_copy( dst, src)                 va_copy( dst, src)
#define objc_va_end( args)                      va_end( args)
#define objc_va_start( args, last)              va_start( args, last)

#define objc_va_next_fp( args, type)            va_arg( args, type)
#define objc_va_next_integer( args, type)       va_arg( args, type)
#define objc_va_next_long_double( args, type)   va_arg( args, type)
#define objc_va_next_object( args, type)        va_arg( args, type)
#define objc_va_next_pointer( args, type)       va_arg( args, type)
#define objc_va_next_struct( args, type)        va_arg( args, type)
#define objc_va_next_union( args, type)         va_arg( args, type)

#define objc_va_next_char_pointer( args)        va_arg( args, char *)
#define objc_va_next_double( args)              va_arg( args, double)
#define objc_va_next_id( args)                  va_arg( args, id)
#define objc_va_next_int( args)                 va_arg( args, int)

//
// hacks the selector of initWithFormat:objcVarargList: and such methods
// to use the proper method. initWithFormat:arguments:
// Fails for @selector( initWithFormat:objcVarargList:)
//
#define objcVarargList             arguments

#endif
