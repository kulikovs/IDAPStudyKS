//
//  KSDispatcher.m
//  KSIdapStudy
//
//  Created by KulikovS on 06.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSDispatcher.h"
#import "KSEmployee.h"

@interface KSDispatcher ()
@property (nonatomic, retain) NSMutableArray    *staff;
@property (nonatomic, retain) KSQueue           *queue;

@end


@implementation KSDispatcher

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.staff = nil;
    self.queue = nil;
    
    [super dealloc];
}


- (instancetype)init {
    return [self initWithStaff:nil];
}

- (instancetype)initWithStaff:(KSEmployee *)staff {
    self = [super init];
    if (self) {
        self.staff = [NSMutableArray arrayWithArray:[[staff copy] autorelease]];
        self.queue = [KSQueue object];
    }
    
    return self;
}


#pragma mark -
#pragma mark Public Methods

- (void)addObject:(id)object {

}

- (BOOL)containsObject:(id)object {

}

- (void)performWorkWithObject:(id)object {

}
@end
