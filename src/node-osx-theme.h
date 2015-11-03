
#ifndef SRC_NODE_OSX_THEME_H_
#define SRC_NODE_OSX_THEME_H_

#include <node.h>

class NodeOSXTheme {
public:
    static void Init(v8::Local<v8::Object> iExports);

private:
    static void ToggleMode(const v8::FunctionCallbackInfo<v8::Value>& iArgs);
    static void SetMode(const v8::FunctionCallbackInfo<v8::Value>& iArgs);
    static void GetMode(const v8::FunctionCallbackInfo<v8::Value>& iArgs);
    static void IsDark(const v8::FunctionCallbackInfo<v8::Value>& iArgs);
    static void IsLight(const v8::FunctionCallbackInfo<v8::Value>& iArgs);
};

#endif  // SRC_NODE_OSX_THEME_H_
