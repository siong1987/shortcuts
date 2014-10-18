//
//  AppDelegate.m
//  Logout
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
  MDSendAppleEventToSystemProcess(kAEReallyLogOut);

  // Quit the app
  [[NSApplication sharedApplication] terminate:nil];
}

@end
