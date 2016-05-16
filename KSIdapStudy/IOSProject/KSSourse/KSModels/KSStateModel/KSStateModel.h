//
//  KSStateModel.h
//  KSIdapStudy
//
//  Created by KulikovS on 12.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger) {
    kKSAddedState,
    kKSRemoveState,
} kKSObjectState;

@interface KSStateModel : NSObject
@property (nonatomic, assign) kKSObjectState   state;
@property (nonatomic, assign) NSUInteger       index;

@end
