//
//  KSDispatch.m
//  KSIdapStudy
//
//  Created by KulikovS on 18.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSDispatch.h"

#pragma mark -
#pragma mark Private Declarations

static
dispatch_queue_t KSQueueWithPriority(KSDispatchPriority priority);

#pragma mark -
#pragma mark Public Implementations

void KSDispatchAsyncWithPriority(KSDispatchPriority priority, KSHandlerObject handler) {
    dispatch_async(KSQueueWithPriority(priority), handler);
}

void KSDispatchAsyncInBackground(KSHandlerObject handler) {
    KSDispatchAsyncWithPriority(kKSPriorityBackground, handler);
}

void KSDispatchAsyncOnMainThred(KSHandlerObject handler) {
    KSDispatchAsyncWithPriority(kKSPriorityMain, handler);
}

void KSDispatchSyncWithPriority(KSDispatchPriority priority, KSHandlerObject handler) {
    dispatch_async(KSQueueWithPriority(priority), ^{
        dispatch_sync(KSQueueWithPriority(priority), handler);
    });
}

void KSDispatchSyncInBackground(KSHandlerObject handler) {
    KSDispatchSyncWithPriority(kKSPriorityBackground, handler);
}

void KSDispatchSyncOnMainThred(KSHandlerObject handler) {
    KSDispatchSyncWithPriority(kKSPriorityMain, handler);
}


#pragma mark -
#pragma mark Private Implementations

dispatch_queue_t KSQueueWithPriority(KSDispatchPriority priority) {
    switch (priority) {
        case kKSPriorityMain:
            return dispatch_get_main_queue();
            
        case kKSPriorityBackground:
            return dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0);
       
        case kKSPriorityLow:
            return dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0);
            
        case kKSPriorityHigh:
            return dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0);
            
        case kKSPriorityDefault:
            return dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    }
    
    return dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
}



