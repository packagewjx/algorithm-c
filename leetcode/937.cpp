//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-10.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
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

int main(int argv, char *argc[]) {
    Solution s;


    vector<string> test = {"j je", "b fjt", "7 zbr", "m le", "o 33"};
    s.reorderLogFiles(test);
    return 0;
}