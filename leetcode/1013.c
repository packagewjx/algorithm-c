//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-25.
//

#include <stdbool.h>

// 如果三部分的和是相等的，那么必定是总和的三分之一
bool canThreePartsEqualSum(int *A, int ASize) {
    int sum = 0;
    for (int i = 0; i < ASize; i++) {
        sum += A[i];
    }
    if (sum % 3 != 0)
        return false;

    int target = sum / 3;
    sum = 0;
    int count = 0;
    for (int i = 0; i < ASize; i++) {
        sum += A[i];
        if (sum == target) {
            // found the first
            sum = 0;
            count++;
        }
    }
    return count == 3;
}

int main(int argv, char *argc[]) {
    int num[] = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    canThreePartsEqualSum(num, 11);
    return 0;
}