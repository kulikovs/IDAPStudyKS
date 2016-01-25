//
//  KSStringObjectTest.c
//  KSIdapStudy
//
//  Created by KulikovS on 22.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSStringObjectTest.h"

void KSStringObjectTest(void){

   KSString *string = KSStringCreateWithSymbols("This is test string");
    KSString *addString = KSStringCreateWithSymbols("- add");
    KSString *stringCopy = KSStringCreateWithSymbols("This is test string");
    puts(KSStringGetSymbols(string));
 //   KSStringPrint(string);
   // KSStringSetCountSymbols(string);
    printf("CountSymbols - %d\n", KSStringGetCount(string));
    KSObjectRelease(string);
    
  //  KSStringAddInSymbol(string, "add");
    puts(KSStringGetSymbols(string));
}