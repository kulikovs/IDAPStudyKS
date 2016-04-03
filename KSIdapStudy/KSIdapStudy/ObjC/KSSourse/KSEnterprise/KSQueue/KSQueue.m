//
//  KSQueue.m
//  KSIdapStudy
//
//  Created by KulikovS on 02.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSQueue.h"
#import "KSEmployee.h"

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

- (id)firstObject {
   return [self.queue firstObject];
}

- (void)addObjectToQueue:(id)object {
    @synchronized(self.queue) {
        [self.queue addObject:object];
    }
}

- (void)removeObjectFromQueue:(id)object {
    @synchronized(self.queue) {
        [self.queue removeObject:object];
    }
}

- (void)removeAllObjectsFromQueue {
    [self.queue removeAllObjects];
}

- (id)sendTheWorkFirstObjectFromQueue;{
    @synchronized(self.queue) {
        id object = [self.queue firstObject];
        if (object) {
            [self removeObjectFromQueue:object];
        } else {

        }
        
        return object;
    }
}

@end