//
//  AppDelegate.h
//  Lock
//
//  Created by Teng Siong Ong on 11/19/14.
//  Copyright (c) 2014 Teng Siong Ong. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate>


@end

// ref: http://stackoverflow.com/questions/11609751/osx-lion-bug-desktop-may-become-unusable-when-launching-screensaver-programmati/11626752#11626752
@interface ScreenSaverController : NSObject + controller;
@end

@protocol ScreenSaverControl
- (void)screenSaverStartNow;
@end
