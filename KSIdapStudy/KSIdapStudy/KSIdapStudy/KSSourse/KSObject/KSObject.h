//
//  KSObject.h
//  KSIdapStudy
//
//  Created by KulikovS on 20.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#ifndef KSObject_h
#define KSObject_h

typedef struct KSObject KSObject;

typedef void (KSObjectDeallocator)(void *object);

struct KSObject {
    uint16_t _retainCount;
    KSObjectDeallocator *deallocator;
};

void *KSObjectCreate(size_t size, KSObjectDeallocator *deallocator);

void *KSObjectRetain(void *object);

void KSObjectRelease(void *object);

#endif /* KSObject_h */
