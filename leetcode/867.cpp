//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-3.
//

#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> result(A[0].size());

        for (int i = 0; i < A[0].size(); i++) {
            result[i] = vector<int>(A.size());
            for (int j = 0; j < A.size(); j++) {
                result[i][j] = A[j][i];
            }
        }

        return result;
    }
};