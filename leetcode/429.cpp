//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-10.
//

#include "datastructures.hpp"

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        if (root == nullptr)
            return vector<vector<int>>();
        vector<vector<int>> result;

        vector<Node *> level[2];
        level[0].push_back(root);
        int nextLevelVectorIndex = 1;

        while (!level[nextLevelVectorIndex ^ 1].empty()) {
            vector<Node *> &thisLevel = level[nextLevelVectorIndex ^ 1];
            vector<Node *> &nextLevel = level[nextLevelVectorIndex];
            vector<int> lVal;
            nextLevel.clear();
            for (auto it = thisLevel.begin(); it != thisLevel.end(); it++) {
                if (!(*it)->children.empty())
                    nextLevel.insert(nextLevel.end(), (*it)->children.begin(), (*it)->children.end());
                lVal.push_back((*it)->val);
            }
            result.push_back(lVal);
            nextLevelVectorIndex ^= 1;
        }

        return result;
    }
};