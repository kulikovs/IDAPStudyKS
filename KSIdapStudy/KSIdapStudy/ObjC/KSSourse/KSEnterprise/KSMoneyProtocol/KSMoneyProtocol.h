//
//  KSMoneyProtocol.h
//  KSIdapStudy
//
//  Created by KulikovS on 13.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol KSMoneyProtocol <NSObject>
@property (nonatomic, assign) NSUInteger money;

@required
- (NSUInteger)giveMoney;

@optional
- (void)takeMoney:(NSUInteger)money;

@end
