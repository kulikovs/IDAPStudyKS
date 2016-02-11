//
//  KSEnumerator.h
//  KSIdapStudy
//
//  Created by KulikovS on 10.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#ifndef KSEnumerator_h
#define KSEnumerator_h

#include <stdio.h>
#include <stdbool.h>

#include "KSObject.h"
#include "KSLinkedList.h"
#include "KSNode.h"

typedef struct KSEnumerator KSEnumerator;
typedef struct KSLinkedList KSLinkedList;

struct KSEnumerator {
    KSObject *_super;
    KSLinkedList *_list;
    KSNode *node;
    uint64_t _mutationsCount;
    bool _isValid;
};

extern
KSEnumerator *KSEnumeratorCreateWithList(KSLinkedList *list);

extern
KSLinkedList *KSEnumeratorGetLinkedList(KSEnumerator *enumerator);

extern
void KSEnumeratorSetNode(KSEnumerator *enumerator, KSNode *node);

extern
KSNode *KSEnumeratorGetNode(KSEnumerator *enumerator);

#endif /* KSEnumerator_h */
