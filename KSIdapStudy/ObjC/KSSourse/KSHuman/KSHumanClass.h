//
//  KSHuman.h
//  KSIdapStudy
//
//  Created by KulikovS on 18.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    kKSGenderUndefine,
    kKSMale,
    kKSFemale,
} KSGenderType;

@interface KSHuman : NSObject

@property (nonatomic, copy)     NSString *name;
@property (nonatomic, copy)     NSArray *children;
@property (nonatomic, assign)   KSGenderType gender;
@property (nonatomic, assign)   uint16_t age;
@property (nonatomic, assign)   float weignt;

- (instancetype)initWithAge;

@end



