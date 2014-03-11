//
//  PBGitRepository.h
//  GitTest
//
//  Created by Pieter de Bie on 13-06-08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "PBGitRevList.h"
#import "PBGitRevSpecifier.h"
#import "PBGitConfig.h"

extern NSString* PBGitRepositoryErrorDomain;

@class PBGitWindowController;

@interface PBGitRepository : NSDocument {
	PBGitRevList* revisionList;
	PBGitConfig *config;

	BOOL hasChanged;
	NSMutableArray *__strong branches;
	PBGitRevSpecifier *__strong currentBranch;
	NSMutableDictionary *refs;

	PBGitRevSpecifier *_headRef; // Caching
}

- (NSFileHandle*) handleForCommand:(NSString*) cmd;
- (NSFileHandle*) handleForArguments:(NSArray*) args;
- (NSFileHandle *) handleInWorkDirForArguments:(NSArray *)args;
- (NSString*) outputForCommand:(NSString*) cmd;
- (NSString *)outputForCommand:(NSString *)str retValue:(int *)ret;
- (NSString *)outputForArguments:(NSArray *)arguments inputString:(NSString *)input retValue:(int *)ret;
- (NSString *)outputForArguments:(NSArray *)arguments inputString:(NSString *)input byExtendingEnvironment:(NSDictionary *)dict retValue:(int *)ret;


- (NSString*) outputForArguments:(NSArray*) args;
- (NSString*) outputForArguments:(NSArray*) args retValue:(int *)ret;
- (NSString *)outputInWorkdirForArguments:(NSArray*) arguments;
- (NSString *)outputInWorkdirForArguments:(NSArray*) arguments retValue:(int *)ret;
- (BOOL)executeHook:(NSString *)name output:(NSString **)output;
- (BOOL)executeHook:(NSString *)name withArgs:(NSArray*) arguments output:(NSString **)output;

- (NSString *)workingDirectory;
- (NSString *)gitIgnoreFilename;
- (BOOL)isBareRepository;

- (BOOL) reloadRefs;
- (void) addRef:(PBGitRef *)ref fromParameters:(NSArray *)params;
- (void) lazyReload;
- (PBGitRevSpecifier*) headRef;

- (void) readCurrentBranch;
- (PBGitRevSpecifier*) addBranch: (PBGitRevSpecifier*) rev;
- (BOOL)removeBranch:(PBGitRevSpecifier *)rev;

- (NSString*) parseSymbolicReference:(NSString*) ref;
- (NSString*) parseReference:(NSString*) ref;

+ (NSURL*)gitDirForURL:(NSURL*)repositoryURL;
+ (NSURL*)baseDirForURL:(NSURL*)repositoryURL;

- (id) initWithURL: (NSURL*) path;
- (void) setup;

@property (assign) BOOL hasChanged;
@property (readonly) PBGitWindowController *windowController;
@property (readonly) PBGitConfig *config;
@property (strong) PBGitRevList* revisionList;
@property (strong) NSMutableArray* branches;
@property (strong) PBGitRevSpecifier *currentBranch;
@property (strong) NSMutableDictionary* refs;
@end
