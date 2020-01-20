//
//  CSAspectContext.h
//  CocoaService-Framework
//
//  Created by 吴云海
//  Copyright © 2018年 yunhai.wu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSAspect.h"
#import "CSAspectDefine.h"

NS_ASSUME_NONNULL_BEGIN
/*
 切面包装类
 */
@interface CSAspectContext : NSObject

/*
 切面点选项
 */
@property (nonatomic, assign, readonly) CSAopAspectActionOption options;

/*
 切面对象
 */
- (id<CSAspect>)aspectObject;


/*
 所属模块id
 */
- (NSString*)belongModuleId;

/*
 切面id
 */
- (NSString*)aspectId;

/*
 切入类名列表
 */
- (NSSet<NSString*>* _Nullable)pointcutClassNames;

/*
 切入方法列表
 */
- (NSSet<NSString*>*)pointcutMethods:(NSString*)className;

/*
 构建Context方法
 */
+ (instancetype _Nullable)buildContext:(id<CSAspectDefine>)aspectRegisterDefine;

@end

NS_ASSUME_NONNULL_END
