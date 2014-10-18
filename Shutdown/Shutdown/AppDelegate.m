//
//  AppDelegate.m
//  Shutdown
//
//  Created by Teng Siong Ong on 10/18/14.
//  Copyright (c) 2014 Teng Siong Ong. All rights reserved.
//

#import "AppDelegate.h"
#import "MDRestartShutdownLogout.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
  MDSendAppleEventToSystemProcess(kAEShutDown);

  // Quit the app
  [[NSApplication sharedApplication] terminate:nil];
}

@end
