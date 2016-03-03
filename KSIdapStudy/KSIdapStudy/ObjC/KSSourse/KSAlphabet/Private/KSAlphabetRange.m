//
//  KSAlphabetWithRange.m
//  KSIdapStudy
//
//  Created by KulikovS on 29.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSAlphabetRange.h"

@interface KSAlphabetRange ()
@property (nonatomic, assign) NSRange range;

@end

@implementation KSAlphabetRange

#pragma mark -
#pragma mark Class Methods

+ (instancetype)stringWithCharacterRange:(unichar)firstValue secondValue:(unichar)lastValue {
    return [[[[self class] alloc] initWithCharacterRange:firstValue lastValue:lastValue] autorelease];
}

+ (instancetype)alphabetWithRange:(NSRange)range {
    KSAlphabetRange *alphabet = [[[KSAlphabetRange alloc] initWithRange:range] autorelease];
    NSMutableString *string = [NSMutableString string];
    
    NSUInteger location = alphabet.range.location;
    
    for (NSUInteger index = location; index < location + alphabet.range.length; index++) {
        [string appendString:[NSString stringWithFormat:@"%c", (unichar)index]];
    }
    
    return alphabet;
}

#pragma mark -
#pragma mark Accessors

- (NSString *)alphabetString {
    
    NSMutableString *string = [NSMutableString string];
    NSUInteger location = self.range.location;
    
    for (NSUInteger index = location; index < location + self.range.length; index++) {
        [string appendString:[NSString stringWithFormat:@"%c", (unichar)index]];
    }
    
    return [[string copy] autorelease];
}

- (NSUInteger)count {
    return self.range.length;
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithRange:(NSRange)range{
    self =  [super init];
    if (self) {
        self.range = range;
    }
    
    return self;
}

- (instancetype)initWithCharacterRange:(unichar)firstValue lastValue:(unichar)lastValue {
    self = [super init];
    if (self) {
        NSRange range = NSMakeRange(firstValue, lastValue - firstValue);
        self.range = range;
    }
    
    return self;
}


@end
