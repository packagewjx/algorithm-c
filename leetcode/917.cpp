//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-22.
//

#include <string>

using namespace std;

class Solution {
    bool isLetter(const string& s, int i) {
        return (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z');
    }

public:
    string reverseOnlyLetters(string S) {
        int p = S.size();
        int q = 0;
        string buf = S;

        while (q < buf.size()) {
            while (q < buf.size() && !isLetter(buf, q)) {
                q++;
            }
            if (q == buf.size())
                break;

            while (!isLetter(S, p)) {
                p--;
            }

            buf[q] = S[p];
            q++;
            p--;
        }

        return buf;
    }
};