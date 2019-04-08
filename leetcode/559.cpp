//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-27.
//


#include "datastructures.hpp"

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;

        return traverse(root, 1);
    }

private:
    int traverse(Node* root, int current) {
        int deepest = current;

        for (auto it = root->children.begin(); it < root->children.end(); it++) {
            int ret = traverse(*it, current + 1);
            if (ret > deepest)
                deepest = ret;
        }

        return deepest;
    }
};