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

#define KSObjectCreateMacro(type) \
KSObjectCreate(sizeof(type), (void*) __##type##Deallocate)

struct KSObject {
    uint16_t _retainCount;
    KSObjectDeallocator *deallocator;
};

extern
void *KSObjectCreate(size_t size, KSObjectDeallocator *deallocator);

extern
void __KSObjectDeallocate(void *object);

extern
void *KSObjectRetain(void *object);

extern
void KSObjectRelease(void *object);

#endif /* KSObject_h */
