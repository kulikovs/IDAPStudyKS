//
//  main.m
//  ObjC
//
//  Created by KulikovS on 16.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KSCreatureTest.h"
#import "NSString+KSExtension.h"
#import "KSAlphabet.h"
#import "KSEnterprise.h"
#import "KSCar.h"
#import "KSCarsWasher.h"

int main(int argc, const char * argv[]) {
   @autoreleasepool {
       
       NSArray *arrayCars = [KSCar objectsWithCount:20];
       KSEnterprise *enterprise = [KSEnterprise object];
       
       for (NSUInteger index = 0; index < arrayCars.count; index ++) {
           [enterprise washCar:arrayCars[index]];
       }
       
       NSRunLoop *runloop = [NSRunLoop mainRunLoop];
       [runloop run];
       
   }
    
    return 0;
}