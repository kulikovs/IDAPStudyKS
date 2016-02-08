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

static
uint64_t KSLinkedListGetCount(KSLinkedList *linkedList);

static
void KSLinkedListSetHead(KSLinkedList *linkedList, void *node);

static
void *KSLinkedListGetHead(KSLinkedList *linkedList);

static
KSNode *KSLinkedListGetLastNode(KSLinkedList *linkedList);

#pragma mark -
#pragma mark Initializations and Deallocations

void *KSLinkedListCreate(void){
    KSLinkedList *linkedList = KSObjectCreateMacro(KSLinkedList);
    KSLinkedListSetCount(linkedList, 0);
    KSLinkedListSetHead(linkedList, NULL);
    
    return linkedList;
}

void __KSLinkedListDeallocate(KSLinkedList *linkedList){
    KSReturnMacro(linkedList);
    KSLinkedListSetHead(linkedList, NULL);
    
    __KSObjectDeallocate(linkedList);
}

#pragma mark -
#pragma mark Accessors

void KSLinkedListSetCount(KSLinkedList *linkedList, uint64_t count) {
    KSReturnMacro(linkedList);
    
    linkedList->_count = count;
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

#pragma mark -
#pragma mark Public Implimentations

void KSLinkedListAddObject(KSLinkedList *linkedList, void *object) {
    KSReturnMacro(linkedList);
    
    KSNode *node = KSNodeCreateWithObject(object);
    KSNodeSetNextNode(node, KSLinkedListGetHead(linkedList));
    KSLinkedListSetHead(linkedList, node);
    KSLinkedListSetCount(linkedList, KSLinkedListGetCount(linkedList) + 1);
    
    KSObjectRelease(node);
}


void *KSLinkedListGetFirstObject(KSLinkedList *linkedList) {
    KSReturnNullMacro(linkedList, NULL);
    
   return KSNodeGetObject(KSLinkedListGetHead(linkedList));
}


void *KSLinkedListGetLastObject(KSLinkedList *linkedList) {
    KSReturnNullMacro(linkedList, NULL);
    
   return KSNodeGetObject(KSLinkedListGetLastNode(linkedList));
}


bool KSLinkedListContainsObject(KSLinkedList *linkedList, void *object) {
    KSNode * node = KSLinkedListGetHead(linkedList);

    while (KSNodeGetNextNode(node)) {  // в таком виде не вылавливает обьект в последней ноде. Если изменить как в методе removeObject,
                                        //то тогда надо               условие делать по первой ноде. В любом случае получается дублирование циклов. в обоих методах.
        if (KSNodeGetObject(node) == object) {
            return true;
        }
        
        node = KSNodeGetNextNode(node);
    }
    
    return false;
}

void KSLinkedListRemoveObject(KSLinkedList *linkedList, void *object) {
    KSReturnMacro(linkedList);
    
    if (KSLinkedListContainsObject(linkedList, object)) {
        KSNode *node = KSLinkedListGetHead(linkedList);
        KSNode *nextNode = KSNodeGetNextNode(node);
        
        if (object == KSNodeGetObject(node)) {
            KSLinkedListSetHead(linkedList, nextNode);
        } else {
            while (object != KSNodeGetObject(nextNode)) {
                node = nextNode;
                nextNode = KSNodeGetNextNode(node);
            }
         
            KSNodeSetNextNode(node, KSNodeGetNextNode(nextNode));
        }
        
        KSLinkedListSetCount(linkedList, KSLinkedListGetCount(linkedList) - 1);
    }
}

#pragma mark -
#pragma mark Private Implimentations

KSNode *KSLinkedListGetLastNode(KSLinkedList *linkedList) {
    KSReturnNullMacro(linkedList, NULL);
    
    KSNode *node = KSLinkedListGetHead(linkedList);
    while (NULL != KSNodeGetNextNode(node)) {
        node = KSNodeGetNextNode(node);
    }
    
    return node;
}
