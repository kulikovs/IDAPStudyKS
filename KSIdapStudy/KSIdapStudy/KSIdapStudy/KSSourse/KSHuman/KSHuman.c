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
KSHuman *KSHumanCreate();

static
void KSHumanDeallocate(KSHuman *human);

static
void KSHumanSetPartner(KSHuman *human, KSHuman *partner);

static
void KSHumanSetAge(KSHuman *human, uint8_t age);

static
void KSHumanSetSexType(KSHuman *human, KSSexType sexType);

static
void KSHumanSetMother(KSHuman *human, KSHuman *mother);

static
void KSHumanSetFather(KSHuman *human, KSHuman *father);


struct KSHuman {
    int16_t _retainCount;
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
    
    human->_retainCount = 1;

    return human;
}

KSHuman *KSChildCreateWithParentNamedAgeGender(KSHuman *father,
                                              KSHuman *mother,
                                              char *name,
                                              uint8_t age,
                                              KSSexType sex) {
    
    assert(KSHumanGetPartner(father) == mother);
    assert(age < 120);
    
    KSHuman *human = KSHumanCreate();
    
    assert(human != NULL);
    
    human->_retainCount = 1;
    KSHumanSetAge(human, age);
    KSHumanSetName(human, name);
    KSHumanSetSexType(human, sex);
    KSHumanSetMother(human, mother);
    KSHumanSetFather(human, father);
    KSHumanSetChild(human, father);
    KSHumanSetChild(human, mother);
    
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

void KSHumanSetPartner(KSHuman *human, KSHuman *partner) {
   
    assert(KSHumanGetSexType(human) != KSHumanGetSexType(partner));
    
    human->_partner = partner;
}

KSHuman *KSHumanGetPartner(KSHuman *human) {

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

    
    human->_mother = mother;
}

KSHuman *KSHumanGetMother(KSHuman *human) {
    KSReturnNullMacro(human);
    return human->_mother;
}

void KSHumanSetFather(KSHuman *human, KSHuman *father) {
    
    human->_father = father;
}

KSHuman *KSHumanGetFather(KSHuman *human) {
 //   KSReturnNullMacro(human);
    return human->_father;
}

void KSHumanSetChild(KSHuman *human, KSHuman *parent) {
    
    int index = 0;
    
    while (parent->_children[index] != NULL) {
        index++;
        assert(index < 20);
    }
    parent->_children[index] = human;
}

KSHuman *KSHumanGetChildren(KSHuman *human) {
    KSReturnNullMacro(human);
    return *human->_children;
}


#pragma mark -
#pragma mark Public Implementations

void KSHumanRetain(KSHuman *human) {
    KSReturnMacro(human);
    human->_retainCount++;
}

void KSHumanRelease(KSHuman *human) {
    KSReturnMacro(human);
    human->_retainCount--;
    
    if (0 == human->_retainCount) {
        KSHumanDeallocate(human);
    }
}

void KSHumanMarry(KSHuman *human, KSHuman *partner) {
    KSReturnMacro(human);
    KSReturnMacro(partner);

    if (human->_partner != NULL || partner->_partner != NULL) {
        return;
    }
    
    KSHumanGetSexType(human) == kKSSexMale
                                ? KSHumanRetain(human)
                                : KSHumanRetain(partner);
    
    KSHumanSetPartner(human, partner);
    KSHumanSetPartner(partner, human);
}

void KSHumanDivorce(KSHuman *human) {
    KSReturnMacro(human);

    KSHumanGetSexType(human) == kKSSexMale
                                ? KSHumanRelease(human)
                                : KSHumanRelease(KSHumanGetPartner(human));
    
    KSHumanSetPartner(KSHumanGetPartner(human), NULL);
    KSHumanSetPartner(human, NULL);
}


void KSHumanKillChildren(KSHuman *human) {
    KSReturnMacro(human);
    
    int index = 0;
    
    while (human->_children[index] != NULL) {
        human->_children[index] = NULL;
        index++;
        assert(index < 20);
    }
}

void KSHumanRemoveParentsFromTheirChildren(KSHuman *human) {
    KSReturnMacro(human);
    
    int index = 0;
    
    while (human->_children[index] != NULL) {
        KSHumanGetSexType(human) == kKSSexMale
            ? KSHumanSetFather(human->_children[index], NULL)
            : KSHumanSetMother(human->_children[index], NULL);
        human->_children[index] = NULL;
        index++;
        assert(index < 20);
    }
}


void KSHumanRemoveChildrenFromTheirParents(KSHuman *human) {

    KSHuman *father = KSHumanGetFather(human);
    KSHuman *mother = KSHumanGetMother(human);
    
    int index = 0;
    
    if (father != NULL) {
            while (father->_children[index] != human) {
                index++;
            }
        father->_children[index] = NULL;
    }
    
    if (mother != NULL) {
        while (mother->_children[index] != human) {
            index++;
        }
        mother->_children[index] = NULL;
    }
}

void KSRemoveHumanCommunication(KSHuman *human) {
    
    if (KSHumanGetPartner(human) != NULL) {
        KSHumanDivorce(human);
    }
    KSHumanRemoveChildrenFromTheirParents(human);
    KSHumanRemoveParentsFromTheirChildren(human);
}
