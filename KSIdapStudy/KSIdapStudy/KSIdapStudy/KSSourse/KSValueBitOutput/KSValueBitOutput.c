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
    struct {
        bool boolValue1 : 1;
        bool boolValue2 : 1;
        bool boolValue3 : 1;
        bool boolValue4 : 1;
        bool boolValue5 : 1;
        bool boolValue6 : 1;
        bool boolValue7 : 1;
        bool boolValue8 : 1;
    };
    
    char charValue;
} KSTestUnion;

#pragma mark -
#pragma mark Private Declarations

static const char kKSValueBit = 8;

static
KSEndianTypes KSEndianTypeReturn(void);

static
void KSBitOutput(char *value, KSEndianTypes type);

static
void KSByteValueOutput(void *value, size_t size, KSEndianTypes type);

#pragma mark -
#pragma mark Private Implementations

KSEndianTypes KSEndianTypeReturn(void) {
    KSTestUnion valueTestUnion;
    int returnEndianTypes = 1;
    valueTestUnion.charValue = 1; // BigEndian = value 128
    
    if (valueTestUnion.boolValue1 != 1 && valueTestUnion.boolValue8 != 1) {
        returnEndianTypes = KSUndefinedType;
    } else  {
        returnEndianTypes = valueTestUnion.boolValue1 ? KSLittleEndianType : KSBigEndianType;
    }
   
    return returnEndianTypes;
}

void KSBitOutput(char *value, KSEndianTypes type) {
    uint8_t bitCount = *value;
    
    if (type == KSLittleEndianType) {
    for (uint8_t index = kKSValueBit; index > 0; index--) {
        printf("%s", (bitCount >> (index - 1) & 1 ? "1 " : "0 "));
        }
    } else {
        for (uint8_t index = 0; index < kKSValueBit; index++) {
            printf("%s", (bitCount >> (index) & 1 ? "1 " : "0 "));
        }
    }
}

void KSByteValueOutput(void *value, size_t size, KSEndianTypes type) {
    char *bitField = (char *)value;
    if (type == KSUndefinedType) {
        printf("This type not supported");
        return;
    }
    
    if (type == KSLittleEndianType) {
        for (uint16_t index = 0 ; index < size; index++) {
            KSBitOutput(&bitField[size - index - 1], type);
            printf(", ");
        }
    } else {
        for (uint16_t index = size ; index > 0; index--) {
            KSBitOutput(&bitField[size - index], type);
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