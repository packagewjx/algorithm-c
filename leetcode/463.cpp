//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-10.
//

#include <vector>

using std::vector;

class Solution {
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