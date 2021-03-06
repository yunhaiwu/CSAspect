//
//  CSAspect.h
//  CocoaService-Framework
//
//  Created by 吴云海
//  Copyright © 2018年 yunhai.wu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSAspectJoinPoint.h"

NS_ASSUME_NONNULL_BEGIN
/*
 切面点选项
 */
typedef NS_OPTIONS(NSUInteger, CSAopAspectActionOption) {
    
    CSAopAspectActionOptionNone                 = 0,
    
    //方法执行前
    CSAopAspectActionOptionBefore               = 1,
    
    //方法执行后
    CSAopAspectActionOptionAfter                = 1 << 1,
    
    //方法执行前后
    CSAopAspectActionOptionAround               = 1 << 2
};

/*
 aop切面
 注意：1、所有的aspect是创建成功后是单利
      2、所有aspect 最好继承AbstractAspect
 */
@protocol CSAspect <NSObject>

/*
 切入表达式
 单表达式格式：    类名(方法名)
 例：
    User(login:)    表示调用User类login方法拦截
    *(*)            表示调用如何类中任何方法都会被拦截
    User(*)         标识拦截User类所有方法
    *(login:)       拦截所有login:方法
 
 多表达式格式:
        User(login:);User(logout:)  表示拦截User类 login:、logout: 方法
 */
+ (NSString*)pointcutExpressions;

@optional

/*
 调用之前方法
 */
- (void)doBefore:(id<CSAspectJoinPoint>)joinPoint;

/*
 调用之后方法
 */
- (void)doAfter:(id<CSAspectJoinPoint>)joinPoint;

/*
 环绕方法
 实现此方法需要在方法中调用 proceed 继续执行
 */
- (void)doAround:(id<CSAspectProceedingJoinPoint>)joinPoint;

/*
 切面id
 default：Class Name
 */
+ (NSString*)uniqueId;

/*
 所属模块id
 如果不实现则属于全局通用模块
 */
+ (NSString*)belongModuleId;

@end

NS_ASSUME_NONNULL_END
