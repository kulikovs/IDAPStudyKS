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

extern
KSHuman * KSHumanCreateChildWithNamedAgeGender(KSHuman *father,
                                               KSHuman *mother,
                                               char *name,
                                               uint8_t age,
                                               KSSexType sex);

extern
void KSHumanDeallocate(KSHuman *human);

extern
void KSHumanSetAge(KSHuman *human, uint8_t age);

extern
uint8_t KSHumanGetAge(KSHuman *human);

extern
void KSHumanSetName(KSHuman *human, char *name);

extern
char *KSHumanGetName(KSHuman *human);

extern
void KSHumanSetSexType(KSHuman *human, KSSexType sexType);

extern
KSHuman *KSHumanGetPartner(KSHuman *human);

extern
void KSHumanSetSexType(KSHuman *human, KSSexType sexType);

extern
KSSexType KSHumanGetSexType(KSHuman *human);

extern
void KSHumanMarry(KSHuman *human, KSHuman *partner);

extern
void KSHumanDivorce(KSHuman *human);

#endif /* KSHuman_h */
