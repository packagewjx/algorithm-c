//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-4.
//

// 另外有2分法找到最高位位置的方法

int findComplement(int num) {
    unsigned int temp = num;
    int mask = 0;
    while (temp > 0) {
        mask = (mask << 1) | 1;
        temp = temp >> 1;
    }
    return num ^ mask;
}