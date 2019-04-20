//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-20.
//

#include <stdlib.h>

int intCompare(const void *i1, const void *i2) {
    return *(int *) i2 - *(int *) i1;
}

int largestPerimeter(int *A, int ASize) {
    qsort(A, ASize, sizeof(int), &intCompare);

    for (int i = 0; i < ASize - 2; i++) {
        if (A[i] + A[i + 1] > A[i + 2] && A[i + 1] + A[i + 2] > A[i] && A[i + 2] + A[i] > A[i + 1]) {
            return A[i] + A[i + 1] + A[i + 2];
        }
    }

    return 0;
}

int main(int argv, char* argc[]) {
    int s[4] = {3, 2, 3, 4};
    largestPerimeter(s, 4);
    return 0;
}