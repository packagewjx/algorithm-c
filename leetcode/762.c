//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-11.
//

int prime[33] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0};

inline int bitCount(int n) {
    int count = 0;
    while (n != 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int countPrimeSetBits(int L, int R) {
    int count = 0;
    for (int i = L; i <= R; i++) {
        count += prime[bitCount(i)];
    }
    return count;
}