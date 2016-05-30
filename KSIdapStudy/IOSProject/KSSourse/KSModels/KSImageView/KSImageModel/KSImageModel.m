//
//  KSImageModel.m
//  KSIdapStudy
//
//  Created by KulikovS on 26.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSImageModel.h"

@interface KSImageModel ()
@property (nonatomic, readonly, getter=isCached) BOOL                       cached;
@property (nonatomic, readonly)                  NSString                   *path;
@property (nonatomic, readonly)                  NSString                   *fileName;
@property (nonatomic, strong)                    NSURLSession               *URLSession;
@property (nonatomic, strong)                    NSURLSessionDownloadTask   *downloadTask;

- (void)removeIfNeeded;
- (void)dump;
- (void)performDownload;
- (void)performSetImage;

@end

@implementation KSImageModel

@dynamic path;
@dynamic fileName;

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype) init {
    self = [super init];
    if (self) {
        self.URLSession = [NSURLSession sessionWithConfiguration:
                           [NSURLSessionConfiguration defaultSessionConfiguration]];
    }
    
    return self;
}

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
   return [NSFileManager pathToFileInDocumentsWithName:self.fileName];
}

- (NSString *)fileName {
   return [[self.URL absoluteString] lastPathComponent];
}

- (void)setDownloadTask:(NSURLSessionDownloadTask *)downloadTask {
    if (_downloadTask != downloadTask) {
        [_downloadTask cancel];
        
         _downloadTask = downloadTask;
        [downloadTask resume];
    }
}

#pragma mark -
#pragma mark Private

- (void)removeIfNeeded {
    if (self.isCached) {
        NSError *error = nil;
        [[NSFileManager defaultManager] removeItemAtPath:self.path error:&error];
    }
}

- (void)performDownload {
    self.downloadTask = [self.URLSession downloadTaskWithURL:self.URL
                                           completionHandler:^(NSURL *location, NSURLResponse *response, NSError *error)
    {
        NSError *fileError = nil;
        NSFileManager *fileManager = [NSFileManager defaultManager];
        NSURL * url = [NSURL fileURLWithPath:self.path];
                             
        [fileManager copyItemAtURL:location toURL:url error:&fileError];
        self.image = [UIImage imageWithContentsOfFile:self.path];
        NSLog(@"");
            KSWeakifySelf;
            KSDispatchAsyncOnMainThread(^{
                KSStrongifySelfWithClass(KSImageModel);
                [strongSelf setState:kKSModelStateLoaded withObject:self.image];
            });
     }];
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
    } else
        [self performDownload];
}

- (void)dump {
    self.state = kKSModelStateUndefined;
}

- (void)finishLoading {
    NSUInteger state = self.image ? kKSModelStateLoaded : kKSModelStateFailed;
    [self setState:state withObject:self.image];
}

@end
