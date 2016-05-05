//
//  KSRandomStrings.m
//  KSIdapStudy
//
//  Created by KulikovS on 04.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSStringsModel.h"

@implementation KSStringsModel

+ (instancetype)randomStringsRandomCount; {
    KSStringsModel *strinsModel = [[KSStringsModel alloc] init];
    strinsModel.strings = [NSString randomStringsWithRandomCount];
    return strinsModel;
}


@end
