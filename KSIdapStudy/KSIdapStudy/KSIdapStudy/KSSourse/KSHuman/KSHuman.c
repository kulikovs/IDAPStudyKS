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

struct KSHuman {
    KSHuman *_children[20];
    uint8_t _age;
    bool sexMale;
    char *_name;
    bool _married;
};

#pragma mark -
#pragma mark Initializations and Deallocations

KSHuman *KSHumanCreate(void) {
    KSHuman *human = calloc(1, sizeof(KSHuman));
    
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

void KSHumanSetName(KSHuman *human, char name) {
    human->_name = &name;
}

char KSHumanGetName(KSHuman *human) {
    return (char)human->_name;
}
