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
    kKSWorkerStateWaiting
};

@protocol KSWorkerProtocol <NSObject>

- (void)workerFinishedWork:(id<KSMoneyProtocol>)object;
- (void)workerStartedWork:(id<KSMoneyProtocol>)object;
- (void)workerBecameFree:(id<KSMoneyProtocol>)object;

@end
