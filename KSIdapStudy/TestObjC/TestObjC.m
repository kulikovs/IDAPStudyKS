//
//  TestObjC.m
//  TestObjC
//
//  Created by KulikovS on 28.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "NSString+KSExtension.h"

@interface TestObjC : XCTestCase

@end

@implementation TestObjC

- (void)setUp {
    [super setUp];

}

- (void)tearDown {

    [super tearDown];
}

- (void)testExample {
    
    NSString *upperCaseAlphabet = [NSString upperCaseAlphabet];
    NSString *lowerCaseAlphabet = [NSString lowerCaseAlphabet];
    NSString *numericAlphabet = [NSString numericLettersAlphabet];
    NSString *lowerCaseWithNumericAlphabet = [NSString lowerCaseWithNumericAlphabet];
    NSString *lowerCaseWithUpperCaseAlphabet = [NSString lowerCaseWithUpperCaseAlphabet];
    
    XCTAssert(upperCaseAlphabet.length == 26);
    XCTAssert(lowerCaseAlphabet.length == 26);
    XCTAssert(numericAlphabet.length == 10);
    XCTAssert(lowerCaseWithUpperCaseAlphabet.length == 52);
    XCTAssert(lowerCaseWithNumericAlphabet.length == 36);
    
    NSLog(@"Alphabet is with capital letters. The first letter of alphabet is 'A' and the last is 'Z'");
    NSLog(@"%@", upperCaseAlphabet);
    
    NSLog(@"Alphabet is with small letters. The first letter of alphabet is 'a' and the last is 'z'");
    NSLog(@"%@", lowerCaseAlphabet);
    
    NSLog(@"Alphabet is with numeric letters. The first symbol of alphabet is '0' and the last is '9'");
    NSLog(@"%@", numericAlphabet);
    
    NSLog(@"Alphabet is with numeric letters and lower case letters.");
    NSLog(@"%@", lowerCaseWithNumericAlphabet);
    
    NSLog(@"Alphabet is with lower case and upper case letters.");
    NSLog(@"%@", lowerCaseWithUpperCaseAlphabet);
    
    NSString *randomStringWithLength = [NSString randomStringWithLength:30];
    XCTAssert(randomStringWithLength.length == 30);
    NSLog(@"This is random string created with 30 symbols lowerCase Alphabet");
    NSLog(@"%@", randomStringWithLength);
    
    
    NSString *randomStringDefault = [NSString randomString];
    XCTAssert(randomStringDefault.length == 10);
    NSLog(@"This is random string, created with 10 symbols lowerCase Alphabet");
    NSLog(@"%@", [NSString randomString]);
    
    
    NSString *randomStringWithAlphabet = [NSString randomStringWithLength:20
                                                           alphabet:[NSString numericLettersAlphabet]];
    
    NSLog(@"This is random string, created with 20 symbols numericLetters Alphabet");
    NSLog(@"%@", randomStringWithAlphabet);
    XCTAssert(randomStringWithAlphabet.length == 20);
    
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
}


@end
