//
//  KSHumanTest.c
//  KSIdapStudy
//
//  Created by KulikovS on 09.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSHumanTest.h"
#include <stdbool.h>


//char *nameHumanSerg = "Sergey";

void KSHumanTest() {
    KSHuman *humanSerg = KSHumanCreate("Sergey", 20, true);
    KSHumanSetMaried(humanSerg, true);
    KSHumanGetMarried(humanSerg);
    puts(KSHumanGetName(humanSerg));
    printf("%d\n", KSHumanGetAge(humanSerg));
    KSHumanDeallocate(humanSerg);

}