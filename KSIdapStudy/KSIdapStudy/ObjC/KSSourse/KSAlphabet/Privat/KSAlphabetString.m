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

@property (nonatomic, retain) NSString *alphabetString;

@end

@implementation KSAlphabetString

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithString:(NSString *)string {
    self = [super init];
    if (self) {
        self.alphabetString = string; //property alphabetString is not finding in Class KSAlphabet,
                                        //so was created property in KSAlphabetString
    }
    
    return self;
}

#pragma mark -
#pragma mark Class Methods

+ (instancetype)alphabetWithString:(NSString *)string {    
    KSAlphabetString *alphabet = [[[KSAlphabetString alloc] init] autorelease];
    alphabet.alphabetString = string;
    
    return alphabet;
}

@end
