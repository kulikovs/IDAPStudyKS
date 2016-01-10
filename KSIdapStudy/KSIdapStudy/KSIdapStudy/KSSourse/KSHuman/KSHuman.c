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
//        struct sexAttribute {
//            bool Mail;
//            bool Female;
//        };
    char *_name;
    bool _sexAttributeMale;
    bool _married;
};

#pragma mark -
#pragma mark Initializations and Deallocations

KSHuman *KSHumanCreate(char *name, uint8_t age, bool male) {
    KSHuman *human = calloc(1, sizeof(KSHuman));
    
    assert(human != NULL);
    assert(age < 120);
    
    human->_name = name;
    human->_age = age;
    human->_sexAttributeMale = male;

    return human;
}

//KSHuman *KSChildrenCreate(KSHuman *human, char *name, uint8_t age, bool male) {
// 
//    human->_children[0]->
//
//}

void KSHumanDeallocate(KSHuman *human) {
    free(human);
}

#pragma mark -
#pragma mark Accessors

uint8_t KSHumanGetAge(KSHuman *human) {
    return human->_age;
}

char *KSHumanGetName(KSHuman *human) {
    return human->_name;
}

void KSHumanSetMaried(KSHuman *human, bool maried) {
    assert(human->_age >18);
    human->_married = maried;
}

bool KSHumanGetMarried(KSHuman *human) {
    return human->_married ? puts("Married") : puts("Not married");
}

bool KSHumanGetSexAttributeMale(KSHuman *human) {
    return human->_sexAttributeMale ? puts("The man") : puts("The woman");
}