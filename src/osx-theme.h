
#ifndef SRC_OSX_THEME_H_
#define SRC_OSX_THEME_H_

#include <string>

class OSXTheme {
public:
    // Disable default contructor and copy
    OSXTheme() = delete;
    OSXTheme(const OSXTheme&) = delete;
    OSXTheme& operator=(const OSXTheme&) = delete;

    static void SetMode(const std::string& iMode);
    static void ToggleMode();
    static std::string GetMode();

private:
    static std::string _GetCurrentMode();
};

#endif  // SRC_OSX_THEME_H_
