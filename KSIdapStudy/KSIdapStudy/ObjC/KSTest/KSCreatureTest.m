//
//  KSCreatureTest.m
//  KSIdapStudy
//
//  Created by KulikovS on 19.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSCreatureTest.h"
#import "KSCreatureFemale.h"
#import "KSCreatureMale.h"

@implementation KSCreatureTest

+ (void)creatureTest {
       
       KSCreatureMale *male = [KSCreatureMale object];
       
       KSCreatureMale *Bob = [[[KSCreatureMale alloc]
                           initWithName:@"Bob"]  autorelease];
       
       KSCreatureFemale *Anna = [[[KSCreatureFemale alloc]
                            initWithName:@"Anna"]  autorelease];
       
       KSCreatureMale *Serg = [[[KSCreatureMale alloc]
                           initWithName:@"Serg"]  autorelease];
       
       KSCreatureFemale *Elena = [[[KSCreatureFemale alloc]
                            initWithName:@"Elena"]  autorelease];
       
//       
       KSCreatureMale *childMale1 = [[KSCreatureMale new] autorelease];
       KSCreatureMale *childMale2 = [[KSCreatureMale new] autorelease];
       KSCreatureMale *childMale3 = [[KSCreatureMale new] autorelease];
       KSCreatureFemale *childFemale1 = [[KSCreatureFemale new] autorelease];
       KSCreatureFemale *childFemale2 = [[KSCreatureFemale new] autorelease];
       

//       NSArray *creaturesArray = [NSArray arrayWithObjects:Bob, Anna, Serg,
//                                  Elena, nil];
       
       NSArray *creaturesArray = @[Bob, Anna, Serg];
       
       [Bob addChild:childFemale1];
       [Bob addChild:childMale1];
       [Bob addChild:Elena];

       [Anna addChild:childMale2];
       [Anna addChild:childFemale2];
       
       [Elena addChild:childMale3];
       
       
       for (KSCreature *creature in creaturesArray) {
           [creature performGenderSpecificOperation];
       }
       
    
        NSLog(@"\n\n\n");
       
       
///////////////
// is expected that Bob say "Hi" and him children say "Hi"
       
       [Bob sayHi];
       
}

@end
 