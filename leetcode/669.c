//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-10.
//

#include "tree.h"

struct TreeNode *trimBST(struct TreeNode *root, int L, int R) {
    if (root == 0) {
        return 0;
    }

    if (root->val < L) {
        return trimBST(root->right, L, R);
    } else if (root->val > R) {
        return trimBST(root->left, L, R);
    } else {
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
    }
    return root;
}
