//
//  NSObject+KSObject.m
//  KSIdapStudy
//
//  Created by KulikovS on 24.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "NSObject+KSExtension.h"

@implementation NSObject (KSObject)

+ (instancetype)object {
    return [[[[self class] alloc] init] autorelease];
}



@end
