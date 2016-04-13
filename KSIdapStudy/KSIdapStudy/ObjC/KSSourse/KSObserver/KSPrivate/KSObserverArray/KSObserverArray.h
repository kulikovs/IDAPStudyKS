//
//  KSObserverArray.h
//  KSIdapStudy
//
//  Created by KulikovS on 13.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KSObserverObject.h"

@interface KSObserverArray : NSObject
@property (nonatomic, retain) NSMutableArray *handlers;

- (void)addHandler:(KSHandlerObject)handler forObject:(id)object;
- (void)removeHandlersForObject:(id)object;

@end