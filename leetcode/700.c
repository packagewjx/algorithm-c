//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-27.
//

#include "datastructures.h"

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL)
        return NULL;

    if (root->val > val)
        return searchBST(root->left, val);
    else if (root->val < val)
        return searchBST(root->right, val);
    else // root->val == val
        return root;
}