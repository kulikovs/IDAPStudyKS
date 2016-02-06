//
//  main.c
//  KSIdapStudy
//
//  Created by KulikovS on 29.12.15.
//  Copyright © 2015 KulikovS. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "KSTestMacroOutputType.h"
#include "KSTestStruct.h"
#include "KSValueBitOutputTest.h"
#include "KSHumanTest.h"
#include "KSMacro.h"
#include "KSStringObjectTest.h"
#include "KSArrayObjectTest.h"
#include "KSArrayObject.h"

int main(int argc, const char * argv[]) {

   // KSHumanTest();
//    KSStringObjectTest();
  //  KSArrayObjectTest();
 //  void **array;
    KSArray *array = KSArrayCreate();
    KSString *string1 = KSStringCreateWithSymbols("This is test string");
    KSString *string2 = KSStringCreateWithSymbols("This is test string");
    KSString *string3 = KSStringCreateWithSymbols("This is test string");
    
   
    
    KSArrayAddObject(array, string1);
    KSArrayAddObject(array, string2);
    KSArrayAddObject(array, string3);
//    
//    for (int index = 0; index < 4; index++) {
//        KSArrayAddObject(array, string0);
//    }
    
    KSArrayRemoveObjectAtIndex(array, 1);
    
    KSArrayRemoveAllObjects(array);
    
    array = calloc(3, sizeof(int64_t));
   
    puts("dfsg");
    
    return 0;
}
