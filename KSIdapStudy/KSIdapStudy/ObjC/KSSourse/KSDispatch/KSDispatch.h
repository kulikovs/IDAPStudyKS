//
//  KSDispatch.h
//  KSIdapStudy
//
//  Created by KulikovS on 18.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^KSDispatchHandler)(void);

typedef enum {
    kKSPriorityBackground,
    kKSPriorityMain,
    kKSPriorityHigh,
    kKSPriorityLow,
    kKSPriorityDefault,
} KSDispatchPriority;

void KSDispatchAsyncWithPriority(KSDispatchPriority priority, KSDispatchHandler handler);
void KSDispatchAsyncInBackground(KSDispatchHandler handler);
void KSDispatchAsyncOnMainThred(KSDispatchHandler handler);

void KSDispatchSyncWithPriority(KSDispatchPriority priority, KSDispatchHandler handler);
void KSDispatchSyncInBackground(KSDispatchHandler handler);
void KSDispatchSyncOnMainThred(KSDispatchHandler handler);