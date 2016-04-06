//
//  KSQueue.m
//  KSIdapStudy
//
//  Created by KulikovS on 02.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSQueue.h"
#import "KSEmployee.h"

@interface KSQueue ()
@property (nonatomic, retain) NSMutableArray *queueArray;

@end

@implementation KSQueue

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self.queueArray removeAllObjects];
    self.queueArray = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.queueArray = [NSMutableArray array];
    }
    
    return self;
}
#pragma mark -
#pragma mark Accessors

- (NSArray *)queue {
    return [[self.queueArray copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)addObjectToQueue:(id)object {
    @synchronized(self) {
        [self.queueArray addObject:object];
    }
}

- (void)removeObjectFromQueue:(id)object {
    @synchronized(self) {
        [self.queueArray removeObject:object];
    }
}

- (void)removeAllObject {
    [self.queueArray removeAllObjects];
}

- (id)sendTheWorkFirstObjectFromQueue;{
    @synchronized(self) {
        id object = [self.queue firstObject];
        if (object) {
            [self removeObjectFromQueue:object];
        }
        
        return object;
    }
}

@end