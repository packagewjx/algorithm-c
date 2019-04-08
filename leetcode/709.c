//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-16.
//

#include <malloc.h>
#include <memory.h>

char *toLowerCase(char *str) {
    size_t lenStr = strlen(str);
    char *result = malloc(lenStr + 1);
    char *cur = result;

    long *lstr = (long *) str;
    unsigned long _64 = 0xC0C0C0C0C0C0C0C0; //65-c<=0, 64-c<0
    unsigned long _90 = 0xDADADADADADADADA; //90-c>=0
    while (lenStr > 8) {
        unsigned long m64 = _64 - *lstr;
        unsigned long m90 = _90 - *lstr;
        unsigned long _64to90 = (m64 ^ m90) & 0x8080808080808080;
        *(long *) cur = *lstr | (_64to90 >> 2);
        lenStr -= 8;
        cur += 8;
        str += 8;
        lstr += 1;
    }

    // 处理剩余几个字符
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') {
            *cur = *str | (char) 0x20;
        } else {
            *cur = *str;
        }
        cur++;
        str++;
    }

    // 设置结尾
    *cur = '\0';

    return result;
}

int main() {
//    for (int i = 0; i < 128; i++) {
//        printf("%c", i);
//    }
//    printf("\n");

    char *string = toLowerCase(
            "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
    printf("%s\n", string);
}