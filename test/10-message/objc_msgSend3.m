#import <objc-compat/objc-compat.h>

#include <stdio.h>
#include <stdint.h>


@implementation Foo 

+ (Class) class 
{
	return( self);
}


+ (id) tag:(char *) tag
	  name:(char *) name
	  year:(uintptr_t) year
{
	printf( "%s %s %td\n", tag, name, year);
	return( (id) 0x1848);
}


+ (id) foo 
{
	return( (id) ~0xFF);  // tricky, what is it ? LSB is zero!
}

@end 


int   main( void)
{
	id   obj;
	
	obj = objc_msgSend3( [Foo class], @selector( tag:name:year:), (id) "VfL", (id) "Bochum", (id) 1848);
	printf( "%tx\n", (intptr_t) obj);
	if( obj != (id) 0x1848)
		return( 1);
	return( 0);
}

