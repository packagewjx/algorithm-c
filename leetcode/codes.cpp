//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-18.
//

#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>

#include "datastructures.hpp"

using namespace std;


class Solution412 {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);

        for (int i = 3; i <= n; i += 3) {
            result[i - 1] = "Fizz";
        }
        for (int i = 5; i <= n; i += 5) {
            result[i - 1] += "Buzz";
        }

        for (int i = 1; i <= n; i++) {
            if (result[i - 1].empty()) {
                result[i - 1] = to_string(i);
            }
        }

        return result;
    }
};

class Solution427 {
public:
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

private:
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

class Solution429 {
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

class Solution463 {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int result = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    result += 4;
                    if (i > 0 && grid[i - 1][j])
                        result -= 1;
                    if (i < grid.size() - 1 && grid[i + 1][j])
                        result -= 1;
                    if (j > 0 && grid[i][j - 1])
                        result -= 1;
                    if (j < grid[i].size() - 1 && grid[i][j + 1])
                        result -= 1;
                }
            }
        }

        return result;
    }
};

class Solution496 {

public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            result[i] = -1;
            for (int j = i + 1; j < nums2.size(); j++) {
                if (nums2[j] > nums1[i]) {
                    result[i] = nums2[j];
                    break;
                }
            }
        }
        return result;
    }
};

class Solution500 {
    string row[3] = {"QWERTYUIOPqwertyuiop", "ASDFGHJKLasdfghjkl", "ZXCVBNMzxcvbnm"};
    set<char> rowKeys[3];

    bool typeOneRow(const string &word) {
        // 首先从第一个字符判断是哪个集合
        char first = word[0];
        int setNum = -1;
        for (int i = 0; i < 3; i++) {
            if (rowKeys[i].find(first) != rowKeys[i].end()) {
                setNum = i;
            }
        }

        // 检查后面的字符是否在这个集合
        for (int i = 1; i < word.size(); i++) {
            if (rowKeys[setNum].find(word[i]) == rowKeys[setNum].end()) {
                // 说明不在集合
                return false;
            }
        }

        return true;
    }

    void initSet() {
        for (int i = 0; i < 3; i++) {
            rowKeys[i] = set<char>();
            for (int j = 0; j < row[i].size(); j++) {
                rowKeys[i].insert(row[i][j]);
            }
        }
    }

public:
    vector<string> findWords(vector<string> &words) {
        initSet();

        vector<string> result;

        for (auto &word : words) {
            if (typeOneRow(word)) {
                result.push_back(word);
            }
        }

        return result;
    }
};

class Solution559 {
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

class Solution566 {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        if (r * c != nums.size() * nums[0].size())
            // 无效情况
            return nums;

        vector<int> all;
        for (int i = 0; i < nums.size(); i++) {
            all.insert(all.end(), nums[i].begin(), nums[i].end());
        }

        vector<vector<int>> result(r);
        int row = 0;
        for (auto it = all.begin(); it != all.end(); it += c) {
            result[row].insert(result[row].end(), it, it + c);
            row++;
        }

        return result;
    }
};

class Solution575 {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> candyKinds;
        for (auto it = candies.begin(); it != candies.end(); it++) {
            candyKinds.insert(*it);
        }
        return candies.size() / 2 < candyKinds.size() ? candies.size() / 2 : candyKinds.size();
    }
};

class Solution589 {
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

class Solution590 {

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

class Solution637 {
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

class Solution682 {
public:
    int calPoints(vector<string>& ops) {
        vector<int> points;
        int sum = 0;

        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "D") {
                points.push_back(points[points.size() - 1] * 2);
            } else if (ops[i] == "C") {
                sum -= points[points.size() - 1];
                points.pop_back();
                // don't add
                continue;
            } else if (ops[i] == "+") {
                points.push_back(points[points.size() - 1] + points[points.size() - 2]);
            } else {
                points.push_back(std::stoi(ops[i]));
            }
            sum += points[points.size() - 1] ;
        }
        return sum;
    }
};

class Solution766 {
private:
    // 判断这个点的对角线是否全等
    bool diagonalEqual(vector<vector<int>> &matrix, int row, int col) {
        int num = matrix[row][col];
        row++;
        col++;

        while (row < matrix.size() && col < matrix[0].size()) {
            if (matrix[row][col] != num)
                return false;
            row++;
            col++;
        }
        return true;
    }

public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        // 从最左下开始，往上走
        for (int i = matrix.size() - 1; i >= 0; i--) {
            if (!diagonalEqual(matrix, i, 0)) {
                return false;
            }
        }

