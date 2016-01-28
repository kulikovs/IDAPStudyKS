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
    uint8_t countObject;
};

extern
void *KSArrayCreate(void);

extern
void KSArraySetObjectAtIndex(KSArray *array, void *object, int index);

extern
uint8_t KSArrayGetCountObject(KSArray *array);

extern
void *KSArrayGetObjectAtIndex(KSArray *array, int index);

extern
uint8_t KSArrayGetIndexOfObject(KSArray *array, void *object);

extern
void KSArrayAddObject(KSArray *array, void *object);

extern
void KSArrayRemoveObjectAtIndex(KSArray *array, void *object, int index);

extern
void KSArrayRemoveAllObjects(KSArray *array);

extern
void KSArrayRemoveObjects(KSArray *array, void *object);

extern
void *KSArrayGetFirstObject(KSArray *array);

extern
void *KSArrayGetLastObject(KSArray *array);

#endif /* KSArrayObject_h */
