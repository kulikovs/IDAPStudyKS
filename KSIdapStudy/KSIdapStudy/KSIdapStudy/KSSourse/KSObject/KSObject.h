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

typedef void (KSObjectDeallocate) (void object);

void *KSObjectCreate(size_t size);

KSObject *KSObjectRetain(void *object);

void KSObjectRelease(void *object);

#endif /* KSObject_h */
