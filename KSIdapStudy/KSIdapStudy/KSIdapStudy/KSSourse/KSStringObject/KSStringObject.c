//
//  KSStringObject.c
//  KSIdapStudy
//
//  Created by KulikovS on 22.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "KSStringObject.h"
#include "KSMacro.h"

#pragma mark -
#pragma mark - Privat Declarations

static
KSString *KSStringCreate(void);

static
void __KSStringDeallocate(KSString *sting);

static
void KSStringSetCount(KSString *string);

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
    
    free(string->_symbols);
    
    if (NULL != symbols) {
        string->_symbols = strdup(symbols);
        KSStringSetCount(string);
    } else {
        string->_symbols = NULL;
    }
}

char *KSStringGetSymbols(KSString *string) {
    KSReturnNullMacro(string);
    
    return string->_symbols;
}

void KSStringSetCount(KSString *string) {
    KSReturnMacro(string);
    
    for (int index = 0; KSStringGetSymbols(string)[index] != '\0'; index++) {
        string->_countSymbols = index;
    }
}

uint8_t KSStringGetCount(KSString *string) {
    KSReturnNullMacro(string);
    
    return string->_countSymbols;
}

#pragma mark -
#pragma mark - Public Implementations

void KSPrintString(KSString *string) {
    puts(KSStringGetSymbols(string));
}

bool KSStringIsEqual(KSString *firstString, KSString *secondString) {
    KSReturnNullMacro(firstString);
    KSReturnNullMacro(secondString);
    
    bool stringsEqual = false;
    
    if (0 == strcmp(KSStringGetSymbols(firstString),
                    KSStringGetSymbols(secondString))) {
        stringsEqual = true;
    }
    
    return stringsEqual;
}

KSString *KSStringWithString(KSString *firstString, KSString *secondString) {
    KSReturnNullMacro(firstString);
    
    if (!secondString) {
        return firstString;
    }
    
    int sumCounters = KSStringGetCount(firstString) + KSStringGetCount(secondString);
    char *charString = calloc(sumCounters, sizeof(char));
    strcat(charString, KSStringGetSymbols(firstString));
    strcat(charString, KSStringGetSymbols(secondString));
    
    KSString *newString = KSStringCreateWithSymbols(charString);
    assert(newString);
    
    return newString;
}
