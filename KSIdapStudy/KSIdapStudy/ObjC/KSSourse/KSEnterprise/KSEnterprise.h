//
//  KSEnterprise.h
//  KSIdapStudy
//
//  Created by KulikovS on 09.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KSWorkerProtocol.h"

@class KSCar;

@interface KSEnterprise : NSObject <KSWorkerProtocol>

- (void)washCar:(KSCar *)car;

@end

