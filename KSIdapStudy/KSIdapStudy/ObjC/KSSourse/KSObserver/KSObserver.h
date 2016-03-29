//
//  KSObserver.h
//  KSIdapStudy
//
//  Created by KulikovS on 15.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^HandlerForState)(void);


@interface KSObserver : NSObject
@property (nonatomic, assign)     NSUInteger            state;
@property (nonatomic, readonly)   NSArray               *observers;
@property (nonatomic, retain)     NSMutableDictionary   *handlerDictionary;

- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;

- (void)addHandlerForState:(HandlerForState)handler state:(NSUInteger)state;
- (void)removeHandlerForState:(NSUInteger)state;

//This method is intended for subclassing
- (SEL)selectorForState:(NSUInteger)state;

//- ()
- (void)notifyObjectWithSelector:(SEL)selector;
- (void)notifyObserver;
- (BOOL)isObservedByObject:(id)object;

@end
