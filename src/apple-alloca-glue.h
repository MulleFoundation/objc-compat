#ifndef apple_alloca_glue_h__
#define apple_alloca_glue_h__


//
// A problem with this approach is, that the lifetime is tied to the
// autoreleasepool and not the stack frame.
//
#if DEBUG  // coz the stupid debugger trips up on alloca stack frames
# define objc_alloca( size)  [[NSMutableData dataWithLength:(size)] mutableBytes]
#else
# define objc_alloca( size)            \
  ( (size) <= (sizeof( double) * 32)   \
      ? alloca( (size))                \
      : [[NSMutableData dataWithLength:(size)] mutableBytes])
#endif

#endif
