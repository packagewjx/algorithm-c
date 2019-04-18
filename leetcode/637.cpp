//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-11.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>

using namespace std;
extern "C" {
#include "tree.h"
}


class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        if (root == nullptr)
            return {};

        int levelIndex = 0;
        vector<TreeNode *> nodes[2];
        vector<TreeNode *> *curLevel = &nodes[0];
        vector<TreeNode *> *nextLevel = &nodes[1];
        vector<double> result;
        curLevel->push_back(root);

        while (!curLevel->empty()) {
            double sum = 0;
            double count = 0;

            for (auto it = curLevel->begin(); it != curLevel->end(); it++) {
                sum += (*it)->val;
                count++;
                if ((*it)->left != nullptr)
                    nextLevel->push_back((*it)->left);
                if ((*it)->right != nullptr)
                    nextLevel->push_back((*it)->right);
            }

            result.push_back(sum / count);
            levelIndex ^= 1;
            curLevel = &nodes[levelIndex];
            nextLevel = &nodes[levelIndex ^ 1];
            nextLevel->clear();
        }

        return result;
    }
};

int main(int argv, char *argc[]) {
    int t[5] = {3, 9, 20, 15, 7};
    TreeNode *pNode = constructTreeNodeLeetCode(t, 5);
    Solution s;
    s.averageOfLevels(pNode);
    return 0;
}