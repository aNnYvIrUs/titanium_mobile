/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2018-Present by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
#import "ObjcProxy.h"
#import "TiBase.h"

@implementation ObjcProxy

@synthesize bubbleParent;

- (id)init
{
  if (self = [super init]) {
    self.bubbleParent = YES;
    pthread_rwlock_init(&m_listenerLock, NULL);
  }
  return self;
}

- (void)addEventListener:(NSString *)name withCallback:(JSValue *)callback
{
  pthread_rwlock_wrlock(&m_listenerLock);
  @try {
    if (m_listeners == nil) {
      m_listeners = [[NSMutableDictionary alloc] initWithCapacity:3];
    }
    JSManagedValue *managedRef = [JSManagedValue managedValueWithValue:callback];
    [callback.context.virtualMachine addManagedReference:managedRef withOwner:self];
    NSMutableArray *listenersForType = [m_listeners objectForKey:name];
    if (listenersForType == nil) {
      listenersForType = [[NSMutableArray alloc] init];
    }
    [listenersForType addObject:managedRef];
    [m_listeners setObject:listenersForType forKey:name];
  }
  @finally {
    pthread_rwlock_unlock(&m_listenerLock);
  }
}

- (void)removeEventListener:(NSString *)name withCallback:(JSValue *)callback
{
  pthread_rwlock_wrlock(&m_listenerLock);
  @try {
    if (m_listeners == nil) {
      return;
    }
    NSMutableArray *listenersForType = (NSMutableArray *)[m_listeners objectForKey:name];
    if (listenersForType == nil) {
      return;
    }

    unsigned long count = [listenersForType count];
    for (int i = 0; i < count; i++) {
      JSManagedValue *storedCallback = (JSManagedValue *)[listenersForType objectAtIndex:i];
      JSValue *actualCallback = [storedCallback value];
      if ([actualCallback isEqualToObject:callback]) {
        // if the callback matches, remove the listener from our mapping and mark unmanaged
        [actualCallback.context.virtualMachine removeManagedReference:storedCallback withOwner:self];
        [listenersForType removeObjectAtIndex:i];
        [m_listeners setObject:listenersForType forKey:name];
        break;
      }
    }
  }
  @finally {
    pthread_rwlock_unlock(&m_listenerLock);
  }
}

- (void)fireEvent:(NSString *)name withDict:(NSDictionary *)dict
{
  pthread_rwlock_rdlock(&m_listenerLock);
  @try {
    if (m_listeners == nil) {
      return;
    }
    NSArray *listenersForType = [m_listeners objectForKey:name];
    if (listenersForType == nil) {
      return;
    }
    // FIXME: looks like we need to handle bubble logic/etc. See other fireEvent impl
    for (JSManagedValue *storedCallback in listenersForType) {
      JSValue *function = [storedCallback value];
      [function callWithArguments:@[ dict ]];
    }
  }
  @finally {
    pthread_rwlock_unlock(&m_listenerLock);
  }
}

//For subclasses to override
- (NSString *)apiName
{
  DebugLog(@"[ERROR] Subclasses must override the apiName API endpoint.");
  return @"Ti.Proxy";
}

- (void)dealloc
{
  // remove all listeners JS side proxy
  pthread_rwlock_wrlock(&m_listenerLock);
  RELEASE_TO_NIL(m_listeners);
  pthread_rwlock_unlock(&m_listenerLock);

  pthread_rwlock_destroy(&m_listenerLock);
  [super dealloc];
}

@end
