//
//  KSTableView.h
//  KSIdapStudy
//
//  Created by KulikovS on 03.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KSUserView : UIView
@property (nonatomic, strong) IBOutlet UITableView *tabelView;
@property (nonatomic, strong) IBOutlet UISwitch    *editTableSwitch;
@property (nonatomic, strong) IBOutlet UIButton    *reloadButton;


@end
