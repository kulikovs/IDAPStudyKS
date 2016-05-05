//
//  KSUserTableViewController.h
//  KSIdapStudy
//
//  Created by KulikovS on 03.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <UIKit/UIKit.h>

@class KSStringsModel;

@interface KSUserViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>
@property (nonatomic, strong) KSStringsModel *stringsModel;

- (void)reloadData;

@end
