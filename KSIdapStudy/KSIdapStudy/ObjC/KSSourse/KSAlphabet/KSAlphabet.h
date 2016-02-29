//
//  KSAlphabet.h
//  KSIdapStudy
//
//  Created by KulikovS on 29.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KSAlphabet : NSObject
@property (nonatomic, readonly) NSString *alphabet;
@property (nonatomic, readonly) NSUInteger *count;
@property (nonatomic, readonly) NSRange *range;

+ (instancetype)alphabetWithRange;
+ (instancetype)alphabetWithString:(NSString*)string;

@end

