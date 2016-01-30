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
#pragma mark Privat Declarations

static
void __KSArrayDeallocate(KSArray *array);

static
void KSArrayCountCalculation(KSArray *array);

static
void KSArraySetObjectAtIndex(KSArray *array, void *object, uint8_t index);

static
void KSArrayShiftObjectsFromIndex(KSArray *array, uint8_t index);

#pragma mark -
#pragma mark Initializations and Deallocations

void *KSArrayCreate(void) {
    KSArray *array = KSObjectCreateMacro(KSArray);
    
    return array;
}

void __KSArrayDeallocate(KSArray *array) {
        KSArrayRemoveAllObjects(array);
        __KSObjectDeallocate(array);
}

#pragma mark -
#pragma mark Accessors

uint8_t KSArrayGetCount(KSArray *array) {
    KSReturnNullMacro(array);
    
    return array->count;
}

void KSArraySetObjectAtIndex(KSArray *array, void *object, uint8_t index) {
    KSReturnMacro(array);
    
    KSRetainSetter(array->_arrayData[index], object);
    KSArrayCountCalculation(array);
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
#pragma mark Public Implementations

void KSArrayAddObject(KSArray *array, void *object) {
    KSReturnMacro(array);
    
    KSArraySetObjectAtIndex(array, object, KSArrayGetCount(array));

}

void KSArrayShiftObjectsFromIndex(KSArray *array, uint8_t index) {
    KSReturnMacro(array);
    
    for (; index < KSArrayGetCount(array); index++) {
        if (KSArrayGetObjectAtIndex(array, index) == NULL) {
            KSArraySetObjectAtIndex(array, KSArrayGetObjectAtIndex(array, (index + 1)), index);
            KSArraySetObjectAtIndex(array, NULL, index + 1);
        }
    }
}

void KSArrayRemoveObjectAtIndex(KSArray *array, int index) {
    KSReturnMacro(array);
    
    if (KSArrayGetObjectAtIndex(array, index) != NULL) {
        KSArraySetObjectAtIndex(array, NULL, index);
        KSArrayShiftObjectsFromIndex(array, index);
    }
}

void KSArrayRemoveObject(KSArray *array, void *object) {
    KSReturnMacro(array);
    KSReturnMacro(object);
    
    for (uint8_t index = 0; index < kKSArrayCount; index++) {
        if (KSArrayGetObjectAtIndex(array, index) == object) {
            KSArrayRemoveObjectAtIndex(array, index);
        }
    }
}

void KSArrayRemoveAllObjects(KSArray *array) {
    KSReturnMacro(array);
    
   for (int index = 0; index < kKSArrayCount; index++) {
       KSArrayRemoveObjectAtIndex(array, index);
   }
}

void *KSArrayGetFirstObject(KSArray *array) {
    KSReturnNullMacro(array);

    return KSArrayGetObjectAtIndex(array, 0);
}

void *KSArrayGetLastObject(KSArray *array) {
    KSReturnNullMacro(array);

    return KSArrayGetObjectAtIndex(array, (KSArrayGetCount(array) - 1));
}

#pragma mark -
#pragma mark Privat Implementations

void KSArrayCountCalculation(KSArray *array) {
    KSReturnMacro(array);
    
    uint8_t countObject = 0;
    for (int index = 0; index < kKSArrayCount; index++) {
        if (KSArrayGetObjectAtIndex(array, index) != NULL) {
            countObject++;
        }
    }
    
    array->count = countObject;
}