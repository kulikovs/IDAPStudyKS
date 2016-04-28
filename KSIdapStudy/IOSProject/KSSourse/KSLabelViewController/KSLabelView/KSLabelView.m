//
//  KSLabelView.m
//  KSIdapStudy
//
//  Created by KulikovS on 26.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSLabelView.h"

static const CGFloat kKSAnimationDuration = 0.8;

typedef void (^KSLabelHandler)(void);

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
        [self setSquarePosition:squarePosition animated:self.animationSwitch.on ? YES : NO
                        handler:nil];
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
                         
                         if (self.motionLoopSwitch.on) {
                             [self setSquarePosition:[self nextSquarePosition:self.squarePosition]
                                            animated:animated];
                         }
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
    CGFloat subViewHeight   = self.subView.frame.size.height;
    CGFloat subViewWidht    = self.subView.frame.size.width;
    CGFloat labelWidth      = self.label.frame.size.width;
    CGFloat labelHeight     = self.label.frame.size.height;
    
    CGFloat pointX = 0;
    CGFloat pointY = 0;
    
    CGFloat pointWidht  = subViewWidht - labelWidth;
    CGFloat pointHeight = subViewHeight - labelHeight;
    
    switch (position) {
        case kKSLabelUpperLeftLocation:
            return CGRectMake(pointX, pointY, labelWidth, labelHeight);
            
        case kKSLabelUpperRightLocation:
            return CGRectMake(pointWidht, pointY, labelWidth, labelHeight);
            
        case kKSLabelLowerRightLocation:
            return CGRectMake(pointWidht, pointHeight, labelWidth, labelHeight);
            
        default:
            return CGRectMake(pointX, pointHeight, labelWidth, labelHeight);
    }
}

#pragma mark -
#pragma mark Public Implementations

- (void)moveLabelWithAnimated:(BOOL)animated {
    [self setSquarePosition:[self nextSquarePosition:self.squarePosition] animated:animated];
}

- (void)changeNameForAnimationSwitch {

}

- (void)changeNameForLoopSwitch {

}

@end
