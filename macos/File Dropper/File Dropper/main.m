//
//  main.m
//  File Dropper
//
//  Created by Greg Spencer on 5/2/23.
//

#import <Cocoa/Cocoa.h>

#import "AppDelegate.h"

//int main(int argc, const char * argv[]) {
//  @autoreleasepool {
//      // Setup code that might create autoreleased objects goes here.
//  }
//  return NSApplicationMain(argc, argv);
//}

int main(int argc, const char * argv[]) {
    NSApplication *application = [NSApplication sharedApplication];
    AppDelegate *appDelegate = [[AppDelegate alloc] init];
    [application setDelegate:appDelegate];
    [application run];
    return 0;
}
