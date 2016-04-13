//
//  KSDispatcher.m
//  KSIdapStudy
//
//  Created by KulikovS on 06.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSDispatcher.h"
#import "KSEmployee.h"
#import "KSQueue.h"

@interface KSDispatcher ()
@property (nonatomic, retain) NSMutableArray    *staff;
@property (nonatomic, retain) KSQueue           *queue;

- (KSEmployee *)vacantEmployee;
- (void)dismissStaff;
- (void)dismissEmployee;

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

- (instancetype)initWithStaff:(NSArray *)staff {
    self = [super init];
    if (self) {
        self.staff = [[staff mutableCopy] autorelease];
        self.queue = [KSQueue object];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (void)setStaff:(NSMutableArray *)staff {
    if (_staff != staff) {
        _staff = staff;
        
        [self.staff makeObjectsPerformSelector:@selector(addObserver:) withObject:self];
    }
}

#pragma mark -
#pragma mark Public Methods

- (BOOL)containsObject:(id)object {
    return [self.staff containsObject:object];
}

- (void)addObject:(id)object {
    @synchronized(self) {
        if (object) {
            [self.queue pushObject:object];
            KSEmployee *employee =  [self vacantEmployee];
            
            if (employee) {
                [employee performWorkWithObject:[self.queue popObject]];
            }
        }
    }
}

#pragma mark -
#pragma mark Worker Protocol
    
- (void)workerFinishedWork:(id)object {
    @synchronized(self) {
   //     [self addObject:[self.queue popObject]];
        
        id objectFromQueue = [self.queue popObject];
        if (objectFromQueue) {
            [object performWorkWithObject:objectFromQueue];
        }
    }
}

#pragma mark -
#pragma mark Private Methods

- (KSEmployee *)vacantEmployee {
    @synchronized(self) {
        for (KSEmployee *employee in self.staff) {
            if (employee.state == kKSWorkerStateFree) {
                
                return employee;
            }
        }
    }
    
    return nil;
}



@end
