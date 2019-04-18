//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-18.
//

#include <stdbool.h>

#include "../util.h"

int highestBit(unsigned int N) {
    int move = 16;
    int result = 0;
    while (move > 0) {
        int n = N >> move;
        if (n) {
            result += move;
            N = n;
        }
        move /= 2;
    }
    return result;
}

bool hasAlternatingBits(int n) {
    int h = highestBit(n);
    // 清除右边h+1个比特
    unsigned int mask = 0xFFFFFFFF ^ (0xFFFFFFFF >> (h + 1) << (h + 1));
    unsigned int mask1 = 0x55555555 & mask;// 0b01010101...
    unsigned int mask2 = 0xAAAAAAAA & mask;// 0b10101010...

    return (n ^ mask1) == 0 || (n ^ mask2) == 0;
}

int main(int argv, char* argc[]) {
    hasAlternatingBits(4);
    return 0;
}