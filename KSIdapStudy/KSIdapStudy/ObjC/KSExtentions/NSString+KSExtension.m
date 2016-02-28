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

+ (instancetype)alphabetWithAlphabet:(NSString *)firstAlphabet
                      secondAlphabet:(NSString *)secondAlphabet;
@end

@implementation NSString (KSExtension)

#pragma mark -
#pragma mark Privat Methods

+ (instancetype)stringWithRange:(NSRange)range{
    NSString *string = [NSString string];
    NSUInteger location = range.location;

    for (NSUInteger index = location; index < location + range.length; index++) {
        string = [string stringByAppendingString:[NSString stringWithFormat:@"%c", (unichar)index]];
    }
    
    return string;
}

+ (instancetype)stringWithCharactersInRange:(NSUInteger)firstValue secondValue:(NSUInteger)secondValue {
    NSRange range = NSMakeRange(firstValue, secondValue - firstValue + 1);
    
    return [NSString stringWithRange:range];
}

+ (instancetype)alphabetWithAlphabet:(NSString *)firstAlphabet
                      secondAlphabet:(NSString *)secondAlphabet {
    
    return [firstAlphabet stringByAppendingString:secondAlphabet];
}

#pragma mark -
#pragma mark Class Methods

+ (instancetype)randomStringWithLength:(NSUInteger)length alphabet:(NSString *)alphabet {
    NSString *string = [NSString string];
    
    for (NSUInteger index = 0; index < length; index++) {
        NSUInteger randomValue = arc4random_uniform(alphabet.length - 1);
        unichar symbol = [alphabet characterAtIndex:randomValue];
        string = [string stringByAppendingString:[NSString stringWithFormat:@"%c", symbol]];
    }
    
    return string;
    
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
    return [NSString alphabetWithAlphabet:[NSString lowerCaseAlphabet]
                           secondAlphabet:[NSString numericLettersAlphabet]];
}

+ (instancetype)lowerCaseWithUpperCaseAlphabet {
    return [NSString alphabetWithAlphabet:[NSString lowerCaseAlphabet]
                           secondAlphabet:[NSString upperCaseAlphabet]];
}

@end
