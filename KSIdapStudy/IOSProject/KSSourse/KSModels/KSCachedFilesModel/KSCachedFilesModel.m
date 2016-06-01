//
//  KSCachedFilesModel.m
//  KSIdapStudy
//
//  Created by KulikovS on 01.06.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSCachedFilesModel.h"
static NSString   *  const  kKSStringCachedFilesSave   =   @"cachedFilesSave.plist";
static NSString   *  const  kKSStringCachedFiles       =   @"cachedFiles";

@interface KSCachedFilesModel ()
@property (nonatomic, strong)   NSMutableDictionary *cachedFiles;
@property (nonatomic, readonly) NSString            *path;
@property (nonatomic, readonly) NSArray             *notificationKey;

- (void)save;

@end

@implementation KSCachedFilesModel

#pragma mark - 
#pragma mark Class Methods

+ (instancetype)cachedFilesModel {
    static KSCachedFilesModel *model = nil;
    static dispatch_once_t once_token = 0;
    dispatch_once(&once_token, ^{
                    model =  [[super alloc] initUniqueInstance];
                    model.cachedFiles = [NSMutableDictionary dictionary];
                    [model addObserverWithKeys:model.notificationKey];
                  });
    
    return model;
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self removeObserverWithKeys:self.notificationKey];
}

- (instancetype) initUniqueInstance {
    return [super init];
}

#pragma mark -
#pragma mark Accessors

- (NSString *)path {
    return [NSFileManager pathToFileInDocumentsWithName:kKSStringCachedFilesSave];
}

- (NSArray *)notificationKey {
    return @[UIApplicationDidEnterBackgroundNotification, UIApplicationWillTerminateNotification];
}

#pragma mark -
#pragma mark Private Methods

- (void)addObserverWithKeys:(NSArray *)keys {
    for (NSString *key in keys) {
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(save)
                                                     name:key
                                                   object:nil];
    }
}

- (void)removeObserverWithKeys:(NSArray *)keys {
    for (NSString *key in keys) {
        [[NSNotificationCenter defaultCenter] removeObserver:self name:key object:nil];
    }
}

- (void)save {
    [NSKeyedArchiver archiveRootObject:self toFile:self.path];
}

#pragma mark -
#pragma mark Public Methods

- (NSString *)URLStringForFileName:(NSString *)fileName {
    return [self.cachedFiles objectForKey:fileName];
}

- (BOOL)fileIsCashed:(NSString *)URL {
    NSArray *keys = self.cachedFiles.allKeys;
    
    for (NSUInteger index = 0; index < keys.count; index ++) {
        if ([keys[index] isEqualToString:URL]) {
            return YES;
        }
    }
    
    return NO;
}

- (void)removeURLString:(NSString *)URLString { // question
    [self.cachedFiles removeObjectForKey:URLString];
}

- (void)addURLString:(NSString *)URL {
    if ([self fileIsCashed:URL]) {
        return;
    } else {
        [self.cachedFiles setObject:[URL lastPathComponent] forKey:URL];
    }
}

#pragma mark -
#pragma mark NSCoding

- (instancetype)initWithCoder:(NSCoder *)decoder {
    self = [KSCachedFilesModel cachedFilesModel];
    if (self) {
        self.cachedFiles = [decoder decodeObjectForKey:kKSStringCachedFiles];
    }
    
    return self;
}

- (void)encodeWithCoder:(NSCoder *)aCoder {
    [aCoder encodeObject:self.cachedFiles forKey:kKSStringCachedFiles];
}

@end
