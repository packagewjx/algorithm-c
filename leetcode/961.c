//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-21.
//


#include <stdio.h>
#include <stdlib.h>

void display(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *array, int i1, int i2) {
    int temp = array[i1];
    array[i1] = array[i2];
    array[i2] = temp;
}

/**
 *
 * @param array
 * @param start 开始位置
 * @param end 结束位置（不包含）
 * @return 分区的位置，是高区域的开始
 */
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

int repeatedNTimes(int *A, int ASize) {
    int ret = 0;

    int low = 0;
    int high = ASize;
    // 因为保证ASize是偶数，因此这个ret最后在高半区域
    while ((ret = partition(A, low, high)) != ASize / 2) {
        if (ret < ASize / 2)
            low = ret + 1;
        else
            high = ret;
    }

    // 这里，ret应该在后半部分的开始
    // 三种情况，前半部分是，后半部分是，和中间是
    if (A[ASize / 2] == A[ASize / 2 + 1])
        // 这个情况覆盖了后半部分是
        return A[ASize / 2];
    else
        // 前半部分是和中间是
        return A[ASize / 2 - 1];
}

void quickSort(int *array, int start, int end) {
    if (start + 1 >= end)
        return;
    int middle = partition(array, start, end);
    quickSort(array, start, middle);
    quickSort(array, middle + 1, end);
}

int main() {


}