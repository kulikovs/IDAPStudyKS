//
//  KSArrayModelManager.m
//  KSIdapStudy
//
//  Created by KulikovS on 22.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSArrayModelManager.h"
#import "KSStringModel.h"

//@interface KSArrayModelManager ()
//@property (nonatomic, strong) NSString       *path;
//
//@end
//
//@implementation KSArrayModelManager
//
//#pragma mark -
//#pragma mark Public Methods
//
//- (void)load {
//    if (self.state == kKSArrayModelStateLoading) {
//        return;
//    } else {
//        self.state = kKSArrayModelStateLoading;
//    }
//    
//    KSWeakifySelfWithClass(KSArrayModel);
//    KSDispatchAsyncInBackground(^ {
//        KSStrongifySelfWithClass(KSArrayModel)
//        sleep(3);
//        KSArrayModel *model = [NSKeyedUnarchiver unarchiveObjectWithFile:self.path];
//        
//        model = model ? model : [KSArrayModel arrayModelWithObjects:[KSStringModel randomStringsModels]];
//        [self addObjects:model.arrayObjects];
//        
//        KSDispatchAsyncOnMainThred(^ {
//            KSStrongifySelfWithClass(KSArrayModel)
//            strongSelf.state = kKSArrayModelStateLoaded;
//        });
//    });
//}
//
//- (void)save {
//    [NSKeyedArchiver archiveRootObject:self toFile:self.path];
//}
//
//#pragma mark -
//#pragma mark NSCoding
//
//- (instancetype)initWithCoder:(NSCoder *)decoder {
//    self = [super init];
//    if (self) {
//        self.arrayObjects = [decoder decodeObjectForKey:kKSArrayObjectsForCoderKey];
//    }
//    
//    return self;
//}
//
//- (void)encodeWithCoder:(NSCoder *)aCoder {
//    [aCoder encodeObject:self.arrayObjects forKey:kKSArrayObjectsForCoderKey];
//}
//
//
//@end
