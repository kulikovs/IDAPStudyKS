//
//  main.m
//  ObjC
//
//  Created by KulikovS on 16.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KSHumanClass.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {

        KSHuman *human = [[[KSHuman alloc] initWithAge] autorelease];
        KSHuman *children = [[[KSHuman alloc] initWithAge] autorelease];
        KSHuman *children1 = [[[KSHuman alloc] initWithAge] autorelease];
        KSHuman *children2 = [[[KSHuman alloc] initWithAge] autorelease];
        [human setAge: 80];
        [human setGender:kKSMale];
        [human setChildren:[NSArray arrayWithObjects:children, children1, children2, nil]];
        [human get];
        NSLog(@"%@", human);
        NSLog(@"%d", human.age);
        
    }
    
    return 0;
}
