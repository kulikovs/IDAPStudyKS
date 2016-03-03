//
//  NSString+KSExstension.h
//  KSIdapStudy
//
//  Created by KulikovS on 25.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

extern const NSUInteger kKSDefaultLength;

@interface NSString (KSExstension)

+ (instancetype)randomString;
+ (instancetype)randomStringWithLength:(NSUInteger)length;
+ (instancetype)randomStringWithAlphabet:(NSString *)alphabet;
+ (instancetype)randomStringWithLength:(NSUInteger)length alphabet:(NSString *)alphabet;



@end
