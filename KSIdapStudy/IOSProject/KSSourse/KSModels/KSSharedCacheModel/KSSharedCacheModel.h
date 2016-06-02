//
//  KSSharedCacheModel.h
//  KSIdapStudy
//
//  Created by KulikovS on 01.06.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSModel.h"

@interface KSSharedCacheModel : NSObject <NSCoding>;

+ (instancetype)sharedCacheModel;

- (NSString *)URLStringForFileName:(NSString *)fileName;
- (BOOL)isCashedForURLString:(NSString *)URLString;
- (void)removeURLString:(NSString *)URLString;
- (void)addURLString:(NSString *)URLString fileName:(NSString *)fileName;

@end
