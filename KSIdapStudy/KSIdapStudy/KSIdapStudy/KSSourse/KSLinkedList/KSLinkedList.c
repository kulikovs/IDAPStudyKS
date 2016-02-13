//
//  KSLinkedList.c
//  KSIdapStudy
//
//  Created by KulikovS on 06.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSLinkedList.h"
#include "KSMacro.h"
#include "KSLinkedListPrivate.h"
#include "KSEnumeratorPrivate.h"

#pragma mark -
#pragma mark Private Declarations

static
void __KSLinkedListDeallocate(KSLinkedList *linkedList);

static
void KSLinkedListSetCount(KSLinkedList *linkedList, uint64_t count);

static
uint64_t KSLinkedListGetCount(KSLinkedList *linkedList);

static
void KSLinkedListSetHead(KSLinkedList *linkedList, void *node);

static
void KSLinkedListAddNode(KSLinkedList *linkedList, KSNode *node);

static
void KSLinkedListRemoveNode(KSLinkedList *linkedList, KSNode *node);

static
void KSLinkedListSetMutationsCount(KSLinkedList *linkedList, uint64_t count);

#pragma mark -
#pragma mark Initializations and Deallocations

void *KSLinkedListCreate(void){
    KSLinkedList *linkedList = KSObjectCreateMacro(KSLinkedList);
    KSLinkedListSetMutationsCount(linkedList, 0);
    KSLinkedListSetCount(linkedList, 0);
    KSLinkedListSetHead(linkedList, NULL);
    
    return linkedList;
}

void __KSLinkedListDeallocate(KSLinkedList *linkedList){
    KSReturnMacro(linkedList);
    KSLinkedListSetHead(linkedList, NULL);
    KSLinkedListSetMutationsCount(linkedList, 0);
    
    __KSObjectDeallocate(linkedList);
}

#pragma mark -
#pragma mark Accessors

void KSLinkedListSetCount(KSLinkedList *linkedList, uint64_t count) {
    KSReturnMacro(linkedList);
    
    linkedList->_count = count;
    
    uint64_t mutationsCount = KSLinkedListGetMutationsCount(linkedList);
    KSLinkedListSetMutationsCount(linkedList, mutationsCount + 1);
}

uint64_t KSLinkedListGetCount(KSLinkedList *linkedList) {
    KSReturnNullMacro(linkedList, 0);
    
    return linkedList->_count;
}

void KSLinkedListSetHead(KSLinkedList *linkedList, void *node) {
    KSReturnMacro(linkedList);
    
    KSRetainSetter(linkedList->_head, node);
}

void *KSLinkedListGetHead(KSLinkedList *linkedList){
    KSReturnNullMacro(linkedList, NULL);
    
    return linkedList->_head;
}

void KSLinkedListSetMutationsCount(KSLinkedList *linkedList, uint64_t count) {
    KSReturnMacro(linkedList);
    
    linkedList->_mutationsCount = count;
}

uint64_t KSLinkedListGetMutationsCount(KSLinkedList *linkedList) {

    return linkedList->_mutationsCount;
}

#pragma mark -
#pragma mark Public Implimentations

void KSLinkedListAddObject(KSLinkedList *linkedList, void *object) {
    KSReturnMacro(linkedList);
    
    KSNode *node = KSNodeCreateWithObject(object);
    KSLinkedListAddNode(linkedList, node);

    KSObjectRelease(node);
}

bool KSLinkedListContainsObject(KSLinkedList *linkedList, void *object) {
    KSReturnNullMacro(linkedList, NULL);
    
    KSEnumerator *enumerator = KSEnumeratorCreateWithList(linkedList);
    KSNode *node = KSEnumeratorGetNode(enumerator);
    bool isContains = false;
    
    while (node) {
        if (KSEnumeratorGetIsValid(enumerator)) {
            if (KSNodeGetObject(node) == object) {
                isContains = true;
                break;
            }
            node = KSEnumeratorGetNexNode(enumerator);
        }
    }

    KSObjectRelease(enumerator);
    
    return isContains;
}

void KSLinkedListRemoveObject(KSLinkedList *linkedList, void *object) {
    KSReturnMacro(linkedList);
    
    if (KSLinkedListContainsObject(linkedList, object)) {
        KSEnumerator *enumerator = KSEnumeratorCreateWithList(linkedList);
        KSNode *node = KSEnumeratorGetNode(enumerator);
        
        while (object != KSNodeGetObject(node)) {
            node = KSEnumeratorGetNexNode(enumerator);
        }
        
        KSLinkedListRemoveNode(linkedList, node);
        KSObjectRelease(enumerator);
    }
}

void KSLinkedListRemoveAllObject(KSLinkedList *linkedList) {
    KSReturnMacro(linkedList);
    
    KSLinkedListSetHead(linkedList, NULL);
}

#pragma mark -
#pragma mark Private Implimentations

void KSLinkedListAddNode(KSLinkedList *linkedList, KSNode *node) {
    KSReturnMacro(linkedList);
    
    KSNodeSetNextNode(node, KSLinkedListGetHead(linkedList));
    KSLinkedListSetHead(linkedList, node);
    KSLinkedListSetCount(linkedList, KSLinkedListGetCount(linkedList) + 1);
}

void KSLinkedListRemoveNode(KSLinkedList *linkedList, KSNode *node) {
    KSReturnMacro(linkedList);
    
    KSEnumerator *enumerator = KSEnumeratorCreateWithList(linkedList);
    KSNode *firstNode = NULL;
    KSNode *secondNode = KSEnumeratorGetNode(enumerator);
    
    if (secondNode == node) {
        KSLinkedListSetHead(linkedList, KSNodeGetNextNode(node));
    } else {
        while (secondNode != node) {
            firstNode = secondNode;
            secondNode = KSEnumeratorGetNexNode(enumerator);
        }
    }
    
    KSNodeSetNextNode(firstNode, KSNodeGetNextNode(node));
    KSLinkedListSetCount(linkedList, KSLinkedListGetCount(linkedList) - 1);
}