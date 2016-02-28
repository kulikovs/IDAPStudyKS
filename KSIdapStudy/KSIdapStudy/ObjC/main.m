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

int main(int argc, const char * argv[]) {
   @autoreleasepool {
       
    //[KSCreatureTest creatureTest];
//       
      NSLog(@"%@", [NSString randomString]);
      NSLog(@"%@", [NSString randomStringWithLength:30]);
       NSLog(@"%@", [NSString upperCaseAlphabet]);
       NSLog(@"%@", [NSString randomStringWithLength:20 alphabet:[NSString numericLettersAlphabet]]);

    return 0;
   }
}