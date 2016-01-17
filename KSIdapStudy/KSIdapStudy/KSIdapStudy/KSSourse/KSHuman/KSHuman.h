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
    kKSSexFemale,
} KSSexType;

typedef struct KSHuman KSHuman;

extern
KSHuman *KSHumanCreateWithNamedAgeGender(char *name, uint8_t age, KSSexType sex);

extern
KSHuman * KSChildCreateWithParentNamedAgeGender(KSHuman *father,
                                               KSHuman *mother,
                                               char *name,
                                               uint8_t age,
                                               KSSexType sex);

extern
void KSHumanRetain(KSHuman *human);

extern
void KSHumanRelease(KSHuman *human);

extern
void KSHumanSetChild(KSHuman *human, KSHuman *parent);

extern
KSHuman *KSHumanGetChildren(KSHuman *human);

extern
void KSHumanSetName(KSHuman *human, char *name);

extern
char *KSHumanGetName(KSHuman *human);

extern
uint8_t KSHumanGetAge(KSHuman *human);

extern
KSSexType KSHumanGetSexType(KSHuman *human);

extern
KSHuman *KSHumanGetPartner(KSHuman *human);

extern
KSHuman *KSHumanGetMother(KSHuman *human);

extern
KSHuman *KSHumanGetFather(KSHuman *human);

extern
void KSHumanMarry(KSHuman *human, KSHuman *partner);

extern
void KSHumanDivorce(KSHuman *human);

extern
void KSHumanDieParent(KSHuman *human);

extern
void KSHumanRemoveChildrenFromTheirParents(KSHuman *human);

void KSDelFather(KSHuman *human);

extern
void KSHumanDelParentsFromChildren(KSHuman *human);

extern
void KSHumanRemoveParentsFromTheirChildren(KSHuman *human);

#endif /* KSHuman_h */
