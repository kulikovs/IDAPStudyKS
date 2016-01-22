//
//  KSStringObjectTest.c
//  KSIdapStudy
//
//  Created by KulikovS on 22.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#include "KSStringObjectTest.h"

void KSStringObjectTest(void){

   KSString *string = KSStringCreateWithSymbols("This is test string");
    puts(KSStringGetSymbols(string));
    KSObjectRelease(string);
    
    puts(KSStringGetSymbols(string));
}