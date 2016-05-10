//
//  KSArrayModel.h
//  KSIdapStudy
//
//  Created by KulikovS on 08.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

//#import "KSObserver.h"

@interface KSArrayModel : NSObject
@property (nonatomic, readonly) NSUInteger  count;

+ (instancetype)arrayModelWithObject:(id)object;
+ (instancetype)arrayModelWithObjects:(NSArray *)objects;

- (instancetype)initModelWithObject:(id)object;
- (instancetype)initModelWithArray:(NSArray *)objects;

- (id)objectAtIndex:(NSUInteger)index;
- (id)objectAtIndexedSubscript:(NSUInteger)index;
- (NSUInteger)indexOfObject:(id)object;

- (void)moveObjectAtIndex:(NSUInteger)index onObjectAtIndex:(NSUInteger)onIndex;
- (void)addObject:(id)object;
- (void)removeObject:(id)object;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)removeAllObject;

@end
