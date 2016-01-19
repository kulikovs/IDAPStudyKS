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
#include <string.h>

#include "KSHuman.h"
#include "KSMacro.h"

static const uint8_t kKSChildrenCount = 20;

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
void KSHumanRetain(KSHuman *human);

static
void KSHumanSetChildAtIndex(KSHuman *human, KSHuman *child, int index);

static
KSHuman *KSHumanGetChildAtIndex(KSHuman *human, int index);

struct KSHuman {
    int16_t _retainCount;
    KSHuman *_children[kKSChildrenCount];
    KSHuman *_partner;
    KSHuman *_mother;
    KSHuman *_father;
    KSGenderType _gender;
    uint8_t _age;
    char *_name;
};

#pragma mark -
#pragma mark Initializations and Deallocations

void __KSHumanDeallocate(KSHuman *human) {
    
//    KSHumanSetPartner(human, NULL) or Divorce
    KSHumanSetMother(human, NULL);
    KSHumanSetFather(human, NULL);
    KSHumanRemoveAllChildren(human);
    KSHumanSetName(human, NULL);

    free(human);
    
    puts("Killed");
}

KSHuman *KSHumanCreate() {
    KSHuman *human = calloc(1, sizeof(KSHuman));
    
    assert(human != NULL);
    
    human->_retainCount = 1;
    
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
    
    assert(KSHumanGetPartner(father) == mother);
    
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
    
    human->_age = age;
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
    
    human->_partner = partner;
}

KSHuman *KSHumanGetPartner(KSHuman *human) {
    KSReturnNullMacro(human);

    return human->_partner;
}

void KSHumanSetGenderType(KSHuman *human, KSGenderType gender) {
    KSReturnMacro(human);
    
    human->_gender = gender;
}

KSGenderType KSHumanGetGenderType(KSHuman *human) {
    KSReturnNullMacro(human);
    
    return human->_gender;
}

void KSHumanSetMother(KSHuman *human, KSHuman *mother) {
    KSReturnMacro(human);
    
    human->_mother = mother;
}

KSHuman *KSHumanGetMother(KSHuman *human) {
    KSReturnNullMacro(human);
    
    return human->_mother;
}

void KSHumanSetFather(KSHuman *human, KSHuman *father) {
    KSReturnMacro(human);
    
    human->_father = father;
}

KSHuman *KSHumanGetFather(KSHuman *human) {
    KSReturnNullMacro(human);
    
    return human->_father;
}

KSHuman *KSHumanGetChildren(KSHuman *human) {
    KSReturnNullMacro(human);
    
    return *human->_children;
}

void KSHumanSetChildAtIndex(KSHuman *human, KSHuman *child, int index) {
    KSReturnMacro(human);
    
    if (human->_children[index] != child) {
        KSHumanRelease(human->_children[index]);
        human->_children[index] = child;
        KSHumanRetain(child);
    }
    
}

KSHuman *KSHumanGetChildAtIndex(KSHuman *human, int index) {
    KSReturnNullMacro(human);
    
    return human->_children[index];
}

#pragma mark -
#pragma mark Public Implementations

void KSHumanRelease(KSHuman *human) {
    KSReturnMacro(human);
    
    human->_retainCount--;
    
    if (0 == human->_retainCount) {
        __KSHumanDeallocate(human);
    }
}

void KSHumanRetain(KSHuman *human) {
    KSReturnMacro(human);
    
    human->_retainCount++;
}

void KSHumanAddChild(KSHuman *human, KSHuman *child) {
    KSReturnMacro(human);
    
    int index = 0;
    
    while (human->_children[index] != NULL) {
        index++;
    }
    
    human->_children[index] = child;
    KSHumanRetain(child);
}

void KSHumanRemoveChild(KSHuman *human, KSHuman *child) {
    KSReturnMacro(human);
    
    for (int index = 0; index < kKSChildrenCount; index++) {
        if (human->_children[index] == child) {
            human->_children[index] = NULL;
            
            KSHumanRelease(child);
            
            KSHumanGetGenderType(human) == kKSMale
            ? KSHumanSetFather(child, NULL)
            : KSHumanSetMother(child, NULL);
        }
    }
}

void KSHumanRemoveAllChildren(KSHuman *human) {
    KSReturnMacro(human);
    
    for (int index = 0; index < kKSChildrenCount; index++) {
        human->_children[index] = NULL;
    }
}

void KSHumanMarry(KSHuman *human, KSHuman *partner) {
    KSReturnMacro(human);
    KSReturnMacro(partner);

    if (human->_partner != NULL || partner->_partner != NULL) {
        return;
    }
    
    KSHumanGetGenderType(human) == kKSMale
                                ? KSHumanRetain(human)
                                : KSHumanRetain(partner);
    
    KSHumanSetPartner(human, partner);
    KSHumanSetPartner(partner, human);
}

bool KSHumanMarried(KSHuman *human) {
    bool married = false;
    
    if (KSHumanGetPartner(human) != NULL) {
        married = true;
    }
    
    return married;
}

void KSHumanDivorce(KSHuman *human) {
    KSReturnMacro(human);

    KSHumanGetGenderType(human) == kKSMale
                                ? KSHumanRelease(human)
                                : KSHumanRelease(KSHumanGetPartner(human));
    
    KSHumanSetPartner(KSHumanGetPartner(human), NULL);
    KSHumanSetPartner(human, NULL);
}