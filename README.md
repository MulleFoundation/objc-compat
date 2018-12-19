# 🔗 objc-compat
### Glue for Objective-C code to support different runtimes

This library adds a few functions to portably write various somewhat tricky
topics such as variable arguments calls.

It is also the place that includes the required runtime headers depending on
platform.


Runtime       |  Selection
--------------|---------------------
mulle-objc    | `defined( __MULLE_OBJC__)`
Apple         | `! defined( __MULLE_OBJC__) && defined( __APPLE__)`
GnuSTEP       | not yet
Cocoatron     | not yet
FW            | not yet


## Message sends

Message sending in most cases shold be done by the compiler with `[]` as the
compiler knows how to handle mulle-objc messaging. but
since you're here anyway. These are the defined message functions:

Function        | Return Value | Arguments
----------------|--------------|----------------
`objc_msgSend0` | id           | id, SEL
`objc_msgSend`  | id           | id, SEL, id
`objc_msgSend2` | id           | id, SEL, id, id

These are the defined IMP calls:

Function        | Return Value | Arguments
----------------|--------------|----------------
`objc_callIMP0` | id           | id, SEL
`objc_callIMP`  | id           | id, SEL, id
`objc_callIMP2` | id           | id, SEL, id, id


> #### Note
>
> Casting to BOOL should not be done like this
> `(BOOL) objc_callIMP( self, @selector( foo))`, since the
> compiler may potentially use the wrong bits .
> 

## Variable arguments

The various `va_list`, `va_start`functions and types are prefixed with `objc_`. These are to be used
instead of the `<stdarg.h>` counterparts for Objective-C functions accepting variable arguments
with `...` or `va_list`.

C functions will still use `<stdarg.h>`.

Note that `va_list` and `objc_va_list` are different types and not compatible!


## In memory instance allocation

If you are allocating instances "manually", you need to use these two functions
to convert from allocation to the instance and back:

Function               | Description
-----------------------|--------------
`objc_getInstance`     | Convert a block of memory to an object pointer
`object_getAlloc`      | Retrieve block of memory from the object pointer



## Stack allocation

See alloca(3) for the alloca semantics. objc_alloca is different though, the
alloca block, if it is too large to be put on the stack, will be allocated
with autorelease semantics instead.


Function        | Return Value | Arguments
----------------|--------------|----------------
`objc_alloca`   | void  *      | bytes to allocate.

To portably use alloca, there exists a function called `objc_alloca`, it is
supposed to do "the right thing", depending on platform. Since it may use
`NSMutableData`, you need this class defined somewhere.

