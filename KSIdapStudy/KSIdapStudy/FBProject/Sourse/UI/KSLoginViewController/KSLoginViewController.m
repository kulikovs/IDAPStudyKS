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
//    sleep(2);
     self.rootView.loginButton = [[FBSDKLoginButton alloc] init];
}


- (IBAction)onClickLoginButton:(id)sender {
    FBSDKLoginManager *login = [[FBSDKLoginManager alloc] init];
    [login logInWithReadPermissions: @[@"public_profile", @"email", @"user_friends"]
     fromViewController:self
     handler:^(FBSDKLoginManagerLoginResult *result, NSError *error) {
         if (error) {
             NSLog(@"Process error");
         } else if (result.isCancelled) {
             NSLog(@"Cancelled");
         } else {
             NSLog(@"Logged in");
         }
     }];
}

- (void)loginButtonDidLogOut:(FBSDKLoginButton *)loginButton {
    
}

@end
