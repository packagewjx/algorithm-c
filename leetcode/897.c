//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-27.
//

#include <stdlib.h>
#include "datastructures.h"



struct TreeNode *last = NULL;
struct TreeNode *Root = NULL;

/**
 *
 * @param root not null
 * @return
 */
void traverse(struct TreeNode *root) {
    if (root == NULL)
        return;
    traverse(root->left);
    root->left = NULL;
    if (last != NULL)
        last->right = root;
    else  // last == NULL
        Root = root;
    last = root;
    traverse(root->right);
}

struct TreeNode *increasingBST(struct TreeNode *root) {
    if (root == NULL)
        return NULL;

    traverse(root);

    return Root;
}

int main(int argv, char *argc[]) {
    int num[] = {212};
    struct TreeNode *pNode = constructTreeNodeLeetCode(num, 1);
    struct TreeNode *pTreeNode = increasingBST(pNode);
    return 0;
}