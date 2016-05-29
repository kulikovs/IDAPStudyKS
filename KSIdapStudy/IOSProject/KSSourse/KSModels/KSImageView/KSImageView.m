//
//  KSImageView.m
//  KSIdapStudy
//
//  Created by KulikovS on 26.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSImageView.h"
#import "KSImageModel.h"

@interface KSImageView ()
@property (nonatomic, strong) UIActivityIndicatorView   *spinner;
@property (nonatomic, strong) UIImageView               *customImageView;

- (void)baseInit;
- (void)performSpinner;

@end

@implementation KSImageView

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self baseInit];
    }
    
    return self;
}

- (instancetype)initWithCoder:(NSCoder *)aDecoder {
    self = [super initWithCoder:aDecoder];
    if (self) {
        [self baseInit];
    }
    
    return self;
}

- (void)baseInit {
    UIImageView *imageView = [[UIImageView alloc] initWithFrame:self.bounds];
    [self addSubview:imageView];
    self.customImageView = imageView;
    
    self.backgroundColor = [UIColor clearColor];
    [self performSpinner];
    self.imageModel = [KSImageModel new];
}

#pragma mark -
#pragma mark Accessor

- (void)setURL:(NSString *)URL {
    if (_URL != URL) {
        _URL = URL;
    }
    
    self.imageModel.URL = self.URL;
}

- (void)setImageModel:(KSImageModel *)imageModel {
    if (_imageModel != imageModel) {
        _imageModel = imageModel;
    }
        KSWeakifySelf;
        [_imageModel addHandler:^(UIImage *image) {
            KSStrongifySelfWithClass(KSImageView);
        
            strongSelf.customImageView.image = image;
            [strongSelf.spinner stopAnimating];
        } state:kKSModelStateLoaded object:self];
    
    [self.spinner startAnimating];
}

#pragma mark -
#pragma mark Private Methods

- (void)performSpinner {

    UIActivityIndicatorView *spinner = [[UIActivityIndicatorView alloc]
                                        initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
    
    UIImageView *imageView = self.customImageView;
    spinner.center = imageView.center;
    [spinner startAnimating];
    [imageView addSubview:spinner];
    
     self.spinner = spinner;
}

@end
