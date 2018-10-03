/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-Present by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
#ifdef USE_TI_PLATFORM

#import "TiPlatformDisplayCaps.h"
#import <TitaniumKit/TiUtils.h>

@implementation TiPlatformDisplayCaps

// NOTE: device capabilities currently are hardcoded for iPad, while high/low
// display density is now detected for iPhone / iPod Touch under iOS 4.

- (id)density
{
  if ([TiUtils is3xRetina]) {
    return @"xhigh";
  }
  if ([TiUtils is2xRetina]) {
    return @"high";
  }
  return @"medium";
}

- (NSNumber *)getDensity
{
  return [self density];
}

- (NSString *)apiName
{
  return @"Ti.Platform.DisplayCaps";
}

- (NSNumber *)dpi
{
  return [NSNumber numberWithInt:[TiUtils dpi]];
}

- (NSNumber *)getDpi
{
  return [self dpi];
}

// TODO Remove? Not in our docs!
- (BOOL)isDevicePortrait
{
  UIDeviceOrientation orientation = [UIDevice currentDevice].orientation;
  return (orientation == UIDeviceOrientationPortrait || orientation == UIDeviceOrientationPortraitUpsideDown || orientation == UIDeviceOrientationUnknown);
}

// TODO Remove? Not in our docs!
- (BOOL)isUIPortrait
{
  UIInterfaceOrientation orientation = [[UIApplication sharedApplication] statusBarOrientation];
  return UIInterfaceOrientationIsPortrait(orientation);
}

- (NSNumber *)platformWidth
{
  CGRect mainScreenBounds = [[UIScreen mainScreen] bounds];
  return [NSNumber numberWithFloat:mainScreenBounds.size.width];
}

- (NSNumber *)getPlatformWidth
{
  return [self platformWidth];
}

- (NSNumber *)platformHeight
{
  CGRect mainScreenBounds = [[UIScreen mainScreen] bounds];
  return [NSNumber numberWithFloat:mainScreenBounds.size.height];
}

- (NSNumber *)getPlatformHeight
{
  return [self platformHeight];
}

- (NSNumber *)logicalDensityFactor
{
  return [NSNumber numberWithFloat:[[UIScreen mainScreen] scale]];
}

- (NSNumber *)getLogicalDensityFactor
{
  return [self logicalDensityFactor];
}
@end

#endif
