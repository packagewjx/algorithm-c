//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-23.
//

#include <stdlib.h>
#include <memory.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* S, int* returnSize) {
    *returnSize = (int) strlen(S) + 1;
    int *result = malloc(sizeof(int) * *returnSize);

    result[0] = 0;
    int m = -1;
    int p = 1;

    for (int i = 1; i < *returnSize; i++) {
        switch (S[i - 1]) {
            case 'I':
                result[i] = p++;
                break;
            case 'D':
                result[i] = m--;
                break;
        }
    }

    // add to zero base
    int shouldAdd = -(m + 1);
    for (int i = 0; i < *returnSize; i++) {
        result[i] += shouldAdd;
    }

    return result;
}