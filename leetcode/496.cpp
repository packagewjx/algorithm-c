//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-10.
//

#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            result[i] = -1;
            for (int j = i + 1; j < nums2.size(); j++) {
                if (nums2[j] > nums1[i]) {
                    result[i] = nums2[j];
                    break;
                }
            }
        }
        return result;
    }
};

int main(int argv, char *argc[]) {
    vector<int> i1 = {4, 1, 2};
    vector<int> i2 = {1, 3, 4, 2};
    Solution s;
    s.nextGreaterElement(i1, i2);
    return 0;
}