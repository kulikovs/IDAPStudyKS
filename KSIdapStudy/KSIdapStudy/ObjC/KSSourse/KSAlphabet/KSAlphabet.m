//
//  KSAlphabet.m
//  KSIdapStudy
//
//  Created by KulikovS on 29.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSAlphabet.h"
#import "KSAlphabetRange.h"
#import "KSAlphabetString.h"
#import "KSAlphabetCluster.h"

@implementation KSAlphabet

@dynamic alphabetString;
@dynamic count;

#pragma mark
#pragma mark Class Methods

+ (instancetype)alphabetWithCharacterRange:(unichar)firstValue lastValue:(unichar)lastValue {
    return [[[[self class] alloc] initWithRange:NSMakeRange(firstValue, lastValue - firstValue)] autorelease];
}

+ (instancetype)alphabetWithString:(NSString *)string {
    return [[[[self class] alloc] initWithString:string] autorelease];
}

+ (instancetype)alphabetWithRange:(NSRange)range {
    return [[[[self class] alloc] initWithRange:range] autorelease];
}

+ (instancetype)alphabetWithAlphabetsArray:(NSArray *)alphabets {
    return [[[[self class] alloc] initWithAlphabetsArray:alphabets] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithRange:(NSRange)range {
    [self autorelease];
    
    return [[KSAlphabetRange alloc] initWithRange:range];
}

- (instancetype)initWithString:(NSString *)string {
    [self autorelease];
    
    return [[KSAlphabetString alloc] initWithString:string];
}

- (instancetype)initWithCharacterRange:(unichar)firstValue lastValue:(unichar)lastValue {
    [self autorelease];
    
    return [[KSAlphabetRange alloc] initWithRange:NSMakeRange(firstValue, lastValue - firstValue)];
}

- (instancetype)initWithAlphabetsArray:(NSArray *)alphabets {
    [self autorelease];
    
    return [[KSAlphabetCluster alloc] initWithAlphabetsArray:alphabets];
}

#pragma mark
#pragma mark Alphabets

+ (instancetype)lowerCaseLettersAlphabet {
    return [[self class] alphabetWithCharacterRange:'a' lastValue:'z'];
}

+ (instancetype)upperCaseLettersAlphabet {
    return [[self class] alphabetWithCharacterRange:'A' lastValue:'Z'];
}

+ (instancetype)numericLettersAlphabet {
    return [[self class] alphabetWithCharacterRange:'0' lastValue:'9'];
}

#pragma mark -
#pragma mark Accessors

- (NSString *)alphabetString {
    return nil;
}

- (NSUInteger)count {
    return self.alphabetString.length;
}

@end