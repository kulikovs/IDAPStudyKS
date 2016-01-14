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
    KSHuman *Serg = KSHumanCreateWithNamedAgeGender("Sergey", 30, kKSSexMale);
    KSHuman *Masha = KSHumanCreateWithNamedAgeGender("Masha", 31, kKSSexTypeFemale);
    KSHumanMarry(Serg, Masha);
    KSHuman *Pasha = KSHumanCreateChildWithNamedAgeGender(Serg, Masha, "Pasha", 0, kKSSexMale);
    puts(KSHumanGetName(Serg));

    KSHumanDivorce(Serg);
    

    printf("%d\n", KSHumanGetAge(Serg));
    
    KSHumanDeallocate(Serg);
    KSHumanDeallocate(Masha);
    KSHumanDeallocate(Pasha);
}