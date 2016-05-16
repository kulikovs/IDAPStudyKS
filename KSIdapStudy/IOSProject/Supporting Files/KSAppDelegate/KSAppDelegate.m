//
//  AppDelegate.m
//  IOSProject
//
//  Created by KulikovS on 19.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSAppDelegate.h"
#import "KSLabelViewController.h"
#import "KSUserViewController.h"
#import "KSArrayModel.h"
#import "KSStringModel.h"

static const NSString * kKSSaveStateName = @"/saveStateProgram.plist";

@interface KSAppDelegate ()
- (void)archiveRootObjectToFile:(NSString *)fileName;
- (NSString *)pathToFileInDocumentsWithName:(NSString *)fileName;

@end

@implementation KSAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    UIWindow *window = [UIWindow window];
    self.window = window;
    
    KSUserViewController *viewController = [KSUserViewController controllerFromNib];
    
    KSArrayModel *model =  [NSKeyedUnarchiver unarchiveObjectWithFile:[self pathToFileInDocumentsWithName:[kKSSaveStateName copy]]];
    viewController.arrayModel = model ? model : [KSArrayModel arrayModelWithObjects:[KSStringModel randomStringsModels]];
    window.rootViewController = viewController;
    
    [window makeKeyAndVisible];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {

}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    [self archiveRootObjectToFile:[kKSSaveStateName copy]];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {

}

- (void)applicationDidBecomeActive:(UIApplication *)application {

}

- (void)applicationWillTerminate:(UIApplication *)application {
    [self archiveRootObjectToFile:[kKSSaveStateName copy]];
}

#pragma mark -
#pragma mark Private Methods 

- (NSString *)pathToFileInDocumentsWithName:(NSString *)fileName {
    NSArray *documentsPaths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDir = [documentsPaths firstObject]; //first object ?
    NSString *path = [documentsDir stringByAppendingString:fileName];
    
    return path;
}

- (void)archiveRootObjectToFile:(NSString *)fileName {
    KSUserViewController *viewController = (KSUserViewController *)self.window.rootViewController; //Class UserView ???

    [NSKeyedArchiver archiveRootObject:viewController.arrayModel
                                toFile:[self pathToFileInDocumentsWithName:fileName]];
}

@end
