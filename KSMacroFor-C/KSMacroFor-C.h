//
//  KSPrintOutputType.h
//  KSMacrosPrintOutputType
//
//  Created by KulikovS on 25.12.15.
//  Copyright © 2015 KulikovS. All rights reserved.
//


#ifndef KSOutputType_h
#define KSOutputType_h

//Objective C

#define KSWeakifySelf \
    __weak id weakSelf = self

#define KSStrongifySelfAndReturnIfNil \
    __strong id strongSelf = weakSelf; \
        if (!strongSelf) { \
            return; \
    }

#define KSRootViewAndReturnNilMacro(theClass) \
- (theClass *)rootView { \
if ([self isViewLoaded] && [self.view isKindOfClass:[theClass class]]) { \
return (theClass *)self.view; \
} \
return nil; \
}


// C

#define KSPrintSizeType(type) \
    printf("Size type "#type" = %lu\n", sizeof(type));

#define KSOutputValue(qualifier, value) \
    printf("This is "#qualifier"\n", value);

#define KSOutputType(type, qualifier) \
    void KSOutput_##type(type value) {\
       KSOutputValue(qualifier, value);\
    }

#define KSOutputTypeMacro(type, value) \
    KSOutput_##type(value)

#define KSReturnMacro(value) \
    if (NULL == value) {\
        return;\
    }

#define KSReturnNullMacro(value, returnValue) \
                        if (NULL == value) {\
                        return returnValue;\
                       }

#define KSRetainSetter(oldValue, newValue) \
            if (oldValue != newValue) {\
                KSObjectRetain(newValue);\
                KSObjectRelease(oldValue); \
                oldValue = newValue;\
            }

#define KSAssignMacro(oldValue, newValue) \
            if (oldValue != newValue) {\
                oldValue = newValue; \
            }

#endif /* KSOutputType_h */
