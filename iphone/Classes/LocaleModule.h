/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-Present by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
#import <JavaScriptCore/JavaScriptCore.h>
#import <TitaniumKit/ObjcProxy.h>

@protocol LocaleExports <JSExport>

@property (readonly) NSString *currentCountry;
@property (readonly) NSString *currentLanguage;
@property (readonly) NSString *currentLocale;

// TODO These are deprecated, remove in SDK 9.0.0
// accessors
- (NSString *)getCurrentCountry __attribute((deprecated("Use the property instead.")));
- (NSString *)getCurrentLanguage __attribute((deprecated("Use the property instead.")));
- (NSString *)getCurrentLocale __attribute((deprecated("Use the property instead.")));

// methods
- (NSString *)getCurrencyCode:(NSString *)locale;
- (NSString *)getCurrencySymbol:(NSString *)currencyCode;
- (NSString *)getLocaleCurrencySymbol:(NSString *)locale;
JSExportAs(getString,
           -(NSString *)getString
           : (NSString *)key withHint
           : (id)hint);
- (void)setLanguage:(NSString *)language;

@end

@interface LocaleModule : ObjcProxy <LocaleExports>

@end
