//
//  main.c
//  KSIdapStudy
//
//  Created by KulikovS on 29.12.15.
//  Copyright © 2015 KulikovS. All rights reserved.
//

#include <stdio.h>
#include "KSTestMacroOutputType.h"
#include "KSTestStruct.h"
#include "KSValueBitOutputTest.h"
#include "KSHumanTest.h"

int main(int argc, const char * argv[]) {
//    
//    KSTestMacroOutputType();
//    KSTestCarStruct();
//
//    KSPrintByteValueOutputTest();
     KSHumanTest();

    int *countHuman;
    
    int human = 10;
    printf("Value human %d\n", human);
    countHuman = &human;
    *countHuman = 5;
    
    printf("Value numan after pointer %d\n", human);
    printf("Value pointer %p\n", countHuman);
    
    return 0;
}
