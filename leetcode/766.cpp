//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-9.
//

#include <vector>

using std::vector;


class Solution {
private:
    // 判断这个点的对角线是否全等
    bool diagonalEqual(vector<vector<int>> &matrix, int row, int col) {
        int num = matrix[row][col];
        row++;
        col++;

        while (row < matrix.size() && col < matrix[0].size()) {
            if (matrix[row][col] != num)
                return false;
            row++;
            col++;
        }
        return true;
    }

public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        // 从最左下开始，往上走
        for (int i = matrix.size() - 1; i >= 0; i--) {
            if (!diagonalEqual(matrix, i, 0)) {
                return false;
            }
        }

        // 第一行第二个，往右走。这样就覆盖了所有对角线
        for (int i = 1; i < matrix[0].size(); i++) {
            if (!diagonalEqual(matrix, 0, i)) {
                return false;
            }
        }

        return true;
    }
};