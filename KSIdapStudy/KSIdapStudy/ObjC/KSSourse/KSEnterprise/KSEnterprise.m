//
//  KSEnterprise.m
//  KSIdapStudy
//
//  Created by KulikovS on 09.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSEnterprise.h"
#import "KSBoss.h"
#import "KSAccountant.h"
#import "KSCarsWasher.h"
#import "KSObserver.h"
#import "KSDispatcher.h"

static const NSUInteger kKSAccauntantsCount    = 2;
static const NSUInteger kKSBossCount           = 1;
static const NSUInteger kKSCarWasherCount      = 2;

@interface KSEnterprise ()
@property (nonatomic, retain) KSDispatcher      *bossDispatcher;
@property (nonatomic, retain) KSDispatcher      *carWashersDispatcher;
@property (nonatomic, retain) KSDispatcher      *accauntantsDispatcher;

- (void)hireStaff;
- (void)addHandlerForStateWaiting:(NSArray *)staff;

@end

@implementation KSEnterprise

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.bossDispatcher = nil;
    self.carWashersDispatcher = nil;
    self.accauntantsDispatcher = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        [self hireStaff];
    }
    
    return self;
}

#pragma mark -
#pragma mark Private Methods

- (void)hireStaff {
    NSArray *boss = [KSBoss objectsWithCount:kKSBossCount];
    self.bossDispatcher = [[[KSDispatcher alloc] initWithStaff:boss] autorelease];
    
    NSArray *accountants = [KSAccountant objectsWithCount:kKSAccauntantsCount];
    self.accauntantsDispatcher = [[[KSDispatcher alloc] initWithStaff:accountants] autorelease];
    
    NSArray *carWashers = [KSCarsWasher objectsWithCount:kKSCarWasherCount];
    self.carWashersDispatcher = [[[KSDispatcher alloc] initWithStaff:carWashers] autorelease];
    
    [self addHandlerForStateWaiting:accountants];
    [self addHandlerForStateWaiting:carWashers];
}

- (void)addHandlerForStateWaiting:(NSArray *)staff {
    @synchronized(self) {
        for (KSEmployee *employee in staff) {
            
            KSWeakSelf(KSEnterprise);
            [employee addHandler:^ {
                KSStrongSelf(KSEnterprise);
                [self workerIsWaiting:employee];
            }              state:kKSWorkerStateWaiting
                          object:self];
        }
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)washCar:(KSCar *)car {
    @synchronized(self) {
        [self.carWashersDispatcher addObject:car];
    }
}

#pragma mark -
#pragma mark Worker Protocol

- (void)workerIsWaiting:(KSEmployee *)employee {
    if ([self.accauntantsDispatcher containsObject:employee]) {
        [self.bossDispatcher addObject:employee];
    }
    
    if ([self.carWashersDispatcher containsObject:employee]) {
        [self.accauntantsDispatcher addObject:employee];
    }
}

@end