        // 第一行第二个，往右走。这样就覆盖了所有对角线
        for (int i = 1; i < matrix[0].size(); i++) {
            if (!diagonalEqual(matrix, 0, i)) {
                return false;
            }
        }

        return true;
    }
};

class Solution806 {
#define MAX_WIDTH_806 100

public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lineWidth = 0;
        int lineCount = 0;
        for (int i = 0; i < S.size(); i++) {
            if (lineWidth + widths[S[i] - 'a'] > MAX_WIDTH_806) {
                lineCount += 1;
                lineWidth = 0;
            }
            lineWidth += widths[S[i] - 'a'];
        }

        vector<int> r(2);
        r[0] = lineCount + 1;
        r[1] = lineWidth;
        return r;
    }
};

class Solution811 {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> count;
        vector<string> result;

        for (auto it = cpdomains.begin(); it < cpdomains.end(); it++) {
            int spaceIndex = (*it).find(' ');
            const string countStr = (*it).substr(0, spaceIndex);
            long thisCount = strtol(countStr.c_str(), nullptr, 10);

            // 从后往前查找，并加入count到map中
            for (int i = (*it).size() - 1; i > spaceIndex; i--) {
                while (i > spaceIndex && (*it)[i] != '.')
                    i--;

                count[(*it).substr(i + 1)] += thisCount;
            }
        }

        for (auto it = count.begin(); it != count.end(); it++) {
            result.push_back(std::to_string(it->second) + " " + it->first);
        }

        return result;
    }
};

class Solution867 {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> result(A[0].size());

        for (int i = 0; i < A[0].size(); i++) {
            result[i] = vector<int>(A.size());
            for (int j = 0; j < A.size(); j++) {
                result[i][j] = A[j][i];
            }
        }

        return result;
    }
};

class Solution872 {
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

class Solution883 {
public:
    int projectionArea(vector<vector<int>>& grid) {
        vector<int> xzProject(grid.size());
        vector<int> yzProject(grid[0].size());

        int sum = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0)
                    continue;

                sum += 1;

                if (xzProject[i] < grid[i][j]) {
                    xzProject[i] = grid[i][j];
                }

                if (yzProject[j] < grid[i][j]) {
                    yzProject[j] = grid[i][j];
                }
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            sum += xzProject[i];
        }

        for (int i = 0; i < grid[0].size(); i++) {
            sum += yzProject[i];
        }

        return sum;
    }
};

class Solution884 {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        set<string> aWord;
        set<string> aWordUncommon;

        string word;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == ' ') {
                if (aWord.find(word) != aWord.end()) {
                    aWordUncommon.erase(word);
                } else {
                    aWord.insert(word);
                    aWordUncommon.insert(word);
                }
                word.clear();
            } else {
                word += A[i];
            }
        }
        // last word
        if (aWord.find(word) != aWord.end()) {
            aWordUncommon.erase(word);
        } else {
            aWord.insert(word);
            aWordUncommon.insert(word);
        }
        word.clear();

        // handle B
        set<string> bWord;
        set<string> bWordUncommon;
        // aWordOnce用于存储A中出现1次的，但是B中不出现的，因此下面需要删除一些元素

        for (int i = 0; i < B.size(); i++) {
            if (B[i] == ' ') {
                if (bWord.find(word) != bWord.end()) {
                    bWordUncommon.erase(word);
                } else {
                    bWord.insert(word);

                    if (aWord.find(word) == aWord.end())
                        bWordUncommon.insert(word);
                    else
                        aWordUncommon.erase(word);
                }
                word.clear();
            } else {
                word += B[i];
            }
        }
        // 最后一个word
        if (bWord.find(word) != bWord.end()) {
            bWordUncommon.erase(word);
        } else {
            if (aWord.find(word) == aWord.end())
                bWordUncommon.insert(word);
            else
                aWordUncommon.erase(word);
        }

        vector<string> result = vector<string>(aWordUncommon.begin(), aWordUncommon.end());
        result.insert(result.end(), bWordUncommon.begin(), bWordUncommon.end());
        return result;
    }
};

