//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-23.
//

#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **flipAndInvertImage(int **A, int ARowSize, int *AColSizes, int **columnSizes, int *returnSize) {
    *columnSizes = malloc(ARowSize * sizeof(int *));
    *returnSize = ARowSize;

    int **result = malloc(sizeof(int *) * ARowSize);
    for (int i = 0; i < ARowSize; i++) {
        result[i] = malloc(sizeof(int) * AColSizes[i]);
        (*columnSizes)[i] = AColSizes[i];

        for (int j = 0; j < AColSizes[i]; j++) {
            result[i][j] = 1 - A[i][AColSizes[i] - 1 - j];
        }
    }

    return result;
}

int main() {
    int A[] = {1, 1, 0, 1, 0, 1, 0, 0, 0};
    int cSize[] = {3, 3, 3};
    int* rCSize;
    int rSize;
    flipAndInvertImage((int **) A, 3, cSize, &rCSize, &rSize);



}