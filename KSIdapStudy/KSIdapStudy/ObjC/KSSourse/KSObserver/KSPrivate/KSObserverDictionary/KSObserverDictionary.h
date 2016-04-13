//
//  KSObserverDictionary.h
//  KSIdapStudy
//
//  Created by KulikovS on 13.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KSObserverArray.h"

@interface KSObserverDictionary : NSObject
@property (nonatomic, assign) NSUInteger        state;
@property (nonatomic, retain) KSObserverArray   *arrayObject;

- (void)addHandler:(KSHandlerObject)handler state:(NSUInteger)state object:(id)object;
- (void)removeHandlersForObject:(id)object;

@end
