#include <node.h>

namespace index {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Number;


void isPalindrome(const FunctionCallbackInfo<Value>& info) {
  String::Utf8Value sentence(info[0]->ToString());
  std::string str = std::string(*sentence);
  int len = str.length();
  int half = len / 2;
  int start = 0;
  int end = len - 1;
  int space = 32;
  bool isPal = true;

  while (half > 0 && isPal) {
    bool startSpace = str.at(start) == space;
    bool endSpace = str.at(end) == space;

    if (str.at(start) == str.at(end)) {
      start++;
      end--;
    } else if (startSpace || endSpace) {
      startSpace && start++;
      endSpace && end--;
    } else {
      isPal = false;
    }

    half--;
  }

  info.GetReturnValue().Set(isPal);
}

void weirdSum(const FunctionCallbackInfo<Value>& info){
  Isolate* isolate = info.GetIsolate();
  int i;
  double a = 3.14159265358979323846, b = 5.321123321;
  for(i = 0 ; i < 100000000; i++){
    a += b + i;
  }

  auto total = Number::New(isolate, a);
  info.GetReturnValue().Set(total);
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "isPalindrome", isPalindrome);
  NODE_SET_METHOD(exports, "weirdSum", weirdSum);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo