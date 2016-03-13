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

@end

@implementation KSEmployee

@synthesize money = _money;
@synthesize workerState = _workerState;

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

#pragma mark -
#pragma mark Public Methods

- (void)performWithObject:(id)object {
    self.workerState = kKSWorkerStateBusy;
    [self takeMoney:[object giveMoney]];
    self.workerState = kKSWorkerStateFree;
    
    if (self.delegate) {
        [self.delegate workerDidFinishWork:self];
    }
}

@end
