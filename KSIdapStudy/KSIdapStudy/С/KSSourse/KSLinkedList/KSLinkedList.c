//
//  KSLinkedList.c
//  KSIdapStudy
//
//  Created by KulikovS on 06.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include <stdlib.h>
#include <assert.h>

#include "KSLinkedList.h"
#include "KSMacro.h"
#include "KSLinkedListPrivate.h"
#include "KSEnumeratorPrivate.h"

#define KSContextCreateMacro(type, object)\
         type *context = calloc(1, sizeof(type)); \
         assert(context); \
         context->object = object;

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

    KSContextCreateMacro(KSLinkedListContext, object);
    KSNode *node = KSLinkedListGetNodeWithContext(linkedList,
                                                  KSLinkedListNodeContainsObject,
                                                  context);
    free(context);
    
    return node;
}

void KSLinkedListRemoveObject(KSLinkedList *linkedList, void *object) {
    KSReturnMacro(linkedList);
    
    KSContextCreateMacro(KSLinkedListContext, object);
    KSNode *node = KSLinkedListGetNodeWithContext(linkedList,
                                                  KSLinkedListNodeContainsObject,
                                                  context);
    if (node) {
        if (node == KSLinkedListGetHead(linkedList)) {
            KSLinkedListSetHead(linkedList, KSNodeGetNextNode(node));
        } else {
            KSNodeSetNextNode(context->previusNode, KSNodeGetNextNode(node));
        }
        
        KSLinkedListSetCount(linkedList, KSLinkedListGetCount(linkedList) - 1);
    }
    
    free(context);
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

KSNode *KSLinkedListGetNodeWithContext(KSLinkedList *list,
                                       KSLinkedListComparator comparator,
                                       KSLinkedListContext *context)
{
    KSReturnNullMacro(list, NULL);
    
    KSEnumerator *enumerator = KSEnumeratorCreateWithList(list);
    KSNode *node = NULL;
    
    while (KSEnumeratorGetIsValid(enumerator)) {
        node = KSEnumeratorGetNextNode(enumerator);
        context->node = node;
        
        if (comparator(context)) {
            break;
        }
        
        context->previusNode = node;
    }
    
    KSObjectRelease(enumerator);
    
    return node;
}

bool KSLinkedListNodeContainsObject(KSLinkedListContext *context) {
    KSReturnNullMacro(context, NULL);
    
    return KSNodeGetObject(context->node) == context->object;
}