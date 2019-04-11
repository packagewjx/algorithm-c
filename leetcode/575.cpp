//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-10.
//

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> candyKinds;
        for (auto it = candies.begin(); it != candies.end(); it++) {
            candyKinds.insert(*it);
        }
        return candies.size() / 2 < candyKinds.size() ? candies.size() / 2 : candyKinds.size();
    }
};