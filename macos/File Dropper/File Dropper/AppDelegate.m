//
//  AppDelegate.m
//  File Dropper
//
//  Created by Greg Spencer on 5/2/23.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@property (nonatomic, strong) NSWindow *window;

@end

@implementation AppDelegate

- (void)applicationWillTerminate:(NSNotification *)aNotification {
  // Insert code here to tear down your application
}

- (BOOL)applicationSupportsSecureRestorableState:(NSApplication *)app {
  return YES;
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Create the main window
    self.window = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, 400, 300)
                                              styleMask:NSWindowStyleMaskTitled|NSWindowStyleMaskClosable|NSWindowStyleMaskMiniaturizable|NSWindowStyleMaskResizable
                                                backing:NSBackingStoreBuffered
                                                  defer:NO];
    [self.window setTitle:@"File Dropper"];
    [self.window setDelegate:self];
    [self.window makeKeyAndOrderFront:self];
    NSLog(@"Finished Launching");
}

- (BOOL)application:(NSApplication *)app handleOpenURL:(NSURL *)url {
  // Check the type of the dropped object.

  NSLog(@"%@", [url path]);
  return YES;
}


@end
