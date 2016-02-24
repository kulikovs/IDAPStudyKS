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
@property (nonatomic, assign)      NSUInteger      age;
@property (nonatomic, assign)      CGFloat         weight;

@end

@implementation KSCreature

#pragma mark - 
#pragma Initializations and Deallocations
            
- (void)dealloc {
    self.name = nil;
    self.childrenArray = nil;
    
   [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.childrenArray = [NSMutableArray array];
    }
    
    return self;
}

- (instancetype)initWithName:(NSString*)name {
    self = [self init];
    if (self) {
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

- (void)addChild:(KSCreature *)child {
    [self.childrenArray addObject:child];
}

- (void)removeChild:(KSCreature *)child {
    [self.childrenArray removeObject:child];
}

- (void)removeAllChildren {
    [self.childrenArray removeAllObjects];
}

- (void)sayHi {
    NSLog(@"Hi!");
    [self.children makeObjectsPerformSelector:@selector(sayHi)];
}

- (void)performGenderSpecificOperation {

}

@end
