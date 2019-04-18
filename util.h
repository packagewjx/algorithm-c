//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-23.
//

#ifndef ALGORITHM_C_UTIL_H

void printIntArray(int *A, int size);

void swap(int *array, int i1, int i2);

/**
 *
 * @param array
 * @param start 开始位置
 * @param end 结束位置（不包含）
 * @return 分区的位置，是高区域的开始
 */
int partition(int *array, int start, int end);

/**
 * 寻找最高bit的位置
 * @param N
 * @return 最高比特位置，第一个比特下标为0
 */
int highestBit(unsigned int N);

#define ALGORITHM_C_UTIL_H

#endif //ALGORITHM_C_UTIL_H
