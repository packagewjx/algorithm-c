//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-10.
//

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);

        for (int i = 3; i <= n; i += 3) {
            result[i - 1] = "Fizz";
        }
        for (int i = 5; i <= n; i += 5) {
            result[i - 1] += "Buzz";
        }

        for (int i = 1; i <= n; i++) {
            if (result[i - 1].empty()) {
                result[i - 1] = to_string(i);
            }
        }

        return result;
    }
};