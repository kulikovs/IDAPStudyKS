//
//  KSArrayModel.m
//  KSIdapStudy
//
//  Created by KulikovS on 08.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSArrayModel.h"

@interface KSArrayModel ()
@property (nonatomic, strong) NSMutableArray *arrayObjects;

@end

@implementation KSArrayModel

#pragma mark -
#pragma mark Class Methods

+ (instancetype)arrayModelWithObject:(id)object {
    return [[[self class] alloc] initWithObject:object];
}

+ (instancetype)arrayModelWithObjects:(NSArray *)objects {
    return [[[self class] alloc] initWithObject:objects];
}

#pragma mark -
#pragma mark Initializations

- (instancetype)initWithObject:(id)object {
    self = [super init];
    if (self) {
        self.arrayObjects = [NSMutableArray arrayWithObject:object];
    }
    
    return self;
}

- (instancetype)initWithObjects:(NSArray *)objects {
    self = [super init];
    if (self) {
        self.arrayObjects = [NSMutableArray arrayWithArray:objects];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)objects {
    return [self.arrayObjects copy];
}

- (NSUInteger)count {
  return self.arrayObjects.count;
}

#pragma mark -
#pragma mark Public Methods

- (id)objectAtIndex:(NSUInteger)index {
  return [self.arrayObjects objectAtIndex:index];
}

- (id)objectAtIndexedSubscript:(NSUInteger)index {
    return self.objects[index];
}

- (NSUInteger)indexOfObject:(id)object {
    return [self.arrayObjects indexOfObject:object];
}

- (void)addObject:(id)object {
    [self.arrayObjects addObject:object];
}

- (void)removeObject:(id)object {
    [self.arrayObjects removeObject:object];
}

- (void)removeObjectAtIndex:(NSUInteger)index {
    [self.arrayObjects removeObjectAtIndex:index];
}

- (void)removeAllObject {
    [self.arrayObjects removeAllObjects];
}

@end
