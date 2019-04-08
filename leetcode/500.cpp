//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-8.
//

#include <vector>
#include <string>
#include <set>

using std::string;
using std::vector;
using std::set;

class Solution {
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