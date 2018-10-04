/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-Present by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
#ifdef USE_TI_PLATFORM

#import <JavaScriptCore/JavaScriptCore.h>
#import <TitaniumKit/ObjcProxy.h>

@protocol TiPlatformDisplayCapsExports <JSExport>

@property (nonatomic, readonly) NSString *density;
@property (nonatomic, readonly) NSNumber *dpi;
@property (nonatomic, readonly) NSNumber *logicalDensityFactor;
@property (nonatomic, readonly) NSNumber *platformHeight;
@property (nonatomic, readonly) NSNumber *platformWidth;
// TODO xdpi
// TODO ydpi

// TODO: deprecated getters, remove in SDK 9.0.0!
- (NSString *)getDensity;
- (NSNumber *)getDpi;
- (NSNumber *)getLogicalDensityFactor;
- (NSNumber *)getPlatformHeight;
- (NSNumber *)getPlatformWidth;

@end

@interface TiPlatformDisplayCaps : ObjcProxy <TiPlatformDisplayCapsExports>
@end

#endif
