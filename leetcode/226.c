//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-18.
//

#include "tree.h"

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == 0) {
        return 0;
    }

    struct TreeNode * temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}

int main(int argv, char* argc[]) {
    int num[] = {4, 2, 7, 1, 3, 6, 9};
    struct TreeNode *pNode = constructTreeNodeLeetCode(num, 7);
    invertTree(pNode);
    return 0;
}