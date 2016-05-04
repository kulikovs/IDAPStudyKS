//
//  KSRandomStrings.m
//  KSIdapStudy
//
//  Created by KulikovS on 04.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSStringsModel.h"

@implementation KSStringsModel

#pragma mark -
#pragma mark Initializations 

- (instancetype)initWithRandomStringRandomCount {
    self = [super init];
    if (self) {
        self.strings = [NSString randomStringsWithRandomCount];
    }
    
    return self;
}


@end
