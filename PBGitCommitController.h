//
//  PBGitCommitController.h
//  GitX
//
//  Created by Pieter de Bie on 19-09-08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "PBViewController.h"

@class PBGitIndexController, PBIconAndTextCell, PBWebChangesController, PBGitIndex;

@interface PBGitCommitController : PBViewController {
	PBGitIndex *index;
	
	IBOutlet NSTextView *commitMessageView;
	IBOutlet NSArrayController *unstagedFilesController;
	IBOutlet NSArrayController *cachedFilesController;

	IBOutlet PBGitIndexController *indexController;
	IBOutlet PBWebChangesController *webController;

	NSString *status;

	NSDictionary *amendEnvironment;

}

@property(copy) NSString *status;
@property(readonly) PBGitIndex *index;

// FIXME: redo 0823ff859dc65db238951c16e49293ea411c2b5a
- (IBAction) refresh:(id) sender;
- (IBAction) commit:(id) sender;
- (IBAction)signOff:(id)sender;
@end
