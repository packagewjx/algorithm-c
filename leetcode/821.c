//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-3.
//

#include <stdlib.h>

int *shortestToChar(char *S, char C, int *returnSize) {
    int lastLoc = -1;
    int cap = 1048;
    int *ret = malloc(sizeof(int) * cap);
    int length = 0;


    while (*S) {
        if (*S != C) {
            if (lastLoc == -1) {
                ret[length] = 0x7FFFFFFF;
            } else {
                ret[length] = length - lastLoc;
            }
        } else {
            lastLoc = length;
            ret[lastLoc] = 0;

            // 更新左边的数字
            for (int i = length - 1; i >= 0; i--) {
                int d = lastLoc - i;
                if (d < ret[i])
                    ret[i] = d;
                else
                    // 说明左边有更近的
                    break;
            }
        }

        length++;
        if (length == cap) {
            ret = realloc(ret, cap <<= 1);
        }
        S++;
    }

    *returnSize = length;
    return ret;
}

int main() {
    int size = 0;
    shortestToChar("loveleetcode", 'e', &size);
}