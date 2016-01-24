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
    KSStringResultComparisonsBySymbols(string, stringCopy);
    puts(KSStringGetSymbols(string));
    KSStringPrintSymbols(string);
   // KSStringSetCountSymbols(string);
    KSStringAddInSymbol(string, addString);
    printf("CountSymbols - %d\n", KSStringGetCountSymbols(string));
    KSObjectRelease(string);
    
  //  KSStringAddInSymbol(string, "add");
    puts(KSStringGetSymbols(string));
}