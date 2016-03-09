//
//  KSCarsWasher.m
//  KSIdapStudy
//
//  Created by KulikovS on 09.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSCarsWasher.h"

@implementation KSCarsWasher

#pragma mark -
#pragma mark KSEnterpriseDelegete

- (void)enterprise:(KSEnterprise *)enterprise washTheCar:(KSCar *)car {
    car.isDirty = NO;
    self.money = [car payMoney:100];
    
    [self.delegate carsWasher:self carIsPure:car];
}

@end

