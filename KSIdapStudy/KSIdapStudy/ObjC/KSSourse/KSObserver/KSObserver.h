//
//  KSObserver.h
//  KSIdapStudy
//
//  Created by KulikovS on 15.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^KSHandlerObject)(void);

@interface KSObserver : NSObject
@property (nonatomic, assign)     NSUInteger    state;

- (void)addHandler:(KSHandlerObject)handler state:(NSUInteger)state object:(id)object;
- (void)removeHandlersForState:(NSUInteger)state;
- (void)removeHandlersForObject:(id)object;
- (void)removeAllHandlers;

@end
