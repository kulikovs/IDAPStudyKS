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
} KSObjectState;

@interface KSStateModel : NSObject
@property (nonatomic, assign) KSObjectState   state;
@property (nonatomic, assign) NSUInteger       index;

@end
