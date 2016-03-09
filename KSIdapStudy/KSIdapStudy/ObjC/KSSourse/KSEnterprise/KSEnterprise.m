//
//  KSEnterprise.m
//  KSIdapStudy
//
//  Created by KulikovS on 09.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSEnterprise.h"

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
#pragma mark Class Methods Public

- (void)addCarToWash:(KSCar *)car {
    if (car.isDirty) {
        self.car = car;
        [self.delegate enterprise:self washTheCar:car];
    }
}

@end

