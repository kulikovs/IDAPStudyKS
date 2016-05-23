//
//  KSStringModel.m
//  KSIdapStudy
//
//  Created by KulikovS on 08.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSStringModel.h"

static NSUInteger       const  kKSDefaultStringsCount  =   40;
static NSString   *     const  kKSStringForDecoder     =   @"string";
static NSString   *     const  kKSNameImageForCell     =   @"gremlin.jpg";

@interface KSStringModel ()
@property (nonatomic, copy)     NSString    *string;
@property (nonatomic, strong)   UIImage     *image;

- (void)load;

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
#pragma mark Public Methods

- (void)load {
    if (self.state == kKSStringModelStateLoading) {
        return;
    } else {
        self.state = kKSStringModelStateLoading;
    }
    
    KSWeakifySelfWithClass(KSStringModel);
    KSDispatchAsyncInBackground(^ {
        KSStrongifySelfWithClass(KSStringModel)
        sleep(3);
        
        strongSelf.image = [UIImage imageWithContentsOfFile:[NSBundle pathToFileWithName:kKSNameImageForCell]];
        
        KSDispatchAsyncOnMainThred(^ {
            KSStrongifySelfWithClass(KSStringModel)
            [strongSelf setState:kKSStringModelStateLoaded withObject:self.image];
        });
    });
}

#pragma mark -
#pragma mark NSCoding

- (instancetype)initWithCoder:(NSCoder *)decoder {
    self = [self init];
    if (self) {
        self.string = [decoder decodeObjectForKey:kKSStringForDecoder];
    }
    
    return self;
}

- (void)encodeWithCoder:(NSCoder *)aCoder {
    [aCoder encodeObject:self.string forKey:kKSStringForDecoder];
}

@end