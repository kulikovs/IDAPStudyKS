//
//  KSQueue.h
//  KSIdapStudy
//
//  Created by KulikovS on 02.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KSQueue : NSObject
@property (nonatomic, retain) NSMutableArray *queue;

- (void)addObjectToQueue:(id)object;
- (void)removeObjectFromQueue:(id)object;
- (void)removeAllObjectsFromQueue;
- (id)firstObject;

@end
