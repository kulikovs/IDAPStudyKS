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

- (void)hireStaff;
- (void)dismissStaff;
- (void)dismissEmployee:(KSEmployee *)emlpoyee;
- (id)vacantEmployeeWithClass:(Class)class;

@end

@implementation KSEnterprise

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self dismissStaff];
    self.staff = nil;
    
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
    KSAccountant *accountant = [KSAccountant object];
    KSBoss *boss = [KSBoss object];
    KSCarsWasher *carsWasher = [KSCarsWasher object];
    
    [carsWasher addObserver:accountant];
    [accountant addObserver:boss];
    
    self.staff = [@[accountant, boss, carsWasher] mutableCopy];
}

- (void)dismissStaff {
    [self.staff removeAllObjects];
}

- (id)vacantEmployeeWithClass:(Class)class {
    for (KSEmployee *employee in self.staff) {
        if ([employee isMemberOfClass:class] && employee.state == kKSWorkerStateFree) {
            return employee;
        }
    }
    
    return nil;
}

#pragma mark -
#pragma mark Public Methods

- (void)washCar:(KSCar *)car {
   KSCarsWasher *carsWasher =  [self vacantEmployeeWithClass:[KSCarsWasher class]];
    [carsWasher performWithObject:car];
}

@end

