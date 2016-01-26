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
    KSString *string8 = KSStringCreateWithSymbols("This is test string");
    KSArrayAddObject(array, string0);
    KSArrayAddObject(array, string1);
    KSArrayAddObject(array, string2);
    KSArrayAddObject(array, string3);
    KSArrayAddObject(array, string5);
    KSArrayAddObject(array, string6);
    KSArrayAddObject(array, string7);
    KSArrayAddObject(array, string8);
    KSArrayAddObject(array, string4);
    
    KSArrayRemoveObjects(array, string3);

    
    printf("%d", KSArrayGetCountObject(array));
    
    KSArrayRemoveObjectAtIndex(array, string0, 0);
    printf("%d", KSArrayGetCountObject(array));
    
}