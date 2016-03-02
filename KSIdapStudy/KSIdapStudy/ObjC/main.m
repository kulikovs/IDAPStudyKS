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
//
    //   KSAlphabet *alphabet = [[[KSAlphabet alloc] initWithRange:(5)] autorelease];
       KSAlphabet *alphabetString = [[[KSAlphabet alloc] initWithString:(@"ASDFGKJKGKG")] autorelease];
       
       KSAlphabet *lowerAlphabet = [KSAlphabet alphabetWithLowerCaseLetters];
       KSAlphabet *rangeAlphabet = [[KSAlphabet alloc] initWithRange:'g' secondValue:'z'];
       
       
//       NSLog(@"%@", [NSString randomString]);
   //   NSLog(@"%@", [NSString randomStringWithLength:30 alphabet:rangeAlphabet]);
     //  NSLog(@"%@", [NSString randomStringWithLength:10 alphabet:alphabetString]);
//      NSLog(@"%@", [NSString upperCaseAlphabet]);
//      NSLog(@"%@", [NSString randomStringWithLength:20 alphabet:[NSString numericLettersAlphabet]]);

    return 0;
   }
}