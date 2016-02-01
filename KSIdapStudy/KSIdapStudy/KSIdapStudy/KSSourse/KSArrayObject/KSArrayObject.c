//
//  KSArrayObject.c
//  KSIdapStudy
//
//  Created by KulikovS on 25.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "KSArrayObject.h"
#include "KSMacro.h"

const uint8_t kKSUndefineCount = UINT8_MAX;

#pragma mark -
#pragma mark Privat Declarations

static
void __KSArrayDeallocate(KSArray *array);

static
void *KSArrayCreateData(KSArray *array);

static
void KSArraySetCount(KSArray *array, uint64_t count);

static
void KSArraySetObjectAtIndex(KSArray *array, void *object, uint8_t index);

static
void KSArrayShiftObjectsFromIndex(KSArray *array, uint8_t index);

static
void KSarraySetCapacity(KSArray *array,  uint64_t capacity);

static
uint64_t KSarrayGetCapacity(KSArray *array);


#pragma mark -
#pragma mark Initializations and Deallocations

void *KSArrayCreate(void) {
    KSArray *array = KSObjectCreateMacro(KSArray);
    array->_arrayData =  KSArrayCreateData(array);

    return array;
}

void __KSArrayDeallocate(KSArray *array) {
        KSArrayRemoveAllObjects(array);
        __KSObjectDeallocate(array);
}

void *KSArrayCreateData(KSArray *array) {
    
    int countArray = 5;
    
    void **arrayData = 0;
    array->_arrayData = calloc(1, sizeof(int64_t*));
    
    for (int index = 0; index < countArray; index++) {
        arrayData = calloc(index, sizeof(int64_t*));
    }
    
    return arrayData;

//void KSArrayCreateData(KSArray *array) {
//    
//    int countArray = 5;
//    
//    void **arrayData = 0;
//    array->_arrayData = calloc(1, sizeof(int64_t*));
//
//    for (int index = 0; index < countArray; index++) {
//        arrayData = calloc(index, sizeof(int64_t*));
//    }
//    
//    array->_arrayData=arrayData;
   // array->_arrayData = calloc(countArray, sizeof(int64_t*));


   // arrayData[countArray] = calloc(countArray, sizeof(array->_arrayData));
}

#pragma mark -
#pragma mark Accessors

void KSarraySetCapacity(KSArray *array, uint64_t capacity) {
    KSReturnMacro(array);
    
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

void KSArraySetObjectAtIndex(KSArray *array, void *object, uint8_t index) {
    KSReturnMacro(array);
    
    KSRetainSetter(array->_arrayData, object);
    KSArraySetCount(array, (KSArrayGetCount(array) + 1));
}

void *KSArrayGetObjectAtIndex(KSArray *array, int index) {
    KSReturnNullMacro(array);

    return array->_arrayData;
}

uint8_t KSArrayGetIndexOfObject(KSArray *array, void *object) {

    uint8_t indexObject = kKSUndefineCount;
    
    if (NULL != object && NULL != array ) {
        for (int index = 0; index < kKSArrayCount; index++) {
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

