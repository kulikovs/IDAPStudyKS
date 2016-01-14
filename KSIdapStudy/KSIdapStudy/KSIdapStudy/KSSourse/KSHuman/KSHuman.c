//
//  KSHuman.c
//  KSIdapStudy
//
//  Created by KulikovS on 08.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "KSHuman.h"
#include "KSMacro.h"

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

KSHuman *KSHumanCreate() {
    KSHuman *human = calloc(1, sizeof(KSHuman));
    
    assert(human != NULL);
    
    return human;
}

KSHuman *KSHumanCreateWithNamedAgeGender(char *name, uint8_t age, KSSexType sex) {
    KSHuman *human = KSHumanCreate();

    assert(age < 120);
    
    KSHumanSetAge(human, age);
    KSHumanSetName(human, name);
    KSHumanSetSexType(human, sex);
    
    human->_retailCount = 1;

    return human;
}

KSHuman *KSHumanCreateChildWithNamedAgeGender(KSHuman *father,
                                              KSHuman *mother,
                                              char *name,
                                              uint8_t age,
                                              KSSexType sex) {
    KSHuman *human = KSHumanCreate();
    
    assert(human != NULL);
    assert(age < 120);
    
    KSHumanSetAge(human, age);
    KSHumanSetName(human, name);
    KSHumanSetSexType(human, sex);
    KSHumanSetMother(human, mother);
    KSHumanSetFather(human, father);
    KSHumanSetChild(human, father);
    KSHumanSetChild(human, mother);
    
    human->_retailCount = 1;
    
    return human;
}


void KSHumanDeallocate(KSHuman *human) {
    free(human);
}

#pragma mark -
#pragma mark Accessors


void KSHumanSetAge(KSHuman *human, uint8_t age) {
    KSReturnMacro(human);
    human->_age = age;
}

uint8_t KSHumanGetAge(KSHuman *human) {
    KSReturnNullMacro(human);
    return human->_age;
}

void KSHumanSetName(KSHuman *human, char *name) {
    KSReturnMacro(human);
    human->_name = name;
}

char *KSHumanGetName(KSHuman *human) {
    KSReturnNullMacro(human);
    return human->_name;
}

KSHuman *KSHumanGetPartner(KSHuman *human) {
    KSReturnNullMacro(human);
    return human->_partner;
}

void KSHumanSetSexType(KSHuman *human, KSSexType sexType) {
    KSReturnMacro(human);
    
    human->_sexType = sexType;
}

KSSexType KSHumanGetSexType(KSHuman *human) {
    KSReturnNullMacro(human);
    return human->_sexType;
}

void KSHumanSetMother(KSHuman *human, KSHuman *mother) {
    KSReturnMacro(human);
    KSReturnMacro(mother);
    
    human->_mother = mother;
}

KSHuman *KSHumanGetMother(KSHuman *human) {
    KSReturnNullMacro(human);
    return human->_mother;
}

void KSHumanSetFather(KSHuman *human, KSHuman *father) {
    KSReturnMacro(human);
    KSReturnMacro(father);
    
    human->_father = father;
}

KSHuman *KSHumanGetFather(KSHuman *human) {
    KSReturnNullMacro(human);
    return human->_father;
}

void KSHumanRatain(KSHuman *human) {
    KSReturnMacro(human);
    human->_retailCount++;
}

void KSHumanRelease(KSHuman *human) {
    KSReturnMacro(human);
    human->_retailCount--;
    
    if (0 == human->_retailCount) {
        KSHumanDeallocate(human);
    }
}

void KSHumanSetChild(KSHuman *human, KSHuman *parent) {
    KSReturnMacro(human);
    KSReturnMacro(parent);
    
    int index = 0;
    while (parent->_children[index] != NULL) {
        index++;
    }
    parent->_children[index] = human;
}


#pragma mark -
#pragma mark Private Implementations

void KSHumanSetPartner(KSHuman *human, KSHuman *partner) {
    KSReturnMacro(human);
    KSReturnMacro(partner);
    assert(human->_age >18);
    
    human->_partner = partner;
}

#pragma mark -
#pragma mark Public Implementations

void KSHumanMarry(KSHuman *human, KSHuman *partner) {
    KSReturnMacro(human);
    KSReturnMacro(partner);
    
    KSHumanSetPartner(human, partner);
    KSHumanSetPartner(partner, human);
}

void KSHumanDivorce(KSHuman *human) {
    KSReturnMacro(human);
    
    KSHumanSetPartner(KSHumanGetPartner(human), NULL);
    KSHumanSetPartner(human, NULL);
}
