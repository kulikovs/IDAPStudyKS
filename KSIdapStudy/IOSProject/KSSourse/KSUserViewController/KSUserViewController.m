//
//  KSUserTableViewController.m
//  KSIdapStudy
//
//  Created by KulikovS on 03.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSUserViewController.h"
#import "KSUserView.h"

@interface KSUserViewController ()
@property (nonatomic, readonly) KSUserView      *rootView;
@property (nonatomic, strong)   NSArray         *stringArray;

@end

@implementation KSUserViewController

#pragma mark -
#pragma mark Accessors

KSRootViewAndReturnNilMacro(KSUserView);

#pragma mark -
#pragma mark Private Methods



#pragma mark -
#pragma mark Life cycle

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.rootView.tabelView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"RandomString"];
    
    self.stringArray = [NSArray arrayWithArray:[NSString randomStringsWithRandomCount]];
}

#pragma mark -
#pragma mark UITableViewDataSource Protocol

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.stringArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSString *cellIdentifire = @"RandomString";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifire];
    
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                      reuseIdentifier:cellIdentifire];
    }
    
    cell.textLabel.text = self.stringArray[indexPath.row];
    
    return cell;
}

@end
