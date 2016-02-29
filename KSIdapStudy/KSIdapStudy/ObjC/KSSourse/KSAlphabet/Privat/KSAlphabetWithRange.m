//
//  KSAlphabetWithRange.m
//  KSIdapStudy
//
//  Created by KulikovS on 29.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSAlphabetWithRange.h"

@implementation KSAlphabetWithRange

+ (instancetype)alphabetWithRange {
NSMutableString *string = [NSMutableString string];
    NSUInteger location = self->range.location;

for (NSUInteger index = location; index < location + range.length; index++) {
    [string appendString:[NSString stringWithFormat:@"%c", (unichar)index]];
}

return [[string copy] autorelease];
}

@end
