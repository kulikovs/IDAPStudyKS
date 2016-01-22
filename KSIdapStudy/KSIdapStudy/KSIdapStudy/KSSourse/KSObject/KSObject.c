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

#pragma mark
#pragma mark - Private Implementations

#pragma mark -
#pragma mark - Initializations and Deallocations

void *KSObjectCreate(size_t size, KSObjectDeallocator *deallocator) {
    KSObject *object = calloc(1, size);
    
    assert(object);
    
    object->_retainCount = 1;
    object->deallocator = deallocator;
    
    return object;
}

void __KSObjectDeallocate(void *object) {
    KSReturnMacro(object);
    
    free(object);
}

#pragma mark -
#pragma mark - Public Implementations

void *KSObjectRetain(void *object) {
    KSReturnNullMacro(object);
    
    KSObject *newObject = object;
    
    assert(newObject->_retainCount >0 );
    assert(INT16_MAX > newObject->_retainCount);
    
    newObject->_retainCount++;
    
    return newObject;
}

void KSObjectRelease(void *object) {
    KSReturnMacro(object);
    
    KSObject *newObject = object;
    newObject->_retainCount--;
    
    if (newObject->_retainCount == 0) {
       newObject->deallocator(object);
    }
}