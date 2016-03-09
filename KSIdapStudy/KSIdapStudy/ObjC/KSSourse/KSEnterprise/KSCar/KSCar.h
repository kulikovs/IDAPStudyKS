//
//  KSCar.h
//  KSIdapStudy
//
//  Created by KulikovS on 09.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KSCar : NSObject
@property (nonatomic, assign) BOOL          isDirty;
@property (nonatomic, assign) NSUInteger    cash;

- (NSUInteger)payMoney:(NSUInteger)sum;

@end

