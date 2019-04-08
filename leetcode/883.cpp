//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-31.
//

#include <vector>
using std::vector;

class Solution {
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