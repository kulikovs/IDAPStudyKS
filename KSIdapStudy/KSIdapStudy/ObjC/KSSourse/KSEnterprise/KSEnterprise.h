//
//  KSEnterprise.h
//  KSIdapStudy
//
//  Created by KulikovS on 09.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KSCar.h"

@protocol KSEnterpriseDelegete;

@interface KSEnterprise : NSObject
@property (nonatomic, readonly) KSCar *car;
@property (nonatomic, assign) id <KSEnterpriseDelegete> delegate;

- (void)addCarToWash:(KSCar *)car;

@end

@protocol KSEnterpriseDelegete <NSObject>

- (void)enterprise:(KSEnterprise *)enterprise washTheCar:(KSCar *)car;

@end
