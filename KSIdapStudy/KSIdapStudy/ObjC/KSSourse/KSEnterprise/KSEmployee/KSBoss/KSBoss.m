//
//  KSBoss.m
//  KSIdapStudy
//
//  Created by KulikovS on 13.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSBoss.h"


@implementation KSBoss

- (void)completeWorking {
        NSLog(@"Money count = %lu", self.money);
        self.state = kKSWorkerStateFree;
}

@end
