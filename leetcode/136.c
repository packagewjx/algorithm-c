//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-10.
//

int singleNumber(int* nums, int numsSize) {
    int num = 0;
    for (int i = 0; i < numsSize; i++) {
        num ^= nums[i];
    }

    return num;
}