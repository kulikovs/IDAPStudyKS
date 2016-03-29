//
//  KSCarsWasher.h
//  KSIdapStudy
//
//  Created by KulikovS on 09.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KSEnterprise.h"
#import "KSCar.h"

@protocol KSEnterpriseDelegete;
@protocol KSCarsWasherDelegete;

@interface KSCarsWasher : NSObject <KSEnterpriseDelegete>
@property (nonatomic, assign) NSUInteger money;
@property (nonatomic, assign) id <KSCarsWasherDelegete> delegate;

@end

@protocol KSCarsWasherDelegate <NSObject>

- (void)carsWasher:(KSCarsWasher *)carsWasher carIsPure:(KSCar *)car;

@end

