# objc-compat

🔗 Glue for Objective-C code for using various runtimes

This library adds a few functions to portably write message sends and variable arguments calls.
It is also the place that includes the required headers depending on platform.

Runtime       |  Selection
--------------|---------------------
mulle-objc    | `defined( __MULLE_OBJC__)`
Apple         | `! defined( __MULLE_OBJC__) && defined( __APPLE__)`
GnuSTEP       | not yet
Cocoatron     | not yet
FW            | not yet


## Message sends

Message sending in most cases shold be done by the compiler with `[]`, but since you're here anyway. 
These are the defined message functions:

Function        | Return Value | Arguments
----------------|--------------|----------------
`objc_msgSend0` | id           | void
`objc_msgSend`  | id           | id
`objc_msgSend2` | id           | id, id


## Variable arguments

The various `va_list`, `va_start`functions and types are prefixed with `objc_`. These are to be used 
instead of the `<stdarg.h>` counterparts for Objective-C functions accepting variable arguments
with `...` or `va_list`. 

C functions will still use `<stdarg.h>`.

Note that `va_list` and `objc_va_list` are different types and not compatible!

