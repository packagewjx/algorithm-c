//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-24.
//


#include <stdio.h>


// 应该有二分搜索的方法，但是暂时不清楚

#ifdef VER1
// normal iteration
int peakIndexInMountainArray(int* A, int ASize) {
    for (int i = 0; i < ASize - 1; i++) {
        if (A[i] > A[i + 1]) {
            return i;
        }
    }
    return 0;
}
#endif
