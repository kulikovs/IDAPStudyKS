//
//  KSImageModel.m
//  KSIdapStudy
//
//  Created by KulikovS on 26.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSImageModel.h"
#import "KSCachedFilesModel.h"

@interface KSImageModel ()
@property (nonatomic, readonly, getter=isCached) BOOL                       cached;
@property (nonatomic, readonly)                  NSString                   *path;
@property (nonatomic, readonly)                  NSString                   *fileName;
@property (nonatomic, strong)                    NSURLSession               *URLSession;
@property (nonatomic, strong)                    NSURLSessionDownloadTask   *downloadTask;

- (void)removeIfNeeded;
- (void)dump;
- (void)performDownload;
- (void)loadFromFileSystem;

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
   return [[KSCachedFilesModel cachedFilesModel] fileIsCashed:self.URL.absoluteString];
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
        [_downloadTask resume];
    }
}

#pragma mark -
#pragma mark Private

- (void)removeIfNeeded {
    if (self.isCached) {
        NSError *error = nil;
        if ([[NSFileManager defaultManager] removeItemAtPath:self.path error:&error]) {
            [[KSCachedFilesModel cachedFilesModel] removeURLString:self.URL.absoluteString];
        }
    }
}

- (void)performDownload {
    if (self.isCached) {
        [self loadFromFileSystem];
    } else {
        self.downloadTask = [self.URLSession downloadTaskWithURL:self.URL
                                               completionHandler:^(NSURL *location,
                                                                   NSURLResponse *response,
                                                                   NSError *error)
    {
        NSError *fileError = nil;
        NSFileManager *fileManager = [NSFileManager defaultManager];
        [fileManager copyItemAtURL:location toURL:[NSURL fileURLWithPath:self.path] error:&fileError];
       [[KSCachedFilesModel cachedFilesModel] addURLString:self.URL.absoluteString];
        self.image = [UIImage imageWithContentsOfFile:self.path];
        [self loadFromFileSystem];
     }];
    }
}

- (void)loadFromFileSystem {
    if (self.isCached) {
        UIImage *image = [UIImage imageWithContentsOfFile:self.path];
        
        if (!image) {
            [self removeIfNeeded];
        } else {
            self.image = image;
            [self completeLoading];
        }
    }
}

- (void)prepareToLoad {
    if (self.URL.isFileURL) {
        [self loadFromFileSystem];
    } else {
        [self performDownload];
    }
}

- (void)dump {
    self.state = kKSModelStateUndefined;
}

- (void)completeLoading {
    KSWeakifySelf;
    KSDispatchAsyncOnMainThread(^{
        KSStrongifySelfWithClass(KSImageModel);
        NSUInteger state = kKSModelStateFailed;
        if (self.image) {
            state = kKSModelStateLoaded;
            [[KSCachedFilesModel cachedFilesModel] addURLString:self.URL.absoluteString];
        }
        
        [self setState:state withObject:self.image];
    });
}

@end
