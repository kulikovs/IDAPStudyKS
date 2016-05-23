//
//  KSUserViewCell.m
//  KSIdapStudy
//
//  Created by KulikovS on 05.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSUserViewCell.h"
#import "KSStringModel.h"

@interface KSUserViewCell ()
@property (nonatomic, strong) KSStringModel *stringModel;

@end

@implementation KSUserViewCell

#pragma mark -
#pragma mark Accessors

- (void)setStringModel:(KSStringModel *)stringModel {
    if (_stringModel != stringModel) {
        stringModel = stringModel;

        self.stringsImage.image = nil;
        
        KSWeakifySelfWithClass(KSUserViewCell);
        
        [_stringModel addHandler:^(UIImage *image) {
            KSStrongifySelfWithClass(KSUserViewCell);
            
            strongSelf.stringsImage.image = image;
            [strongSelf.activeIndicator stopAnimating];
          } state:kKSStringModelStateLoaded
                              object:self];
        
         self.stringsLabel.text = stringModel.string;
        [stringModel load];
        [self.activeIndicator startAnimating];
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)fillWithModel:(KSStringModel *)model {
    self.stringModel = model;
}

@end
