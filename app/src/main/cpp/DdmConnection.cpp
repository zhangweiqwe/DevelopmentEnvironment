//
// Created by Administrator on 2019/7/8.
//

#include <dlfcn.h>
#include <unistd.h>

//#include <cutils/log.h>

#include "jni.h"
#include "DdmConnection.h"

#include <iostream>
#include <ostream>

using namespace std;

namespace android {

    void DdmConnection_start(const char *name) {
        //ALOGI("DdmConnection_start");
        cout << "DdmConnection_start" << endl;

        DdmConnection::start(name);
    }

    void DdmConnection::start(const char *name) {
        JavaVM *vm;
        JNIEnv *env;

        // start a VM
        JavaVMInitArgs args;
        JavaVMOption opt;

        opt.optionString =
                "-agentlib:jdwp=transport=dt_android_adb,suspend=n,server=y";

        args.version = JNI_VERSION_1_4;
        args.options = &opt;
        args.nOptions = 1;
        args.ignoreUnrecognized = JNI_FALSE;


        //void *libdvm_dso = dlopen("libdvm.so", RTLD_NOW);
        void *libdvm_dso = dlopen("libart.so", RTLD_NOW);
        //ALOGE_IF(!libdvm_dso, "DdmConnection: %s", dlerror());

        if(!libdvm_dso){
            cout << "DdmConnection:"<<dlerror() << endl;
        } else{
            cout << "libdvm_dso" << endl;
        }

        void *libandroid_runtime_dso = dlopen("libandroid_runtime.so", RTLD_NOW);
        //ALOGE_IF(!libandroid_runtime_dso, "DdmConnection: %s", dlerror());
        if(!libandroid_runtime_dso){
            cout << "DdmConnection:"<<dlerror() << endl;
        } else{
            cout << "libandroid_runtime_dso" << endl;
        }


        if (!libdvm_dso || !libandroid_runtime_dso) {
            goto error;
        }

        jint (*JNI_CreateJavaVM)(JavaVM **p_vm, JNIEnv **p_env, void *vm_args);
        //JNI_CreateJavaVM = (typeof JNI_CreateJavaVM)dlsym(libdvm_dso, "JNI_CreateJavaVM");
        //ALOGE_IF(!JNI_CreateJavaVM, "DdmConnection: %s", dlerror());

        jint (*registerNatives)(JNIEnv *env, jclass clazz);
        /*registerNatives = (typeof registerNatives)dlsym(libandroid_runtime_dso,
                                                        "Java_com_android_internal_util_WithFramework_registerNatives");*/
        //ALOGE_IF(!registerNatives, "DdmConnection: %s", dlerror());

        cout << "1" << endl;


        if (!JNI_CreateJavaVM || !registerNatives) {
            goto error;
        }

        cout << "2" << endl;

        if (JNI_CreateJavaVM(&vm, &env, &args) == 0) {
            jclass startClass;
            jmethodID startMeth;
            // register native code
            if (registerNatives(env, 0) == 0) {
                // set our name by calling DdmHandleAppName.setAppName()
                startClass = env->FindClass("android/ddm/DdmHandleAppName");
                if (startClass) {
                    startMeth = env->GetStaticMethodID(startClass,
                                                       "setAppName", "(Ljava/lang/String;I)V");
                    if (startMeth) {
                        jstring str = env->NewStringUTF(name);
                        env->CallStaticVoidMethod(startClass, startMeth, str, getuid());
                        env->DeleteLocalRef(str);
                    }
                }

                // initialize DDMS communication by calling
                // DdmRegister.registerHandlers()
                startClass = env->FindClass("android/ddm/DdmRegister");
                if (startClass) {
                    startMeth = env->GetStaticMethodID(startClass,
                                                       "registerHandlers", "()V");
                    if (startMeth) {
                        env->CallStaticVoidMethod(startClass, startMeth);
                    }
                }
            }
        }
        return;

        error:
        if (libandroid_runtime_dso) {
            dlclose(libandroid_runtime_dso);
        }
        if (libdvm_dso) {
            dlclose(libdvm_dso);
        }
    }

}; // namespace android
