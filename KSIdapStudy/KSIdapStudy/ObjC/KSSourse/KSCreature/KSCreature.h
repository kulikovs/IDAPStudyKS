//
//  KSHuman.h
//  KSIdapStudy
//
//  Created by KulikovS on 18.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, KSGenderType) {
    kKSGenderUndefine,
    kKSMale,
    kKSFemale,
};

@interface KSCreature : NSObject

@property (nonatomic, readonly)   NSString        *name;
@property (nonatomic, readonly)   NSArray         *children;
@property (nonatomic, readonly)   KSGenderType    gender;
@property (nonatomic, readonly)   NSUInteger      age;
@property (nonatomic, readonly)   CGFloat         weight;

- (instancetype)initWithName: (NSString*)name andGender:(KSGenderType)gender;
- (instancetype)initWithName: (NSString*)name;

- (void)sayHi;

- (void)addChild: (KSCreature *) child;
- (void)removeChild: (KSCreature *)child;
- (void)removeAllChildren;
- (void)howManyChildren;

- (KSCreature*)giveBirthChild;
- (void)goToWar;

@end
