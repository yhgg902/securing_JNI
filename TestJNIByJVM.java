public class TestJNIByJVM {
   
        static {
            System.loadLibrary("name"); // Load native library hello.dll (Windows) or libhello.so (Unixes)
                                         //  at runtime
                                         // This library contains a native method called sayHello()
         }

    
    public native void testJNI(int inputInt, double inputDouble);

    public static void main(String[] args) {
 
        int input1 = 10;
        double input2 = 9.9;
        TestJNIByJVM testJNIByJVM = new TestJNIByJVM();
        testJNIByJVM.testJNI(input1, input2);

}
}