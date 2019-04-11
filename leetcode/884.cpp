//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-10.
//

#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        set<string> aWord;
        set<string> aWordUncommon;

        string word;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == ' ') {
                if (aWord.find(word) != aWord.end()) {
                    aWordUncommon.erase(word);
                } else {
                    aWord.insert(word);
                    aWordUncommon.insert(word);
                }
                word.clear();
            } else {
                word += A[i];
            }
        }
        // last word
        if (aWord.find(word) != aWord.end()) {
            aWordUncommon.erase(word);
        } else {
            aWord.insert(word);
            aWordUncommon.insert(word);
        }
        word.clear();

        // handle B
        set<string> bWord;
        set<string> bWordUncommon;
        // aWordOnce用于存储A中出现1次的，但是B中不出现的，因此下面需要删除一些元素

        for (int i = 0; i < B.size(); i++) {
            if (B[i] == ' ') {
                if (bWord.find(word) != bWord.end()) {
                    bWordUncommon.erase(word);
                } else {
                    bWord.insert(word);

                    if (aWord.find(word) == aWord.end())
                        bWordUncommon.insert(word);
                    else
                        aWordUncommon.erase(word);
                }
                word.clear();
            } else {
                word += B[i];
            }
        }
        // 最后一个word
        if (bWord.find(word) != bWord.end()) {
            bWordUncommon.erase(word);
        } else {
            if (aWord.find(word) == aWord.end())
                bWordUncommon.insert(word);
            else
                aWordUncommon.erase(word);
        }

        vector<string> result = vector<string>(aWordUncommon.begin(), aWordUncommon.end());
        result.insert(result.end(), bWordUncommon.begin(), bWordUncommon.end());
        return result;
    }
};


int main() {
    Solution s;
    s.uncommonFromSentences("xf tyl xf", "gw p gw xf");
}