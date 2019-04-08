//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-27.
//

#include <stdlib.h>

#include "tree.h"
#include "../queue.h"


struct TreeNode * constructTreeNodeLeetCode(int *num, int size) {
    if (size == 0)
        return 0;
    struct TreeNode *root = malloc(sizeof(struct TreeNode));

    root->val = num[0];
    Queue *q = newQueue(sizeof(struct TreeNode *));
    queuePush(q, &root);
    struct TreeNode *cur = NULL;

    for (int i = 1; i < size; i++) {
        int err = queuePoll(q, &cur);
        if (err == -1) {
            exit(-1);
        }

        if (num[i] != NULL_NODE) {
            // 左节点不为空
            struct TreeNode *left = malloc(sizeof(struct TreeNode));
            left->val = num[i];

            cur->left = left;
            queuePush(q, &left);
        }

        i++;

        if (i == size)
            // 若抵达数组尾部则退出
            break;

        if (num[i] == NULL_NODE)
            // 右节点为空
            continue;

        // 右节点不为空
        struct TreeNode *right = malloc(sizeof(struct TreeNode));
        right->val = num[i];
        cur->right = right;
        queuePush(q, &right);
    }

    return root;
}