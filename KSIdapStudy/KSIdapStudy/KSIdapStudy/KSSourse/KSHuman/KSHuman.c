//
//  KSHuman.c
//  KSIdapStudy
//
//  Created by KulikovS on 08.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//
#include <stdbool.h>
#include <stdlib.h>
#include "KSHuman.h"
#include "KSMacro.h"

#include <assert.h>

#pragma mark -
#pragma mark Private Declarations

static
void KSHumanSetPartner(KSHuman *human, KSHuman *partner);

struct KSHuman {
    int16_t _retailCount;
    KSHuman *_children[20];
    KSHuman *_partner;
    KSHuman *_mother;
    KSHuman *_father;
    KSSexType _sexType;
    uint8_t _age;
    char *_name;
};

#pragma mark -
#pragma mark Initializations and Deallocations

KSHuman * KSHumanCreateWithNamedAgeGender(char *name, uint8_t age, KSSexType sex) {
    KSHuman *human = calloc(1, sizeof(KSHuman));

    assert(human != NULL);
    assert(age < 120);

    human->_retailCount = 1;

    return human;
}

KSHuman * KSHumanCreateChildWithNamedAgeGender(KSHuman *father, KSHuman *mother,
                                        char *name, uint8_t age, KSSexType sex) {
    KSHuman *human = calloc(1, sizeof(KSHuman));
    
    assert(human != NULL);
    assert(age < 120);
    human->_name = name;
    human->_age = age;
    human->_sexType = sex;
    human->_retailCount = 1;
    human->_father = father;
    human->_mother = mother;
    father->_children[0] = human;
    mother->_children[0] = human;
    
    return human;
}


void KSHumanDeallocate(KSHuman *human) {
    free(human);
}

#pragma mark -
#pragma mark Accessors


void KSHumanSetAge(KSHuman *human, uint8_t age) {
    human->_age = age;
}


uint8_t KSHumanGetAge(KSHuman *human) {
    return human->_age;
}

void KSHumanSetName(KSHuman *human, char *name) {
    human->_name = name;
}

char *KSHumanGetName(KSHuman *human) {
    return human->_name;
}

KSHuman *KSHumanGetPartner(KSHuman *human) {
    return human->_partner;
}

void KSHumanSetSexType(KSHuman *human, KSSexType sexType) {
    human->_sexType = sexType;
}

KSSexType KSHumanGetSexType(KSHuman *human) {
    return human->_sexType;
}

#pragma mark -
#pragma mark Private Implementations

void KSHumanSetPartner(KSHuman *human, KSHuman *partner) {
    
    assert(human != NULL);
    assert(human->_age >18);
    
    human->_partner = partner;
}

#pragma mark -
#pragma mark Public Implementations

void KSHumanMarry(KSHuman *human, KSHuman *partner) {
    KSHumanSetPartner(human, partner);
    KSHumanSetPartner(partner, human);
}

void KSHumanDivorce(KSHuman *human) {
    KSHumanSetPartner(KSHumanGetPartner(human), NULL);
    KSHumanSetPartner(human, NULL);
}
