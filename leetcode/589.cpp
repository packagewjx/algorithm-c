//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-31.
//

#include "datastructures.hpp"

class Solution {
public:
    vector<int> preorder(Node *root) {
        vector<Node *> stack(10);
        stack.push_back(root);

        vector<int> result;

        Node *cur;

        while (!stack.empty() && (cur = stack.back()) != nullptr) {
            result.push_back(cur->val);
            stack.pop_back();

            for (auto it = cur->children.rbegin(); it < cur->children.rend(); it++)
                // 反向推入子节点
                stack.push_back(*it);
        }

        return result;
    }
};