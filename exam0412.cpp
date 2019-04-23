//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-12.
//


#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Compressor {
public:

    struct FieldPos {
        int blockIndex;
        int bitIndex;
    };

    // greedy method
    // always find the largest bit for the next pos
    vector<FieldPos> getFieldPos_Greedy(vector<int> &bitLengths) {
        vector<FieldPos> result;
        sort(bitLengths.begin(), bitLengths.end());
        int bitsRemain = 32;
        int blockIndex = 0;
        while (!bitLengths.empty()) {
            auto pos = lower_bound(bitLengths.begin(), bitLengths.end(), bitsRemain);
            // pos will be at the first number bigger than bitsRemain
            if (pos == bitLengths.begin()) {
                // we can not find any number to fit in
                blockIndex++;
                bitsRemain = 32;
                continue;
            }
            // to find the first number smaller than bitsRemain
            pos--;
            bitsRemain -= *pos;
            FieldPos fp{};
            fp.bitIndex = 32 - bitsRemain;
            fp.blockIndex = blockIndex;
            result.push_back(fp);
            bitLengths.erase(pos);
        }

        return result;
    }

    int intermediate(int iChoose, int bitsRemain, map<int, map<int, int>>& iResult, vector<int>& bitsLength) {


    }

    vector<FieldPos> getFieldPos(vector<int> &bitLengths) {
        sort(bitLengths.begin(), bitLengths.end());
        int bitsRemain = 32;
        int blockIndex = 0;

        // first key is numIndex, next is bitsRemain
        map<int, map<int, int>> intermediateResults;

        while (!bitLengths.empty()) {


        }




    }

};

