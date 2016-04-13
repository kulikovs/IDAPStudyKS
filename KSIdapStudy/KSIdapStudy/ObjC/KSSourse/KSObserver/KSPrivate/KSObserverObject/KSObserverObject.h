//
//  KSObserverObject.h
//  KSIdapStudy
//
//  Created by KulikovS on 13.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KSObserver.h"

@interface KSObserverObject : NSObject
@property (nonatomic, retain) id                object;
@property (nonatomic, assign) KSHandlerObject   handler;

- (instancetype)initWithObject:(id)object handler:(KSHandlerObject)handler NS_DESIGNATED_INITIALIZER;

@end
