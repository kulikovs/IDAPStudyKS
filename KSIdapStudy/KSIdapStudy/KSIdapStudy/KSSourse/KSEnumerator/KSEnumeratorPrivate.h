//
//  KSEnumeratorPrivate.h
//  KSIdapStudy
//
//  Created by KulikovS on 11.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#ifndef KSEnumeratorPrivate_h
#define KSEnumeratorPrivate_h

typedef struct KSEnumerator KSEnumerator;

extern
KSEnumerator *KSEnumeratorCreateWithList(KSLinkedList *list);

extern
KSNode *KSEnumeratorGetNexNode(KSEnumerator *enumerator);

extern
KSNode *KSEnumeratorGetNode(KSEnumerator *enumerator);

extern
bool KSEnumeratorGetIsValid(KSEnumerator *enumerator);

#endif /* KSEnumeratorPrivate_h */
