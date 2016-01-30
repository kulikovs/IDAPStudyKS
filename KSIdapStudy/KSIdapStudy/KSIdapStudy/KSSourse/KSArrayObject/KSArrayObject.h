//
//  KSArrayObject.h
//  KSIdapStudy
//
//  Created by KulikovS on 25.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#ifndef KSArrayObject_h
#define KSArrayObject_h

#include "KSObject.h"

static const uint8_t kKSArrayCount = 20;

typedef struct KSArrayObject KSArray;

extern const uint8_t kKSUndefineCount;

struct KSArrayObject {
    KSObject _super;
    void *_arrayData[kKSArrayCount];
    uint8_t count;
};

extern
void *KSArrayCreate(void);

extern
uint8_t KSArrayGetCount(KSArray *array);

extern
void *KSArrayGetObjectAtIndex(KSArray *array, int index);

extern
uint8_t KSArrayGetIndexOfObject(KSArray *array, void *object);

extern
void KSArrayAddObject(KSArray *array, void *object);

extern
void KSArrayRemoveObjectAtIndex(KSArray *array, int index);

extern
void KSArrayRemoveAllObjects(KSArray *array);

extern
void KSArrayRemoveObject(KSArray *array, void *object);

extern
void *KSArrayGetFirstObject(KSArray *array);

extern
void *KSArrayGetLastObject(KSArray *array);

#endif /* KSArrayObject_h */
