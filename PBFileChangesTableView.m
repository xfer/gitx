//
//  PBFileChangesTableView.m
//  GitX
//
//  Created by Pieter de Bie on 09-10-08.
//  Copyright 2008 Pieter de Bie. All rights reserved.
//

#import "PBFileChangesTableView.h"
#import "PBGitIndexController.h"

@implementation PBFileChangesTableView

#pragma mark NSTableView overrides
- (NSMenu *)menuForEvent:(NSEvent *)theEvent
{
	if ([self delegate]) {
		NSPoint eventLocation = [self convertPoint: [theEvent locationInWindow] fromView: nil];
		NSInteger rowIndex = [self rowAtPoint:eventLocation];
		[self selectRowIndexes:[NSIndexSet indexSetWithIndex:rowIndex] byExtendingSelection:TRUE];
        NSObject *delegate = [self delegate];
        if ([delegate isKindOfClass:[PBGitIndexController class]]) {
            PBGitIndexController *controller = (PBGitIndexController *)delegate;
            return [controller menuForTable:self];
        }
        NSLog(@"[[self delegate] menuForTable: self] == not found =( ");
		return nil;
	}

	return nil;
}

- (NSDragOperation) draggingSourceOperationMaskForLocal:(BOOL) local
{
	return NSDragOperationEvery;
}

@end
