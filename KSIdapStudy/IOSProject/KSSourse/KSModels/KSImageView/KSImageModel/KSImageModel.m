//
//  KSImageModel.m
//  KSIdapStudy
//
//  Created by KulikovS on 26.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSImageModel.h"

@interface KSImageModel ()
@property (nonatomic, readonly, getter=isCached) BOOL cached;

@end

@implementation KSImageModel

#pragma mark -
#pragma mark Accessors

- (BOOL)isCached {
    return [[NSFileManager defaultManager] fileExistsAtPath:self.URL];
}

- (void)setURL:(NSString *)URL {
    if (_URL != URL) {
        _URL = URL;
    }
    
    [self load];
}
     
#pragma mark -
#pragma mark Public Methods

- (void)prepareToLoad {
    sleep(3);
    if (self.isCached) {
        self.imageInModel = [UIImage imageWithContentsOfFile:self.URL];
    }
}

- (void)finishLoading {
    [self setState:kKSModelStateLoaded withObject:self.imageInModel];
}

@end
