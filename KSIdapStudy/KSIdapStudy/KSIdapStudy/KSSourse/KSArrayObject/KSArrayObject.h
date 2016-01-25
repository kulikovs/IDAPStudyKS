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

struct KSArrayObject {
    KSObject _super;
    void* _arrayData[kKSArrayCount];
};

extern
void *KSArrayCreate(void);

extern
void KSArraySetElementAtIndex(KSArray *array, void *object, int index);

extern
void *KSArrayGetElementAtIndex(KSArray *array, int index);

extern
void KSArrayRemoveElementAtIndex(KSArray *array, void *object, int index);

extern
void KSArrayRemoveAllElements(KSArray *array);

extern
void KSArrayAddElements(KSArray *array, void *object);

#endif /* KSArrayObject_h */
