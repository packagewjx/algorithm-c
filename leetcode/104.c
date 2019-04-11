//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-10.
//

#include "tree.h"

/**
 *
 * @param root
 * @param depth root's depth
 * @return max depth from root
 */
int traverse(struct TreeNode* root, int depth) {
    if (root == 0)
        return depth - 1;

    int left = traverse(root->left, depth + 1);
    int right = traverse(root->right, depth + 1);

    return right > left ? right : left;
}

int maxDepth(struct TreeNode* root) {
    return traverse(root, 1);
}