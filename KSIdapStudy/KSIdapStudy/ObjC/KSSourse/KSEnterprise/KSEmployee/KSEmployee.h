//
//  KSEmployee.h
//  KSIdapStudy
//
//  Created by KulikovS on 09.03.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KSWorkerProtocol.h"
#import "KSMoneyProtocol.h"

@interface KSEmployee : NSObject <KSMoneyProtocol, KSWorkerProtocol>
@property (nonatomic, assign) id<KSWorkerProtocol> delegate;

- (void)performWithObject:(id)object;

@end

