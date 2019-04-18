//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-11.
//

#include <vector>

using namespace std;

class Solution {
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

int main(int argv, char *argc[]) {
    Solution s;
    vector<vector<int>> test = {{1, 2},
                                {3, 4},
                                {5, 6}};
    s.matrixReshape(test, 2, 3);
    return 0;
}