//
//  KSBoss.m
//  KSIdapStudy
//
//  Created by KulikovS on 13.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSBoss.h"

@implementation KSBoss

- (void)completeWorkingWithObject:(KSEmployee *)object {
    object.workerState = kKSWorkerStateFree;
    NSLog(@"Money count = %lu", self.money);
    self.workerState = kKSWorkerStateFree;
}


@end
