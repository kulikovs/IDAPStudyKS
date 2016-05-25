//
//  KSModel.m
//  KSIdapStudy
//
//  Created by KulikovS on 24.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSModel.h"

@implementation KSModel

#pragma mark -
#pragma mark Public Methods

- (void)setUpLoading {

}

- (void)prepareToLoad {

}

- (void)finishLoading {

}

- (void)load {
    if (self.state == kKSModelStateLoading) {
        return;
    }
        if (self.state == kKSModelStateLoaded) {
            self.state = kKSModelStateLoading;
            [self finishLoading];
            return;
        } else {
            
        self.state = kKSModelStateLoading;
    }
    
    KSWeakifySelf;
    KSDispatchAsyncInBackground(^ {
        KSStrongifySelfWithClass(KSModel)
        
        [self prepareToLoad];
        
        KSDispatchAsyncOnMainThred(^ {
            KSStrongifySelfWithClass(KSModel)
            
            [self finishLoading];
        });
    });
}


@end
