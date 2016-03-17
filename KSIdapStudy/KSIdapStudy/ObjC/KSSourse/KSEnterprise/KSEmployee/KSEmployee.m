//
//  KSEmployee.m
//  KSIdapStudy
//
//  Created by KulikovS on 09.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSEmployee.h"

@interface KSEmployee ()

- (void)completeWorkingWithObject:(KSEmployee *)object;
- (void)completeWorking;

@end

@implementation KSEmployee

@synthesize money = _money;
@synthesize state = _state;

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
#pragma mark Accessors

- (void)setState:(NSUInteger)state {
    if (_state != state) {
        _state = state;
        
        [self notifyObserver];
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)performWithObject:(id)object {
    self.state = kKSWorkerStateBusy;

    [self takeMoney:[object giveMoney]];
    
    [self completeWorkingWithObject:object];
    
    [self completeWorking];
}

#pragma mark -
#pragma mark Private Methods

- (void)completeWorkingWithObject:(KSEmployee *)object {
    object.state = kKSWorkerStateFree;
}

- (void)completeWorking {
    self.state = kKSWorkerStateWaiting;
}

#pragma mark -
#pragma mark Observer Method

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case kKSWorkerStateBusy:
            return @selector(workerStartedWork:);
            
        case kKSWorkerStateFree:
            return @selector(workerBecameFree:);
            
        case kKSWorkerStateWaiting:
            return @selector(workerFinishedWork:);
        
        default:
            return [super selectorForState:state];
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

- (void)workerFinishedWork:(id<KSMoneyProtocol>)object {
    [self performWithObject:object];
}

- (void)workerStartedWork:(id<KSMoneyProtocol>)object {

}

- (void)workerBecameFree:(id<KSMoneyProtocol>)object {

}

@end
