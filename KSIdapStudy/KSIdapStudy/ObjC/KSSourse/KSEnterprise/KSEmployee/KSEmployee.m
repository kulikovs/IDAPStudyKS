//
//  KSEmployee.m
//  KSIdapStudy
//
//  Created by KulikovS on 09.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSEmployee.h"
#import "KSQueue.h"

@interface KSEmployee ()
@property (nonatomic, retain) KSQueue *queue;

- (void)completeWorkingWithObject:(id)object;
- (void)completeWorking;
- (void)performWorkWithObjectInBackground:(id<KSMoneyProtocol>)object;

@end

@implementation KSEmployee

@synthesize money = _money;

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)init {
    self = [super init];
    if (self) {
        self.state = kKSWorkerStateFree;
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)performWorkWithObject:(id<KSMoneyProtocol>)object {
    @synchronized(self) {
        if (object && self.state == kKSWorkerStateFree) {
            self.state = kKSWorkerStateBusy;
            [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:)
                                   withObject:object];
        }
    }
}

#pragma mark -
#pragma mark Private Methods

- (void)performWorkWithObjectInBackground:(id<KSMoneyProtocol>)object {
    @synchronized(self) {
        usleep(arc4random_uniform(10000) + 1);
        
        [self takeMoney:[object giveMoney]];
        [self completeWorkingWithObject:object];
        
        [self performSelectorOnMainThread:@selector(completeWorking) withObject:nil waitUntilDone:NO];
    }
}

- (void)completeWorkingWithObject:(id)object {
        KSEmployee *emloyee = (KSEmployee *)object;
        emloyee.state = kKSWorkerStateFree;
}

- (void)completeWorking {
    self.state = kKSWorkerStateWaiting;
}

#pragma mark -
#pragma mark Money Protocol

- (NSUInteger)giveMoney {
    @synchronized(self) {
        NSUInteger money = self.money;
        self.money = 0;
        return money;
    }
}

- (void)takeMoney:(NSUInteger)money {
    @synchronized(self) {
        self.money += money;
    }
}

@end