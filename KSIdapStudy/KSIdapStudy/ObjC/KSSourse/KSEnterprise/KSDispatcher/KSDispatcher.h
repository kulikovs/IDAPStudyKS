//
//  KSDispatcher.h
//  KSIdapStudy
//
//  Created by KulikovS on 06.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class KSEmployee;

@interface KSDispatcher : NSObject

- (instancetype)initWithStaff:(KSEmployee *)staff  NS_DESIGNATED_INITIALIZER;

- (void)addObject:(id)object;
- (BOOL)containsObject:(id)object;

@end
