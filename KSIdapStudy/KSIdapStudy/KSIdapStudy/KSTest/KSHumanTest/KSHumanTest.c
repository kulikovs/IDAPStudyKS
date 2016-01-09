//
//  KSHumanTest.c
//  KSIdapStudy
//
//  Created by KulikovS on 09.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSHumanTest.h"
#include <stdbool.h>


char *nameHumanSerg = "Sergey";

void KSHumanTest() {
    KSHuman *humanSerg = KSHumanCreate();
    KSHumanSetName(humanSerg, *nameHumanSerg);
    KSHumanSetAge(humanSerg, 20);
    KSHumanSetMaried(humanSerg, true);
    printf("%d", KSHumanGetMarried(humanSerg));
 //   printf("%s\n", KSHumanGetName(humanSerg));
    printf("%d\n", KSHumanGetAge(humanSerg));

}