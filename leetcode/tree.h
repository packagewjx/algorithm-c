//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-27.
//

#ifndef ALGORITHM_C_TREE_H

#define NULL_NODE 0x7FFFFFFF

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * 根据数组构建数
 * @param num 若元素为NULL_NODE，代表该节点为空节点
 * @param size 数组长度
 * @return
 */
struct TreeNode *constructTreeNodeLeetCode(int *num, int size);




#define ALGORITHM_C_TREE_H

#endif //ALGORITHM_C_TREE_H
