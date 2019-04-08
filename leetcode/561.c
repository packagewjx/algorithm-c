//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-24.
//

#include <stdlib.h>

int compare(const void* i1, const void* i2) {
    return *(int *) i1 - *(int *) i2;
}

int arrayPairSum(int* nums, int numsSize) {
    qsort(nums, (size_t) numsSize, sizeof(int), &compare);
    int sum = 0;
    for (int i = 0; i < numsSize; i += 2) {
        sum += nums[i];
    }

    return sum;
}