//
//  KSPrintOutputType.h
//  KSMacrosPrintOutputType
//
//  Created by KulikovS on 25.12.15.
//  Copyright © 2015 KulikovS. All rights reserved.
//


#ifndef KSOutputType_h
#define KSOutputType_h

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

#define KSReturnNullMacro(value) \
    if (NULL == value) {\
        return 0;\
    }

//#define KSRetainSetter(oldValue, newValue) \
//            if (oldValue != newValue) {\
//                KSHumanRelease(oldValue); \
//                oldValue = newValue; \
//                KSHumanRetain(newValue); \
//            }

#define KSRetainSetter(oldValue, newValue) \
            if (oldValue != newValue) {\
                KSObjectRelease(oldValue); \
                oldValue = KSObjectRetain(newValue); \
}

#define KSAssignMacro(oldValue, newValue) \
            if (oldValue != newValue) {\
                oldValue = newValue; \
            }

#define KSObjectCreateMacro(type) \
            KSObjectCreate(sizeof(type), (void*) __##type##Deallocate)

#endif /* KSOutputType_h */
