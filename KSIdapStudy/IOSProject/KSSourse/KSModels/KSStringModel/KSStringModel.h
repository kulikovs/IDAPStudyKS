//
//  KSStringModel.h
//  KSIdapStudy
//
//  Created by KulikovS on 08.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KSStringModel : NSObject
@property (nonatomic, retain) NSString *string;

+ (instancetype)stringModelWithRandomString;
+ (instancetype)stringModelWithString:(NSString *)string;

//Super init initialized with random string and random count.
- (instancetype)initWithString:(NSString *)string;

+ (NSArray *)stringsModelsWithRandomStringRandomCount;

@end
