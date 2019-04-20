//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-18.
//

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "tree.h"
#include "../util.h"

// ====================================================104==============================================================

/**
 *
 * @param root
 * @param depth root's depth
 * @return max depth from root
 */
int traverse_104(struct TreeNode *root, int depth) {
    if (root == 0)
        return depth - 1;

    int left = traverse_104(root->left, depth + 1);
    int right = traverse_104(root->right, depth + 1);

    return right > left ? right : left;
}

int maxDepth(struct TreeNode* root) {
    return traverse_104(root, 1);
}

// ====================================================136==============================================================

int singleNumber(int* nums, int numsSize) {
    int num = 0;
    for (int i = 0; i < numsSize; i++) {
        num ^= nums[i];
    }

    return num;
}

// ====================================================226==============================================================

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == 0) {
        return 0;
    }

    struct TreeNode * temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}

// ====================================================344==============================================================

void swapChar(char *s, int i1, int i2) {
    char temp = s[i1];
    s[i1] = s[i2];
    s[i2] = temp;
}

void reverseString(char* s, int sSize) {
    for (int i = 0; i < sSize / 2; i++) {
        swapChar(s, i, sSize - i - 1);
    }
}

// ====================================================461==============================================================

/**
 * 计算有多少个1在n里
 * @param n
 * @return
 */
int count1s(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int hammingDistance(int x, int y) {
    return count1s(x ^ y);
}

// ====================================================476==============================================================

int findComplement(int num) {
    unsigned int temp = num;
    int mask = 0;
    while (temp > 0) {
        mask = (mask << 1) | 1;
        temp = temp >> 1;
    }
    return num ^ mask;
}

// ====================================================509==============================================================

int fib(int N) {
    if (N == 1)
        return 1;
    else if (N == 0)
        return 0;

    int a = 0;
    int b = 1;
    int result = 0;

    for (int i = 2; i <= N; i++) {
        result = a + b;
        a = b;
        b = result;
    }

    return result;
}

// ====================================================557==============================================================

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

// ====================================================561==============================================================

int compareInt(const void *i1, const void *i2) {
    return *(int *) i1 - *(int *) i2;
}

int arrayPairSum(int* nums, int numsSize) {
    qsort(nums, (size_t) numsSize, sizeof(int), &compareInt);
    int sum = 0;
    for (int i = 0; i < numsSize; i += 2) {
        sum += nums[i];
    }

    return sum;
}

// ====================================================671==============================================================

struct TreeNode *mergeTrees(struct TreeNode *t1, struct TreeNode *t2) {
    if (t1 == NULL)
        return t2;
    if (t2 == NULL)
        return t1;

    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = t1->val + t2->val;
    node->left = mergeTrees(t1->left, t2->left);
    node->right = mergeTrees(t1->right, t2->right);
    return node;
}

// ====================================================657==============================================================

bool judgeCircle(char* moves) {
    int U = 0;
    int D = 0;
    int L = 0;
    int R = 0;

    while (*moves) {
        switch (*moves) {
            case 'U':
                U++;
                break;
            case 'D':
                D++;
                break;
            case 'L':
                L++;
                break;
            case 'R':
                R++;
                break;
        }
        moves++;
    }

    return U == D && L == R;
}

// ====================================================669==============================================================

struct TreeNode *trimBST(struct TreeNode *root, int L, int R) {
    if (root == 0) {
        return 0;
    }

    if (root->val < L) {
        return trimBST(root->right, L, R);
    } else if (root->val > R) {
        return trimBST(root->left, L, R);
    } else {
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
    }
    return root;
}

// ====================================================693==============================================================

bool hasAlternatingBits(int n) {
    int h = highestBit(n);
    // 清除右边h+1个比特
    unsigned int mask = 0xFFFFFFFF ^ (0xFFFFFFFF >> (h + 1) << (h + 1));
    unsigned int mask1 = 0x55555555 & mask;// 0b01010101...
    unsigned int mask2 = 0xAAAAAAAA & mask;// 0b10101010...

    return (n ^ mask1) == 0 || (n ^ mask2) == 0;
}

// ====================================================700==============================================================

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL)
        return NULL;

    if (root->val > val)
        return searchBST(root->left, val);
    else if (root->val < val)
        return searchBST(root->right, val);
    else // root->val == val
        return root;
}

// ====================================================709==============================================================

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

// ====================================================728==============================================================

/**
 *
 * @param num
 * @param digit
 * @return 数组有多少个数字
 */
int getDigits_728(int num, int *digit) {
    int temp = num;
    int cur = 0;
    while (temp > 0) {
        digit[cur++] = temp % 10;
        temp /= 10;
    }
    return cur;
}

void increment_728(int *digit) {
    digit[0] += 1;
    for (int i = 0; i < 4; i++) {
        if (digit[i] == 10) {
            digit[i] = 0;
            digit[i + 1] += 1;
        }
    }
}

int *selfDividingNumbers(int left, int right, int *returnSize) {
    int digit[5] = {0, 0, 0, 0, 0};

    int *result = malloc(sizeof(int) * 10000);
    *returnSize = 0;

    // 拆解最左边的数字以开始
    int numOfDigits = getDigits_728(left, digit);

    for (int i = left; i <= right; i++) {
        int isDividing = 1;

        // 只有在分界点的时候更改，减少写入次数
        if (i == 10) {
            numOfDigits = 2;
        } else if (i == 100) {
            numOfDigits = 3;
        } else if (i == 1000) {
            numOfDigits = 4;
        } else if (i == 10000) {
            numOfDigits = 5;
        }

        for (int j = 0; j < numOfDigits; j++) {
            if (digit[j] == 0 || i % digit[j]) {
                isDividing = 0;
                break;
            }
        }

        if (isDividing) {
            result[*returnSize] = i;
            (*returnSize)++;
        }

        increment_728(digit);
    }
    return result;
}

// ====================================================762==============================================================

int prime_762[33] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0};

int countPrimeSetBits(int L, int R) {
    int count = 0;
    for (int i = L; i <= R; i++) {
        count += prime_762[bitCount(i)];
    }
    return count;
}

// ====================================================771==============================================================

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

// ====================================================806==============================================================

#define MAX_WIDTH_806 100

int *numberOfLines(int *widths, int widthsSize, char *S, int *returnSize) {
    int lineWidth = 0;
    int lineCount = 0;
    for (int i = 0; i < S.size; i++) {
        if (lineWidth + widths[S[i] - 'a'] > MAX_WIDTH_806) {
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

// ====================================================821==============================================================

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

// ====================================================832==============================================================

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **flipAndInvertImage(int **A, int ARowSize, int *AColSizes, int **columnSizes, int *returnSize) {
    *columnSizes = malloc(ARowSize * sizeof(int *));
    *returnSize = ARowSize;

    int **result = malloc(sizeof(int *) * ARowSize);
    for (int i = 0; i < ARowSize; i++) {
        result[i] = malloc(sizeof(int) * AColSizes[i]);
        (*columnSizes)[i] = AColSizes[i];

        for (int j = 0; j < AColSizes[i]; j++) {
            result[i][j] = 1 - A[i][AColSizes[i] - 1 - j];
        }
    }

    return result;
}

// ====================================================852==============================================================

int peakIndexInMountainArray(int* A, int ASize) {
    for (int i = 0; i < ASize - 1; i++) {
        if (A[i] > A[i + 1]) {
            return i;
        }
    }
    return 0;
}