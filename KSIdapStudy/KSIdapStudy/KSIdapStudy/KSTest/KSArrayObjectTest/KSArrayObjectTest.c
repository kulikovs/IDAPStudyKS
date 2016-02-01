//
//  KSArrayObjectTest.c
//  KSIdapStudy
//
//  Created by KulikovS on 26.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSArrayObjectTest.h"
#include "KSStringObject.h"

void KSArrayObjectTest(void) {
    KSArray *array = KSArrayCreate();
    KSString *string0 = KSStringCreateWithSymbols("This is test string");
    KSString *string1 = KSStringCreateWithSymbols("This is test string");
    KSString *string2 = KSStringCreateWithSymbols("This is test string");
    KSString *string3 = KSStringCreateWithSymbols("This is test string");
    KSString *string4 = KSStringCreateWithSymbols("This is test string");
    KSString *string5 = KSStringCreateWithSymbols("This is test string");
    KSString *string6 = KSStringCreateWithSymbols("This is test string");
    KSString *string7 = KSStringCreateWithSymbols("This is test string");
//    KSString *string8 = KSStringCreateWithSymbols("This is test string");
//    KSString *string9 = KSStringCreateWithSymbols("This is test string");
//    KSString *string10 = KSStringCreateWithSymbols("This is test string");
//    KSString *string11 = KSStringCreateWithSymbols("This is test string");
//    KSString *string12 = KSStringCreateWithSymbols("This is test string");
//    KSString *string13 = KSStringCreateWithSymbols("This is test string");
//    KSString *string14 = KSStringCreateWithSymbols("This is test string");
//    KSString *string15 = KSStringCreateWithSymbols("This is test string");
//    KSString *string16 = KSStringCreateWithSymbols("This is test string");
//    KSString *string17 = KSStringCreateWithSymbols("This is test string");
//    KSString *string18 = KSStringCreateWithSymbols("This is test string");
//    KSString *string19 = KSStringCreateWithSymbols("This is test string");
//    KSString *string20 = KSStringCreateWithSymbols("This is test string");
//    
    KSArrayAddObject(array, string0);
    KSArrayAddObject(array, string1);
//    KSArrayRemoveObject(array, string1);
    KSArrayAddObject(array, string2);
    KSArrayAddObject(array, string3);
    KSArrayAddObject(array, string4);
    KSArrayAddObject(array, string5);
    KSArrayAddObject(array, string6);
    KSArrayAddObject(array, string7);
////    KSArrayAddObject(array, string8);
//    KSArrayAddObject(array, string9);
//    KSArrayAddObject(array, string10);
//    KSArrayAddObject(array, string11);
//    KSArrayAddObject(array, string12);
//    KSArrayAddObject(array, string13);
//    KSArrayAddObject(array, string14);
//    KSArrayAddObject(array, string15);
//    KSArrayAddObject(array, string16);
//    KSArrayAddObject(array, string17);
//    KSArrayAddObject(array, string18);
//    KSArrayAddObject(array, string19);
//    KSArrayAddObject(array, string20);
    
    KSArrayRemoveObject(array, string3);
//    
    printf(" start %d", KSArrayGetCount(array));
//
//    KSArrayRemoveObject(array, string3);
//
//    printf("-1 %d", KSArrayGetCount(array));
//    
//    KSArrayRemoveObjectAtIndex(array, 0);
//    
//    printf("- 1 %d", KSArrayGetCount(array));
//    
//    KSObjectRelease(array);
    
}