//
//  KSValueBitOutput.c
//  KSIdapStudy
//
//  Created by KulikovS on 04.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSValueBitOutput.h"
#include <stdbool.h>


typedef union {
    bool boolValue : 1;
    char valueOne;
} KSTestEndian;


#pragma mark -
#pragma mark Private Declarations

static const char kKSValueBit = 8;

static
void KSBitOutput(char *value);

#pragma mark -
#pragma mark Private Implementations

void KSBitOutput(char *value) {
    uint8_t bitCount = *value;
    
    for (uint8_t index = kKSValueBit; index > 0; index--) {
        uint8_t shiftBitValue = bitCount >> (index - 1);
        printf("%s", (shiftBitValue & 1 ? "1 " : "0 "));
    }
}

#pragma mark -
#pragma mark Public Implementations

void KSByteValueOutput (void *value, size_t size) {
    char *bitField = (char *)value;
    uint16_t index = 0;
    
    while (index < size) {
        char byte = bitField[size - index - 1];
        KSBitOutput(&byte);
        index ++;
        printf(", ");
    }
//    for (uint16_t index = 0 ; index < size; index ++) {
//        char byte = bitField[size - index - 1];
//        KSBitOutput(&byte);
//        printf(", ");
//    }
    
    printf(" \n");
}