//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-24.
//

/**
 * 计算有多少个1在n里
 * @param n
 * @return
 */
int count1s(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int hammingDistance(int x, int y) {
    return count1s(x ^ y);
}
