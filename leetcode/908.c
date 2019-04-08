//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-27.
//

#include <zconf.h>

int smallestRangeI(int* A, int ASize, int K) {
    int smallest = INT_MAX;
    int biggest = INT_MIN;
    for (int i = 0; i < ASize; i++) {
        if (A[i] > biggest)
            biggest = A[i];
        if (A[i] < smallest)
            smallest = A[i];
    }

    if (smallest + K < biggest - K) {
        return biggest - K - smallest - K;
    } else {
        return 0;
    }
}