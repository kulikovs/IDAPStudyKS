//
//  KSLoginViewController.m
//  KSIdapStudy
//
//  Created by KulikovS on 08.06.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSLoginViewController.h"
#import "KSLoginView.h"

@interface KSLoginViewController ()
@property (nonatomic, readonly) KSLoginView *rootView;

@end

@implementation KSLoginViewController


#pragma mark -
#pragma mark Accessors

KSRootViewAndReturnNilMacro(KSLoginView);

#pragma mark -
#pragma mark View LifeCycle

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
//    [self.rootView showLoadingViewWithDefaultTextAnimated:YES];

     self.rootView.loginButton = [[FBSDKLoginButton alloc] init];
}

@end
