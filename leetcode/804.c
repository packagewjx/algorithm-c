//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-21.
//

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

char *MORSE[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
                 "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
size_t MORSE_SIZE[] = {2, 4, 4, 3, 1, 4, 3, 4, 2, 4, 4, 4, 2, 2, 3, 4, 4, 3, 3, 1, 3, 4, 3, 4, 4, 4};

// 计算字符串的哈希值
int calHash(const char *str) {
    int hash = 0;
    while (*str) {
        hash = hash * 31 + *str;
        str++;
    }
    return hash;
}

/**
 * 检查array是否有val
 * @param array
 * @param val
 * @return 0代表没有，1则是有
 */
int inArray(const int *array, int aSize, int val) {
    for (int i = 0; i < aSize; i++) {
        if (val == array[i])
            return 1;
    }
    return 0;
}

/**
 * 计算一个字符串的摩斯码
 * @param str
 * @return 摩斯码的长度。如果是-1，代表空间不足
 */
int getMorse(const char *str, char *buf, size_t bufSize) {
    int written = 0;
    while (*str) {
        int no = *str - 'a';
        // 如果超过内存空间，则返回
        if (written + MORSE_SIZE[no] >= bufSize)
            return -1;

        memcpy(buf, MORSE[no], MORSE_SIZE[no]);
        buf += MORSE_SIZE[no];
        written += MORSE_SIZE[no];
        str++;
    }

    // 最后写空字符，表示字符串结束
    *buf = '\0';
    return written;
}

int uniqueMorseRepresentations(char **words, int wordsSize) {
    int *hashes = malloc(wordsSize * sizeof(int));
    int hashSize = 0;

    size_t bufferSize = 512;
    char *buf = malloc(bufferSize);

    for (int i = 0; i < wordsSize; i++) {
        // 如果buffer空间不足，则重新分配
        while (getMorse(words[i], buf, bufferSize) == -1) {
            bufferSize *= 2;
            free(buf);
            buf = malloc(bufferSize);
        }

        int hash = calHash(buf);

        if (!inArray(hashes, hashSize, hash)) {
            hashes[hashSize++] = hash;
        }
    }

    free(buf);
    free(hashes);
    return hashSize;
}

int main() {
    char* strings[4];
    strings[0] = "gin";
    strings[1] = "zen";
    strings[2] = "gig";
    strings[3] = "msg";

    printf("%d\n", uniqueMorseRepresentations(strings, 4));
}