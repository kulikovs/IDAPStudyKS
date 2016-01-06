//
//  KSValueBitOutputTest.c
//  KSIdapStudy
//
//  Created by KulikovS on 04.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSValueBitOutputTest.h"
#include "KSValueBitOutput.h"

#include <stdio.h>

void  KSPrintByteValueOutputTest(void) {
    int valueInt = 500640;
    short valueShort = 50;
    char valueChar = 1;
    
    puts("Value short 50");
    KSPrintByteValueOutput(&valueShort, sizeof(valueShort));
    
    puts("Value char 1");
    KSPrintByteValueOutput(&valueChar, sizeof(valueChar));
    
    puts("Value int 500640");
    KSPrintByteValueOutput(&valueInt, sizeof(valueInt));
}

