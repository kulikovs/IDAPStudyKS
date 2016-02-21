//
//  KSCreatureTest.m
//  KSIdapStudy
//
//  Created by KulikovS on 19.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSCreatureTest.h"

@implementation KSCreatureTest

+(void)creatureTest {
   @autoreleasepool {
       
       KSCreature *Bob = [[[KSCreature alloc]
                           initWithName:@"Bob"
                           andGender:kKSMale ]  autorelease];
       
       KSCreature *Anna = [[[KSCreature alloc]
                            initWithName:@"Anna"
                            andGender:kKSFemale ]  autorelease];
       
       KSCreature *Serg = [[[KSCreature alloc]
                           initWithName:@"Serg"
                           andGender:kKSMale ]  autorelease];
       
       KSCreature *Elena = [[[KSCreature alloc]
                            initWithName:@"Elena"
                            andGender:kKSFemale ]  autorelease];
       
       KSCreature *child = [Bob giveBirthChild];
       KSCreature *child1 = [Anna giveBirthChild];
       KSCreature *child2 = [Anna giveBirthChild];
       KSCreature *child3 = [Anna giveBirthChild];
       
//
//       NSArray *creaturesArray = [NSArray arrayWithObjects:Bob, Anna, Serg,
//                                  Elena, nil];
       
       NSArray *creaturesArray = @[Bob, Anna, Serg, Elena];
       
       [Bob addChild:child];
       [Bob addChild:child1];
       
       [Anna addChild:child2];
       [Anna addChild:child3];
       
       [child addChild:Anna];
       [child addChild:child2];
       [child addChild:child3];
       
///// creature goes to war or giving birth to a child
       
///// we should get two messages "You're the man! Go to War!"
       
///// and two messages "I'm happy! My child is beautiful!"
       
       NSEnumerator *enumerator = [creaturesArray objectEnumerator];
       KSCreature *object = [enumerator nextObject];
       while (object) {
           if (object.gender == kKSFemale) {
               [object giveBirthChild];
               NSLog(@"I'm happy! My child is beautiful!");
           }
           if (object.gender == kKSMale) {
               [object goToWar];
           }
           
           object = [enumerator nextObject];
       }
       
        NSLog(@"\n\n\n");
       
///////////////
// is expected that Bob say "Hi" and him children say "Hi"
       
       [Bob sayHi];
       
       NSLog(@"\n\n\n");
       
       [Bob howManyChildren];
       
   }
}

@end
 