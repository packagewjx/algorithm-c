//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-23.
//

#include <stdio.h>
#include "util.h"

void printIntArray(int *A, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void swap(int *array, int i1, int i2) {
    int temp = array[i1];
    array[i1] = array[i2];
    array[i2] = temp;
}


int partition(int *array, const int start, const int end) {
    if (end <= start + 1)
        return start;
    else if (end - 2 == start) {
        // 针对只有两个元素的情况
        if (array[start] > array[end - 1]) {
            swap(array, start, end - 1);
        }
        return end - 1;
    }
    int pivot = array[start];

    int low = start + 1;
    int high = end - 1;

    // high将会停止在小于pivot的数上，而low停止在大于等于pivot的数上
    while (low <= high) {
        while (array[low] < pivot && low <= high)
            low++;
        while (array[high] >= pivot && low <= high)
            high--;

        if (low > high)
            break;

        swap(array, low, high);

        low++;
        high--;
    }
    // pivot交换
    swap(array, start, high);

    return high;
}

/**
 * 寻找最高bit的位置
 * @param N
 * @return 最高比特位置，第一个比特下标为0
 */
int highestBit(unsigned int N) {
    int move = 16;
    int result = 0;
    while (move > 0) {
        int n = N >> move;
        if (n) {
            result += move;
            N = n;
        }
        move /= 2;
    }
    return result;
}