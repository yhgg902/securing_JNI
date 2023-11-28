#include "TestJNIByJVM.h"
#include <thread>
#include <future>

double multiplication(jint input, jdouble input2){
    printf("C++:input data: %d\n", input);
    jint res = input * input;
    printf("C++:return data: %d\n", res);
    printf("C++:input data: %f\n", input2);
    jdouble res2 = input2 * input2;
    printf("C++:return data: %f\n", res2);
    return res2;
}

JNIEXPORT void JNICALL Java_TestJNIByJVM_testJNI
  (JNIEnv* env, jobject jobj, jint input, jdouble input2) {
    auto value = std::async (multiplication, std::ref(input), std::ref(input2));
    printf("C++:return data: %f\n", value.get());
    // return value.get();
  }

  // create new process
  // sql real example from library
  // separate processes
  // describe challege error
  // how to marshall


