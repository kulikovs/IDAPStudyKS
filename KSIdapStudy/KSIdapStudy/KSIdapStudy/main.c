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
#include "KSHuman.h"

char *nameHumanSerg = "Sergey";


int main(int argc, const char * argv[]) {
//    
//    KSTestMacroOutputType();
//    KSTestCarStruct();
//
//  KSPrintByteValueOutputTest();
    KSHuman *humanSerg = KSHumanCreate();
    KSHumanSetName(humanSerg, *nameHumanSerg);
    KSHumanSetAge(humanSerg, 20);
    printf("%s\n", KSHumanGetName(humanSerg));
    printf("%d\n", KSHumanGetAge(humanSerg));
    return 0;
}
