//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-3.
//

#include "datastructures.hpp"

class Solution {
    TreeNode *last = nullptr;
    TreeNode *Root = nullptr;

private:
    /**
 *
 * @param root not null
 * @return
 */
    void traverse(struct TreeNode *root) {
        if (root == nullptr)
            return;
        traverse(root->left);
        root->left = nullptr;
        if (last != nullptr)
            last->right = root;
        else  // last == NULL
            Root = root;
        last = root;
        traverse(root->right);
    }

public:
    TreeNode *increasingBST(TreeNode *root) {
        if (root == nullptr)
            return nullptr;

        last = nullptr;
        Root = nullptr;

        traverse(root);

        return Root;
    }
};