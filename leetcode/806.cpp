//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-4.
//

#include <vector>
#include <string>

using std::string;
using std::vector;

#define MAX_WIDTH 100

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lineWidth = 0;
        int lineCount = 0;
        for (int i = 0; i < S.size(); i++) {
            if (lineWidth + widths[S[i] - 'a'] > MAX_WIDTH) {
                lineCount += 1;
                lineWidth = 0;
            }
            lineWidth += widths[S[i] - 'a'];
        }

        vector<int> r(2);
        r[0] = lineCount + 1;
        r[1] = lineWidth;
        return r;
    }
};