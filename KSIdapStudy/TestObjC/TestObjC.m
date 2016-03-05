//
//  TestObjC.m
//  TestObjC
//
//  Created by KulikovS on 28.02.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "NSString+KSExtension.h"
#import "KSAlphabet.h"

@interface TestObjC : XCTestCase
@property (nonatomic, retain) KSAlphabet *alphabet;
@property (nonatomic, retain) NSString *string;

@end

@implementation TestObjC

- (void)setUp {
    [super setUp];

}

- (void)tearDown {
    [super tearDown];
}

- (void)testAlphabetsRange {
    NSLog(@"Alphabet is with capital letters. The first letter of alphabet is 'A' and the last is 'Z'");
    self.alphabet = [KSAlphabet upperCaseLettersAlphabet];
    NSLog(@"%@", self.alphabet.alphabetString);
    XCTAssert(self.alphabet.count == 26);
    
    NSLog(@"Alphabet is with small letters. The first letter of alphabet is 'a' and the last is 'z'");
    self.alphabet = [KSAlphabet lowerCaseLettersAlphabet];
    NSLog(@"%@", self.alphabet.alphabetString);
    XCTAssert(self.alphabet.count == 26);
    
    NSLog(@"Alphabet is with numeric letters. The first symbol of alphabet is '0' and the last is '9'");
    self.alphabet = [KSAlphabet numericLettersAlphabet];
    NSLog(@"%@", self.alphabet.alphabetString);
    XCTAssert(self.alphabet.count == 10);
}

- (void)testAlphabetString {
    NSLog(@"Alphabet is with String. The first letter of alphabet is 'A' and the last is 'H'");
    self.alphabet = [KSAlphabet alphabetWithString:@"ABCDEFGH"];
    NSLog(@"%@", self.alphabet.alphabetString);
    XCTAssert(self.alphabet.count == 8);
}

- (void)testAlphabetsArray {
    NSLog(@"RandomString with alphabets.");
    KSAlphabet *lowerCaseAlphabet = [KSAlphabet lowerCaseLettersAlphabet];
    KSAlphabet *upperCaseAlphabet = [KSAlphabet upperCaseLettersAlphabet];
    NSArray *strings = [NSArray arrayWithObjects:lowerCaseAlphabet, upperCaseAlphabet, nil];
    self.alphabet = [KSAlphabet alphabetWithAlphabetsArray:strings];
    NSLog(@"%@", self.alphabet.alphabetString);
    XCTAssert(self.alphabet.count == 52);
}

- (void)testRandomString {
    NSLog(@"RandomString with default alphabet (lowerCaseLettersAlphabet).\n String lenght is 15");
    self.string = [NSString randomStringWithLength:15];
    NSLog(@"%@", self.string);
    XCTAssert(self.string.length == 15);
    
    NSLog(@"RandomString with alphabet.\n String lenght is default");
    self.alphabet = [KSAlphabet alphabetWithString:@"ABCDEFGH"];
    self.string = [NSString randomStringWithAlphabet:self.alphabet];
    NSLog(@"%@", self.string);
    XCTAssert(self.string.length == 10);
}

@end
