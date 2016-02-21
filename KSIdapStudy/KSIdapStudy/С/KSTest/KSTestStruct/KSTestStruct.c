//
//  KSTestCarStruct.c
//  KSMacros
//
//  Created by KulikovS on 28.12.15.
//  Copyright © 2015 KulikovS. All rights reserved.
//

#include "KSTestStruct.h"
#include <stddef.h>

void KSTestCarStruct(KSCarData Car) {
    puts("\t\t\t Size Struct");
    printf("model %lu\n", offsetof(KSCarData, model));
    printf("Engine Displacement %lu\n", offsetof(KSCarData, engineDisplacement));
    printf("speed %lu\n", offsetof(KSCarData, speed));
    printf("Horse Power %lu\n", offsetof(KSCarData, horsePower));
    printf("rpm %lu\n", offsetof(KSCarData, rpm));
    
    printf("Size KSDataCar = %lu byte\n", sizeof(KSCarData));
    
}