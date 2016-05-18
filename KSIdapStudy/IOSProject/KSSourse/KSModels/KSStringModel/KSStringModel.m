//
//  KSStringModel.m
//  KSIdapStudy
//
//  Created by KulikovS on 08.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSStringModel.h"

static const NSUInteger     kKSDefaultStringsCount  =   40;
static const NSString   *   kKSStringForDecoder     =   @"string";
static const NSString   *   kKSImageForCell         =   @"gremlin.jpg";

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
        NSString *path = [[[NSBundle mainBundle] resourcePath]
                          stringByAppendingPathComponent:[kKSImageForCell copy]];
        self.image = [[UIImage alloc] initWithContentsOfFile:path];
        self.string = [NSString randomString];
    }
    
    return self;
}

- (instancetype)initWithCoder:(NSCoder *)decoder {
    self = [self init];
    if (self) {
        self.string = [decoder decodeObjectForKey:[kKSStringForDecoder copy]];
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
#pragma mark NSCoding

- (void)encodeWithCoder:(NSCoder *)aCoder {
    [aCoder encodeObject:self.string forKey:[kKSStringForDecoder copy]];
}

@end