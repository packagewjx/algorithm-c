//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-31.
//

#include <vector>

using std::vector;


/**
 * No if solution.
 */
class Solution {
    /**
     * @param val
     * @return val if val is even, 0 if val is odd.
     */
    inline int even(int val) {
        return val & (0xFFFFFFFF + (val & 1));
    }

public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries) {
        vector<int> result(A.size());

        int sum = 0;
        vector<bool> isEven(A.size());
        for (int i = 0; i < A.size(); i++) {
            sum += even(A[i]);
        }


        for (int i = 0; i < queries.size(); i++) {
            int index = queries[i][1];
            int newVal = A[index] + queries[i][0];

            sum += + even(newVal) - even(A[index]);

            A[index] = newVal;
            result[i] = sum;
        }

        return result;
    }
};

int main(int argv, char *argc[]) {
    vector<int> a({5,5,4});
    vector<vector<int>> queries({{0, 1}, {1, 0}, {4, 1}});
    Solution s;
    const vector<int> &vector = s.sumEvenAfterQueries(a, queries);


    return 0;
}