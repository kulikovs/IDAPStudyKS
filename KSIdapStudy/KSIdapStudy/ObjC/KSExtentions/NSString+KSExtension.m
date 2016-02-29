//
//  NSString+KSExstension.m
//  KSIdapStudy
//
//  Created by KulikovS on 25.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "NSString+KSExtension.h"

const NSUInteger kKSDefaultLength  = 10;

@interface NSString (KSPrivateExstension)

+ (instancetype)stringWithRange:(NSRange)range;
+ (instancetype)stringWithCharactersInRange:(unichar)firstValue secondValue:(unichar)secondValue;

@end

@implementation NSString (KSExtension)

#pragma mark -
#pragma mark Privat Class Methods

+ (instancetype)stringWithRange:(NSRange)range{
    NSMutableString *string = [NSMutableString string];
    NSUInteger location = range.location;

    for (NSUInteger index = location; index < location + range.length; index++) {
        [string appendString:[NSString stringWithFormat:@"%c", (unichar)index]];
    }
    
    return [[string copy] autorelease];
}

+ (instancetype)stringWithCharactersInRange:(NSUInteger)firstValue secondValue:(NSUInteger)secondValue {
    NSRange range = NSMakeRange(firstValue, secondValue - firstValue + 1);
    
    return [NSString stringWithRange:range];
}

#pragma mark -
#pragma mark Public Class Methods

+ (instancetype)randomStringWithLength:(NSUInteger)length alphabet:(NSString *)alphabet {
    NSMutableString *string = [NSMutableString string];
    
    for (NSUInteger index = 0; index < length; index++) {
        NSUInteger randomValue = arc4random_uniform((uint32_t)alphabet.length - 1);
        unichar symbol = [alphabet characterAtIndex:randomValue];
        [string stringByAppendingString:[NSString stringWithFormat:@"%c", symbol]];
    }
    
    return [[string copy] autorelease];
    
}

+ (instancetype)randomStringWithAlphabet:(NSString *)alphabet {
    return [NSString randomStringWithLength:kKSDefaultLength alphabet:alphabet];
}

+ (instancetype)randomStringWithLength:(NSUInteger)length {
    return [NSString randomStringWithLength:length alphabet:[NSString lowerCaseAlphabet]];
}

+ (instancetype)randomString{
    return [NSString randomStringWithLength:kKSDefaultLength alphabet:[NSString lowerCaseAlphabet]];
}

#pragma mark -
#pragma mark Alphabets

+ (instancetype)lowerCaseAlphabet {
    return [NSString stringWithCharactersInRange:'a' secondValue:'z'];

}

+ (instancetype)upperCaseAlphabet {
    return [NSString stringWithCharactersInRange:'A' secondValue:'Z'];

}

+ (instancetype)numericLettersAlphabet {
    return [NSString stringWithCharactersInRange:'0' secondValue:'9'];

}

+ (instancetype)lowerCaseWithNumericAlphabet {
    NSString *lowerCaseAlphabet = [NSString lowerCaseAlphabet];
    
    return [lowerCaseAlphabet stringByAppendingString:[NSString numericLettersAlphabet]];
}

+ (instancetype)lowerCaseWithUpperCaseAlphabet {
    NSString *lowerCaseAlphabet = [NSString lowerCaseAlphabet];
    
    return [lowerCaseAlphabet stringByAppendingString:[NSString upperCaseAlphabet]];
}

@end
