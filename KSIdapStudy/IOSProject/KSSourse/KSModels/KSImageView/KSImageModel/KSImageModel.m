//
//  KSImageModel.m
//  KSIdapStudy
//
//  Created by KulikovS on 26.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSImageModel.h"

@interface KSImageModel ()
@property (nonatomic, readonly, getter=isCached) BOOL     cached;
@property (nonatomic, readonly)                  NSString *path;
@property (nonatomic, readonly)                  NSString *fileName;

- (void)removeIfNeeded;
- (void)dump;

@end

@implementation KSImageModel

@dynamic path;
@dynamic fileName;

#pragma mark -
#pragma mark Accessors

- (BOOL)isCached {
    return [[NSFileManager defaultManager] fileExistsAtPath:self.path];
}

- (void)setURL:(NSURL *)URL {
    if (![_URL isEqual:URL]) {
        _URL = URL;
        
        [self dump];
    }
    
    [self load];
}

- (NSString *)path {
    return [self.URL absoluteString];
   //return [NSFileManager pathToFileInDocumentsWithName:self.fileName];
}

- (NSString *)fileName {
   return [[self.URL absoluteString] lastPathComponent];
}

#pragma mark -
#pragma mark Private

- (void)removeIfNeeded {
    if (self.isCached) {
        NSError *error = nil;
        [[NSFileManager defaultManager] removeItemAtPath:self.path error:&error];
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)prepareToLoad {
    if (self.isCached) {
        UIImage *image = [UIImage imageWithContentsOfFile:self.path];
        
        if (!image) {
            [self removeIfNeeded];
        } else {
            self.image = image;
        }
    }
}

- (void)dump {
    self.state = kKSModelStateUndefined;
}

- (void)finishLoading {
    NSUInteger state = self.image ? kKSModelStateLoaded : kKSModelStateFailed;
    [self setState:state withObject:self.image];
}

@end
