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

int main(int argc, const char * argv[]) {
   @autoreleasepool {
       
    //[KSCreatureTest creatureTest];
       NSMutableString *mutableString = [NSMutableString string];
       KSAlphabet *alphabet = [[[KSAlphabet alloc] initWithCharacterRange:'G' lastValue:'z'] autorelease];
       for (NSString *string in alphabet) {
        [mutableString appendFormat:@"%@", string];
       }
       NSLog(@"%@", mutableString);
       
    return 0;
   }
}