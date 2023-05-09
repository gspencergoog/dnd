//
//  ViewController.m
//  File Dropper
//
//  Created by Greg Spencer on 5/2/23.
//

#import "ViewController.h"

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];

  // Do any additional setup after loading the view.
}


- (void)setRepresentedObject:(id)representedObject {
  [super setRepresentedObject:representedObject];

  // Update the view, if already loaded.
}

- (void)window:(NSWindow *)window didBecomeKey:(NSNotification *)notification {
    // Enable file dropping on the window
    [window registerForDraggedTypes:@[NSPasteboardTypeString, NSPasteboardTypePDF, NSPasteboardTypeTIFF, NSPasteboardTypePNG, NSPasteboardTypeRTF, NSPasteboardTypeRTFD, NSPasteboardTypeHTML, NSPasteboardTypeTabularText, NSPasteboardTypeFont, NSPasteboardTypeRuler, NSPasteboardTypeColor, NSPasteboardTypeSound, NSPasteboardTypeMultipleTextSelection, NSPasteboardTypeTextFinderOptions, NSPasteboardTypeURL, NSPasteboardTypeFileURL]];
    NSLog(@"Registered for drags");
}

- (NSDragOperation)draggingEntered:(id <NSDraggingInfo>)sender {
    // Allow files to be copied to the window
    NSLog(@"Dragging Entered");
    return NSDragOperationEvery;
}

- (BOOL)window:(NSWindow *)window shouldDragDocumentWithEvent:(NSEvent *)event from:(id<NSDraggingInfo>)source {
  NSLog(@"Should Drag?");
    return YES;
}

- (BOOL)performDragOperation:(id <NSDraggingInfo>)sender {
    // Check if the dragged items are of the expected type
    NSPasteboard *pboard = [sender draggingPasteboard];
    NSArray *classes = @[[NSURL class]];
    NSDictionary *options = @{NSPasteboardURLReadingFileURLsOnlyKey : @YES};
    NSArray *urls = [pboard readObjectsForClasses:classes options:options];
    if ([urls count] == 0) {
      NSLog(@"No URLs Found");
      return NO;
    }

    // Retrieve the URL of the first dragged item and print its path
    NSURL *url = urls[0];
    NSLog(@"%@", [url path]);

    return YES;
}

@end
