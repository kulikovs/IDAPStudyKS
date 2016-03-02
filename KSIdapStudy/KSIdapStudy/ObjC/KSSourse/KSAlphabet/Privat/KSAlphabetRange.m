//
//  KSAlphabetWithRange.m
//  KSIdapStudy
//
//  Created by KulikovS on 29.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSAlphabetRange.h"

@interface KSAlphabetRange ()
@property (nonatomic, retain) NSString *rangeAlphabet;

@end

@implementation KSAlphabetRange


#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithRange:(unichar)firstValue secondValue:(unichar)secondValue {
    self =  [super init];
    if (self) {
        self = [KSAlphabetRange stringWithCharactersInRange:firstValue secondValue:(secondValue)];
    }
    
    return self;
}

#pragma mark -
#pragma mark Class Methods

+ (instancetype)stringWithCharactersInRange:(unichar)firstValue secondValue:(unichar)secondValue {
    NSRange range = NSMakeRange(firstValue, secondValue - firstValue + 1);
    
    return [KSAlphabetRange alphabetWithRange:range];
}

+ (instancetype)alphabetWithRange:(NSRange)range {
    KSAlphabetRange *alphabet = [[[KSAlphabetRange alloc] init] autorelease];
    NSMutableString *string = [NSMutableString string];
    alphabet.range = range;
    NSUInteger location = range.location;
    
    for (NSUInteger index = location; index < location + range.length; index++) {
        [string appendString:[NSString stringWithFormat:@"%c", (unichar)index]];
    }
    
    alphabet.rangeAlphabet = [[string copy] autorelease];
    return alphabet;
}


@end
