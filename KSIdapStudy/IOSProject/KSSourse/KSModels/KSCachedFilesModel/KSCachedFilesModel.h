//
//  KSCachedFilesModel.h
//  KSIdapStudy
//
//  Created by KulikovS on 01.06.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSModel.h"

@interface KSCachedFilesModel : NSObject <NSCoding>;

+ (instancetype)cachedFilesModel;

+(instancetype) alloc __attribute__((unavailable("alloc not available, call cachedFilesModel instead")));
-(instancetype) init __attribute__((unavailable("init not available, call cachedFilesModel instead")));
+(instancetype) new __attribute__((unavailable("new not available, call cachedFilesModel instead")));

- (NSString *)URLStringForFileName:(NSString *)fileName;
- (BOOL)fileIsCashed:(NSString *)URL;
- (void)removeURLString:(NSString *)URLString;
- (void)addURLString:(NSString *)URL;

@end
