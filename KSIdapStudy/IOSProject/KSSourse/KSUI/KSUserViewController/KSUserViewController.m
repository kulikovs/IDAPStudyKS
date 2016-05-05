//
//  KSUserTableViewController.m
//  KSIdapStudy
//
//  Created by KulikovS on 03.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSUserViewController.h"
#import "KSUserView.h"
#import "KSStringsModel.h"
#import "KSUserViewCell.h"

@interface KSUserViewController ()
@property (nonatomic, readonly) KSUserView *rootView;

@end

@implementation KSUserViewController

#pragma mark -
#pragma mark Accessors

KSRootViewAndReturnNilMacro(KSUserView);


#pragma mark -
#pragma mark Public

- (void)reloadData {
    [self.rootView.tabelView reloadData];
}

#pragma mark -
#pragma mark UITableViewDataSource Protocol


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.stringsModel.strings.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {

    KSUserViewCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass([KSUserViewCell class])];
    
    if (!cell) {
        UINib *nib = [UINib nibWithNibName:NSStringFromClass([KSUserViewCell class])
                                    bundle:[NSBundle mainBundle]];
        cell = [[nib instantiateWithOwner:self options:nil] firstObject];
        
        //  UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass([KSUserViewCell class])];
        //if (!cell) {
     //   cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
    //                                  reuseIdentifier:NSStringFromClass([KSUserViewCell class])];
    // }
    }
    
    cell.stringsLabel.text = self.stringsModel.strings[indexPath.row];
    
    return cell;
}

@end
