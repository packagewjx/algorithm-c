//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-3.
//

#include <stdlib.h>

#define MAX_WIDTH 100

int *numberOfLines(int *widths, int widthsSize, char *S, int *returnSize) {
    int lineWidth = 0;
    int lineCount = 0;
    for (int i = 0; i < S.size; i++) {
        if (lineWidth + widths[S[i] - 'a'] > MAX_WIDTH) {
            lineCount += 1;
            lineWidth = 0;
        }
        lineWidth += widths[S[i] - 'a'];
    }


    int *r = malloc(sizeof(int) * 2);
    r[0] = lineCount + 1;
    r[1] = lineWidth;
    *returnSize = 2;
    return r;
}

int main(int argv, char *argc[]) {
    int widths[] = {4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                    10};
    int size = 0;
    numberOfLines(widths, 12, "bbbcccdddaaa", &size);
    return 0;
}