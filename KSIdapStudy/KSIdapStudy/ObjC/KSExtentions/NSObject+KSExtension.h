//
//  NSObject+KSObject.h
//  KSIdapStudy
//
//  Created by KulikovS on 24.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (KSObject)

+ (instancetype)object;
+ (NSArray *)objectsWithClass:(Class)theClass count:(NSUInteger)count;

@end
