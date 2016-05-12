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
#import "KSStringModel.h"
#import "KSStateModel.h"

@interface KSUserViewController ()
@property (nonatomic, readonly) KSUserView *rootView;

@end

@implementation KSUserViewController

#pragma mark -
#pragma mark Accessors

KSRootViewAndReturnNilMacro(KSUserView);

-(void)setArrayModel:(KSArrayModel *)arrayModel {
    if (_arrayModel != arrayModel) {
        _arrayModel = arrayModel;
        
        KSWeakifySelfWithClass(KSUserViewController);
        [_arrayModel addHandler:^(KSStateModel *object) {
            KSStrongifySelfWithClass(KSUserViewController);
            UITableView *tableView = strongSelf.rootView.tabelView;
            NSIndexPath *indexPath = [NSIndexPath indexPathForItem:strongSelf.arrayModel.index inSection:0];
            if (object.state == kKSRemoveState) {
                [tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:indexPath]
                                 withRowAnimation:UITableViewRowAnimationTop];
            } else {
                [tableView insertRowsAtIndexPaths:[NSArray arrayWithObject:indexPath]
                                 withRowAnimation:UITableViewRowAnimationLeft];
                
            }
        }
                          state:kKSChangedState
                         object:self];
    }
}

#pragma mark -
#pragma mark Handling

- (IBAction)onEditTable:(id)sender {
    KSUserView *rootview = self.rootView;
    rootview.tabelView.editing = !rootview.editTableSwitch.on;
}

#pragma mark -
#pragma mark UITableViewDataSource Protocol

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.arrayModel.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    KSUserViewCell *cell = [tableView dequeueReusableCellFromNibWithClass:[KSUserViewCell class]];
    [cell fillWithModel:self.arrayModel[indexPath.row]];
    
    return cell;
}

- (void)        tableView:(UITableView *)tableView
       commitEditingStyle:(UITableViewCellEditingStyle)editingStyle
        forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        [self.arrayModel removeObjectAtIndex:indexPath.row];
    } else {
        KSStringModel *string = [KSStringModel new];
        [self.arrayModel addObject:string];
    }
}

- (NSString *)                              tableView:(UITableView *)tableView
    titleForDeleteConfirmationButtonForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return @"Remove";
}

- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath {
    return YES;
}

- (void)            tableView:(UITableView *)tableView
           moveRowAtIndexPath:(NSIndexPath *)fromIndexPath
                  toIndexPath:(NSIndexPath *)toIndexPath
{
    [self.arrayModel moveObjectAtIndex:fromIndexPath.row onObjectAtIndex:toIndexPath.row];
}

- (UITableViewCellEditingStyle)tableView:(UITableView *)aTableView
           editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.row == 0) {
        return UITableViewCellEditingStyleInsert;
    } else {
        return UITableViewCellEditingStyleDelete;
    }
}

@end
