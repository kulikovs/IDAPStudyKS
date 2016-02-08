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

#pragma mark -
#pragma mark Initializations and Deallocations

void *KSNodeCreateWithObject(void *object) {
    KSNode *node = KSObjectCreateMacro(KSNode);
    KSNodeSetNextNode(node, NULL);
    KSNodeSetObject(node, object);

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
    
    KSRetainSetter(node->_nextNode, nextNode);
}

void *KSNodeGetNextNode(KSNode *node) {
    KSReturnNullMacro(node, NULL);
    
    return node->_nextNode;
}

void KSNodeSetObject(KSNode *node, void *object) {
    KSReturnMacro(node);
    
     KSRetainSetter(node->_object, object);
}

void *KSNodeGetObject(KSNode *node) {
    KSReturnNullMacro(node, NULL);
    
    return node->_object;
}