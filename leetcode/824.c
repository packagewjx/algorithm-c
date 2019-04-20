//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-18.
//

#include <string.h>
#include <stdlib.h>

int nextSpaceOrEnd(char *str) {
    int count = 0;
    while (*str && *str != ' ') {
        str++;
        count++;
    }
    return count;
}

char *toGoatLatin(char *S) {
    char *buffer = malloc(sizeof(char) * 4096);
    int bufferSize = 0;
    char *cur = S;
    int wordCount = 0;

    while (*cur) {
        // 跳转到第一个位置
        while (*cur == ' ')
            cur++;

        int wordLength = nextSpaceOrEnd(cur);

        // 判断是否元音字母开头
        switch (*cur) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                // 复制整个字符串
                memcpy(buffer + bufferSize, cur, wordLength);
                bufferSize += wordLength;

                break;
            default:
                // 复制字符串
                memcpy(buffer + bufferSize, cur + 1, wordLength - 1);
                // 将头字符移动到最后
                buffer[bufferSize + wordLength - 1] = *cur;
                bufferSize += wordLength;
                break;
        }

        // 加ma到后面
        buffer[bufferSize++] = 'm';
        buffer[bufferSize++] = 'a';
        // 加入a
        memset(buffer + bufferSize, 'a', wordCount + 1);
        buffer[bufferSize + wordCount + 1] = ' ';
        bufferSize += wordCount + 2;
        wordCount += 1;

        cur += wordLength;
    }

    // 多了一个空格
    buffer[bufferSize - 1] = '\0';
    return buffer;
}

int main(int argv, char* argc[]) {
    toGoatLatin("CHcV J xm jH D oAD R CHl zgE Je HCP f iDf up ogm dd sqqX REv LgWg TD eMng ipHb g Yos Mb bWHf R btH GPHn M MIX z wU LXL Kl i B htS Yc IQvI p V");
    return 0;
}