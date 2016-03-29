//
//  KSObserver.m
//  KSIdapStudy
//
//  Created by KulikovS on 15.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSObserver.h"

@interface KSObserver ()
@property (nonatomic, retain) NSHashTable    *mutableObservers;

@end

@implementation KSObserver
@dynamic observers;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableObservers = nil;
    self.handlerDictionary = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableObservers = [NSHashTable weakObjectsHashTable];
        self.handlerDictionary = [NSMutableDictionary dictionary];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)observers {
    return [self.mutableObservers allObjects];
}

#pragma mark -
#pragma mark Public Methods

- (void)addObserver:(id)observer {
    [self.mutableObservers addObject:observer];
}

- (void)removeObserver:(id)observer {
    [self.mutableObservers removeObject:observer];
}

- (BOOL)isObservedByObject:(id)object {
    return [self.mutableObservers containsObject:object];
}

- (SEL)selectorForState:(NSUInteger)state {
    return nil;
}

- (void)notifyObserver {
    [self notifyObjectWithSelector:[self selectorForState:self.state]];
}

- (void)notifyObjectWithSelector:(SEL)selector {
    NSHashTable *mutableObservers = self.mutableObservers;
    for (id observer in mutableObservers) {
        if ([observer respondsToSelector:selector]) {
            [observer performSelector:selector withObject:self];
        }
    }
}

@end
