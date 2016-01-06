//
//  KSValueBitOutput.c
//  KSIdapStudy
//
//  Created by KulikovS on 04.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSValueBitOutput.h"
#include <stdbool.h>
#include <stdio.h>

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
void KSBitOutputForLittleEndian(char *value);

static
void KSBitOutputForBigEndian(char *value);

static
void KSByteValueOutput(void *value, size_t size, KSEndianTypes type);

#pragma mark -
#pragma mark Private Implementations

KSEndianTypes KSEndianTypeReturn(void) {
    KSTestUnion valueTestUnion;
    valueTestUnion.charValue = 1;
    
    return valueTestUnion.boolValue ? KSLittleEndianType : KSBigEndianType;
}

void KSBitOutputForLittleEndian(char *value) {
    uint8_t bitCount = *value;
    
    for (uint8_t index = kKSValueBit; index > 0; index--) {
        printf("%s", (bitCount >> (index - 1) & 1 ? "1 " : "0 "));
    }
}

void KSBitOutputForBigEndian(char *value) {
    uint8_t bitCount = *value;
    
    for (uint8_t index = 0; index < kKSValueBit; index++) {
        printf("%s", (bitCount >> (index) & 1 ? "1 " : "0 "));
    }
}

void KSByteValueOutput(void *value, size_t size, KSEndianTypes type) {
    char *bitField = (char *)value;
    
    if (type == KSLittleEndianType) {
        for (uint16_t index = 0 ; index < size; index++) {
            KSBitOutputForLittleEndian(&bitField[size - index - 1]);
            printf(", ");
        }
    }
    else {
        for (uint16_t index = size ; index > 0; index--) {
            KSBitOutputForBigEndian(&bitField[size - index]);
            printf(", ");
        }
    }
    
    printf(" \n");
}

#pragma mark -
#pragma mark Public Implementations

void KSPrintByteValueOutput(void *value, size_t size) {
    KSByteValueOutput(value, size, KSEndianTypeReturn());
}