//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-29.
//

#include "tree.h"

int main(int argv, char* argc[]) {
    int num[] = {5, 3, 6, 2, 4, NULL_NODE, 8, 1, NULL_NODE, NULL_NODE, NULL_NODE, 7, 9};
    struct TreeNode *pNode = constructTreeNodeLeetCode(num, 13);
    return 0;
}