//
//  KSArrayObject.c
//  KSIdapStudy
//
//  Created by KulikovS on 25.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "KSArrayObject.h"
#include "KSMacro.h"

const int kKSCapacityMinimum = 5;
const uint64_t kKSUndefineCount = UINT64_MAX;

#pragma mark -
#pragma mark Private Declarations

static
void __KSArrayDeallocate(KSArray *array);

static
void KSArraySetData(KSArray *array, void **arrayData);

static
void KSArraySetCount(KSArray *array, uint64_t count);

static
void KSArraySetObjectAtIndex(KSArray *array, void *object, uint64_t index);

static
void KSArrayShiftObjectsFromIndex(KSArray *array, uint64_t index);

static
void KSArraySetCapacity(KSArray *array,  uint64_t capacity);

static
bool KSArrayNeedToChangeSize(KSArray *array);

static
void KSArrayResizeIfNeeded(KSArray *array);

static
uint64_t KSArrayRecomendedSize(KSArray *array);

#pragma mark -
#pragma mark Initializations and Deallocations

void *KSArrayCreate(void) {
    KSArray *array = KSObjectCreateMacro(KSArray);
    KSArraySetCount(array, 0);
    KSArraySetCapacity(array, 0);

    return array;
}

void __KSArrayDeallocate(KSArray *array) {
        KSArrayRemoveAllObjects(array);
        __KSObjectDeallocate(array);
}

#pragma mark -
#pragma mark Accessors

void KSArraySetData(KSArray *array, void **arrayData) {
    KSReturnMacro(array);

    array->_arrayData = arrayData;
}

void **KSArrayGetData(KSArray *array) {
    KSReturnNullMacro(array, NULL);
    
    return array->_arrayData;
}

void KSArraySetCapacity(KSArray *array, uint64_t capacity) {
    KSReturnMacro(array);
 
    size_t size = sizeof(void *);
    uint64_t count = KSArrayGetCount(array);
    
    KSArraySetData(array, realloc(KSArrayGetData(array), capacity * size));
    
    memset(&array->_arrayData[count], 0, (capacity - count) * size);
    array->_capacity = capacity;
}

uint64_t KSArrayGetCapacity(KSArray *array) {
    KSReturnNullMacro(array, 0);
    
    return array->_capacity;
}

void KSArraySetCount(KSArray *array, uint64_t count) {
    KSReturnMacro(array);
    
    array->_count = count;
}

uint64_t KSArrayGetCount(KSArray *array) {
    KSReturnNullMacro(array, 0);
    
    return array->_count;
}

void KSArraySetObjectAtIndex(KSArray *array, void *object, uint64_t index) {
    KSReturnMacro(array);
    
    KSRetainSetter(array->_arrayData[index], object);
}

void *KSArrayGetObjectAtIndex(KSArray *array, uint64_t index) {
    KSReturnNullMacro(array, NULL);
    
    return array->_arrayData[index];
}

uint8_t KSArrayGetIndexOfObject(KSArray *array, void *object) {
    KSReturnNullMacro(array, kKSUndefineCount);
    KSReturnNullMacro(object, kKSUndefineCount);

    uint64_t indexObject = kKSUndefineCount;
    
    for (int index = 0; index < KSArrayGetCount(array); index++) {
        if (KSArrayGetObjectAtIndex(array, index) == object) {
            indexObject = index;
        }
    }
    
    return indexObject;
}

#pragma mark -
#pragma mark Public Implementations

bool KSArrayContainsObject(KSArray *array, void *object) {
    KSReturnNullMacro(array, NULL);
 
    return KSArrayGetIndexOfObject(array, object) != kKSUndefineCount ? true : false;
}

void KSArrayAddObject(KSArray *array, void *object) {
    KSReturnMacro(array);
    
    KSArrayResizeIfNeeded(array);
    
    KSArraySetObjectAtIndex(array, object, KSArrayGetCount(array));
    KSArraySetCount(array, (KSArrayGetCount(array) + 1));
}

void KSArrayShiftObjectsFromIndex(KSArray *array, uint64_t index) {
    KSReturnMacro(array);
    
    for (; index < KSArrayGetCount(array); index++) {
        
        void *firstObject = KSArrayGetObjectAtIndex(array, index);
        void *secondObject = KSArrayGetObjectAtIndex(array, (index + 1));
        
        if (firstObject == NULL) {
            KSArraySetObjectAtIndex(array, secondObject, index);
            KSArraySetObjectAtIndex(array, NULL, (index + 1));
        }
    }
}

void KSArrayRemoveObjectAtIndex(KSArray *array, uint64_t index) {
    KSReturnMacro(array);
    
    if (KSArrayGetObjectAtIndex(array, index) != NULL) {
        KSArraySetObjectAtIndex(array, NULL, index);
        KSArrayShiftObjectsFromIndex(array, index);
    }
    
    KSArraySetCount(array, (KSArrayGetCount(array) - 1));
}

void KSArrayRemoveObject(KSArray *array, void *object) {
    KSReturnMacro(array);
    KSReturnMacro(object);
    
    for (uint8_t index = 0; index < KSArrayGetCount(array); index++) {
        if (KSArrayGetObjectAtIndex(array, index) == object) {
            KSArrayRemoveObjectAtIndex(array, index);
        }
    }

    KSArrayResizeIfNeeded(array);
}

void KSArrayRemoveAllObjects(KSArray *array) {
    KSReturnMacro(array);
    
   for (uint64_t index = KSArrayGetCount(array); index != 0; index--) {
       KSArrayRemoveObjectAtIndex(array, index);
       
   }
    KSArraySetCapacity(array, 0);
}

void *KSArrayGetFirstObject(KSArray *array) {
    KSReturnNullMacro(array, NULL);

    return KSArrayGetObjectAtIndex(array, 0);
}

void *KSArrayGetLastObject(KSArray *array) {
    KSReturnNullMacro(array, NULL);

    return KSArrayGetObjectAtIndex(array, (KSArrayGetCount(array) - 1));
}

#pragma mark -
#pragma mark Private Implementations

uint64_t KSArrayRecomendedSize(KSArray *array){
    KSReturnNullMacro(array, 0);
    
    uint64_t count = KSArrayGetCount(array);
    uint64_t capacity = KSArrayGetCapacity(array);
    
    if (count == capacity) {
        capacity = capacity + kKSCapacityMinimum + (capacity * 1.2);
    } else {
        capacity = capacity * 0.9;
    }
    
    return capacity;
}

void KSArrayResizeIfNeeded(KSArray *array) {
    KSReturnMacro(array);
    
    if (KSArrayNeedToChangeSize(array)) {
        KSArraySetCapacity(array, KSArrayRecomendedSize(array));
    }
}

bool KSArrayNeedToChangeSize(KSArray *array) {
    KSReturnNullMacro(array, NULL);
    
    uint64_t count = KSArrayGetCount(array);
    uint64_t capacity = KSArrayGetCapacity(array);

    return (count == capacity || count + kKSCapacityMinimum < (capacity * 0.8));
}
