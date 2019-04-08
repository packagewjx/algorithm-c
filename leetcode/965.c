//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-27.
//

#include "datastructures.h"

bool traverse(struct TreeNode *root, int shouldBeVal) {
    if (root->val != shouldBeVal)
        return false;

    return (root->left != NULL ? traverse(root->left, shouldBeVal) : true) &&
           (root->right != NULL ? traverse(root->right, shouldBeVal) : true);
}

bool isUnivalTree(struct TreeNode *root) {
    if (root == NULL) {
        return false;
    }

    return traverse(root, root->val);
}