//
//  KSHuman.c
//  KSIdapStudy
//
//  Created by KulikovS on 08.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "KSHuman.h"
#include "KSMacro.h"


static const uint8_t kKSChildrenCount = 20;

struct KSHuman {
    KSObject _super;
    KSHuman *_children[kKSChildrenCount];
    KSHuman *_partner;
    KSHuman *_mother;
    KSHuman *_father;
    uint8_t _age;
    char *_name;
    KSGenderType _gender;
};

#pragma mark -
#pragma mark Private Declarations

static
KSHuman *KSHumanCreate();

static
void __KSHumanDeallocate(KSHuman *human);

static
void KSHumanSetPartner(KSHuman *human, KSHuman *partner);

static
void KSHumanSetAge(KSHuman *human, uint8_t age);

static
void KSHumanSetGenderType(KSHuman *human, KSGenderType gender);

static
void KSHumanSetMother(KSHuman *human, KSHuman *mother);

static
void KSHumanSetFather(KSHuman *human, KSHuman *father);

static
void KSHumanAddChild(KSHuman *human, KSHuman *child);

static
void KSHumanSetChildAtIndex(KSHuman *human, KSHuman *child, int index);

static
KSHuman *KSHumanGetChildAtIndex(KSHuman *human, int index);

static
void KSHumanRemoveChildAtIndex(KSHuman *human, KSHuman *child, int index);

#pragma mark -
#pragma mark Initializations and Deallocations

void __KSHumanDeallocate(KSHuman *human) {
    
    KSHumanDivorce(human);
    KSHumanSetMother(human, NULL);
    KSHumanSetFather(human, NULL);
    KSHumanRemoveAllChildren(human);
    KSHumanSetName(human, NULL);

    __KSObjectDeallocate(human);
    
}

KSHuman *KSHumanCreate() {
    KSHuman *human = KSObjectCreateMacro(KSHuman);
    
    return human;
}

KSHuman *KSHumanCreateWithNameAgeGender(char *name, uint8_t age, KSGenderType gender) {
    KSHuman *human = KSHumanCreate();

    assert(age < UINT8_MAX / 2);
    
    KSHumanSetAge(human, age);
    KSHumanSetName(human, name);
    KSHumanSetGenderType(human, gender);
    
    return human;
}

KSHuman *KSHumanCreateWithParentsNameAgeGender(KSHuman *father,
                                              KSHuman *mother,
                                              char *name,
                                              uint8_t age,
                                              KSGenderType gender) {
    
    assert(father->_partner == mother);
    
    KSHuman *human = KSHumanCreateWithNameAgeGender(name, age, gender);
    
    KSHumanSetMother(human, mother);
    KSHumanSetFather(human, father);
    KSHumanAddChild(father, human);
    KSHumanAddChild(mother, human);
    
    return human;
}

#pragma mark -
#pragma mark Accessors

void KSHumanSetAge(KSHuman *human, uint8_t age) {
    KSReturnMacro(human);
    
    KSAssignMacro(human->_age, age);
}

uint8_t KSHumanGetAge(KSHuman *human) {
    KSReturnNullMacro(human);
    
    return human->_age;
}

void KSHumanSetName(KSHuman *human, char *name) {
    KSReturnMacro(human);
    
    free(human->_name);
    
    if (NULL != name) {
        human->_name = strdup(name);
    } else {
        human->_name = NULL;
    }
}

char *KSHumanGetName(KSHuman *human) {
    KSReturnNullMacro(human);
    
    return human->_name;
}

void KSHumanSetPartner(KSHuman *human, KSHuman *partner) {
    KSReturnMacro(human);
   
    assert(KSHumanGetGenderType(human) != KSHumanGetGenderType(partner));
    
    if (KSHumanGetGenderType(human) == kKSMale) {
        KSRetainSetter(human->_partner, partner)
    } else {
        KSAssignMacro(human->_partner, partner);
    }
}

KSHuman *KSHumanGetPartner(KSHuman *human) {
    KSReturnNullMacro(human);

    return human->_partner;
}

void KSHumanSetGenderType(KSHuman *human, KSGenderType gender) {
    KSReturnMacro(human);
    
    KSAssignMacro(human->_gender, gender)
}

KSGenderType KSHumanGetGenderType(KSHuman *human) {
    KSReturnNullMacro(human);
    
    return human->_gender;
}

void KSHumanSetMother(KSHuman *human, KSHuman *mother) {
    KSReturnMacro(human);
    
    KSAssignMacro(human->_mother, mother)
}

KSHuman *KSHumanGetMother(KSHuman *human) {
    KSReturnNullMacro(human);
    
    return human->_mother;
}

void KSHumanSetFather(KSHuman *human, KSHuman *father) {
    KSReturnMacro(human);
    
    KSAssignMacro(human->_father, father);
}

KSHuman *KSHumanGetFather(KSHuman *human) {
    KSReturnNullMacro(human);
    
    return human->_father;
}

void KSHumanSetChildAtIndex(KSHuman *human, KSHuman *child, int index) {
    KSReturnMacro(human);
    
    KSRetainSetter(human->_children[index], child);
    
}

KSHuman *KSHumanGetChildAtIndex(KSHuman *human, int index) {
    KSReturnNullMacro(human);
    
    return human->_children[index];
}

#pragma mark -
#pragma mark Public Implementations

void KSHumanRemoveChild(KSHuman *human, KSHuman *child) {
    KSReturnMacro(human);
    
    for (int index = 0; index < kKSChildrenCount; index++) {
        KSHumanRemoveChildAtIndex(human, child, index);
    }
}

void KSHumanRemoveAllChildren(KSHuman *human) {
    KSReturnMacro(human);
    
    for (int index = 0; index < kKSChildrenCount; index++) {
        KSHumanRemoveChildAtIndex(human, KSHumanGetChildAtIndex(human, index), index);
    }
    
}

void KSHumanMarry(KSHuman *human, KSHuman *partner) {
    KSReturnMacro(human);
    KSReturnMacro(partner);

    if (human->_partner != NULL || partner->_partner != NULL) {
        return;
    }
    
    KSHumanSetPartner(human, partner);
    KSHumanSetPartner(partner, human);
}

bool KSHumanIsMarried(KSHuman *human) {
    bool married = false;
    
    if (KSHumanGetPartner(human) != NULL) {
        married = true;
    }
    
    return married;
}

void KSHumanDivorce(KSHuman *human) {
    KSReturnMacro(human);
    
    KSHumanSetPartner(KSHumanGetPartner(human), NULL);
    KSHumanSetPartner(human, NULL);
}

#pragma mark -
#pragma mark Private Implementations

void KSHumanAddChild(KSHuman *human, KSHuman *child) {
    KSReturnMacro(human);
    
    int index = 0;
    
    while (human->_children[index] != NULL) {
        index++;
    }
    
    KSHumanSetChildAtIndex(human, child, index);
}

void KSHumanRemoveChildAtIndex(KSHuman *human, KSHuman *child, int index) {
    
    if (KSHumanGetChildAtIndex(human, index) == child) {
        KSHumanSetChildAtIndex(human, NULL, index);
        
        KSHumanGetGenderType(human) == kKSMale
        ? KSHumanSetFather(child, NULL)
        : KSHumanSetMother(child, NULL);

    }
}