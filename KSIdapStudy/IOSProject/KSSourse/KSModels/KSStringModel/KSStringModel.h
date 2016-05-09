//
//  KSStringModel.h
//  KSIdapStudy
//
//  Created by KulikovS on 08.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KSStringModel : NSObject
@property (nonatomic, readonly) NSString *string;

+ (instancetype)randomStringModel;
+ (instancetype)stringModelWithString:(NSString *)string;

//This two methods initialized with random string and random count.
- (instancetype)initWithString:(NSString *)string;

+ (NSArray *)randomStringsModels;

@end
