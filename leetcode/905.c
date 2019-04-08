//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-23.
//

#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize) {
    int *result = malloc(sizeof(int) * ASize);
    *returnSize = ASize;

    int low = 0;
    int high = ASize - 1;

    for (int i = 0; i < ASize; i++) {
        if (A[i] & 1) {
            // odd
            result[high--] = A[i];
        } else {
            // even
            result[low++] = A[i];
        }
    }

    return result;
}