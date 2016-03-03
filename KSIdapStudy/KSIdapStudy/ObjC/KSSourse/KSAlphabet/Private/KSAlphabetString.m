//
//  KSAlphabetWithString.m
//  KSIdapStudy
//
//  Created by KulikovS on 29.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSAlphabetString.h"
#import "KSAlphabet.h"

@interface KSAlphabetString ()

@property (nonatomic, copy) NSString *stringAlphabet;

@end

@implementation KSAlphabetString

#pragma mark -
#pragma mark Class Methods

+ (instancetype)alphabetWithString:(NSString *)string {
    return [[self alloc] initWithString:string];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.stringAlphabet = nil;
    
    [super dealloc];
}

- (instancetype)initWithString:(NSString *)string {
    self = [super init];
    if (self) {
        self.stringAlphabet = [[string copy] autorelease];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSUInteger)count {
    return self.stringAlphabet.length;
}

- (NSString *)alphabetString {
    return self.stringAlphabet;
}
@end

