# objc-compat

🔗 Glue for Objective-C code to support different runtimes

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

Message sending in most cases should be done by the compiler with `[]` as the
compiler knows how to handle mulle-objc messaging. You need to be sure that
the argument on the receiver side is `id` size, otherwise things break.
So any id or pointer arguments is fine. You should only call methods that
use these argument and return type exclusively:

NSInteger | is defined as `intptr_t`
NSUInteger| which is defined as `uintptr_t`
id        | or any other Objective-C instance
void *    | any pointer that can be casted to void * (not function pointers!)

As an exception to the rule, there are two functions that return BOOL instead
of id:

These are the defined message functions:

Function                   | Return Value | Arguments
---------------------------|--------------|----------------
`objc_msgSend0`            | id           | id, SEL
`objc_msgSend`             | id           | id, SEL, id
`objc_msgSend2`            | id           | id, SEL, id, id
`objc_msgSend3`            | id           | id, SEL, id, id, id
`objc_msgSend4`            | id           | id, SEL, id, id, id, id
`objc_msgSend5`            | id           | id, SEL, id, id, id, id, id
`objc_msgSendBOOLReturn`   | BOOL         | id, SEL, id
`objc_msgSendIntReturn`    | int          | id, SEL, id

These are the defined IMP calls:

Function                | Return Value | Arguments
------------------------|--------------|----------------
`objc_callIMP0`         | id           | id, SEL
`objc_callIMP`          | id           | id, SEL, id
`objc_callIMP2`         | id           | id, SEL, id, id
`objc_callIMP3`         | id           | id, SEL, id, id, id
`objc_callIMP4`         | id           | id, SEL, id, id, id, id
`objc_callIMP5`         | id           | id, SEL, id, id, id, id, id
`objc_callIMPIntReturn` | int          | id, SEL, id


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

Function            | Description
--------------------|--------------
`objc_getInstance`  | Convert a block of memory to an object pointer
`object_getAlloc`   | Retrieve block of memory from the object pointer


Here is how to determine the location of extra bytes:

```
static void  get_extra_bytes( id self)
{
   size_t    size;
   id        alloc;

   size  = class_getInstanceSize( object_getClass( self));
   alloc = object_getAlloc( self);
   return( (void *) &((char *) alloc)[ size]);
}
```



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

