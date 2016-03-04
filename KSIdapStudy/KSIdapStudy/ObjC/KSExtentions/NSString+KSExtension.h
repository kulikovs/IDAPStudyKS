//
//  NSString+KSExstension.h
//  KSIdapStudy
//
//  Created by KulikovS on 25.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KSAlphabet.h"

extern const NSUInteger kKSDefaultLength;

@interface NSString (KSExstension)

//There are lowerCaseLettersAlphabet is default in this two methods
+ (instancetype)randomString;
+ (instancetype)randomStringWithLength:(NSUInteger)length;

+ (instancetype)randomStringWithAlphabet:(KSAlphabet *)alphabet;
+ (instancetype)randomStringWithLength:(NSUInteger)length alphabet:(KSAlphabet *)alphabet;



@end
