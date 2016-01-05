//
//  KSValueBitOutput.c
//  KSIdapStudy
//
//  Created by KulikovS on 04.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSValueBitOutput.h"
#include <stdbool.h>


typedef enum {
    KSUndefinedType,
    KSBigEndianType,
    KSLittleEndianType,
} KSEndianTypes;

typedef union {
    bool boolValue : 1;
    char charValue;
} KSTestUnion;

#pragma mark -
#pragma mark Private Declarations

static const char kKSValueBit = 8;



static
KSEndianTypes KSEndianTypeReturn(void);

static
void KSBitOutput(char *value);

static
void KSByteValueOutput(void *value, size_t size, KSEndianTypes type);

#pragma mark -
#pragma mark Private Implementations

KSEndianTypes KSEndianTypeReturn() {
    KSTestUnion valueTestUnion;
    valueTestUnion.charValue = 1;
    
    return valueTestUnion.boolValue == 1 ? KSLittleEndianType : KSBigEndianType;
}

void KSBitOutput(char *value) {
    uint8_t bitCount = *value;
    
    for (uint8_t index = kKSValueBit; index > 0; index--) {
        printf("%s", bitCount >> (index - 1) & 1 ? "1 " : "0 ");
    }
}

#pragma mark -
#pragma mark Public Implementations

void KSByteValueOutput(void *value, size_t size, KSEndianTypes type) {
    char *bitField = (char *)value;
    if (type == KSBigEndianType) {
        for (uint16_t index = 0 ; index < size; index++) {
            char byte = bitField[size - index - 1];
            KSBitOutput(&byte);
            printf(", ");
        }
    }
    else {
        printf("LitleEndian");
    }
    
    printf(" \n");
}

void KSPrintByteValueOutput(void *value, size_t size) {
    void KSByteValueOutput(&value, size_t size, KSEndianTypeReturn());
}