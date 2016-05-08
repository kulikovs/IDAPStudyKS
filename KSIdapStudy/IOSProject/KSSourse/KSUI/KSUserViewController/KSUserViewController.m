//
//  KSUserTableViewController.m
//  KSIdapStudy
//
//  Created by KulikovS on 03.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSUserViewController.h"
#import "KSUserView.h"
#import "KSArrayModel.h"
#import "KSUserViewCell.h"

@interface KSUserViewController ()
@property (nonatomic, readonly) KSUserView *rootView;

@end

@implementation KSUserViewController

#pragma mark -
#pragma mark Accessors

KSRootViewAndReturnNilMacro(KSUserView);

-(void)setStringsModel:(KSArrayModel *)arrayModel {
    if (_arrayModel != arrayModel) {
        _arrayModel = arrayModel;
        [self.rootView.tabelView reloadData];
    }
}

#pragma mark -
#pragma mark UITableViewDataSource Protocol

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.arrayModel.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    KSUserViewCell *cell = [tableView dequeueReusableCellFromBundleWithClass:[KSUserViewCell class]];
    id object = self.arrayModel.objects[indexPath.row];
    cell.stringsLabel.text = [object string];

    return cell;
}

@end
