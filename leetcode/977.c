//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-23.
//

#include <stdlib.h>
#include "../util.h"

#ifdef VER2

int *sortedSquares(int *A, int ASize, int *returnSize) {
    int *result = malloc(sizeof(int) * ASize);
    *returnSize = ASize;

    if (A[0] >= 0 && A[ASize - 1] >= 0) {
        // if all positive
        for (int i = 0; i < ASize; i++) {
            result[i] = A[i] * A[i];
        }
        return result;
    } else if (A[0] < 0 && A[ASize - 1] < 0) {
        // if all negative
        for (int i = 0; i < ASize; i++) {
            result[i] = A[ASize - i - 1] * A[ASize - i - 1];
        }
    }

    // pointer of minus numbers
    int mp = 0;
    // pointer of positive numbers
    int pp = ASize - 1;

    // eventually, these pointer will go to number 0, and stand there.
    int cur = ASize - 1;
    while (A[mp] < 0 && A[pp] > 0) {
        if (-A[mp] > A[pp]) {
            result[cur--] = A[mp] * A[mp];
            mp++;
        } else {
            result[cur--] = A[pp] * A[pp];
            pp--;
        }
    }


    if (A[mp] >= 0) {
        // mp stands at 0, so pp has positive numbers.
        while (mp <= pp) {
            result[cur--] = A[pp] * A[pp];
            pp--;
        }
    } else {
        while (mp <= pp) {
            result[cur--] = A[mp] * A[mp];
            mp++;
        }

    }
    return result;
}

#endif

#ifdef VER1
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize) {
    // stands for positive squares, include 0, ascending.
    int *pSquares = malloc(sizeof(int) * ASize);
    int pSize = 0;
    // stands for negative squares, descending.
    int *mSquares = malloc(sizeof(int) * ASize);
    int mSize = 0;

    // calculate two squares.
    int cur;
    for (cur = 0; cur < ASize && A[cur] < 0; cur++) {
        mSquares[mSize++] = A[cur] * A[cur];
    }
    while (cur < ASize) {
        pSquares[pSize++] = A[cur] * A[cur];
        cur++;
    }

    // merge two sequences
    int *result = malloc(sizeof(int) * (pSize + mSize));
    cur = 0;
    int pCur = 0;
    int mCur = mSize - 1;
    while (pCur < pSize && mCur >= 0) {
        if (pSquares[pCur] < mSquares[mCur]) {
            result[cur++] = pSquares[pCur];
            pCur++;
        } else{
            result[cur++] = mSquares[mCur];
            mCur--;
        }
    }

    while (pCur < pSize) {
        result[cur++] = pSquares[pCur++];
    }

    while (mCur >= 0) {
        result[cur++] = mSquares[mCur--];
    }

    *returnSize = pSize + mSize;
    return result;
}

#endif

int main() {
    int num[] = {-5, -4, 1, 2, 5};
    int size;
    int *pInt = sortedSquares(num, 5, &size);

    printIntArray(pInt, 5);
}