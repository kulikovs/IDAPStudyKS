//
//  KSImageModel.m
//  KSIdapStudy
//
//  Created by KulikovS on 26.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSImageModel.h"
#import "KSSharedCacheModel.h"

@interface KSImageModel ()
@property (nonatomic, readonly, getter=isCached) BOOL                       cached;
@property (nonatomic, readonly)                  NSString                   *path;
@property (nonatomic, readonly)                  NSString                   *fileName;
@property (nonatomic, readonly)                  KSSharedCacheModel         *sharedCacheModel;
@property (nonatomic, strong)                    NSURLSession               *URLSession;
@property (nonatomic, strong)                    NSURLSessionDownloadTask   *downloadTask;

- (void)removeIfNeeded;
- (void)dump;
- (void)performDownload;
- (void)loadFromFileSystem;

@end

@implementation KSImageModel

@dynamic cached;
@dynamic path;
@dynamic fileName;
@dynamic sharedCacheModel;

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
   return [self.sharedCacheModel isCashedForURLString:self.URL.absoluteString];
}

- (void)setURL:(NSURL *)URL {
    if (![_URL isEqual:URL]) {
        _URL = URL;
        
        [self dump];
    }
    
    [self load];
}

- (KSSharedCacheModel *)sharedCacheModel {
    return [KSSharedCacheModel sharedCacheModel];;
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
            [self.sharedCacheModel removeURLString:self.URL.absoluteString];
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
        if (!error) {
        NSError *fileError = nil;
        NSString *path = self.path;
            
        NSFileManager *fileManager = [NSFileManager defaultManager];
        [fileManager copyItemAtURL:location toURL:[NSURL fileURLWithPath:path] error:&fileError];
            if (self.isCached && [fileManager fileExistsAtPath:path]) {
                [fileManager removeItemAtPath:path error:nil];
            }
            
            if (!fileError) {
                [self.sharedCacheModel addURLString:self.URL.absoluteString fileName:self.fileName];
            }
            
            [self loadFromFileSystem];
        }
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
        }
    }
    
    [self completeLoading];
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
        NSUInteger state = self.image ? kKSModelStateLoaded : kKSModelStateFailed;
        [self setState:state withObject:self.image];
    });
}

@end
