//
//  KSLabelView.m
//  KSIdapStudy
//
//  Created by KulikovS on 26.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSLabelView.h"

static const CGFloat kKSAnimationDuration = 0.8;

@interface KSLabelView ()
@property (nonatomic, assign) KSLabelLocation squarePosition;

- (KSLabelLocation)nextSquarePosition;
- (CGRect)frameForSquarePosition:(KSLabelLocation)position;

@end

@implementation KSLabelView

#pragma mark -
#pragma mark Accessors

- (void)setSquarePosition:(KSLabelLocation)squarePosition {
    [self setSquarePosition:squarePosition animated:NO];
}

- (void)setSquarePosition:(KSLabelLocation)squarePosition animated:(BOOL)animated {
    if (_squarePosition != squarePosition) {
        [self setSquarePosition:squarePosition animated:animated handler:nil];
    }
}

- (void)setSquarePosition:(KSLabelLocation)squarePosition
                 animated:(BOOL)animated
                  handler:(KSLabelHandler)handler
{
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
                         
                         if (self.motionLoopSwitch.on) {
                             [self setSquarePosition:[self nextSquarePosition]
                                            animated:self.animationSwitch.on];
                         }
                     }];
}

#pragma mark -
#pragma mark Private Implementations

- (KSLabelLocation)nextSquarePosition {
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
    CGSize subViewSize = self.subView.frame.size;
    CGSize labelSize = self.label.frame.size;

    CGFloat pointX = 0;
    CGFloat pointY = 0;
    
    CGFloat pointWidht  = subViewSize.width - labelSize.width;
    CGFloat pointHeight = subViewSize.height - labelSize.height;
    
    switch (position) {
        case kKSLabelUpperLeftLocation:
            return CGRectMakeWithSize(pointX, pointY, labelSize);
            
        case kKSLabelUpperRightLocation:
            return CGRectMakeWithSize(pointWidht, pointY, labelSize);
            
        case kKSLabelLowerRightLocation:
            return CGRectMakeWithSize(pointWidht, pointHeight, labelSize);
            
        default:
            return CGRectMakeWithSize(pointX, pointHeight, labelSize);
    }
}

#pragma mark -
#pragma mark Public Implementations

- (void)moveLabel {
    [self setSquarePosition:[self nextSquarePosition]];
}

@end
