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

KSObject *KSObjectCreate(size_t size);

KSObject *KSObjectRetain(KSObject *object);

void KSObjectRelease(KSObject *object);

#endif /* KSObject_h */
