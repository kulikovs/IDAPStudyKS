//
//  KSObserverObject.h
//  KSIdapStudy
//
//  Created by KulikovS on 13.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^KSHandlerObject)(void);

@interface KSObserverObject : NSObject
@property (nonatomic, weak) id                object;
@property (nonatomic, copy) KSHandlerObject   handler;

- (instancetype)initWithObject:(id)object handler:(KSHandlerObject)handler NS_DESIGNATED_INITIALIZER;

@end
