/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-Present by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
#ifdef USE_TI_GESTURE
#import <JavaScriptCore/JavaScriptCore.h>
#import <TitaniumKit/ObjcProxy.h>

@protocol GestureExports <JSExport>

@property (readonly) BOOL landscape;
@property (readonly) NSNumber *orientation;
@property (readonly) BOOL portrait;

// TODO These are deprecated, remove in SDK 9.0.0
// accessors
- (BOOL)getLandscape __attribute((deprecated("Use the property instead.")));
- (NSNumber *)getOrientation __attribute((deprecated("Use the property instead.")));
- (BOOL)getPortrait __attribute((deprecated("Use the property instead.")));

// methods
// TODO: Add isFaceDown() and isFaceUp()?
// - (BOOL)isFaceDown;
// - (BOOL)isFaceUp;

@end

@interface GestureModule : ObjcProxy <GestureExports> {
  NSTimeInterval lastShakeTime;
}

@end

#endif
