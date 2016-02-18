//
//  KSHuman.m
//  KSIdapStudy
//
//  Created by KulikovS on 18.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSHumanClass.h"

@implementation KSHuman

#pragma mark -
#pragma mark Class Methods


#pragma mark - 
#pragma Initializations and Deallocations

- (instancetype)initWithAge {
    self = [super init];
    if (self) {
        self.age = 50;
    }

    return self;
}

#pragma mark -
#pragma mark Public Methods

@end
