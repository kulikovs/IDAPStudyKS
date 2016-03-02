//
//  NSString+KSExstension.m
//  KSIdapStudy
//
//  Created by KulikovS on 25.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "NSString+KSExtension.h"
#import "KSAlphabet.h"

const NSUInteger kKSDefaultLength  = 10;

@implementation NSString (KSExtension)

#pragma mark -
#pragma mark Public Class Methods

+ (instancetype)randomStringWithLength:(NSUInteger)length alphabet:(KSAlphabet *)alphabet {
    NSMutableString *string = [NSMutableString string];
    
    for (NSUInteger index = 0; index < length; index++) {
        NSUInteger randomValue = arc4random_uniform((uint32_t)alphabet.count - 1);
        unichar symbol = [alphabet.alphabet characterAtIndex:randomValue];
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
