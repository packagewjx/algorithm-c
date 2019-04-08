//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-31.
//

#include "datastructures.hpp"

#include <map>

using std::map;

class Solution {

public:
    vector<int> postorder(Node *root) {
        vector<Node *> stack(10);
        stack.push_back(root);

        map<Node *, bool> visited;
        vector<int> result;

        Node* cur;

        while (!stack.empty() && (cur = stack.back()) != nullptr) {
            if (cur->children.empty() || visited[cur]) {
                // 已经访问的中间节点和叶子节点将会打印
                result.push_back(cur->val);
                stack.pop_back();
            } else {
                for (auto it = cur->children.rbegin(); it < cur->children.rend(); it++)
                    // 反向推入子节点
                    stack.push_back(*it);
                visited[cur] = true;
            }
        }

        return result;
    }
};

int main(int argv, char* argc[]) {
    Node node1(1);
    Node node2(2);
    Node node3(3);
    Node node4(4);
    Node node5(5);
    Node node6(6);
    node1.children.push_back(&node3);
    node1.children.push_back(&node2);
    node1.children.push_back(&node4);
    node3.children.push_back(&node5);
    node3.children.push_back(&node6);

    Solution s;
    s.postorder(&node1);

    return 0;
}