//
//  KSLinkedListPrivate.h
//  KSIdapStudy
//
//  Created by KulikovS on 11.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#ifndef KSLinkedListPrivate_h
#define KSLinkedListPrivate_h

typedef struct KSLinkedListContext KSLinkedListContext;

struct KSLinkedListContext {
    KSNode *previusNode;
    KSNode *node;
    void *object;
};

typedef bool (*KSLinkedListComparator)(KSNode *node, KSLinkedListContext *context);

extern
void *KSLinkedListGetHead(KSLinkedList *linkedList);

extern
uint64_t KSLinkedListGetMutationsCount(KSLinkedList *linkedList);

extern
KSNode *KSLinkedListGetNodeWithContext(KSLinkedList *list,
                                       KSLinkedListComparator comparator,
                                       KSLinkedListContext *context);

extern
bool KSLinkedListNodeContainsObject(KSNode *node, KSLinkedListContext *context);

#endif /* KSLinkedListPrivate_h */
