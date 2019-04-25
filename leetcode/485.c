//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-25.
//

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            if (count > maxCount)
                maxCount = count;
            count = 0;
        } else {
            count++;
        }
    }
    if (count > maxCount)
        maxCount = count;
    return maxCount;
}