//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-27.
//

#include "datastructures.h"

bool traverse_104(struct TreeNode *root, int depth) {
    if (root->val != depth)
        return false;

    return (root->left != NULL ? traverse_104(root->left, depth) : true) &&
           (root->right != NULL ? traverse_104(root->right, depth) : true);
}

bool isUnivalTree(struct TreeNode *root) {
    if (root == NULL) {
        return false;
    }

    return traverse_104(root, root->val);
}