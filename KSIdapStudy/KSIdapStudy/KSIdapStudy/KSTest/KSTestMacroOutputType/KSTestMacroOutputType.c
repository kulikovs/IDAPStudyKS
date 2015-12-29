//
//  KSTestOutputType.c
//  KSMacrosPrintOutputType
//
//  Created by KulikovS on 26.12.15.
//  Copyright © 2015 KulikovS. All rights reserved.
//

#include "KSTestMacroOutputType.h"
#include "KSMacro.h"

#include <stdio.h>
#include <stdbool.h>

KSOutputType(long, %lu)
KSOutputType(int, %d)
//KSOutputType(char, %s)
KSOutputType(double, %f)
KSOutputType(bool, %d)

void KSTestMacroOutputType() {
    puts("\t\tPrint size type using macro 'KSPrintSizeType'");
    
    puts("We waiting -  type int = 4");
    KSPrintSizeType(int)
    
    puts("We waiting -  type char = 1");
    KSPrintSizeType(char)
    
    puts("We waiting -  type short = 2");
    KSPrintSizeType(short)
    
    puts("We waiting -  type double = 8");
    KSPrintSizeType(double)
    
    puts("We waiting -  type long = 8");
    KSPrintSizeType(long)
    
    puts("\n\t\tPrint value using macro 'KSOutputTypeMacro'");
    
    puts("We waiting -  number = 8");
    KSOutputTypeMacro(int, 8);
    
//    puts("We waiting - string 'Hello'");
//    KSOutputTypeMacro(char, "Hello");
    
    puts("We waiting -  number = 5000000");
    
    KSOutputTypeMacro(long, 5000000);
    puts("We waiting -  number = 1000.99");
    
    KSOutputTypeMacro(double, 1000.99);
    
    puts("We waiting -  'bool' true = 1");
    KSOutputTypeMacro(bool, true);
}