class Solution892 {
public:
    int surfaceArea(vector<vector<int>> &grid) {
        int area = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0)
                    continue;
                area += grid[i][j] * 6;

                // 减去叠加中间少的面积
                area -= (grid[i][j] - 1) * 2;
                // 减去下面重复面积
                if (i + 1 < grid.size()) {
                    area -= 2 * (grid[i][j] > grid[i + 1][j] ? grid[i + 1][j] : grid[i][j]);
                }
                // 减去右边重复部分的面积
                if (j + 1 < grid[i].size()) {
                    area -= 2 * (grid[i][j] < grid[i][j + 1] ? grid[i][j] : grid[i][j + 1]);
                }
            }
        }

        return area;
    }
};

class Solution893 {
#define INDEX_MASK 0x1F
#define COUNT_ARRAY_SIZE 32

private:

    struct Group {
        // 成员数量
        int size;

        // 偶数位字符统计数组
        char *evenCount;
        // 奇数位字符统计数组
        char *oddCount;
    };

    void newGroup(const string &A, Group *g) {
        g->size = 1;
        g->evenCount = static_cast<char *>(calloc(sizeof(char), COUNT_ARRAY_SIZE));
        g->oddCount = static_cast<char *>(calloc(sizeof(char), COUNT_ARRAY_SIZE));
        for (int i = 0; i < A.size(); i += 2) {
            g->evenCount[A[i] & INDEX_MASK]++;
        }

        for (int i = 1; i < A.size(); i += 2) {
            g->oddCount[A[i] & INDEX_MASK]++;
        }
    }

    // 比较两组是否相同
    bool groupEqual(Group *g1, Group *g2) {
        int ite = (COUNT_ARRAY_SIZE - 1) / sizeof(long) + 1;

        long *count1 = reinterpret_cast<long *>(g1->evenCount);
        long *count2 = reinterpret_cast<long *>(g2->evenCount);
        for (int i = 0; i < ite; i++) {
            if (count1[i] != count2[i])
                return false;
        }

        count1 = reinterpret_cast<long *>(g1->oddCount);
        count2 = reinterpret_cast<long *>(g2->oddCount);
        for (int i = 0; i < ite; i++) {
            if (count1[i] != count2[i])
                return false;
        }

        return true;
    }

public:

    /* 想法：要是经过多次特殊移动之后是相同的，意味着同一组里面，奇数位的字符，都是一样的，偶数位的字符也是一样的
       优化方法：
           1. 都是小写字符，且长度不超过20，因此做一个长度32的char数组，下标不用减法，而是用与计算，字符与上0x1FFFF。
           2. 将数组强制转换为long，只需要比较4次，而不是26次。
     */
    int numSpecialEquivGroups(vector<string> &A) {
        vector<Group *> groups;


        for (auto it = A.begin(); it != A.end(); it++) {
            Group *g = static_cast<Group *>(malloc(sizeof(Group)));
            newGroup(*it, g);

            Group *foundG = nullptr;
            // 寻找是否有相同组的
            for (auto git = groups.begin(); git != groups.end(); git++) {
                if (groupEqual(*git, g)) {
                    foundG = *git;
                    break;
                }
            }

            if (foundG != nullptr) {
                foundG->size++;
                free(g->oddCount);
                free(g->evenCount);
                free(g);
            } else {
                groups.push_back(g);
            }
        }

        return groups.size();
    }
};

