//
//  KSTestCarStruct.c
//  KSMacros
//
//  Created by KulikovS on 28.12.15.
//  Copyright © 2015 KulikovS. All rights reserved.
//

#include "KSTestStruct.h"
#include <stddef.h>

void KSTestCarStruct() {
    printf("Size struct KSCarData - %lu, byte\n", sizeof(KSCarData));
    
//    printf("Size struct KSCarData - %lu, byte\n", sizeof(KSCarData->brand));
//    printf("Size struct KSCarData - %lu, byte\n", sizeof(KSCarData.brand));
    
    printf("brand %lu\n", offsetof(KSCarData, brand));
    printf("model %lu\n", offsetof(KSCarData, model));
    printf("Engine Displacement %lu\n", offsetof(KSCarData, engineDisplacement));
    printf("Horse Power %lu\n", offsetof(KSCarData, horsePower));
    printf("speed %lu\n", offsetof(KSCarData, speed));
}