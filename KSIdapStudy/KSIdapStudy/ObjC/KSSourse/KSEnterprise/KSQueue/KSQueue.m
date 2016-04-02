//
//  KSQueue.m
//  KSIdapStudy
//
//  Created by KulikovS on 02.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSQueue.h"

@implementation KSQueue

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.queue = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.queue = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)addObjectToQueue:(id)object {
    [self.queue addObject:object];
}
- (void)removeObjectFromQueue:(id)object {
    [self.queue removeObject:object];
}

- (id)firstObject {
    return [self.queue firstObject];
}

- (void)removeAllObjectsFromQueue {
    [self.queue removeAllObjects];
}

@end