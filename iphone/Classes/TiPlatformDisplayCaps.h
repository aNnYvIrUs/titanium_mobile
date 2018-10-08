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

@property (readonly) NSString *density;
@property (readonly) NSNumber *dpi;
@property (readonly) NSNumber *logicalDensityFactor;
@property (readonly) NSNumber *platformHeight;
@property (readonly) NSNumber *platformWidth;
// TODO xdpi
// TODO ydpi

// TODO: deprecated getters, remove in SDK 9.0.0!
- (NSString *)getDensity __attribute((deprecated("Use the property instead.")));
;
- (NSNumber *)getDpi __attribute((deprecated("Use the property instead.")));
;
- (NSNumber *)getLogicalDensityFactor __attribute((deprecated("Use the property instead.")));
;
- (NSNumber *)getPlatformHeight __attribute((deprecated("Use the property instead.")));
;
- (NSNumber *)getPlatformWidth __attribute((deprecated("Use the property instead.")));
;

@end

@interface TiPlatformDisplayCaps : ObjcProxy <TiPlatformDisplayCapsExports>
@end

#endif
