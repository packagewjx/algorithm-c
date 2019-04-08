//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-27.
//

#include <stdlib.h>

int **transpose(int **A, int ARowSize, int AColSize, int **columnSizes, int *returnSize) {
    int **B = malloc(sizeof(int *) * AColSize);
    for (int i = 0; i < AColSize; i++) {
        B[i] = malloc(sizeof(int) * ARowSize);
        for (int j = 0; j < ARowSize; j++) {
            B[i][j] = A[j][i];
        }
    }

    *returnSize = AColSize;
    *columnSizes = malloc(sizeof(int) * AColSize);
    for (int i = 0; i < AColSize; i++) {
        (*columnSizes)[i] = ARowSize;
    }

    return B;
}

int main(int argv, char *argc[]) {
    int temp[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *matrix[] = {temp, temp + 3, temp + 6};

    int *co;
    int size;
    int **transpose1 = transpose(matrix, 3, 3, &co, &size);
    return 0;
}