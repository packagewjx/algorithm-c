//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-9.
//

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
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

int main() {
    Solution s;
    vector<string> test = {"5", "2", "C", "D", "+"};
    s.calPoints(test);
}