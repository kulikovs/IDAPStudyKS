//
//  KSNode.c
//  KSIdapStudy
//
//  Created by KulikovS on 06.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSNode.h"
#include "KSMacro.h"

#pragma mark -
#pragma mark Private Declarations

static
void __KSNodeDeallocate(KSNode *node);

static
void KSNodeSetNextNode(KSNode *node, KSNode *nextNode);

void KSNodeSetObject(KSNode *node, void *object);

#pragma mark -
#pragma mark Initializations and Deallocations

void *KSNodeCreate(void){
    KSNode *node = KSObjectCreateMacro(KSNode);
    KSNodeSetNextNode(node, NULL);
    KSNodeSetObject(node, NULL);

    return node;
}

void __KSNodeDeallocate(KSNode *node){
    KSReturnMacro(node);
    
    __KSObjectDeallocate(node);
}

#pragma mark -
#pragma mark Accessors

void KSNodeSetNextNode(KSNode *node, KSNode *nextNode) {
    KSReturnMacro(node);
    KSReturnMacro(nextNode);
    
    node->_nextNode = nextNode;
}

void *KSNodeGetNextNode(KSNode *node) {
    KSReturnNullMacro(node, NULL);
    
    return node->_nextNode;
}

void KSNodeSetObject(KSNode *node, void *object) {
    KSReturnMacro(node);
    
    node->_object = object;
}

void *KSNodeGetObject(KSNode *node) {
    KSReturnNullMacro(node, NULL);
    
    return node->_object;
}


#pragma mark -
#pragma mark Private Implimentations