//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-27.
//

#include <stdlib.h>
#include <stdio.h>
#include "../util.h"

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sumEvenAfterQueries(int *A, int ASize, int **queries, int queriesRowSize, int queriesColSize, int *returnSize) {
    *returnSize = queriesRowSize;
    int *result = malloc(sizeof(int) * queriesRowSize);

    for (int i = 0; i < queriesRowSize; i++) {
        A[queries[i][1]] += queries[i][0];

        // add all even number
        result[i] = 0;
        for (int j = 0; j < ASize; j++) {
            result[i] += A[j] & (0xFFFFFFFF + (A[j] & 1));
        }
    }

    return result;
}

int main() {
    int A[] = {1, 2, 3, 4};
    int queriesA[] = {1, 0, -3, 1, -4, 0, 2, 3};

    int *queries[] = {queriesA, queriesA + 2, queriesA + 4, queriesA + 6};

    int size;
    int *pInt = sumEvenAfterQueries(A, 4, queries, 4, 2, &size);
    printIntArray(pInt, size);

}