//
//  KSWorkerProtocol.h
//  KSIdapStudy
//
//  Created by KulikovS on 13.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KSMoneyProtocol.h"

typedef NS_ENUM(NSUInteger, KSWorkerState) {
    kKSWorkerStateUndefine,
    kKSWorkerStateBusy,
    kKSWorkerStateFree,
};

@protocol KSWorkerProtocol <NSObject>
//@property (nonatomic, assign) KSWorkerState workerState;

- (void)workerDidFinishWork:(id<KSMoneyProtocol>)object;

@end
