//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-27.
//

#ifndef ALGORITHM_C_DATASTRUCTURES_HPP

#include <vector>

using std::vector;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) : val(_val) {}

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


#define ALGORITHM_C_DATASTRUCTURES_HPP

#endif //ALGORITHM_C_DATASTRUCTURES_HPP
