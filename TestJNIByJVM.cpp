#include "TestJNIByJVM.h"

    #include"iostream"
 #include<unistd.h> //unix标准文件

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
    // auto value = std::async (multiplication, std::ref(input), std::ref(input2));
    // printf("C++:return data: %f\n", value.get());
  
       using namespace std;
       pid_t pid;
      cout<<"parent have!"<<endl;
      pid = fork();//执行fork的时候到底发生了什么?
       if(pid == -1)//错误创建
       {
           perror("fork error");
             _exit(1);
       }
       else if(pid == 0)//子进程
       {

           cout<<"i am child,pid = "<<getpid()<<" my parent is:"<<getppid()<<endl;
           multiplication(input,input2);
       }
       else//父进程
       {
          sleep(1);
           cout<<"i am parent,pid = "<<getpid()<<" my parent is:"<<getppid()<<endl;
       }
       cout<<"both have!"<<endl;
      //  return 0;
   
    // return value.get();
  }





  // create new process
  // sql real example from library
  // separate processes
  // describe challege error
  // how to marshall


