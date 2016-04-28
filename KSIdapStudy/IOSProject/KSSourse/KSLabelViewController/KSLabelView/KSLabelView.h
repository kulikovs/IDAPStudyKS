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

@interface KSLabelView : UIView
@property (nonatomic, strong) IBOutlet UIView   *subView;
@property (nonatomic, strong) IBOutlet UILabel  *label;

@property (nonatomic, strong) IBOutlet UISwitch *animationSwitch;
@property (nonatomic, strong) IBOutlet UISwitch *motionLoopSwitch;
@property (nonatomic, strong) IBOutlet UILabel  *motionLoopLabel;
@property (nonatomic, strong) IBOutlet UILabel  *animationLabel;

- (void)moveLabelWithAnimated:(BOOL)animated;
- (void)changeNameForAnimationSwitch;
- (void)changeNameForLoopSwitch;

@end
