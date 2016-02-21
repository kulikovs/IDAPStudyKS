//
//  KSCreatureFemale.m
//  KSIdapStudy
//
//  Created by KulikovS on 21.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSCreatureFemale.h"

@implementation KSCreatureFemale

#pragma mark -
#pragma mark Class Methods

//+ (KSCreatureFemale *)creatureCreate {
//    return [KSCreatureFemale creatureCreate];
//}

#pragma mark -
#pragma mark Public Methods

- (void)giveBirthChild {
    NSLog(@"I'm happy! My child is beautiful!");
}

- (void) performGenderSpecificOperation {
    [self giveBirthChild];
}

@end
