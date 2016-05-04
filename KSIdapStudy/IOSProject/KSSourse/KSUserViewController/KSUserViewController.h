//
//  KSUserTableViewController.h
//  KSIdapStudy
//
//  Created by KulikovS on 03.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <UIKit/UIKit.h>

@class KSUserView;
@class KSStringsModel;


@interface KSUserViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>
@property (nonatomic, readonly)   KSUserView       *rootView;
@property (nonatomic, readonly)   KSStringsModel   *strings;

- (void)addStringsModelWithRandomStringsRandomCount;

@end
