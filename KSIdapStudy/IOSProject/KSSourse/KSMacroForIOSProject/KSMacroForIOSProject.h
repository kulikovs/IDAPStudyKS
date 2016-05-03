//
//  KSMacroForIOSProject.h
//  KSIdapStudy
//
//  Created by KulikovS on 26.04.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#ifndef KSMacroForIOSProject_h
#define KSMacroForIOSProject_h

#define KSRootViewAndReturnNilMacro(theClass) \
    - (theClass *)rootView { \
        if ([self isViewLoaded] && [self.view isKindOfClass:[theClass class]]) { \
        return (theClass *)self.view; \
      } \
    return nil; \
}

#define KSSelfButtonEnable(NamePropertyButton) \
self.NamePropertyButton.userInteractionEnabled = YES; \
self.NamePropertyButton.enabled = YES;

#define KSSelfButtonDisable(NamePropertyButton) \
self.NamePropertyButton.userInteractionEnabled = NO; \
self.NamePropertyButton.enabled = NO;

#endif /* KSMacroForIOSProject_h */
