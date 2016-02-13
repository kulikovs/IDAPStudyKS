//
//  KSEnumerator.c
//  KSIdapStudy
//
//  Created by KulikovS on 10.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSEnumerator.h"
#include "KSMacro.h"
#include "KSLinkedListPrivate.h"
#include "KSEnumeratorPrivate.h"

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
void KSEnumeratorSetValid(KSEnumerator *enumerator, bool valid);

#pragma mark -
#pragma mark Initializations and Deallocations

KSEnumerator *KSEnumeratorCreateWithList(KSLinkedList *list) {
    KSEnumerator *enumerator = KSObjectCreateMacro(KSEnumerator);
    KSEnumeratorSetList(enumerator, list);
    KSEnumeratorSetMutationsCount(enumerator, KSLinkedListGetMutationsCount(list));
    KSEnumeratorSetValid(enumerator, true);
    KSEnumeratorSetNode(enumerator, KSLinkedListGetHead(list));
    
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

void KSEnumeratorSetValid(KSEnumerator *enumerator, bool valid) {
    KSReturnMacro(enumerator);

    enumerator->_isValid = valid;
}

bool KSEnumeratorGetIsValid(KSEnumerator *enumerator) {
    KSReturnNullMacro(enumerator, NULL);

    return enumerator->_isValid;
}

#pragma mark -
#pragma mark Private Implimentations

KSNode *KSEnumeratorGetNexNode(KSEnumerator *enumerator) {
    KSReturnNullMacro(enumerator, NULL);
    
    KSLinkedList *list = KSEnumeratorGetLinkedList(enumerator);
    uint64_t mutationsCountList = KSLinkedListGetMutationsCount(list);
    uint64_t mutationsCountEnumerator = KSEnumeratorGetMutationsCount(enumerator);

    KSNode *nextNode = KSNodeGetNextNode(KSEnumeratorGetNode(enumerator));
    
    if (!KSEnumeratorGetNode(enumerator)) {
        nextNode = KSLinkedListGetHead(list);
    } else {
        KSEnumeratorSetNode(enumerator, nextNode);
    }
    
    if (mutationsCountList != mutationsCountEnumerator || nextNode == NULL) {
        KSEnumeratorSetValid(enumerator, false);
    }
    
    return nextNode;
}
