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
void KSLinkedListSetNodeBegin(KSLinkedList *linkedList, void *node);

#pragma mark -
#pragma mark Initializations and Deallocations

void *KSLinkedListCreate(void){
    KSLinkedList *linkedList = KSObjectCreateMacro(KSLinkedList);
    KSLinkedListSetCount(linkedList, 0);
    KSLinkedListSetNodeBegin(linkedList, NULL);
    
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

void KSLinkedListSetNodeBegin(KSLinkedList *linkedList, void *node) {
    KSReturnMacro(linkedList);
    
    linkedList->_nodeBegin = node;
}

void *KSLinkedListGetNodeBegin(KSLinkedList *linkedList){
    KSReturnNullMacro(linkedList, NULL);
    
    return linkedList->_nodeBegin;
}

#pragma mark -
#pragma mark Private Implimentations

