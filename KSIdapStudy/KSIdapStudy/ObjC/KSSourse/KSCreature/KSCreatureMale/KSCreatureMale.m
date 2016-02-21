//
//  KSCreatureMale.m
//  KSIdapStudy
//
//  Created by KulikovS on 21.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSCreatureMale.h"

@implementation KSCreatureMale

#pragma mark -
#pragma mark Public Methods

- (void)goToWar {
    NSLog(@"You're the man! Go to War!");
}

- (void) performGenderSpecificOperation {
    [self goToWar];
}

@end
