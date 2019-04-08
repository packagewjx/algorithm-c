//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-27.
//

#include <stdlib.h>
#include <memory.h>

char **commonChars(char **A, int ASize, int *returnSize) {
    int *countA = malloc(sizeof(int) * 26 * ASize);
    int totalLength = 26 * ASize;

    for (int i = 0; i < ASize; i++) {
        char *str = A[i];
        int *count = countA + i * 26;
        while (*str) {
            count[*str - 'a']++;
            str++;
        }
    }

    char ** result = NULL;
    *returnSize = 0;
    for (int i = 0; i < 26; i++) {
        int smallest = 0x7FFFFFFF;
        for (int j = i; j < totalLength; j += 26) {
            if (countA[j] < smallest) {
                smallest = countA[j];
            }
        }

        if (smallest == 0)
            continue;

        // 写入结果
        result = realloc(result, sizeof(char*) * (*returnSize + smallest));
        for (int j = *returnSize; j < smallest + *returnSize; j++) {
            result[j] = malloc(2 * sizeof(char));
            result[j][0] = ('a' + i);
            result[j][1] = '\0';
        }
        *returnSize += smallest;
    }

    free(countA);

    return result;
}

int main(int argv, char* argc[]) {
    char *str[3];
    str[0] = "bella";
    str[1] = "label";
    str[2] = "roller";

    int size;
    char **chars = commonChars(str, 3, &size);
    
    return 0;
}