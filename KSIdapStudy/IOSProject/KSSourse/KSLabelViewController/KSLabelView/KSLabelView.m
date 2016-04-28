//
//  KSLabelView.m
//  KSIdapStudy
//
//  Created by KulikovS on 26.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSLabelView.h"

static const CGFloat kKSAnimationDuration = 2;

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
                         
                         _squarePosition = squarePosition;
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
    CGFloat subViewHeight = self.subView.frame.size.height;
    CGFloat subViewWidht = self.subView.frame.size.width;
    CGFloat labelWidth = self.label.frame.size.width;
    CGFloat labelHeight = self.label.frame.size.height;
    
    switch (position) {
        case kKSLabelUpperLeftLocation:
            return CGRectMake(0, 0, labelWidth, labelHeight);
            
        case kKSLabelUpperRightLocation:
            return CGRectMake(subViewWidht - labelWidth, subViewHeight-subViewHeight, labelWidth, labelHeight);
            
        case kKSLabelLowerRightLocation:
            return CGRectMake(subViewWidht - labelWidth, subViewHeight - labelWidth, labelWidth, labelHeight);
            
        default:
            return CGRectMake(0, subViewWidht - labelWidth, labelWidth, labelHeight);
    }
}

#pragma mark -
#pragma mark Public Implementations

- (void)moveLabelWithAnimated:(BOOL)animated {
    [self setSquarePosition:[self nextSquarePosition:self.squarePosition] animated:animated];
}

@end
