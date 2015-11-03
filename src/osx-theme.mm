
#include "./osx-theme.h"

#import <Foundation/Foundation.h>

void OSXTheme::SetMode(const std::string& iMode) {
    // If the mode is not correct then return
    if (iMode != "Light" && iMode != "Dark") {
        return;
    }

    NSString *newMode = [NSString stringWithCString:iMode.c_str()
                                  encoding:[NSString defaultCStringEncoding]];

    CFPreferencesSetValue((CFStringRef)@"AppleInterfaceStyle", (__bridge CFPropertyListRef)(newMode), kCFPreferencesAnyApplication, kCFPreferencesCurrentUser, kCFPreferencesCurrentHost);

    CFNotificationCenterPostNotification(CFNotificationCenterGetDistributedCenter(), (CFStringRef)@"AppleInterfaceThemeChangedNotification", NULL, NULL, YES);
}

void OSXTheme::ToggleMode() {
  std::string currentMode = OSXTheme::GetMode();

  OSXTheme::SetMode(currentMode == "Dark" ? "Light" : "Dark");
}

std::string OSXTheme::GetMode() {
    NSString *mode = CFBridgingRelease(CFPreferencesCopyValue((CFStringRef)@"AppleInterfaceStyle", kCFPreferencesAnyApplication, kCFPreferencesCurrentUser, kCFPreferencesCurrentHost));

    return [mode UTF8String];
}

