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
@property (nonatomic, readwrite)   KSGenderType    gender;
@property (nonatomic, readwrite)   NSUInteger      age;
@property (nonatomic, readwrite)   CGFloat         weight;

@end

@implementation KSCreature

#pragma mark -
#pragma mark Class Methods


#pragma mark - 
#pragma Initializations and Deallocations

- (instancetype)init {
    self = [super init];
    if (self) {
        self.childrenArray = [NSMutableArray array];
        self.gender = arc4random_uniform(2) + 1;
    }
    
    return self;
}

- (instancetype)initWithName: (NSString*)name {
    self = [super init];
    if (self) {
        self.childrenArray = [NSMutableArray array];
        self.name = name;
        self.gender = arc4random_uniform(2) + 1;
    }

    return self;
}

- (instancetype)initWithName: (NSString*)name andGender:(KSGenderType)gender  {
    self = [super init];
    if (self) {
        self.childrenArray = [NSMutableArray array];
        self.name = name;
        self.gender = gender;
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

- (KSCreature*)giveBirthChild {
    KSCreature *child = [[KSCreature new] autorelease];
    
    return child;
}

- (void)goToWar {
    NSLog(@"You're the man! Go to War!");
}

@end
