//
//  KSStringObject.h
//  KSIdapStudy
//
//  Created by KulikovS on 22.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#ifndef KSStringObject_h
#define KSStringObject_h

#include <stdbool.h>

#include "KSObject.h"

typedef struct KSStringObject KSString;

struct KSStringObject {
    KSObject _super;
    char *symbols;
    uint8_t countSymbols;
};

extern
KSString *KSStringCreate(void);

extern
KSString *KSStringCreateWithSymbols(char *symbols);

extern
void __KSStringDeallocate(KSString *sting);

extern
void KSStringSetSymbols(KSString *string, char *symbols);

extern
char *KSStringGetSymbols(KSString *string);

extern
void KSStringPrintSymbols(KSString *string);

extern
void KSStringAddInSymbol(KSString *string, KSString *addString);

extern
void KSStringSetCountSymbols(KSString *string);

extern
uint8_t KSStringGetCountSymbols(KSString *string);

extern
bool KSStringResultComparisonsBySymbols(KSString *firstString,
                                        KSString *secondString);

#endif /* KSStringObject_h */
