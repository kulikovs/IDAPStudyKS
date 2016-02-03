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

const int kKSCapasityMinimum = 5;
const uint64_t kKSUndefineCount = UINT64_MAX;

#pragma mark -
#pragma mark Privat Declarations

static
void __KSArrayDeallocate(KSArray *array);

static
void KSArraySetData(KSArray *array, void **arrayData);

static
void KSArraySetCount(KSArray *array, uint64_t count);

static
void KSArraySetObjectAtIndex(KSArray *array, void *object, uint64_t index);

static
void KSArrayShiftObjectsFromIndex(KSArray *array, uint8_t index);

static
void KSArraySetCapacity(KSArray *array,  uint64_t capacity);

static
bool KSArrayNeedToChangeSize(KSArray *array);

static
uint64_t KSArrayCapasityResizeIfNeeded(KSArray *array);

#pragma mark -
#pragma mark Initializations and Deallocations

void *KSArrayCreate(void) {
    KSArray *array = KSObjectCreateMacro(KSArray);
    KSArraySetCount(array, 0);
    KSArraySetCapacity(array, 10);

    return array;
}

void __KSArrayDeallocate(KSArray *array) {
        KSArrayRemoveAllObjects(array);
        __KSObjectDeallocate(array);
}

#pragma mark -
#pragma mark Accessors

void KSArraySetData(KSArray *array, void **arrayData) {

    array->_arrayData = arrayData;
}

void **KSArrayGetData(KSArray *array) {
    KSReturnNullMacro(array);
    
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

uint64_t KSArrayGetCapasity(KSArray *array) {
    KSReturnZeroMacro(array);
    
    return array->_capacity;
}

void KSArraySetCount(KSArray *array, uint64_t count) {
    KSReturnMacro(array);
    
    array->_count = count;
}

uint64_t KSArrayGetCount(KSArray *array) {
    KSReturnZeroMacro(array);
    
    return array->_count;
}

void KSArraySetObjectAtIndex(KSArray *array, void *object, uint64_t index) {
    KSReturnMacro(array);
    
    KSRetainSetter(array->_arrayData[index], object);

}

void *KSArrayGetObjectAtIndex(KSArray *array, uint64_t index) {
    KSReturnNullMacro(array);
    
    return array->_arrayData[index];
}

uint8_t KSArrayGetIndexOfObject(KSArray *array, void *object) {

    uint64_t indexObject = kKSUndefineCount;
    
    if (NULL != object && NULL != array ) {
        for (int index = 0; index < KSArrayGetCount(array); index++) {
            if (KSArrayGetObjectAtIndex(array, index) == object) {
                indexObject = index;
            }
        }
    }
    
    return indexObject;
}

#pragma mark -
#pragma mark Public Implementations

bool KSArrayIsContainsObject(KSArray *array, void *object) {
 
    return KSArrayGetIndexOfObject(array, object) != kKSUndefineCount ? true : false;
}

void KSArrayAddObject(KSArray *array, void *object) {
    KSReturnMacro(array);
    
    if (KSArrayNeedToChangeSize(array)) {
        KSArraySetCapacity(array, KSArrayCapasityResizeIfNeeded(array));
    }

    KSArraySetObjectAtIndex(array, object, KSArrayGetCount(array));
    KSArraySetCount(array, (KSArrayGetCount(array) + 1));
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
    
    if (KSArrayNeedToChangeSize(array)) {
        KSArraySetCapacity(array, KSArrayCapasityResizeIfNeeded(array));
    }
}

void KSArrayRemoveAllObjects(KSArray *array) {
    KSReturnMacro(array);
    
   for (uint64_t index = KSArrayGetCount(array); index != 0; index--) {
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

uint64_t KSArrayCapasityResizeIfNeeded(KSArray *array) {
    KSReturnZeroMacro(array);
    
    uint64_t count = KSArrayGetCount(array);
    uint64_t capasity = KSArrayGetCapasity(array);
    
    if (count < capasity / 2) {
        capasity = capasity / 2;
    } else {
        capasity = capasity * 1.5;
    }
    
    return capasity;
}

bool KSArrayNeedToChangeSize(KSArray *array) {
    KSReturnNullMacro(array);
    
    uint64_t count = KSArrayGetCount(array);
    uint64_t capasity = KSArrayGetCapasity(array);
    
    if ((count >= capasity / 2) && (count < capasity - 1)) {
        return false;
    }
    
    return true;
}
