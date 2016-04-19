//
//  KSDispatch.h
//  KSIdapStudy
//
//  Created by KulikovS on 18.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^KSHandlerObject)(void);

typedef enum {
    kKSPriorityBackground,
    kKSPriorityMain,
    kKSPriorityHigh,
    kKSPriorityLow,
    kKSPriorityDefault,
} KSDispatchPriority;

void KSDispatchAsyncWithPriority(KSDispatchPriority priority, KSHandlerObject handler);
void KSDispatchAsyncInBackground(KSHandlerObject handler);
void KSDispatchAsyncOnMainThred(KSHandlerObject handler);

void KSDispatchSyncWithPriority(KSDispatchPriority priority, KSHandlerObject handler);
void KSDispatchSyncInBackground(KSHandlerObject handler);
void KSDispatchSyncOnMainThred(KSHandlerObject handler);