class Solution897 {
    TreeNode *last = nullptr;
    TreeNode *Root = nullptr;

private:
    /**
 *
 * @param root not null
 * @return
 */
    void traverse(struct TreeNode *root) {
        if (root == nullptr)
            return;
        traverse(root->left);
        root->left = nullptr;
        if (last != nullptr)
            last->right = root;
        else  // last == NULL
            Root = root;
        last = root;
        traverse(root->right);
    }

public:
    TreeNode *increasingBST(TreeNode *root) {
        if (root == nullptr)
            return nullptr;

        last = nullptr;
        Root = nullptr;

        traverse(root);

        return Root;
    }
};

class Solution917 {
    bool isLetter(const string& s, int i) {
        return (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z');
    }

public:
    string reverseOnlyLetters(string S) {
        int p = S.size();
        int q = 0;
        string buf = S;

        while (q < buf.size()) {
            while (q < buf.size() && !isLetter(buf, q)) {
                q++;
            }
            if (q == buf.size())
                break;

            while (!isLetter(S, p)) {
                p--;
            }

            buf[q] = S[p];
            q++;
            p--;
        }

        return buf;
    }
};

class Solution937 {
private:

    static int compare(const string &log1, const string &log2) {
        string p1 = log1.substr(log1.find(' ') + 1);
        string p2 = log2.substr(log2.find(' ') + 1);
        return p1 < p2;
    }

    /**
     *
     * @param log
     * @param pos
     * @param startPos 当前位置开始的一个token
     * @return
     */
    string nextToken(const string &log, int startPos = 0, int *pos = nullptr) {
        if (startPos == 0) {
            while (log[startPos] != ' ')
                startPos++;
            // 跳过空格
            startPos++;
        }

        int p = startPos;
        while (p < log.size() && log[p] != ' ')
            p++;

        if (pos != nullptr)
            *pos = p;

        return log.substr(startPos, p);
    }

public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        vector<string> digitLogs;
        vector<string> letterLogs;

        for (int i = 0; i < logs.size(); i++) {
            const string &s = nextToken(logs[i], 0);
            if (s[0] >= '0' && s[0] <= '9') {
                digitLogs.push_back(logs[i]);
            } else {
                letterLogs.push_back(logs[i]);
            }
        }

        sort(letterLogs.begin(), letterLogs.end(), compare);
        letterLogs.insert(letterLogs.end(), digitLogs.begin(), digitLogs.end());
        return letterLogs;
    }
};

class Solution953 {
public:
    bool isAlienSorted(vector<string> &words, string order) {
        // 保存着每个字母的下标
        int index[128];

        for (int i = 0; i < 26; i++) {
            index[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            // 取较小的长度
            int len = words[i].length() > words[i + 1].length() ? words[i + 1].length() : words[i].length();
            bool rightOrder = false;
            for (int j = 0; j < len; j++) {
                if (index[words[i][j]] < index[words[i + 1][j]]) {
                    // 顺序正确，退出这个for循环
                    rightOrder = true;
                    break;
                } else if (index[words[i][j]] > index[words[i + 1][j]])
                    // 顺序不正确，返回
                    return false;
            }

            if (!rightOrder) {
                // 到这里的话，说明两字符串前缀相等，但是有一条更长
                if (words[i].length() > words[i + 1].length()) {
                    // 前面的更长的话，就是错误的
                    return false;
                }
            }
        }

        return true;
    }
};

class Solution985 {
    /**
     * @param val
     * @return val if val is even, 0 if val is odd.
     */
    inline int even(int val) {
        return val & (0xFFFFFFFF + (val & 1));
    }

public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries) {
        vector<int> result(A.size());

        int sum = 0;
        vector<bool> isEven(A.size());
        for (int i = 0; i < A.size(); i++) {
            sum += even(A[i]);
        }


        for (int i = 0; i < queries.size(); i++) {
            int index = queries[i][1];
            int newVal = A[index] + queries[i][0];

            sum += + even(newVal) - even(A[index]);

            A[index] = newVal;
            result[i] = sum;
        }

        return result;
    }
};



