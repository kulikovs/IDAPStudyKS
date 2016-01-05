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

void  KSPrintByteValueOutputTest() {
    int valueInt = 500640;
    short valueShort = 50;
    char valueChar = 1;
    KSPrintByteValueOutput(&valueShort, sizeof(valueShort));
    KSPrintByteValueOutput(&valueChar, sizeof(valueChar));
    KSPrintByteValueOutput(&valueInt, sizeof(valueInt));
    }


//void KSValueBitOutputTest() {
//    int valueInt = 500640;
//    short valueShort = 50;
//    
//    puts("Value int 500640");
//    KSByteValueOutput(&valueInt, sizeof(valueInt));
//    
//    puts("Value short 50");
//    KSByteValueOutput(&valueShort, sizeof(valueShort));

