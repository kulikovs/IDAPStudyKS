//
//  KSArrayObject.c
//  KSIdapStudy
//
//  Created by KulikovS on 25.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include <stdio.h>

#include "KSArrayObject.h"
#include "KSMacro.h"

const uint8_t kKSUndefineCount = UINT8_MAX;

#pragma mark -
#pragma mark - Privat Declarations

static
void __KSArrayDeallocate(KSArray *array);

static
void KSArraySetCountObject(KSArray *array);

static
void KSArrayShiftObjects(KSArray *array, uint8_t index);

#pragma mark -
#pragma mark - Initializations and Deallocations

void *KSArrayCreate(void) {
    KSArray *array = KSObjectCreateMacro(KSArray);
    
    return array;
}

void __KSArrayDeallocate(KSArray *array) {
        KSArrayRemoveAllObjects(array);
        __KSObjectDeallocate(array);
}

#pragma mark -
#pragma mark - Accessors

void KSArraySetCountObject(KSArray *array) {
    KSReturnMacro(array);
    
    uint8_t count = 0;
    for (int index = 0; index < kKSArrayCount; index++) {
        if (KSArrayGetObjectAtIndex(array, index) != NULL) {
            count++;
        }
        array->countObject = count;
    }
}

uint8_t KSArrayGetCountObject(KSArray *array) {
    KSReturnNullMacro(array);
    
    return array->countObject;
}

void KSArraySetObjectAtIndex(KSArray *array, void *object, int index) {
    KSReturnMacro(array);
    
    KSRetainSetter(array->_arrayData[index], object);
    KSArraySetCountObject(array);
}

void *KSArrayGetObjectAtIndex(KSArray *array, int index) {
    KSReturnNullMacro(array);

    return array->_arrayData[index];
}

uint8_t KSArrayGetIndexOfObject(KSArray *array, void *object) {
    KSReturnNullMacro(array);
    KSReturnNullMacro(object);
    
    uint8_t indexObject = kKSUndefineCount;
    
    for (int index = 0; index < kKSArrayCount; index++) {
        if (KSArrayGetObjectAtIndex(array, index) == object) {
            indexObject = index;
        }
    }
    return indexObject;
}

#pragma mark -
#pragma mark - Public Implementations

void KSArrayAddObject(KSArray *array, void *object) {
    KSReturnMacro(array);
    
    int index = 0;
    if (index < kKSArrayCount) {
        while (KSArrayGetObjectAtIndex(array, index) != NULL) {
            index++;
        }
        KSArraySetObjectAtIndex(array, object, index);
    }
}

void KSArrayShiftObjects(KSArray *array, uint8_t index) {
    KSReturnMacro(array);
    
    for (; index < KSArrayGetCountObject(array); index++) {
        if (KSArrayGetObjectAtIndex(array, index) == NULL) {
            KSArraySetObjectAtIndex(array, KSArrayGetObjectAtIndex(array, (index + 1)), index);
            KSArraySetObjectAtIndex(array, NULL, index + 1);
        }
    }
}

void KSArrayRemoveObjectAtIndex(KSArray *array, void *object, int index) {
    KSReturnMacro(array);
    
    if (KSArrayGetObjectAtIndex(array, index) == object) {
        KSArraySetObjectAtIndex(array, NULL, index);
    }
    KSArrayShiftObjects(array, index);
    
}

void KSArrayRemoveObjects(KSArray *array, void *object) {
    KSReturnMacro(array);
    KSReturnMacro(object);
    
    for (uint8_t index = 0; index < kKSArrayCount; index++) {
        KSArrayRemoveObjectAtIndex(array, object, index);
    }
}

void KSArrayRemoveAllObjects(KSArray *array) {
    KSReturnMacro(array);
    
   for (int index = 0; index < kKSArrayCount; index++) {
       KSArrayRemoveObjectAtIndex(array, KSArrayGetObjectAtIndex(array, index), index);
   }
}

void *KSArrayGetFirstObject(KSArray *array) {
    KSReturnNullMacro(array);
    
    KSArray *newArray = KSArrayGetObjectAtIndex(array, 0);
    
    if (newArray == NULL) {
        newArray = NULL;
    }
    
    return newArray;
}

void *KSArrayGetLastObject(KSArray *array) {
    KSReturnNullMacro(array);

    return KSArrayGetObjectAtIndex(array, (KSArrayGetCountObject(array) - 1));
}