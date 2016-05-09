//
//  KSUserViewCell.m
//  KSIdapStudy
//
//  Created by KulikovS on 05.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSUserViewCell.h"
#import "KSStringModel.h"

@implementation KSUserViewCell

- (void)fillWithModel:(KSStringModel *)model {
    self.stringsLabel.text = [model string];
    self.stringsImage = [[UIImageView alloc] initWithImage:[model image]];
}

@end
