//
//  KSCar.h
//  KSIdapStudy
//
//  Created by KulikovS on 09.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KSMoneyProtocol.h"

typedef NS_ENUM(NSUInteger, KSCarState){
    kKSCarStateUndefine,
    kKSCarStateClean,
    kKSCarStateDirty,
};

@interface KSCar : NSObject <KSMoneyProtocol>
@property (nonatomic, assign) KSCarState   carState ;

@end

