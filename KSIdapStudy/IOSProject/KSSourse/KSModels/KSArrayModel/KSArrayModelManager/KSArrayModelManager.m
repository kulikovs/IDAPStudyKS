//
//  KSArrayModelManager.m
//  KSIdapStudy
//
//  Created by KulikovS on 22.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSArrayModelManager.h"
#import "KSStringModel.h"

static NSString * const kKSSaveArrayModelKey       = @"saveArrayModel.plist";
static NSString * const kKSArrayObjectsForCoderKey = @"arrayObjects";

@interface KSArrayModelManager ()
@property (nonatomic, readonly) NSString    *path;

@end

@implementation KSArrayModelManager

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(save)
                                                     name:UIApplicationDidEnterBackgroundNotification
                                                   object:nil];
        
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(save)
                                                     name:UIApplicationWillTerminateNotification
                                                   object:nil];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSString *)path {
    return [NSFileManager pathToFileInDocumentsWithName:kKSSaveArrayModelKey];
}

#pragma mark -
#pragma mark Public Methods

- (void)load {
    if (self.state == kKSArrayModelStateLoading) {
        return;
    } else {
        self.state = kKSArrayModelStateLoading;
    }
    
    KSWeakifySelfWithClass(KSArrayModel);
    KSDispatchAsyncInBackground(^ {
        KSStrongifySelfWithClass(KSArrayModel)
        sleep(3);
        KSArrayModel *model = [NSKeyedUnarchiver unarchiveObjectWithFile:self.path];
        
        model = model ? model : [KSArrayModel arrayModelWithObjects:[KSStringModel randomStringsModels]];
        [strongSelf addObjects:model.objects];
        
        KSDispatchAsyncOnMainThred(^ {
            KSStrongifySelfWithClass(KSArrayModel)
            strongSelf.state = kKSArrayModelStateLoaded;
        });
    });
}

- (void)save {
    [NSKeyedArchiver archiveRootObject:self toFile:self.path];
}

#pragma mark -
#pragma mark NSCoding

- (instancetype)initWithCoder:(NSCoder *)decoder {
    self = [super init];
    if (self) {
        [self addObjects:[decoder decodeObjectForKey:kKSArrayObjectsForCoderKey]];
    }
    
    return self;
}

- (void)encodeWithCoder:(NSCoder *)aCoder {
    [aCoder encodeObject:self.objects forKey:kKSArrayObjectsForCoderKey];
}


@end
