//
//  KSQueue.h
//  KSIdapStudy
//
//  Created by KulikovS on 02.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KSQueue : NSObject
@property (nonatomic, readonly) NSArray *queue;

- (void)addObject:(id)object;
- (id)pushObject;
- (void)removeAllObject;

@end
