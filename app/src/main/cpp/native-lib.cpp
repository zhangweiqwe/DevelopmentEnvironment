#include <jni.h>
#include <string>
#include <android/log.h>
#include "Box.h"
#include <math.h>
#include <unistd.h>
#include <map>
#include <iostream>
#include <ostream>
#include <list>
#include "DdmConnection.h"
#define  TAG    "demo"
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)

using namespace std;

int main(int argc, char *argv[]) {
    LOG_D(".so say hello");
    Box box;
    box.length = 5;
    box.breadth = 6;
    box.height = 7;


    int ip = 10;
    int *ipPos = &ip;

    Box *box1;
    box1 = &box;

    string str = "rwrewrrw";
    LOG_D("%lf\t%lf\t%lf\t%lf\t%lf\t%d\t%d", box.height, box.breadth, box.height, box.getHeight(),
          box1->getHeight(), &box, &box1);
    LOG_D("%s\t%lf\t%#x\t%lf", str.c_str(), (box1->getHeight()), &box, box.height);

    LOG_D("%d\t%#x", ip, &ip);
    //LOG_D("--\n\n--\n\n----");

    for (int i = 1; i <= 20; i++) {
        double result = sin(M_PIl / 180 * i);
        //LOG_D("%lf",result);
    }

    /*int i=0;
    while (true){
        sleep(5);
        LOG_D("zr%d",i++);
    }*/


    //https://blog.csdn.net/qq_40914533/article/details/81981467
    map<int, int> m1, m2, m3;
    map<int, int>::iterator m1_iterator;
    m1.insert(pair<int, int>(1, 10));

    for (m1_iterator = m1.begin(); m1_iterator != m1.end(); m1_iterator++) {
        LOG_D("%d\t%d", m1_iterator->first, m1_iterator->second);
    }

    cout << "success" << std::endl;

    map<int, int>::iterator k1_iterator = m1.find(1);
    cout << m1_iterator->first << endl;


    //https://www.cnblogs.com/lalalabi/p/5060210.html
    list<int> list_1;
    list<int>::iterator list_1_iterator;
    list_1_iterator = list_1.begin();

    cout << "success 0" << endl;

    for (int i = 1; i <= 5; ++i) {
        list_1.push_back(i); // 1 2 3 4 5
        //list_1_iterator = list_1.begin();
        ++list_1_iterator;

    }

    list_1.resize(5);
    list_1.insert(list_1_iterator, 1);
    list_1.insert(list_1_iterator, 30);
    cout << "success 1" << endl;

    int index = 0;
    int posi_value;
    for (list_1_iterator = list_1.begin(); list_1_iterator != list_1.end(); list_1_iterator++) {
        cout << *list_1_iterator << "<--" << endl;

        if (index == 3) {
            posi_value = *list_1_iterator;
        }
        index++;
    }

    cout << "--->" << posi_value << endl;

    cout << list_1.size() << endl;

    android::DdmConnection_start("test JavaVM");

    //https://github.com/davros-/frameworks_native/blob/bb2b505a87cbecfd5fd9da166e15fbbb852c1721/services/surfaceflinger/DdmConnection.cpp
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
