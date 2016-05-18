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

static const NSString * kKSSaveStateName = @"saveStateProgram.plist";

@interface KSAppDelegate ()
@property (nonatomic, strong) KSUserViewController *viewController;

- (void)archiveRootObjectToFile:(NSString *)fileName;

@end

@implementation KSAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    UIWindow *window = [UIWindow window];
    self.window = window;
    
    KSUserViewController *viewController = [KSUserViewController controllerFromNib];
    self.viewController = viewController;
    
    KSArrayModel *model =  [NSKeyedUnarchiver unarchiveObjectWithFile:
                            [NSFileManager pathToFileInDocumentsWithName:[kKSSaveStateName copy]]];
    
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

- (void)archiveRootObjectToFile:(NSString *)fileName {
    [NSKeyedArchiver archiveRootObject:self.viewController.arrayModel
                                toFile:[NSFileManager pathToFileInDocumentsWithName:[kKSSaveStateName copy]]];
}

@end
