//
//  CSSimpleAspectJoinPoint.h
//  CocoaService-Framework
//
//  Created by 吴云海
//  Copyright © 2018年 yunhai.wu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSAspectJoinPoint.h"

NS_ASSUME_NONNULL_BEGIN

/*
 连接点
 */
@interface CSSimpleAspectJoinPoint : NSObject<CSAspectProceedingJoinPoint>

- (instancetype)initWithInvocation:(NSInvocation*)invocation;

@end

NS_ASSUME_NONNULL_END
