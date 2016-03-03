//
//  KSAlphabetCluster.m
//  KSIdapStudy
//
//  Created by KulikovS on 04.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSAlphabetCluster.h"

@interface KSAlphabetCluster ()
@property (nonatomic, retain) NSArray *arrayAlphabets;

@end

@implementation KSAlphabetCluster

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithAlphabetsArray:(NSArray *)alphabetsArray {
    self = [super init];
    if (self) {
        self.arrayAlphabets = [[alphabetsArray copy] autorelease];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSString *)alphabetString {
    NSMutableString *string = [NSMutableString string];
    for (KSAlphabet *alphabet in self.arrayAlphabets) {
        [string appendString:alphabet.alphabetString];
    }
    
    return [[string copy] autorelease];
}

@end
