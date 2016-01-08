//
//  KSHuman.c
//  KSIdapStudy
//
//  Created by KulikovS on 08.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//
#include <stdbool.h>

#include "KSHuman.h"

struct KSHuman {
    KSHuman *_children[20];
    uint8_t _age;
    char _name;
    char _sex;
    bool _married;
};

#pragma mark -
#pragma mark Initializations and Deallocations

KSHuman KSHumanCreate(void);

#pragma mark -
#pragma mark Accessors

