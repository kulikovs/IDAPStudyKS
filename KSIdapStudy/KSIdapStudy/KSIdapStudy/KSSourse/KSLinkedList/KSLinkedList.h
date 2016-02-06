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
    KSNode *_nodeBegin;
    uint64_t _count;
};

extern
void *KSLinkedListCreate(void);

extern
uint64_t KSLinkedListGetCount(KSLinkedList *linkedList);

extern
void *KSLinkedListGetNodeBegin(KSLinkedList *linkedList);

#endif /* KSLinkedList_h */
