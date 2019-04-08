//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-16.
//

#include <string.h>
#include <stdio.h>

#define VER2

#ifdef VER1

int numJewelsInStones(char *J, char *S) {
    if (strlen(J) == 0 || strlen(S) == 0) {
        return 0;
    }

    // 使用一个表记录哪些是宝石
    char isJewel[128];
    memset(isJewel, 0, 128);
    for (int i = 0; i < strlen(J); i++) {
        isJewel[J[i]] = 1;
    }

    int jewelCount = 0;
    for (int i = 0; i < strlen(S); i++) {
        if (isJewel[S[i]] != 0) {
            jewelCount++;
        }
    }

    return jewelCount;
}

#elif defined(VER2)

int numJewelsInStones(char *J, char *S) {

}

#endif


int main() {
    printf("%d", numJewelsInStones("", "AaaAAAbBBBbb"));
}
