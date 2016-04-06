//
//  TestKSCarWasher.m
//  KSIdapStudy
//
//  Created by KulikovS on 03.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <XCTest/XCTest.h>

#import "KSEnterprise.h"

@interface TestKSCarWasher : XCTestCase

@end

@implementation TestKSCarWasher

- (void)setUp {
    NSArray *arrayCars = [KSCar objectsWithCount:20];
    KSEnterprise *enterprise = [KSEnterprise object];
    
    for (NSUInteger index = 0; index < arrayCars.count; index ++) {
        [enterprise washCar:arrayCars[index]];
    }
    [super setUp];

}

- (void)tearDown {

    [super tearDown];
}

- (void)testExample {

}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
