//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-27.
//

#include <stdlib.h>

int* sortArrayByParityII(int* A, int ASize, int* returnSize) {
    int oddIndex = 1;
    int evenIndex = 0;

    int *result = malloc(sizeof(int) * ASize);
    *returnSize = ASize;

    for (int i = 0; i < ASize; i++) {
        if (A[i] & 1) {
            result[oddIndex] = A[i];
            oddIndex += 2;
        } else {
            result[evenIndex] = A[i];
            evenIndex += 2;
        }
    }

    return result;
}