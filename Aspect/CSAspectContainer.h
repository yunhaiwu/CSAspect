//
//  CSAspectContainer.h
//  CocoaService-Framework
//
//  Created by 吴云海
//  Copyright © 2018年 yunhai.wu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSAspect.h"
#import "CSAspectContext.h"
#import "CSAspectDefine.h"
#import "CSAspectServiceProxy.h"
#import "CSApplicationComponent.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSAspectContainer : NSObject<CSApplicationComponent>

- (void)registerAspect:(id<CSAspectDefine>)aspectRegisterDefine;

- (void)batchRegisterAspects:(NSSet<id<CSAspectDefine>>*)aspectRegisterDefineSet;

- (id)getServiceProxy:(id)service;

@end

NS_ASSUME_NONNULL_END
