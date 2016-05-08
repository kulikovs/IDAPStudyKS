//
//  KSRandomStrings.h
//  KSIdapStudy
//
//  Created by KulikovS on 04.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KSStringsModel : NSObject
@property (nonatomic, readonly) NSArray       *strings;
@property (nonatomic, readonly) NSUInteger    count;

+ (instancetype)randomStringsRandomCount;

- (NSString *)stringAtIndex:(NSUInteger)index;
- (BOOL)containsString:(NSString *)string;

- (void)addString:(NSString *)string;
- (void)generateNewRandomStrings;

- (void)removeString:(NSString *)string;
- (void)removeStringAtIndex:(NSUInteger)index;
- (void)removeAllStrings;

@end
