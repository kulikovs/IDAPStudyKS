//
//  KSHumanTest.c
//  KSIdapStudy
//
//  Created by KulikovS on 09.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSHumanTest.h"

void KSHumanTest(void) {
    KSHuman *Serg = KSHumanCreateWithNameAgeGender("Sergey", 30, kKSMale);
    KSHuman *Masha = KSHumanCreateWithNameAgeGender("Masha", 31, kKSFemale);
    
    KSHumanMarry(Masha, Serg);
    
    KSHuman *Pasha = KSHumanCreateWithParentsNameAgeGender(Serg, Masha, "Pasha", 0, kKSMale);
    KSHuman *Pasha2 = KSHumanCreateWithParentsNameAgeGender(Serg, Masha, "Pasha2", 1, kKSMale);
    KSHuman *Pasha3 = KSHumanCreateWithParentsNameAgeGender(Serg, Masha, "Pasha", 0, kKSMale);
    
    KSHumanDivorce(Serg);
    
    KSHumanRemoveChild(Serg, Pasha3);
    KSHumanRemoveChild(Masha, Pasha3);
    KSHumanRemoveChild(Serg, Pasha2);
    KSHumanRemoveChild(Masha, Pasha2);
    KSHumanRemoveChild(Serg, Pasha);
    KSHumanRemoveChild(Masha, Pasha);
    
    
    KSHumanRelease(Serg);
    KSHumanRelease(Masha);
    KSHumanRelease(Pasha);
    KSHumanRelease(Pasha2);
    KSHumanRelease(Pasha3);
    
    
    printf("%d\n", KSHumanGetAge(Serg));
    printf("%d\n", KSHumanGetAge(Masha));
    printf("%d\n", KSHumanGetAge(Pasha));
    printf("%d\n", KSHumanGetAge(Pasha2));
    puts("test");
    printf("%d\n", KSHumanGetAge(Pasha3));
}

