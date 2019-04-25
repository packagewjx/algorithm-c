//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-25.
//

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;

        for (int i : nums1) {
            s1.insert(i);
        }

        unordered_set<int> intersect;
        for (int i: nums2) {
            if (s1.find(i) != s1.end())
                intersect.insert(i);
        }

        return vector<int>(intersect.begin(), intersect.end());
    }
};