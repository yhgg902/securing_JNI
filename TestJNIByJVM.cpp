#include "TestJNIByJVM.h"

JNIEXPORT jint JNICALL Java_TestJNIByJVM_testJNI
  (JNIEnv* env, jobject jobj, jint input, jdouble input2) {
    printf("C++:input data: %d\n", input);
    jint res = input * input;
    printf("C++:return data: %d\n", res);
    printf("C++:input data: %f\n", input2);
    jdouble res2 = input2 * input2;
    printf("C++:return data: %f\n", res2);
    return res;
  }
