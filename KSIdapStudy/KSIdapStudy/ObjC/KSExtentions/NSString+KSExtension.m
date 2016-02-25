//
//  NSString+KSExstension.m
//  KSIdapStudy
//
//  Created by KulikovS on 25.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "NSString+KSExtension.h"

static const NSUInteger kKSMaxStringLenght  = 15;
static const NSUInteger kKSDefaultStart     = 97;
static const NSUInteger kKSDefaultRange     = 25;

static const NSString   *capitalLetter      = @"ABCDEFGH";
static const NSString   *smallLetter        = @"abcdefg";
static const NSString   *numbers            = @"0123456789";


@implementation NSString (KSExtension)

+ (instancetype)randomString {
    NSUInteger lenght = arc4random_uniform(kKSMaxStringLenght);
    
    return [NSString randomStringWithLenght: lenght];
}

+ (instancetype)randomStringWithLenght:(NSUInteger)lenght {
    NSString *string = [NSString string];
    
    for (NSUInteger index = 0; index < lenght; index++) {
        unichar symbol = arc4random_uniform(kKSDefaultRange) +kKSDefaultStart;
        NSString *charRandom = [NSString stringWithFormat:@"%c", symbol];
        string = [string stringByAppendingString:charRandom];
    }
    
    return string;
}

+ (instancetype)randomStringWithCapitallLetter{
        NSString *string = [NSString string];
        NSUInteger lenght = arc4random_uniform(kKSMaxStringLenght);
    
    for (NSUInteger index = 0; index < lenght; index++) {
        NSUInteger randomValue = arc4random_uniform(capitalLetter.length - 1);
        unichar symbol = [capitalLetter characterAtIndex:randomValue];
        NSString *charRandom = [NSString stringWithFormat:@"%c", symbol];
        string = [string stringByAppendingString:charRandom];
    }
    
    return string;
}

@end
