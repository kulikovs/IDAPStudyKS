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

@interface KSCarsWasher : NSObject <KSEnterpriseDelegete>
@property (nonatomic, assign) NSUInteger money;

@end
