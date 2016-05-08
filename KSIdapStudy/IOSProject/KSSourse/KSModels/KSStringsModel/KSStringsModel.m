//
//  KSRandomStrings.m
//  KSIdapStudy
//
//  Created by KulikovS on 04.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSStringsModel.h"

@interface KSStringsModel ()
@property (nonatomic, strong) NSMutableArray *stringsArray;

@end

@implementation KSStringsModel

#pragma mark -
#pragma mark Initialization

- (instancetype)init {
    self = [super init];
    if (self) {
      [self generateNewRandomStrings];
    }
    
    return self;
}

#pragma mark -
#pragma mark Class Methods

+ (instancetype)randomStringsRandomCount; {
    KSStringsModel *strinsModel = [[KSStringsModel alloc] init];
    return strinsModel;
}

#pragma mark -
#pragma mark Accessors

- (NSUInteger)count {
    return self.strings.count;
}

- (NSArray *)strings {
   return [self.stringsArray copy];
}

#pragma mark -
#pragma mark Public Methods

-(void)addString:(NSString *)string {
    [self.stringsArray addObject:string];
}

- (void)generateNewRandomStrings {
    self.stringsArray = [NSMutableArray arrayWithArray:[NSString randomStringsWithRandomCount]];
}

- (NSString *)stringAtIndex:(NSUInteger)index {
    return [self.strings objectAtIndex:index];
}

- (BOOL)containsString:(NSString *)string {
    return nil;
}


@end

