//
//  KSCreatureFemale.m
//  KSIdapStudy
//
//  Created by KulikovS on 21.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSCreatureFemale.h"

@interface KSCreatureFemale ()

- (KSCreature *)giveBirthChild;

@end

@implementation KSCreatureFemale

#pragma mark -
#pragma mark Public Methods

- (KSCreature *)giveBirthChild {
    return [KSCreature object];
}

- (void)performGenderSpecificOperation {
    [self giveBirthChild];
}

@end
