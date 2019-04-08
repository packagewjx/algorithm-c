//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-31.
//

#include <vector>
#include <string>
#include <map>
using std::string;
using std::vector;
using std::map;

class Solution {
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

int main(int argv, char* argc[]) {
    Solution s;
    vector<string> v({"9001 discuss.leetcode.com"});
    s.subdomainVisits(v);
    return 0;
}