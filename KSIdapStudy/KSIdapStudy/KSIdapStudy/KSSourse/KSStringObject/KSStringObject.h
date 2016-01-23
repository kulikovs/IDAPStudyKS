//
//  KSStringObject.h
//  KSIdapStudy
//
//  Created by KulikovS on 22.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#ifndef KSStringObject_h
#define KSStringObject_h

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
void KSStringPrint(KSString *string);

#endif /* KSStringObject_h */
