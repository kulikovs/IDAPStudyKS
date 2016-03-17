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
#import "KSObserver.h"

@interface KSEmployee : KSObserver <KSMoneyProtocol, KSWorkerProtocol>

- (void)performWithObject:(id<KSMoneyProtocol>)object;

@end

