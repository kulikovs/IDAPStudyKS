//
//  KSUserTableViewController.m
//  KSIdapStudy
//
//  Created by KulikovS on 03.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSUserTableViewController.h"
#import "KSTableView.h"

static const NSUInteger kKSDefaultNumberRowsForTableView = 15;

@interface KSUserTableViewController ()
@property (nonatomic, readonly) KSTableView     *rootView;
@property (nonatomic, strong)   NSArray  *stringArray;

@end

@implementation KSUserTableViewController

#pragma mark -
#pragma mark Accessors

KSRootViewAndReturnNilMacro(KSTableView);

#pragma mark -
#pragma mark Life cycle

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.rootView.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"RandomString"];
    
    self.stringArray = [NSMutableArray arrayWithObject:[NSString randomString]];
}

#pragma mark -
#pragma mark UITableViewDataSource Protocol


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return kKSDefaultNumberRowsForTableView;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSString *cellIdentifire = @"RandomString";
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                                   reuseIdentifier:cellIdentifire];

    cell.textLabel.text = self.stringArray[0];
    
    return cell;
}

#pragma mark -
#pragma mark UITableViewDelegate Protocol

@end
