//
//  NSString+KSExstension.h
//  KSIdapStudy
//
//  Created by KulikovS on 25.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (KSExstension)

+ (instancetype)randomString;
+ (instancetype)randomStringWithLenght:(NSUInteger)lenght;
+ (instancetype)randomStringWithCapitallLetter;

@end
