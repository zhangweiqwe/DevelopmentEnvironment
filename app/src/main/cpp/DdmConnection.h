//
// Created by Administrator on 2019/7/8.
//

#ifndef MYAPPLICATION27_DDMCONNECTION_H
#define MYAPPLICATION27_DDMCONNECTION_H
#endif

#ifndef ANDROID_SF_DDM_CONNECTION
#define ANDROID_SF_DDM_CONNECTION
//#endif
namespace android {

// wrapper for dlsym
    extern "C" void DdmConnection_start(const char* name);

    class DdmConnection {
    public:
        static void start(const char* name);
    };

}; // namespace android

#endif /* ANDROID_SF_DDM_CONNECTION */
