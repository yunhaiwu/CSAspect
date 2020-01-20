//
//  CSSimpleAspectJoinPoint.m
//  CocoaService-Framework
//
//  Created by 吴云海
//  Copyright © 2018年 yunhai.wu. All rights reserved.
//

#import "CSSimpleAspectJoinPoint.h"

@interface CSSimpleAspectJoinPoint ()

@property (nonatomic, strong, readonly) NSInvocation *invocation;

@property (atomic, assign) BOOL performed;

@end

@implementation CSSimpleAspectJoinPoint

- (instancetype)initWithInvocation:(NSInvocation *)invocation {
    self = [super init];
    if (self) {
        _invocation = invocation;
    }
    return self;
}

#pragma mark CSAspectJoinPoint
- (SEL)aopSelector {
    return [_invocation selector];
}

- (id)aopTarget {
    return [_invocation target];
}

- (NSUInteger)numberOfArguments {
    return [[_invocation methodSignature] numberOfArguments];
}

- (void)getArgument:(void *)argumentLocation atIndex:(NSInteger)idx {
    [_invocation getArgument:argumentLocation atIndex:idx + 2];
}

- (void)setArgument:(void *)argumentLocation atIndex:(NSInteger)idx {
    [_invocation setArgument:argumentLocation atIndex:idx + 2];
}

- (BOOL)isPerformed {
    return _performed;
}

- (void)proceed {
    if (!_performed) {
        _performed = YES;
        [_invocation invoke];
    }
}

@end
