//
//  KSObserverArray.m
//  KSIdapStudy
//
//  Created by KulikovS on 13.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSObserverArray.h"

@interface KSObserverArray ()

@end

@implementation KSObserverArray

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.handlers = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.handlers = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark - 
#pragma mark Public Methods

- (void)addHandler:(KSHandlerObject)handler forObject:(id)object {
    KSObserverObject *observerObject = [[[KSObserverObject alloc] initWithObject:object
                                                                         handler:handler] autorelease];
    [self.handlers addObject:observerObject];
}

- (void)removeHandlersForObject:(id)object {
    NSArray *objects = [[self.handlers copy] autorelease];
    for (KSObserverObject *observerObject in objects) {
        if (observerObject.object == object) {
            [self.handlers removeObject:observerObject];
        }
    }
}

@end