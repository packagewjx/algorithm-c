//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-3.
//

#include <stdlib.h>

char* reverseWords(char* s) {
    int cap = 4096;
    char *buf = malloc(cap);

    int wordLength = 0;
    int length = 0;

    while (1) {
        while (*s && *s != ' ') {
            wordLength++;
            s++;
        }

        char* continueLoc = s;
        s--;

        // check if we have enough place
        if (wordLength + length + 2 > cap) {
            // 2 includes space and \0
            cap = cap << 1;
            buf = realloc(buf, cap);
        }

        while (wordLength > 0) {
            buf[length] = *s;

            s--;
            length++;
            wordLength--;
        }

        if (*continueLoc == '\0')
            break;
        else
            s = continueLoc + 1;
        buf[length] = ' ';
        length++;
    }

    buf[length] = '\0';

    return buf;
}

int main() {
    reverseWords("abc  cba");
}