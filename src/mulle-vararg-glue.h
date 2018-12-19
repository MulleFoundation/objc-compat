#ifndef mulle_vararg_glue_h__
#define mulle_vararg_glue_h__

#include <mulle-vararg/mulle-vararg.h>

typedef mulle_vararg_list          objc_va_list;

#define objc_va_copy( dst, src)    mulle_vararg_copy( dst, src)
#define objc_va_end( args)         mulle_vararg_end( args)
#define objc_va_start( args, last) mulle_vararg_start( args, last)

// use this for all pointer types
#define objc_va_next_fp( args, type)          mulle_vararg_next_fp( args, type)
#define objc_va_next_integer( args, type)     mulle_vararg_next_integer( args, type)
#define objc_va_next_long_double( args, type) mulle_vararg_next_long_double( args, type)
#define objc_va_next_object( args, type)      mulle_vararg_next_object( args, type)
#define objc_va_next_pointer( args, type)     mulle_vararg_next_pointer( args, type)
#define objc_va_next_struct( args, type)      mulle_vararg_next_struct( args, type)
#define objc_va_next_union( args, type)       mulle_vararg_next_union( args, type)

#define objc_va_next_char_pointer( args)      mulle_vararg_next_pointer( args, char *)
#define objc_va_next_double( args)            mulle_vararg_next_fp( args, double)
#define objc_va_next_id( args)                mulle_vararg_next_object( args, id)
#define objc_va_next_int( args)               mulle_vararg_next_integer( args, int)


//
// hacks the selector of initWithFormat:objcVarargList: and such methods
// to use the proper method. initWithFormat:mulleVarargList:
// Fails for @selector( initWithFormat:objcVarargList:)
//
#define objcVarargList             mulleVarargList

#endif
