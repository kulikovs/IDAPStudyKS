//
//  KSCar.m
//  KSIdapStudy
//
//  Created by KulikovS on 09.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSCar.h"

static const NSUInteger carCash = 100;

@implementation KSCar

#pragma mark -
#pragma mark Initializations and Deallocations

-(void)dealloc {
    self.cash = 0;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    self.isDirty = YES;
    self.cash = carCash;
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (NSUInteger)payMoney:(NSUInteger)sum {
    NSUInteger payCash = self.cash;
    self.cash = self.cash - sum;
    
    return payCash;
}


@end
