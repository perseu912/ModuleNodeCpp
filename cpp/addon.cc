#include <node.h>
 
//exemplo de função 
void Sum(const v8::FunctionCallbackInfo<v8::Value>& args){
  v8::Isolate* isolate= args.GetIsolate();
  
  //parametros da função
  double a = 1.0, b = 1.0;
  for(int i = b; i< 1.0e7; i++){
    a+=a/i;
  }
  
  //pega o valor produzido pelos parametros da função e escolhe o tipo de sua variavel
  auto total = v8::Number::New(isolate,a);
  
  //e envia de volta pro script
  args.GetReturnValue().Set(total);
}
 
 
void Initialize(v8::Local<v8::Object> exports){
  NODE_SET_METHOD(exports, "sum",Sum);
}
 
NODE_MODULE(addon, Initialize)