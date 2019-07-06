#include <jni.h>
#include <string>
#include <android/log.h>
#include "Box.h"
#include <math.h>

#define  TAG    "demo"
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)

using namespace std;

int main(int argc, char *argv[]) {
    LOG_D(".so say hello");
    Box box;
    box.length = 5;
    box.breadth = 6;
    box.height = 7;


    Box *box1;
    box1 = &box;

    string str = "rwrewrrw";
    LOG_D("%lf\t%lf\t%lf\t%lf\t%lf\t%d\t%d", box.height, box.breadth, box.height, box.getHeight(),
          box1->getHeight(), &box, &box1);
    LOG_D("%s", str.c_str());
    LOG_D("--\n\n--\n\n----");

    for (int i = 1; i <= 20; i++) {
        double result = sin(M_PIl / 180 * i);
        //LOG_D("%lf",result);
    }
    return 0;
}

//https://developer.android.com/training/articles/perf-jni
//https://github.com/search?l=C%2B%2B&q=JNI_OnUnload+&type=Code

/*extern "C"
JNIEXPORT jstring JNICALL
Java_cn_wsgwz_myapplication_Jni_stringFromJNI(JNIEnv *env, jobject instance) {

    std::string hello = "Hello from C++";


    return env->NewStringUTF(hello.c_str());
}*/

/*extern "C"
JNIEXPORT jstring JNICALL
Java_cn_wsgwz_myapplication_MainActivity_stringFromJNI(JNIEnv *env, jobject instance) {

    std::string hello = "Hello from C++ UnregisterNatives ";

    jclass clazz = env->FindClass("cn/wsgwz/myapplication/Jni");
    if (clazz == 0) {
        LOG_D("JNI_OnUnload FindClass failed!");
    }

    int result = env->UnregisterNatives(clazz);
    LOG_D("JNI_OnUnload UnregisterNatives result:%d", result);
    LOG_D("JNI_OnUnload end==");


    return env->NewStringUTF(hello.c_str());
}*/
