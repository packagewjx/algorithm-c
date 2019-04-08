//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-24.
//

#ifndef ALGORITHM_C_QUEUE_H


/**
 * 自动增长长度的队列
 */
typedef struct {
    void *a;
    size_t head;
    // new place for new element
    size_t tail;
    size_t size;
    size_t elmSize;
} Queue;

/**
 * 创建新队列
 * @return 创建的新队列的指针。不用的时候需要使用queueFree释放
 */
Queue *newQueue(size_t elmSize);

/**
 * 取出队列头元素
 * @param q
 * @param loc 队列头元素存放这位置
 * @return 错误码。若0表示成功，其余表示出错，通常为队列空错误
 */
int queuePoll(Queue *q, void *loc);

/**
 * 推入一个元素。
 * 除非队列为空，否则head与tail永远不相遇。当只剩一个空位时，本函数自动进行扩展。
 * @param q
 */
void queuePush(Queue *q, void *val);

/**
 * 查看下一个元素
 * @param q
 * @param loc 队列头存放的位置
 * @return 错误码，0为成功，-1为队列空
 */
int queuePeek(Queue *q, void *loc);

/**
 * 查看队列是否空
 * @return 0是非空，其他是空
 */
int queueIsEmpty(Queue *q);

/**
 * 获取队列的长度
 * @param q
 * @return 队列长度
 */
int queueSize(Queue *q);

/**
 * 释放队列
 * @param q
 */
void queueFree(Queue *q);

#define ALGORITHM_C_QUEUE_H

#endif //ALGORITHM_C_QUEUE_H
