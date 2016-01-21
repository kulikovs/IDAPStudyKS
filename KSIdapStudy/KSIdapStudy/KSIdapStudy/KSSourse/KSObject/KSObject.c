//
//  KSObject.c
//  KSIdapStudy
//
//  Created by KulikovS on 20.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include <stdlib.h>
#include <assert.h>

#include "KSObject.h"
#include "KSMacro.h"

struct KSObject {
    int16_t _retainCount;
    void *KSObjectDeallocator;
};

#pragma mark
#pragma mark - Private Implementations

void __KSObjectDeallocate(KSObject *object);

#pragma mark
#pragma mark Initializations and Deallocations

void *KSObjectCreate(size_t size, ) {
    KSObject *object = calloc(1, size);
    
    assert(object);
    
    object->_retainCount = 1;
    
    return object;
}

void __KSObjectDeallocate(KSObject *object) {
    KSReturnMacro(object);
    
    free(object);
}

#pragma mark
#pragma mark - Public Implementations

KSObject *KSObjectRetain(void *object) {
    KSReturnNullMacro(object);
    
    KSObject *newObject = object;
    
//    assert(int16_t < newObject->_retainCount);
    
    newObject->_retainCount++;
    
    return newObject;
}

void KSObjectRelease(void *object) {
    KSReturnMacro(object);
    
    KSObject *newObject = object;
    
    newObject->_retainCount--;
    
    if (newObject->_retainCount == 0) {
        __KSObjectDeallocate(object);
    }
}