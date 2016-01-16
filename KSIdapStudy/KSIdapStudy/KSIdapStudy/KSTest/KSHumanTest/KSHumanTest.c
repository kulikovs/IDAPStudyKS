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
    KSHuman *Masha = KSHumanCreateWithNamedAgeGender("Masha", 31, kKSSexFemale);
    KSHumanMarry(Masha, Serg);
    KSHuman *Pasha = KSChildCreateWithParentNamedAgeGender(Serg, Masha, "Pasha", 0, kKSSexMale);
    KSHuman *Pasha2 = KSChildCreateWithParentNamedAgeGender(Serg, Masha, "Pasha2", 1, kKSSexMale);
    KSHuman *Pasha3 = KSChildCreateWithParentNamedAgeGender(Serg, Masha, "Pasha", 0, kKSSexMale);
    puts(KSHumanGetName(Serg));
    KSHumanRemoveChildrenFromParent(Serg);
    
    KSHumanDivorce(Serg);
    

    printf("%d\n", KSHumanGetAge(Serg));
    

}