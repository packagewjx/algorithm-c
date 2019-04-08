//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-24.
//

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#define QUEUE_INIT_SIZE 16

/**
 * 自动增长长度的队列
 */
typedef struct {
    int *a;
    int head;
    // new place for new element
    int tail;
    int size;
} Queue;

/**
 * create a new queue. be sure to call free on Queue pointer.
 * @param initSize
 * @return
 */
Queue *newQueue() {
    Queue *queue = malloc(sizeof(Queue));
    queue->a = malloc(sizeof(int) * QUEUE_INIT_SIZE);
    queue->head = 0;
    queue->tail = 0;
    queue->size = QUEUE_INIT_SIZE;
    return queue;
}

/**
 *
 * @param q
 * @param val  value polled
 * @return errno. 0 indicate success. -1 indicate queue is empty.
 */
int poll(Queue *q, int *val) {
    if (q->head == q->tail) {
        // indicate it's empty
        return -1;
    }
    *val = q->a[q->head];
    // 对于2的幂，位与相当于取余
    q->head = (q->head + 1) & (q->size - 1);
    return 0;
}

/**
 * 除非队列为空，否则head与tail永远不相遇。当只剩一个空位时，本函数自动进行扩展。
 * @param q
 */
void push(Queue *q, int num) {
    int newTail = (q->tail + 1) & (q->size - 1);
    if (newTail == q->head) {
        // 这表明，如果加了这个元素，队列就会满，因此需要扩容
        int *newQueue = realloc(q->a, sizeof(int) * (q->size << 1));
        if (q->tail < q->head) {
            // 如果队列的尾部在数组中的位置是在head的前头，则需要复制到现在的size位置
            memcpy(newQueue + q->size, newQueue, sizeof(int) * (q->tail + 1));
            q->tail = q->tail + q->size;
        }

        q->a = newQueue;
        q->size = q->size << 1;
    }

    q->a[q->tail] = num;
    q->tail = (q->tail + 1) & (q->size - 1);
}

/**
 * 查看下一个元素
 * @param q
 * @param num 队列头
 * @return 错误码，0为成功，-1为队列空
 */
int peek(Queue *q, int *num) {
    if (q->head == q->tail)
        return -1;
    *num = q->a[q->head];
    return 0;
}

/**
 * 查看队列是否空
 * @return 0是非空，其他是空
 */
int isEmpty(Queue* q) {
    return q->head == q->tail;
}


int size(Queue* q) {
    return (q->tail - q->head + q->size) & (q->size - 1);
}

void freeQueue(Queue *q) {
    free(q->a);
    free(q);
}

typedef struct {
    Queue *q;
} RecentCounter;

RecentCounter *recentCounterCreate() {
    RecentCounter *c = malloc(sizeof(RecentCounter));
    c->q = newQueue();
    return c;
}

int recentCounterPing(RecentCounter *obj, int t) {
    int first;

    push(obj->q, t);
    
    while (!peek(obj->q, &first) && t - first > 3000) {
        poll(obj->q, &first);
    }

    return size(obj->q);
}

void recentCounterFree(RecentCounter *obj) {
    freeQueue(obj->q);
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * struct RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 * recentCounterFree(obj);
 */


int main() {
    RecentCounter *ptr = recentCounterCreate();
    recentCounterPing(ptr, 1);
    recentCounterPing(ptr, 100);
    recentCounterPing(ptr, 3000);
    recentCounterPing(ptr, 3001);
    recentCounterPing(ptr, 7000);
}