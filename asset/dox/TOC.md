# objc-compat Library Documentation for AI
<!-- Keywords: objc, messaging, varargs, alloca, runtime, compatibility, glue -->

## 1. Introduction & Purpose

- objc-compat is a header-only compatibility "glue" library that exposes a small, portable Objective-C runtime API surface for different runtimes (Apple/clang runtime and MulleObjC).
- Solves portability issues when writing Objective-C code intended to compile against multiple runtimes by providing consistent inline functions and macros (message sends, IMP calls, varargs helpers, alloca semantics, and instance allocation helpers).
- Key features: runtime selection via macros, safe message-send wrappers, portable vararg traversal, stack/heap alloca userspace fallback, and helpers to convert between raw memory and ObjC objects.
- Relationship: Intended to be included into projects (via #import) and used alongside MulleObjC or Apple Objective-C runtime. Depends on MulleObjC when compiled for that runtime.

## 2. Key Concepts & Design Philosophy

- Header-only, compile-time dispatch: selects runtime specific glue headers depending on __MULLE_OBJC__ or __APPLE__.
- Provide small, explicit wrappers (objc_msgSendN, objc_callIMPN) to avoid direct casting of the raw runtime functions and to normalize return/argument handling across runtimes.
- Prefixing and macro indirection: all portable vararg functions/macros are named objc_* to avoid mixing with C varargs on non-ObjC callers.
- Small building blocks: prefer inline functions and macros to avoid runtime overhead and keep ABI stable.

## 3. Core API & Data Structures

### 3.1. [objc-compat.h]
- Purpose: Central include deciding which runtime-specific glue headers to include.
- Provides version helpers:
  - objc_compat_get_version_major(), objc_compat_get_version_minor(), objc_compat_get_version_patch()
- Behaviour: Includes mulle- or apple- prefixed glue headers depending on __MULLE_OBJC__ / __APPLE__.

### 3.2. [apple-message-glue.h] and [mulle-message-glue.h]
- Purpose: Provide stable, small-arity message send wrappers and IMP call wrappers.
- Message-send wrappers (inline functions):
  - objc_msgSend0(id self, SEL _cmd) -> id
  - objc_msgSend1(id self, SEL _cmd, id a) -> id
  - objc_msgSend2(... up to objc_msgSend5)
  - objc_msgSendBOOLReturn(id self, SEL _cmd, id a) -> BOOL
  - objc_msgSendIntReturn(id self, SEL _cmd, id a) -> int
- IMP call wrappers (inline):
  - objc_callIMP0(IMP imp, id self, SEL _cmd) -> id
  - objc_callIMP1..objc_callIMP5
  - objc_callIMPBOOLReturn, objc_callIMPIntReturn
- Broadcast helper:
  - objc_msgBroadcast(id *objects, count, SEL _cmd, id a) -- sends selector to array of objects.
- Notes: Apple glue casts objc_msgSend to function pointer of correct signature. Mulle glue delegates to MulleObjC runtime helpers (MulleObjCObjectPerformSelector* and MulleObjCIMPCall*).

### 3.3. [apple-vararg-glue.h] and [mulle-vararg-glue.h]
- Purpose: Portable traversal of Objective-C method variable arguments.
- Typedefs/macros:
  - typedef objc_va_list (va_list or mulle_vararg_list)
  - objc_va_start/objc_va_copy/objc_va_end
  - Accessors: objc_va_next_fp, objc_va_next_integer, objc_va_next_long_double, objc_va_next_object, objc_va_next_pointer, objc_va_next_struct, objc_va_next_union
  - Shortcuts: objc_va_next_char_pointer, objc_va_next_double, objc_va_next_id, objc_va_next_int
  - Selector convention macro: objcVarargList (expands to the appropriate name for selectors like initWithFormat:objcVarargList:)
- Important: objc_va_list is not the same as C va_list when using mulle-vararg; do not mix.

### 3.4. [apple-alloca-glue.h] and [mulle-alloca-glue.h]
- Purpose: Portable stack allocation helper objc_alloca(size)
- Semantics:
  - If size is small (<= 32 * sizeof(double)) uses alloca() (stack allocation).
  - If size is large, fall back to autoreleased heap allocation (NSMutableData or MulleObjC MulleObjCCallocAutoreleased), so lifetime ties to autoreleasepool rather than stack frame.
- Macro: objc_alloca(size) -> void * pointer with suitable lifetime.
- Caveat: Large allocations may live beyond the current stack frame; callers must be aware of autorelease pool semantics.

### 3.5. [apple-object-glue.h] and [mulle-object-glue.h]
- Purpose: Helpers when allocating instances manually in memory and converting between raw allocation and objective-c object pointer.
- Functions:
  - objc_getInstance(void *memory) -> id : convert raw allocation to object pointer (mulle variant inspects object header)
  - object_getAlloc(id obj) -> void * : get raw allocation pointer for an object
  - object_getExtraBytes(id obj) -> void * : pointer to extra bytes after instance body
- Additional helpers (apple version): MulleObjCCopyObjects and MulleObjCCopyObjectArray for legacy convenience; they iterate va_list style lists.

## 4. Performance Characteristics

- All API glue is inline macros/functions; cost is a single function-call or an optimized casted call. Typical performance: O(1) for message wrappers and IMP calls.
- objc_alloca: O(1) but large allocations may allocate on heap (autoreleased) — trade-off between stack safety and heap allocation.
- Vararg traversal: O(n) per argument traversal; relies on underlying va_list or mulle-vararg implementation.
- Thread-safety: The wrappers themselves are stateless and thread-safe. Autorelease-based fallbacks rely on runtime autorelease pool semantics; ensure pools are present when using objc_alloca fallback allocations.

## 5. AI Usage Recommendations & Patterns

- Always #import <objc-compat/objc-compat.h> (or the public header) rather than #include to ensure Foundation headers are present first.
- Use the provided small-arity message wrappers instead of casting raw objc_msgSend; they avoid signature mismatches and undefined behaviour.
- Use objcVarargList when declaring/forwarding Objective-C variadic methods to ensure selector names match the runtime expectation.
- Be careful with BOOL returns: cast using (BOOL)(intptr_t) or use objc_msgSendBOOLReturn/objc_callIMPBOOLReturn to avoid bitwidth mismatches.
- Do not mix objc_va_list (objc-compat) with plain C va_list when using mulle-vararg backend.
- Prefer inline helpers for instance allocation and extra-byte calculation rather than manual pointer arithmetic.

## 6. Integration Examples

### Example 1: Sending a selector with one argument

```c
// Objective-C function style example
- (id) forwardTo: (id)target
       selector: (SEL) sel
       argument: (id)arg
{
   return( objc_msgSend1( target, sel, arg));
}
```

### Example 2: Using objc_alloca for temporary buffer

```c
void  use_temporary( size_t n)
{
   void  *p;

   p = objc_alloca( n);
   /* use p for n bytes; if n large this may be autoreleased */
}
```

### Example 3: Traversing Objective-C varargs in a method

```objc
- (void) process: (id)first, ...
objcVarargList:(objc_va_list) args
{
   id      obj;

   obj = objc_va_next_id( args);
   while( obj)
   {
      // handle obj
      obj = objc_va_next_id( args);
   }
}

- (void) process: (id)first, ...
{
   objc_va_list  args;

   objc_va_start( args, first);
   [self process: first objcVarargList: args];
   objc_va_end( args);
}
```

## 7. Dependencies

- MulleObjC (when compiling with __MULLE_OBJC__)
- mulle-objc-compat (compat layer used for Apple-like runtime compatibility in some builds)


---

References:
- README.md (project overview and API summary)
- src/*-glue.h (runtime-specific inline glue headers)

