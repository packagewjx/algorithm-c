//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-22.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
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

int main(int argv, char *argc[]) {
    vector<string> words = {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    Solution s;
    s.isAlienSorted(words, order);
    return 0;
}