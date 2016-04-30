//
//  KSLabelView.h
//  KSIdapStudy
//
//  Created by KulikovS on 26.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum KSLabelLocation : NSUInteger {
    kKSLabelUpperLeftLocation,
    kKSLabelUpperRightLocation,
    kKSLabelLowerLeftLocation,
    kKSLabelLowerRightLocation
} KSLabelLocation;

typedef void (^KSLabelHandler)(void);

@interface KSLabelView : UIView
@property (nonatomic, strong) IBOutlet UIView   *subView;
@property (nonatomic, strong) IBOutlet UILabel  *label;

@property (nonatomic, strong) IBOutlet UISwitch *animationSwitch;
@property (nonatomic, strong) IBOutlet UISwitch *motionLoopSwitch;

- (void)setSquarePosition:(KSLabelLocation)squarePosition animated:(BOOL)animated;
- (void)setSquarePosition:(KSLabelLocation)squarePosition
                 animated:(BOOL)animated
                  handler:(KSLabelHandler)handler;

- (void)moveLabel;

@end
