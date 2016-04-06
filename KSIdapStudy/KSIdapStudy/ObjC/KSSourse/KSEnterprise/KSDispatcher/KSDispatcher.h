//
//  KSDispatcher.h
//  KSIdapStudy
//
//  Created by KulikovS on 06.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KSQueue.h"

@interface KSDispatcher : NSObject
@property (nonatomic, readonly) KSQueue *queue;

@end
