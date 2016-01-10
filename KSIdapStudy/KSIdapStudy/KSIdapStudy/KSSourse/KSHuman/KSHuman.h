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

typedef struct KSHuman KSHuman;

extern
KSHuman *KSHumanCreate(char *name, uint8_t age, bool male);

extern
KSHuman *KSChildrenCreate((char *name, uint8_t age, bool male));

extern
void KSHumanDeallocate(KSHuman *human);

extern
uint8_t KSHumanGetAge(KSHuman *human);

extern
char *KSHumanGetName(KSHuman *human);

extern
void KSHumanSetMaried(KSHuman *human, bool maried);

extern
bool KSHumanGetMarried(KSHuman *human);

extern
bool KSHumanGetSexAttributeMale(KSHuman *human);

#endif /* KSHuman_h */
