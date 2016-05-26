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
@property (nonatomic, strong) KSImageModel              *imageModel;
@property (nonatomic, strong) UIActivityIndicatorView   *spinner;

- (void)baseInit;

@end

@implementation KSImageView

@dynamic url;

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

#pragma mark -
#pragma mark Accessor

- (NSString *)url {

}

#pragma mark -
#pragma mark Private Methods

- (void)baseInit {
    KSImageView *imageView = [[KSImageView alloc] initWithFrame:self.frame];
    [self addSubview:imageView];
    self.backgroundColor = [UIColor clearColor];
    
    UIActivityIndicatorView *spinner = self.spinner;
    spinner = [[UIActivityIndicatorView alloc]
               initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhite];
    spinner.center = imageView.center;
    spinner.hidesWhenStopped = YES;
}

@end
