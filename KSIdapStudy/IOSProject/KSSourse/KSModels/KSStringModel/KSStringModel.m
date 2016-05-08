//
//  KSStringModel.m
//  KSIdapStudy
//
//  Created by KulikovS on 08.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSStringModel.h"

static const NSUInteger kKSDefaultStringsCount = 40;

@interface KSStringModel ()
//@property (nonatomic, retain) NSString *string;

@end

@implementation KSStringModel

#pragma mark -
#pragma mark Initialization

- (instancetype)init {
    self = [super init];
    if (self) {
        self.string = [NSString randomString];
    }
    
    return self;
}

- (instancetype)initWithString:(NSString *)string {
    self = [super init];
    if (self) {
        self.string = [string copy];
    }
    
    return self;
}

#pragma mark -
#pragma mark Class Methods

+ (instancetype)stringModelWithRandomString {
    return [[self class] new];
}

+ (instancetype)stringModelWithString:(NSString *)string {
    return [[[self class] alloc] initWithString:string];
}

+ (NSArray *)stringsModelsWithRandomStringRandomCount {
    NSMutableArray *mutableArray = [NSMutableArray array];
    
    for (NSUInteger index = 0; index < arc4random_uniform(kKSDefaultStringsCount) + 1; index++) {
         [mutableArray addObject:[self stringModelWithString:[NSString randomString]]];
    }
    
    return [mutableArray copy];
}

#pragma mark -
#pragma mark Accessors

- (NSString *)string {
    return self.string;
}

@end
