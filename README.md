## after modifying the java code

run 

```
javac -h . TestJNIByJVM.java
```

to compile a .class file and .h file for c/c++ code


## after modifying the cpp code

run

```
g++ -std=c++11 -I $JAVA_HOME/include -I $JAVA_HOME/include/darwin -dynamiclib -o libname.dylib TestJNIByJVM.cpp
```

to link the library code


## RUN the code

```
java TestJNIByJVM
```
