//
//  KSEmployee.m
//  KSIdapStudy
//
//  Created by KulikovS on 09.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSEmployee.h"

@interface KSEmployee ()

- (void)performWithObject:(id)object;
- (void)completeWorkingWithObject:(KSEmployee *)object;
- (void)finishWork;

@end

@implementation KSEmployee

@synthesize money = _money;
@synthesize workerState = _workerState;

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)init {
    self = [super init];
    if (self) {
        self.workerState = kKSWorkerStateFree;
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)performWithObject:(id)object {
    self.workerState = kKSWorkerStateBusy;
    
    [self takeMoney:[object giveMoney]];
    
    [self completeWorkingWithObject:object];
    
    [self finishWork];

}

#pragma mark -
#pragma mark Private Methods

- (void)completeWorkingWithObject:(KSEmployee *)object {
    object.workerState = kKSWorkerStateFree;
}

- (void)finishWork {
    if (self.delegate) {
        [self.delegate workerDidFinishWork:self];
    }
}

#pragma mark -
#pragma mark Money Protocol

- (NSUInteger)giveMoney {
    NSUInteger money = self.money;
    self.money = 0;
    
    return money;
}


- (void)takeMoney:(NSUInteger)money {
    self.money += money;
}

#pragma mark -
#pragma mark Worker Protocol

- (void)workerDidFinishWork:(id<KSMoneyProtocol>)object {
    [self performWithObject:object];
}

@end
