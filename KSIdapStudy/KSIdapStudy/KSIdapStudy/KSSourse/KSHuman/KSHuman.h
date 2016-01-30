//
//  KSHuman.h
//  KSIdapStudy
//
//  Created by KulikovS on 08.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#ifndef KSHuman_h
#define KSHuman_h

#include <stdlib.h>
#include <stdbool.h>

#include "KSStringObject.h"
#include "KSArrayObject.h"

typedef enum {
    kKSGenderUndefine,
    kKSMale,
    kKSFemale,
} KSGenderType;

typedef struct KSHuman KSHuman;

extern  
KSHuman *KSHumanCreateWithNameAgeGender(KSString *stringName,
                                        uint8_t age,
                                        KSGenderType gender);

extern
KSHuman *KSHumanCreateWithParentsNameAgeGender(KSHuman *father,
                                               KSHuman *mother,
                                               KSString *stringName,
                                               uint8_t age,
                                               KSGenderType gender);

extern
void KSHumanRemoveChild(KSHuman *human, KSHuman *child);

extern
void KSHumanRemoveAllChildren(KSHuman *human);

extern
KSArray *KSHumanGetChildren(KSHuman *human);

extern
void KSHumanSetName(KSHuman *human, KSString *stringName);

extern
KSString *KSHumanGetName(KSHuman *human);

extern
uint8_t KSHumanGetAge(KSHuman *human);

extern
KSGenderType KSHumanGetGenderType(KSHuman *human);

extern
KSHuman *KSHumanGetPartner(KSHuman *human);

extern
KSHuman *KSHumanGetMother(KSHuman *human);

extern
KSHuman *KSHumanGetFather(KSHuman *human);

extern
uint8_t KSHumanGetCountChildren(KSHuman *human);

extern
void KSHumanMarry(KSHuman *human, KSHuman *partner);

extern
bool KSHumanIsMarried(KSHuman *human);

extern
void KSHumanDivorce(KSHuman *human);

#endif /* KSHuman_h */
