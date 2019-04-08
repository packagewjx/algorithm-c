//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-24.
//

#include <stdlib.h>
#include "../util.h"

/**
 *
 * @param num
 * @param digit
 * @return 数组有多少个数字
 */
int getDigits(int num, int digit[5]) {
    int temp = num;
    int cur = 0;
    while (temp > 0) {
        digit[cur++] = temp % 10;
        temp /= 10;
    }
    return cur;
}

void increment(int digit[5]) {
    digit[0] += 1;
    for (int i = 0; i < 4; i++) {
        if (digit[i] == 10) {
            digit[i] = 0;
            digit[i + 1] += 1;
        }
    }
}

int *selfDividingNumbers(int left, int right, int *returnSize) {
    int digit[5] = {0, 0, 0, 0, 0};

    int *result = malloc(sizeof(int) * 10000);
    *returnSize = 0;

    // 拆解最左边的数字以开始
    int numOfDigits = getDigits(left, digit);

    for (int i = left; i <= right; i++) {
        int isDividing = 1;

        // 只有在分界点的时候更改，减少写入次数
        if (i == 10) {
            numOfDigits = 2;
        } else if (i == 100) {
            numOfDigits = 3;
        } else if (i == 1000) {
            numOfDigits = 4;
        } else if (i == 10000) {
            numOfDigits = 5;
        }

        for (int j = 0; j < numOfDigits; j++) {
            if (digit[j] == 0 || i % digit[j]) {
                isDividing = 0;
                break;
            }
        }

        if (isDividing) {
            result[*returnSize] = i;
            (*returnSize)++;
        }

        increment(digit);
    }
    return result;
}

int main() {
    int size = 0;
    int *pInt = selfDividingNumbers(1, 100, &size);
    printIntArray(pInt, size);
}