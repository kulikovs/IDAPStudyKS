//
//  KSLabelView.m
//  KSIdapStudy
//
//  Created by KulikovS on 26.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSLabelView.h"

@interface KSLabelView ()
@property (nonatomic, assign) NSUInteger squarePosition;

- (KSLabelLocation)nextSquarePosition:(KSLabelLocation)position;

@end

@implementation KSLabelView


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

#pragma mark -
#pragma mark Public Implementations

- (void)moveLabelWithAnimated:(BOOL)animated {

}



@end
