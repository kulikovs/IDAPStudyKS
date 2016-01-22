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