//
//  KSLinkedList.h
//  KSIdapStudy
//
//  Created by KulikovS on 06.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#ifndef KSLinkedList_h
#define KSLinkedList_h

#include <stdio.h>

#include "KSObject.h"
#include "KSNode.h"

typedef struct KSLinkedList KSLinkedList;

struct KSLinkedList {
    KSObject _super;
    KSNode *_nodeHead;
    uint64_t _count;
};

extern
void *KSLinkedListCreate(void);

extern
uint64_t KSLinkedListGetCount(KSLinkedList *linkedList);

extern
void KSLinkedListSetNodeHead(KSLinkedList *linkedList, void *node);

extern
void *KSLinkedListGetNodeHead(KSLinkedList *linkedList);

extern
void KSLinkedListAddObject(KSLinkedList *linkedList, void *object);

extern
KSNode *KSLinkedListGetNodeOfCount(KSLinkedList *linkedList, uint64_t count);

extern
KSNode *KSLinkedListGetLastNode(KSLinkedList *linkedList);

extern
void KSLinkedListRemoveObject(KSLinkedList *linkedList, void *object);

#endif /* KSLinkedList_h */
