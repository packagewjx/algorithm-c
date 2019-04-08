//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-24.
//

#include <memory.h>

int minDeletionSize(char **A, int ASize) {
    int strSize = (int) strlen(A[0]);
    int count = 0;

    for (int i = 0; i < strSize; i++) {
        for (int j = 0; j < ASize - 1; j++) {
            if (A[j][i] > A[j + 1][i]) {
                count++;
                break;
            }
        }
    }

    return count;
}