//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-22.
//

#include <vector>

using namespace std;

class Solution {
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

int main(int argv, char *argc[]) {
    vector<vector<int>> num = {{1, 0},
                               {0, 2}};
    Solution s;
    s.surfaceArea(num);
    return 0;
}