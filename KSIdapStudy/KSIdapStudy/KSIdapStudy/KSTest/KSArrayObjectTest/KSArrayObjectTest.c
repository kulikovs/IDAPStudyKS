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
    KSString *string = KSStringCreateWithSymbols("This is test string");
    KSArraySetObjectAtIndex(array, string, 0);
    printf("%d", KSArrayGetCountObject(array));
    KSArrayRemoveObjectAtIndex(array, string, 0);
    printf("%d", KSArrayGetCountObject(array));
    
}