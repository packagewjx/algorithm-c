//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-24.
//

#include <stdlib.h>
#include <memory.h>
#include "queue.h"

#define QUEUE_INIT_SIZE 16


Queue *newQueue(size_t elmSize) {
    Queue *queue = malloc(sizeof(Queue));
    queue->elmSize = elmSize;
    queue->size = QUEUE_INIT_SIZE;
    queue->a = malloc(elmSize * queue->size);
    queue->head = queue->tail = 0;

    return queue;
}

int queuePoll(Queue *q, void *val) {
    if (queueIsEmpty(q)) {
        // 空队列
        return -1;
    }

    memcpy(val, q->a + q->head * q->elmSize, q->elmSize);
    q->head = (q->head + 1) & (q->size - 1);
    return 0;
}


void queuePush(Queue *q, void *val) {
    size_t newTail = (q->tail + 1) & (q->size - 1);
    if (newTail == q->head) {
        // 加了这个元素，队列就会满，因此需要扩容
        void *newA = realloc(q->a, q->elmSize * (q->size << 1));

        if (q->tail < q->head) {
            // 在这个数组中，尾部在前面，则复制到head后的空元素的位置
            memcpy(newA + (q->size) * q->elmSize, newA, q->elmSize * (q->tail + 1));
            q->tail = q->tail + q->size;
        }

        q->a = newA;
        q->size = q->size << 1;
    }

    memcpy(q->elmSize * q->tail + q->a, val, q->elmSize);
    q->tail = (q->tail + 1) & (q->size - 1);
}

int queuePeek(Queue *q, void *loc) {
    if (queueIsEmpty(q))
        return -1;

    memcpy(loc, q->a + q->elmSize * q->head, q->elmSize);
    return 0;
}

int queueIsEmpty(Queue *q)  {
    return q->head == q->tail;
}

int queueSize(Queue *q) {
    return (int) ((q->tail - q->head + q->size) & (q->size - 1));
}

void queueFree(Queue *q) {
    free(q->a);
    free(q);
}