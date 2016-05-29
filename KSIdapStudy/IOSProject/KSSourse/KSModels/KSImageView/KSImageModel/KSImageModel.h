//
//  KSImageModel.h
//  KSIdapStudy
//
//  Created by KulikovS on 26.05.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//

#import "KSModel.h"

@interface KSImageModel : KSModel
@property (nonatomic, copy)     NSString    *URL;
@property (nonatomic, strong)   UIImage     *imageInModel;

@end


