//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-10.
//

// 其实就是计算0的最多数目
int binaryGap(int N) {
    int longestGap = 0;
    unsigned int n = N;
    int last1 = -1;
    int zeroCount = 0;
    int cur = 0;

    while (n > 0) {
        if (n & 1) {
            // n & 1 == 1
            if (last1 != -1) {
                longestGap = longestGap > zeroCount + 1 ? longestGap : zeroCount + 1;
            }
            last1 = cur;
            zeroCount = 0;
        } else {
            // n & 1 == 0
            zeroCount++;
        }
        cur++;
        n = n >> 1;
    }

    return longestGap;
}

int main(int argv, char* argc[]) {
    binaryGap(291 );
    return 0;
}