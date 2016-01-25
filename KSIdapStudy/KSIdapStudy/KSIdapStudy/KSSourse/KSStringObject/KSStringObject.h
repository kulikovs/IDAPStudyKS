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
    char *_symbols;
    uint8_t _countSymbols;
};

extern
KSString *KSStringCreateWithSymbols(char *symbols);

extern
void KSStringSetSymbols(KSString *string, char *symbols);

extern
char *KSStringGetSymbols(KSString *string);

extern
void KSPrintString(KSString *string);

extern
KSString *KSStringWithString(KSString *firstString, KSString *secondString);

extern
uint8_t KSStringGetCount(KSString *string);

extern
bool KSStringIsEqual(KSString *firstString, KSString *secondString);

#endif /* KSStringObject_h */
