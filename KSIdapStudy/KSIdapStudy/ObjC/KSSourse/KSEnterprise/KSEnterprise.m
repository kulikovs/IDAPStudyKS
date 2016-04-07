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

@interface KSEnterprise ()
@property (nonatomic, retain) NSMutableArray    *staff;
@property (nonatomic, retain) KSDispatcher      *carsDispatcher;
@property (nonatomic, retain) KSDispatcher      *carWashersDispatcher;
@property (nonatomic, retain) KSDispatcher      *accauntentsDispatcher;

- (void)hireStaff;
- (void)dismissStaff;
- (void)dismissEmployee:(KSEmployee *)emlpoyee;

@end

@implementation KSEnterprise

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self dismissStaff];
    self.staff = nil;
    self.carsDispatcher = nil;
    self.carWashersDispatcher = nil;
    self.accauntentsDispatcher = nil;

    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        [self hireStaff];
        self.carWashersDispatcher = [KSDispatcher object];
        self.carsDispatcher = [KSDispatcher object];
        self.accauntentsDispatcher = [KSDispatcher object];
    }
    
    return self;
}

#pragma mark -
#pragma mark Private Methods

- (void)hireStaff {
    
    KSBoss *boss = [KSBoss object];
    
    NSArray *accountants = [KSAccountant employeesWithCount:2 observers:self;

    
    NSArray *carWashers = [KSCarsWasher employeesWithCount:3 observer:];
    self.staff = [NSMutableArray arrayWithObjects:accountant, accountant1, boss, nil];
    
    [self.staff addObjectsFromArray:carWashers];
}

- (void)dismissStaff {
    NSArray *staff = [[self.staff copy] autorelease];
    
    for (KSEmployee *employee in staff) {
        [self dismissEmployee:employee];
    }
}

- (void)dismissEmployee:(KSEmployee *)object {
    for (NSUInteger index = 0; index < self.staff.count; index++) {
        KSEmployee *employee = self.staff[index];
        if ([employee isObservedByObject:object]) {
            [employee removeObserver:object];
        }
    }
    
    [self.staff removeObject:object];
}

#pragma mark -
#pragma mark Public Methods

- (void)washCar:(KSCar *)car {
    @synchronized(self) {
        [self.carsDispatcher addObject:car];
    }
}

#pragma mark -
#pragma mark Worker Protocol

- (void)workerFinishedWork:(KSEmployee *)employee {
    @synchronized(self) {
        if ([employee isMemberOfClass:[KSCarsWasher class]]) {
            [self.carWashersDispatcher addObject:employee];
        }
        
        if ([employee isMemberOfClass:[KSAccountant class]]) {
            [self.accauntentsDispatcher addObject:employee];
        }
        
        if ([employee isMemberOfClass:[KSCar class]]) {
            [self.carsDispatcher addObject:employee];
        }
    }
}


@end