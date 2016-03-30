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
       
       KSCar *car = [KSCar object];
       KSEnterprise *enterprise = [KSEnterprise object];
       
       for (NSUInteger index = 0; index < 10; index ++) {
           [enterprise washCar:car];
           car.carState = kKSCarStateDirty;
           car.money = 100;
       }
       
       NSLog(@"Car");
       
       
       
       
    //[KSCreatureTest creatureTest];
//       NSMutableString *mutableString = [NSMutableString string];
//       KSAlphabet *alphabet = [[[KSAlphabet alloc] initWithCharacterRange:'G' lastValue:'z'] autorelease];
//       for (NSString *string in alphabet) {
//        [mutableString appendFormat:@"%@", string];
//       }
//       NSLog(@"%@", mutableString);
       
       NSRunLoop *runloop = [NSRunLoop mainRunLoop];
       [runloop run];
       
   }
    
    return 0;
}