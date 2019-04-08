//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-4.
//

extern "C"{
#include "tree.h"
}
#include <vector>

using std::vector;

class Solution {
private:
    TreeNode *nextLeaf(vector<TreeNode *> &currentStack) {
        while (!currentStack.empty()) {
            TreeNode *cur = currentStack.back();
            currentStack.pop_back();

            if (cur->left == nullptr && cur->right == nullptr)
                return cur;
            if (cur->right != nullptr)
                currentStack.push_back(cur->right);
            if (cur->left != nullptr)
                currentStack.push_back(cur->left);
        }
        return nullptr;
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr || root2 == nullptr)
            return false;

        // 两个栈，保存遍历顺序
        vector<TreeNode *> s1;
        vector<TreeNode *> s2;
        s1.push_back(root1);
        s2.push_back(root2);

        while (!s1.empty() && !s2.empty()) {
            // 找到root1的下一个子女
            TreeNode *root1Leaf = nextLeaf(s1);
            TreeNode *root2Leaf = nextLeaf(s2);

            if (root1Leaf->val != root2Leaf->val)
                return false;
        }

        return true;
    }
};

int main(int argv, char *argc[]) {
    int t1[] = {3, 5, 1, 6, 2, 9, 8, NULL_NODE, NULL_NODE, 7, 4};
    int t2[] = {3, 5, 1, 6, 7, 4, 2, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, 9, 8};
    TreeNode *root1 = constructTreeNodeLeetCode(t1, 11);
    TreeNode *root2 = constructTreeNodeLeetCode(t2, 15);
    Solution s;
    s.leafSimilar(root1, root2);

    return 0;
}