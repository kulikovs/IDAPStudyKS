//
//  KSUserViewCell.m
//  KSIdapStudy
//
//  Created by KulikovS on 05.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSUserViewCell.h"
#import "KSStringModel.h"
#import "KSImageView.h"

@interface KSUserViewCell ()
@property (nonatomic, strong) KSStringModel *stringModel;

@end

@implementation KSUserViewCell

#pragma mark -
#pragma mark Accessors

- (void)setStringModel:(KSStringModel *)stringModel {
    if (_stringModel != stringModel) {
        _stringModel = stringModel;

        self.customImageView.URLString = stringModel.URLString;
        self.stringsLabel.text = stringModel.string;
        
//        KSWeakifySelfWithClass(KSUserViewCell);
//        
//        [_stringModel addHandler:^(UIImage *image) {
//            KSStrongifySelfWithClass(KSUserViewCell);
//            
//            strongSelf.stringsImage.image = image;
//            [strongSelf.activeIndicator stopAnimating];
//          } state:kKSModelStateLoaded object:self];
//        
//        [self.activeIndicator startAnimating];
//        [_stringModel load];
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)fillWithModel:(KSStringModel *)model {
    self.stringModel = model;
}

@end
