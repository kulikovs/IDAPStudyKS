//
//  KSEnterprise.m
//  KSIdapStudy
//
//  Created by KulikovS on 09.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSEnterprise.h"

@protocol KSCarsWasherDelegate;

@interface KSEnterprise ()
@property (nonatomic, retain) KSCar *car;

@end

@implementation KSEnterprise

#pragma mark -
#pragma mark Initializations and Deallocations

-(void)dealloc {
    self.car = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Private Methods

- (void)carsWasher:(KSCarsWasher *)carsWasher сarIsPure:(KSCar *)car {
    [self removeCarFromEnterprise:car];
}

#pragma mark - 
#pragma mark Public Methods

- (void)addCarToWash:(KSCar *)car {
    if (car.isDirty) {
        self.car = car;
        [self.delegate enterprise:self washTheCar:car];
    }
}

- (void)removeCarFromEnterprise:(KSCar *)car {
    if (self.car == car) {
        self.car = nil;
    }
}

@end

