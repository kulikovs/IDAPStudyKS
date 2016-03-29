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
    
    [carsWasher addHandlerForState:^{
        [accountant performWorkWithObject:carsWasher];}
                             state:kKSWorkerStateWaiting];
    
    [accountant addHandlerForState:^{
        [boss performWorkWithObject:accountant];}
                             state:kKSWorkerStateWaiting];
    
    self.staff = [[@[accountant, boss, carsWasher] mutableCopy] autorelease];
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
        
        [object.handlerDictionary removeAllObjects];
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

#pragma mark -
#pragma mark Public Methods

- (void)washCar:(KSCar *)car {
   KSCarsWasher *carsWasher =  [self vacantEmployeeWithClass:[KSCarsWasher class]];
    [carsWasher performWorkWithObject:car];
}

@end

