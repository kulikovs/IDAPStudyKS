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
};

#pragma mark
#pragma mark - Private Implementations

void __KSDeallocate(KSObject *object);

#pragma mark
#pragma mark Initializations and Deallocations

KSObject *KSObjectCreate(size_t size) {
    KSObject *object = calloc(1, size);
    
    assert(object);
    
    object->_retainCount = 1;
    
    return object;
}

void __KSDeallocate(KSObject *object) {
    KSReturnMacro(object);
    
    free(object);
}

#pragma mark
#pragma mark - Public Implementations

KSObject *KSObjectRetain(KSObject *object) {
    KSReturnNullMacro(object);
    KSObject *newObject = object;
    
    newObject->_retainCount++;
    
    return newObject;
}

void KSObjectRelease(KSObject *object) {
    KSReturnMacro(object);
    
    if (object->_retainCount == 0) {
        __KSDeallocate(object);
    }
}