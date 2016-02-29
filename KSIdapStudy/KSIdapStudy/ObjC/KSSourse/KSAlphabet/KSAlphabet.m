//
//  KSAlphabet.m
//  KSIdapStudy
//
//  Created by KulikovS on 29.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSAlphabet.h"

@interface KSAlphabet ()
@property (nonatomic, retain) NSMutableString *alphabet;
@property (nonatomic, assign) NSUInteger *count;

@end

@implementation KSAlphabet

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.alphabet = nil;
    self.count = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.alphabet = [NSMutableString string];
    }
    
    return self;
}

#pragma mark
#pragma mark Class Methods

+ (instancetype)alphabetWithRange {

    return nil;
}

+ (instancetype)alphabetWithString:(NSString*)string {

    return nil;
}

@end
