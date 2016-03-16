//
//  KSBoss.m
//  KSIdapStudy
//
//  Created by KulikovS on 13.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSBoss.h"


@implementation KSBoss
@synthesize state = _state;

- (void)completeWorkingWithObject:(KSBoss *)object {
 //   object.state = kKSWorkerStateFree;
    NSLog(@"Money count = %lu", self.money);
  //  self.state = kKSWorkerStateFree;
}


@end
