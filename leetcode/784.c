//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-22.
//

#include <string.h>
#include <stdlib.h>

char **letterCasePermutation(char *S, int *returnSize) {
    int strLen = strlen(S);
    char Scopy[12];
    strcpy(Scopy, S);

    int alphaPos[12];
    int alphaLen = 0;
    for (int i = 0; i < strLen; i++) {
        if (!(S[i] >= '0' && S[i] <= '9')) {
            alphaPos[alphaLen++] = i;
        }
    }

    if (alphaLen == 0) {
        char **result = malloc(sizeof(char *));
        result[0] = S;
        *returnSize = 1;
        return result;
    }

    *returnSize = 1 << alphaLen;
    char **result = malloc(*returnSize * sizeof(char *));
    char *buf = malloc(*returnSize * (strLen + 1) * sizeof(char));
    char *bufStart = buf;

    // 使用位图方式生成
    int bitmap = 0;
    for (int i = 0; i < *returnSize; i++) {
        // 从bitmap获取并设置字符串
        int mask = 1;
        for (int j = 0; j < alphaLen; j++) {
            if (mask & bitmap) {
                // 是1的话，为大写
                Scopy[alphaPos[j]] &= 0xDF;
            } else {
                // 不是1的话，为小写
                Scopy[alphaPos[j]] |= 0x20;
            }
            mask <<= 1;
        }

        // 设置完成复制结果
        strcpy(buf, Scopy);
        result[i] = buf;
        buf += strLen + 1;

        // 位图
        bitmap += 1;
    }

    return result;
}

int main(int argv, char *argc[]) {
    int size = 0;
    char **pString = letterCasePermutation("a1b2", &size);
    return 0;
}