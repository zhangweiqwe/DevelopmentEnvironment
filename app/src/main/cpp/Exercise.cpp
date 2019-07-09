//
// Created by Administrator on 2019/7/9.
//
#include <jni.h>
#include "Exercise.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "Util.h"
#include <time.h>
#include "Box.h"

using namespace std;

void Exercise::test() {
    srand(time(nullptr));
    for (int i = 0; i < ARR_LENGTH; i++) {
        arr[i] = rand();
    }


    printCurrentArr("排序之前的数组 size=" + to_string(Util::getArrSize(arr)));



    for (int i = 0; i < ARR_LENGTH; i++) {
        for (int u = i; u < ARR_LENGTH; u++) {
            int z = arr[u];
            if (arr[i] < z) {
                arr[u] = arr[i];
                arr[i] = z;
            }
        }
    }


    printCurrentArr("排序后的数组");


    int max_value = arr[0];

    cout << "max value = " << max_value << endl;

    for (int i = 0; i < ARR_LENGTH; i++) {

        if (arr[i] == max_value) {
            cout << "max value index = " << i << endl;
            break;
        }
    }

}

void Exercise::printCurrentArr(string description) {
    cout << description << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }
}

