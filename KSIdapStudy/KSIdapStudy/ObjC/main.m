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
////
       KSAlphabet *alphabet = [[[KSAlphabet alloc] initWithCharacterRange:'f' lastValue:'z'] autorelease];
      NSLog(@"%@", alphabet.alphabetString);
       NSLog(@"%d", alphabet.count);
       
     //  KSAlphabet *alphabetRange = [[[KSAlphabet alloc] initWithRange:NSMakeRange(40, 5)] autorelease];
  //    KSAlphabet *alphabetRange1 = [KSAlphabet object];

       
       KSAlphabet *alphabetString = [[[KSAlphabet alloc] initWithString:(@"ASDFGKJKGKG")] autorelease];
       NSLog(@"%@", alphabetString);
       NSLog(@"%d", alphabetString.count);
       
       
       KSAlphabet *lowerAlphabet = [KSAlphabet lowerCaseLettersAlphabet];
//       
       
//       NSLog(@"%@", [NSString randomString]);
      NSLog(@"%@", [NSString randomStringWithLength:30 alphabet:alphabet]);
     //  NSLog(@"%@", [NSString randomStringWithLength:10 alphabet:alphabetString]);
//      NSLog(@"%@", [NSString upperCaseAlphabet]);
//      NSLog(@"%@", [NSString randomStringWithLength:20 alphabet:[NSString numericLettersAlphabet]]);

    return 0;
   }
}