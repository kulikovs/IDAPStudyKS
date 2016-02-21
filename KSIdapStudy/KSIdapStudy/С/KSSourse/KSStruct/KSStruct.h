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
    long long runKm1; //8
    double lenght1; //8
    char *model; // 8
    float engineDisplacement; //4
    int price1; // 4
    short horsePower; //2
    short speed; //2
    short rpm; //2
    union {
        struct {
            bool pushButtonStart : 1;
            bool rearviewCamera : 1;
            bool cruiseControl : 1;
            bool usbAudioInterface : 1;
            bool wheelType : 1;
            bool typeEngine : 1;
        };
        char bitField;
    };
} KSCarData;




#endif /* KSStruct_h */
