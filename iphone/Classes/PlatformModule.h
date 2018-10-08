/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-Present by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
#ifdef USE_TI_PLATFORM

#import <JavaScriptCore/JavaScriptCore.h>
#import <TitaniumKit/ObjcProxy.h>

@class TiPlatformDisplayCaps; // forward declare

@protocol TiPlatformExports <JSExport>

@property (readonly) NSNumber *BATTERY_STATE_CHARGING;
@property (readonly) NSNumber *BATTERY_STATE_FULL;
@property (readonly) NSNumber *BATTERY_STATE_UNKNOWN;
@property (readonly) NSNumber *BATTERY_STATE_UNPLUGGED;

@property (readonly) NSString *address;
@property (readonly) NSString *architecture;
@property (readonly) NSNumber *availableMemory;
@property (readonly) NSNumber *batteryLevel;
@property NSNumber *batteryMonitoring;
@property (readonly) NSNumber *batteryState;
@property (readonly) TiPlatformDisplayCaps *displayCaps;
@property (readonly) TiPlatformDisplayCaps *DisplayCaps;
@property (readonly) NSString *id;
@property (readonly) NSString *identifierForAdvertising;
@property (readonly) NSString *identifierForVendor;
@property (readonly) BOOL isAdvertisingTrackingEnabled;
@property (readonly) NSString *locale;
@property (readonly) NSString *macaddress;
@property (readonly) NSString *manufacturer;
@property (readonly) NSString *model;
@property (readonly) NSString *name;
@property (readonly) NSString *netmask;
@property (readonly) NSString *osname;
@property (readonly) NSString *ostype;
@property (readonly) NSNumber *processorCount;
@property (readonly) NSString *runtime;
@property (readonly) NSString *username;
@property (readonly) NSString *version;

// TODO Add accessor methods for the properties!

- (BOOL)canOpenURL:(NSString *)url;
- (NSString *)createUUID;
- (BOOL)is24HourTimeFormat;

JSExportAs(openURL,
           -(BOOL)openURL
           : (NSString *)url withOptions
           : (id)options andCallback
           : (JSValue *)callback);

@end

@interface PlatformModule : ObjcProxy <TiPlatformExports> {
  BOOL batteryEnabled;
}
@end

#endif
