//
//  KSArrayObject.h
//  KSIdapStudy
//
//  Created by KulikovS on 25.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#ifndef KSArrayObject_h
#define KSArrayObject_h

#include <stdbool.h>

#include "KSObject.h"

typedef struct KSArrayObject KSArray;

extern const uint64_t kKSUndefineCount;

struct KSArrayObject {
    KSObject _super;
    void **_arrayData;
    uint64_t _count;
    uint64_t _capacity;
};

extern
void *KSArrayCreate(void);

extern
uint64_t KSArrayGetCount(KSArray *array);

extern
void *KSArrayGetObjectAtIndex(KSArray *array, uint64_t index);

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

extern
uint64_t KSArrayGetCapasity(KSArray *array);

extern
bool KSArrayIsContainsObject(KSArray *array, void *object);

extern
void **KSArrayGetData(KSArray *array);

#endif /* KSArrayObject_h */
