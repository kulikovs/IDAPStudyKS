//
//  KSUserTableViewController.m
//  KSIdapStudy
//
//  Created by KulikovS on 03.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSUserTableViewController.h"
#import "KSTableView.h"

static const NSUInteger kKSRandomStringCount = 40;

@interface KSUserTableViewController ()
@property (nonatomic, readonly) KSTableView     *rootView;
@property (nonatomic, strong)   NSMutableArray  *stringArray;

- (NSArray *)randomStringsWithCount:(NSUInteger)count;

@end

@implementation KSUserTableViewController

#pragma mark -
#pragma mark Accessors

KSRootViewAndReturnNilMacro(KSTableView);

#pragma mark -
#pragma mark Private Methods

- (NSArray *)randomStringsWithCount:(NSUInteger)count {
    NSMutableArray *mutableArray = [NSMutableArray array];
    
    for (NSUInteger index = 0; index < count; index++) {
        [mutableArray addObject:[NSString randomString]];
    }
    
    return [mutableArray copy];
}

#pragma mark -
#pragma mark Life cycle

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.rootView.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"RandomString"];
    
    self.stringArray = [NSMutableArray arrayWithArray:[self randomStringsWithCount:kKSRandomStringCount]];
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
    
    if (indexPath.row < self.stringArray.count) {
        cell.textLabel.text = self.stringArray[indexPath.row];
    }
    
    return cell;
}

@end
