//
//  KSArrayModelManager.m
//  KSIdapStudy
//
//  Created by KulikovS on 22.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSArrayModelManager.h"
#import "KSStringModel.h"

static NSString * const kKSSaveArrayModelKey = @"saveArrayModel.plist";

@interface KSArrayModelManager ()
@property (nonatomic, readonly) NSString    *path;

- (void)addObserverWithKeys:(NSArray *)keys;

@end

@implementation KSArrayModelManager

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        NSArray *array = @[UIApplicationDidEnterBackgroundNotification,
                           UIApplicationWillTerminateNotification];
        [self addObserverWithKeys:array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSString *)path {
    return [NSFileManager pathToFileInDocumentsWithName:kKSSaveArrayModelKey];
}

#pragma mark -
#pragma mark Private Methods

- (void)addObserverWithKeys:(NSArray *)keys {
    for (NSString *key in keys) {
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(save)
                                                     name:key
                                                   object:nil];
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)prepareToLoad {
    sleep(3);
    
    KSArrayModel *model = [NSKeyedUnarchiver unarchiveObjectWithFile:self.path];
    model = model ? model : [KSArrayModel arrayModelWithObjects:[KSStringModel randomStringsModels]];
    [self addObjects:model.objects];
}

- (void)finishLoading {
    self.state = kKSModelStateLoaded;
}

- (void)save {
    [NSKeyedArchiver archiveRootObject:self toFile:self.path];
}

@end
