//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-22.
//

#include <string.h>
#include <stdlib.h>

extern inline int isLetter(const char *loc) {
    if ((*loc >= 'a' && *loc <= 'z') || (*loc >= 'A' && *loc <= 'Z'))
        return 1;
    return 0;
}

char *reverseOnlyLetters(char *S) {
    int len = strlen(S);
    char *buf = malloc(sizeof(char) * len);
    strcpy(buf, S);

    // 双头指针
    char *p = S + len - 1;
    char *q = buf;

    while (*q) {
        // 跳过buf中符号
        while (*q && !isLetter(q))
            q++;
        if (*q == 0)
            break;

        // 跳过S中的符号
        while (!isLetter(p))
            p--;

        *q = *p;
        q++;
        p--;
    }

    return buf;
}

int main(int argv, char* argc[]) {
    reverseOnlyLetters("ab-cd");
    return 0;
}