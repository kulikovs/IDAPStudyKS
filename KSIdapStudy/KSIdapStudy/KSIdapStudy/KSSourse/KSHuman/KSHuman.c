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
#include <assert.h>

struct KSHuman {
    KSHuman *_children[20];
    uint8_t _age;
        struct sexAttribute {
            bool Mail;
            bool Female;
        };
    char *_name;
    bool _sexAttributeMale;
    bool _married;
};

#pragma mark -
#pragma mark Initializations and Deallocations

KSHuman *KSHumanCreate(void) {
    KSHuman *human = calloc(1, sizeof(KSHuman));
    
    assert(human != NULL);
    
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

void KSHumanSetMaried(KSHuman *human, bool maried) {
    human->_married = maried;
}

bool KSHumanGetMarried(KSHuman *human) {
    (human->_married == true) ? puts("Married") : puts("Not married");
    return human->_married;
}

//bool KSHumanSetSexAttribute(KSHuman *human, sexAttribute) {
//human->_sexAttributeMale
//}