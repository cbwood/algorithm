/*
 * @File Name          :leetcode-2013.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/26 10:05
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "map"
#include "vector"

using namespace std;

class DetectSquares {
public:
    static const int maxn = 1e3 + 1;
    map<int, int> ma;

    DetectSquares() {

    }

    void add(vector<int> point) {
        ma[point[0] * maxn + point[1]] += 1;
    }

    int area(int &x1, int &y1, int &x2, int &y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }

    int count(vector<int> point) {
        int ans = 0;
        for (auto &x: ma) {
            int xx = x.first / maxn;
            int yy = x.first % maxn;
            if (xx != point[0] && yy != point[1] &&
                area(point[0], point[1], xx, point[1]) == area(point[0], point[1], point[0], yy)) {
                if (ma[xx * maxn + point[1]] > 0 && ma[point[0] * maxn + yy] > 0)
                    ans = ans + ma[xx * maxn + point[1]] * ma[point[0] * maxn + yy] * x.second;
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */