//
//  KSAlphabetWithRange.h
//  KSIdapStudy
//
//  Created by KulikovS on 29.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSAlphabet.h"

@interface KSAlphabetRange : KSAlphabet
@property (nonatomic, assign) NSRange range;

+ (instancetype)stringWithCharactersInRange:(unichar)firstValue
                                secondValue:(unichar)secondValue;

@end
