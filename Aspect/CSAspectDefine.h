//
//  CSAspectDefine.h
//  CocoaService-Framework
//
//  Created by 吴云海
//  Copyright © 2018年 yunhai.wu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSAspect.h"

NS_ASSUME_NONNULL_BEGIN

/*
 CSAspect 定义
 */
@protocol CSAspectDefine <NSObject>

/*
 切面id
 */
- (NSString*)aspectId;

/*
 所属模块
 */
- (NSString*)belongModuleId;

/*
 切面类
 */
- (Class)aspectClass;

@end

NS_ASSUME_NONNULL_END
