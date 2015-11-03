
#include "./node-osx-theme.h"
#include "./osx-theme.h"

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

void NodeOSXTheme::ToggleMode(const FunctionCallbackInfo<Value>& iArgs) {
    OSXTheme::ToggleMode();
}

void NodeOSXTheme::SetMode(const FunctionCallbackInfo<Value>& iArgs) {
    Isolate* isolate = iArgs.GetIsolate();

    if (iArgs.Length() < 1) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }

    if (!iArgs[0]->IsString()) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong arguments")));
        return;
    }

    std::string test = *String::Utf8Value(iArgs[0]);
    OSXTheme::SetMode(test);
}

void NodeOSXTheme::GetMode(const FunctionCallbackInfo<Value>& iArgs) {
    Isolate* isolate = iArgs.GetIsolate();

    Local<String> mode = String::NewFromUtf8(isolate, OSXTheme::GetMode().c_str());

    iArgs.GetReturnValue().Set(mode);
}

void NodeOSXTheme::IsDark(const FunctionCallbackInfo<Value>& iArgs) {
    Isolate* isolate = iArgs.GetIsolate();

    iArgs.GetReturnValue().Set(OSXTheme::GetMode() == "Dark");
}

void NodeOSXTheme::IsLight(const FunctionCallbackInfo<Value>& iArgs) {
    Isolate* isolate = iArgs.GetIsolate();

    iArgs.GetReturnValue().Set(OSXTheme::GetMode() == "Light");
}

void NodeOSXTheme::Init(Local<Object> iExports) {
    NODE_SET_METHOD(iExports, "toggleMode", NodeOSXTheme::ToggleMode);
    NODE_SET_METHOD(iExports, "setMode", NodeOSXTheme::SetMode);
    NODE_SET_METHOD(iExports, "getMode", NodeOSXTheme::GetMode);
    NODE_SET_METHOD(iExports, "isDark", NodeOSXTheme::IsDark);
    NODE_SET_METHOD(iExports, "isLight", NodeOSXTheme::IsLight);
}

NODE_MODULE(OSXTheme, NodeOSXTheme::Init)
