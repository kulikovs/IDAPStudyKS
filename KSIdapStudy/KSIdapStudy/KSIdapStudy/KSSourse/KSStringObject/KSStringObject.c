//
//  KSStringObject.c
//  KSIdapStudy
//
//  Created by KulikovS on 22.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include <stdio.h>

#include "KSStringObject.h"
#include "KSMacro.h"

#pragma mark - 
#pragma mark - Initializations and Deallocations

KSString *KSStringCreate(void) {
    KSString *string = KSObjectCreateMacro(KSString);
    
    return string;
}

KSString *KSStringCreateWithSymbols(char *symbols) {
    KSString *string = KSStringCreate();
    
    KSStringSetSymbols(string, symbols);
    KSStringSetCountSymbols(string);
    
    return string;
}

void __KSStringDeallocate(KSString *string) {
    KSReturnMacro(string);
    
    KSStringSetSymbols(string, NULL);
    __KSObjectDeallocate(string);
}

#pragma mark -
#pragma mark - Accessors

void KSStringSetSymbols(KSString *string, char *symbols) {
    KSReturnMacro(string);
    
    string->symbols = symbols;
}

char *KSStringGetSymbols(KSString *string) {
    KSReturnNullMacro(string);
    
    return string->symbols;
}

void KSStringSetCountSymbols(KSString *string) {
    KSReturnMacro(string);
    
    for (int index = 0; KSStringGetSymbols(string)[index] != '\0'; index++) {
        string->countSymbols = index;
    }
}

uint8_t KSStringGetCountSymbols(KSString *string) {
    KSReturnNullMacro(string);
    
    return string->countSymbols;
}


#pragma mark -
#pragma mark - Public Implementations

void KSStringPrintSymbols(KSString *string) {
    puts(KSStringGetSymbols(string));
}

bool KSStringResultComparisonsBySymbols(KSString *firstString, //function is not working. Bad access
                                        KSString *secondString) {
    KSReturnNullMacro(firstString);
    KSReturnNullMacro(secondString);
    
    bool stringsAreEqual = true;
    int index = 0;
    
    if (firstString->countSymbols == secondString->countSymbols) {
        while (firstString->symbols[index] == secondString->symbols[index]) {
            if (firstString->symbols[index] == '\0') {
                stringsAreEqual = true;
            }
            index++;
        }s
    }else {
        stringsAreEqual = false;
    }
    
    return stringsAreEqual;
}

void KSStringAddInSymbol(KSString *string, KSString *addString) { //function is not working. Bad access
    for (int index = 0; addString->symbols[index] != '\0'; index++) {
        string->symbols[string->countSymbols+index] = addString->symbols[index];
    }
    
}

//void KSStringAddInSymbol(KSString *string, char *symbols) {
//    char *newStirng = string->symbols;
//    char *stringAdd = symbols;
// //   char newSymbols = 0;
//    
//    for (int count = 0; stringAdd[count] != '\0'; count++) {
//        newStirng[string->countSymbols+1] = stringAdd[count];    }
//}