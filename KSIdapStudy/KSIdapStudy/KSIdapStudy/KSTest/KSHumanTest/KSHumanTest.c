//
//  KSHumanTest.c
//  KSIdapStudy
//
//  Created by KulikovS on 09.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include <stdio.h>

#include "KSHumanTest.h"



void KSHumanTest(void) {
    
//    KSString *stringName = KSStringCreateWithSymbols("Sergey");
    
    KSString *nameSerg = KSStringCreateWithSymbols("Sergey");
    KSString *nameMasha = KSStringCreateWithSymbols("Masha");
    KSString *namePasha1 = KSStringCreateWithSymbols("Pasha1");
    KSString *namePasha2 = KSStringCreateWithSymbols("Pasha2");
    KSString *namePasha3 = KSStringCreateWithSymbols("Pasha3");
    
    KSStringPrintSymbols(namePasha1);

    KSHuman *Serg = KSHumanCreateWithNameAgeGender(nameSerg, 30, kKSMale);
    KSHuman *Masha = KSHumanCreateWithNameAgeGender(nameMasha, 31, kKSFemale);
    KSHumanMarry(Masha, Serg);
    
    KSString *nameSergVasya = KSStringCreateWithSymbols("Serg-Vasya");
    KSHumanSetName(Serg, nameSergVasya);

 
    KSHuman *Pasha = KSHumanCreateWithParentsNameAgeGender(Serg, Masha, namePasha1, 0, kKSMale);
    KSHuman *Pasha2 = KSHumanCreateWithParentsNameAgeGender(Serg, Masha, namePasha2, 1, kKSMale);
    KSHuman *Pasha3 = KSHumanCreateWithParentsNameAgeGender(Serg, Masha, namePasha3, 0, kKSMale);
    
    KSHumanDivorce(Serg);
    
//    KSHumanRemoveAllChildren(Serg);
    KSHumanRemoveChild(Serg, Pasha3);
    KSHumanRemoveChild(Masha, Pasha3);
    KSHumanRemoveChild(Serg, Pasha2);
    KSHumanRemoveChild(Masha, Pasha2);
    KSHumanRemoveChild(Serg, Pasha);
    KSHumanRemoveChild(Masha, Pasha);



    KSObjectRelease(Serg);
    KSObjectRelease(nameSerg);
    KSObjectRelease(nameSergVasya);
    
    KSObjectRelease(Masha);
    KSObjectRelease(nameMasha);
    
    KSObjectRelease(Pasha);
    KSObjectRelease(namePasha1);
    
    KSObjectRelease(Pasha2);
    KSObjectRelease(namePasha2);
    
    KSObjectRelease(Pasha3);
    KSObjectRelease(namePasha3);
    
    printf("%d\n", KSHumanGetAge(Serg));
    printf("%d\n", KSHumanGetAge(Masha));
    printf("%d\n", KSHumanGetAge(Pasha));
    printf("%d\n", KSHumanGetAge(Pasha2));
    puts("test");
    printf("%d\n", KSHumanGetAge(Pasha3));
}

