//
//  KSLinkedListTest.c
//  KSIdapStudy
//
//  Created by KulikovS on 06.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSLinkedListTest.h"
#include "KSStringObject.h"


void KSLinkedListTest(void) {

    KSLinkedList *linkedList = KSLinkedListCreate();
    
    KSString *string = KSStringCreateWithSymbols("This is test string");
    KSString *string1 = KSStringCreateWithSymbols("- add");
    KSString *string2 = KSStringCreateWithSymbols("This is test string");
    KSString *string3 = KSStringCreateWithSymbols("This is test string");
    KSString *string4 = KSStringCreateWithSymbols("This is test string");
    
    KSLinkedListAddObject(linkedList, string);
    KSLinkedListAddObject(linkedList, string1);
    KSLinkedListAddObject(linkedList, string2);
    KSLinkedListAddObject(linkedList, string3);
    KSLinkedListAddObject(linkedList, string4);

  //  KSLinkedListRemoveObject(linkedList, string1);
    KSLinkedListRemoveAllObject(linkedList);
    puts(KSLinkedListGetFirstObject(linkedList));
}