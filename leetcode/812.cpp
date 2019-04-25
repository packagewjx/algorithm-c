//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-25.
//

#include <vector>

using namespace std;

class Solution {
    double area2(int x1, int y1, int x2, int y2, int x3, int y3) {
        double result = x1 * y2 + +x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2;
        return result > 0 ? result / 2 : -result / 2;
    }

public:
    double largestTriangleArea(vector<vector<int>> &points) {
        double largest = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    double a = area2(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0],
                                     points[k][1]);
                    largest = a > largest ? a : largest;
                }
            }
        }

        return largest;
    }
};

int main(int argv, char *argc[]) {
    vector<vector<int>> points = {{1, 0},
                                  {0, 0},
                                  {0, 1}};
    Solution s;
    s.largestTriangleArea(points);
    return 0;
}