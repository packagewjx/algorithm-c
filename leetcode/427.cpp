//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-22.
//

#include <vector>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node *topLeft = nullptr;
    Node *topRight = nullptr;
    Node *bottomLeft = nullptr;
    Node *bottomRight = nullptr;

    Node() {}

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
    /**
     * 将N*N的grid转换为初始的node数组
     * @param grid
     * @return 大小为(N/2)*(N/2)的Node*数组
     */
    vector<vector<Node *>> *bottomNodes(vector<vector<int>> &grid) {
        auto *nodes = new vector<vector<Node *>>();
        for (int i = 0; i < grid.size(); i += 2) {
            nodes->push_back(vector<Node *>());
            auto &rowNodes = (*nodes)[i >> 1];
            for (int j = 0; j < grid[i].size(); j += 2) {
                // 每次查看4个格子

                // 使用加法减少if数量
                int sum = grid[i][j] + grid[i][j + 1] + grid[i + 1][j] + grid[i + 1][j + 1];
                Node *n = new Node();
                if (sum == 0) {
                    // 4个均为0
                    n->isLeaf = true;
                    n->val = false;
                } else if (sum == 4) {
//                } else if (grid[i][j] && grid[i][j + 1] && grid[i + 1][j] && grid[i + 1][j + 1]) {
                    // 4个均为true
                    n->isLeaf = true;
                    n->val = true;
                } else {
                    // 4个不相等的，需要创建4个子node
                    n->val = false;
                    n->isLeaf = false;
                    n->topLeft = new Node(grid[i][j], true, nullptr, nullptr, nullptr, nullptr);
                    n->topRight = new Node(grid[i][j + 1], true, nullptr, nullptr, nullptr, nullptr);
                    n->bottomLeft = new Node(grid[i + 1][j], true, nullptr, nullptr, nullptr, nullptr);
                    n->bottomRight = new Node(grid[i + 1][j + 1], true, nullptr, nullptr, nullptr, nullptr);
                }

                rowNodes.push_back(n);
            }
        }
        return nodes;
    }

    /**
     * 将当前节点聚合成一棵树
     * @param nodes 2*2的节点的集合
     * @param targetSize 原本grid边长
     * @return
     */
    Node *aggregate(vector<vector<Node *>> *nodes) {
        // 聚合后，(0,0)就是根

        while (nodes->size() > 1) {
            auto *newNodes = new vector<vector<Node *>>();
            for (int i = 0; i < nodes->size(); i += 2) {
                // 每次检查两个
                auto &rowNodes = (*nodes)[i];
                auto &nextRowNodes = (*nodes)[i + 1];

                newNodes->push_back(vector<Node *>());
                auto &newRowNodes = (*newNodes)[i >> 1];

                for (int j = 0; j < rowNodes.size(); j += 2) {
                    // 4个格子中如果有1个是中间节点，则无法合并
                    Node *aNode = nullptr;
                    if (rowNodes[j]->isLeaf && rowNodes[j + 1]->isLeaf && nextRowNodes[j]->isLeaf &&
                        nextRowNodes[j + 1]->isLeaf) {
                        // 只有4个都为true，结果才是true。也就是4个都是叶子，才可能合并
                        if (rowNodes[j]->val + rowNodes[j + 1]->val + nextRowNodes[j]->val + nextRowNodes[j + 1]->val ==
                            0) {
                            aNode = new Node();
                            // 4个均为false结果为0
                            aNode->val = false;
                            aNode->isLeaf = true;
                        } else if (rowNodes[j]->val && rowNodes[j + 1]->val && nextRowNodes[j]->val &&
                                   nextRowNodes[j + 1]->val) {
                            // 4个均为true结果为true
                            aNode = new Node();
                            aNode->val = true;
                            aNode->isLeaf = true;
                        } else {
                            aNode = node4(rowNodes[j], rowNodes[j + 1], nextRowNodes[j], nextRowNodes[j + 1]);
                        }

                    } else {
                        // 无法合并，因此创建一个新的Node存储即可
                        aNode = node4(rowNodes[j], rowNodes[j + 1], nextRowNodes[j], nextRowNodes[j + 1]);
                    }
                    newRowNodes.push_back(aNode);
                }
            }

            // 继续下一轮循环
            nodes = newNodes;
        }

        return (*nodes)[0][0];
    }

    Node *node4(Node *topLeft, Node *topRight, Node *bottomLeft, Node *bottomRight) {
        Node *aNode = new Node();
        aNode->isLeaf = false;
        aNode->val = false;
        aNode->topLeft = topLeft;
        aNode->topRight = topRight;
        aNode->bottomLeft = bottomLeft;
        aNode->bottomRight = bottomRight;
        return aNode;
    }


public:

    /**
     * 自底向上构建树，首先构建2*2格子的Node数组，构建完毕后，就可以开始合并这些node。直到合并到只有一个根节点
     * @param grid
     * @return
     */
    Node *construct(vector<vector<int>> &grid) {
        vector<vector<Node *>> *pVector = bottomNodes(grid);
        return aggregate(pVector);
    }
};

int main(int argv, char *argc[]) {
    Solution s;
    vector<vector<int>> num = {{1, 1, 1, 1, 0, 0, 0, 0},
                               {1, 1, 1, 1, 0, 0, 0, 0},
                               {1, 1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 0, 0, 0, 0},
                               {1, 1, 1, 1, 0, 0, 0, 0},
                               {1, 1, 1, 1, 0, 0, 0, 0},
                               {1, 1, 1, 1, 0, 0, 0, 0}};
    s.construct(num);
    return 0;
}