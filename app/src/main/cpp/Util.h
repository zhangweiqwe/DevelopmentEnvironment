//
// Created by Administrator on 2019/7/9.
//

#ifndef MYAPPLICATION27_UTIL_H
#define MYAPPLICATION27_UTIL_H

class Util {

public:
    template<class T>
    static int getArrSize(T &arr) {
        return sizeof(arr) / sizeof(arr[0]);
    }
};


#endif //MYAPPLICATION27_UTIL_H
