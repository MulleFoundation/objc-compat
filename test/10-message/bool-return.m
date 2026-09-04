#import <objc-compat/objc-compat.h>

#include <stdio.h>
#include <stdint.h>


@implementation Foo 

+ (Class) class 
{
	return( self);
}

+ (BOOL) bar:(id) value 
{
	return( value == (id) 1848 ? YES : NO);
}

+ (id) foo 
{
	return( (id) ~0xFF);  // tricky, what is it ? LSB is zero!
}

@end 


int   main( void)
{
	BOOL   flag;
	
	flag = objc_msgSendBOOLReturn( [Foo class], @selector( bar:), (id) 1848);
	fprintf( stderr, "%tx\n", (intptr_t) flag);
	if( flag != YES)
		return( 1);

	// this works when BOOL is char
	flag = objc_msgSendBOOLReturn( [Foo class], @selector( foo), (id) 1848);
	fprintf( stderr, "%tx\n", (intptr_t) flag);
	if( flag)
		return( 2);
	return( 0);
}

