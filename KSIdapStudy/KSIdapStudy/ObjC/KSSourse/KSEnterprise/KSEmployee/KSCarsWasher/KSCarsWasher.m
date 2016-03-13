//
//  KSCarsWasher.m
//  KSIdapStudy
//
//  Created by KulikovS on 13.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSCarsWasher.h"

@implementation KSCarsWasher

#pragma mark
#pragma mark Private Method

- (void)performWithObject:(KSCar *)car {
    if (car.money >= 100) {
        [super performWithObject:car];
        car.carState = kKSCarStateClean;
    }
}

@end
