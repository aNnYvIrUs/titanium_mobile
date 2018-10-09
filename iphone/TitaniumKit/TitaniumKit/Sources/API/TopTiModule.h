/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-Present by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
#import "ObjcProxy.h"
#import <JavaScriptCore/JavaScriptCore.h>

@protocol TiExports <JSExport>

@property (readonly) NSString *buildDate;
@property (readonly) NSString *buildHash;
@property NSString *userAgent;
@property (readonly) NSString *version;

- (JSValue *)createBuffer:(NSDictionary *)arg;

// Accessors from JS. This is pretty redundant, Maybe introduce macros for this common case?
// (i.e. readonly properties also generate getter methods, readwrite generator getter/setters)
- (NSString *)getBuildDate __attribute((deprecated("Use the property instead.")));
- (NSString *)getBuildHash __attribute((deprecated("Use the property instead.")));
- (NSString *)getUserAgent __attribute((deprecated("Use the property instead.")));
- (void)setUserAgent:(NSString *)value __attribute((deprecated("Use the property instead.")));
- (NSString *)getVersion __attribute((deprecated("Use the property instead.")));

@end

@interface TopTiModule : ObjcProxy <TiExports>
@end
