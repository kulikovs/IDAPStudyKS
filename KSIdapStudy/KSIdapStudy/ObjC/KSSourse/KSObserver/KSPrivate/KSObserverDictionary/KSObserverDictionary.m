//
//  KSObserverDictionary.m
//  KSIdapStudy
//
//  Created by KulikovS on 13.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSObserverDictionary.h"

@interface KSObserverDictionary ()

@end

@implementation KSObserverDictionary

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.arrayObject = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.arrayObject = [KSObserverArray object];
    }
    
    return self;
}

#pragma mark -
#pragma mark - Public Methods

- (void)addHandler:(KSHandlerObject)handler state:(NSUInteger)state object:(id)object {
    KSObserverArray *observerArray = [KSObserverArray object];
    [observerArray addHandler:handler forObject:object];
    self.state = state;
    self.arrayObject = observerArray;
}

- (void)removeHandlersForObject:(id)object {
    [self.arrayObject removeHandlersForObject:object];
}

@end