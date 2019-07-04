#include <jni.h>
#include <string>
#include <android/log.h>

#define  TAG    "demo"
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)
int main(int argc, char *argv[]) {
    LOG_D(".so say hello");
    return 0;
}
