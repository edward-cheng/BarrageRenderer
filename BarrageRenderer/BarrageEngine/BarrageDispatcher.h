// Part of BarrageRenderer. Created by UnAsh.
// Blog: http://blog.exbye.com
// Github: https://github.com/unash/BarrageRenderer

// This code is distributed under the terms and conditions of the MIT license.

// Copyright (c) 2015年 UnAsh.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

@class BarrageSprite;
@class BarrageDispatcher;

@protocol BarrageDispatcherDelegate <NSObject>

@optional
/// 是否激活此弹幕精灵.
- (BOOL)shouldActiveSprite:(BarrageSprite *)sprite;
- (NSTimeInterval)timeForBarrageDispatcher:(BarrageDispatcher *)dispatcher;

@required
- (void)willActiveSprite:(BarrageSprite *)sprite;
- (void)willDeactiveSprite:(BarrageSprite *)sprite;

@end

/// 弹幕调度器, 主要完成负载均衡的工作.
@interface BarrageDispatcher : NSObject

/// 添加精灵.
- (void)addSprite:(BarrageSprite *)sprite;

/// 派发精灵.
- (void)dispatchSprites;

/// 是否开启过期精灵缓存功能, 默认关闭, 如需支持后退时重新播放弹幕, 则需置为YES.
@property (nonatomic,assign)BOOL cacheDeadSprites;

/// 当前活跃的精灵.
@property (nonatomic,strong,readonly)NSArray * activeSprites;

/// 停止当前被激活的精灵
- (void)deactiveAllSprites;

/// 删除精灵
- (void)deleteAllSprites:(NSString *)spriteName;

/// 平滑系数, 范围为[0,1],当为0时，无平滑; 否则越大，越平滑;
/// 高平滑值在大量弹幕的时候(一般100+)，可能造成弹幕丢失
@property(nonatomic,assign)CGFloat smoothness;

@property (nonatomic,weak)id<BarrageDispatcherDelegate> delegate;

@end
