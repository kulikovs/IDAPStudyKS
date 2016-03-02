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

@interface KSAlphabet ()
@property (nonatomic, retain) NSString *alphabetString;

@end

@implementation KSAlphabet

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    
    [super dealloc];
}

- (instancetype)initWithRange:(unichar)firstValue secondValue:(unichar)secondValue; {
    [self autorelease];
    
    return [[KSAlphabetRange alloc] initWithRange:firstValue secondValue:secondValue];
}

- (instancetype)initWithString:(NSString *)string {
    return [[[KSAlphabetString alloc]initWithString:string ] autorelease];
}

#pragma mark -
#pragma mark Accessors

- (instancetype)alphabet {
    return [[self.alphabetString copy] autorelease];
}

- (instancetype)count {
    return self.alphabetString.length;
}

#pragma mark
#pragma mark Class Methods

+ (instancetype)alphabetWithRange:(unichar)firstValue secondValue:(unichar)secondValue {
    return [KSAlphabetRange stringWithCharactersInRange:firstValue secondValue:secondValue];
}

+ (instancetype)alphabetWithString:(NSString *)string {
    return [KSAlphabetString alphabetWithString:string];
}

#pragma mark
#pragma mark Alphabets

+ (instancetype)alphabetWithLowerCaseLetters {
    return [KSAlphabetRange stringWithCharactersInRange:'a' secondValue:'z'];
}

+ (instancetype)alphabetWithUpperCaseLetters {
    return [KSAlphabetRange stringWithCharactersInRange:'A' secondValue:'Z'];
}

+ (instancetype)alphabetWithNumericSymbols {
    return [KSAlphabetRange stringWithCharactersInRange:'0' secondValue:'9'];
}

@end
