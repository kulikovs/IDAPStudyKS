//
//  KSLinkedListTest.c
//  KSIdapStudy
//
//  Created by KulikovS on 06.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSLinkedListTest.h"


void KSLinkedListTest(void) {

    KSLinkedList *linkedList = KSLinkedListCreate();
    KSNode *node = KSNodeCreate();
    
    KSLinkedListSetNodeBegin(linkedList, node);
    
    KSLinkedListGetNodeBegin(node);
    KSLinkedListGetCount(linkedList);
}