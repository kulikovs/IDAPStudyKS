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
#include <stdbool.h>

#include "KSObject.h"
#include "KSNode.h"

typedef struct KSLinkedList KSLinkedList;

struct KSLinkedList {
    KSObject _super;
    KSNode *_head;
    uint64_t _count;
    uint64_t _mutationsCount;
};

extern
void *KSLinkedListCreate(void);

extern
void KSLinkedListAddObject(KSLinkedList *linkedList, void *object);

extern
void KSLinkedListRemoveObject(KSLinkedList *linkedList, void *object);

extern
bool KSLinkedListContainsObject(KSLinkedList *linkedList, void *object);

extern
void KSLinkedListRemoveAllObject(KSLinkedList *linkedList);

#endif /* KSLinkedList_h */
