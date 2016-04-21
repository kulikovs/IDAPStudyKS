//
//  KSLabelViewController.m
//  KSIdapStudy
//
//  Created by KulikovS on 20.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSLabelViewController.h"

@interface KSLabelViewController ()

@end

@implementation KSLabelViewController

- (void)loadView {
    [super loadView];
    
    NSLog(@"Load view"); //загружается
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSLog(@"view did load"); //загружено
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    NSLog(@"View will appear"); // скоро появится
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    NSLog(@"view did appear"); //появилось
    
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    NSLog(@"view will disappear"); //скоро исчезнет
}


- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    
    NSLog(@"view did disappear"); //исчезло
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
