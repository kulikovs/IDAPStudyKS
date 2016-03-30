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

@interface KSEnterprise ()
@property (nonatomic, retain) NSMutableArray *staff;
@property (nonatomic, retain) NSMutableArray *queueCars;

- (void)hireStaff;
- (void)dismissStaff;
- (void)dismissEmployee:(KSEmployee *)emlpoyee;
- (id)vacantEmployeeWithClass:(Class)class;

- (void)addCarToQueue:(KSCar*)car;

@end

@implementation KSEnterprise

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self dismissStaff];
    self.staff = nil;
    self.queueCars = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.queueCars = [NSMutableArray object];
        [self hireStaff];
    }
    
    return self;
}

#pragma mark -
#pragma mark Private Methods

- (void)hireStaff {
    KSBoss *boss = [KSBoss object];
    
    KSAccountant *accountant1 = [KSAccountant object];
    KSAccountant *accountant2 = [KSAccountant object];
    
    KSCarsWasher *carsWasher1 = [KSCarsWasher object];
    KSCarsWasher *carsWasher2 = [KSCarsWasher object];
    KSCarsWasher *carsWasher3 = [KSCarsWasher object];
    
//    [carsWasher addObserver:accountant];
//    [accountant addObserver:boss];

    self.staff = [[@[accountant1, accountant2, boss, carsWasher1, carsWasher2, carsWasher3]
                   mutableCopy] autorelease];
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

        [self.staff removeObject:object];
    }
}

- (id)vacantEmployeeWithClass:(Class)class {
    for (KSEmployee *employee in self.staff) {
        if ([employee isMemberOfClass:class] && employee.state == kKSWorkerStateFree) {
            
            return employee;
        }
    }
    
    return nil;
}

- (void)addCarToQueue:(KSCar*)car {
    [self.queueCars addObject:car];
}

#pragma mark -
#pragma mark Public Methods

- (void)washCar:(KSCar *)car {
   KSCarsWasher *carsWasher =  [self vacantEmployeeWithClass:[KSCarsWasher class]];
    [carsWasher performWorkWithObject:car];
}

@end

