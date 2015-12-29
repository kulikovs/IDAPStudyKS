//
//  KSСar.h
//  KSMacros
//
//  Created by KulikovS on 28.12.15.
//  Copyright © 2015 KulikovS. All rights reserved.
//

#ifndef KSStruct_h
#define KSStruct_h

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char    * brand;
    char    * model;
    float     engineDisplacement;
    short     horsePower;
    short     speed;
    short     rpm;
    bool      pushButtonStart;
    bool      rearviewCamera;
    bool      cruiseControl;
    bool      usbAudioInterface;
    bool      wheelType;
    bool      typeEngine;
    long long runKm;
    double    lenght;
    int       price;
} KSCarData;



#endif /* KSStruct_h */
