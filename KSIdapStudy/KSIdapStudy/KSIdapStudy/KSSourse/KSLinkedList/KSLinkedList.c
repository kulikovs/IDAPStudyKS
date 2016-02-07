//
//  KSLinkedList.c
//  KSIdapStudy
//
//  Created by KulikovS on 06.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSLinkedList.h"
#include "KSMacro.h"

#pragma mark -
#pragma mark Private Declarations

static
void __KSLinkedListDeallocate(KSLinkedList *linkedList);

static
void KSLinkedListSetCount(KSLinkedList *linkedList, uint64_t count);

//static
//void KSLinkedListSetNodeBegin(KSLinkedList *linkedList, void *node);

#pragma mark -
#pragma mark Initializations and Deallocations

void *KSLinkedListCreate(void){
    KSLinkedList *linkedList = KSObjectCreateMacro(KSLinkedList);
    KSLinkedListSetCount(linkedList, 0);
    KSLinkedListSetNodeHead(linkedList, NULL);
    
    return linkedList;
}

void __KSLinkedListDeallocate(KSLinkedList *linkedList){
    KSReturnMacro(linkedList);
    
    __KSObjectDeallocate(linkedList);
}

#pragma mark -
#pragma mark Accessors

void KSLinkedListSetCount(KSLinkedList *linkedList, uint64_t count) {
    KSReturnMacro(linkedList);
    
    linkedList->_count = count;
}

uint64_t KSLinkedListGetCount(KSLinkedList *linkedList) {
   // KSReturnNullMacro(linkedList, 0);
    
    return linkedList->_count;
}

void KSLinkedListSetNodeHead(KSLinkedList *linkedList, void *node) {
    KSReturnMacro(linkedList);
    
    KSRetainSetter(linkedList->_nodeHead, node);
}

void *KSLinkedListGetNodeHead(KSLinkedList *linkedList){
    KSReturnNullMacro(linkedList, NULL);
    
    return linkedList->_nodeHead;
}

#pragma mark -
#pragma mark Public Implimentations

void KSLinkedListAddObject(KSLinkedList *linkedList, void *object) {
    KSReturnMacro(linkedList);
    
    KSNode *node = KSNodeCreate();
    KSNodeSetObject(node, object);
    
    if (KSLinkedListGetNodeHead(linkedList) == NULL) {
        KSLinkedListSetNodeHead(linkedList, node);
    } else {
        KSNodeSetNextNode(KSLinkedListGetLastNode(linkedList), node);
    }
    
    KSLinkedListSetCount(linkedList, KSLinkedListGetCount(linkedList) + 1);
}

KSNode *KSLinkedListGetNodeOfCount(KSLinkedList *linkedList, uint64_t count) {
    KSReturnNullMacro(linkedList, NULL);
    
    uint64_t index  = 1;
    KSNode *node = KSLinkedListGetNodeHead(linkedList);
    
    while (index != count) {
        node = node->_nextNode;
        index++;
    }
    
    return node;
}

KSNode *KSLinkedListGetLastNode(KSLinkedList *linkedList) {
    KSReturnNullMacro(linkedList, NULL);
    
    KSNode *node = KSLinkedListGetNodeHead(linkedList);
    uint64_t index = 1;
    
    while (index != KSLinkedListGetCount(linkedList)) {
        node = node->_nextNode;
        index++;
    }
    
//    while (node == NULL) {
//        node = node->_nextNode;
//    }
    return node;
}


//void KSLinkedListRemoveObject(KSLinkedList *linkedList, void *object) {
//    KSReturnMacro(linkedList);
//    
//    KSNode *node = KSLinkedListGetNodeHead(linkedList);
//    uint64_t index = 0;
//    
//    if () {
//        <#statements#>
//    }
//    
//    for (uint64_t index = 0; node->_object != object; index++) {
//        <#statements#>
//    }
//    
//}

#pragma mark -
#pragma mark Private Implimentations
