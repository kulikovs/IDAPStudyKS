//
//  KSHuman.m
//  KSIdapStudy
//
//  Created by KulikovS on 18.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSCreature.h"

@interface KSCreature ()
@property (nonatomic, copy)        NSString        *name;
@property (nonatomic, retain)      NSMutableArray  *childrenArray;
@property (nonatomic, readwrite)   NSUInteger      age;
@property (nonatomic, readwrite)   CGFloat         weight;

@end

@implementation KSCreature

#pragma mark -
#pragma mark Class Methods

+ (KSCreature*)creatureCreate {
    return [[KSCreature new] autorelease];
}

#pragma mark - 
#pragma Initializations and Deallocations

- (instancetype)init {
    self = [super init];
    if (self) {
        self.childrenArray = [NSMutableArray array];
    }
    
    return self;
}

- (instancetype)initWithName: (NSString*)name {
    self = [super init];
    if (self) {
        self.childrenArray = [NSMutableArray array];
        self.name = name;
    }

    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)children {
    return [self.childrenArray copy];
}

#pragma mark -
#pragma mark Public Methods

- (void)addChild: (KSCreature *)child {
    [self.childrenArray addObject:child];
}

- (void)removeChild: (KSCreature *)child {
    [self.childrenArray removeObject:child];
}

- (void)removeAllChildren {
    [self.childrenArray removeAllObjects];
}

-(void)sayHi {
    NSLog(@"Hi!");
    [self.children makeObjectsPerformSelector:@selector(sayHi)];
}

-(void)howManyChildren {
    NSLog(@"I have %lu children", (unsigned long)[self.children count]);
}

- (void)performGenderSpecificOperation {

}

@end
