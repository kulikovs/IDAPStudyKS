//
//  KSUserViewCell.h
//  KSIdapStudy
//
//  Created by KulikovS on 05.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KSUserViewCell : UITableViewCell
@property (nonatomic, strong) IBOutlet UILabel      *stringsLabel;
@property (nonatomic, strong) IBOutlet UIImageView  *stringsImage;

- (void)fillWithModel:(id)model;

@end
