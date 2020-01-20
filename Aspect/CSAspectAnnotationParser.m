//
//  CSAspectAnnotationParser.m
//  CocoaService-framework
//
//  Created by 吴云海 on 2018/10/14.
//  Copyright © 2018 吴云海. All rights reserved.
//

#import "CSAspectAnnotationParser.h"
#import "CSAspectDefine.h"
#import "CSLoggingHeader.h"


@interface CSAspectAnnotationDefine : NSObject<CSAnnotationDefine, CSAspectDefine>

@property (nonatomic, assign) Class aspectClass;

@end

@implementation CSAspectAnnotationDefine

- (BOOL)isEqual:(id)object {
    if ([object conformsToProtocol:@protocol(CSAspectDefine)]) {
        if ([self aspectClass] == [object aspectClass]) {
            return YES;
        }
    }
    return NO;
}

- (NSUInteger)hash {
    return [[self aspectClass] hash];
}

- (instancetype)initWithAspectClass:(Class<CSAspect>)aspectClass {
    self = [super init];
    if (self) {
        _aspectClass = aspectClass;
    }
    return self;
}

+ (CSAspectAnnotationDefine *)buildDefine:(NSString *)defineExpression {
    CSAspectAnnotationDefine *define = nil;
    if (defineExpression) {
        Class clazz = NSClassFromString(defineExpression);
        if ([clazz conformsToProtocol:@protocol(CSAspect)]) {
            define = [[CSAspectAnnotationDefine alloc] initWithAspectClass:clazz];
        } else {
            CSLogError(@"[✗] aspect build fail, class '%@' not implementation 'CSAspect' protocol", NSStringFromClass(clazz));
        }
    }
    return define;
}

#pragma mark CSAnnotationDefine
- (Class)defineClass {
    return _aspectClass;
}

#pragma mark CSAspectDefine
- (NSString*)aspectId {
    return [_aspectClass uniqueId];
}

- (NSString*)belongModuleId {
    return [_aspectClass belongModuleId];
}

- (Class)aspectClass {
    return _aspectClass;
}

@end


@implementation CSAspectAnnotationParser

#pragma mark CSAnnotationParser
+ (id<CSAnnotationDefine>)parsing:(NSString *)defineExpression {
    return [CSAspectAnnotationDefine buildDefine:defineExpression];
}

@end
