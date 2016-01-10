//
//  KSHumanTest.c
//  KSIdapStudy
//
//  Created by KulikovS on 09.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSHumanTest.h"
#include <stdbool.h>

void KSHumanTest() {
    KSHuman *humanSerg = KSHumanCreate("Sergey", 35, true);

    KSHumanSetMaried(humanSerg, true);
    KSHumanGetMarried(humanSerg);
    KSHuman *childMasha = KSChildrenCreate(humanSerg, "Masha", 8, false);
    
    puts(KSHumanGetName(humanSerg));
    printf("%d\n", KSHumanGetAge(humanSerg));
    
    KSHumanDeallocate(humanSerg);

}