//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-11.
//

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

int bitwiseComplement(int N) {
    int move = highestBit(N) + 1;
    unsigned int mask = 0xFFFFFFFF >> move << move;
    mask ^= 0xFFFFFFFF;
    return N ^ mask;
}

int main(int argv, char *argc[]) {
    bitwiseComplement(8);
    return 0;
}