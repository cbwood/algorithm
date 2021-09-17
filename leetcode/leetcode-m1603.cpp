//
// Created by cb on 2021/9/17.
//

#include "vector"
#include "cmath"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<double> intersection(vector<int> &start1, vector<int> &end1, vector<int> &start2, vector<int> &end2) {
        if (!(max(start1[0], end1[0]) >= min(start2[0], end2[0])
              && min(start1[0], end1[0]) <= max(start2[0], end2[0])
              && max(start1[1], end1[1]) >= min(start2[1], end2[1])
              && min(start1[1], end1[1]) <= max(start2[1], end2[1])
              && cross(start1[0] - end1[0], start1[1] - end1[1], start2[0] - end1[0], start2[1] - end1[1])
                 * cross(end2[0] - end1[0], end2[1] - end1[1], start1[0] - end1[0], start1[1] - end1[1]) >= 0
              && cross(start1[0] - end2[0], start1[1] - end2[1], start2[0] - end2[0], start2[1] - end2[1])
                 * cross(start2[0] - end2[0], start2[1] - end2[1], end1[0] - end2[0], end1[1] - end2[1]) >= 0))
            return {};

        double t = cross(start1[0] - end1[0], start1[1] - end1[1], start2[0] - end2[0], start2[1] - end2[1]);

        if (t == 0) {
            if (start1[0] > end1[0]) swap(start1, end1);
            if (start2[0] > end2[0]) swap(start2, end2);

            if (start1[0] >= min(start2[0], end2[0]) && start1[0] <= max(end2[0], start2[0])
                && start1[1] >= min(start2[1], end2[1]) && start1[1] <= max(end2[1], start2[1]))
                return {start1[0] * 1.0, start1[1] * 1.0};
            if (end1[0] >= min(start2[0], end2[0]) && end1[0] <= max(end2[0], start2[0])
                && end1[1] >= min(start2[1], end2[1]) && end1[1] <= max(end2[1], start2[1]))
                return {end1[0] * 1.0, end1[1] * 1.0};
            if (start2[0] >= min(start1[0], end1[0]) && start2[0] <= max(end1[0], start1[0])
                && start2[1] >= min(start1[1], end1[1]) && start2[1] <= max(end1[1], start1[1]))
                return {start2[0] * 1.0, start2[1] * 1.0};
            if (end2[0] >= min(start1[0], end1[0]) && end2[0] <= max(end1[0], start1[0])
                && end2[1] >= min(start1[1], end1[1]) && end2[1] <= max(end1[1], start1[1]))
                return {end2[0] * 1.0, end2[1] * 1.0};
        }

        double a0 = start1[1] - end1[1];
        double b0 = end1[0] - start1[0];
        double c0 = start1[0] * end1[1] - start1[1] * end1[0];

        double a1 = start2[1] - end2[1];
        double b1 = end2[0] - start2[0];
        double c1 = start2[0] * end2[1] - start2[1] * end2[0];

        vector<double> ans;
        ans.push_back((b0 * c1 - b1 * c0) / t);
        ans.push_back((a1 * c0 - a0 * c1) / t);
        return ans;
    }

    double cross(int x1, int y1, int x2, int y2) {
        return x1 * y2 - x2 * y1;
    }
};
