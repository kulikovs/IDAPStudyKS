//
//  KSEnumerator.c
//  KSIdapStudy
//
//  Created by KulikovS on 10.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSEnumerator.h"
#include "KSMacro.h"

#pragma mark -
#pragma mark Private Declarations

static
void __KSEnumeratorDeallocate(KSEnumerator *enumerator);

static
void KSEnumeratorSetList(KSEnumerator *enumerator, KSLinkedList *list);

static
void KSEnumeratorSetMutationsCount(KSEnumerator *enumerator, uint64_t count);

static
uint64_t KSEnumeratorGetMutationsCount(KSEnumerator *enumerator);

static
void KSEnumeratorSetIsValid(KSEnumerator *enumerator);

#pragma mark -
#pragma mark Initializations and Deallocations

KSEnumerator *KSEnumeratorCreateWithList(KSLinkedList *list) {
    KSEnumerator *enumerator = KSObjectCreateMacro(KSEnumerator);
    KSEnumeratorSetList(enumerator, list);
    
    return enumerator;
}

void __KSEnumeratorDeallocate(KSEnumerator *enumerator) {

    __KSObjectDeallocate(enumerator);
}

#pragma mark -
#pragma mark Accessors

void KSEnumeratorSetList(KSEnumerator *enumerator, KSLinkedList *list) {
    KSReturnMacro(enumerator);
    
    KSRetainSetter(enumerator->_list, list);
}

KSLinkedList *KSEnumeratorGetLinkedList(KSEnumerator *enumerator) {
    KSReturnNullMacro(enumerator, NULL);
    
    return enumerator->_list;
}

void KSEnumeratorSetNode(KSEnumerator *enumerator, KSNode *node) {
    KSReturnMacro(enumerator);
    
    KSRetainSetter(enumerator->node, node);
}

KSNode *KSEnumeratorGetNode(KSEnumerator *enumerator) {
    KSReturnNullMacro(enumerator, NULL);
    
    return enumerator->node;
}

void KSEnumeratorSetMutationsCount(KSEnumerator *enumerator, uint64_t count) {
    KSReturnMacro(enumerator);
    
    enumerator->_mutationsCount = count;
}

uint64_t KSEnumeratorGetMutationsCount(KSEnumerator *enumerator) {
    KSReturnNullMacro(enumerator, 0);
    
    return enumerator->_mutationsCount;
}

void KSEnumeratorSetIsValid(KSEnumerator *enumerator) {
    KSReturnMacro(enumerator);
    
    uint64_t mutationsCount = KSEnumeratorGetMutationsCount(enumerator);
    uint64_t listMutationsCount = KSLinkedListGetMutationsCount(KSEnumeratorGetLinkedList(enumerator));
    enumerator->_isValid = mutationsCount == listMutationsCount ? true : false;
}

bool KSEnumeratorGetIsValid(KSEnumerator *enumerator) {

    return enumerator->_isValid;
}

