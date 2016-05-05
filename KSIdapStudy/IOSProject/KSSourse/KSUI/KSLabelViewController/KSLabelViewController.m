//
//  KSLabelViewController.m
//  KSIdapStudy
//
//  Created by KulikovS on 20.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSLabelViewController.h"
#import "KSLabelView.h"

@interface KSLabelViewController ()
@property (nonatomic, readonly) KSLabelView *rootView;

@end

@implementation KSLabelViewController

#pragma mark -
#pragma mark Accessors

KSRootViewAndReturnNilMacro(KSLabelView);

#pragma mark -
#pragma mark Handling Interface

- (IBAction)onClickAnimationButton:(id)sender {
    [self.rootView moveLabel];
}

@end
