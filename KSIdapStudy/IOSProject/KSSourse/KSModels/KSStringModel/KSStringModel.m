//
//  KSStringModel.m
//  KSIdapStudy
//
//  Created by KulikovS on 08.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSStringModel.h"

static const NSUInteger kKSDefaultStringsCount = 40;
static const NSString *kKSPathToPictureForCell = @"/Users/kulikovs/Documents/Lessons/IdapStudy/KSIdapStudy/IOSProject/Supporting Files/Assets.xcassets/gizmo.imageset/gizmo.jpg";

@interface KSStringModel ()
@property (nonatomic, copy)     NSString    *string;
@property (nonatomic, strong)   UIImage     *image;

@end

@implementation KSStringModel

#pragma mark -
#pragma mark Class Methods

+ (instancetype)randomStringModel {
    return [[self class] new];
}

+ (instancetype)stringModelWithString:(NSString *)string {
    return [[[self class] alloc] initWithString:string];
}

+ (NSArray *)randomStringsModels {
    NSMutableArray *mutableArray = [NSMutableArray array];
    
    for (NSUInteger index = 0; index < arc4random_uniform(kKSDefaultStringsCount) + 1; index++) {
        [mutableArray addObject:[self new]];
    }
    
    return [mutableArray copy];
}

#pragma mark -
#pragma mark Initialization and Deallocations

- (instancetype)init {
    self = [super init];
    if (self) {
        self.image = [[UIImage alloc] initWithContentsOfFile:[kKSPathToPictureForCell copy]];
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

@end