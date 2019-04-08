//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-8.
//

#include <vector>
#include <string>
#include <cstring>

using std::string;
using std::vector;

#define INDEX_MASK 0x1F
#define COUNT_ARRAY_SIZE 32

class Solution {
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

int main(int argv, char *argc[]) {
    vector<string> test = {"abcd", "cdab", "adcb", "cbad"};
    Solution s;
    s.numSpecialEquivGroups(test);


    return 0;
}