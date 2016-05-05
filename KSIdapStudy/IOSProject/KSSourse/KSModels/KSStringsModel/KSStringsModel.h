//
//  KSRandomStrings.h
//  KSIdapStudy
//
//  Created by KulikovS on 04.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KSStringsModel : NSObject
@property (nonatomic, strong) NSArray *strings;

+ (instancetype)randomStringsRandomCount;

@end
