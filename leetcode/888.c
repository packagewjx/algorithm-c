//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-20.
//

#include <stdlib.h>

int intCompare(const void* i1, const void* i2) {
    return *(int*) i1 - *(int*) i2;
}

int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize) {
    qsort(B, BSize, sizeof(int), &intCompare);

    // 确定总数
    int ASum = 0;
    for (int i = 0; i < ASize; i++) {
        ASum += A[i];
    }

    int BSum = 0;
    for (int i = 0; i < BSize; i++) {
        BSum += B[i];
    }

    // 确定差值。A与B交换糖果的差值就是两个总和的一半
    int diff = (ASum - BSum) / 2;

    int *result = malloc(2 * sizeof(int));
    *returnSize = 2;

    // 再次遍历A
    for (int i = 0; i < ASize; i++) {
        int key = A[i] - diff;
        int* search = NULL;
        if ((search = bsearch(&key, B, BSize, sizeof(int), &intCompare)) != NULL) {
            result[0] = A[i];
            result[1] = *search;
            return result;
        }
    }

    return result;
}

int main(int argv, char* argc[]) {

    return 0;
}