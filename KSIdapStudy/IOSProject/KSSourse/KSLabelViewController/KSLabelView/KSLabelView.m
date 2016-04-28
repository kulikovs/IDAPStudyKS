//
//  KSLabelView.m
//  KSIdapStudy
//
//  Created by KulikovS on 26.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSLabelView.h"

static const CGFloat kKSAnimationDuration = 0.1;

@interface KSLabelView ()
@property (nonatomic, assign) NSUInteger squarePosition;

- (KSLabelLocation)nextSquarePosition:(KSLabelLocation)position;
- (CGRect)frameForSquarePosition:(KSLabelLocation)position;
- (void)setSquarePosition:(NSUInteger)squarePosition animated:(BOOL)animated;
- (void)setSquarePosition:(NSUInteger)squarePosition animated:(BOOL)animated handler:(KSLabelHandler)handler;

@end

@implementation KSLabelView

#pragma mark -
#pragma mark Accessors

- (void)setSquarePosition:(NSUInteger)squarePosition {
    [self setSquarePosition:squarePosition animated:NO];
}


- (void)setSquarePosition:(NSUInteger)squarePosition animated:(BOOL)animated {
    if (_squarePosition != squarePosition) {
        [self setSquarePosition:squarePosition animated:animated handler:nil];
    }
}

- (void)setSquarePosition:(NSUInteger)squarePosition animated:(BOOL)animated handler:(KSLabelHandler)handler {
    [UIView animateWithDuration: animated ? kKSAnimationDuration : 0
                          delay:0
                        options:UIViewAnimationOptionCurveEaseIn
                     animations: ^{
                         self.label.frame = [self frameForSquarePosition:squarePosition];
                     } completion:^(BOOL finished) {
                         if (handler) {
                             handler();
                         }
                         
                         [self setSquarePosition:squarePosition];
                     }];
}

#pragma mark -
#pragma mark Private Implementations

- (KSLabelLocation)nextSquarePosition:(KSLabelLocation)position {
    switch (self.squarePosition) {
        case kKSLabelUpperLeftLocation:
            return kKSLabelUpperRightLocation;
            
        case kKSLabelUpperRightLocation:
            return kKSLabelLowerRightLocation;
            
        case kKSLabelLowerRightLocation:
            return kKSLabelLowerLeftLocation;
            
        default:
            return kKSLabelUpperLeftLocation;
    }
}

- (CGRect)frameForSquarePosition:(KSLabelLocation)position {
    switch (position) {
        case kKSLabelUpperLeftLocation:
            return CGRectMake(0, 100, self.label.frame.size.width, self.label.frame.size.height);
            
        case kKSLabelUpperRightLocation:
            return CGRectMake(100, 200, self.label.frame.size.width, self.label.frame.size.height);;
            
        case kKSLabelLowerRightLocation:
            return CGRectMake(0, 100, self.label.frame.size.width, self.label.frame.size.height);;
            
        default:
            return CGRectMake(0, 100, self.label.frame.size.width, self.label.frame.size.height);;
    }
}

#pragma mark -
#pragma mark Public Implementations

- (void)moveLabelWithAnimated:(BOOL)animated {
    self.squarePosition = [self nextSquarePosition:self.squarePosition];
}

@end
