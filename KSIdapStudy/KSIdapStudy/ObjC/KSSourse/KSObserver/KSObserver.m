//
//  KSObserver.m
//  KSIdapStudy
//
//  Created by KulikovS on 15.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.

#import "KSObserver.h"
#import "KSObserverDictionary.h"

@interface KSObserver ()
@property (nonatomic, retain) NSMutableArray *observers;

@end

@implementation KSObserver

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.observers = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.observers = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (void)setState:(NSUInteger)state {
    @synchronized(self) {
        if (_state != state) {
            _state = state;
            
            for (KSObserverDictionary *observerDictionary in self.observers) {
                if (observerDictionary.state == state) {
                    for (KSObserverObject *observer in observerDictionary.arrayObject.handlers ) {
                        observer.handler();
                    }
                }
            }
        }
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)addHandler:(KSHandlerObject)handler state:(NSUInteger)state object:(id)object {
    [self removeHandlersForState:state];
    
    KSObserverDictionary *observerDictionary = [KSObserverDictionary object];
    [observerDictionary addHandler:handler state:state object:object];
    
    [self.observers addObject:observerDictionary];
}

- (void)removeHandlersForState:(NSUInteger)state {
    for (KSObserverDictionary *observerDictionary in self.observers) {
        if (observerDictionary.state == state) {
            [self.observers removeObject:observerDictionary];
        }
    }
}

- (void)removeHandlersForObject:(id)object {
    for (KSObserverDictionary *observerDictionary in self.observers) {
        [observerDictionary removeHandlersForObject:object];
    }
}

@end
