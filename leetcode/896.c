//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-25.
//
#include <stdbool.h>

bool isMonotonic(int *A, int ASize) {
    if (ASize == 1) {
        return true;
    }

    int i = 0;
    // 跳过相同的元素
    while (i + 1 < ASize && A[i] == A[i + 1])
        i++;
    if (i + 1 == ASize) {
        // 所有都相同，返回true
        return true;
    }

    int direction = A[i] - A[i + 1];
    if (direction < 0) {
        while (i + 1 < ASize) {
            if (A[i] > A[i + 1])
                return false;
            i++;
        }
    } else {
        while (i + 1 < ASize) {
            if (A[i] < A[i + 1])
                return false;
            i++;
        }
    }

    return true;
}