//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-25.
//

#include <string.h>

void moveZeroes(int *nums, int numsSize) {
    int size = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0)
            nums[size++] = nums[i];
    }
    memset(nums + size, 0, sizeof(int) * (numsSize - size));
}

int main(int argv, char *argc[]) {
    int n[] = {1, 0, 3, 0, 0, 12, 0};
    moveZeroes(n, 7);
    return 0;
}