//
//  KSUserTableViewController.m
//  KSIdapStudy
//
//  Created by KulikovS on 03.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSUserTableViewController.h"
#import "KSTableView.h"

@interface KSUserTableViewController ()
@property (nonatomic, readonly) KSTableView *rootView;

@end

@implementation KSUserTableViewController

#pragma mark -
#pragma mark Accessors

KSRootViewAndReturnNilMacro(KSTableView);


#pragma mark -
#pragma mark Life cycle

- (void)viewDidLoad {
    [super viewDidLoad];
}


@end
