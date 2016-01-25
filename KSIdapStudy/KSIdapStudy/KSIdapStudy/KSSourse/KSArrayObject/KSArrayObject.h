//
//  KSArrayObject.h
//  KSIdapStudy
//
//  Created by KulikovS on 25.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#ifndef KSArrayObject_h
#define KSArrayObject_h

#include "KSObject.h"

static const uint8_t arrayCount = 20;

struct KSArrayObject {
    KSObject _super;
    void* _arrayData[arrayCount];
};




#endif /* KSArrayObject_h */
