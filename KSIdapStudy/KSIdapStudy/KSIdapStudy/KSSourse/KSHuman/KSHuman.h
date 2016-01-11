//
//  KSHuman.h
//  KSIdapStudy
//
//  Created by KulikovS on 08.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#ifndef KSHuman_h
#define KSHuman_h

#include <stdio.h>
#include <stdbool.h>


typedef enum {
    kKSexTypeUndefine,
    kKSSexMale,
    kKSSexTypeFemale,
} KSSexType;

typedef struct KSHuman KSHuman;

extern
KSHuman *KSHumanCreateWithNamedAgeGender(char *name, uint8_t age, KSSexType sex);

KSHuman * KSHumanCreateChildWithNamedAgeGender(KSHuman *father, KSHuman *mother,
                                        char *name, uint8_t age, KSSexType sex);

extern
void KSHumanDeallocate(KSHuman *human);

extern
uint8_t KSHumanGetAge(KSHuman *human);

extern
char *KSHumanGetName(KSHuman *human);

extern
KSHuman *KSHumanGetPartner(KSHuman *human);

extern
void KSHumanMarried(KSHuman *human, KSHuman *partner);

extern
void KSHumanDivorced(KSHuman *human);

#endif /* KSHuman_h */
