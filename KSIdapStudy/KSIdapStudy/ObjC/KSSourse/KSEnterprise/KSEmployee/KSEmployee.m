//
//  KSEmployee.m
//  KSIdapStudy
//
//  Created by KulikovS on 09.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSEmployee.h"

@interface KSEmployee ()
@property (nonatomic, assign) KSWorkerState state;

- (void)performWithObject:(id)object;
- (void)completeWorkingWithObject:(KSEmployee *)object;
- (void)finishWork;

@end

@implementation KSEmployee

@synthesize state = _state;
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

- (void)setState:(KSWorkerState)state {
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
    self.state = kKSWorkerStateFree;
    [self completeWorkingWithObject:object];
    
   // [self finishWork];
}

#pragma mark -
#pragma mark Private Methods

- (void)completeWorkingWithObject:(KSEmployee *)object {
    object.state = kKSWorkerStateFree;
}

- (void)finishWork {

    [self workerDidFinishWork:self];
}

#pragma mark -
#pragma mark Observer Methods

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case kKSWorkerStateBusy:
            return [super selectorForState:state];
            
        case kKSWorkerStateFree:
            return @selector(finishWork);
        
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

- (void)workerDidFinishWork:(id<KSMoneyProtocol>)object {
    [self performWithObject:object];
}

@end
