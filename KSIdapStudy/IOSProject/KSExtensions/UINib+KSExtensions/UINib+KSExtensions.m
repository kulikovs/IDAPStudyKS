//
//  UINib+KSExtensions.m
//  KSIdapStudy
//
//  Created by KulikovS on 09.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "UINib+KSExtensions.h"

@implementation UINib (KSExtensions)

+ (id)cellFroNibWithClass:(Class)theClass {
    UINib *nib = [UINib nibWithNibName:NSStringFromClass(theClass)
                                bundle:[NSBundle mainBundle]];
    
    NSArray *array = [nib instantiateWithOwner:self options:nil];
    for (id cell in array) {
        if ([cell isMemberOfClass:[theClass class]]) {
            return cell;
        }
    }
    
    return nil;
}

@end
