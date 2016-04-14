//
//  KSObserver.m
//  KSIdapStudy
//
//  Created by KulikovS on 15.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.

#import "KSObserver.h"
#import "KSObserverObject.h"
#import "KSObserverDictionary.h"
#import "KSObserverArray.h"

@interface KSObserver ()
@property (nonatomic, retain)     NSMutableArray    *observers;

- (void)performHandlersForState:(NSUInteger)state;
- (KSObserverDictionary *)dictionaryWithState:(NSUInteger)state;

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
            
            [self performHandlersForState:state];
        }
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)addHandler:(KSHandlerObject)handler state:(NSUInteger)state object:(id)object {
    if (object) {
        KSObserverDictionary *observerDictionary = [self dictionaryWithState:state];
        
        [observerDictionary addHandler:handler object:object];
        [self.observers addObject:observerDictionary];
    }
}

- (void)removeHandlersForState:(NSUInteger)state {
    KSObserverDictionary *dictionary = [self dictionaryWithState:state];
    [self.observers removeObject:dictionary];
}

- (void)removeHandlersForObject:(id)object {
    for (KSObserverDictionary *observerDictionary in self.observers) {
        [observerDictionary removeHandlersForObject:object];
    }
}

#pragma mark -
#pragma mark Private Methods

- (KSObserverDictionary *)dictionaryWithState:(NSUInteger)state {
    for (KSObserverDictionary *observerDictionary in self.observers) {
        if (observerDictionary.state == state) {
            return observerDictionary;
        }
    }
    
    return [KSObserverDictionary dictionaryWithState:state];
}

- (void)performHandlersForState:(NSUInteger)state {
    KSObserverDictionary *observerDictionary = [self dictionaryWithState:state];
    for (KSHandlerObject handler in observerDictionary.handlers) {
        handler();
    }
}

@end