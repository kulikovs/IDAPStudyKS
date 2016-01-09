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

typedef struct KSHuman KSHuman;

extern
KSHuman *KSHumanCreate(void);

extern
void KSHumanDeallocate(KSHuman *human);

extern
void KSHumanSetAge(KSHuman *human, uint8_t age);

extern
uint8_t KSHumanGetAge(KSHuman *human);

extern
void KSHumanSetName(KSHuman *human, char name);

extern
char KSHumanGetName(KSHuman *human);

#endif /* KSHuman_h */
