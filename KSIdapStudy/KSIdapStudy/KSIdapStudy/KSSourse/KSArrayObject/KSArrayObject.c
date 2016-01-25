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

#pragma mark -
#pragma mark - Privat Declarations

static
void __KSArrayDeallocate(KSArray *array);

#pragma mark -
#pragma mark - Initializations and Deallocations

void *KSArrayCreate(void) {
    KSArray *array = KSObjectCreateMacro(KSArray);
    
    return array;
}

void __KSArrayDeallocate(KSArray *array) {
    
        KSArrayRemoveAllElements(array);
        __KSObjectDeallocate(array);
}


#pragma mark -
#pragma mark - Accessors

void KSArraySetElementAtIndex(KSArray *array, void *object, int index) {
    KSReturnMacro(array);
    
    KSRetainSetter(array->_arrayData[index], object);
}

void *KSArrayGetElementAtIndex(KSArray *array, int index) {

    return  array->_arrayData[index];
}

void KSArrayRemoveElementAtIndex(KSArray *array, void *object, int index) {
    KSReturnMacro(array);
    
    if (KSArrayGetElementAtIndex(array, index) == object) {
        KSArraySetElementAtIndex(array, NULL, index);
    }
}

#pragma mark -
#pragma mark - Public Implementations

void KSArrayRemoveAllElements(KSArray *array) {
    KSReturnMacro(array);
    
   for (int index = 0; index < kKSArrayCount; index++) {
       KSArrayRemoveElementAtIndex(array, KSArrayGetElementAtIndex(array, index), index);
   }
}

void KSArrayAddElements(KSArray *array, void *object) {
    KSReturnMacro(array);
    
    int index = 0;
    
    while (array->_arrayData[index] != NULL) {
        index++;
    }
    
   KSArraySetElementAtIndex(array, object, index);
}