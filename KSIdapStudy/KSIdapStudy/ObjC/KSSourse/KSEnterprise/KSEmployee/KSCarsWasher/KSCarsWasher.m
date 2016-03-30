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

- (void)completeWorkingWithObject:(KSCar *)car {
    sleep(arc4random_uniform(3) + 1);
    car.carState = kKSCarStateClean;
}

@end
