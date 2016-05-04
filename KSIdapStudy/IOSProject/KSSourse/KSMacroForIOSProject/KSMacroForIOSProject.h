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

#endif /* KSMacroForIOSProject_h */
