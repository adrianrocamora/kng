#import <Foundation/Foundation.h>
#import <ApplicationServices/ApplicationServices.h>

int main(int argc, char *argv[]) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	NSUserDefaults *args = [NSUserDefaults standardUserDefaults];

	int x = [args integerForKey:@"x"];
	int y = [args integerForKey:@"y"];

    CGPoint pt;
    //pt.x = x;
    //pt.y = y;
    pt.x = 100;
    pt.y = 100;

	//CGPostMouseEvent( pt, 1, 1, 1 );
	//CGPostMouseEvent( pt, 1, 1, 0 );
	CGPostKeyboardEvent( (CGCharCode)0, (CGKeyCode)41, true );		// - : key down
	CGPostKeyboardEvent( (CGCharCode)0, (CGKeyCode)41, false );		// - : key up

	CGPostKeyboardEvent( (CGCharCode)0, (CGKeyCode)49, true );		// - SPACE down
	CGPostKeyboardEvent( (CGCharCode)0, (CGKeyCode)49, false );		// - SPACE up

	CGPostKeyboardEvent( (CGCharCode)0, (CGKeyCode)41, true );		// - : key down
	CGPostKeyboardEvent( (CGCharCode)0, (CGKeyCode)41, false );		// - : key up

	[pool release];
    return 0;
}

