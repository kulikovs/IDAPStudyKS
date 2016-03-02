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
@property (nonatomic, readonly) NSUInteger count;

- (instancetype)initWithString:(NSString *)string;
- (instancetype)initWithRange:(unichar)firstValue secondValue:(unichar)secondValue;

+ (instancetype)alphabetWithRange:(unichar)firstValue secondValue:(unichar)secondValue;;
+ (instancetype)alphabetWithString:(NSString *)string;

+ (instancetype)alphabetWithLowerCaseLetters;
+ (instancetype)alphabetWithUpperCaseLetters;
+ (instancetype)alphabetWithNumericSymbols;

@end

